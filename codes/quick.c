/*
Assim como o mergie sort, o quick é baseado no paradigma de divisão e conquista. Ele faz a ordenação dos elementos por particionamento 
ao dividir o problema com n elementos em dois problemas menores que posteriormente são ordenados. Depois disso, ocorre uma combinação
para rejuntar os elementos ordenados. É o método mais rápido para situações de praticidade.
*/
#include <stdio.h>
#include <stdlib.h>

#define troca(A, B) { int t = A; A = B; B = t; } 
typedef enum {FALSE, TRUE} bool;
    
//Quick Sort: função que possibilita fazer a troca dos elementos por meio do pivô. 
void swap(int *a, int i, int j) { 
   int t = a[i];                  
   a[i] = a[j];
   a[j] = t;
}

int partition(int *a, int left,int right,int pivot) //Função que realiza o particionamento
{
    int pos, i;
    swap(a, pivot, right);
    pos = left;
    for(i = left; i < right; i++)
    {
       if (a[i] < a[right]) // Comparação que vê se os elementos da esquerda (a[i]) são menores que os da direita (a[right]).
       {
          swap(a, i, pos); //Troca dos elementos comparados (a[i] com a[pos] com o incremento da chave pos).
          pos++;
       }
     }
     swap(a, right, pos); //Caso os da esquerda não sejam menores, a comparação é feita de forma inversa.
     return pos;
}

void quickSort( int *a, int left, int right)//Algoritimo de ordenação QuickSort
{
    if (left < right)
    {
        int pivot = (left+right)/2;
        int pos = partition(a,left,right,pivot);
        quickSort(a,left,pos-1);
        quickSort(a,pos+1,right);
    }
}

