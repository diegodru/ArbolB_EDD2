#include "arbolB.h"

ArbolB::ArbolB(int orden) : max_hijos(orden), max_llaves(orden - 1), min_llaves(orden/2 - 1){
   raiz = new Nodo{ .hijos = new Nodo*[max_hijos], .llaves = new int[max_llaves] };
}

void splitWithBuffer(Nodo* padre, Nodo* hijo, int key, int indice, Nodo* buffer_node){

}

void ArbolB::split(Nodo* padre, Nodo* hijo, int key, int indice){
   for(int i = 0; i < hijo->num_de_llaves; i++)
      if(key < hijo->llaves[i])
         std::swap(key, hijo->llaves[i]);
   Nodo* buffer_node = new Nodo { .hijos = new Nodo*[max_hijos], .llaves = new int[max_llaves] };

   for(int j = max_hijos/2 + 1; j < max_llaves; j++)
      buffer_node->llaves[buffer_node->num_de_llaves++] = hijo->llaves[j];
   buffer_node->llaves[buffer_node->num_de_llaves++] = key;

   //organizar los hijos respectivamente
   for(int j = 0; j < max_hijos/2 - 1; j++)
      buffer_node->hijos[j] = hijo->hijos[j + max_hijos - max_hijos/2 + 1]; 

   for(int k = max_hijos - 1; k > 0; k--)
      hijo->hijos[k] = hijo->hijos[k - 1];

   hijo->num_de_llaves = max_llaves - min_llaves;
   key = hijo->llaves[max_hijos/2];

   if(padre != nullptr){
      if(padre->llaves[indice] > key){
         std::swap(padre->llaves[indice], key);
         std::swap(padre->hijos[indice + 1], buffer_node);
      }
      padre->llaves[padre->num_de_llaves] = key;
      padre->hijos[padre->num_de_llaves++ + 1] = buffer_node;

      buffer_node->padre = padre;
      hijo->padre = padre;
      //sort llaves e hijos del padre con el buffer_node
      for(int i = indice + 1; i < padre->num_de_llaves; i++){
         std::swap(key, padre->llaves[i]);
         std::swap(buffer_node, padre->hijos[i]);
      }
   }else{
      raiz = new Nodo{ .hijos = new Nodo*[max_hijos], .llaves = new int[max_llaves]};
      raiz->llaves[0] = key;
      raiz->hijos[0] = hijo;
      raiz->hijos[1] = buffer_node;
      raiz->es_nodo_hoja = false;
      raiz->num_de_llaves++;
      hijo->padre = raiz;
      buffer_node->padre = raiz;
   }
}


void ArbolB::insertNonFull(int key, Nodo* x){
   int indice = x->num_de_llaves - 1;
   if(x->es_nodo_hoja){
      while(indice >= 0 && key < x->llaves[indice]){
         x->llaves[indice + 1] = x->llaves[indice]; //
         indice--;
      }
      if(x->num_de_llaves == max_llaves)
         split(x->padre, x, key, indice);
      else{
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
   insertNonFull(key, raiz); 
}

void ArbolB::printTree_rec(Nodo* x, int current_height){
   if(x == nullptr)
      return;
   for(int i = 0; i < current_height; i++)
      std::cout << "- ";
   for(int i = 0; i < x->num_de_llaves - 1; i++)
      std::cout << x->llaves[i] << ", ";
   std::cout << x->llaves[x->num_de_llaves - 1] << '\n';
   for(int i = 0; i < max_hijos; i++)
      printTree_rec(x->hijos[i], current_height + 1);
}

void ArbolB::printTree(){
   printTree_rec(raiz, 0);
}
