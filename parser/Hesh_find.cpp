#include "stdafx.h"
#include "Hesh_find.h"



bool find_word(const string &str, unordered_set<char> filter)
{
	for (auto c : str) // проверка на совпадение для каждого символа в строке str
	{
		if (filter.find(c) != filter.end())
			return true;
	}
	return false;
}
