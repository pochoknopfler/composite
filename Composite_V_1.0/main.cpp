#include <iostream>
//#include "./include/Folder.cpp"
//#include "./include/File.cpp"
#include <Folder.cpp>
#include <File.cpp>`

int main()
{
    Folder* folder_01 = new Folder("folder_01");

    Folder* folder_02 = new Folder("folder_02");
    folder_01->add(folder_02);

    Folder* folder_03 = new Folder("folder_03");
    folder_03->add(new File("file A"));
    folder_03->add(new File("file B"));
    folder_02->add(folder_03);
    
    folder_01->list(1);

    delete folder_03;
    delete folder_02;
    delete folder_01;
    return 0;
};