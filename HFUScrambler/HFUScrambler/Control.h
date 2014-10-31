#pragma once
#include <string>

using namespace std;


class CScrambler; 
class CData; 


class CControl
{
public:
	CControl();
	~CControl();

	CScrambler* Scrambler; 
	CData* Data; 

	int encryptFile(string& file, string& key); 
	int decryptFile(string& file, string& key); 
};

