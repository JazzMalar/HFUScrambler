#pragma once
#include <string>
#include "CScrambler.h"
#include "Data.h"

using namespace std;

class CControl
{

private:
	CScrambler* Scrambler;
	CData* Data;
	string FileExtension; 


public:
	CControl();
	~CControl();

	int encryptFile(string& file, string& key); 
	int decryptFile(string& file, string& key); 
};

