:: Compilo el Binario
g++ -Wall -std=c++11 -I.\include\ -c .\src\Folder.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\File.cpp
g++ -Wall -std=c++11 -I.\include\ -c main.cpp

g++ Folder.o File.o main.o -o composite.exe

:: Limpio los códigos objeto
DEL .\*.o