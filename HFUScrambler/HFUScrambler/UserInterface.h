///////////////////////////////////////////////////////////
//  CUserInterface.h
//  Implementation of the Class CUserInterface
//  Created on:      30-Okt-2014 21:35:34
//  Original author: AbdulM
///////////////////////////////////////////////////////////

#if !defined(EA_775F6831_9ED5_4ae2_B4CB_D046FEF667D5__INCLUDED_)
#define EA_775F6831_9ED5_4ae2_B4CB_D046FEF667D5__INCLUDED_
#include "string"

using namespace std;
class CUserInterface
{

public:
	string path;
	string key;

	CUserInterface();
	~CUserInterface();
	void Ask();
	void Print(string ret_val);

};
#endif // !defined(EA_775F6831_9ED5_4ae2_B4CB_D046FEF667D5__INCLUDED_)
