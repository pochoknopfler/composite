#ifndef FOLDER_H
#define FOLDER_H
#include <iostream>
#include <vector>
#include <algorithm>
// #include <IComposableOfListable.h>
#include "../include/IComposableOfListable.h"
// #include <IListable.h>
#include "../include/IListable.h"
#include <string>

class Folder : public IListable, public IComposableOfListable
{
    private:
        std::string m_nodeName;
        std::vector<IListable*> m_children;

    public:
        Folder(std::string nodeName);
        virtual ~Folder();
        void list(int depth);//operation     
        void add(IListable* component);
        void remove(IListable* component);
       
};

#endif // FOLDER_H