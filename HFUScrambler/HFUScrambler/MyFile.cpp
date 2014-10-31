#include "stdafx.h"
#include "MyFile.h"
#include <iostream>
#include <fstream>



using namespace std;


CMyFile::CMyFile()
{
	m_pReadStream = new ifstream("");
	m_pWriteStream = new ofstream("");
	testData[0] = char("A");
}


CMyFile::~CMyFile()
{
	delete m_pReadStream;
	delete m_pWriteStream;
	m_pReadStream = NULL;
	m_pWriteStream = NULL;
}

int CMyFile::OpenForRead(string path)
{

	m_pReadStream->open(path, ios::in | ios::binary);
	if (m_pReadStream->is_open())
	{

		/*int _testPosition = 0;
		char c = m_pReadStream->get();

		while (m_pReadStream->good()) {
		cout << c;
		testData[_testPosition] = c;
		_testPosition++;
		c = m_pReadStream->get();
		}*/

		return 0;//No Error: Is Sucess
	}

	return 99; //Error: The File is not opened!
}
int CMyFile::OpenForWrite(string path)
{
	m_pWriteStream->open(path, ios::binary | ofstream::out);
	if (m_pWriteStream->is_open())
	{
		/*int _tempPosition = 0;

		for (int i = 0; i < sizeof(testData)-1; i++)
		{
		cout << testData[i] << endl;
		*m_pWriteStream << testData[i];
		}*/


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
