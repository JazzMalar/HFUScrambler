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
	m_pReadStream = NULL;
	m_pWriteStream = NULL;
}


CData::~CData()
{
	if (!m_pReadStream==NULL)
	{
		delete m_pReadStream;
	}
	if (!m_pWriteStream == NULL)
	{
		delete m_pWriteStream;
	}
	m_pReadStream = NULL;
	m_pWriteStream = NULL;
}

int CData::OpenForRead(string path)
{
	fileInputBuffer.open(path, ios::in | ios::binary);
	m_pReadStream = new istream(&fileInputBuffer);
	if (fileInputBuffer.is_open())
	{
		return 0;
	}
	return 101; //Error: Not Implemented
	
}
int CData::OpenForWrite(string path)
{
	fileOutputBuffer.open(path, ios::out | ios::binary);
	m_pWriteStream = new ostream(&fileOutputBuffer);
	if (fileOutputBuffer.is_open())
	{
		return 0;
	}
	return 101; //Error: Not Implemented
}
void CData::write()
{
	m_pWriteStream->flush();
	fileInputBuffer.close();
	fileOutputBuffer.close();
}
