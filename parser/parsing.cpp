#include "stdafx.h"
#include "parsing.h"
#include "BM_find.h"
#include "Hesh_find.h"


int parser(string in_file, string out_file, string conf_file,bool recording_matches)
{
	string str; // declaring a variable string input file
	string filtr;//// declaring a variable string config file
	ifstream ifile(in_file); // open file
	ifstream cfile(conf_file); 
	ofstream ofile(out_file);
	unordered_set <string> stringSet; // declaring unordered_set for key phrase  
	unordered_set <char> charSet; // // declaring unordered_set for key char  
	unordered_set <string> outSet; // // declaring unordered_set for key string  

	 
	if (!ifile)// check open file
	{
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
	
	while (getline(cfile, filtr))// iterate through all the rows in file
	{ 
		if (filtr.length() == 0)// check NULL
			continue;

		if (filtr.length()==1)
		{
			charSet.insert(filtr[0]);// input key char in unordered_set
			continue;
		}
		
		stringSet.insert(filtr);// input key string in unordered_set
	}

	while (getline(ifile, str)) // iterate through all the rows in file
	{
		if (charSet.size() == 0)
			break;
		if (find_word(str, charSet))//Hesh-find
			outSet.insert(str);
	}

	unordered_set<string> ::iterator itr;

	for (itr = stringSet.begin(); itr != stringSet.end(); itr++) //iterate through all the rows in unordered_set
	{
		char *fil = (char*)(*itr).c_str();
		while (getline(ifile, str)) // iterate through all the rows in file
		{
			char *txt = (char*)str.c_str();
			if (search(txt, fil))// BM-find
				outSet.insert(str);
		}
		ifile.clear();
		ifile.seekg(0);// go to first string file
	}

	

	ifile.clear();
	ifile.seekg(0);// go to first string file


	if (recording_matches)
		for (itr = outSet.begin(); itr != outSet.end(); itr++) //write all matches string
		{
			ofile << (*itr) << endl; // // write string in file
		}
	else
		while (getline(ifile, str))
		{
			if (outSet.find(str) == outSet.end())
				ofile << str << endl; // write string in file
		}
	ifile.close(); //close file
	ofile.close(); 
	cfile.close();
	return 0;
}




