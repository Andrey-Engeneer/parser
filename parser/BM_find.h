#pragma once
#include <iostream>
#include <string>
# include <limits.h>
# include <stdio.h>

# define NO_OF_CHARS 256// ограничение длины строки

int max(int a, int b);
void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS]);
bool search(char *txt, char *pat);