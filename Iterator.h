#ifndef ITERATOR_H
#define ITERATOR_H
#include "house.h"

struct Qelem
{
    House *object = nullptr;
    Qelem *next = nullptr;
};

class Iterator
{
public:
    friend class Recipe;
    Iterator()
    {
        current = nullptr;
    }
    Iterator(Qelem *init)
    {
        current = init;
    }
    ~Iterator()
    {

    }
    void step()
    {
        current = current->next;
    }
    House *get() const
    {
        return current->object;
    }
    bool end() const
    {
        if (!current)
            return true;
        else
            return false;
    }
private:
    Qelem *current;
};

#endif // ITERATOR_H
