///////////////////////////////////////////////////////////
//  CMyFile.h
//  Headerclass of CMyFile (From Baseclass "CData")
//  Created on:      31-Okt-2014 19:39
//  Original author: Martin Osterwalder
///////////////////////////////////////////////////////////
#pragma once
#include "Data.h"
class CMyFile :
	public CData
{
public:
	ifstream *m_pReadStream;
	ofstream *m_pWriteStream;
	CMyFile();
	~CMyFile();
	int OpenForRead(string path);
	int OpenForWrite(string path);
	void write();
};

