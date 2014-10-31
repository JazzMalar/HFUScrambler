#pragma once
#include <iostream>
using namespace std;

class CScrAlgo
{
public:
	CScrAlgo();
	~CScrAlgo();
	virtual int Encrypt(istream& input, ostream& output, std::string& key) = 0;// pure virtual function -> abstract class
	virtual int Decrypt(istream& input, ostream& output, std::string& key) = 0;// pure virtual function -> abstract class
};


// return 0 = success // key = ASCII int Encrypt(istream& input, ostream& output, std::string& key);
// return 0 = success // key = ASCII int Decrypt(istream& input, ostream& output, std::string& key);};
