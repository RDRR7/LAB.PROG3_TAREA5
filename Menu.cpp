#include "Menu.h"

Menu::Menu(SDL_Renderer *renderer)
{
    TTF_Init();
    font=TTF_OpenFont("lazy.ttf",20);
    color={ 0, 0, 0, 255};

    this->renderer = renderer;

    ifstream in("menu/menu.txt");
    for(int x=0; x<arraySize; x++)
        in>>nombre_archivo[x];

    this->background = IMG_LoadTexture(renderer, nombre_archivo[0].c_str());
    int w,h;
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect.x = 0;
    rect.y = 0;
    rect.w = w;
    rect.h = h;
}

Menu::~Menu()
{
    //dtor
}

void Menu::draw()
{
    SDL_RenderCopy(renderer, background, NULL, &rect);

    for(int x=1; x<arraySize; x+=3)
    {
        SDL_Surface *textSurface=TTF_RenderText_Solid(font, nombre_archivo[x].c_str(), color);
        SDL_Texture *text=SDL_CreateTextureFromSurface(renderer, textSurface);
        int xRect;
        int yRect;
        sscanf(nombre_archivo[x+1].c_str(), "%d", &xRect);
        sscanf(nombre_archivo[x+2].c_str(), "%d", &yRect);
        SDL_Rect textRect;
        textRect.x=xRect;
        textRect.y=yRect;
        SDL_QueryTexture(text, NULL, NULL, &textRect.w, &textRect.h);
        SDL_RenderCopy(renderer, text, NULL, &textRect);
    }
}

void Menu::loop()
{
    SDL_Event Event;
    double last_frame_ticks=SDL_GetTicks();
    bool exit_loop=false;
    while(!exit_loop)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                exit(0);
            }
            if(Event.type == SDL_KEYDOWN)
            {
                exit_loop=true;
            }
        }

        draw();

        SDL_RenderPresent(renderer);
        double current_ticks = SDL_GetTicks();
        double ticks_diff = current_ticks-last_frame_ticks;
        double sleep_time = 17-ticks_diff;
        //cout<<ticks_diff<<","<<sleep_time<<endl;
        last_frame_ticks=SDL_GetTicks();
        if(sleep_time>0)
            SDL_Delay(sleep_time);

    }
}
