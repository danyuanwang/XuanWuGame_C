#include<string>
#include<stdarg.h>
#include<iostream>
#include "Logger.h"

int main(int argc, char* args[])
{
	const char* s = "Test";
	double x = 0.11;
	int y = 2;
	LOGTRACE("Hello World! %s, %f, %d", s, x, y);
}