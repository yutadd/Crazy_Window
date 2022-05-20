#include <windows.h>
#include <stdlib.h>
#include <random>
std::random_device rnd;
std::mt19937 mt(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
std::uniform_int_distribution<> rand1080(0, 1080);        // [0, 99] 範囲の一様乱数
std::uniform_int_distribution<> rand720(0, 720);        // [0, 99] 範囲の一様乱数
BOOL CALLBACK WndEnumProc(HWND hWnd, LPARAM)
{
    char szClassName[256];
    ::GetClassNameA(hWnd, szClassName, _countof(szClassName));
    for (; ::lstrcmpiA(szClassName, "Notepad") == 0;) {
        
            MoveWindow(hWnd, rand1080(mt), rand720(mt), 500,  500, TRUE);
            Sleep(16);
    }
    return TRUE;
}

int main()
{
    WinExec("notepad", SW_SHOW);
    ::EnumWindows(WndEnumProc, 0);
    return 0;
}