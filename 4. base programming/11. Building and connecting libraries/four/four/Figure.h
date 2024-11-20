#pragma once
#ifdef LIBRARYDYNAMIC_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif
#include <string>

LIBRARY_API class Figure {
protected:
	std::string name;
	int a, b, c, d;
	int A, B, C, D;
	Figure (int a, int b, int c, int A, int B, int C) {};
	Figure (int a, int b, int c, int d, int A, int B, int C, int D) {};
};