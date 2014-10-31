#include "stdafx.h"
#include "Control.h"


CControl::CControl()
{
	this->Scrambler = new CScrambler;
	this->Data = new CData;
}


CControl::~CControl()
{
}

int CControl::encryptFile(string& file, string& key)
{

	this->Data->OpenFileForRead(file);
	this->Data->OpenFileForWrite(file + ".hfux"); 
	 
	this->Scrambler->Encrypt(Data->m_pReadStream, Data->m_pWriteStream, key); 

	return 0; 

}
