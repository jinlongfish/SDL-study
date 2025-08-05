/*
#include <SDL.h>

#undef main
#define W 800
#define H 600

SDL_Window *win = NULL;
SDL_Renderer *render = NULL;

int inited()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)//初始化视频和音频模块
	{
		SDL_Log("初始化失败：%s", SDL_GetError());//SDL_GetError是获取错误信息
		return -1;
	}//初始化

	 //参数分别为标题，x坐标，y坐标（从左上开始），宽，高，标识
	win = SDL_CreateWindow("hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

	if (NULL == win)
	{
		SDL_Log("创建窗口失败：%s", SDL_GetError());
		return -1;

	}
	//创建窗口
	//1，创建渲染器
	render = SDL_CreateRenderer(win, -1, 0);
	//SDL_RENDERER_ACCELERATED硬件加速  |  SDL_RENDERER_SOFTWARE软件渲染
	if (NULL == render)
	{
		SDL_Log("创建窗口失败：%s", SDL_GetError());
		return -1;

	}
	return 0;
}


int drawed()
{

	//2，设置渲染颜色
	SDL_SetRenderDrawColor(render, 67, 202, 223, 225);

	//3，清屏
	SDL_RenderClear(render);

	//导入BMP图片
	SDL_Surface *bmp_surf = SDL_LoadBMP("8.bmp");
	if (NULL == bmp_surf)
	{
		SDL_Log("获取bmp_surface失败：%s", SDL_GetError());
		return -1;
	}
	//SDL_SetWindowSize(win,bmp_surf->w,bmp_surf->h);

	//创建texture
	SDL_Texture *texture = SDL_CreateTextureFromSurface(render, bmp_surf);
	if (NULL == texture)
	{
		SDL_Log("创建texture失败：%s", SDL_GetError());
		return -1;
	}

	SDL_Point pt = { 60,70 };
	SDL_Rect rect = { 100,100,200,300 };

	//复制texture
	SDL_RenderCopyEx(render, texture, NULL, &rect, 30, &pt, SDL_FLIP_HORIZONTAL);
	//渲染器；texture；texture的目标区域；复制目标的区域。（NULL为全部）；旋转角度（浮点）；选择中心(以目标区域的左上角作为0，0)；翻转操作。

	//4,渲染呈现
	SDL_RenderPresent(render);

	//销毁texture
	SDL_DestroyTexture(texture);

	return 0;

}

void deinit()
{
	//销毁渲染器
	SDL_DestroyRenderer(render);
	//销毁窗口
	SDL_DestroyWindow(win);
	SDL_Quit();		//退出
}

void event_get()
{
	SDL_Event event;	//事件监听

	while (true)
	{
		while(SDL_PollEvent(&event))//取出事件
		{
			switch (event.type)
			{
			case SDL_QUIT:
				return;
			default:
				break;
			}
		}
	}

}




int main() {
	if (inited() < 0)
	{
		return -1;
	}

	if (drawed() < 0)
	{
		return -1;
	}

	event_get();

	deinit();

	return 0;
}
*/