#pragma once
#include <iostream>//подключаем ввод/вывод
#include <string> // подключаем строки
#include <fstream> // подключаем для работы с файлами
#include <unordered_set>//подключаем неупорядоченное множество
#include <sstream>//подключаем для организации работы со строками
using namespace std; // используем стандартное пространство имен


int parser(string in_file, string out_file, string conf_file,bool recording_matches);


