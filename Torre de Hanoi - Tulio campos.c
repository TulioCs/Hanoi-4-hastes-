#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#define coluna 4


/****
*
* Título: AlocaMatriz
*
* Autor: Tulio Campos
*
* Data de Criação: 20/07/2016
* Última modificação: 25/07/2016
*
* Descrição: A função aloca uma matriz.
*
* Parâmetros:
*   (entrada)
*           const int l:  Representa o número de linhas (discos) da matriz.
*          	 
*
* Valor de retorno: A função retorna a matriz alocada.
*
****/


int ** Aloca_matriz(const int);

/****
*
* Título: LiberaMatriz
*
* Autor: Tulio Campos
*
* Data de Criação: 20/07/2016
* Última modificação:25/07/2016
*
* Descrição: Libera uma matriz alocada dinamicamente.
*
* Parâmetros:
*   (entrada)
*           int **m: Ponteiro que aponta para a matriz que foi alocada e definida na função AlocaMatriz.
*          
* Valor de retorno: void.
*
****/

void Libera_matriz(int **);

/****
*
* Título: Inicializa_controle
*
* Autor: Tulio Campos
*
* Data de Criação: 20/07/2016
* ultima modificação: 25/07/2016
*
* Descrição: A função zera a matriz númerica , e coloca os valores correspondente ao tamanho dos discos na primeira coluna.
*
* Parâmetros:
*   (entrada)
*    const int num:  Número de discos digitado pelo usuario.
*	 int **m:  É um ponteiro que aponta para a matriz que já foi alocada e definida na função Aloca_Matriz.
* Valor de retorno: A função não possui retorno.
*
****/


void Inicializa_controle(int**,const int);


/****
*
* Título: Move_disco
*
/* Autor: Tulio Campos
*
* Data de Criação: 20/07/2016
* Ultima modificação: 25/07/2016
*
* Descrição: A função define a posição do disco de origem através do parâmetro de entrada, depois verifica para onde ele deve ser copiado (haste de destino)
*            Então, copia o disco da  posição  de origem para a posição de destino, e substitui a  posição de origem onde o disco estava por 0.
*			 Depois chama a função saida para imprimir a nova posição dos discos na tela.
* Parâmetros:
*   (entrada)
*       int:  inicio, Posição  de origem do disco,onde o disco se encontra.
*		int:  final,  Posição  de destino ,para onde o disco deve ser movido.
*		int  *n    ,  Número de discos digitado pelo usuario.
*		int  **m,     Ponteiro que aponta para a matriz númerica que contem a posição dos discos.
*		FILE *f,      Ponteiro para o arquivo .txt criado no início do programa, usado para a função fprintf.
* Valor de retorno: A função não possui retorno.
*
****/


void Move_disco(int, int, int*, int**, FILE *f);


/****
*
* Título: Torre_hanoi
*
* Autor: Tulio Campos
*
* Data de Criação: 20/07/2016
* ultima modificação: 25/07/2016
*
* Descrisção: A função faz uma série de chamadas recursivas para resolver o problema em questão.
*
* Parâmetros:
*   (entrada)
		int:    *n,   número de discos digitado pelo usuario ,que irá ser usado na função move disco.
*		int:	N ,   número de discos digitado pelo usuario,que irá ser usado na função
*       int:	orig, haste de origem do disco,onde os discos se encontram.
*		int:	aux1, haste auxiliar que recebe os discos temporariamente.
*       int:	aux2, haste auxiliar que recebe os discos temporariamente.
*		int:	dest, haste de destino ,para onde os discos devem ser movidos.
*       int:    **m,  Ponteiro que aponta para a matriz númerica que contem a posição dos discos.
*		FILE:   *f,   Ponteiro para o arquivo .txt criado no início do programa, usado para a função fprintf.
* Valor de retorno: A função não possui retorno.
*
****/


void Torre_hanoi(int*, int, int, int, int, int,int**,FILE *f);


/****
*
* Título: Saida
*
/* Autor: Tulio Campos
*
* Data de Criação: 20/07/2016
* Ultima modificação: 25/07/2016
*
* Descrição: A função transforma a matriz númerica , no print grafico das torres de hanoi , e printa toda vez que os discos são movimentados .
*           
*
* Parâmetros:
*   (entrada)
*       
*		int  *n    ,  Número de discos digitado pelo usuario.
*		int  **m   ,  Ponteiro que aponta para a matriz númerica que contem a posição dos discos.
*		FILE *f    ,  Ponteiro para o arquivo .txt criado no início do programa, usado para a função fprintf.
* Valor de retorno: A função não possui retorno.
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
	printf("  | Descrição: Dada quatro hastes(A;B;C e D), existem n discos de vários tamanhos na haste A,colocados  |\n" );
	printf("  | em ordem decrescente segundo o tamanho.Os discos deverão ser movimentados da haste A para a haste D |\n" );
	printf("  | com o menor número de movimentos respeitando as seguintes restrições :                              |\n" );
	printf("  | * Pode-se mover um único disco por vez;	                                                        |\n" );
	printf("  | * Nunca colocar um disco em outro lugar que não seja uma das Quatros hastes.                        |\n" );
	printf("  | * Nunca colocar um disco maior sobre um disco menor;                                                |\n");
	printf("  | Autor:Tulio Campos Silva                                                                            |\n" );
	printf("  +-----------------------------------------------------------------------------------------------------+\n");
	
	Sleep(10000);

	printf ("\nDigite o número de discos desejados : ");
	scanf ("%d",&num);
	
	if (num>10)
		printf ("O número de discos informados é grande, com isso pode ocorrer o desbordamento da tela do computador ao printar,\n"
			" mas a solução para número de discos desejados pode ser encontrada no arquivo de nome hanoi.txt .\n ");
	
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

	m[linha][inicio] = 0;  //zera a posição 

    /* "coloca" disco na torre final */
    linha = *n-1;
    while(m[linha][final] != 0) //pecorre a haste de baixo para cima,encontra a primeira posição vazia.//final==3 na primeira chamada
		linha--;

    m[linha][final] = disco;//substitui pelo valor do disco.
    
	/* printa (temporario) */
	if (*n < 11) 
    	system("CLS"); //limpa a tela
    
	Saida(m,n,f);// chama a função de print
		
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
 		printf("Erro de alocação!!!\n");
 		exit(1);
 	}
 	for(i=0; i<l; i++)
 	{
 		m[i] = (int *) malloc(coluna * sizeof(int));
 		if (m[i]==NULL)
 		{
 			printf("Erro de alocação!!!\n");
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



	if (*n <11 ) // condição 
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

