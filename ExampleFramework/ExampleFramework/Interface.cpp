#include "Common.h"
#include "Interface.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "SceneManager.h"

namespace BONE_FRAMEWORK
{
	LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
	{
		switch (iMessage) {
		case WM_MOUSEMOVE:
			break;

		case WM_DESTROY:
			CRenderManager::GetInstance()->ReleaseMembers();
			PostQuitMessage(0);
			return 0;
		}
		return(DefWindowProc(hWnd, iMessage, wParam, lParam));
	}

	HWND FastCreateWindow(HINSTANCE& _hInstance, std::string _name, int _width, int _height)
	{
		HWND hWnd;
		WNDCLASS WndClass;

		WCHAR Temp[MAX_PATH] = TEXT("");
		mbstowcs(Temp, _name.c_str(), _name.size() + 1);
		
		WndClass.cbClsExtra = 0;
		WndClass.cbWndExtra = 0;
		WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		WndClass.hInstance = _hInstance;
		WndClass.lpfnWndProc = (WNDPROC)WndProc;
		WndClass.lpszClassName = Temp;
		WndClass.lpszMenuName = NULL;
		WndClass.style = CS_HREDRAW | CS_VREDRAW;
		RegisterClass(&WndClass);

		hWnd = CreateWindow(Temp, Temp, WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, _width, _height,
			NULL, (HMENU)NULL, _hInstance, NULL);
		ShowWindow(hWnd, true);

		return hWnd;
	}
}