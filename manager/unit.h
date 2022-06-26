//
// Created by tntrol on 27.06.22.
//

#ifndef TASK_TEST_UNIT_H
#define TASK_TEST_UNIT_H


#include <cstdint>
#include "vec2.h"


static uint64_t sid = 0;

class Unit
{

private:
    vec2 m_direction;
    vec2 m_position;
    uint64_t m_count;
    uint64_t m_id = sid++;
public:

    Unit(vec2 &position, vec2 &direction);

    const vec2 &get_direction();

    const vec2 &get_position();

    uint64_t get_count();

    void set_count(uint64_t);

    uint64_t get_id();
};


#endif //TASK_TEST_UNIT_H
