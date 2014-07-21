#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

static int STATIC_COUNTER = 0;

class Entity
{
    public:
        Entity(int id) : _id(id) {};
        Entity(): _id(STATIC_COUNTER++) {};
        ~Entity() {};
        int getId() {return _id;};
    protected:
        int _id;
};

#endif
