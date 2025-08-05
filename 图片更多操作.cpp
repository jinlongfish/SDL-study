/*
#include <SDL.h>

#undef main
#define W 800
#define H 600

SDL_Window *win = NULL;
SDL_Renderer *render = NULL;

int inited()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)//��ʼ����Ƶ����Ƶģ��
	{
		SDL_Log("��ʼ��ʧ�ܣ�%s", SDL_GetError());//SDL_GetError�ǻ�ȡ������Ϣ
		return -1;
	}//��ʼ��

	 //�����ֱ�Ϊ���⣬x���꣬y���꣨�����Ͽ�ʼ�������ߣ���ʶ
	win = SDL_CreateWindow("hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

	if (NULL == win)
	{
		SDL_Log("��������ʧ�ܣ�%s", SDL_GetError());
		return -1;

	}
	//��������
	//1��������Ⱦ��
	render = SDL_CreateRenderer(win, -1, 0);
	//SDL_RENDERER_ACCELERATEDӲ������  |  SDL_RENDERER_SOFTWARE�����Ⱦ
	if (NULL == render)
	{
		SDL_Log("��������ʧ�ܣ�%s", SDL_GetError());
		return -1;

	}
	return 0;
}


int drawed()
{

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

	SDL_Point pt = { 60,70 };
	SDL_Rect rect = { 100,100,200,300 };

	//����texture
	SDL_RenderCopyEx(render, texture, NULL, &rect, 30, &pt, SDL_FLIP_HORIZONTAL);
	//��Ⱦ����texture��texture��Ŀ�����򣻸���Ŀ������򡣣�NULLΪȫ��������ת�Ƕȣ����㣩��ѡ������(��Ŀ����������Ͻ���Ϊ0��0)����ת������

	//4,��Ⱦ����
	SDL_RenderPresent(render);

	//����texture
	SDL_DestroyTexture(texture);

	return 0;

}

void deinit()
{
	//������Ⱦ��
	SDL_DestroyRenderer(render);
	//���ٴ���
	SDL_DestroyWindow(win);
	SDL_Quit();		//�˳�
}

void event_get()
{
	SDL_Event event;	//�¼�����

	while (true)
	{
		while(SDL_PollEvent(&event))//ȡ���¼�
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