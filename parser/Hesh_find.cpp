#include "stdafx.h"
#include "Hesh_find.h"



bool find_word(const string &str, unordered_set<char> filter)
{
	for (auto c : str) // check identity char in filter  and string
	{
		if (filter.find(c) != filter.end())
			return true;
	}
	return false;
}
