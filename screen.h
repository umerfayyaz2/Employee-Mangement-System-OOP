#ifndef SCREEN_H
#define SCREEN_H

#ifdef _WIN32
#include <cstdlib>
#define CLEAR_SCREEN() system("cls")
#else
#include <cstdlib>
#define CLEAR_SCREEN() system("clear")
#endif

#endif // SCREEN_H
