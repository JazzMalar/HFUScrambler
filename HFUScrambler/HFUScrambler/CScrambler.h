#pragma once
#include "CScrAlgo.h"
class CScrambler
{
public:
	CScrAlgo *Algo;

	CScrambler();
	~CScrambler();
	int Encrypt(istream& input, ostream& output, std::string& key);
	int Decrypt(istream& input, ostream& output, std::string& key);

};
