#ifndef ARBOLB_H
#define ARBOLB_H

#include <utility>
#include <iostream>

struct Nodo{
   Nodo* padre = nullptr;
   unsigned int num_de_llaves = 0;
   bool es_nodo_hoja = true;

   Nodo** hijos;
   int* llaves;
};

class ArbolB{

   private:
      Nodo* raiz = nullptr;
      void split(Nodo* padre, Nodo* hijo, int key, int indice);
      void splitWithBuffer(Nodo* padre, Nodo* hijo, int key, int indice, Nodo* buffer_node);
      void insertNonFull(int key, Nodo* x);
      void printTree_rec(Nodo* x, int current_height);

      const unsigned char max_hijos;
      const unsigned char max_llaves;
      const unsigned char min_llaves;

   public:
      ArbolB();
      ArbolB(int orden);
      void insert(int key);
      void loadTree(char* file);
      void printTree();
};

#endif

