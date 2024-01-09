#include<windows.h>
#include "Kernel.cuh"
struct img
{
	int width;
	int height;
	unsigned* image;
};
void* calculate(void* image, double a, double b)
{
	struct img* im = (img*)image;
	if (calc(im->image, im->width, im->height, a, b) == -1)
		return NULL;
	return im;
}
BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD ul_reason_for_call,
	LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}