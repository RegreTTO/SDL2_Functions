#include "itc_sdl.h"

namespace it_sdl {
	void it_horizontalLine(SDL_Renderer *render, int x, int y, int length) {
		int sign = length < 0 ? -1 : 1;
		for (int i = x, j = 0; j < length * sign + 1; i += sign, j++)
			SDL_RenderDrawPoint(render, i, y);
		SDL_RenderPresent(render);
	}

	void it_verticalLine(SDL_Renderer *render, int x, int y, int length) {
		int sign = length < 0 ? -1 : 1;
		for (int i = y, j = 0; j < length * sign + 1; i -= sign, j++)
			SDL_RenderDrawPoint(render, x, i);
		SDL_RenderPresent(render);
	}

	void it_hollow_rectangle(SDL_Renderer *renderer, int x, int y, int width, int height) {
		y--;
		it_verticalLine(renderer, x, y, height);
		it_verticalLine(renderer, x + width, y, height);
		it_horizontalLine(renderer, x, y, width);
		it_horizontalLine(renderer, x, y - height, width);
	}

	void it_verticalDiagram(SDL_Renderer *render, const vector<int> &numbers) {
		SDL_Rect r;
		SDL_RenderGetViewport(render, &r);
		const int width = r.w;
		const int height = r.h;
		const int column_width = width / int(numbers.size());
		int max_elem = numbers[0];
		for (int i = 1; i < numbers.size(); ++i) {
			if (max_elem < numbers[i])
				max_elem = numbers[i];
		}
		const double k = double(height) / max_elem;
		for (int i = 0; i < numbers.size(); ++i) {
			it_hollow_rectangle(render, column_width * i, height, column_width, int(numbers[i] * k) - 1);
		}
	}

	void it_horizontalDiagram(SDL_Renderer *render, const vector<int> &numbers) {
		SDL_Rect r;
		SDL_RenderGetViewport(render, &r);
		const int width = r.w;
		const int height = r.h;
		const int column_height = height / int(numbers.size()) + 1;
		int max_elem = numbers[0];
		for (int i = 1; i < numbers.size(); ++i) {
			if (max_elem < numbers[i])
				max_elem = numbers[i];
		}
		const double k = double(width) / max_elem;
		for (int i = 0; i < numbers.size(); ++i) {
			it_hollow_rectangle(render, 0, 1 + column_height * i, int(numbers[i] * k) - 1, -column_height);
		}
	}
}
