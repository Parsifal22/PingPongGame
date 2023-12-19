
#include <windows.h>


struct Render_State
{
	int height, width;
	void* memory;

	BITMAPINFO bitmap_info;
};

extern Render_State render_state;  

extern bool running;  


void render_background();
void clear_screen(unsigned int color);

void draw_rect(int x0, int y0, int x1, int y1, unsigned int color);