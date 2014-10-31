#include "stdafx.h"
#include "CScrambler.h"


CScrambler::CScrambler()
{
}


CScrambler::~CScrambler()
{
}


int CScrambler::Encrypt(istream& input, ostream& output, std::string& key)
{
	int iOut = -1;
	if (Algo)
	{
		iOut = Algo->Encrypt(input, output, key);
	}
	return iOut;
}

int CScrambler::Decrypt(istream& input, ostream& output, std::string& key)
{
	int iOut = -1;
	if (Algo)
	{
		iOut = Algo->Encrypt(input, output, key);
	}
	return iOut;
}
