#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#define coluna 4


/****
*
* T�tulo: AlocaMatriz
*
* Autor: Tulio Campos
*
* Data de Cria��o: 20/07/2016
* �ltima modifica��o: 25/07/2016
*
* Descri��o: A fun��o aloca uma matriz.
*
* Par�metros:
*   (entrada)
*           const int l:  Representa o n�mero de linhas (discos) da matriz.
*          	 
*
* Valor de retorno: A fun��o retorna a matriz alocada.
*
****/


int ** Aloca_matriz(const int);

/****
*
* T�tulo: LiberaMatriz
*
* Autor: Tulio Campos
*
* Data de Cria��o: 20/07/2016
* �ltima modifica��o:25/07/2016
*
* Descri��o: Libera uma matriz alocada dinamicamente.
*
* Par�metros:
*   (entrada)
*           int **m: Ponteiro que aponta para a matriz que foi alocada e definida na fun��o AlocaMatriz.
*          
* Valor de retorno: void.
*
****/

void Libera_matriz(int **);

/****
*
* T�tulo: Inicializa_controle
*
* Autor: Tulio Campos
*
* Data de Cria��o: 20/07/2016
* ultima modifica��o: 25/07/2016
*
* Descri��o: A fun��o zera a matriz n�merica , e coloca os valores correspondente ao tamanho dos discos na primeira coluna.
*
* Par�metros:
*   (entrada)
*    const int num:  N�mero de discos digitado pelo usuario.
*	 int **m:  � um ponteiro que aponta para a matriz que j� foi alocada e definida na fun��o Aloca_Matriz.
* Valor de retorno: A fun��o n�o possui retorno.
*
****/


void Inicializa_controle(int**,const int);


/****
*
* T�tulo: Move_disco
*
/* Autor: Tulio Campos
*
* Data de Cria��o: 20/07/2016
* Ultima modifica��o: 25/07/2016
*
* Descri��o: A fun��o define a posi��o do disco de origem atrav�s do par�metro de entrada, depois verifica para onde ele deve ser copiado (haste de destino)
*            Ent�o, copia o disco da  posi��o  de origem para a posi��o de destino, e substitui a  posi��o de origem onde o disco estava por 0.
*			 Depois chama a fun��o saida para imprimir a nova posi��o dos discos na tela.
* Par�metros:
*   (entrada)
*       int:  inicio, Posi��o  de origem do disco,onde o disco se encontra.
*		int:  final,  Posi��o  de destino ,para onde o disco deve ser movido.
*		int  *n    ,  N�mero de discos digitado pelo usuario.
*		int  **m,     Ponteiro que aponta para a matriz n�merica que contem a posi��o dos discos.
*		FILE *f,      Ponteiro para o arquivo .txt criado no in�cio do programa, usado para a fun��o fprintf.
* Valor de retorno: A fun��o n�o possui retorno.
*
****/


void Move_disco(int, int, int*, int**, FILE *f);


/****
*
* T�tulo: Torre_hanoi
*
* Autor: Tulio Campos
*
* Data de Cria��o: 20/07/2016
* ultima modifica��o: 25/07/2016
*
* Descris��o: A fun��o faz uma s�rie de chamadas recursivas para resolver o problema em quest�o.
*
* Par�metros:
*   (entrada)
		int:    *n,   n�mero de discos digitado pelo usuario ,que ir� ser usado na fun��o move disco.
*		int:	N ,   n�mero de discos digitado pelo usuario,que ir� ser usado na fun��o
*       int:	orig, haste de origem do disco,onde os discos se encontram.
*		int:	aux1, haste auxiliar que recebe os discos temporariamente.
*       int:	aux2, haste auxiliar que recebe os discos temporariamente.
*		int:	dest, haste de destino ,para onde os discos devem ser movidos.
*       int:    **m,  Ponteiro que aponta para a matriz n�merica que contem a posi��o dos discos.
*		FILE:   *f,   Ponteiro para o arquivo .txt criado no in�cio do programa, usado para a fun��o fprintf.
* Valor de retorno: A fun��o n�o possui retorno.
*
****/


void Torre_hanoi(int*, int, int, int, int, int,int**,FILE *f);


/****
*
* T�tulo: Saida
*
/* Autor: Tulio Campos
*
* Data de Cria��o: 20/07/2016
* Ultima modifica��o: 25/07/2016
*
* Descri��o: A fun��o transforma a matriz n�merica , no print grafico das torres de hanoi , e printa toda vez que os discos s�o movimentados .
*           
*
* Par�metros:
*   (entrada)
*       
*		int  *n    ,  N�mero de discos digitado pelo usuario.
*		int  **m   ,  Ponteiro que aponta para a matriz n�merica que contem a posi��o dos discos.
*		FILE *f    ,  Ponteiro para o arquivo .txt criado no in�cio do programa, usado para a fun��o fprintf.
* Valor de retorno: A fun��o n�o possui retorno.
*
****/


void Saida(int **,int *n, FILE *f);


int main (void)
{
	int num, **m;// matriz
	FILE *f;
	setlocale(LC_ALL, "portuguese");
	system("cls");	
	printf("\n\n\n");
	printf("                                    Torre de Hanoi                                                      \n" );
	printf("  +-----------------------------------------------------------------------------------------------------+\n");
	printf("  | Descri��o: Dada quatro hastes(A;B;C e D), existem n discos de v�rios tamanhos na haste A,colocados  |\n" );
	printf("  | em ordem decrescente segundo o tamanho.Os discos dever�o ser movimentados da haste A para a haste D |\n" );
	printf("  | com o menor n�mero de movimentos respeitando as seguintes restri��es :                              |\n" );
	printf("  | * Pode-se mover um �nico disco por vez;	                                                        |\n" );
	printf("  | * Nunca colocar um disco em outro lugar que n�o seja uma das Quatros hastes.                        |\n" );
	printf("  | * Nunca colocar um disco maior sobre um disco menor;                                                |\n");
	printf("  | Autor:Tulio Campos Silva                                                                            |\n" );
	printf("  +-----------------------------------------------------------------------------------------------------+\n");
	
	Sleep(10000);

	printf ("\nDigite o n�mero de discos desejados : ");
	scanf ("%d",&num);
	
	if (num>10)
		printf ("O n�mero de discos informados � grande, com isso pode ocorrer o desbordamento da tela do computador ao printar,\n"
			" mas a solu��o para n�mero de discos desejados pode ser encontrada no arquivo de nome hanoi.txt .\n ");
	
	m=Aloca_matriz(num+1);

	if ((f=fopen("hanoi.txt","w"))==NULL)
	{
	 	printf("Erro ao criar arquivo!!!\n");
	 	exit(1);
	}

	Inicializa_controle(m,num);
	Torre_hanoi(&num,num,0,1,2,3,m,f);
	fclose(f);
	Libera_matriz(m);
	system ("pause");
	return 0;
}

void Inicializa_controle(int **m, const int num)
{
    int cont,cont2,disco,linha;

    /* zera tudo */
    for (linha = 0; linha < num; linha++)
    {
        for (cont2 = 0; cont2 < 4; cont2++)
        {
            m[linha][cont2] = 0;
        }
		

    }
    /* coloca os discos na primeira torre */
    disco = 2*num-1;
    linha = num-1; 
    
    for (cont = 1; cont <= num; cont++)
    {
        m[linha][0] = disco; // preenche a primeira coluna com os discos.
        disco -= 2;
        linha--;
    }
}


void Move_disco(int inicio, int final, int *n, int **m, FILE *f)

{
    int disco,linha,colunaaux;


    /* "retira" disco da torre inicial */
    linha = 0;

    while(m[linha][inicio] == 0)  //pecorre a haste de cima para baixo. //inicio==0 na primeira chamada.
		linha++;

	disco = m[linha][inicio];// encontra o primeiro disco,guarda em disco.

	m[linha][inicio] = 0;  //zera a posi��o 

    /* "coloca" disco na torre final */
    linha = *n-1;
    while(m[linha][final] != 0) //pecorre a haste de baixo para cima,encontra a primeira posi��o vazia.//final==3 na primeira chamada
		linha--;

    m[linha][final] = disco;//substitui pelo valor do disco.
    
	/* printa (temporario) */
	if (*n < 11) 
    	system("CLS"); //limpa a tela
    
	Saida(m,n,f);// chama a fun��o de print
		
	if (*n < 11) 
		Sleep(1000); // espera 
		
}

void Torre_hanoi(int *n, int N, int orig, int aux1, int aux2, int dest, int **m, FILE *f) 
{

	if (N==1)
	{
		Move_disco(orig,dest,n,m,f);
		return;
	}
	else if (N==2)
	{
		Move_disco(orig,aux1,n,m,f);
		Move_disco(orig,dest,n,m,f);
		Move_disco(aux1,dest,n,m,f);
	}
	else
	{
		Torre_hanoi(n,N-2,orig,aux2,dest,aux1,m,f);
		Torre_hanoi(n,2,orig,aux2, aux1,dest,m,f);
		Torre_hanoi(n,N-2,aux1,aux2,orig,dest,m,f);
	}
}


int ** Aloca_matriz(const int l)
{
 	int **m;
 	int i;

 	m = malloc(l * sizeof(int *));
 	if (m==NULL)
 	{
 		printf("Erro de aloca��o!!!\n");
 		exit(1);
 	}
 	for(i=0; i<l; i++)
 	{
 		m[i] = (int *) malloc(coluna * sizeof(int));
 		if (m[i]==NULL)
 		{
 			printf("Erro de aloca��o!!!\n");
 			exit(1);
 		}
 	}
 	return m;
}

void Libera_matriz(int **m)
{
 	int i;
 	for(i=0;i<coluna;i++)
 		free(m[i]);
 	free(m);
}

void Saida(int **m, int *n, FILE *f)
{

	int lagmax = (*n*2);//variavel que guarda a largura 
	int count,count2,espaco,linha,colunaaux;



	if (*n <11 ) // condi��o 
	{
		for (linha = 0; linha < (*n+1); linha++) //n+1 para a base
		{
			for (colunaaux = 0; colunaaux < coluna; colunaaux++)
				{
					if(linha == *n)//printa a base
					{ 
						for(count=0; count<((lagmax-1)/2); count++) 
						{
							printf("-");
							fprintf(f, "-");
						}
						printf("+");
						fprintf(f, "+");
						for(count=0; count<((lagmax-1)/2); count++)
						{
							printf("-");
							fprintf(f, "-");
						}
					}
					else if(m[linha][colunaaux]==0)//printa as hastes
					{
						for(count=0; count<((lagmax-1)/2); count++)
						{ 
							printf(" ");
							fprintf(f, " ");
						}
						
						printf("|");
						fprintf(f, "|");
						
						for(count=0; count<((lagmax-1)/2); count++)
						{
							printf(" ");
							fprintf(f, " ");
						}

					}
					else //printa discos
					{
						for(count2=0; count2<1; count2++)
						{
							espaco = (lagmax-m[linha][colunaaux])/2;
							for(count=0; count<espaco; count++)
							{
								printf(" ");
								fprintf(f, " ");
							}
							for(count=0; count<m[linha][colunaaux]; count++) //imprime os asteriscos 
							{
								printf("*");
								fprintf(f, "*");
							}
							for(count=0; count<espaco; count++)
							{
								printf(" ");
								fprintf(f, " ");
							}
						}
					}
				}
			printf("\n");
			fprintf(f,"\n");
		}
		fprintf(f,"\n\n\n");
	} 
	else 
	{
		for (linha = 0; linha < (*n+1); linha++) //n+1 para a base
		{
			for (colunaaux = 0; colunaaux < coluna; colunaaux++)

				{
					if(linha == *n)//printa a base
					{ 
						for(count=0; count<((lagmax-1)/2); count++) 
						{

							fprintf(f, "-");
						}

						fprintf(f, "+");
						for(count=0; count<((lagmax-1)/2); count++)
						{

							fprintf(f, "-");
						}
					}
					else if(m[linha][colunaaux]==0)//printa as hastes
					{
						for(count=0; count<((lagmax-1)/2); count++)
						{ 

							fprintf(f, " ");
						}
						

						fprintf(f, "|");
						
						for(count=0; count<((lagmax-1)/2); count++)
						{

							fprintf(f, " ");
						}

					}
					else //printa discos
					{
						for(count2=0; count2<1; count2++)
						{
							espaco = (lagmax-m[linha][colunaaux])/2;
							for(count=0; count<espaco; count++)
							{

								fprintf(f," ");
							}
							for(count=0; count<m[linha][colunaaux]; count++)
							{

								fprintf(f, "*");
							}
							for(count=0; count<espaco; count++)
							{

								fprintf(f, " ");
							}
						}
					}
				}

			fprintf(f,"\n");
		}
		fprintf(f,"\n\n\n");
	}
}

