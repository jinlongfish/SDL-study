
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

	}//��������



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


int draw()
{
	//2��������Ⱦ��ɫ
	SDL_SetRenderDrawColor(render, 67, 202, 223, 225);

	//3������
	SDL_RenderClear(render);

	//��Ⱦ����
	SDL_SetRenderDrawColor(render, 0, 0, 255, 255);
	for (int i = 0; i < 2000; i += 30)
	{
		SDL_RenderDrawLine(render, 0, i, 800, i);
	}
	for (int i = 0; i < 2000; i += 40)
	{
		SDL_RenderDrawLine(render, i, 0, i, 600);
	}

	//���ƾ���
	SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
	SDL_Rect rect = { 200,300,400,500 };
	SDL_RenderDrawRect(render, &rect);


	//4,��Ⱦ����
	SDL_RenderPresent(render);


	SDL_UpdateWindowSurface(win);
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
		while (SDL_PollEvent(&event))//ȡ���¼�
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

