/*
//修改像素点的颜色
#include <SDL.h>

#undef main
#define W 304
#define H 376

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

	}//创建窗口



	 //绘制一个矩形
	 //1.获取与窗口关联的surface
	SDL_Surface *surf = SDL_GetWindowSurface(win);
	if (NULL == surf)
	{
		SDL_Log("获取windowsurf失败：%s", SDL_GetError());
		return -1;
	}

	//导入BMP图片
	SDL_Surface *bmp_surf = SDL_LoadBMP("7.bmp");
	if (NULL == bmp_surf)
	{
		SDL_Log("获取bmp_surface失败：%s", SDL_GetError());
		return -1;
	}

	//修改像素颜色值
	Uint32 *px = (Uint32 *)surf->pixels;   //强制类型转换 void -> Uint32(SDL定义)
	Uint32 *px_t = (Uint32 *)bmp_surf->pixels;

	//px[i] = SDL_MapRGB(surf->format,10,20,30);
	for (int i = 2; i < 10000; i++)
	{
		px[i] = px_t[i];
		SDL_UpdateWindowSurface(win);
	}


	SDL_Event event;	//事件监听

	while (true)
	{
		if (SDL_PollEvent(&event))//取出事件
		{
			if (event.type == SDL_QUIT)
			{
				break;
			}
		}

		SDL_UpdateWindowSurface(win);
		SDL_Delay(10);
	}

	//释放surface
	SDL_FreeSurface(surf);

	//销毁窗口
	SDL_DestroyWindow(win);


	SDL_Quit();		//退出
	return 0;
}
*/