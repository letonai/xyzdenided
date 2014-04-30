/*
 * Sprite.cpp
 *
 *  Created on: 29/04/2014
 *      Author: letonai
 */
#include "SDL/SDL_image.h"
#include <string>
#include <SDL/SDL.h>
#include "Sprite.h"


	float tam = NULL;
    float offsetx = NULL ;
    float offsety = NULL ;

Sprite::Sprite(){

}



Sprite::~Sprite() {
	// TODO Auto-generated destructor stub
}

//Carrega Imagem e trata o fundo para deixa-lo transparente
SDL_Surface *Sprite::carregaImagem(char *caminho,int r, int g, int b){
    SDL_Surface *imgTmp = NULL;
    SDL_Surface *imgOtim = NULL;

    imgTmp = IMG_Load(caminho);

    if(imgTmp!=NULL){
        imgOtim = SDL_DisplayFormat(imgTmp);
        SDL_FreeSurface(imgTmp);
        if(imgOtim!=NULL && r!=NULL){
            Uint32 corChave = SDL_MapRGB( (*imgOtim).format,r,g,b);
            SDL_SetColorKey(imgOtim,SDL_SRCCOLORKEY,corChave);
        }

    }
    return imgOtim;
}

