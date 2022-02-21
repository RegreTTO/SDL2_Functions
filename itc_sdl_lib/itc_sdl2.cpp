#include "itc_sdl.h"

namespace it_sdl {
	void it_line(SDL_Renderer *renderer, int x0, int y0, int x1, int y1) {
		bool steep = abs(y1 - y0) > abs(x1 - x0);
		if (steep) {
			swap(x0, y0);
			swap(x1, y1);
		}

		if (x0 > x1) {
			swap(x0, x1);
			swap(y0, y1);
		}
		int dx = x1 - x0;
		int dy = abs(y1 - y0);
		int error = dx / 2;
		int ystep = y0 < y1 ? 1 : -1;
		int y = y0;
		for (int x = x0; x <= x1; x++) {
			SDL_RenderDrawPoint(renderer, (steep ? y : x), (steep ? x : y));
			error -= dy;
			if (error < 0) {
				y += ystep;
				error += dx;
			}
		}
	}

	void it_circle(SDL_Renderer *renderer, int x0, int y0, int r) {
		int x = r;
		int y = 0;
		int r_error = 1 - x;
		while (x >= y) {
			SDL_RenderDrawPoint(renderer, x + x0, y + y0);
			SDL_RenderDrawPoint(renderer, y + x0, x + y0);
			SDL_RenderDrawPoint(renderer, -x + x0, y + y0);
			SDL_RenderDrawPoint(renderer, -y + x0, x + y0);
			SDL_RenderDrawPoint(renderer, -x + x0, -y + y0);
			SDL_RenderDrawPoint(renderer, -y + x0, -x + y0);
			SDL_RenderDrawPoint(renderer, x + x0, -y + y0);
			SDL_RenderDrawPoint(renderer, y + x0, -x + y0);
			y++;
			if (r_error < 0) r_error += 2 * y + 1;
			else x--, r_error += 2 * (y - x + 1);
		}
	}
}

