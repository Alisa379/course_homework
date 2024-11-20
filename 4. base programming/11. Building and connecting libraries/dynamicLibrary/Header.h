#pragma once
#include <string>
#ifdef DYNAMICLIBRARY_EXPORTS
#define SERVICE_API __declspec(dllexport)
#else
#define SERVICE_API __declspec(dllimport)
#endif

class Leaver {
public:
	SERVICE_API std::string leave(std::string s);
};