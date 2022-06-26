//
// Created by tntrol on 27.06.22.
//

#ifndef TASK_TEST_VIEW_H
#define TASK_TEST_VIEW_H

#include "math.h"
#include "vec2.h"
#include "unit_manager.h"

class View
{
private:
    const float m_angle;
    float m_cos_p;
    float m_sin_p;
    float m_cos_n;
    float m_sin_n;
    const float m_radius;
    UnitManager *unitManager;
private:
    size_t calculate_units(Unit *unit);
public:
    View(float radius, float angle, UnitManager *unitManager);
    void update();
};


#endif //TASK_TEST_VIEW_H
