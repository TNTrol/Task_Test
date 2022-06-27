#include <iostream>
#include "manager/unit_manager.h"
#include "manager/view.h"

#define N 100
#define R 100

int main()
{
    UnitManager unitManager(N);
    View view(20.0f, 135.5f, &unitManager);
    vec2 position;
    vec2 direction;
    for(int i = 0; i < N; ++i)
    {
        direction.x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        direction.y = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        position.x =  static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(R)));
        position.y =  static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(R)));
        unitManager.create(position, direction);
    }
    for (auto *u: unitManager)
    {
        std::cout << "Unit# " << u->get_id()
        << ": position("<< u->get_position().x << ", " <<  u->get_position().y
        << "), direction(" << u->get_direction().x << ", " << u->get_direction().y << ")\n";
    }
    view.update();
    for (auto *u: unitManager)
    {
        std::cout << "Unit# " << u->get_id() << " see:"<< u->get_count() << "\n";
    }
    return 0;
}
