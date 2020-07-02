
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#ifndef ClassCompo_h
#define ClassCompo_h

class Composite : public IComponent
{
    private:
        std::string m_nodeName;
        std::vector<IComponent*> m_children;

    public:
        Composite(std::string nodeName)
        {
            m_nodeName = nodeName;
        }

        virtual ~Composite(){}
        
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

#endif//ClassCompo