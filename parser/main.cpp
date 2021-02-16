// parser.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "parsing.h"

#include <iostream>
#include <fstream>
#include <cstdlib> // для использования функции exit()

int main()
{
	parser("Пример лога для парсинга.log","Пример результата парсинга.log","Пример фильра для парсинга.txt", false);// вызов функции парсинга
    return 0;
}

