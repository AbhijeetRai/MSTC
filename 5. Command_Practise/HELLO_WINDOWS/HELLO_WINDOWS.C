/*
* @AUTHOR: ABHIJEET RAI 
* @DATE: 17TH NOV 2022 
* @GOAL: TO DISPLAY GREETINGS MESSAGE BOX
*/

#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nShowCmd)
{
	MessageBox(NULL, TEXT("Greetings!"), TEXT("Masterclass in C Batch 3!"), MB_OK);
	return (0);
}