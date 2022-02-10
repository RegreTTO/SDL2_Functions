#ifndef SDL2_ITC_SDL_H
#define SDL2_ITC_SDL_H

#include <SDL.h>
#include <vector>

using namespace std;

namespace it_sdl {

	void it_horizontalLine(SDL_Renderer *render, int x, int y, int length);

	void it_verticalLine(SDL_Renderer *render, int x, int y, int length);

	void it_hollow_rectangle(SDL_Renderer *renderer, int x, int y, int width, int height);

	void it_verticalDiagram(SDL_Renderer *render, const vector<int> &numbers);

	void it_horizontalDiagram(SDL_Renderer *render, const vector<int> &numbers);
}
#endif
