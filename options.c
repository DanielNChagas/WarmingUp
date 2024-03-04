/*options.c*/
/*Ficheiro onde se encontram implementadas
as funções que implementam as opções */
/*Daniel Chagas 90043*/
/*Mariana Santos 90137*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"



void HistoricoGlobal(node_t *head)
{

	int t_min=0;		//inicialização da variavel que guarda o ano mais baixo da lista
	int temp=0;			//inicialização da variavel que serve de contador para o calculo da média
	int flag =0;		//inicialização da flag que indica a existencia ou não de dados
	int T=0;				//inicialização da variavel que guarda o intrevalo de tempo a analizar
	char options[]={'\0'};
	int i=0;
	float soma=0;	//inicialização da variavel que guarda as somas das temperaturas para o calculo da média
	float media=0;	//inicialização da variavel que guarda o valor da média
	float max=0.0f;	//inicialização da variavel que guarda o valor do maximo
	float min=0.0f;	//inicialização da variavel que guarda o valor do minimo



	node_t *aux=NULL; //inicialização de um node auxiliar para percorrer a listas

	aux =GetNewNode(); // obteção de um node com memória alocada

	T=GetT(T);//obteção do intrevalo de tempo a analisar

	t_min=head->payload.dt.ano; //menor ano que aparece na lista
	t_min =t_min+T; // calculo do valor do ano mais alto do intervalo de tempo
	aux=head;	//igualar os nodulos para o auxiliar poder percorrer a lista
	min =aux->payload.temperatura; //minimo inicial
	max =aux->payload.temperatura; // maximo inicial
	while (aux!=NULL && i<20 )
	{
		//reinicialização das variavéis
		soma=0;
		temp=0;
		media=0;
		flag=0;
		options[0]='\0';

			printf("Inicio do ao %d ao inicio do ano %d\n",t_min-T,t_min ); // print do intervalo de tempo que é analisado
			while(aux->payload.dt.ano<t_min  )
			{
				if(min >= aux->payload.temperatura) //caso o minimo seja superior a valor lido do node
				{
					min =aux->payload.temperatura;	//atualização do minimo
					flag=1;	// valor da flag que indica que existe dados no periodo de tempo
				}
				// printf("%f-%f\n",min ,aux->payload.temperatura );
				if(max <= aux->payload.temperatura)	//caso o maximo seja inferior do que o valor lido do node
				{
					max =aux->payload.temperatura; // atualização do máximo
					flag=1; // valor da flag que indica que existe dados no periodo de tempo
				}
				// printf("%f-%f\n",max ,aux->payload.temperatura );
				soma = soma +aux->payload.temperatura; // calculo da soma das temperaturas
				temp++;	//incremento do contador
				aux=aux->next;	//passagem para o próximo node
				if (aux==NULL)break;//caso o próximo aux a analisar seja NULL o loop é quebrado
													//eu tinha utilizado como condição do while(aux->payload.dt.ano<t_min&& aux!=NULL)
													// mas dava me um erro no ultimo elemento e este break resolveu
			}

			media= soma/(float)temp; // calculo da média

			if (flag==0) // caso nao haja paises na lista durante o periodo de tempo defenido
				printf("Sem dados neste período de tempo\n" );
			else // caso haja paises na lista durante o periodo de tempo defenido
			{
				printf("Média: %lf          Máximo:%lf          Mínimo:%lf          \n" ,media,max,min);
			}
			t_min=t_min+T;
			min=1000.0f; // reinicialização do minimo com um valor muito alto
			max=-1000.0f; // reinicialização do maximo com um valor muito baixo

			if(i==19)//se o utilizador desejar imprimir outra pagina
			{
				printf("--------------Deseja ver mais resultados?-------------\n");
				printf("---------Prima 'a' para sim e 'q' para sair.----------\n");
				fgets(options, 2, stdin);

				if(options[0]=='a')
				{
					i=0;
				}
				if(options[0]=='q')
				{
					return;
				}
			}
			else i=i+1;



	}
}
void HistoricoPais (node_t *head)
{
	int t_min=0;		//inicialização da variavel que guarda o ano mais baixo da lista
	int temp=0;			//inicialização da variavel que serve de contador para o calculo da média
	int flag =0;		//inicialização da flag que indica a existencia ou não de dados
	int T=0;			//inicialização da variavel que guarda o intrevalo de tempo a analizar
	char options[]={'\0'};
	int i=0;

	float soma=0;		//inicialização da variavel que guarda as somas das temperaturas para o calculo da média
	float media=0;	//inicialização da variavel que guarda o valor da média
	float max=0.0f;	//inicialização da variavel que guarda o valor do maximo
	float min=0.0f;	//inicialização da variavel que guarda o valor do minimo

	char country[MAX_LINE_LEN]={0};//inicialização do array que guarda o pais a analisar


	node_t *aux=NULL; //inicialização de um node auxiliar para percorrer a listas

	aux =GetNewNode(); // obteção de um node com memória alocada
	aux=head;	//igualar os nodulos para o auxiliar poder percorrer a lista
	T=GetT(T);//obteção do intrevalo de tempo a analisar
	GetCountry(head, country);	//obtenção do pais a analisar
	while (strcmp(aux->payload.pais, country) !=0 )
	{
		aux=aux->next;
	}
	t_min=aux->payload.dt.ano; //menor ano que aparece na lista
	t_min =t_min+T; // calculo do valor do ano mais alto do intervalo de tempo

	min =aux->payload.temperatura; //minimo inicial
	max =aux->payload.temperatura; // maximo inicial

	while (aux!=NULL &&i<20)
	{
		//reinicialização das variavéis
		soma=0;
		temp=0;
		media=0;
		flag=0;
		options[0]='\0';


			printf("Inicio do ao %d ao inicio do ano %d\n",t_min-T,t_min ); // print do intervalo de tempo que é analisado
			while(aux->payload.dt.ano<t_min )
			{
				if(min >= aux->payload.temperatura &&strcmp(aux->payload.pais, country) ==0 ) //caso o minimo seja superior a valor lido do node e o pais for o escolhido
				{
					min =aux->payload.temperatura;	//atualização do minimo
					flag=1;	// valor da flag que indica que existe dados no periodo de tempo
				}
				// printf("%f-%f\n",min ,aux->payload.temperatura );
				if(max <= aux->payload.temperatura&&strcmp(aux->payload.pais, country) ==0 )	//caso o maximo seja inferior do que o valor lido do node e o pais for o escolhido
				{
					max =aux->payload.temperatura; // atualização do máximo
					flag=1; // valor da flag que indica que existe dados no periodo de tempo
				}
				// printf("%f-%f\n",max ,aux->payload.temperatura );
				soma = soma +aux->payload.temperatura; // calculo da soma das temperaturas
				temp++;	//incremento do contador
				aux=aux->next;	//passagem para o próximo node
				if (aux==NULL)break;//caso o próximo aux a analisar seja NULL o loop é quebrado
													//eu tinha utilizado como condição do while(aux->payload.dt.ano<t_min&& aux!=NULL)
													// mas dava me um erro no ultimo elemento e este break resolveu
			}

			media= soma/(float)temp; // calculo da média

			if (flag==0) // caso nao haja paises na lista durante o periodo de tempo defenido
				printf("Sem dados neste período de tempo\n" );
			else // caso haja paises na lista durante o periodo de tempo defenido
			{
				printf("Média: %lf          Máximo:%lf          Mínimo:%lf          \n",media,max,min);

			}
			t_min=t_min+T;
			min=1000.0f; // reinicialização do minimo com um valor muito alto
			max=-1000.0f; // reinicialização do maximo com um valor muito baixo
			if(i==19)//se o utilizador desejar imprimir outra pagina
			{
				printf("--------------Deseja ver mais resultados?-------------\n");
				printf("---------Prima 'a' para sim e 'q' para sair.----------\n");
				fgets(options, 5, stdin);

				if(options[0]=='a')
				{
					i=0;
				}
				if(options[0]=='q')
				{
					return;
				}
			}
			else i=i+1;


	}
}

void HistoricoCidade(node_l *head)
{

		int t_min=0;		//inicialização da variavel que guarda o ano mais baixo da lista
		int temp=0;			//inicialização da variavel que serve de contador para o calculo da média
		int flag =0;		//inicialização da flag que indica a existencia ou não de dados
		int T=0;				//inicialização da variavel que guarda o intrevalo de tempo a analizar
		char options[]={'\0'};
		int i=0;
		float soma=0;		//inicialização da variavel que guarda as somas das temperaturas para o calculo da média
		float media=0;	//inicialização da variavel que guarda o valor da média
		float max=0.0f;	//inicialização da variavel que guarda o valor do maximo
		float min=0.0f;	//inicialização da variavel que guarda o valor do minimo

		char city[MAX_LINE_LEN]={0};//inicialização do array que guarda a cidade a analisar

		node_l *aux=NULL; //inicialização de um node auxiliar para percorrer a lista de listas
		node_t *tmp=NULL;	//inicialização de um node auxiliar para percorrer a lista


		aux=head;	//igualar os nodulos para o auxiliar poder percorrer a lista
		T=GetT(T);//obteção do intrevalo de tempo a analisar
		GetCity(head, city);	//obtenção do pais a analisar

		while(strcmp(aux->cidade, city)!=0)	// ciclo que encontra o node em que esta guardada a cabeça
																				// da lista com a cidade pretendida
		{
			aux=aux->next;
		}
		tmp =aux->cabeca;
		t_min=tmp->payload.dt.ano; //menor ano que aparece na lista
		t_min =t_min+T; // calculo do valor do ano mais alto do intervalo de tempo

		min =tmp->payload.temperatura; //minimo inicial
		max =tmp->payload.temperatura; // maximo inicial

		while (tmp!=NULL && i<20 )
		{
			//reinicialização das variavéis
			soma=0;
			temp=0;
			media=0;
			flag=0;
			options[0]='\0';

				printf("Inicio do ao %d ao inicio do ano %d\n",t_min-T,t_min ); // print do intervalo de tempo que é analisado
				while(tmp->payload.dt.ano<t_min  )
				{
					if(min >= tmp->payload.temperatura ) //caso o minimo seja superior a valor lido do node
					{
						min =tmp->payload.temperatura;	//atualização do minimo
						flag=1;	// valor da flag que indica que existe dados no periodo de tempo
					}
					if(max <= tmp->payload.temperatura)	//caso o maximo seja inferior do que o valor lido do node
					{
						max =tmp->payload.temperatura; // atualização do máximo
						flag=1; // valor da flag que indica que existe dados no periodo de tempo
					}
					// printf("%f-%f\n",max ,aux->payload.temperatura );
					soma = soma +tmp->payload.temperatura; // calculo da soma das temperaturas
					temp++;	//incremento do contador
					tmp=tmp->next;	//passagem para o próximo node
					if (tmp==NULL)break;//caso o próximo aux a analisar seja NULL o loop é quebrado
														//eu tinha utilizado como condição do while(tmp->payload.dt.ano<t_min&& tmp!=NULL)
														// mas dava me um erro no ultimo elemento e este break resolveu
				}

				media= soma/(float)temp; // calculo da média

				if (flag==0) // caso nao haja paises na lista durante o periodo de tempo defenido
					printf("Sem dados neste período de tempo\n" );
				else // caso haja paises na lista durante o periodo de tempo defenido
				{
					printf("Média: %lf          Máximo:%lf          Mínimo:%lf          \n",media,max,min);
				}
				t_min=t_min+T;
				min=1000.0f; // reinicialização do minimo com um valor muito alto
				max=-1000.0f; // reinicialização do maximo com um valor muito baixo
				if(i==19)//se o utilizador desejar imprimir outra pagina
				{
					printf("--------------Deseja ver mais resultados?-------------\n");
					printf("---------Prima 'a' para sim e 'q' para sair.----------\n");
					fgets(options, 5, stdin);

					if(options[0]=='a')
					{
						i=0;
					}
					if(options[0]=='q')
					{
						return;
					}
				}
				else i=i+1;

		}
}
void filtragemGlobalCidades (node_l **head, int *year, int *month )
{

	char a='a';//inicialização da variavel que guarda um caracter para a verificação dos parametros introduzidps
	char mes[MAX_LINE_LEN]={0};//inicialização da variavel que guarda o parametro mes introduzido pelo utilizador
	char ano[MAX_LINE_LEN]={0};//inicialização da variavel que guarda o parametro ano introduzido pelo utilizador

	node_l *aux=NULL;
	node_l *tmp=NULL;

	while((*year)<1743||(*year)>2013 || a != '\n' )
	{
		printf("Introduza um ano(Entre 1743 e 2013):");
		fgets(ano, MAX_LINE_LEN, stdin);// guarda a string  introduzida pelo utilizador
		sscanf(ano, "%d%c", year, &a); // le os numeros e caracteres da string introduzida e guarda num inteiro
		if((*year)<1743||(*year)>2013 || a != '\n') // se o numero não pertence á gama e existir caracteres depois do numero dá erro
			printf("ERRO: o valor introduzido não pertence à gama permitida \n");
	}
	while((*month)<1||(*month)>12 || a != '\n' )
	{
		printf("Introduza um mes (Entre 1 e 12):");
		fgets(mes, MAX_LINE_LEN, stdin);// guarda a string  introduzida pelo utilizador
		sscanf(mes, "%d%c", month, &a); // le os numeros e caracteres da string introduzida e guarda num inteiro
		if((*month)<1||(*month)>12 || a != '\n' ) // se o numero não pertence á gama e existir caracteres depois do numero dá erro
			printf("ERRO: o valor introduzido não pertence à gama permitida \n");
	}

	aux=(*head);

	while (aux!=NULL) //loop para o aux percorre toda a lista que guarda as outras listas
	{

		while(aux->cabeca->payload.dt.ano<(*year))//enquanto o ano guardado na cabeça for inferior ao introduzido pelo utilizador
		{
			removeHead(&aux->cabeca);// a cabeça é removida
		}
		if(aux->cabeca->payload.dt.ano==(*year))//caso o ano seja igual
		{

			while(aux->cabeca->payload.dt.mes<(*month) && aux->cabeca->payload.dt.ano==(*year))//enquanto o mes guardado na cabeça for inferior ao introduzido pelo utilizado
			{
				removeHead(&aux->cabeca);// a cabeça é removida
			}
		}
		if(aux->cabeca==NULL)
		{
			tmp=aux;
			aux=aux->next;
			free(tmp);
		}
		else
			aux=aux->next;
	}

}
void filtragemGlobal(node_t **head, int year, int month )//nesta tendo em conta que a lista esta ordenada por data basta remover a cabeça da lista ate á data pretendida
{



	while((*head)->payload.dt.ano<year)//enquanto o ano guardado na cabeça for inferior ao introduzido pelo utilizador
	{
		removeHead(head);// a cabeça é removida

	}
	if((*head)->payload.dt.ano==year)//caso o ano seja igual
	{
		while((*head)->payload.dt.mes<month && (*head)->payload.dt.ano==year)//enquanto o mes guardado na cabeça for inferior ao introduzido pelo utilizado
		{
			removeHead(head);// a cabeça é removida
		}
	}
}

void filtragemMesCidades(node_l **head, int month1, int month2)
{

	node_l *aux = NULL;// inicialização de um node auxiliar para percorrer a lista das listas
	node_t *tmp=NULL; //inicialização de um node auxiliar para percorrer a lista
	node_l *tmp2=NULL;// inicialização de um node para ajudar na eleminação de um elemento da lista das listas

	aux=(*head);
	while(aux!=NULL)
	{

		if(month1>month2) //caso primeiro mes seja superior ao segundo
		{
			while(aux->cabeca->payload.dt.mes<month1 && aux->cabeca->payload.dt.mes>month2 )//enquanto o mes guardado na cabeça for ao inferior mes inferior(ou superior ao superior)  introduzido pelo utilizador
			{
				removeHead(&aux->cabeca);// a cabeça é removida

			}

			tmp= aux->cabeca;//igualar o node auxiliar ao o node da cabeça da lista(ponteiro auxiliar aponta para a cabeça)
			while (tmp->next->next != NULL)	//o ciclo mantem-se enquanto o node aseguir ao a seguir do auxiliar for
																			//diferente de NULL pois a função removeNode não funciona se for necessário
																			//remover o ultimo node de uma lista
			{
				if(tmp->next->payload.dt.mes<month1 && tmp->next->payload.dt.mes>month2)//caso o es guardado na cabeça da lista não estiver entre os meses introduzidos
				{
					removeNode(tmp);// o node é removido
				}
				else//caso contrário
				{
					tmp=tmp->next;//vai ser analisado o proximo node
				}
			}

			if(tmp->next->payload.dt.mes<month1 &&tmp->next->payload.dt.mes>month2) // caso seja necessário remover o ultimo elemento da lista
			{
				tmp=tmp->next;//o aux aponta para esse elemento
				tmp->prev->next = NULL;//o elemento anterior aponta para NULL
				free(tmp); //memória do ex-ultimo node da lista é libertada
			}
			if(aux->cabeca==NULL)
			{
				tmp2=aux;
				aux=aux->next;
				free(tmp2);
			}
			else
				aux=aux->next;
		}
		else
		{
			while(aux->cabeca->payload.dt.mes<month1 || aux->cabeca->payload.dt.mes>month2 )//enquanto o mes guardado na cabeça for ao inferior mes inferior  introduzido pelo utilizador
			{
				removeHead(&aux->cabeca);// a cabeça é removida
			}
			tmp= aux->cabeca;//igualar o node auxiliar ao o node da cabeça da lista
			while (tmp->next->next != NULL)	//o ciclo mantem-se enquanto o node aseguir ao a seguir do auxiliar for
																			//diferente de NULL pois a função removeNode não funciona se for necessário
																			//remover o ultimo node de uma lista
			{
				if(tmp->next->payload.dt.mes<month1 || tmp->next->payload.dt.mes>month2)//caso o es guardado na cabeça da lista não estiver entre os meses introduzidos
				{
					removeNode(tmp);// o node é removido
				}
				else//caso contrário
				{
					tmp=tmp->next;//vai ser analisado o proximo node
				}
			}

			if(tmp->next->payload.dt.mes<month1 || tmp->next->payload.dt.mes>month2) // caso seja necessário remover o ultimo elemento da lista
			{
				tmp=tmp->next;//o aux aponta para esse elemento
				tmp->prev->next = NULL;//o elemento anterior aponta para NULL
				free(tmp); //memória do ex-ultimo node da lista é libertada
			}
			if(aux->cabeca==NULL)
			{
				tmp2=aux;
				aux=aux->next;
				free(tmp2);
			}
			else
				aux=aux->next;
		}
	}
	// print_list((*head)->cabeca);
	// print_list((*head)->next->cabeca);
}
//função responsavel pela filtragem dos meses
void filtragemMes(node_t **head, int *month1, int *month2)
{

	char a='a';//inicialização da variavel que guarda um caracter para a verificação dos parametros introduzidps
	char mes1[MAX_LINE_LEN]={0};//inicialização da variavel que guarda o parametro 1ºmes introduzido pelo utilizador
	char mes2[MAX_LINE_LEN]={0};//inicialização da variavel que guarda o parametro 2ºmes introduzido pelo utilizador

	node_t *aux = NULL;// inicialização de um node auxiliar para percorrer a lista

	aux= GetNewNode();//obtenção de um node com memória allocada

	while((*month1)<1||(*month1)>12 || a != '\n' )//enquanto os paramentro introduzidos pelo utilizador forem inválido, voltam a ser pedidos parametros
	{
		printf("Introduza o primeiro mes (Entre 1 e 12):");
		fgets(mes1, MAX_LINE_LEN, stdin);// guarda a string  introduzida pelo utilizador
		sscanf(mes1, "%d%c", month1, &a); // le os numeros e caracteres da string introduzida e guarda num inteiro
		if((*month1)<1||(*month1)>12 || a != '\n' ) // se o numero não pertence á gama e existir caracteres depois do numero dá erro
			printf("ERRO: o valor introduzido não pertence à gama permitida \n");
	}
	while((*month2)<1||(*month2)>12 || a != '\n' )//enquanto os paramentro introduzidos pelo utilizador forem inválido, voltam a ser pedidos parametros
	{
		printf("Introduza o segundo mes (Entre 1 e 12):");
		fgets(mes2, MAX_LINE_LEN, stdin);// guarda a string  introduzida pelo utilizador
		sscanf(mes2, "%d%c", month2, &a); // le os numeros e caracteres da string introduzida e guarda num inteiro
		if((*month2)<1||(*month2)>12 || a != '\n' ) // se o numero não pertence á gama e existir caracteres depois do numero dá erro
			printf("ERRO: o valor introduzido não pertence à gama permitida \n");
	}
	if((*month1)>(*month2)) //caso primeiro mes seja superior ao segundo
	{
		while(((*head)->payload.dt.mes<(*month1) && (*head)->payload.dt.mes>(*month2)) && (*head)!= NULL )//enquanto o mes guardado na cabeça for ao inferior mes inferior(ou superior ao superior)  introduzido pelo utilizador
		{
			removeHead(head);// a cabeça é removida
		}

			aux= (*head);//igualar o node auxiliar ao o node da cabeça da lista(ponteiro auxiliar aponta para a cabeça)
			while (aux->next->next != NULL)	//o ciclo mantem-se enquanto o node aseguir ao a seguir do auxiliar for
																			//diferente de NULL pois a função removeNode não funciona se for necessário
																			//remover o ultimo node de uma lista
			{

				if(aux->next->payload.dt.mes<(*month1) && aux->next->payload.dt.mes>(*month2))//caso o es guardado na cabeça da lista não estiver entre os meses introduzidos
				{
					removeNode(aux);// o node é removido
				}
				else//caso contrário
				{
					aux=aux->next;//vai ser analisado o proximo node
				}
			}

			if(aux->next->payload.dt.mes<(*month1) && aux->next->payload.dt.mes>(*month2)) // caso seja necessário remover o ultimo elemento da lista
			{
				aux=aux->next;//o aux aponta para esse elemento
				aux->prev->next = NULL;//o elemento anterior aponta para NULL
				free(aux); //memória do ex-ultimo node da lista é libertada
			}

			//print_list(*head);
	}
	else
	{
		while(((*head)->payload.dt.mes<(*month1) || (*head)->payload.dt.mes>(*month2)) && (*head)!= NULL )//enquanto o mes guardado na cabeça for ao inferior mes inferior  introduzido pelo utilizador
		{
			removeHead(head);// a cabeça é removida
		}

		aux= (*head);//igualar o node auxiliar ao o node da cabeça da lista
		while (aux->next->next != NULL)	//o ciclo mantem-se enquanto o node aseguir ao a seguir do auxiliar for
																	//diferente de NULL pois a função removeNode não funciona se for necessário
																	//remover o ultimo node de uma lista
		{

			if(aux->next->payload.dt.mes<(*month1) || aux->next->payload.dt.mes>(*month2))//caso o es guardado na cabeça da lista não estiver entre os meses introduzidos
			{
				removeNode(aux);// o node é removido
			}
			else//caso contrário
			{
				aux=aux->next;//vai ser analisado o proximo node
			}
		}

		if(aux->next->payload.dt.mes<(*month1) || aux->next->payload.dt.mes>(*month2)) // caso seja necessário remover o ultimo elemento da lista
		{
			aux=aux->next;//o aux aponta para esse elemento
			aux->prev->next = NULL;//o elemento anterior aponta para NULL
			free(aux); //memória do ex-ultimo node da lista é libertada
		}

		//print_list(*head);
	}
}
void undoFiltragem(int f1, int f2, char *argv[], node_l **head_p, node_l **head_c, node_t **head_countries)
{
	/*node_l *aux= NULL;//node auxiliar que ajuda a percorrer a lista dos paises
	node_t *aux2=NULL;//node auxiliar que ajuda a percorrer a lista das cidades
	node_l *tmp=NULL;//node auxiliar que ajuda a percorrer a lista das cidades

	while(head_countries!=NULL)
	{
		aux2= head_countries;
		head_countries = head_countries->next;
		free(aux2);
	}*/
/*	while ((*head_c)->next != NULL)
	{
		aux2=(*head_c)->cabeca;//o node aux2 aponta para a cabeça da lista guardada na cabeça da lista de listas
		while((*head_p) != NULL)
		{
			aux = (*head_p);// o node aux aponta para a cabeça
			(*head_p)=(*head_p)->next;//a cabeça aponta para o seu proximo elemento
			free(aux);// a cabeça antiga é eleminada
		}
		tmp =(*head_c);// node tmp aponta para a cabeca da lista de listas
		(*head_c) =(*head_c)->next ;//a cabeca aponta para o seu procimo elemento
		free(tmp);//a cabeca antiga é eleminada
	}
	aux2=(*head_c)->cabeca;//o node aux2 aponta para a cabeça da lista guardada na cabeça da lista de listas
	while ((*head_p)!= NULL)
	{
		aux = (*head_p);// o node aux aponta para a cabeça
		(*head_p)=(*head_p)->next;//a cabeça aponta para o seu proximo elemento
		free(aux);// a cabeça antiga é eleminada
	}

	free((*head_c));//elemina o ultimo elemento da lista
	(*head_c)=NULL;// a head da lista das lista é inicializada a NULL*/
	//ler_cidades(f2, argv, head_c);//a lista das cidades é lida e guardada numa lista
	//head_countries= criaLista(head_p);
	//ler_pais(f1, argv,head_p);

}
void bubleSort_temperatura(stats **paises, int npaises)
{
	int i =0;
	int j = 0;
	stats *aux=NULL;
	for (i=1;i<npaises;i++)//ciclo que ordena o um vetor em função da tempratura
	{
		for (j=i;j>0;j--)
		{
			if(paises[j]->temperatura < paises[j-1]->temperatura)
			{
				aux=paises[j];
				paises[j]=paises[j-1];
				paises[j-1]=aux;
			}
		}
	}
}
void bubleSort_amplitude(stats **paises, int npaises)
{
	int i =0;
	int j = 0;
	stats *aux=NULL;
	for (i=1;i<npaises;i++)//ciclo que ordena o um vetor em função da amplitude
	{
		for (j=i;j>0;j--)
		{
			if(paises[j]->Amplitude > paises[j-1]->Amplitude)
			{
				aux=paises[j];
				paises[j]=paises[j-1];
				paises[j-1]=aux;
			}
		}
	}
}

void AnaliseAnoPais(node_t *head)
{
	char NN[MAX_LINE_LEN]={0};// inicialização da string que guarda o numero de paises introduzido pelo utilizador
	char ano[MAX_LINE_LEN]={0};// inicialização da string que guarda o ano introduzido pelo utilizador
	char a='a';//inicialização da variavel que guarda um caracter que ajuda na obtenção do ano introduzido pelo utilizador

	int year=0;
	int N=0;
	int npaises=0;
	int i = 0;
	node_t *aux = NULL;

	stats **paises={NULL};

	stats *new_struct=NULL;

	paises=(stats**)malloc(sizeof(stats*));
	if (paises==NULL)
	{
		printf("ERRO na alocação de memória\n" );
		exit(EXIT_FAILURE);
	}

	while(year<1743||year>2013 || a != '\n' )
	{
		printf("Introduza um ano(Entre 1743 e 2013):");
		fgets(ano, MAX_LINE_LEN, stdin);// guarda a string  introduzida pelo utilizador
		sscanf(ano, "%d%c", &year, &a); // le os numeros e caracteres da string introduzida e guarda num inteiro
		if(year<1743||year>2013 || a != '\n') // se o numero não pertence á gama e existir caracteres depois do numero dá erro
			printf("ERRO: o valor introduzido não pertence à gama permitida \n");
	}
	while(N<1||N>20|| a != '\n' )
	{
		printf("Introduza o numero de paises que pretende analisar(entre 1 e 20): ");
		fgets(NN, MAX_LINE_LEN, stdin);// guarda a string  introduzida pelo utilizador
		sscanf(NN, "%d%c", &N, &a); // le os numeros e caracteres da string introduzida e guarda num inteiro
		if(N<1||N>20|| a != '\n') // se o numero não pertence á gama e existir caracteres depois do numero dá erro
			printf("ERRO: o valor introduzido não pertence à gama permitida \n");
	}

	aux=head;

	while(aux->payload.dt.ano != year && aux!=NULL)//percorre a lista ate encontrar
		aux=aux->next;							//informação do ano
	printf("%d\n",aux->payload.dt.ano );
	if(aux!=NULL)
	{

		while (aux->payload.dt.ano == year && aux!=NULL)//percorre a lista enquanto houver info sobre o ano
		{
			if (npaises==0)// no caso de o vetor estar vazio
			{

				npaises +=1;
				new_struct=(stats*)malloc(sizeof(stats));
				if (new_struct==NULL)
				{
					printf("ERRO na alocação de memória\n" );
					exit(EXIT_FAILURE);
				}

				strcpy(new_struct->nome, aux->payload.pais);
				new_struct->soma=aux->payload.temperatura;
				new_struct->count=1;
				new_struct->min=aux->payload.temperatura;
				new_struct->max=aux->payload.temperatura;
				paises[npaises-1]=new_struct;

			}
			else
			{
				for(i=0;i<npaises;i++)
				{
					if(strcmp(aux->payload.pais, paises[i]->nome)==0)
					{
						paises[i]->soma=paises[i]->soma+aux->payload.temperatura;
						paises[i]->count +=1;
						if(paises[i]->min > aux->payload.temperatura)
							paises[i]->min=aux->payload.temperatura;
						if(paises[i]->max < aux->payload.temperatura)
							paises[i]->max=aux->payload.temperatura;
						break;
					}
				}
				if(i==npaises)
				{
					npaises=npaises+1;
					paises=(stats**)realloc(paises,sizeof(stats*) * npaises);
					if (paises==NULL)
					{
						printf("ERRO na alocação de memória\n" );
						exit(EXIT_FAILURE);
					}
					new_struct=(stats*)malloc(sizeof(stats));
					if (new_struct==NULL)
					{
						printf("ERRO na alocação de memória\n" );
						exit(EXIT_FAILURE);
					}
					strcpy(new_struct->nome, aux->payload.pais);
					new_struct->soma=aux->payload.temperatura;
					new_struct->count=1;
					new_struct->min=aux->payload.temperatura;
					new_struct->max=aux->payload.temperatura;
					paises[npaises-1]=new_struct;
					}
				}
				aux=aux->next;
				//printf("%d\n", npaises);
		}
		for(i=0;i<npaises;i++)
		{
			paises[i]->temperatura= (paises[i]->soma)/(paises[i]->count);
			paises[i]->Amplitude= (paises[i]->max)-(paises[i]->min);
			//printf("%f-%f\n",paises[i]->temperatura,paises[i]->Amplitude );
		}
		bubleSort_temperatura(paises, npaises);
		printf("=============================\n" );
		printf("%d Paises mais frios:\n", N );
		for(i=0;i<N;i++)
		{
			printf("%s : %f\n",paises[i]->nome,paises[i]->temperatura);
		}
		printf("=============================\n" );
		printf("%d Paises mais quentes:\n", N );
		for(i=npaises-1;i>(npaises-N-1);i--)
		{
			printf("%s : %f\n",paises[i]->nome,paises[i]->temperatura);
		}
		bubleSort_amplitude(paises, npaises);
		printf("=============================\n" );
		printf("%d Paises mais extremos:\n", N );
		for(i=0;i<N;i++)
		{
			printf("%s:  Minimo:%f Máximo:%f\n",paises[i]->nome,paises[i]->min,paises[i]->max);
		}
		printf("=============================\n" );


	}
	else
		printf("Não existem dados sobre esse ano\n");
}
void AnaliseAnoCidade(node_l *head)
{
	char NN[MAX_LINE_LEN]={0};// inicialização da string que guarda o numero de paises introduzido pelo utilizador
	char ano[MAX_LINE_LEN]={0};// inicialização da string que guarda o ano introduzido pelo utilizador
	char a='a';//inicialização da variavel que guarda um caracter que ajuda na obtenção do ano introduzido pelo utilizador

	int year=0;
	int N=0;
	int ncidades=0;
	int i = 0;
	node_t *aux = NULL;
	node_l *tmp=NULL;

	stats **cidades={NULL};

	stats *new_struct=NULL;

	cidades=(stats**)malloc(sizeof(stats*));
	if (cidades==NULL)
	{
		printf("ERRO na alocação de memória\n" );
		exit(EXIT_FAILURE);
	}

	while(year<1743||year>2013 || a != '\n' )
	{
		printf("Introduza um ano(Entre 1743 e 2013):");
		fgets(ano, MAX_LINE_LEN, stdin);// guarda a string  introduzida pelo utilizador
		sscanf(ano, "%d%c", &year, &a); // le os numeros e caracteres da string introduzida e guarda num inteiro
		if(year<1743||year>2013 || a != '\n') // se o numero não pertence á gama e existir caracteres depois do numero dá erro
			printf("ERRO: o valor introduzido não pertence à gama permitida \n");
	}
	while(N<1||N>20|| a != '\n' )
	{
		printf("Introduza o numero de cidades que pretende analisar(entre 1 e 20): ");
		fgets(NN, MAX_LINE_LEN, stdin);// guarda a string  introduzida pelo utilizador
		sscanf(NN, "%d%c", &N, &a); // le os numeros e caracteres da string introduzida e guarda num inteiro
		if(N<1||N>20|| a != '\n') // se o numero não pertence á gama e existir caracteres depois do numero dá erro
			printf("ERRO: o valor introduzido não pertence à gama permitida!\n");
	}
	tmp=head;
	aux=tmp->cabeca;
	while(tmp->next!=NULL)//ciclo que corre a lista de listas
	{

			aux=tmp->cabeca;
		while(aux->payload.dt.ano != year && aux!=NULL)//ciclo que percorre a lista ate encontrar o ano introduzido pelo utilizador
			aux=aux->next;
		if(ncidades!=0)// no caso de o vetor estar vazio
		{
			new_struct=(stats*)malloc(sizeof(stats));//alocação de memoria para uma estrutura nova
			if (new_struct==NULL)
			{
				printf("ERRO na alocação de memória\n" );
				exit(EXIT_FAILURE);
			}
			strcpy(new_struct->nome, aux->payload.cidade);
			new_struct->soma= aux->payload.temperatura;
			new_struct->count=1;
			new_struct->min= aux->payload.temperatura;
			new_struct->max= aux->payload.temperatura;
			cidades[ncidades-1]=new_struct;
		}
		if(aux!=NULL)//caso exista informação sobre esse ano
		{

			while (aux->payload.dt.ano == year && aux->next!=NULL)//ciclo que percorre a lista ate encontrar um node com o ano diferente do intrpduzido
			{																											//ou no caso de nao exitir mais valores na lista
				if (ncidades==0)// no caso de o vetor estar vazio
				{
					ncidades+=1;//é incrementado o numero de paises
					new_struct=(stats*)malloc(sizeof(stats));//alocação de memoria para uma estrutura
					if (new_struct==NULL)
					{
						printf("ERRO na alocação de memória\n" );
						exit(EXIT_FAILURE);
					}
					//atualização das variaveis da estrutura com os valores do node
					strcpy(new_struct->nome, aux->payload.cidade);
					new_struct->soma=aux->payload.temperatura;
					new_struct->count=1;
					new_struct->min=aux->payload.temperatura;
					new_struct->max=aux->payload.temperatura;
					cidades[ncidades-1]=new_struct;
				}
				else//caso a lista nao esteja vazia
				{
					cidades[ncidades-1]->soma=cidades[ncidades-1]->soma+aux->payload.temperatura;
					cidades[ncidades-1]->count +=1;
					if(cidades[ncidades-1]->min > aux->payload.temperatura)//caso a temperatura no node seja menor qu o minimo
						cidades[ncidades-1]->min=aux->payload.temperatura;
					if(cidades[ncidades-1]->max < aux->payload.temperatura)//caso a tempratura do node seja maior qur o maximo
						cidades[ncidades-1]->max=aux->payload.temperatura;
				}
				aux=aux->next;
			}


			tmp=tmp->next;
			//printf("%s\n",tmp->cabeca->payload.cidade );
			ncidades=ncidades+1;
			cidades=(stats**)realloc(cidades,sizeof(stats*) * ncidades);//realocação da memoria para mais um elemento do vetor
			if (cidades==NULL)
			{
				printf("ERRO na alocação de memória\n" );
				exit(EXIT_FAILURE);
			}

		}
	}
	//ler a ultima lista da lista de listas
		aux=tmp->cabeca;
	while (aux->payload.dt.ano != year && aux->next!=NULL)
		aux=aux->next;
		//atualização das variaveis da estrutura com os valores do node
		strcpy(new_struct->nome, aux->payload.cidade);
		new_struct->soma= aux->payload.temperatura;
		new_struct->count=1;
		new_struct->min= aux->payload.temperatura;
		new_struct->max= aux->payload.temperatura;
		cidades[ncidades-1]=new_struct;

	while (aux->payload.dt.ano == year && aux->next!=NULL)//ciclo que percorre a lista ate encontrar um node com o ano diferente do intrpduzido
	{
			cidades[ncidades-1]->soma=cidades[ncidades-1]->soma+aux->payload.temperatura;
			cidades[ncidades-1]->count +=1;
			if(cidades[ncidades-1]->min > aux->payload.temperatura)//caso a temperatura no node seja menor qu o minimo
				cidades[ncidades-1]->min=aux->payload.temperatura;
			if(cidades[ncidades-1]->max < aux->payload.temperatura)//caso a tempratura do node seja maior qur o maximo
				cidades[ncidades-1]->max=aux->payload.temperatura;

		aux=aux->next;
	}
	for(i=0;i<ncidades;i++)//calculo da amplitude e da média das temperaturas para os npaises
	{
		cidades[i]->temperatura= (cidades[i]->soma)/(cidades[i]->count);
		cidades[i]->Amplitude= (cidades[i]->max)-(cidades[i]->min);
	}
	bubleSort_temperatura(cidades, ncidades);//função que ordena o vetor em função da temperaturas
	printf("=============================\n" );
	printf("%d Cidades mais frias:\n", N );
	for(i=0;i<N;i++)//ciclo que imprime as N cidades mais frios
	{
		printf("%s : %f\n",cidades[i]->nome,cidades[i]->temperatura);
	}
	printf("=============================\n" );
	printf("%d Cidades mais quentes:\n", N );
	for(i=ncidades-1;i>(ncidades-N-1);i--)//ciclo que imprime as N cidades smais quentes
	{
		printf("%s : %f\n",cidades[i]->nome,cidades[i]->temperatura);
	}
	bubleSort_amplitude(cidades, ncidades);//função que ordena o vetor em função da amplitude
	printf("=============================\n" );
	printf("%d Cidades mais extremas:\n", N );
	for(i=0;i<N;i++)//ciclo que imprime as N cidades mais extremas
	{
		printf("%s: Minimo:%f Máximo:%f\n",cidades[i]->nome,cidades[i]->min,cidades[i]->max);
	}
	printf("=============================\n" );
}
void analiseGlobal(node_t *head)
{
	float **temperaturas = NULL; //inicializaçãode um vetor de ponteiros, cada pondeiro correspondente a um mes
	float **temperaturasMA=NULL;//inicialização da "matriz que guardas as moving averages"
	float* temperaturasAno=NULL;//vetpr que guarda temperaturas por ano
	int *anos=NULL;//vetor que guarda o ano da temperatura guardada no vetor inicializado em cima
	int n_anos=0;//valiavel que guarda o numero de anos
	int i=0, j=0,temp=0;//variaveis contador
	int mes=0;//variavel que guarda a posição correspondente ao mes na matrix
	int ano=0;//variavel que guarda a posição correspondente ao ano na matrix
	int ano_inicial=0;//variavel que guarda o ano inicial
	float soma=0.0f;//variavel que guarda o valor da soma para o calculo de médias
	float aumento=0.0f;//variavel que calcula o aumento/diminuição de temperatura

	node_t *aux=NULL;
	int min=0,max=0;//inicialização das variavéis que guardam as posições nos vetores onde estão o minimo e o máximo;


	n_anos=getAnos(head);//função que cacula o numero de anos da lista para a alocação de memória

	anos=(int*)malloc(n_anos*sizeof(int));
	temperaturasAno = (float*)malloc(n_anos*sizeof(float));
	if (temperaturasAno==NULL)//verificação da aloocação
	{
		printf("ERRO na alocação de memória\n" );
		exit(EXIT_FAILURE);
	}


	temperaturas=(float**)malloc(12*sizeof(float*));//alocação para as linhas de da matrix que guarda as temperaturas
	if (temperaturas==NULL)//verificação da aloocação
	{
		printf("ERRO na alocação de memória\n" );
		exit(EXIT_FAILURE);
	}
	for(i=0; i < 12; i++)
	{
		temperaturas[i] = (float*)calloc(n_anos,sizeof(float));

		if (temperaturas[i]==NULL)//verificação da aloocação
		{
			printf("ERRO na alocação de memória\n" );
			exit(EXIT_FAILURE);
		}
	}


	aux=head;//aux aponta para a cebaca
	ano_inicial= head->payload.dt.ano;//obtenção do ano inicial,uma vez que a lista esta ordenada por data
	anos[0]=ano_inicial;
	while(aux!=NULL)
	{
		i=0;//reinicialização da variavel
		soma=0;//reinicialização da variavel
		mes=aux->payload.dt.mes;//a variavel que guarda o mes é igualada ao mes do no que esta a ser analisado
		while(aux->next->payload.dt.mes == aux->payload.dt.mes && aux->next !=NULL)//enquanto o mes do node a analisar e do pŕoximo forem iguais
		{
			soma=soma+aux->payload.temperatura;//atualização da soma para calculo da média
			aux=aux->next;//analise do proximo nó
			i++;//incremento de i

			if (aux->next==NULL) break;//este bloco foi para corrigir um erro em que não saia do while mesmo com a condição em cima
		}
		if (aux->next==NULL) break;

		temperaturas[mes-1][ano]=soma/i;//calculo da média da temperatura
		mes=aux->next->payload.dt.mes;//atualização do mes que estamos a analisar com o mes do proximo node
		if(aux->next->payload.dt.ano != aux->payload.dt.ano)//caso haja uma mudança de ano
		{
			mes=aux->next->payload.dt.mes;//atualização do mes que estamos a analisar com o mes do proximo node
			ano++;//incremento da variavel que guarda o ano
			anos[ano]=aux->next->payload.dt.ano;//guarda ano novo na posição equivalente no vetor
		}
		if(aux->next !=NULL)//caso não esteja a ser analisado o ultimo node
			aux=aux->next;
	}

	temperaturasMA=movingAverage(temperaturas, n_anos);//função que realiza a movingAverageaverage e guarda os valores noutra matrix

	for(i=0;i<n_anos; i++)//ciclo para calcular a temperatura média de cada ano
	{
		soma=0;//reinicialização da soma
		temp=0;//e do contador
		for(j=0;j<12;j++)//
		{
			if(temperaturasMA[j][i] != 0.00000000f)//caso não haja valores na lista
			{
				soma=soma+temperaturasMA[j][i];//calculo da soma
				temp++;//incremento do contador
			}
		}
		temperaturasAno[i]=soma/temp;//calculo da temperatura e armazenamento num vetor

	}


	i=0;
	if(anos[0]<1860)//caso exista valores antes de 1860
	{
		while(anos[i]<=1860)//ciclo que procura a temperatura minima e máxima
		{
			if(temperaturasAno[max]<temperaturasAno[i])
				max=i;//guarda a posição da temperatura e do ano
			if(temperaturasAno[min]>temperaturasAno[i])
				min=i;//guarda a posição da temperatura e do ano
			i++;
		}
		aumento= temperaturasAno[max]-temperaturasAno[min];//calculo do aumento da temperatura
		if(anos[max]>anos[min])//caso em que há aumento
			printf("Entre %d e 1860 houve um aumento de %f graus\n",anos[0], aumento);
		else//caso em que ha diminuição
			printf("Entre %d e 1860 houve uma diminuição de %f graus\n",anos[0], aumento);
	}
	i=0;//reinicializaçãodo contador e da posição do max e do min
	max=0;
	min=0;
	if(anos[0]<1910)//caso exista anos antes de 1910
	{
		while(anos[i]<=1910)
		{
			if(temperaturasAno[max]<temperaturasAno[i])
				max=i;
			if(temperaturasAno[min]>temperaturasAno[i])
				min=i;
			i++;
		}
		aumento= temperaturasAno[max]-temperaturasAno[min];
		if(anos[max]>anos[min])
			printf("Entre %d e 1910 houve um aumento de %f graus\n",anos[0], aumento);
		else
			printf("Entre %d e 1910 houve uma diminuição de %f graus\n",anos[0], aumento);
	}
	i=0;
	max=0;
	min=0;
	if(anos[0]<1960)//caso exista anos antes de 1960
	{
		while(anos[i]<=1960)
		{
			if(temperaturasAno[max]<temperaturasAno[i])
				max=i;
			if(temperaturasAno[min]>temperaturasAno[i])
				min=i;
			i++;
		}
		aumento= temperaturasAno[max]-temperaturasAno[min];
		if(anos[max]>anos[min])
			printf("Entre %d e 1960 houve um aumento de %f graus\n",anos[0], aumento);
		else
			printf("Entre %d e 1960 houve uma diminuição de %f graus\n",anos[0], aumento);
	}
	i=0;
	max=0;
	min=0;
	if(anos[0]<1990)
	{
		while(anos[i]<=1990)//caso exista anos antes de 1990
		{
			if(temperaturasAno[max]<temperaturasAno[i])
				max=i;
			if(temperaturasAno[min]>temperaturasAno[i])
				min=i;
			i++;
		}
		aumento= temperaturasAno[max]-temperaturasAno[min];
		if(anos[max]>anos[min])
			printf("Entre %d e 1910 houve um aumento de %f graus\n",anos[0], aumento);
		else
			printf("Entre %d e 1910 houve uma diminuição de %f graus\n",anos[0], aumento);
	}
	i=0;
	max=0;
	min=0;
	if(anos[0]<2013)
	{
		while(anos[i]<=2013)
		{
			if(temperaturasAno[max]<temperaturasAno[i])
				max=i;
			if(temperaturasAno[min]>temperaturasAno[i])
				min=i;
			i++;
		}
		aumento= temperaturasAno[max]-temperaturasAno[min];
		if(anos[max]>anos[min])
			printf("Entre %d e 2013 houve um aumento de %f graus\n",anos[0], aumento);
		else
			printf("Entre %d e 2013 houve uma diminuição de %f graus\n",anos[0], aumento);
	}
	free(aux);
}
void analiseCidades(node_l *head)
{
	node_t *aux= NULL;
	node_l *tmp=NULL;
	char city[MAX_LINE_LEN]={0};
	float **temperaturas = NULL; //inicializaçãode um vetor de ponteiros, cada pondeiro correspondente a um mes
	float **temperaturasMA=NULL;//inicialização da "matriz que guardas as moving averages"
	float* temperaturasAno=NULL;//vetpr que guarda temperaturas por ano
	int *anos=NULL;//vetor que guarda o ano da temperatura guardada no vetor inicializado em cima
	int n_anos=0;
	int i=0, j=0,temp=0;
	int ano=0;
	int ano_inicial=0;
	float soma=0.0f;
	float aumento=0.0f;
	int min=0,max=0;//inicialização das variavéis que guardam as posições nos vetores onde estão o minimo e o máximo;
	tmp=head;
	GetCity(head,city);
	while(strcmp(tmp->cidade, city)!=0)	// ciclo que encontra o node em que esta guardada a cabeça
		tmp=tmp->next;																	// da lista com a cidade pretendida

	aux =tmp->cabeca;

	n_anos=getAnos(aux);//função que cacula o numero de anos da lista para a alocação de memória
	anos=(int*)malloc(n_anos*sizeof(int));
	temperaturasAno = (float*)malloc(n_anos*sizeof(float));
	if (temperaturasAno==NULL)//verificação da aloocação
	{
		printf("ERRO na alocação de memória\n" );
		exit(EXIT_FAILURE);
	}


	temperaturas=(float**)malloc(12*sizeof(float*));//alocação para as linhas de da matrix que guarda as temperaturas
	if (temperaturas==NULL)//verificação da aloocação
	{
		printf("ERRO na alocação de memória\n" );
		exit(EXIT_FAILURE);
	}
	for(i=0; i < 12; i++)
	{
		temperaturas[i] = (float*)calloc(n_anos, sizeof(float));

		if (temperaturas[i]==NULL)//verificação da aloocação
		{
			printf("ERRO na alocação de memória\n" );
			exit(EXIT_FAILURE);
		}
	}

	ano_inicial= aux->payload.dt.ano;//obtenção do ano inicial,uma vez que a lista esta ordenada por data
	anos[0]=ano_inicial;
	while(aux->next!=NULL)
	{
		temperaturas[aux->payload.dt.mes-1][ano]=aux->payload.temperatura;//calculo da média da temperatura
		if(aux->next->payload.dt.ano != aux->payload.dt.ano||aux->next!=NULL)//caso haja uma mudança de ano
		{
			ano++;//incremento da variavel que guarda o ano
			anos[ano]=aux->next->payload.dt.ano;//guarda ano novo na posição equivalente no vetor
		}
		aux=aux->next;
	}
	//para o ultimo elemento da node
	temperaturas[aux->payload.dt.mes-1][ano]=aux->payload.temperatura;//atualização da temperatura

	temperaturasMA=movingAverage(temperaturas, n_anos);//função que realiza a movingAverageaverage e guarda os valores noutra matrix

	for(i=0;i<n_anos; i++)//ciclo para calcular a temperatura média de cada ano
	{
		soma=0;//reinicialização da soma
		temp=0;//e do contador
		for(j=0;j<12;j++)//
		{
			if(temperaturasMA[j][i] != 0.00000000f)//caso não haja valores na lista
			{
				soma=soma+temperaturasMA[j][i];//calculo da soma
				temp++;//incremento do contador
			}
		}
		temperaturasAno[i]=soma/temp;//calculo da temperatura e armazenamento num vetor
	}

	i=0;
	if(anos[0]<1860)//caso exista valores antes de 1860
	{
		while(anos[i]<=1860)//ciclo que procura a temperatura minima e máxima
		{
			if(temperaturasAno[max]<temperaturasAno[i])
				max=i;//guarda a posição da temperatura e do ano
			if(temperaturasAno[min]>temperaturasAno[i])
				min=i;//guarda a posição da temperatura e do ano
			i++;
		}
		aumento= temperaturasAno[max]-temperaturasAno[min];//calculo do aumento da temperatura
		if(anos[max]>anos[min])//caso em que há aumento
			printf("Entre %d e 1860 houve um aumento de %f graus\n",anos[0], aumento);
		else//caso em que ha diminuição
			printf("Entre %d e 1860 houve uma diminuição de %f graus\n",anos[0], aumento);
	}
	i=0;//reinicializaçãodo contador e da posição do max e do min
	max=0;
	min=0;
	if(anos[0]<1910)//caso exista anos antes de 1910
	{
		while(anos[i]<=1910)
		{
			if(temperaturasAno[max]<temperaturasAno[i])
				max=i;
			if(temperaturasAno[min]>temperaturasAno[i])
				min=i;
			i++;
		}
		aumento= temperaturasAno[max]-temperaturasAno[min];
		if(anos[max]>anos[min])
			printf("Entre %d e 1910 houve um aumento de %f graus\n",anos[0], aumento);
		else
			printf("Entre %d e 1910 houve uma diminuição de %f graus\n",anos[0], aumento);
	}
	i=0;
	max=0;
	min=0;
	if(anos[0]<1960)//caso exista anos antes de 1960
	{
		while(anos[i]<=1960)
		{
			if(temperaturasAno[max]<temperaturasAno[i])
				max=i;
			if(temperaturasAno[min]>temperaturasAno[i])
				min=i;
			i++;
		}
		aumento= temperaturasAno[max]-temperaturasAno[min];
		if(anos[max]>anos[min])
			printf("Entre %d e 1960 houve um aumento de %f graus\n",anos[0], aumento);
		else
			printf("Entre %d e 1960 houve uma diminuição de %f graus\n",anos[0], aumento);
	}
	i=0;
	max=0;
	min=0;
	if(anos[0]<1990)
	{
		while(anos[i]<=1990)//caso exista anos antes de 1990
		{
			if(temperaturasAno[max]<temperaturasAno[i])
				max=i;
			if(temperaturasAno[min]>temperaturasAno[i])
				min=i;
			i++;
		}
		aumento= temperaturasAno[max]-temperaturasAno[min];
		if(anos[max]>anos[min])
			printf("Entre %d e 1910 houve um aumento de %f graus\n",anos[0], aumento);
		else
			printf("Entre %d e 1910 houve uma diminuição de %f graus\n",anos[0], aumento);
	}
	i=0;
	max=0;
	min=0;
	if(anos[0]<2013)
	{
		while(anos[i]<=2013)
		{
			if(temperaturasAno[max]<temperaturasAno[i])
				max=i;
			if(temperaturasAno[min]>temperaturasAno[i])
				min=i;
			i++;
		}
		aumento= temperaturasAno[max]-temperaturasAno[min];
		if(anos[max]>anos[min])
			printf("Entre %d e 2013 houve um aumento de %f graus\n",anos[0], aumento);
		else
			printf("Entre %d e 2013 houve uma diminuição de %f graus\n",anos[0], aumento);
	}
	free(aux);
	free(tmp);
}
void analisePaises(node_t *head)
{
	node_t *aux= NULL;
	char country[MAX_LINE_LEN]={0};
	float **temperaturas = NULL; //inicializaçãode um vetor de ponteiros, cada pondeiro correspondente a um mes
	float **temperaturasMA=NULL;//inicialização da "matriz que guardas as moving averages"
	float* temperaturasAno=NULL;//vetpr que guarda temperaturas por ano
	int *anos=NULL;//vetor que guarda o ano da temperatura guardada no vetor inicializado em cima
	int n_anos=0;
	int i=0, j=0,temp=0;
	int ano=0;
	int anoaux=0;
	int ano_inicial=0;
	float soma=0.0f;
	float aumento=0.0f;
	int min=0,max=0;//inicialização das variavéis que guardam as posições nos vetores onde estão o minimo e o máximo;
	GetCountry(head,country);
	aux=head;
	while(strcmp(aux->payload.pais, country)!=0)//ciclo para encontrar a primeira informação sobre o pais
		aux=aux->next;
	ano_inicial=aux->payload.dt.ano;



	n_anos=getAnos(aux);//função que cacula o numero de anos da lista para a alocação de memória
	anos=(int*)malloc(n_anos*sizeof(int));
	temperaturasAno = (float*)malloc(n_anos*sizeof(float));
	if (temperaturasAno==NULL)//verificação da aloocação
	{
		printf("ERRO na alocação de memória\n" );
		exit(EXIT_FAILURE);
	}


	temperaturas=(float**)malloc(12*sizeof(float*));//alocação para as linhas de da matrix que guarda as temperaturas
	if (temperaturas==NULL)//verificação da aloocação
	{
		printf("ERRO na alocação de memória\n" );
		exit(EXIT_FAILURE);
	}
	for(i=0; i < 12; i++)
	{
		temperaturas[i] = (float*)calloc(n_anos,sizeof(float));

		if (temperaturas[i]==NULL)//verificação da aloocação
		{
			printf("ERRO na alocação de memória\n" );
			exit(EXIT_FAILURE);
		}
	}
	anos[0]= ano_inicial;//colocada a primeira posição do vetor com o ano inicial
	while(aux->next!=NULL)
	{
		anoaux=aux->payload.dt.ano;
		while (strcmp(aux->payload.pais, country)!=0 &&aux->next!=NULL)
			aux=aux->next;
		if(anoaux != aux->payload.dt.ano||aux->next!=NULL)//caso haja uma mudança de ano
		{
			ano++;//incremento da variavel que guarda o ano
			anos[ano]=aux->payload.dt.ano;
		}
		if (strcmp(aux->payload.pais, country)==0)
			temperaturas[aux->payload.dt.mes-1][ano]=aux->payload.temperatura;//calculo da média da temperatura
		if (aux->next!=NULL)
			aux=aux->next;

	}
	//para o ultimo elemento da node
	temperaturas[aux->payload.dt.mes-1][ano]=aux->payload.temperatura;//atualização da temperatura

	temperaturasMA=movingAverage(temperaturas, n_anos);//função que realiza a movingAverageaverage e guarda os valores noutra matrix

	for(i=0;i<n_anos; i++)//ciclo para calcular a temperatura média de cada ano
	{
		soma=0;//reinicialização da soma
		temp=0;//e do contador
		for(j=0;j<12;j++)//
		{
			if(temperaturasMA[j][i] != 0.00000000f)//caso não haja valores na lista
			{
				soma=soma+temperaturasMA[j][i];//calculo da soma
				temp++;//incremento do contador
			}
		}
		temperaturasAno[i]=soma/temp;//calculo da temperatura e armazenamento num vetor

	}

	i=0;
	if(anos[0]<1860)//caso exista valores antes de 1860
	{
		while(anos[i]<=1860)//ciclo que procura a temperatura minima e máxima
		{
			if(temperaturasAno[max]<temperaturasAno[i])
				max=i;//guarda a posição da temperatura e do ano
			if(temperaturasAno[min]>temperaturasAno[i])
				min=i;//guarda a posição da temperatura e do ano
			i++;
		}
		aumento= temperaturasAno[max]-temperaturasAno[min];//calculo do aumento da temperatura
		if(anos[max]>anos[min])//caso em que há aumento
			printf("Entre %d e 1860 houve um aumento de %f graus\n",anos[0], aumento);
		else//caso em que ha diminuição
			printf("Entre %d e 1860 houve uma diminuição de %f graus\n",anos[0], aumento);
	}
	i=0;//reinicializaçãodo contador e da posição do max e do min
	max=0;
	min=0;
	if(anos[0]<1910)//caso exista anos antes de 1910
	{
		while(anos[i]<=1910)
		{
			if(temperaturasAno[max]<temperaturasAno[i])
				max=i;
			if(temperaturasAno[min]>temperaturasAno[i])
				min=i;
			i++;
		}
		aumento= temperaturasAno[max]-temperaturasAno[min];
		if(anos[max]>anos[min])
			printf("Entre %d e 1910 houve um aumento de %f graus\n",anos[0], aumento);
		else
			printf("Entre %d e 1910 houve uma diminuição de %f graus\n",anos[0], aumento);
	}
	i=0;
	max=0;
	min=0;
	if(anos[0]<1960)//caso exista anos antes de 1960
	{
		while(anos[i]<=1960)
		{
			if(temperaturasAno[max]<temperaturasAno[i])
				max=i;
			if(temperaturasAno[min]>temperaturasAno[i])
				min=i;
			i++;
		}
		aumento= temperaturasAno[max]-temperaturasAno[min];
		if(anos[max]>anos[min])
			printf("Entre %d e 1960 houve um aumento de %f graus\n",anos[0], aumento);
		else
			printf("Entre %d e 1960 houve uma diminuição de %f graus\n",anos[0], aumento);
	}
	i=0;
	max=0;
	min=0;
	if(anos[0]<1990)
	{
		while(anos[i]<=1990)//caso exista anos antes de 1990
		{
			if(temperaturasAno[max]<temperaturasAno[i])
				max=i;
			if(temperaturasAno[min]>temperaturasAno[i])
				min=i;
			i++;
		}
		aumento= temperaturasAno[max]-temperaturasAno[min];
		if(anos[max]>anos[min])
			printf("Entre %d e 1910 houve um aumento de %f graus\n",anos[0], aumento);
		else
			printf("Entre %d e 1910 houve uma diminuição de %f graus\n",anos[0], aumento);
	}
	i=0;
	max=0;
	min=0;
	if(anos[0]<2013)
	{
		while(anos[i]<=2013)
		{
			if(temperaturasAno[max]<temperaturasAno[i])
				max=i;
			if(temperaturasAno[min]>temperaturasAno[i])
				min=i;
			i++;
		}
		aumento= temperaturasAno[max]-temperaturasAno[min];
		if(anos[max]>anos[min])
			printf("Entre %d e 2013 houve um aumento de %f graus\n",anos[0], aumento);
		else
			printf("Entre %d e 2013 houve uma diminuição de %f graus\n",anos[0], aumento);
	}
	free(aux);
}
