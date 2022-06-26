//
// Created by tntrol on 27.06.22.
//

#include "unit_manager.h"

std::vector<Unit*>::iterator UnitManager::begin()
{
    return m_units.begin();
}

std::vector<Unit *>::iterator UnitManager::end()
{
    return m_units.end();
}

UnitManager::UnitManager(size_t count_units)
{
    m_pool = new Container<Unit>(count_units, count_units);
}

UnitManager::~UnitManager()
{
    delete m_pool;
}
