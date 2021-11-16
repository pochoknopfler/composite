#ifndef IListable_H
#define IListable_H

#include <iostream>

class IListable
{
    public:
        virtual ~IListable(){};
        virtual void list(int depth) = 0; //operation
};

#endif // IListable_H