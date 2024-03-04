/*menu.c*/
/*Daniel Chagas 90043*/
/*Mariana Santos 90137*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

int printMenu0(int menu_choice0)
{
    char option[MAX_LINE_LEN];
    char a;

    printf("-------------------------Menu0------------------------\n");
    printf("--Prima a tecla correspondente à opção que pretende --\n");
    printf("----------1. Filtragem de dados;----------------------\n");
    printf("----------2. Histórico de temperaturas;---------------\n");
    printf("----------3. Análise da temperatura por ano;----------\n");
    printf("----------4. Análise da temperatura global;-----------\n");
    printf("----------5. Sair;------------------------------------\n");
    printf("######################################################\n");

    fgets(option, MAX_LINE_LEN, stdin);
    sscanf(option, "%d%c", &menu_choice0, &a);
    return menu_choice0;



}
void printMenu1( node_l **head_p, node_l **head_c, node_t **head,int f2, char *_argv[], int f1)
{
    int menu_choice1=0;
    char option[MAX_LINE_LEN];
    char a;
    int year=0;
    int month=0;
    int month1=0;
    int month2=0;


    printf("-------------------------Menu1------------------------\n");
    printf("-------------------Filtragem de Dados-----------------\n");
    printf("--Prima a tecla correspondente à opção que pretende --\n");
    printf("----------1. Limpa critérios;-------------------------\n");
    printf("----------2. Escolhe intervalo para análise;----------\n");
    printf("----------3. Escolhe mês para análise-----------------\n");
    printf("----------4. Voltar ao menu principal-----------------\n");
    printf("######################################################\n");

    fgets(option, MAX_LINE_LEN, stdin);
    sscanf(option, "%d%c", &menu_choice1, &a);

    switch(menu_choice1){
      ///limpa criterios
      case 1:
         ///limpar as listas
		///dar reupload dos ficheiros para as listas novamente
        undoFiltragem(f1,f2 , _argv, &(*head_p), &(*head_c), &(*head));

      break;
            ///escolhe o intervalo
      case 2:
      {
		    filtragemGlobalCidades (&(*head_c), &year, &month);

        filtragemGlobal(&(*head), year, month);


        break;
      }
    case 3 :
    {
    ///utilizador escolhe o mes inicial e final tudo o que nao estiver entre eles deve ser eliminado
        filtragemMes(&(*head), &month1, &month2);
        filtragemMesCidades(&(*head_c), month1, month2);

    break;
    }
    case 4:
        return;
    break;
    default:
    printf("--------------Erro : Opção Inválida-------------------\n");
    break;

    }

}
void printMenu2( node_t *head, node_l *head_c)
{

    int menu_choice2=0;
    char option[MAX_LINE_LEN];
    char a;

    printf("-------------------------Menu2------------------------\n");
    printf("---------------Histórico de temperaturas--------------\n");
    printf("--Prima a tecla correspondente à opção que pretende --\n");
    printf("----------1. Global: aplica-se a todos os países;-----\n");
    printf("----------2. Por país: aplica-se a um único país;-----\n");
    printf("----------3. Por cidade: aplica-se a uma única cidade;\n");
    printf("----------4.Voltar ao Menu Principal;-----------------\n");
    printf("######################################################\n");

    fgets(option, MAX_LINE_LEN, stdin);
    sscanf(option, "%d%c", &menu_choice2, &a);

    switch(menu_choice2){
        case 1:
            HistoricoGlobal(head);
        break;
        case 2:
            HistoricoPais(head);
        break;
        case 3:

            HistoricoCidade(head_c);
        break;
        case 4:
            return;
        break;

        default:
            printf("--------------Erro : Opção Inválida-------------------\n");
        break;

    }

}
void printMenu3( node_t *head, node_l *head_c)
{
    char option[MAX_LINE_LEN];
    char a;
    int menu_choice3=0;

    printf("-------------------------Menu3------------------------\n");
    printf("-----------Análise da temperatura por ano-------------\n");
    printf("--Prima a tecla correspondente à opção que pretende --\n");
    printf("----------1. Análise por país;------------------------\n");
    printf("----------2. Analise por cidade;----------------------\n");
    printf("----------3.Voltar ao Menu Principal;-----------------\n");
    printf("######################################################\n");


    fgets(option, MAX_LINE_LEN, stdin);
    sscanf(option, "%d%c", &menu_choice3, &a);

    switch(menu_choice3){
        case 1:

            AnaliseAnoPais(head);

        break;
        case 2:

            AnaliseAnoCidade(head_c);
        break;
        case 3:
            return;
        break;

        default:
            printf("--------------Erro : Opção Inválida-------------------\n");
        break;
    }

}
void printMenu4(node_t *head_p, node_l *head_c)
{
    int menu_choice4=0;
    char option[MAX_LINE_LEN];
    char a;

    printf("-------------------------Menu4------------------------\n");
    printf("-------------Análise da Temperatura Global------------\n");
    printf("--Prima a tecla correspondente à opção que pretende --\n");
    printf("----------1. Global;----------------------------------\n");
    printf("----------2. Por país;--------------------------------\n");
    printf("----------3. Por cidade;------------------------------\n");
    printf("----------4.Voltar ao Menu Principal;-----------------\n");
    printf("######################################################\n");

    fgets(option, MAX_LINE_LEN, stdin);
    sscanf(option, "%d%c", &menu_choice4, &a);

    switch(menu_choice4){
        case 1:
            analiseGlobal(head_p);
        break;
        case 2:
            analisePaises(head_p);
        break;
        case 3:

            analiseCidades(head_c);
        break;
        case 4:
            return;
        break;

        default:
            printf("--------------Erro : Opção Inválida-------------------\n");
        break;

    }
}
