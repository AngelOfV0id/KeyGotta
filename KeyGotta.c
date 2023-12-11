/*

KeyGotta (early known as KamstRec) is a tiny Win32 utility that gets keyboard and mouse states
and writes info into console.

Copyright (c) Ivan Movchan, 2021-2022 / 2023
https://angelofv0id.github.io

See UNLICENSE.txt for licensing details.

*/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	system("title KeyGotta"); // Set console title
	
	while (1) // Program lifetime loop
	{
		// Scan keyboard
		
		for (int i = 8; i < 190; i++)
			if (GetAsyncKeyState(i))
				printf("0x%.2X (%d) key returned %d\n", i, i, GetAsyncKeyState(i));
		
		// Check mouse buttons
		
		POINT p; GetCursorPos(&p);
		if (GetAsyncKeyState(VK_LBUTTON))
			printf("Left mouse button returned %d\n", GetAsyncKeyState(VK_LBUTTON));
		if (GetAsyncKeyState(VK_MBUTTON))
			printf("Middle mouse button returned %d\n", GetAsyncKeyState(VK_MBUTTON));
		if (GetAsyncKeyState(VK_RBUTTON))
			printf("Right mouse button returned %d\n", GetAsyncKeyState(VK_RBUTTON));
		
		// Get cursor position
		printf("Cursor position: %d.%d\n", p.x, p.y);
		
		system("cls"); // Clear console
	};
	
	// return 0;
}
