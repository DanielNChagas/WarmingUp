/*main.c*/
/*Daniel Chagas 90043*/
/*Mariana Santos 90137*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "grafica.h"

int main (int argc, char *argv[])
{
    int f1=0, f2=0, flag_parametros=0, menu_choice0=0;//inicialização de variaveis referentes à obtenção dos parametros
    node_t *head_countries=NULL;//cabeça da lista dos paises
    node_l *head= NULL;//cabeça da lista de listas das cidade
    node_l *head_cities=NULL;//cabeça da lista de listas das cidades
    node_l *aux=NULL;//nó auxiliar
   


	//inicialização de variaveis referentes 
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    TTF_Font *serif = NULL;
    SDL_Surface *imgs[2];
    SDL_Event event;
    int delay = 200;
    int quit = 0;
    int width = (MAP_W+ LEFT_BAR_SIZE);
    int height = MAP_H;
    int ano=0;
    int ano_inicial=0;
    float media=0.0f;

	flag_parametros= verificaParametros(argc, argv, &f1, &f2);//obtenção dos parametros iniciais

    /*Realiza o programa no modo textual*/ 
    if(flag_parametros==2)//caso seja escolhido o analise 
    {
        ler_pais(f1, argv, &head);//função que le e guarda os paises numa lista de listas
        head_countries = criaLista(head);//função que transforma uma lista de listas numa só lista
        //print_list(head_countries);

        ler_cidades(f2,argv, &head_cities);//função que le as cidades e guarda numa lista de listas
        
        printf("******MODO TEXTUAL******\n");//ciclo que imprime os vários menus 
        do{

            menu_choice0=printMenu0(menu_choice0);
            printf("\n");

            switch(menu_choice0){
            //filtragem de dados
            case 1:
                printMenu1( &head, &head_cities,&head_countries, f2, argv, f1);
                printf("\n");

            break;
            //Historico Temperaturas
            case 2:
                printMenu2( head_countries, head_cities);
                printf("\n");

            break;
            //Analise da temperatura por ano
            case 3 :
                printMenu3(head_countries, head_cities);
                printf("\n");
            break;
            //Analise da temperatura global (MA)
            case 4 :
                printMenu4(head_countries, head_cities);
                printf("\n");
            break;
            case 5:
            exit(0);
            break;

            default:
            printf("--------------Erro : Opção Inválida-------------------\n");

            break;

            }

        }while(menu_choice0!=5);

        return 0;
    }
    /*Realiza o programa no modo grafico*/
    if(flag_parametros==3)//caso seja escolhida a parte gráfica
    {
        printf("******MODO GRÁFICO******\n");
        ler_cidades(f2,argv,&head_cities);//leitura da lista de cidades

        ano_inicial=getano_inicial(head_cities);//calculo do ano inicial
        ano=ano_inicial;//anos a renderizar é igual ao ano inicial


        InitEverything(width, height, &serif, imgs, &window, &renderer);

        while( quit == 0)//enquanto o utilizador não sair do programa
        {
            // while there's events to handle
            while( SDL_PollEvent( &event ) )
            {
                if( event.type == SDL_QUIT )
                {
                    quit = 1;
                }
                else if ( event.type == SDL_KEYDOWN )
                {
                    if( SDLK_q)
                    {
                        quit = 1;break;
                    }
                }
            }
            RenderMap( serif, imgs, renderer);//função que renderiza o mapa
            aux=head_cities;//aux apponta para a cabeça da lista de cidades
            while(aux!=NULL)//ciclo que precorre a lista de listas
            {
                media=calculomedia(aux->cabeca, ano);//função que calcula a media de temperaturas de cada ano
                RenderCircles(renderer, aux, media);//função que renderiza os circulos
                RenderAnos(renderer, serif, ano);//função que renderiza o ano a analisar
                aux=aux->next;//percorrer da lista
            }



            RenderLable(renderer,serif);//função que faz render da legenda

            ano++;//incremento do ano a renderizar

            if( ano==2014)//caso chegue ao final da lista
                ano=ano_inicial;//ano a renderizar volta a ser o ano inicial
            SDL_RenderPresent(renderer);
            SDL_Delay(delay);
        }


        TTF_CloseFont(serif);
        SDL_FreeSurface(imgs[0]);
        SDL_FreeSurface(imgs[1]);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();

        return 0;
    
    }
    else return 0;
}






