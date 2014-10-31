#pragma once
#include "CScrAlgo.h"
#include "defines.h"
#include <string>
#include <stdlib.h>
#include <iostream>

#define MAX_KEY_CHARS 6
#define ZERO_OFFSET 111

using namespace std;

#ifdef DEBUGGING_ON
#define CSA_SHOW_INTERN_INFO
#endif

class CSA_one :
	public CScrAlgo
{
public:
	CSA_one();
	~CSA_one();
	int Encrypt(istream& input, ostream& output, std::string& key);
	int Decrypt(istream& input, ostream& output, std::string& key);
private:
	int getShiftValue(const std::string& key);
};


