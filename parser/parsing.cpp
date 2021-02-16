#include "stdafx.h"
#include "parsing.h"
#include "BM_find.h"
#include "Hesh_find.h"


int parser(string in_file, string out_file, string conf_file,bool recording_matches)
{
	string str; // ��������� ���������� ��� ����� �� �������� �����
	string filtr;//// ��������� ���������� ��� ����� �� ����� � ��������� �������
	ifstream ifile(in_file); // ���� ��� ������
	ifstream cfile(conf_file); // ���� � ���������
	ofstream ofile(out_file);// ���� ��� ������
	unordered_set <string> stringSet; // ��������� ��������������� ��������� ��� �������� �����  
	unordered_set <char> charSet; // ��������� ��������������� ��������� ��� �������� �������� 
	unordered_set <string> outSet; // ��������� ��������������� ��������� ��� ��������������� �����

	 
	if (!ifile)// ���� �� �� ����� ������� ���� ���� ��� ������ ������ � ����,
	{
		// �� ������� ��������� �� ������ � ��������� ������� exit()
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
	
	while (getline(cfile, filtr))// ���� �� ��������� ����� ����� ���� ��������� �������� ������
	{ 
		if (filtr.length() == 0)// �������� �� ������ ������
			continue;

		if (filtr.length()==1)
		{
			charSet.insert(filtr[0]);// ���������� ��������� ������� � ��������������� ���������
			continue;
		}
		
		stringSet.insert(filtr);// ���������� �������� ������ � ��������������� ���������
	}
	unordered_set<string> ::iterator itr;

	for (itr = stringSet.begin(); itr != stringSet.end(); itr++) //������� ���� �������� ����� ���������������� ���������
	{
		char *fil = (char*)(*itr).c_str();
		while (getline(ifile, str)) // ���� �� ��������� ����� ����� ���� ��������� ������
		{
			char *txt = (char*)str.c_str();
			if (search(txt, fil))
				outSet.insert(str);
		}
		ifile.clear();
		ifile.seekg(0);// ����������� ��������� � ������ �����
	}

	while (getline(ifile, str)) // ���� �� ��������� ����� ����� ���� ��������� ������
	{
		if (find_word(str, charSet))
			outSet.insert(str);
	}

	ifile.clear();
	ifile.seekg(0);// ����������� ��������� � ������ �����


	if (recording_matches)
		for (itr = outSet.begin(); itr != outSet.end(); itr++) //������� ���� �������� ����� ���������������� ���������
		{
			ofile << (*itr) << endl; // ��������� ������ � ����� ����
		}
	else
		while (getline(ifile, str))
		{
			if (outSet.find(str) == outSet.end())
				ofile << str << endl; // ��������� ������ � ����� ����
		}
	ifile.close(); //��������� ����
	ofile.close(); 
	cfile.close();
	return 0;
}




