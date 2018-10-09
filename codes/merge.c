/*
O mergie sort � um meio de ordena��o por intercala��o. � baseado no paradigma de divis�o e conquista, que consiste em dividir o problema
em subproblemas, buscando solu��es recursivas por meio de combina��es.  
*/


#include <stdio.h>
#include <stdlib.h>

//Merge Sort 

void intercala( int p, int q, int r, int v[]) {  //Fun��o intecala do MergeSort
   int i, j, k, *w;
   
   w = malloc( (r-p) * sizeof (int));
   i = p; 
   j = q;
   k = 0;

   while (i < q && j < r) {  
      if (v[i] <= v[j])       
         w[k++] = v[i++];   
      else  
         w[k++] = v[j++];
   }
   
   while (i < q)  //compara��o do elemento na posicao i com outro elemento na posicao q; em que q representa o meio. 
      w[k++] = v[i++];
   while (j < r)  // compara��o do elemento na posicao j com o outro elemento da posicao r, meio com o final (j com r).
      w[k++] = v[j++];
      
   for (i = p; i < r; ++i)
       v[i] = w[i-p]; //Depois da divis�o, o algor�tmo coloca os elementos no vetor original (conquista).
       
   free(w);
}

void mergeSort( int v[], int p, int r) {//Algoritimo de Ordena��o MergeSort
   int q;
     
   if (p < r-1) {
      q = (p + r) / 2;
      
      mergeSort(v, p, q);
      mergeSort(v, q, r);
      
      intercala( p, q, r, v);
   }
}

