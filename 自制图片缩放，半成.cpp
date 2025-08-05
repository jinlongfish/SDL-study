/*
//图片缩放自制
#include <SDL.h>

#undef main
#define W 800
#define H 600

int main() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)//初始化视频和音频模块
	{
		SDL_Log("初始化失败：%s", SDL_GetError());//SDL_GetError是获取错误信息
		return -1;
	}//初始化

	 //参数分别为标题，x坐标，y坐标（从左上开始），宽，高，标识
	SDL_Window *win = SDL_CreateWindow("hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

	if (NULL == win)
	{
		SDL_Log("创建窗口失败：%s", SDL_GetError());
		return -1;

	}
	//创建窗口



	//1，创建渲染器
	SDL_Renderer *render = SDL_CreateRenderer(win, -1, 0);
	//SDL_RENDERER_ACCELERATED硬件加速  |  SDL_RENDERER_SOFTWARE软件渲染
	if (NULL == render)
	{
		SDL_Log("创建窗口失败：%s", SDL_GetError());
		return -1;

	}

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

	SDL_Rect rect = { 10,10,100,200 };
	//SDL_Rect rect1 = { 20,30,40,50 };


	SDL_Event event;	//事件监听

	while (true)
	{
		if (SDL_PollEvent(&event))//取出事件
		{
			if(event.wheel.y > 0)
			{
				rect.w += 5;
				rect.h += 5;
				SDL_Log("+5");
				SDL_RenderClear(render);
				//复制texture
				SDL_RenderCopy(render, texture, &rect, NULL);
				//渲染器；texture；texture的目标区域；复制目标的区域。（NULL为全部）

				//4,渲染呈现
				SDL_RenderPresent(render);
			}
			if (event.wheel.y < 0)
			{
				rect.w -= 5;
				rect.h -= 5;
				SDL_Log("-5");
				SDL_RenderClear(render);
				//复制texture
				SDL_RenderCopy(render, texture, &rect, NULL);
				//渲染器；texture；texture的目标区域；复制目标的区域。（NULL为全部）

				//4,渲染呈现
				SDL_RenderPresent(render);
			}
			if (event.type == SDL_QUIT)
			{
				break;
			}


		}

	}

	//销毁texture
	SDL_DestroyTexture(texture);


	//销毁渲染器
	SDL_DestroyRenderer(render);


	//销毁窗口
	SDL_DestroyWindow(win);


	SDL_Quit();		//退出
	return 0;
}
*/
