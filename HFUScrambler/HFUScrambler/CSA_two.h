#pragma once
#include "CScrAlgo.h"
#include "defines.h"

#ifdef DEBUGGING_ON
#define CSA_TWO_SHOW_INTERN_INFO
#endif

class CSA_two :
	public CScrAlgo
{
public:
	CSA_two();
	~CSA_two();
	int Encrypt(istream& input, ostream& output, std::string& key);
	int Decrypt(istream& input, ostream& output, std::string& key);

};