#include <SDL.h>

namespace SDLproject
{
	class Screen
	{
	public:
		Screen();
		~Screen();
		bool init();
		void update();
		void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
		void close();
		bool processEvents();
		void clear();
		void boxBlur();

		const static int SCREEN_WIDTH = 800;
		const static int SCREEN_HEIGHT = 600;

	private:
		SDL_Window *m_window;
		SDL_Renderer *m_renderer;
		SDL_Texture *m_texture;
		Uint32 *m_buffer1;
		Uint32 *m_buffer2;
	};
}


