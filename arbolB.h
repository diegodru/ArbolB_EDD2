#ifndef ARBOLB_H
#define ARBOLB_H

#include <utility>

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
      Nodo* split(Nodo* padre, Nodo* hijo, int key, int indice);
      void insertNonFull(int key, Nodo* x);

      const unsigned char max_hijos;
      const unsigned char max_llaves;
      const unsigned char min_llaves;

   public:
      ArbolB(int orden);
      void insert(int key);
};

#endif

