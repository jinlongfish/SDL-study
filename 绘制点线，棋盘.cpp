
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

	}//创建窗口



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


int draw()
{
	//2，设置渲染颜色
	SDL_SetRenderDrawColor(render, 67, 202, 223, 225);

	//3，清屏
	SDL_RenderClear(render);

	//渲染点线
	SDL_SetRenderDrawColor(render, 0, 0, 255, 255);
	for (int i = 0; i < 2000; i += 30)
	{
		SDL_RenderDrawLine(render, 0, i, 800, i);
	}
	for (int i = 0; i < 2000; i += 40)
	{
		SDL_RenderDrawLine(render, i, 0, i, 600);
	}

	//绘制矩形
	SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
	SDL_Rect rect = { 200,300,400,500 };
	SDL_RenderDrawRect(render, &rect);


	//4,渲染呈现
	SDL_RenderPresent(render);


	SDL_UpdateWindowSurface(win);
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
		while (SDL_PollEvent(&event))//取出事件
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

	if (draw() < 0)
	{
		return -1;
	}

	event_get();

	deinit();
	return 0;
}

