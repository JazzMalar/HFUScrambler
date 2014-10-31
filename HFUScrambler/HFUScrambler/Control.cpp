#include "stdafx.h"
#include "Control.h"
#include "Data.h"
#include "CScrambler.h"

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

	this->Data->OpenForRead(file);
	this->Data->OpenForWrite(file + ".hfux"); 
	 
	this->Scrambler->Encrypt((*(Data->m_pReadStream)), (*(Data->m_pWriteStream)), key); 

	return 0; 

}
