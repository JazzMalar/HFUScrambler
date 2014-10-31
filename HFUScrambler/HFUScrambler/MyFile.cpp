///////////////////////////////////////////////////////////
//  MyFile.cpp
//  Implementation of the Class CMyFile (instead of CFile)
//  Created on:      31-Okt-2014 19:39
//  Original author: Martin Osterwalder
///////////////////////////////////////////////////////////
#include "stdafx.h"
#include "MyFile.h"
#include <iostream>
#include <fstream>



using namespace std;


CMyFile::CMyFile()
{
	m_pReadStream = NULL;
	m_pWriteStream = NULL;
}


CMyFile::~CMyFile()
{
	if (!m_pReadStream == NULL)
	{
		delete m_pReadStream;
	}
	if (!m_pWriteStream ==NULL)
	{
		delete m_pWriteStream;
	}
	
	m_pReadStream = NULL;
	m_pWriteStream = NULL;
}

int CMyFile::OpenForRead(string path)
{
	m_pReadStream = new ifstream(path, ios::in | ios::binary);
	//m_pReadStream = new ifstream("");
	//m_pReadStream->open(path, ios::in | ios::binary);
	
	if (m_pReadStream->is_open())
	{
		return 0;//No Error: Is Sucess
	}
	
	return 99; //Error: The File is not opened!
}
int CMyFile::OpenForWrite(string path)
{
	m_pWriteStream = new ofstream(path, ios::binary | ofstream::out);
	//m_pWriteStream = new ofstream("");
	//m_pWriteStream ->open(path, ios::binary|ofstream::out);
	if (m_pWriteStream->is_open())
	{
	return 0;//No Error: Is Success
	}
	return 99; //Error: The File is not opened!
}
void CMyFile::write()
{
	m_pWriteStream->flush();
	m_pReadStream->close();
	m_pWriteStream->close();
}
