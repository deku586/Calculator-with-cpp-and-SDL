#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>



bool init();
bool loadMedia();
void close();

constexpr int ScreenWidth { 600 };
constexpr int ScreenHeight { 400 };


SDL_Window* gWindow {nullptr};
SDL_Surface* gScreenSurface {nullptr};
SDL_Surface* gHelloWorld {nullptr};


bool init()

{
    bool sucess {true};

    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("SDL não foi inicializado, SDL ERROR: %s", SDL_GetError());
        sucess = false;
    }

    else
    {
        //Criando a janela
        if ( gWindow = SDL_CreateWindow("SEKIRO", ScreenWidth, ScreenHeight, 0 ); gWindow == nullptr)
        {
            SDL_Log("A janela não pôde ser criada, SDL Error: %s\n", SDL_GetError());
            sucess = false;
        }
            
        else
        {
            //Pegando a surface da janela
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }
    return sucess;

}

bool loadMedia()
{
    bool sucess{true};

    std::string pathImg{ "/home/deku/Pictures/dekuXD.bmp"};
    if (gHelloWorld = SDL_LoadBMP(pathImg.c_str()); gHelloWorld == nullptr)
    {
        SDL_Log("Erro ao carregar imagem %s\n SDL_Error: %s",pathImg.c_str(), SDL_GetError() );
        sucess = false;
    }

    return sucess;
}

void close()
{
    SDL_DestroySurface(gHelloWorld);
    gHelloWorld = nullptr;

    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gScreenSurface = nullptr; // liberando a surface da tela

    SDL_Quit(); // limpando toda as inicializacoes dos subsystems SDL

}

int main(int argc, char* argv[])
{
    int exitCode {0};
    if( !init() )
    {
        SDL_Log("Erro ao iniciar ao inicializar o programa\n");
        exitCode = 1;

    }
    
    else 
    {
        if ( !loadMedia() )
        {
            SDL_Log("Erro ao carregar a mídia\n");
            exitCode = 2;
        }

        else
        {
            bool quit { false };

            SDL_Event e;
            SDL_zero ( e );

            while ( quit == false )
            {
                while( SDL_PollEvent( &e ) )
                {
                    if (e.type == SDL_EVENT_QUIT )
                    {
                        quit = true;
                    }
                }

                SDL_FillSurfaceRect( gScreenSurface, nullptr, SDL_MapSurfaceRGB( gScreenSurface, 0xFF, 0xFF, 0xFF) );
            
                SDL_BlitSurface(gHelloWorld, nullptr, gScreenSurface, nullptr );
            
                SDL_UpdateWindowSurface( gWindow );
            }
        }
        
    }
    

    close();

    return exitCode;
}



