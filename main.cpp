//Compilar con std=c++17
#include "arbolB.h"
#include <string.h>

int main(int argc, char* argv[]){
   ArbolB* arbol;
   if(std::string(argv[1]) == "-m"){
      arbol = new ArbolB(atoi(argv[2]));
      arbol->insert(1);
      arbol->insert(2);
      arbol->insert(3);
      arbol->insert(4);
      arbol->insert(5);
      arbol->insert(6);
      arbol->insert(7);
      arbol->insert(8);
      arbol->insert(9);
      arbol->insert(10);
      arbol->insert(11);
      arbol->insert(12);
      arbol->printTree();
   }
}
