#ifndef CHAOS_OBJECTPOOL_H
#define CHAOS_OBJECTPOOL_H

#include <vector>
#include "Err.h"

/**
 *
 *
 *
 * @tparam PoolSize
 * @tparam ObjectType
 */
template <int PoolSize, typename ObjectType>
class ObjectPool
{
private:
    ObjectType pool_[PoolSize];
    std::vector<int> freeSlots_;
public:


    /**
     *
     * @param id
     * @return
     */
    ObjectType *getObjectAt(int id)
    {
        Err::predicate(id < PoolSize, "ObjectPool: id is greater than pool size");
        if (id > PoolSize)
        {
            return NULL;
        }
        return &pool_[id];
    }


    /**
     *
     * @return
     */
    int createObject()
    {
        int id = freeSlots_.back();
        freeSlots_.pop_back();
        pool_[id] = ObjectType();
        return id;
    }


    /**
     *
     * @param id
     */
    void destroyObject(int id)
    {
        Err::predicate(id < PoolSize, "ObjectPool: id is greater than pool size");
        freeSlots_.push_back(id);
    }


    /**
     *
     */
    ObjectPool()
    {
        for (int i = 0; i < PoolSize; i++)
        {
            freeSlots_.push_back(i);
        }
    }

};



#endif //CHAOS_OBJECTPOOL_H
