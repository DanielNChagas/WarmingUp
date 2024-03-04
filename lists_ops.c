/*Lists_ops.c*/
/*Daniel Chagas 90043*/
/*Mariana Santos 90137*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

node_t *GetNewNode()
{
	node_t *new_node=NULL;
	new_node=(node_t*)malloc(sizeof(node_t));//alocação de memoria para o novo node
	if (new_node==NULL)
	{
		printf("ERRO na alocação de memória\n" );
		exit(EXIT_FAILURE);
	}
	new_node->next=NULL;
	new_node->prev=NULL;
	return new_node;
}
node_l *GetNewNode_l()
{
	node_l *new_node=NULL;
	new_node=(node_l*)malloc(sizeof(node_l));//alocação de memoria para o novo node
	if (new_node==NULL)
	{
		printf("ERRO na alocação de memória\n" );
		exit(EXIT_FAILURE);
	}
	new_node->next=NULL;

	return new_node;
}
void print_list(node_t *_head)//função que imprime uma lista(auxiliar)
{
	node_t *aux=NULL;
	aux = _head;
	while(aux != NULL)
	{
		printf("%d-%d-%d,%f,%f,%s\n",aux->payload.dt.ano,aux->payload.dt.mes,aux->payload.dt.dia, aux->payload.temperatura,aux->payload.incerteza, aux->payload.pais);
		aux= aux->next;
	}
}
void print_list_l(node_l *_head)//função que imprime uma lista(auxiliar)
{
	node_l *aux=NULL;
	aux = _head;
	while(aux != NULL)
	{
		printf("%s-%d\n",aux->cidade,aux->ano);

		aux= aux->next;
	}
}
void removeHead_L(node_l **_head)
{
	node_l *aux=NULL;//inicialização de um ponteiro auxiliar
	if(*_head==NULL)//caso a lista esteja vazia
		return;
	aux=*_head;//igualar o ponteiro auxiliar à cabeça que vai ser removida
	*_head=(*_head)->next;//atualização da head (igualar ao elemento da lista a seguir à head)
	free(aux);//libertar a memoria antiga
}
void removeHead(node_t **_head)
{
	node_t *aux=NULL;//inicialização de um ponteiro auxiliar
	if(*_head==NULL)//caso a lista esteja vazia
		return;
	aux=*_head;//igualar o ponteiro auxiliar à cabeça que vai ser removida
	*_head=(*_head)->next;//atualização da head (igualar ao elemento da lista a seguir à head)
	(*_head)->prev=NULL;//apontar o que esta antes da lista para NULL
	free(aux);//libertar a memoria antiga
}
void removeNode (node_t *aux)
{
	node_t *tmp = NULL;//inicialização de um ponteiro auxiliar
	tmp=aux->next;//igualar o vetor auxiliar à elemento a seguir ao aux
	aux->next= tmp->next;// ligação do aux ao elemento a seguir ao tmp
	aux->next->prev = aux; // ligação desse elemento ao aux no sentido contrario
	free(tmp);//libertar a memoria do node a eleminar
}
node_t *criaLista(node_l *head)//função que transforma uma lista de listas numa lista
{

	node_t *headLista=NULL;
	node_t *aux=NULL;
	node_l *tmp=NULL;

	headLista=head->cabeca;//aponta a cabeça da lista para a cabeça da primeira lista da lista das listas
	tmp=head;


	while(tmp->next!=NULL )	//percorre uma lista da lista de listas  e une a 
	{						//cabeça da proxima lista á tail da anterior
		
		aux=tmp->cabeca;
		while (aux->next!= NULL)
		{
			
			aux=aux->next;
			
		}
		
		tmp=tmp->next;
		
		aux->next=tmp->cabeca;
		
	}

	return headLista;
}
void insertTail(node_t **_head, node_t **_tail, node_t *_new_elem)
{

	if((*_head)==NULL)//caso não exita cabeca
	{
		
		(*_head)= _new_elem;
		(*_tail)= _new_elem;
		(*_tail)->next=NULL;
		(*_head)->next = NULL;
		
		return;
	}
	else//caso a lista exista
	{
		if((*_head)==(*_tail))//caso so tenha um elemento
		{
			_new_elem->next = (*_tail)->next;
			(*_tail)->next = _new_elem;
			(*_head)->next = _new_elem;
			(*_tail)=_new_elem;
		}
		else//caso contrario
		{
			_new_elem->next = (*_tail)->next;
			(*_tail)->next = _new_elem;
			(*_tail)=_new_elem;
		}
	}

}
node_l *insertSortAno(node_l **_head,node_l *new_node)
{
	node_l *aux=NULL;
	aux=(*_head);
	if(*_head==NULL||(*_head)->ano >= new_node->ano)//caso a lista esteja vazia
	{												//ou seja necessario introduzi antes da head
		
		new_node->next=(*_head);
		(*_head)= new_node;
		return *_head;
	}
	else//caso contrario introduzi no sitio certo
	{
		while(aux->next!=NULL&&aux->next->ano < new_node->ano)
		{
			aux=aux->next;
		}
		new_node->next = aux->next;
		aux->next = new_node;

		return aux->next;
	}
}
void insertSortMes(node_t **_head, node_t *_new_node)
{
	node_t * aux = NULL;

	aux=(*_head);
	//caso a lista esteja vazia

//caso a lista esteja vazia ou seja necessario introduzi antes da head
	 if((*_head) == NULL||((*_head)->payload.dt.mes  >= _new_node->payload.dt.mes))
	{												
	
		_new_node->prev=NULL;
		_new_node->next = *_head;
		*_head = _new_node;
	}
	else//caso contrario insere no sitio certo
	{

		while(aux->next!= NULL && aux->next->payload.dt.mes < _new_node->payload.dt.mes )
		{
				aux=aux->next;
		
		}
	
		_new_node->next = aux->next;
		aux->next = _new_node;
		aux->next->prev = aux;
	}
}
