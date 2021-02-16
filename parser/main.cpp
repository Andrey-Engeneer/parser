
#include "stdafx.h"
#include "parsing.h"

#include <iostream>
#include <fstream>
#include <cstdlib>

int main()
{
	parser("Пример лога для парсинга.log","Пример результата парсинга.log","Пример фильтра для парсинга.txt", true);
    return 0;
}

