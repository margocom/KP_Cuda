#pragma once
#ifdef _DLLEXPORT_
#define _DECLARATOR_ __declspec(dllexport)
#else
#define _DECLARATOR_ __declspec(dllimport)
#endif
extern "C"
{
	void* _DECLARATOR_ __cdecl calculate(void* image);
}
