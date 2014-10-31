#include "stdafx.h"
#include "Control.h"
#include "Data.h"
#include "CScrambler.h"

CControl::CControl()
{
	this->Scrambler = new CScrambler;
	this->Data = new CData;
	this->FileExtension = ".hfux";
}


CControl::~CControl()
{
}

int CControl::encryptFile(string& file, string& key)
{

	this->Data->OpenForRead(file);
	this->Data->OpenForWrite(file.append(FileExtension)); 
	 
	this->Scrambler->Encrypt((*(Data->m_pReadStream)), (*(Data->m_pWriteStream)), key); 

	return 0; 

}

int CControl::decryptFile(string& file, string& key)
{
	this->Data->OpenForRead(file);
	this->Data->OpenForWrite(file.substr(0, file.length() - FileExtension.length()));

	this->Scrambler->Decrypt((*(Data->m_pReadStream)), (*(Data->m_pWriteStream)), key); 
}
