//
// Created by tntrol on 27.06.22.
//

#ifndef TASK_TEST_UNIT_MANAGER_H
#define TASK_TEST_UNIT_MANAGER_H

#include <vector>

#include "container.h"
#include "unit.h"

class UnitManager
{
private:
    Container<Unit> *m_pool;
    std::vector<Unit *> m_units;
public:
    UnitManager(size_t count_units = 10);
    ~UnitManager();

    template<class... ARGS>
    Unit *create(ARGS &&... args)
    {
        Unit* unit = m_pool->allocate();
        unit = new(unit) Unit(std::forward<ARGS>(args)...);
        m_units.push_back(unit);
        return unit;
    }

    std::vector<Unit *>::iterator begin();

    std::vector<Unit *>::iterator end();
};


#endif //TASK_TEST_UNIT_MANAGER_H
