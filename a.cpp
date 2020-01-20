#include<stdio.h>
#include<SDL2/SDL.h>

const int width = 800;
const int height = 600;

int main (int argc,char* args[])
{
    SDL_Window*  window = NULL;
    SDL_Surface* screenSurface = NULL;


   if( SDL_Init(SDL_INIT_VIDEO)==-1)
    {
        printf("sdl error :%s ",SDL_GetError());
    }
    else
    {
        window = SDL_CreateWindow("sdl test",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_SHOWN);
    
    if (window == NULL)
    {
        printf("window couldn't be created! sdl_error :%s\n",SDL_GetError());
    }
    else
       screenSurface =SDL_GetWindowSurface(window );
        SDL_FillRect(screenSurface,NULL,SDL_MapRGB(screenSurface->format,0xFF,0xFF,0xFF));
    SDL_UpdateWindowSurface(window);
    SDL_Delay(4000);

    }
    SDL_DestroyWindow( window);

    SDL_Quit();
    
    return 0;
}
    

