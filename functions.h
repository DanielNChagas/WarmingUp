/*Functions.h*/
/*Ficheiro  header onde se encontram declaradas todas 
as funções relativas ao modo textual */
/*Daniel Chagas 90043*/
/*Mariana Santos 90137*/
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "structs.h"


node_t *GetNewNode();//função para obter um no com memoria alocada
node_l *GetNewNode_l();//função para obter um no com memoria alocada
void print_list(node_t *);//função para teste de listas
void print_list_l(node_l *);//função para teste de listas
void removeHead_L(node_l **);//função que remove a cabeça de uma lista de listas
void removeHead(node_t **);//função que remove a cabeça de uma lista
void removeNode (node_t *);//função que um node em qualquer ponto da lista
void insertTail(node_t **, node_t **, node_t *);//função que insere um no na cauda
void insertSortMes(node_t **, node_t *);//função que insere  um no no sitio certo tendo em conta a ordenação
node_l *insertSortAno(node_l **,node_l *);//função que insere  um no no sitio certo tendo em conta a ordenação
node_t *criaLista(node_l *);//função que transforma uma lista de lista em uma lista

int verificaParametros(int , char ** , int *, int *);//função que verifica os parametros de entrada do programa
void ler_cidades(int , char **, node_l **);//função que le as cidades de um ficheiro e guarda numa lista de listas
void ler_pais(int , char **,node_l **);//função que le os paises de um ficheiro e guarda numa lista de listas
int GetT(int );//função que obtem o intrevalo de tempo
void GetCity(node_l *, char *);//função que obtem a cidade introduzida pelo utilizador
void GetCountry(node_t *,char *);//função que obtem o pais introduzido pelo utilizador
int getAnos(node_t *);//função que retorna o numero de anos de uma lista
float** movingAverage(float** , int );// função que faz moving average e retorna uma matriz

/*Funções relativas aos menus*/
void HistoricoGlobal(node_t *);//função que faz o historico global
void HistoricoPais (node_t *);//função que faz o historico de paises
void HistoricoCidade(node_l *);//função que faz o historico de cidades
void filtragemGlobalCidades (node_l **, int *, int *);
void filtragemGlobal(node_t **, int, int);
void filtragemMesCidades(node_l **, int, int);
void filtragemMes(node_t **, int *, int *);
void undoFiltragem(int , int , char **, node_l **, node_l **, node_t **);//limpa criterios (não funciona)
void bubleSort_temperatura(stats **, int);//função que ordena temperaturas
void bubleSort_amplitude(stats **, int);//função que ordena amplitudes
void AnaliseAnoPais(node_t *);
void AnaliseAnoCidade(node_l *);
void analiseGlobal(node_t *);// com MA
void analiseCidades(node_l *);
void analisePaises(node_t *);


/*Funções relativas ao print dos menus*/
int printMenu0(int );
void printMenu1( node_l **, node_l **, node_t **,int , char **, int );
void printMenu2( node_t *, node_l *);
void printMenu3( node_t *, node_l *);
void printMenu4( node_t *, node_l *);



#endif // FUNCTIONS_H_INCLUDED
