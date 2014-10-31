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
