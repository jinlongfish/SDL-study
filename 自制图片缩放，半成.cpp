/*
//ͼƬ��������
#include <SDL.h>

#undef main
#define W 800
#define H 600

int main() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)//��ʼ����Ƶ����Ƶģ��
	{
		SDL_Log("��ʼ��ʧ�ܣ�%s", SDL_GetError());//SDL_GetError�ǻ�ȡ������Ϣ
		return -1;
	}//��ʼ��

	 //�����ֱ�Ϊ���⣬x���꣬y���꣨�����Ͽ�ʼ�������ߣ���ʶ
	SDL_Window *win = SDL_CreateWindow("hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

	if (NULL == win)
	{
		SDL_Log("��������ʧ�ܣ�%s", SDL_GetError());
		return -1;

	}
	//��������



	//1��������Ⱦ��
	SDL_Renderer *render = SDL_CreateRenderer(win, -1, 0);
	//SDL_RENDERER_ACCELERATEDӲ������  |  SDL_RENDERER_SOFTWARE�����Ⱦ
	if (NULL == render)
	{
		SDL_Log("��������ʧ�ܣ�%s", SDL_GetError());
		return -1;

	}

	//2��������Ⱦ��ɫ
	SDL_SetRenderDrawColor(render, 67, 202, 223, 225);

	//3������
	SDL_RenderClear(render);

	//����BMPͼƬ
	SDL_Surface *bmp_surf = SDL_LoadBMP("8.bmp");
	if (NULL == bmp_surf)
	{
		SDL_Log("��ȡbmp_surfaceʧ�ܣ�%s", SDL_GetError());
		return -1;
	}
	//SDL_SetWindowSize(win,bmp_surf->w,bmp_surf->h);

	//����texture
	SDL_Texture *texture = SDL_CreateTextureFromSurface(render, bmp_surf);
	if (NULL == texture)
	{
		SDL_Log("����textureʧ�ܣ�%s", SDL_GetError());
		return -1;
	}

	SDL_Rect rect = { 10,10,100,200 };
	//SDL_Rect rect1 = { 20,30,40,50 };


	SDL_Event event;	//�¼�����

	while (true)
	{
		if (SDL_PollEvent(&event))//ȡ���¼�
		{
			if(event.wheel.y > 0)
			{
				rect.w += 5;
				rect.h += 5;
				SDL_Log("+5");
				SDL_RenderClear(render);
				//����texture
				SDL_RenderCopy(render, texture, &rect, NULL);
				//��Ⱦ����texture��texture��Ŀ�����򣻸���Ŀ������򡣣�NULLΪȫ����

				//4,��Ⱦ����
				SDL_RenderPresent(render);
			}
			if (event.wheel.y < 0)
			{
				rect.w -= 5;
				rect.h -= 5;
				SDL_Log("-5");
				SDL_RenderClear(render);
				//����texture
				SDL_RenderCopy(render, texture, &rect, NULL);
				//��Ⱦ����texture��texture��Ŀ�����򣻸���Ŀ������򡣣�NULLΪȫ����

				//4,��Ⱦ����
				SDL_RenderPresent(render);
			}
			if (event.type == SDL_QUIT)
			{
				break;
			}


		}

	}

	//����texture
	SDL_DestroyTexture(texture);


	//������Ⱦ��
	SDL_DestroyRenderer(render);


	//���ٴ���
	SDL_DestroyWindow(win);


	SDL_Quit();		//�˳�
	return 0;
}
*/
