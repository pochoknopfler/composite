
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#ifndef IComponent_h
#define IComponent_h

class IComponent
{
    public:
        virtual ~IComponent(){};
        virtual void show(int depth) = 0; //operation
        virtual void add(IComponent* component) = 0;
        virtual void remove(IComponent* component) = 0;
        virtual IComponent* getChild(int key) = 0;
};

#endif//ICOMPONENT