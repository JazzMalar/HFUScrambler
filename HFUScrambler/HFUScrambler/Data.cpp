///////////////////////////////////////////////////////////
//  Data.cpp
//  Implementation of the Class CData
//  Created on:      31-Okt-2014 19:39
//  Original author: Martin Osterwalder
///////////////////////////////////////////////////////////
#include "stdafx.h"
#include "Data.h"
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

CData::CData()
{
	m_pReadStream = new ifstream("");
	m_pWriteStream = new ofstream("");
}


CData::~CData()
{
	delete m_pReadStream;
	delete m_pWriteStream;
	m_pReadStream = NULL;
	m_pWriteStream = NULL;
}

int CData::OpenForRead(string path)
{
	
	return 0;

}
int CData::OpenForWrite(string path)
{
	
	return 0;
}
void CData::write()
{
	m_pWriteStream->flush();
}
