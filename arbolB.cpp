#include "arbolB.h"

ArbolB::ArbolB(int orden) : max_hijos(orden), max_llaves(orden - 1), min_llaves(orden/2 - 1){
   raiz = new Nodo{ .hijos = new Nodo*[max_hijos], .llaves = new int[max_llaves] };
}

Nodo* ArbolB::split(Nodo* padre, Nodo* hijo, int key, int indice){
   for(int i = 0; i < hijo->num_de_llaves; i++)
      if(key < hijo->llaves[i])
         std::swap(key, hijo->llaves[i]);
   Nodo* buffer_node = new Nodo { .hijos = new Nodo*[max_hijos], .llaves = new int[max_llaves] };

   for(int j = max_hijos/2 + 1, k = 0; j < max_hijos; j++)
      buffer_node->llaves[k++] = hijo->llaves[j];
   buffer_node->llaves[max_hijos/2 - 1] = key;
   buffer_node->num_de_llaves = min_llaves;

   //organizar los hijos respectivamente
   for(int j = 0; j < max_hijos/2 - 1; j++)
      buffer_node->hijos[j] = hijo->hijos[j + max_hijos - max_hijos/2 + 1];
   for(int k = max_hijos - 1; k >= 0; k--)
      hijo->hijos[k] = hijo->hijos[k - 1];
   hijo->num_de_llaves = max_llaves - min_llaves - 1;
   key = hijo->llaves[max_hijos/2];
   std::swap(padre->llaves[indice], key);
   std::swap(padre->hijos[indice], buffer_node);
}

void ArbolB::insertNonFull(int key, Nodo* x){
   int indice = x->num_de_llaves - 1;
   if(x->es_nodo_hoja){
      if(x->num_de_llaves == max_llaves){

      }else{
         while(indice >= 0 && key < x->llaves[indice]){
            x->llaves[indice + 1] = x->llaves[indice];
            indice--;
         }
         x->llaves[indice + 1] = key;
         x->num_de_llaves++;
      }
   }else{
      while(indice >= 0 && key < x->llaves[indice])
         indice--;
      indice++;
      insertNonFull(key, x->hijos[indice]);
   }
}

void ArbolB::insert(int key){

}
