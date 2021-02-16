#include "stdafx.h"
#include "parsing.h"
#include "BM_find.h"
#include "Hesh_find.h"


int parser(string in_file, string out_file, string conf_file,bool recording_matches)
{
	string str; // объ€вл€ем переменную дл€ строк из входного файл€
	string filtr;//// объ€вл€ем переменную дл€ строк из файл€ с ключевыми фразами
	ifstream ifile(in_file); // файл дл€ чтени€
	ifstream cfile(conf_file); // файл с фильтрами
	ofstream ofile(out_file);// файл дл€ записи
	unordered_set <string> stringSet; // объ€вл€ем неупор€доченное множество дл€ ключевых строк  
	unordered_set <char> charSet; // объ€вл€ем неупор€доченное множество дл€ ключевых символов 
	unordered_set <string> outSet; // объ€вл€ем неупор€доченное множество дл€ отфильтрованных строк

	 
	if (!ifile)// ≈сли мы не можем открыть этот файл дл€ записи данных в него,
	{
		// то выводим сообщение об ошибке и выполн€ем функцию exit()
		cerr << "Uh oh, " << in_file << "could not be opened for writing!" << endl;
		exit(1);
	}
	if (!cfile)
	{
		cerr << "Uh oh, " << conf_file << "could not be opened for writing!" << endl;
		exit(2);
	}
	if (!ofile)
	{
		cerr << "Uh oh, "<< out_file <<  "could not be opened for writing!" << endl;
		exit(3);
	}
	
	while (getline(cfile, filtr))// пока не достигнут конец файла берЄм очередную ключевую строку
	{ 
		if (filtr.length() == 0)// проверка на пустую строку
			continue;

		if (filtr.length()==1)
		{
			charSet.insert(filtr[0]);// добовление ключевого символа в неупор€доченное множество
			continue;
		}
		
		stringSet.insert(filtr);// добовление ключевой строки в неупор€доченное множество
	}
	unordered_set<string> ::iterator itr;

	for (itr = stringSet.begin(); itr != stringSet.end(); itr++) //перебор всех ключевых строк неупор€доченного множества
	{
		char *fil = (char*)(*itr).c_str();
		while (getline(ifile, str)) // пока не достигнут конец файла берЄм очередную строку
		{
			char *txt = (char*)str.c_str();
			if (search(txt, fil))
				outSet.insert(str);
		}
		ifile.clear();
		ifile.seekg(0);// возвращение указател€ в начало файла
	}

	while (getline(ifile, str)) // пока не достигнут конец файла берЄм очередную строку
	{
		if (find_word(str, charSet))
			outSet.insert(str);
	}

	ifile.clear();
	ifile.seekg(0);// возвращение указател€ в начало файла


	if (recording_matches)
		for (itr = outSet.begin(); itr != outSet.end(); itr++) //перебор всех ключевых строк неупор€доченного множества
		{
			ofile << (*itr) << endl; // добовл€ем строку в новый файл
		}
	else
		while (getline(ifile, str))
		{
			if (outSet.find(str) == outSet.end())
				ofile << str << endl; // добовл€ем строку в новый файл
		}
	ifile.close(); //закрываем файл
	ofile.close(); 
	cfile.close();
	return 0;
}




