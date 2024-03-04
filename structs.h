/*structs.h*/
/*Daniel Chagas 90043*/
/*Mariana Santos 90137*/
#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#define MAX_LINE_LEN 100
typedef struct{
	int dia;
	int mes;
	int ano;
}data;
/*Estrutura auxiliar para as coordenadas geograficas*/
typedef struct{
	float angle;
	int hemisferio;
}geo_coord;
/*Estrutura de dados utilizada*/
typedef struct{
	data dt;
	float temperatura;
	float incerteza;
	char pais[100];
	char cidade[100];
	geo_coord lat;
	geo_coord longit;
}dados_temp;

typedef struct node{
	dados_temp payload;
	struct node *next;
	struct node *prev;
}node_t;

/*Lista de listas */ 
typedef struct list_l{
	char cidade[MAX_LINE_LEN];
	int ano;
	struct list_l *next;
	node_t *cabeca;
}node_l;
/*Estrutura utilizada para a opção 3 do menu principal */ 
typedef struct analise{
	char nome[MAX_LINE_LEN];
	float temperatura;
	float max;
	float min;
	float soma;
	int count;
	float Amplitude;
}stats;

#endif // STRUCTS_H_INCLUDED
