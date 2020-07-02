/**
    Project     : Composite Pattern Example

    Authors     : Erich Gamma, Richard Helm, Ralph Johnson and John Vlissides

    Implementer : Gabriel Nicolás González Ferreira
**/

///////////////////////////////////////////ICOMPONENT-INTERFACE///////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Leaf.h"
#include "ClassCompo.h"
#include "IComponent.h"

/*class IComponent
{
    public:
        virtual ~IComponent(){};
        virtual void show(int depth) = 0; //operation
        virtual void add(IComponent* component) = 0;
        virtual void remove(IComponent* component) = 0;
        virtual IComponent* getChild(int key) = 0;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/
/////////////////////////////////////////////COMPOSITE///////////////////////////////////////////////////////
/*class Composite : public IComponent
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/
////////////////////////////////////////////////LEAF////////////////////////////////////////////////////////
/*class Leaf : public IComponent
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/
/////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////
int main()
{
    IComponent* root = new Composite("root");

    IComponent* trunk = new Composite("trunk");
    root->add(trunk);

    IComponent* branch = new Composite("branch");
    branch->add(new Leaf("leaf A"));
    branch->add(new Leaf("leaf B"));
    trunk->add(branch);
    
    root->show(1);

    delete branch;
    delete trunk;
    delete root;
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////