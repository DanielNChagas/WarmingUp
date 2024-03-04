/*Ficheiros.c*/
/*Daniel Chagas 90043*/
/*Mariana Santos 90137*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"



void ler_cidades(int _f2, char *_argv[], node_l **_head_cities)
{
	FILE *fp = NULL;
	// node_l *new_node_l=NULL;
	node_t *new_node=NULL;
	node_t *tail=NULL;

	node_l *tail_lists = NULL;


	char line[MAX_LINE_LEN]={0};
	char * token = NULL;
	int data =0;
	int flag = 1;
	char auxc='0';
	tail= GetNewNode();

	fp = fopen(_argv[_f2], "r");
	if(fp==NULL)    //verificação da correta abertura do ficheiro
	{
	printf("ERRO ficheiro não encontrado");
	exit(EXIT_FAILURE);
	}
	while (	fgets(line, MAX_LINE_LEN, fp) != NULL)//percorre o ficheiro ate ao fim lendo linha a linha 
	{

		flag=1;
		new_node=GetNewNode();//alocaçao de memoria para o node

		token= strtok(line, ",");//leitura da linha ate à vírgula
		data=sscanf(token,"%d-%d-%d", &new_node->payload.dt.ano,&new_node->payload.dt.mes,&new_node->payload.dt.dia);
		if(data!=3 || token==NULL)//caso sejam lidos parametros a menos
		{
			flag=0;
		}
		else//caso contrario
		{
			token= strtok(NULL, ",");//leitura da linha ate à vírgula
			sscanf(token, "%f", &new_node->payload.temperatura);
			token= strtok(NULL, ",");//leitura da linha ate à vírgula
			sscanf(token, "%f", &new_node->payload.incerteza);
			token= strtok(NULL, ",");//leitura da linha ate à vírgula
			sscanf(token, "%s", new_node->payload.cidade);
			
			token= strtok(NULL, ",");//leitura da linha ate à vírgula
			sscanf(token, "%s", new_node->payload.pais);
			
			token= strtok(NULL, ",");//leitura da linha ate à vírgula
			if(token==NULL)//caso nao exista info. sobre a temperatura
			{
				flag=0;
			}
			else
			{
				sscanf(token, "%f%c", &new_node->payload.lat.angle,&auxc);
				if(auxc=='N')
					new_node->payload.lat.hemisferio =1;
				else 	if(auxc=='S')
					new_node->payload.lat.hemisferio =2;
			}
			token= strtok(NULL, "/r");// le ate ao final da linha
			if(token==NULL)//caso nao exista info. sobre a temperatura
			{
				flag=0;//nao e guardado na lista
			}
			else// caso contrario guarda na lista
			{
				sscanf(token, "%f%c", &new_node->payload.longit.angle, &auxc);
				if(auxc=='W')
					new_node->payload.longit.hemisferio =3;
				else
					new_node->payload.longit.hemisferio =4;
			}
		}

		if((*_head_cities)==NULL && flag==1)//caso a lista de listas esteja vazia
		{

			(*_head_cities)=GetNewNode_l();
			(*_head_cities)->cabeca=new_node;
			tail_lists= (*_head_cities);
			strcpy(tail_lists->cidade, new_node->payload.cidade);
			tail_lists->next = NULL;
			insertTail(&tail_lists->cabeca, &tail, new_node);


		}
		else//caso contrario 
		{

			if (flag==1)
			{
				if(strcmp(new_node->payload.cidade, tail_lists->cabeca->payload.cidade)==0)
				{	/*Se ja existir um no para essa cidade */
					insertTail(&tail_lists->cabeca, &tail, new_node);
				}
				else
				/*Se nao existir um no para essa cidade cria um para essa */
				{

					//print_list(tail_lists->cabeca);
					tail_lists->next=GetNewNode_l();
					insertTail(&tail_lists->next->cabeca,&tail, new_node );
					tail_lists=tail_lists->next;
					tail_lists->next=NULL;
					strcpy(tail_lists->cidade, new_node->payload.cidade);


				}
			}
		}
	}
	fclose(fp);
	
}
void ler_pais(int _f1, char *_argv[],node_l **headc)
{
	FILE *fp = NULL;
	node_t *new_node=NULL;
	node_l *new_node_l=NULL;
	node_l *aux=NULL;
	node_l *tmp=NULL;
	char line[MAX_LINE_LEN]={0};
	char * token = NULL;
	int data=0;
	int flag = 0;
	fp = fopen(_argv[_f1], "r");
	if(fp==NULL)    //verificação da correta abertura do ficheiro
	{
	printf("ERRO ficheiro não encontrado");
	exit(EXIT_FAILURE);
	}

	while (fgets(line, MAX_LINE_LEN, fp) != NULL)//semelhante à função descrita em cima na parte de leitura da linha
	{
		
		new_node=GetNewNode();
		new_node_l=GetNewNode_l();
		flag=0;
		//semelhante à função descrita em cima na parte de leitura da linha
		token= strtok(line, ",");
		data=sscanf(token,"%d-%d-%d", &new_node->payload.dt.ano,&new_node->payload.dt.mes,&new_node->payload.dt.dia);
		if(data!=3 || token==NULL)
		{
			flag=1;
		}
		else
		{
			token= strtok(NULL, ",");
			sscanf(token, "%f", &new_node->payload.temperatura);
			token= strtok(NULL, ",");
			if(token==NULL)
			{
				flag=1;
			}
			else
			{
				sscanf(token, "%f", &new_node->payload.incerteza);
				token= strtok(NULL, "\r");
				if(token==NULL)
				{
					flag=1;
				}
			else
				strcpy(new_node->payload.pais, token);

			}
			if (flag== 0)//caso é necessário guardar na lista
			{
				if((*headc) == NULL)//se a lista estiver vazia
				{
					(*headc)=GetNewNode_l();//aloca memoria para a head
					(*headc)->ano= new_node->payload.dt.ano;

					insertSortMes(&(*headc)->cabeca, new_node);//insere na lista 

				}
				else//caso ja exista lista
				{
					aux=(*headc);//auxiliar aponta para a cabeça
					while(new_node->payload.dt.ano !=aux->ano)//percorre a lista ate encontra
					{//se ja existe uma lista que guarda relativamente ao ano do novo no
					
						aux=aux->next;
						if(aux==NULL)break;//se percorrer a lista toda quebra o loop

					}

					if(aux!=NULL)//se existir uma lista que guarda o ano
					{
					//faz insertion sort do novo no
						insertSortMes(&aux->cabeca,new_node );
					
					}
					else//caso não exista uma lista referente ao pais
					{
					//cria uma nova lista inserida no final da lista de listas
						new_node_l->ano=new_node->payload.dt.ano;
						new_node_l->cabeca=new_node;
						tmp=insertSortAno(headc, new_node_l);
						tmp->cabeca=NULL;
					//insere o mes	
						insertSortMes(&tmp->cabeca,new_node );
					
					}
				}
			}
		}
	}

	fclose(fp);

}
