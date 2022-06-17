#include<iostream>
#include "Header.h"
#include "Console.h"
#include "Functions.h"
#include<Windows.h>
using namespace std;

int main()
{
    SetScreenBufferSize(160, 40);
    DisableCtrButton(0, 1, 1);
    DisableResizeWindow();
    showScrollbar(false);
	resizeConsole(CSWidth, CSHeight);
	SetConsoleTitle(TEXT("GAME DO MIN - OBJECT ORIENTED PROGRAMMING"));
	CTBang.designTittle();
	Cursor(false, 1);
	CTBang.mainMenu(0);
	Trang = 1;
	CTBang.xuLy();
	return 0;
}