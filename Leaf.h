#ifndef Leaf_h
#define Leaf_h

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "IComponent.h"

class Leaf : public IComponent
{
    private:
        std::string m_nodeName;
        std::vector<IComponent*> m_children;

    public:
        Leaf(std::string nodeName)
        {
            m_nodeName = nodeName;
        }

        virtual ~Leaf(){}

        void show(int depth)//operation
        {
            std::string newStr(depth, '-');
            std::cout << newStr << m_nodeName << " depth: " << depth << std::endl;
            for(std::vector<IComponent*>::const_iterator it = m_children.begin(); it != m_children.end(); ++it)
            {
                if(*it != 0)
                {
                    (*it)->show(depth + 1);
                }
            }
        }

        void add(IComponent* component)
        {
            m_children.push_back(component);
        }

        void remove(IComponent* component)
        {
            m_children.erase(std::remove(m_children.begin(), m_children.end(), component), m_children.end());
        }

        IComponent* getChild(int key)
        {
            return m_children[key];
        }
};


#endif//Leaf