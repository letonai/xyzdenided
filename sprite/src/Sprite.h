/*
 * Sprite.h
 *
 *  Created on: 29/04/2014
 *      Author: letonai
 */

#ifndef SPRITE_H_
#define SPRITE_H_

class Sprite {
public:
	Sprite();
	Sprite(char *caminho,int r, int g, int b);
	virtual ~Sprite();
	SDL_Surface *carregaImagem(char *caminho,int r, int g, int b);


private:
	SDL_Surface *img;
	float tam;
    float offsetx ;
    float offsety ;
    SDL_Surface *imgTmp;


};

#endif /* SPRITE_H_ */
