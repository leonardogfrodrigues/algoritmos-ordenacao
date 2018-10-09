/*
No insertion sort, ocorre as comparações do
i-ésimo elemento com o j-ésimo elemento, se v[j] for menor que v[i], ocorre a troca.
*/
#include <stdio.h>
#include <stdlib.h>

//Insertion Sort 
void insertionSort(int v[], int n) {
    int i, j;
    int aux; 
 
    for (i = 1; i < n; i++) {
        aux = v[i]; 
 
        for (j = i - 1; j > -1 && v[j] > v[i]; j--) {
            v[i--] = v[j];    
            v[j] = aux;	     
        }
    }
}
