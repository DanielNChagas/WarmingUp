/*grafica.h*/
/*Ficheiro  header onde se encontram declaradas todas 
as funções  relativas ao modo grafico*/
/*Daniel Chagas 90043*/
/*Mariana Santos 90137*/
#ifndef GRAFICA_H_INCLUDED
#define GRAFICA_H_INCLUDED
#include "structs.h"

#define M_PI 3.14159265
#define MAP_W 1000            // largura do mapa
#define MAP_H 500             //altura do mapa
#define MAP_CENTER_X 500      //centro do mapa
#define MAP_CENTER_Y 250      //centro do mapa
#define LEFT_BAR_SIZE 150     // left white bar size
#define WINDOW_POSX 200       // initial position of the window: x
#define WINDOW_POSY 200       // initial position of the window: y
#define MARGIN 5
#define CIRCLER 5
#define MAX_LINE_LEN 100

void InitEverything(int , int , TTF_Font **, SDL_Surface **, SDL_Window ** , SDL_Renderer ** );
void InitSDL();
void InitFont();
SDL_Window* CreateWindow(int , int );
SDL_Renderer* CreateRenderer(int , int , SDL_Window *);
int RenderText(int, int, const char *, TTF_Font *, SDL_Color *, SDL_Renderer *);//renderiza texto
int RenderLogo(int, int, SDL_Surface *, SDL_Renderer *);//renderiza o logo do IST
void filledCircleRGBA(SDL_Renderer * , int , int , int , int,int,int );//renderiza circulo cheio
void RenderMap( TTF_Font *_font, SDL_Surface *_img[], SDL_Renderer* _renderer);//renderiza o mapa
void RenderCircles(SDL_Renderer *,node_l*, float);//renderiza circulo
float convert_H(float);//conversão de coordenadas
float convert_W(float);//conversão de coordenadas
void RenderLable(SDL_Renderer *,TTF_Font *_font);//renderiza a legenda
int getano_inicial(node_l*);//obtem o ano inicial
void RenderAnos(SDL_Renderer *,TTF_Font *_font, int);//renderiza os anos
float calculomedia(node_t *head,int ano);//calcula a media de temperaturas por ano

#endif // GRAFICA_H_INCLUDED
