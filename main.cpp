#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "define.h"
#include "sdlHelper.h"

//The tile
class Tile{
	//use the rect to know where to display.
	//change the texture based on the value of mtype.
	//examples in main render
	//rename all the types.
    public:
		//Initializes position and type
		Tile( int x, int y, bool tileType ){
			//Get the offsets
			tileBoundingBox.x = x;
			tileBoundingBox.y = y;

			//Set the collision box
			tileBoundingBox.w = TILE_WIDTH;
			tileBoundingBox.h = TILE_HEIGHT;

			//Get the tile type
			tileType = tileType;
		}

        //Shows the tile
		/*
        void render(SDL_Texture* tex){
			//tex->render(tileBoundingBox.x, tileBoundingBox.y);
		}
		*/

        //Get the tile type
        bool getType(){
			return tileType;
		}
        
    private:
        //The attributes of the tile
        SDL_Rect tileBoundingBox;

        //The tile type
        int tileType;
};

int main(int argc, char** argv) {
	bool quit = false;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window * window = SDL_CreateWindow("SDL2 Displaying Image",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WWIDTH, WHIGHT, 0);

	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Surface * image = SDL_LoadBMP("./02_getting_an_image_on_the_screen/hello_world.bmp");
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);

	while (!quit)
	{
		SDL_WaitEvent(&event);

		switch (event.type)
		{
			case SDL_QUIT:
				quit = true;
				break;
		}

		SDL_Rect dstrect = { 5, 5, 320, 240 };
		SDL_Rect estrect = { 500, 500, 320, 240 };
		SDL_RenderCopy(renderer, texture, NULL, &dstrect);
		SDL_RenderCopy(renderer, texture, NULL, &estrect);
		//SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
