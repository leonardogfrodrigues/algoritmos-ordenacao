/*
O shell sort, é uma extensao do insertion sort. Enquanto o insertion permitia apenas a troca de itens adjacentes, o shell corrige 
este problema, permitindo trocas de elementos que se distanciam um do outro. Isso ocorre por meio da separação dos elementos por inter-
valos (gaps) ou h, em que o h-ésimo ítem leva a uma sequência ordenada. 
*/

#include <stdio.h>
#include <stdlib.h>

//Shell Sort

void shellsort(int a[], int size)
{
 int i , j , value;
 int gap = 1;
  
 do {
  gap = 3*gap+1; // Formula que resulta em um valor de sequencia do intervalo.
 }while(gap < size);
  
 do{
  gap /= 3; //O valor achado anteriormente é dividido por 3. Quando o valor do intervalo é 1, ocorre o insertion.
  for(i = gap; i < size; i++) {
   value = a[i];
   j = i - gap;
    
   while (j >= 0 && value < a[j]) {
    a[j + gap] = a[j];                //Comparação dos elementos distantes hN um do outro.
    j -= gap;
   }
   a[j + gap] = value;
  }
 }while(gap > 1);
}
