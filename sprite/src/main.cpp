#include "SDL/SDL_image.h"
#include <string>
#include <SDL/SDL.h>
#include "Sprite.h"


int TELA_H=640;
int TELA_V=480;
int COR=32;
bool QUIT = false;
SDL_Surface *screen = NULL;
SDL_Event event;

//Funcaopar a inicializar o video, recebe, titudo da janela,tamanho horizontal, tamanho vertical e profundidasde de cor
bool ini(char *title,int horizontal, int vertical, int profundidade_cor){
    if( SDL_Init(SDL_SWSURFACE) == -1){
        return (false);
    }
    screen = SDL_SetVideoMode(horizontal,vertical,profundidade_cor,SDL_SWSURFACE);
    if(screen == NULL){
        return (false);
    }
    SDL_WM_SetCaption(title,NULL);

    return (true);

}


//Funcao para tratamento de eventos(Teclado,janela ou mouse)
void eventos(SDL_Event event){

    while(SDL_PollEvent(&event) ){
        if( event.type == SDL_QUIT ){
            QUIT = true;
        }

    }

}



void aplicaImg( int x, int y, SDL_Rect clip,SDL_Surface* img, SDL_Surface* tela )
{
    //Temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Get the offsets
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( img, &clip, tela, &offset );

}



int main ( int argc, char** argv )
{

	Sprite spr ;


    if(!ini("Teste",TELA_H,TELA_V,COR)){
        return -1;
    };
    //SDL_Surface *img = carregaImagemBMP("sprites/galinha.bmp",164,117,160);
    SDL_Surface *img  = spr.carregaImagem("sprites/galinha.bmp",164,117,160);
    SDL_Surface *img2  = spr.carregaImagem("sprites/male2.png",255,255,255);


        SDL_Rect r[3*7];
        float tam=(*img).w/7.0;
        int q=2;
        int pos=0;
        float offsetx = 3;
        float offsety = 0;
        for(int linhas=0;linhas<3;linhas++){
            for(int col=0;col<7;col++){
                r[pos].y=(tam*linhas)+linhas/(tam-(int)tam)-offsety;
                r[pos].x=(tam*col)+col/(tam-(int)tam)-offsetx;
                r[pos].w=tam;
                r[pos].h=tam;
                pos++;
            }
        }

    while(!QUIT){
        eventos(event);

        //Preenche a tela com a cor branca
        SDL_FillRect(screen,NULL,0x00FFFF00);
        aplicaImg(50,50,r[q++],img,screen);
        SDL_Flip(screen);
        SDL_Delay(80);
        if(q>5){
            q=2;
        }
    }

    SDL_FreeSurface(img);
    SDL_Quit();

}
