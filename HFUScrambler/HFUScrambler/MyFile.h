#pragma once
#include "Data.h"
class CMyFile :
	public CData
{
private:
	char testData[1000];


public:
	ifstream *m_pReadStream;
	ofstream *m_pWriteStream;
	CMyFile();
	~CMyFile();
	int OpenForRead(string path);
	int OpenForWrite(string path);
	void write();
};

