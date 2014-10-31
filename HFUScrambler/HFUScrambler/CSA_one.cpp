#include "stdafx.h"
#include "CSA_one.h"



CSA_one::CSA_one()
{
}


CSA_one::~CSA_one()
{
}


int CSA_one::Encrypt(istream& input, ostream& output, std::string& key)
{
	
	int iShiftValue = 0;
	int iTemp;
	int iStreamValue;
#ifdef CSA_SHOW_INTERN_INFO
	cout << "START with ENCRYPTING-------------------------------------------------------" << endl;
#endif
	iShiftValue = getShiftValue(key);


	while (!(input.eof()))
	{
		iStreamValue = input.get();

#ifdef CSA_SHOW_INTERN_INFO
		cout << "in : " << iStreamValue << "in : "<< (char)iStreamValue << endl;
#endif
		if (input.bad())
		{
			cout << "bad!" << endl;
		}
		if (input.end)
		{
			cout << "end!" << endl;
		}
		if (input.eof())
		{
			cout << "eof!" << endl;
		}
		if (iStreamValue == -1)
		{
			cout << "break" << endl;
			break;
		}




		if ((iStreamValue + iShiftValue) > 255)
		{
			iTemp = (iStreamValue + iShiftValue) - 255;
		}
		else
		{
			iTemp = iStreamValue + iShiftValue;
		}

		//check
		if (iTemp > 255)
		{
			cout << "Errror!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		}
		//cout << iTemp << endl;  //get int value
		output.put(iTemp);
#ifdef CSA_SHOW_INTERN_INFO
		cout << "out : " << iTemp << "out : " << (char)iTemp << endl;
#endif
	}
	return 0;
}

int CSA_one::Decrypt(istream& input, ostream& output, std::string& key)
{

	int iShiftValue = 0;
	int iTemp;
	int iStreamValue;

#ifdef CSA_SHOW_INTERN_INFO
	cout << "START with DECRYPTING-------------------------------------------------------" << endl;
#endif

	iShiftValue = getShiftValue(key);



	while (!(input.eof()))
	{

		iStreamValue = input.get();

#ifdef CSA_SHOW_INTERN_INFO
		cout << "in : " << iStreamValue << "in : " << (char)iStreamValue << endl;
#endif
		if (input.bad())
		{
			cout << "bad!" << endl;
		}
		if (input.end)
		{
			cout << "end!" << endl;
		}
		if (input.eof())
		{
			cout << "eof!" << endl;
		}
		if (iStreamValue == -1)
		{
			cout << "break" << endl;
			break;
		}



		//decrypt with shift value
		if (iStreamValue >= iShiftValue)
		{
			iTemp = iStreamValue - iShiftValue;
		}
		else
		{
			iTemp = iShiftValue - iStreamValue;
			iTemp = (255 - iTemp);
		}

		//check
		if (iTemp > 255)
		{
			cout << "Errror!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		}
		//cout << iTemp << endl;  //get int value
		output.put(iTemp);
#ifdef CSA_SHOW_INTERN_INFO
		cout << "out : " << iTemp << "out : " << (char)iTemp << endl;
#endif
	}
	return 0;
}



int CSA_one::getShiftValue(const std::string& key)
{
	int iShiftValue = 0;

	cout << "calc shift value...." << endl;

	for (size_t i = 0; (i < key.size() && i < MAX_KEY_CHARS); ++i)
	{
		iShiftValue += key.at(i);  //get int value
	}
	cout << "shift value after subtraction: " << iShiftValue << endl;
	iShiftValue %= 256;  //0..255

	cout << "shift value after modulo 255: " << iShiftValue << endl;
	if (iShiftValue < 15)
	{
		iShiftValue += ZERO_OFFSET;
	}
	cout << "shift value (after zero correction): " << iShiftValue << endl;


	return iShiftValue;
}


/*
int CSA_one::Encrypt(istream& input, ostream& output, std::string& key)
{

	int iSumme = 0;
	int i = 0;

	while (!(key.empty()))
	{
		//iSumme = atoi(key.c_str());  //get int value
		iSumme = key.at(i);  //get int value

#ifdef CSA_SHOW_INTERN_INFO
		cout << "summe++ =" << iSumme << endl;
#endif
		i++;
	}


	
	//	std::string sNumber = "1234567890";
	//int         nResult;

	////nResult = atoi(sNumber.c_str());

	
#ifdef CSA_SHOW_INTERN_INFO
	cout << "encrypt one " << endl;
	cout << "key: " << &key << endl;
#endif
	return 0;  // 0->OK
}

int CSA_one::Decrypt(istream& input, ostream& output, std::string& key)
{
#ifdef CSA_SHOW_INTERN_INFO
	cout << "decrypt one:" << endl;
	cout << "key: " << &key << endl;
#endif
	return 0;  // 0->OK
}
*/