#ifndef SDL2_ITC_SDL2_H
#define SDL2_ITC_SDL2_H

#include <SDL2/SDL.h>
#include <vector>

using namespace std;

namespace it_sdl{
	void it_line(SDL_Renderer* renderer, int x0, int y0, int x1, int y1);
}

#endif //SDL2_ITC_SDL2_H
