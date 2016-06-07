#ifndef MENU_H
#define MENU_H

#include <SDL.h>
#include <SDL_image.h>
#include <fstream>
#include <SDL_TTF.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Menu
{
    public:
        SDL_Texture *background;
        SDL_Rect rect;
        SDL_Renderer *renderer;
        Menu(SDL_Renderer *renderer);
        void draw();
        void loop();
        virtual ~Menu();
    protected:
    private:
        static const int arraySize=10;//Textos por 3 mas 1
        string nombre_archivo[arraySize];
        TTF_Font *font;
        SDL_Color color;
};

#endif // MENU_H
