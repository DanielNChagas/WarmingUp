/*grafica.c*/
/*Daniel Chagas 90043*/
/*Mariana Santos 90137*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "grafica.h"
#include "structs.h"



void RenderAnos(SDL_Renderer *renderer,TTF_Font *font, int ano)
{
	char anos[MAX_LINE_LEN]={0};
	SDL_Color black = {0,0,0};//cor preta

	sprintf(anos, "%d", ano);//converte um inteiro numa string
	RenderText(MARGIN, MARGIN, anos, font, &black, renderer);//renderiza os anos
}

void RenderLable(SDL_Renderer *renderer,TTF_Font *font)
{
	int height=MAP_H-30;//inicialização de uma altura
	int height2= MAP_H-80;//inicialização de uma altura
	int radius=25;//inicialização de um raio

	int w=MAP_W/13;//inicialização de uma largura
	int w2=MAP_W/16;//inicialização de uma largura

	SDL_Color black = { 0, 0, 0 }; // black
	//geração dos circulos que fazem parte da legenda
	filledCircleRGBA(renderer,w,height, radius, 0,0,255);
	filledCircleRGBA(renderer,2*w,height, radius, 30,0,235);
	filledCircleRGBA(renderer,3*w,height, radius, 60,0,215);
	filledCircleRGBA(renderer,4*w,height, radius, 90,0,195);
	filledCircleRGBA(renderer,5*w,height, radius, 110,0,175);
	filledCircleRGBA(renderer,6*w,height, radius, 130,0,155);
	filledCircleRGBA(renderer,7*w,height, radius, 155,0,135);
	filledCircleRGBA(renderer,8*w,height, radius, 175,0,115);
	filledCircleRGBA(renderer,9*w,height, radius, 195,0,90);
	filledCircleRGBA(renderer,10*w,height, radius, 215,0,60);
	filledCircleRGBA(renderer,11*w,height, radius, 235,0,30);
	filledCircleRGBA(renderer,12*w,height, radius, 255,0,0);
	filledCircleRGBA(renderer,13*w,height, radius, 0,0,0);
	
	//renderiza os textos da legenda
	RenderText(w2, height2, "<-20", font, &black, renderer);
	RenderText(2*w2, height2, "-20/-14,5", font, &black, renderer);
	RenderText(2*w2+w, height2, "-14,5/-9", font, &black, renderer);
	RenderText(2*w2+2*w, height2, "-9/-3,5", font, &black, renderer);
	RenderText(2*w2+3*w, height2, "-3,5/2", font, &black, renderer);
	RenderText(2*w2+4*w, height2, "2/7,5", font, &black, renderer);
	RenderText(2*w2+5*w, height2, "7,5/13", font, &black, renderer);
	RenderText(2*w2+6*w, height2, "13/18.5", font, &black, renderer);
	RenderText(2*w2+7*w, height2, "18.5/24", font, &black, renderer);
	RenderText(2*w2+8*w, height2, "24/29,5", font, &black, renderer);
	RenderText(2*w2+9*w, height2, "29,5/35", font, &black, renderer);
	RenderText(2*w2+10*w+15, height2, ">35", font, &black, renderer);
	RenderText(2*w2+11*w, height2, "No info", font, &black, renderer);

}

void RenderCircles(SDL_Renderer *renderer, node_l *head, float temperatura)
{
	float x=0;
	float y=0;



		x=convert_W(head->cabeca->payload.longit.angle);
		y=convert_H(head->cabeca->payload.lat.angle);
		if(head->cabeca->payload.longit.hemisferio==3)//caso a longitude seja W
			x=MAP_CENTER_X-x;//é subtraido o angulo convertido em pixeis à coordenada X
		if(head->cabeca->payload.longit.hemisferio==4)//caso a longitude seja E
			x=MAP_CENTER_X+x;//é adicionado o angulo convertido em pixeis à coordenada X
		if (head->cabeca->payload.lat.hemisferio==1)//caso a latirute seja N
			y=MAP_CENTER_Y-y;//é subtraido o angulo convertido em pixeis à coordenada Y
		if (head->cabeca->payload.lat.hemisferio==2)//caso a latirute seja S
			y=MAP_CENTER_Y+y;//é sadicionado o angulo convertido em pixeis à coordenada Y
		if(temperatura==100.0f)
			filledCircleRGBA(renderer,x,y, CIRCLER, 0,0,0);
		//gera circulos de  cores diferentes consoante a temperatura
		else
		{
			if(temperatura <-20)
				filledCircleRGBA(renderer,x,y, CIRCLER, 0,0,255);
			else if(temperatura >-20 &&temperatura<=-14.5)
				filledCircleRGBA(renderer,x,y, CIRCLER, 30,0,235);
			else if(temperatura >-14.5 &&temperatura <=-9)
				filledCircleRGBA(renderer,x,y, CIRCLER, 60,0,215);
			else if(temperatura >-9 &&temperatura <=-3.5)
				filledCircleRGBA(renderer,x,y, CIRCLER, 90,0,195);
			else if(temperatura >-3.5 &&temperatura <=2)
				filledCircleRGBA(renderer,x,y, CIRCLER, 110,0,175);
			else if(temperatura >2 &&temperatura <=7.5)
				filledCircleRGBA(renderer,x,y, CIRCLER, 130,0,155);
			else if(temperatura >7.5 &&temperatura <=13)
				filledCircleRGBA(renderer,x,y, CIRCLER, 155,0,135);
			else if(temperatura >13&&temperatura <=18.5)
				filledCircleRGBA(renderer,x,y, CIRCLER, 175,0,115);
			else if(temperatura >18.5&&temperatura <=24)
				filledCircleRGBA(renderer,x,y, CIRCLER, 195,0,90);
			else if(temperatura >24&&temperatura<=29.5)
				filledCircleRGBA(renderer,x,y, CIRCLER, 215,0,60);
			else if(temperatura >29.5 &&temperatura <=35)
				filledCircleRGBA(renderer,x,y, CIRCLER, 235,0,30);
			else if(temperatura >35)
				filledCircleRGBA(renderer,x,y, CIRCLER, 00,0,255);
		}



}

/**
 * RenderLogo function: Renders the IST logo on the app window
 * \param x X coordinate of the Logo
 * \param y Y coordinate of the Logo
 * \param _logoIST surface with the IST logo image to render
 * \param _renderer renderer to handle all rendering in a window
 */
int RenderLogo(int x, int y, SDL_Surface *_logoIST, SDL_Renderer* _renderer)
{
    SDL_Texture *text_IST;
    SDL_Rect boardPos;

    // space occupied by the logo
    boardPos.x = x;
    boardPos.y = y;
    boardPos.w = _logoIST->w;
    boardPos.h = _logoIST->h;

    // render it
    text_IST = SDL_CreateTextureFromSurface(_renderer, _logoIST);
    SDL_RenderCopy(_renderer, text_IST, NULL, &boardPos);

    // destroy associated texture !
    SDL_DestroyTexture(text_IST);
    return _logoIST->h;
}


/**
 * RenderText function: Renders some text on a position inside the app window
 * \param x X coordinate of the text
 * \param y Y coordinate of the text
 * \param text string with the text to be written
 * \param _font TTF font used to render the text
 * \param _color color of the text
 * \param _renderer renderer to handle all rendering in a window
 */
int RenderText(int x, int y, const char *text, TTF_Font *_font, SDL_Color *_color, SDL_Renderer* _renderer)
{
    SDL_Surface *text_surface;
    SDL_Texture *text_texture;
    SDL_Rect solidRect;

    solidRect.x = x;
    solidRect.y = y;
    // create a surface from the string text with a predefined font
    text_surface = TTF_RenderText_Blended(_font,text,*_color);
    if(!text_surface)
    {
        printf("TTF_RenderText_Blended: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
    // create texture
    text_texture = SDL_CreateTextureFromSurface(_renderer, text_surface);
    // obtain size
    SDL_QueryTexture( text_texture, NULL, NULL, &solidRect.w, &solidRect.h );
    // render it !
    SDL_RenderCopy(_renderer, text_texture, NULL, &solidRect);
    // clear memory
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(text_surface);
    return solidRect.h;
}
/**
 * filledCircleRGBA: renders a filled circle
 * \param _circleX x pos
 * \param _circleY y pos
 * \param _circleR radius
 * \param _r red
 * \param _g gree
 * \param _b blue
 */
void filledCircleRGBA(SDL_Renderer * _renderer, int _circleX, int _circleY, int _circleR, int _r, int _g, int _b)
{
    int off_x = 0;
    int off_y = 0;
    float degree = 0.0;
    float step = M_PI / (_circleR*8);

    SDL_SetRenderDrawColor(_renderer, _r, _g, _b, 255);

    while (_circleR > 0)
    {
        for (degree = 0.0; degree < M_PI/2; degree+=step)
        {
            off_x = (int)(_circleR * cos(degree));
            off_y = (int)(_circleR * sin(degree));
            SDL_RenderDrawPoint(_renderer, _circleX+off_x, _circleY+off_y);
            SDL_RenderDrawPoint(_renderer, _circleX-off_y, _circleY+off_x);
            SDL_RenderDrawPoint(_renderer, _circleX-off_x, _circleY-off_y);
            SDL_RenderDrawPoint(_renderer, _circleX+off_y, _circleY-off_x);
        }
        _circleR--;
    }
}
void RenderMap( TTF_Font *_font, SDL_Surface *_img[], SDL_Renderer* _renderer)
{
	const char myName2[] = "Mariana Santos";
	const char myNumber2[] = "IST190137";
	const char myName1[] = "Daniel Chagas";
	const char myNumber1[] = "IST190043";
	SDL_Color black = { 0, 0, 0 }; // black
  //SDL_Color light = { 205, 193, 181 };
  // SDL_Color dark = { 120, 110, 102 };
  SDL_Texture *table_texture;
  SDL_Rect tableSrc, tableDest;
  int height;

  // set color of renderer to some color
  SDL_SetRenderDrawColor( _renderer, 255, 255, 255 , 255 );

  // clear the window
  SDL_RenderClear( _renderer );

  tableDest.x = tableSrc.x = 0;
  tableDest.y = tableSrc.y = 0;
  tableSrc.w = _img[0]->w;
  tableSrc.h = _img[0]->h;
  tableDest.w = MAP_W;
  tableDest.h = MAP_H;


  // draws the table texture
  table_texture = SDL_CreateTextureFromSurface(_renderer, _img[0]);
  SDL_RenderCopy(_renderer, table_texture, &tableSrc, &tableDest);

  // render the IST Logo
  height = RenderLogo(MAP_W, 0, _img[1], _renderer);

  // render the student name
  height += RenderText(MAP_W+3*MARGIN, height, myName1, _font, &black, _renderer);
  // this renders the student number
  height +=RenderText(MAP_W+3*MARGIN, height, myNumber1, _font, &black, _renderer);
  // render the student name
  height += RenderText(MAP_W+3*MARGIN, height, myName2, _font, &black, _renderer);
  // this renders the student number
  height +=RenderText(MAP_W+3*MARGIN, height, myNumber2, _font, &black, _renderer);
  // compute and adjust the size of the table and squares



}
/**
 * InitEverything: Initializes the SDL2 library and all graphical components: font, window, renderer
 * \param width width in px of the window
 * \param height height in px of the window
 * \param _font font that will be used to render the text
 * \param _img surface to be created with the table background and IST logo
 * \param _window represents the window of the application
 * \param _renderer renderer to handle all rendering in a window
 */
void InitEverything(int width, int height, TTF_Font **_font, SDL_Surface *_img[], SDL_Window** _window, SDL_Renderer** _renderer)
{
    InitSDL();
    InitFont();
    *_window = CreateWindow(width, height);
    *_renderer = CreateRenderer(width, height, *_window);

    // load the table texture
    _img[0] = IMG_Load("map.png");
    if (_img[0] == NULL)
    {
        printf("Unable to load image: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // load IST logo
    _img[1] = SDL_LoadBMP("ist_logo.bmp");
    if (_img[1] == NULL)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }


    // this opens (loads) a font file and sets a size
    *_font = TTF_OpenFont("FreeSerif.ttf", 16);
    if(!*_font)
    {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
}
void InitSDL()
{
    // init SDL library
    if ( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        printf(" Failed to initialize SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

/**
 * InitFont: Initializes the SDL2_ttf font library
 */
void InitFont()
{
    // Init font library
    if(TTF_Init()==-1)
    {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
}

/**
 * CreateWindow: Creates a window for the application
 * \param width width in px of the window
 * \param height height in px of the window
 * \return pointer to the window created
 */
SDL_Window* CreateWindow(int width, int height)
{
    SDL_Window *window;
    // init window
    window = SDL_CreateWindow( "WarmingUp", WINDOW_POSX, WINDOW_POSY, width, height, 0 );
    // check for error !
    if ( window == NULL )
    {
        printf("Failed to create window : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    return window;
}

/**
 * CreateRenderer: Creates a renderer for the application
 * \param width width in px of the window
 * \param height height in px of the window
 * \param _window represents the window for which the renderer is associated
 * \return pointer to the renderer created
 */
SDL_Renderer* CreateRenderer(int width, int height, SDL_Window *_window)
{
    SDL_Renderer *renderer;
    // init renderer
    renderer = SDL_CreateRenderer( _window, -1, 0 );

    if ( renderer == NULL )
    {
        printf("Failed to create renderer : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // set size of renderer to the same as window
    SDL_RenderSetLogicalSize( renderer, width, height );

    return renderer;
}

float convert_H(float angle)
{
  float max=90.0f;//angulo maximo
  float converted=0.0f;

  converted=(angle*MAP_CENTER_Y)/max;//regra de 3 simples

  return converted;
}
float convert_W(float angle)
{
  double max=180.0f;//angulo maximo
  float converted=0.0f;

  converted=(angle*MAP_CENTER_X)/max;//regra de 3 simples

  return converted;//retorna o angulo convertido
}

int getano_inicial(node_l *head)
{
	int ano_inicial=0;//inicialização de uma variavel que guarda o ano inicial
	node_l *aux=NULL;//inicialização de um nó  auxiliar

	aux=head;//no auxiliar aponta para a cabeca
	ano_inicial=aux->cabeca->payload.dt.ano;//ano inicial igual ao ano guardado na cabeca da lista
	while(aux!=NULL)//ciclo que percorre a lista
	{
		if(ano_inicial>aux->cabeca->payload.dt.ano)//caso o ano guardado na cabeça seja menos que o ano inicial
			ano_inicial=aux->cabeca->payload.dt.ano;////é guardado esse ano como ano inicial
		aux=aux->next;//proximo
	}
	return ano_inicial;//é retornado o ano inicial


}
float calculomedia(node_t *head,int ano)
{
	node_t *aux=NULL;
	float media=0.0f;
	float soma=0.0f;
	int i=0;
	aux=head;
	if(head->payload.dt.ano>ano)
	{
		media=100.0f;//valor da média correspondente a não haver informação
		return media;//retorna o valor da media
	}
	while(aux->payload.dt.ano!=ano && aux->next!=NULL)//percorre a lista até encontrar valores correspondentes ao ano a analisar ou ate ao fim da lista
	{
		aux=aux->next;
	}
	if(aux->next==NULL || aux->payload.dt.ano!=ano)//caso chegue ao fim da lista sem encontrar informação dobre o ano
	{
		media=100.0f;//valor da média correspondente a não haver informação
		return media;//retorna o valor da média
	}
	else//casno o ultimo valor da lista pertença ao ano
	{
		media = aux->payload.temperatura;
		return media;
	}
	while(aux->payload.dt.ano==ano && aux->next!=NULL)//encontre percorre a lista enquanto houver informaçao sobre esse ano
	{
		soma=aux->payload.temperatura+soma;
		i++;
		aux=aux->next;
	}
	// if (aux->next==NULL)
	// {
	// 	soma=aux->payload.temperatura+soma;
	// 	i++;
	// }
	media=soma/i;//calculo da média

	return media;
}
