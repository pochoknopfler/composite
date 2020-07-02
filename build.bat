:: Borro el directorio de binarios si ya existiera
IF EXIST .\bin RMDIR /S /Q .\bin

:: Creo los directorios para el binario y las bibliotecas
MD .\bin

:: Compilo el Binario
g++ -Wall -std=c++11 -c .\ClassCompo.h 
g++ -Wall -std=c++11 -c .\composite.cpp
g++ -Wall -std=c++11 -c .\IComponent.h
g++ -Wall -std=c++11 -c .\Leaf.h 
g++ ClassCompo.o IComponent.o Leaf.o -o .\bin\composite.exe

:: Limpio los códigos objeto
DEL .\*.o
