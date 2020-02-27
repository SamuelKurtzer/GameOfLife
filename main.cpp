#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "define.h"
#include "sdlHelper.h"

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
		
		SDL_Rect* getBoundingBox(){
			return &tileBoundingBox;
		}	
    private:
        //The attributes of the tile
        SDL_Rect tileBoundingBox;

        //The tile type
        int tileType;
};

class GOL{
	private:
		vector<vector<bool>> map;
	public:
		/*
		 * Any live cell with fewer than two live neighbours dies (referred to as underpopulation or exposure[1]).
		 * Any live cell with more than three live neighbours dies (referred to as overpopulation or overcrowding).
		 * Any live cell with two or three live neighbours lives, unchanged, to the next generation.
		 * Any dead cell with exactly three live neighbours will come to life.
		 */
		GOL(unsigned height, unsigned width, string path){}
		vector<vector<bool>> step(){
			vector<vector<bool>> nextMap(map);
			// the inner section that can be looped through without a problem.
			for(int i=1; i<map.size()-1; i++){
				for(int j=1; j<map[0].size()-1; j++){
					int live = 0;
					// The window that needs to be accounted for
					for(int i_indent: {-1,0,1}){
						for(int j_indent: {-1,0,1}){
							// increment the number of live cells
							if(!(i_indent==0 && j_indent==0) && map[i+i_indent][j+j_indent]){
								live++;
							}
						}
					}
					// Set the cell depending on the number alive.
					if(map[i][j]){
						if(live < 2 || live >= 4){
							nextMap[i][j] = false;
						}else{
							nextMap[i][j] = true;
						}
					}else if(live > 3){
						nextMap[i][j] = true;
					}
				}
			}
			// now do the top & bottom section
			for(int i=0; i<map.size(); i++){
				
			}
		}
};


int main(int argc, char** argv) {
	bool quit = false;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window * window = SDL_CreateWindow("SDL2 Displaying Image",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WWIDTH, WHIGHT, 0);

	// Generate all textures
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Surface * whiteSquare = SDL_LoadBMP("./white.bmp");
	SDL_Texture * whiteTexture = SDL_CreateTextureFromSurface(renderer, whiteSquare);
	SDL_Surface * blackSquare = SDL_LoadBMP("./black.bmp");
	SDL_Texture * blackTexture = SDL_CreateTextureFromSurface(renderer, blackSquare);

	// generate all tiles and store in array
		// 2d array or 1d?
		// seperate array to track updates?
		//
	vector<vector<Tile>> tiles;
	while (!quit)
	{
		SDL_WaitEvent(&event);

		switch (event.type)
		{
			case SDL_QUIT:
				quit = true;
				break;
		}
		// 
		Tile a(10, 10, 1);
		Tile b(21, 21, 1);
		// Iterate over Tiles updaating if needed
		for(auto iterVector: tiles){
			for(auto iter: iterVector){

		SDL_RenderCopy(renderer, texture, NULL, a.getBoundingBox());
		SDL_RenderCopy(renderer, texture, NULL, b.getBoundingBox());
		//SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(whiteSquare);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
