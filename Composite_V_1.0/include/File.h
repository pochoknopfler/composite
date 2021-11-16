#ifndef FILE_H
#define FILE_H
#include <iostream>
//#include <IListable.h>
#include "./IListable.h"


class File : public IListable
{
    private:
        std::string m_nodeName;

    public:
        File(std::string nodeName);
        virtual ~File();
        void list(int depth)//operation
        
};

#endif // FILE_H