/*Functions.c*/
/*Daniel Chagas 90043*/
/*Mariana Santos 90137*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"



int verificaParametros(int _argc, char* _argv[], int *f1, int *f2)
{
	int i = 0;//variavel contador
	int flag_text=0;//flags que indica o modo a utilizar
	int flag_graf=0;
	int flag_parametros=0;
	char ficheiro_1[] = "tempcountries.csv";//nomes dos ficheiros
	char ficheiro_2[]= "tempcities.csv";

	if (_argc!=6)//caso o numero de argumentos seja invalido
	{
		printf("ERRO: Parametros inválidos\n" );
		exit(EXIT_FAILURE);//o programa é fechado
	}

	for (i=1;i<_argc;i++)//ciclo que percorre os argumentos
	{
		if (strcmp(_argv[i],"-t")==0)//caso seja chamado o modo textual
		{
			flag_text=1;
		}
		else if(strcmp(_argv[i],"-g")==0)//caso seja chamado o modo grafico
			flag_graf=1;

		if (strcmp(_argv[i],"-f1")==0)//identificação dos ficheiros
		{
			*f1= i+1;
			if ( *f1 >=_argc)// se f1 for o ultimo parametro
			{
				printf("ERRO: Parametros inválidos\n" );
				exit(EXIT_FAILURE);
			}
		}
		if (strcmp(_argv[i],"-f2")==0)//identificação dos ficheiros
		{
			*f2= i+1;
			if ( *f2 >=_argc)// se f2 for o ultimo parametro
			{
				printf("ERRO: Parametros inválidos\n" );
				exit(EXIT_FAILURE);
			}
		}
	}

	if ((flag_graf==0 && flag_text==0)||strcmp(_argv[*f1], ficheiro_1)!=0 ||strcmp(_argv[*f2], ficheiro_2)!=0)//caso um parametro for invalido
	{
		printf("ERRO:Parametros introduzidos inválidos\n" );
		exit(EXIT_FAILURE);
	}
	else//caso todos serem validos atualiza as flags
	{

		flag_parametros = 1;
	}
	if (flag_text==1)
	{
		flag_parametros=2;
	}
		if (flag_graf==1)
	{
		flag_parametros=3;
	}
	return flag_parametros;

}
int GetT(int T)
{


		char a='a';			//inicialização da variavel que serve para identificação de parametros inválidos por parte do utilizador
		char Tempo[MAX_LINE_LEN]={0};	// variavel onde é guardado o parametro introduzido pelo utilizador

		while(T<=0||T>200 || a != '\n' )
		{
			printf("Introduza um periodo de tempo(Max 200):");
			fgets(Tempo, MAX_LINE_LEN, stdin);// guarda a string  introduzida pelo utilizador
			sscanf(Tempo, "%d%c", &T, &a); // le os numeros e caracteres da string introduzida e guarda num inteiro
			if(T<=0||T>200 || a != '\n' ) // se o numero não pertence á gama e existir caracteres depois do numero dá erro
				printf("ERRO: o valor introduzido não pertence à gama permitida \n");
		}
		return T;

}
void GetCity(node_l *_head, char city[])
{
	node_l *aux=NULL;	//inicialização de um node auxiliar para percorrer a lista
 	int flag=1;//inicialização da flag que incica se o pais existe na lista(valor 0) ou não(valor 1)
 	char *token=NULL;//inicialização de um token para obter o que foi escrito pelo utilizador

	aux=GetNewNode_l();//obtenção de um node com memória alocada

	while(flag!=0)
	{
		aux=_head;
		printf("Introduza o nome do cidade que pretende analisar : " );
		fgets(city, MAX_LINE_LEN, stdin);// guarda a string  introduzida pelo utilizador
		token= strtok(city, "\n");

		while( flag!=0 && aux!=NULL)//enquando a cidade nao for encontrado ou a lista acabar
		{
			flag=strcmp(aux->cidade, token); 

			if (flag==0)//se a cidade for encontrada
			{
				printf("Cidade existe\n" );
			}
			else//se a cidade nao for encontrada
			{
				aux=aux->next;
			}
		}
		if(flag!=0)//se a cidade não for encontrada
			printf("ERRO: Cidade não encontrada!\n" );
	}

}

void GetCountry(node_t *_head,char country[])
{
	node_t *aux=NULL;//inicialização de um node auxiliar para percorrer a lista
 	int flag=1;	//inicialização da flag que incica se o pais existe na lista(valor 0) ou não(valor 1)
 	char *token=NULL;//inicialização de um token para obter o que foi escrito pelo utilizador


	aux=GetNewNode();//obtenção de um node com memória alocada

	while(flag!=0)
	{
		aux=_head;
		printf("Introduza o nome do país que pretende analisar : " );
		fgets(country, MAX_LINE_LEN, stdin);// guarda a string  introduzida pelo utilizador
		token= strtok(country, "\n");

		while( flag!=0)
		{
			flag=strcmp(aux->payload.pais, token);

			if (flag==0)//se o pais for encontrado
			{
				printf("País Existe\n" );
			}
			else//se o pais nao for encontrado
			{
				aux=aux->next;
				if (aux==NULL)break;
			}
		}
		if(flag!=0)//se o pais for encontrado na lista inteira
			printf("ERRO: País Não Encontrado!\n" );
	}

}
int getAnos(node_t *head)
{
	int n_anos=1;//inicialização da variavel que guarda o numero de anos
	node_t	*aux=NULL;//no auxiliar
	aux=head;//no auxiliar aponta para a cabeca
	while(aux->next != NULL)//ciclo que percorre a lista
	{
		if(aux->payload.dt.ano!= aux->next->payload.dt.ano)//caso o ano de um no seja diferente do proximo
			n_anos++;//numero de anos é incrementado
		aux=aux->next;
	}
	return n_anos;//retorna o numero de anos
}
float** movingAverage(float** temperaturas, int n_anos)
{
	int M=0;//numero de medidas
	int i=0,j=0,z=0;//variaveis contador

	float soma = 0;

	char a ='a';
	char MM[MAX_LINE_LEN]={0};
	float **temperaturasMA=NULL;//inicialização da "matriz que guardas as moving averages"


	temperaturasMA=(float**)malloc(12*sizeof(float*));//alocação para as linhas de da matrix que guarda as MA
	if (temperaturasMA==NULL)//verificação da aloocação
	{
		printf("ERRO na alocação de memória\n" );
		exit(EXIT_FAILURE);
	}
	for(i=0; i < 12; i++)
	{

		temperaturasMA[i] = (float*)calloc(n_anos,sizeof(float));
		if (temperaturasMA[i]==NULL)//verificação da aloocação
		{
			printf("ERRO na alocação de memória\n" );
			exit(EXIT_FAILURE);
		}
	}

	while(M<2||M>100|| a != '\n' )
	{
		printf("Introduza o numero de medidas que pretende analisar(entre 2 e 100): ");
		fgets(MM, MAX_LINE_LEN, stdin);// guarda a string  introduzida pelo utilizador
		sscanf(MM, "%d%c", &M, &a); // le os numeros e caracteres da string introduzida e guarda num inteiro
		if(M<2||M>100|| a != '\n') // se o numero não pertence á gama e existir caracteres depois do numero dá erro
			printf("ERRO: o valor introduzido não percente à gama permitida \n");
	}

	for(i=0;i<12;i++)//ciclo que copia as medidas que não vão ser escritas pelo moving average
	{
		for(j=0;j<M-1;j++)
			temperaturasMA[i][j]=temperaturas[i][j];
	}
	for(i=0;i<12;i++)//ciclo que faz moving average
	{
		for(j=M-1;j<n_anos;j++)//percorre as colunas
		{
			soma=0;
			for(z=j;z>j-M;z--)//ciclo que faz a média das medidas
				soma = soma + temperaturas[i][z];
			temperaturasMA[i][j]=soma/M;
		}
	}

	return temperaturasMA;//retorna a matriz com os valores do MA
}

