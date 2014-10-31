///////////////////////////////////////////////////////////
//  Data.h
//  Headerclass of CData (Baseclass)
//  Created on:      31-Okt-2014 19:39
//  Original author: Martin Osterwalder
///////////////////////////////////////////////////////////
#pragma once
#include <iostream>
#include <fstream>

using namespace std;
class CData
{
private:
	filebuf fileInputBuffer;
	filebuf fileOutputBuffer;

public:
	istream *m_pReadStream;
	ostream *m_pWriteStream;


	CData();
	~CData();
	virtual int OpenForRead(string path);
	virtual int OpenForWrite(string path);
	virtual void write();
};

