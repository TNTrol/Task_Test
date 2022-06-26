//
// Created by tntrol on 27.06.22.
//

#include "unit.h"

Unit::Unit(vec2 &position, vec2 &direction) :
        m_count(0),
        m_direction(direction),
        m_position(position)
{
}

const vec2 &Unit::get_direction()
{
    return m_direction;
}

uint64_t Unit::get_count()
{
    return m_count;
}

void Unit::set_count(uint64_t count)
{
    m_count = count;
}

const vec2 &Unit::get_position()
{
    return m_position;
}

uint64_t Unit::get_id()
{
    return m_id;
}
