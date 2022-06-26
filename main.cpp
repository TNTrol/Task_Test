#include <iostream>
#include "math.h"

#define PI 3.14159265

struct vec2
{
    float x;
    float y;

    vec2() = default;
};

static vec2 other[] = {
        {1,  2},
        {-5, -1},
        {0,  2},
        {0,  1},
        {1,  0},
        {0,  0}
};

static float cos_a = 0.0f;
static float sin_a = 0.0f;
static float cos_m = 0.0f;
static float sin_m = 0.0f;
static float h = 0.0f;

int check(vec2 &position, vec2 &direction)
{
    vec2 l = {.x = direction.x * cos_a - direction.y * sin_a, .y = direction.y * cos_a + direction.x * sin_a};
    vec2 r = {.x = direction.x * cos_m - direction.y * sin_m, .y = direction.y * cos_m + direction.x * sin_m};
    vec2 n_p = {0, 0};
    bool c_l = false;
    int count = 0;

    for (vec2 pos: other)
    {
        if ((pos.x - position.x) * (pos.x - position.x) + (pos.y - position.y) * (pos.y - position.y) > h)
        {
            continue;
        }
        c_l = false;
        n_p.x = pos.x - position.x;
        n_p.y = pos.y - position.y;
        if (l.x > 0)
        {
            //  n_p.y > (n_p.x)(l.y)/(l.x)
            if (n_p.y <
                (n_p.x) * (l.y) / (l.x)) // under  // (n_p.x) * (l.y) - (l.x ) * (n_p.y) >= 0  x * y_2 <= y * x_2
            {
                c_l = true;
            }
        }
        else
        {
            if (n_p.y > (n_p.x) * (l.y) / (l.x)) // x * y_2 >= y * x_2  // on
            {
                c_l = true;
            }
        }
        if (!c_l)
        {
            continue;
        }
        if (r.x > 0)
        {
            if (n_p.y > (n_p.x) * (r.y) / (r.x)) // on
            {
                count++;
            }
        }
        else
        {
            if (n_p.y < (n_p.x) * (r.y) / (r.x)) // under
            {
                count++;
            }
        }

    }
    return count;
}

void init(float angle)
{
    cos_a = cos(angle / 2 * PI / 180);
    sin_a = sin(angle / 2 * PI / 180);
    cos_m = cos(-angle / 2 * PI / 180);
    sin_m = sin(-angle / 2 * PI / 180);
    h = 2 * 2;
}

int main()
{
    init(135.5f);
    vec2 p = {1, 1}, d = {-1, 0};

    std::cout << "Hello, World!" << check(p, d) << std::endl;
    return 0;
}
