#include "stdafx.h"
#include "CScrambler.h"


CScrambler::CScrambler()
{
}


CScrambler::~CScrambler()
{
}

//	int Decrypt(istream& input, ostream& output, std::string& key);

int CScrambler::Encrypt(istream& input, ostream& output, std::string& key)
{
	int iOut = -1;
	if (Algo)
	{
		iOut = Algo->Encrypt(input, output, key);
	}
	return iOut;
}

/*void CDuck::performQuack(void)
{
	if (m_pQuackBehavior)
	{
		m_pQuackBehavior->doQuack();
	}
}
*/