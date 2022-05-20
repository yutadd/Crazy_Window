#include <windows.h>
#include <stdlib.h>

BOOL CALLBACK WndEnumProc(HWND hWnd, LPARAM)
{
    char szClassName[256];
    ::GetClassNameA(hWnd, szClassName, _countof(szClassName));
    for (int i=0; ::lstrcmpiA(szClassName, "Notepad") == 0;i++) {
            MoveWindow(hWnd, i, i, i , i , TRUE);
            Sleep(16);
    }
    return TRUE;
}

int main()
{
    ::EnumWindows(WndEnumProc, 0);
    return 0;
}