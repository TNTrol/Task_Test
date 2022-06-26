//
// Created by tntrol on 27.06.22.
//

#include "view.h"

#define PI 3.14159265

View::View(float radius, float angle, UnitManager *unitManager) :
        m_angle(angle),
        m_radius(radius * radius),
        unitManager(unitManager)
{
    m_cos_p = cos(angle / 2 * PI / 180);
    m_sin_p = sin(angle / 2 * PI / 180);
    m_cos_n = cos(-angle / 2 * PI / 180);
    m_sin_n = sin(-angle / 2 * PI / 180);
}

void View::update()
{
    for (auto *unit_: *unitManager)
    {
        unit_->set_count(calculate_units(unit_));
    }
}

size_t View::calculate_units(Unit *unit)
{
    vec2 position = unit->get_position();
    vec2 direction = unit->get_direction();
    vec2 left = {.x = direction.x * m_cos_p - direction.y * m_sin_p,
                 .y = direction.y * m_cos_p + direction.x * m_sin_p};
    vec2 right = {.x = direction.x * m_cos_n - direction.y * m_sin_n,
                  .y = direction.y * m_cos_n + direction.x * m_sin_n};
    vec2 normal_position = {0, 0};
    vec2 pos = {0, 0};
    bool checking_left = false;
    size_t count = 0;

    for (auto *unit_: *unitManager)
    {
        if(unit == unit_)
        {
            continue;
        }
        pos = unit_->get_position();
        if ((pos.x - position.x) * (pos.x - position.x) + (pos.y - position.y) * (pos.y - position.y) > m_radius)
        {
            continue;
        }
        checking_left = false;
        normal_position.x = pos.x - position.x;
        normal_position.y = pos.y - position.y;
        if (left.x > 0)
        {
            if (normal_position.y < (normal_position.x) * (left.y) / (left.x)) // under
            {
                checking_left = true;
            }
        }
        else
        {
            if (normal_position.y > (normal_position.x) * (left.y) / (left.x)) // on
            {
                checking_left = true;
            }
        }
        if (!checking_left)
        {
            continue;
        }
        if (right.x > 0)
        {
            if (normal_position.y > (normal_position.x) * (right.y) / (right.x)) // on
            {
                count++;
            }
        }
        else
        {
            if (normal_position.y < (normal_position.x) * (right.y) / (right.x)) // under
            {
                count++;
            }
        }

    }
    return count;
}
