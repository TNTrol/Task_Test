#include <iostream>
#include "manager/unit_manager.h"
#include "manager/view.h"

#define PI 3.14159265
static vec2 position[] = {
        {1,  1},
        {1,  2},
        {-5, -1},
        {0,  2},
        {0,  1},
        {1,  0}
};

static vec2 direction[] = {
        {0,  1},
        {1, 0},
        {0.707,  0.707},
        {0.5,  1},
        {-1.0,  0.2},
        {-1,  0}
};


int main()
{
    UnitManager unitManager(10);
    View view(2.0f, 135.5f, &unitManager);
    for(int i = 0; i < 6; ++i)
    {
        unitManager.create(position[i], direction[i]);
    }
    view.update();
    for (auto *u: unitManager)
    {
        std::cout << "Unit# " << u->get_id() << " see:"<< u->get_count() << "\n";
    }
    return 0;
}
