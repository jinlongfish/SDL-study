/*
//�޸����ص����ɫ
#include <SDL.h>

#undef main
#define W 304
#define H 376

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

	}//��������



	 //����һ������
	 //1.��ȡ�봰�ڹ�����surface
	SDL_Surface *surf = SDL_GetWindowSurface(win);
	if (NULL == surf)
	{
		SDL_Log("��ȡwindowsurfʧ�ܣ�%s", SDL_GetError());
		return -1;
	}

	//����BMPͼƬ
	SDL_Surface *bmp_surf = SDL_LoadBMP("7.bmp");
	if (NULL == bmp_surf)
	{
		SDL_Log("��ȡbmp_surfaceʧ�ܣ�%s", SDL_GetError());
		return -1;
	}

	//�޸�������ɫֵ
	Uint32 *px = (Uint32 *)surf->pixels;   //ǿ������ת�� void -> Uint32(SDL����)
	Uint32 *px_t = (Uint32 *)bmp_surf->pixels;

	//px[i] = SDL_MapRGB(surf->format,10,20,30);
	for (int i = 2; i < 10000; i++)
	{
		px[i] = px_t[i];
		SDL_UpdateWindowSurface(win);
	}


	SDL_Event event;	//�¼�����

	while (true)
	{
		if (SDL_PollEvent(&event))//ȡ���¼�
		{
			if (event.type == SDL_QUIT)
			{
				break;
			}
		}

		SDL_UpdateWindowSurface(win);
		SDL_Delay(10);
	}

	//�ͷ�surface
	SDL_FreeSurface(surf);

	//���ٴ���
	SDL_DestroyWindow(win);


	SDL_Quit();		//�˳�
	return 0;
}
*/