#include <windows.h>
#include "utils.hpp"
#include "platform_common.hpp"
#include <iostream>

#define pressed(b) (input.buttons[b].is_down && input.buttons[b].changed)
#define is_down(b) input.buttons[b].is_down
#define released(b) (!input.buttons[b].is_down && input.buttons[b].changed)

static float render_scale = 0.01f;

struct Render_State
{
	int height, width;
	void* memory;

	BITMAPINFO bitmap_info;
};

extern Render_State render_state;  

extern bool running;  

inline int clamp(int min, int val, int max);

void clear_screen(unsigned int color);

void draw_rect_in_pixels(int x0, int y0, int x1, int y1, unsigned int color);
void draw_rect(float x, float y, float half_size_x, float half_size_y, unsigned int color);
void draw_number(int number, float x, float y, float size, u32 color);
void simulate_game(float dt);