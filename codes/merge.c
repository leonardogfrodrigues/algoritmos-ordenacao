/*
O mergie sort é um meio de ordenação por intercalação. É baseado no paradigma de divisão e conquista, que consiste em dividir o problema
em subproblemas, buscando soluções recursivas por meio de combinações.  
*/


#include <stdio.h>
#include <stdlib.h>

//Merge Sort 

void intercala( int p, int q, int r, int v[]) {  //Função intecala do MergeSort
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
   
   while (i < q)  //comparação do elemento na posicao i com outro elemento na posicao q; em que q representa o meio. 
      w[k++] = v[i++];
   while (j < r)  // comparação do elemento na posicao j com o outro elemento da posicao r, meio com o final (j com r).
      w[k++] = v[j++];
      
   for (i = p; i < r; ++i)
       v[i] = w[i-p]; //Depois da divisão, o algorítmo coloca os elementos no vetor original (conquista).
       
   free(w);
}

void mergeSort( int v[], int p, int r) {//Algoritimo de Ordenação MergeSort
   int q;
     
   if (p < r-1) {
      q = (p + r) / 2;
      
      mergeSort(v, p, q);
      mergeSort(v, q, r);
      
      intercala( p, q, r, v);
   }
}

