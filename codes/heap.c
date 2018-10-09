/*
O heap sort possui a mesma forma de funcionamento do selection, visto que o menor elemento do vetor é selecionado e depois trocado com 
o elemento da primeira posição. Para isso, coloca-se os elementos numa árvore, e caso o último elemento seja maior que seu pai, ocorre 
uma troca deles; o elemento que agora é o último é isolado e recolocado no vetor.
*/

#include <stdio.h>
#include <stdlib.h>

//Heap Sort 
void peneira(int vet[], int raiz, int fundo); //Escopo da função que faz a comparação dos elementos (pais com os folhas) numa 
												// árvore e faz a troca do menor com o maior, pondo este nas folhas.
void heapsort(int vet[], int n) { //Funcao que recoloca os elementos no vetor ao passo que eles são ordenados
	int i, tmp;

	for (i = (n / 2); i >= 0; i--) {
		peneira(vet, i, n - 1); // montagem da heap pelo vetor original
	}

	for (i = n-1; i >= 1; i--) {
		tmp = vet[0]; //o maior é colocado na última posição
		vet[0] = vet[i];
		vet[i] = tmp;
		peneira(vet, 0, i-1); //isolamento do ítem colocado na última posição
	}
}

void peneira(int *vet, int raiz, int fundo) {
	int pronto, filhoMax, tmp;

	pronto = 0;
	while ((raiz*2 <= fundo) && (!pronto)) { // Compara se o pai é menor ou igual ao nós folhas, se for ocorre a troca com o filho
		if (raiz*2 == fundo) {
			filhoMax = raiz * 2;
		}
		else if (vet[raiz * 2] > vet[raiz * 2 + 1]) { //Compara se o pai é maior do que o próximo nó folha, se for, não há trocas.
			filhoMax = raiz * 2;
		}
		else{
			filhoMax = raiz * 2 + 1; //se não for maior, ocorre a troca com o nó folha comparado.
		}

		if (vet[raiz] < vet[filhoMax]) { //Compara se o pai é menor do que o filho
			tmp = vet[raiz];             // Da linha 45 a 48 realiza as trocas por meio de um tmp, caso seja menor 
			vet[raiz] = vet[filhoMax];
			vet[filhoMax] = tmp;
			raiz = filhoMax;
    	}
		else {
    	  pronto = 1;
		}
  	}		
}
