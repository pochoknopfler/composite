#include <iostream>
#include <vector>
#include <algorithm>
// #include <IComposableOfListable.h>
#include "../include/IComposableOfListable.h"
// #include <IListable.h>
#include "../include/IListable.h"

class Folder : public IListable, public IComposableOfListable
{
    private:
        std::string m_nodeName;
        std::vector<IListable*> m_children;

    public:
        Folder(std::string nodeName)
        {
            m_nodeName = nodeName;
        }

        virtual ~Folder(){}
        
        void list(int depth)//operation
        {
            std::string newStr(depth, '-');
            std::cout << newStr << m_nodeName << " depth: " << depth << std::endl;
            for(std::vector<IListable*>::const_iterator it = m_children.begin(); it != m_children.end(); ++it)
            {
                if(*it != 0)
                {
                    (*it)->list(depth + 1);
                }
            }
        }

        void add(IListable* component)
        {
            m_children.push_back(component);
        }

        void remove(IListable* component)
        {
            m_children.erase(std::remove(m_children.begin(), m_children.end(), component), m_children.end());
        }
};