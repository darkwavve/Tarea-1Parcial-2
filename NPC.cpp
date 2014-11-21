#include "NPC.h"

NPC::NPC(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes)
{
    this->rectangulo.x = x;
    this->rectangulo.y = y;
    this->personajes=personajes;
    SDL_Texture *textura = IMG_LoadTexture(renderer, "assets/npcs/npc1/down1.png");
    SDL_QueryTexture(textura, NULL, NULL, &this->rectangulo.w, &this->rectangulo.h);

    texturas.push_back(textura);
    texturas.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc1/down2.png"));

    textura_actual=texturas.begin();
}

NPC::~NPC()
{
    //dtor
}

void NPC::logic(Uint8* teclas_presionadas)
{
    SDL_Rect temp = this->rectangulo;

    rectangulo.x++;
    if(rectangulo.x>500)
        rectangulo.x=0;

    for(list<Personaje*>::iterator i = personajes->begin();
            i!=personajes->end();
            i++)
    {
        if(this==(*i))
            continue;
        if(colision(this->rectangulo, (*i)->rectangulo))
            rectangulo=temp;
    }
}
