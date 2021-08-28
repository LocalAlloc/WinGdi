#include <Windows.h>

void rt(int counter)
{
    HDC hdc = GetDC(0);
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);


    HDC hWindow;
    HDC hDsktp;
    HWND hWnd;
    RECT wRect;
    int dX = 0, dY = 0, dW, dH;
    POINT wPt[    3];



    hWnd = GetDesktopWindow();
    hWindow = GetWindowDC(hWnd);
    hDsktp = GetDC(0);
    GetWindowRect(hWnd, &wRect);

    dW = GetSystemMetrics(0);
    dH = GetSystemMetrics(1);

    wPt[0].x = wRect.left + counter;
    wPt[0].y = wRect.top - counter;
    wPt[1].x = wRect.right + counter;
    wPt[1].y = wRect.top + counter;
    wPt[2].x = wRect.left - counter;
    wPt[2].y = wRect.bottom - counter;

    PlgBlt(hDsktp, wPt, hDsktp, wRect.left, wRect.top, wRect.right - wRect.left, wRect.bottom - wRect.top, 0, 0, 0);
    if (counter < 35) counter++;



}


void rt2(int counter)
{
    HDC hdc = GetDC(0);
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);


    HDC hWindow;
    HDC hDsktp;
    HWND hWnd;
    RECT wRect;
    int dX = 0, dY = 0, dW, dH;
    POINT wPt[3];



    hWnd = GetDesktopWindow();
    hWindow = GetWindowDC(hWnd);
    hDsktp = GetDC(0);
    GetWindowRect(hWnd, &wRect);

    dW = GetSystemMetrics(0);
    dH = GetSystemMetrics(1);

    wPt[0].x = wRect.left - counter;
    wPt[0].y = wRect.top + counter;
    wPt[1].x = wRect.right - counter;
    wPt[1].y = wRect.top - counter;
    wPt[2].x = wRect.left + counter;
    wPt[2].y = wRect.bottom + counter;

    PlgBlt(hDsktp, wPt, hDsktp, wRect.left, wRect.top, wRect.right - wRect.left, wRect.bottom - wRect.top, 0, 0, 0);
    if (counter < 35) counter++;

}

DWORD WINAPI effect5(LPVOID lpvd)
{
    HDC hdc = GetDC(0);
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);

    while (true)
    {
        int x1 = (rand() % 400);
        int y1 = (rand() % 400);
        int x2 = (rand() % 400);
        int y2 = (rand() % 400);
        int width = (rand() % w);
        int height = (rand() % h);
        BitBlt(hdc, x1, y1, width, height, hdc, x2, y2, SRCCOPY);
    }
}


DWORD WINAPI effect4(LPVOID lpvd)
{
    HDC hdc = GetDC(0);
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);

    while (true)
    {
        SelectObject(hdc, CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));
        BitBlt(hdc, 0, 0, w, h, hdc, 0, 0, PATINVERT);
        Sleep(5000);
    }
}

DWORD WINAPI effect3(LPVOID lpvd)
{
    HDC hdc = GetDC(0);
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);

    while (true)
    {
        SelectObject(hdc, CreateSolidBrush(RGB(rand() % 75, rand() % 75, rand() % 75)));
        BitBlt(hdc, 0, 0, w, h, hdc, 0, 0, PATINVERT);
        Sleep(50);
    }
}


DWORD WINAPI effect2(LPVOID lpvd)
{
    HDC hdc = GetDC(0);
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);

    while (true)
    {

        int r = rand() % h;
        int r2 = rand() % 2;
        if (r2 == 0)
        {
            BitBlt(hdc, 1, r, h, 66, hdc, 0, r, SRCCOPY);
        }
        else if (r2 == 1)
        {
            BitBlt(hdc, 0, r, h, 66, hdc, 1, r, SRCCOPY);
        }
    }
}


DWORD WINAPI effect1(LPVOID lpvd)
{
    HDC hdc = GetDC(0);
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    HWND hwnd = GetDesktopWindow();
    RECT rect;
    while (true)
    {
        GetWindowRect(hwnd, &rect);
        int r = rand() % 2;
        if (r == 0)
        {
            StretchBlt(hdc, 0, 0, rect.right, rect.bottom, hdc, 3, 3, rect.right - 6, rect.bottom - 6, SRCCOPY);
        }
        else if (r == 1)
        {
            StretchBlt(hdc, 3, 3, rect.right - 6, rect.bottom - 6, hdc, 0, 0, rect.right, rect.bottom, SRCCOPY);
        }
    }
}

DWORD WINAPI rta(LPVOID lpvd)
{
    while (true) {
        rt(10);
        rt2(10);
        rt2(10);
        rt(10);
    }
}

int __stdcall WinMain(HINSTANCE(a), HINSTANCE(b), LPSTR(c), int(d))
{
	FreeConsole();
	if (MessageBoxA(NULL,"This contains flashing lights still want to execute it?!", "Warning!", MB_ICONHAND | MB_YESNO) == IDYES)
    {
		CreateThread(0, 0, effect1, 0, 0, 0);
        CreateThread(0, 0, effect2, 0, 0, 0);
        CreateThread(0, 0, effect3, 0, 0, 0);
        CreateThread(0, 0, effect4, 0, 0, 0);
        CreateThread(0, 0, effect5, 0, 0, 0);
        CreateThread(0, 0, rta, 0, 0, 0);
        while (1) {}
    }
    else
    {
		return 0;
    }
}