#include "stdafx.h"
#include "CSA_two.h"


CSA_two::CSA_two()
{
}


CSA_two::~CSA_two()
{
}


int CSA_two::Encrypt(istream& input, ostream& output, std::string& key)
{
#ifdef CSA_TWO_SHOW_INTERN_INFO
	cout << "encrypt two " << endl;
	cout << "key: " << &key << endl;
#endif
	return 0;  // 0->OK
}

int CSA_two::Decrypt(istream& input, ostream& output, std::string& key)
{
#ifdef CSA_TWO_SHOW_INTERN_INFO
	cout << "decrypt two:" << endl;
	cout << "key: " << &key << endl;
#endif
	return 0;  // 0->OK
}
