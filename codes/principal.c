/* Universidade Federal de Vicosa campus UFV de Rio Parana?ba
Disciplina: SIN 2113 - Projeto de Algoritmos
Professor: Joelson
Leonardo Gabriel F. Rodrigues 
 
*/

//Biblioteca Padr?o do C para entrada e sa?da
#include <stdio.h>
//Biblioteca Padr?o do C �til para opera��es de aloca��o de mem�ria, controle de processos, convers�es, etc.
#include <stdlib.h>
//Biblioteca Padr?o do C para manipula��o de Tempo
#include <time.h>

//Inclus�o das fun��es necess�rias para o funcionamento do programa
#include "insertion.c"
#include "merge.c"
#include "quick.c"
#include "selection.c"
#include "heap.c"
#include "shell.c"
  

/*in�cio gerador das inst�ncias*/
int numeroAleatorio(int maximo) {//Chamada da fun��o que retorna um n�mero aleat�rio
    return (rand() % maximo);
}
void randomize();

void salvaInstancia(char *nomeArq, int tipoDisposicao, int tamanhoInstancia) {//Salva a instancia gerada aleatoriamente e salva no array, no arquivo texto.
     int i;
     FILE *fp;
     
     fp = fopen(nomeArq, "w+");
     
     if (fp != NULL) {
         
         //Escolher a disposicao dos numeros
         if(tipoDisposicao == 0){//Crescente
             for (i = 0; i < tamanhoInstancia; i++)
             fprintf(fp, "%d\n", i);
         }
         if(tipoDisposicao == 1){//Aleatorio
             randomize();    
             for (i = 0; i < tamanhoInstancia; i++)
                 fprintf(fp, "%d\n", numeroAleatorio(tamanhoInstancia));   
         }
         if(tipoDisposicao == 2){//Decrescente
             for (i = tamanhoInstancia - 1; i >= 0; i--)
             fprintf(fp, "%d\n", i);    
         }
     } else {//Caso nao for poss�vel abrir o arquivo informa ao usuario
         printf("\n\nErro ao Salvar arquivo.\n");
     }   
     
     fclose(fp);//Fecha arquivo
}
void randomize(){//Funcao para retirar informacoes de hora do sistema, para gerar numeros aleatorios
    srand(time(NULL));//diferentes em cada interaco do algoritimo
}
 
int tamanhoVetor;//Variavel que armazena o tamanho do vetor




 
int *carregaDados(char *nomeArq) {
    FILE *fp;
    int num, *v;
     
    fp = fopen(nomeArq, "r+");
     
    if (fp != NULL) {
         
        v = (int *) malloc (sizeof(int));
        tamanhoVetor = 0;
             
        while ( (fscanf(fp, "%d", &num)) != EOF ) {
              v[tamanhoVetor] = num;          
              tamanhoVetor++;
              v = (int *) realloc (v, sizeof(int) * (tamanhoVetor + 1));
        }
         
    } else
      printf("\n\nErro ao carregar arquivo.\n\n");
     
    fclose(fp);
    return v;//Retorna o array apontado por v, para poder ser odenado
} 
 
int escreveOrdenado(char *nomeArq, int *v) {
    FILE *fp;
    int i;
     
    fp = fopen(nomeArq, "w+");
     
    if (fp != NULL) {
       for ( i = 0; i < tamanhoVetor; i++)
           fprintf(fp, "%d\n", v[i]);        
    } else
      printf("\n\nErro ao carregar arquivo.\n\n");
     
    fclose(fp);//Fecha arquivo
    return 0;
}
 
int salvaTempo(char *nomeArq, double tempoExecucao, int tamanho, char* nomeAlgoritimo, char configuracaoDaInstancia) {
    FILE *fp;
     
    fp = fopen(nomeArq, "aw+");
     
    if (fp != NULL) {
        fprintf(fp, "Tamanho da Instancia: %d \nTempo de Execucao: %.15f\nNome Algotitimo: %s \nConfiguracao da Entrada: %c \n\n", tamanhoVetor, tempoExecucao, nomeAlgoritimo, configuracaoDaInstancia);
    } else
      printf("\n\nErro ao carregar arquivo.\n\n");
     
    fclose(fp);
    return 0;
}

void trataOpcao(int opcao){
	if(opcao == 1){//quando for insertion sort
		
		int tipo;
		int tamanho;
		char configuracaoDaInstancia;
		
		system("cls");
		
		printf("\nFormato da Entrada");
		printf("\n1 - Decrescente");
		printf("\n2 - Crescente");
		printf("\n3 - Aleatorio\n");
		scanf("%d",&tipo);
		printf("\n2 - Tamanho da Entrada\n");
		scanf("%d",&tamanho);
		
		if(tipo == 1){
			salvaInstancia("instancia.txt",2,tamanho);
			configuracaoDaInstancia = 'd';
		}
		else{
			if(tipo == 2){
				salvaInstancia("instancia.txt",0,tamanho);
				configuracaoDaInstancia = 'c';
			}
			else{
				if(tipo == 3){
					salvaInstancia("instancia.txt",1,tamanho);		
					configuracaoDaInstancia = 'r';
				}
				else{
					printf("\nTipo de instancia incorreto!");
					system("pause");
					exit(1);
				}	
			}
		}
	
		
		//salvaInstancia();
		int *v, i,j; //Variavel que aponta para o vetor e iteradoras
    	double tInicial, tFinal; //Variaveis para armazenar o tempo inicial e final
     
    	v = carregaDados("instancia.txt");//Carrega os dados do arquivo texto para a mem�ria
         
        tInicial = 0;
        tFinal = 0;
     
        tInicial = (double) clock() / CLOCKS_PER_SEC;//Captura do tempo inicial da CPU
     
        insertionSort(v, tamanhoVetor); //Chamada do algoritimo de ordena��o
     
        tFinal = (double) clock() / CLOCKS_PER_SEC;//Captura do tempo final da CPU
     
        escreveOrdenado("ordenado.txt", v);//O vetor ordenado e escrito no arquivo
     
        printf("%c",configuracaoDaInstancia);
		salvaTempo("tempos.txt", tFinal - tInicial, tamanho, "InsertionSort", configuracaoDaInstancia);//Tempo final - Tempo inicial configura o tempo total gasto na ordena��o da inst�ncia
        
		printf("\nInstancia Ordenada - Checar Arquivos \n");
		system("pause");
		system("cls");
	}
	else{
		if(opcao == 2){//quando for merge sort
		
		int tipo;
		int tamanho;
		char configuracaoDaInstancia;
		
		system("cls");
		
		printf("\nFormato da Entrada");
		printf("\n1 - Decrescente");
		printf("\n2 - Crescente");
		printf("\n3 - Aleatorio\n");
		scanf("%d",&tipo);
		printf("\n2 - Tamanho da Entrada\n");
		scanf("%d",&tamanho);
		
		if(tipo == 1){
			salvaInstancia("instancia.txt",2,tamanho);
			configuracaoDaInstancia = 'd';
		}
		else{
			if(tipo == 2){
				salvaInstancia("instancia.txt",0,tamanho);
				configuracaoDaInstancia = 'c';
			}
			else{
				if(tipo == 3){
					salvaInstancia("instancia.txt",1,tamanho);		
					configuracaoDaInstancia = 'r';
				}
				else{
					printf("\nTipo de instancia incorreto!");
					system("pause");
					exit(1);
				}	
			}
		}
	
		//salvaInstancia();
		int *v, i,j; //Variavel que aponta para o vetor e iteradoras
    	double tInicial, tFinal; //Variaveis para armazenar o tempo inicial e final
     
    	v = carregaDados("instancia.txt");//Carrega os dados do arquivo texto para a memoria
         
        tInicial = 0;
        tFinal = 0;
     
        tInicial = (double) clock() / CLOCKS_PER_SEC;//Captura do tempo inicial da CPU
     
        mergeSort(v, 0,tamanhoVetor); //Chamada do algoritimo de ordena��o
     
        tFinal = (double) clock() / CLOCKS_PER_SEC;//Captura do tempo final da CPU
     
        escreveOrdenado("ordenado.txt", v);//O vetor ordenado � escrito no arquivo
     
        printf("%c",configuracaoDaInstancia);
		salvaTempo("tempos.txt", tFinal - tInicial, tamanho, "MergeSort", configuracaoDaInstancia);//Tempo final - Tempo inicial configura o tempo total gasto na ordena��o da inst�ncia
        
		printf("\nInstancia Ordenada - Checar Arquivos \n");
		system("pause");
		system("cls");
	}
	
		else{
			if (opcao ==3){//quando for selection
				int tipo;
				int tamanho;
				char configuracaoDaInstancia;
				
				system("cls");
				
				printf("\nFormato da Entrada");
				printf("\n1 - Decrescente");
				printf("\n2 - Crescente");
				printf("\n3 - Aleatorio\n");
				scanf("%d",&tipo);
				printf("\n2 - Tamanho da Entrada\n");
				scanf("%d",&tamanho);
				
				if(tipo == 1){
					salvaInstancia("instancia.txt",2,tamanho);
					configuracaoDaInstancia = 'd';
				}
				else{
					if(tipo == 2){
						salvaInstancia("instancia.txt",0,tamanho);
						configuracaoDaInstancia = 'c';
					}
					else{
						if(tipo == 3){
							salvaInstancia("instancia.txt",1,tamanho);		
							configuracaoDaInstancia = 'r';
						}
						else{
							printf("\nTipo de instancia incorreto!");
							system("pause");
							exit(1);
						}	
					}
				}
				
				//salvaInstancia();
				int *v, i,j; //Vari�vel que aponta para o vetor e iteradoras
		    	double tInicial, tFinal; //Vari�veis para armazenar o tempo inicial e final
		     
		    	v = carregaDados("instancia.txt");//Carrega os dados do arquivo texto para a mem�ria
		         
		        tInicial = 0;
		        tFinal = 0;
		     
		        tInicial = (double) clock() / CLOCKS_PER_SEC;//Captura do tempo inicial da CPU
		     
		        selectionSort(v, tamanhoVetor); //Chamada do algoritimo de ordena��o
		     
		        tFinal = (double) clock() / CLOCKS_PER_SEC;//Captura do tempo final da CPU
		     
		        escreveOrdenado("ordenado.txt", v);//O vetor ordenado � escrito no arquivo
		     
		        printf("%c",configuracaoDaInstancia);
				salvaTempo("tempos.txt", tFinal - tInicial, tamanho, "SelectionSort", configuracaoDaInstancia);//Tempo final - Tempo inicial configura o tempo total gasto na ordena��o da inst�ncia
		        
				printf("\nInstancia Ordenada - Checar Arquivos \n");
				system("pause");
				system("cls");
		 	}
		 	
		 	else{
		 		if(opcao==4){
			 		int tipo;
					int tamanho;
					char configuracaoDaInstancia;
					
					system("cls");
					
					printf("\nFormato da Entrada");
					printf("\n1 - Decrescente");
					printf("\n2 - Crescente");
					printf("\n3 - Aleatorio\n");
					scanf("%d",&tipo);
					printf("\n2 - Tamanho da Entrada\n");
					scanf("%d",&tamanho);
					
					if(tipo == 1){
						salvaInstancia("instancia.txt",2,tamanho);
						configuracaoDaInstancia = 'd';
					}
					else{
						if(tipo == 2){
							salvaInstancia("instancia.txt",0,tamanho);
							configuracaoDaInstancia = 'c';
						}
						else{
							if(tipo == 3){
								salvaInstancia("instancia.txt",1,tamanho);		
								configuracaoDaInstancia = 'r';
							}
							else{
								printf("\nTipo de instancia incorreto!");
								system("pause");
								exit(1);
							}	
						}
					}
					
					//salvaInstancia();
					int *v, i,j; //Variável que aponta para o vetor e iteradoras
			    	double tInicial, tFinal; //Variáveis para armazenar o tempo inicial e final
			     
			    	v = carregaDados("instancia.txt");//Carrega os dados do arquivo texto para a memória
			         
			        tInicial = 0;
			        tFinal = 0;
			     
			        tInicial = (double) clock() / CLOCKS_PER_SEC;//Captura do tempo inicial da CPU
			     
			        quickSort(v, 0, tamanhoVetor); //Chamada do algoritimo de ordenação
			     
			        tFinal = (double) clock() / CLOCKS_PER_SEC;//Captura do tempo final da CPU
			     
			        escreveOrdenado("ordenado.txt", v);//O vetor ordenado é escrito no arquivo
			     
			        printf("%c",configuracaoDaInstancia);
					salvaTempo("tempos.txt", tFinal - tInicial, tamanho, "quickSort", configuracaoDaInstancia);//Tempo final - Tempo inicial configura o tempo total gasto na ordenação da instância
			        
					printf("\nInstancia Ordenada - Checar Arquivos \n");
					system("pause");
					system("cls");
			}
			
			else{
				if(opcao==5){
					int tipo;
					int tamanho;
					char configuracaoDaInstancia;
					
					system("cls");
					
					printf("\nFormato da Entrada");
					printf("\n1 - Decrescente");
					printf("\n2 - Crescente");
					printf("\n3 - Aleatorio\n");
					scanf("%d",&tipo);
					printf("\n2 - Tamanho da Entrada\n");
					scanf("%d",&tamanho);
					
					if(tipo == 1){
						salvaInstancia("instancia.txt",2,tamanho);
						configuracaoDaInstancia = 'd';
					}
					else{
						if(tipo == 2){
							salvaInstancia("instancia.txt",0,tamanho);
							configuracaoDaInstancia = 'c';
						}
						else{
							if(tipo == 3){
								salvaInstancia("instancia.txt",1,tamanho);		
								configuracaoDaInstancia = 'r';
							}
							else{
								printf("\nTipo de instancia incorreto!");
								system("pause");
								exit(1);
							}	
						}
					}
					
					//salvaInstancia();
					int *v, i,j; //Variável que aponta para o vetor e iteradoras
			    	double tInicial, tFinal; //Variáveis para armazenar o tempo inicial e final
			     
			    	v = carregaDados("instancia.txt");//Carrega os dados do arquivo texto para a memória
			         
			        tInicial = 0;
			        tFinal = 0;
			     
			        tInicial = (double) clock() / CLOCKS_PER_SEC;//Captura do tempo inicial da CPU
			     
			        heapsort(v, tamanhoVetor); //Chamada do algoritimo de ordenação
			     
			        tFinal = (double) clock() / CLOCKS_PER_SEC;//Captura do tempo final da CPU
			     
			        escreveOrdenado("ordenado.txt", v);//O vetor ordenado é escrito no arquivo
			     
			        printf("%c",configuracaoDaInstancia);
					salvaTempo("tempos.txt", tFinal - tInicial, tamanho, "heapSort", configuracaoDaInstancia);//Tempo final - Tempo inicial configura o tempo total gasto na ordenação da instância
			        
					printf("\nInstancia Ordenada - Checar Arquivos \n");
					system("pause");
					system("cls");
				}
				
				else{
					if(opcao==6){
											int tipo;
					int tamanho;
					char configuracaoDaInstancia;
					
					system("cls");
					
					printf("\nFormato da Entrada");
					printf("\n1 - Decrescente");
					printf("\n2 - Crescente");
					printf("\n3 - Aleatorio\n");
					scanf("%d",&tipo);
					printf("\n2 - Tamanho da Entrada\n");
					scanf("%d",&tamanho);
					
					if(tipo == 1){
						salvaInstancia("instancia.txt",2,tamanho);
						configuracaoDaInstancia = 'd';
					}
					else{
						if(tipo == 2){
							salvaInstancia("instancia.txt",0,tamanho);
							configuracaoDaInstancia = 'c';
						}
						else{
							if(tipo == 3){
								salvaInstancia("instancia.txt",1,tamanho);		
								configuracaoDaInstancia = 'r';
							}
							else{
								printf("\nTipo de instancia incorreto!");
								system("pause");
								exit(1);
							}	
						}
					}
					
					//salvaInstancia();
					int *v, i,j; //Variável que aponta para o vetor e iteradoras
			    	double tInicial, tFinal; //Variáveis para armazenar o tempo inicial e final
			     
			    	v = carregaDados("instancia.txt");//Carrega os dados do arquivo texto para a memória
			         
			        tInicial = 0;
			        tFinal = 0;
			     
			        tInicial = (double) clock() / CLOCKS_PER_SEC;//Captura do tempo inicial da CPU
			     
			        shellsort(v, tamanhoVetor); //Chamada do algoritimo de ordenação
			     
			        tFinal = (double) clock() / CLOCKS_PER_SEC;//Captura do tempo final da CPU
			     
			        escreveOrdenado("ordenado.txt", v);//O vetor ordenado é escrito no arquivo
			     
			        printf("%c",configuracaoDaInstancia);
					salvaTempo("tempos.txt", tFinal - tInicial, tamanho, "shellSort", configuracaoDaInstancia);//Tempo final - Tempo inicial configura o tempo total gasto na ordenação da instância
			        
					printf("\nInstancia Ordenada - Checar Arquivos \n");
					system("pause");
					system("cls");
					}
				}
			}
			
		}
	}
}
}


//Funcao Principal
int main(int argc, char** argv) {
	
	int opcao;
	
	//Cor de fundo azul escuro com letras brancas
    system("color 1F");
    
	printf("::. PROGRAMA DE ORDENA%c%cO .::\n", 128,199);
	
	printf("\n\n Escolha uma op%c%co: \n",135,198);
	do{
		printf("\n 1 - InsertionSort");
		printf("\n 2 - MergeSort");
		printf("\n 3 - SelectionSort");
		printf("\n 4 - QuickSort");
		printf("\n 5 - HeapSort");	
		printf("\n 6 - ShellSort");			
		printf("\n 0 - Sair\n");
		scanf("%d",&opcao);
		if(opcao!=0){
			trataOpcao(opcao);
		}
	}while(opcao != 0);
	
}
