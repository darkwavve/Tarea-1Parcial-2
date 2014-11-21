#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <iostream>
#include <list>

using namespace std;

class Personaje
{
    public:
        SDL_Rect rectangulo;
        list<SDL_Texture*> texturas;
        list<SDL_Texture*>::iterator textura_actual;
        list<Personaje*>*personajes;
        int frame;
        Personaje();
        virtual void logic(Uint8* teclas_presionadas);
        virtual void render(SDL_Renderer* renderer);
        virtual ~Personaje();

        bool colision(SDL_Rect r1, SDL_Rect r2);

    protected:
    private:
};

#endif // PERSONAJE_H
