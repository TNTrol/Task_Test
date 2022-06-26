//
// Created by tntrol on 27.06.22.
//

#ifndef TASK_TEST_CONTAINER_H
#define TASK_TEST_CONTAINER_H
#include <list>
#include <cstdio>
#include <cstdint>

template <class T>
class Container
{
private:
    struct part_memory
    {
        T * m_ptr;
        const size_t m_size;
        size_t m_use_size;
        explicit part_memory(size_t size): m_size(size), m_ptr((T*) new uint8_t [size* sizeof(T)]), m_use_size(0){}
        ~part_memory()=default;
    };
private:
    std::list<part_memory> m_parts;
    const size_t m_grow;
public:
    Container(size_t start_size, size_t grow);
    ~Container();
    T* allocate();
};

template<class T>
Container<T>::Container(size_t start_size, size_t grow): m_grow(grow), m_parts()
{
    part_memory part(start_size);
    m_parts.push_back(part);
}

template<class T>
Container<T>::~Container()
{
    for(auto part: m_parts)
    {
        delete part.m_ptr;
    }
}

template<class T>
T *Container<T>::allocate()
{
    T *ptr;
    for(auto &part: m_parts)
    {
        if(part.m_use_size < part.m_size)
        {
            ptr = &part.m_ptr[part.m_use_size];
            part.m_use_size++;
            break;
        }
    }
    if(!ptr)
    {
        part_memory part(m_grow);
        m_parts.push_back(part);
        ptr = &part.m_ptr[part.m_use_size++];
    }
    return ptr;
}


#endif //TASK_TEST_CONTAINER_H
