/*
Assim como o mergie sort, o quick � baseado no paradigma de divis�o e conquista. Ele faz a ordena��o dos elementos por particionamento 
ao dividir o problema com n elementos em dois problemas menores que posteriormente s�o ordenados. Depois disso, ocorre uma combina��o
para rejuntar os elementos ordenados. � o m�todo mais r�pido para situa��es de praticidade.
*/
#include <stdio.h>
#include <stdlib.h>

#define troca(A, B) { int t = A; A = B; B = t; } 
typedef enum {FALSE, TRUE} bool;
    
//Quick Sort: fun��o que possibilita fazer a troca dos elementos por meio do piv�. 
void swap(int *a, int i, int j) { 
   int t = a[i];                  
   a[i] = a[j];
   a[j] = t;
}

int partition(int *a, int left,int right,int pivot) //Fun��o que realiza o particionamento
{
    int pos, i;
    swap(a, pivot, right);
    pos = left;
    for(i = left; i < right; i++)
    {
       if (a[i] < a[right]) // Compara��o que v� se os elementos da esquerda (a[i]) s�o menores que os da direita (a[right]).
       {
          swap(a, i, pos); //Troca dos elementos comparados (a[i] com a[pos] com o incremento da chave pos).
          pos++;
       }
     }
     swap(a, right, pos); //Caso os da esquerda n�o sejam menores, a compara��o � feita de forma inversa.
     return pos;
}

void quickSort( int *a, int left, int right)//Algoritimo de ordena��o QuickSort
{
    if (left < right)
    {
        int pivot = (left+right)/2;
        int pos = partition(a,left,right,pivot);
        quickSort(a,left,pos-1);
        quickSort(a,pos+1,right);
    }
}

