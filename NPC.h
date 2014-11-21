#ifndef NPC_H
#define NPC_H

#include "Personaje.h"

class Personaje;

class NPC : public Personaje
{
    public:
        NPC(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes);
        virtual ~NPC();
        void logic(Uint8* teclas_presionadas);
    protected:
    private:
};

#endif // NPC_H
