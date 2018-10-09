/*No selection sort, min recebe o indice i (para i<n-1, porque a comparação ocorrerá com o último elemento em n)
para que no for interior  ocorra a comparação de v com o indice j (menor elemento que está na posição n)
depois disso ocorre a troca do elemento v[i] com o último elemento menor (v[min])
*/
#include <stdio.h>
#include <stdlib.h>

//Selection Sort
void selectionSort(int v[], int n) {
   int i, j, min, x;
   
   for (i = 0; i < n-1; ++i) {
      min = i;
      
      for (j = i+1; j < n; ++j)    
         if (v[j] < v[min])                 
            min = j;              
      x = v[i]; 
      v[i] = v[min]; 
      v[min] = x;
   }
}
