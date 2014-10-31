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

	cout << "START with ENCRYPTING-------------------------------------------------------" << endl;
	cout << "Please wait..." << endl;

	iShiftValue = getShiftValue(key);


	while (!(input.eof()))
	{
		iStreamValue = input.get();

#ifdef CSA_SHOW_INTERN_INFO
		cout << "in : " << iStreamValue << "in : "<< (char)iStreamValue << endl;

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
#endif

		if (iStreamValue == -1)
		{
			cout << ".... is finished successfully :)" << endl;
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
			cout << "uoops! Error! File will be corrupted!" << endl;
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

	cout << "START with DECRYPTING-------------------------------------------------------" << endl;
	cout << "Please wait..." << endl;

	iShiftValue = getShiftValue(key);



	while (!(input.eof()))
	{

		iStreamValue = input.get();

#ifdef CSA_SHOW_INTERN_INFO
		cout << "in : " << iStreamValue << "in : " << (char)iStreamValue << endl;

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
#endif
		if (iStreamValue == -1)
		{
			cout << ".... is finished successfully :)" << endl;
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
			cout << "uoops! Error! File will be corrupted!" << endl;
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
#ifdef CSA_SHOW_INTERN_INFO
	cout << "calc shift value...." << endl;
#endif

	for (size_t i = 0; (i < key.size() && i < MAX_KEY_CHARS); ++i)
	{
		iShiftValue += key.at(i);  //get int value
	}
#ifdef CSA_SHOW_INTERN_INFO
	cout << "shift value after subtraction: " << iShiftValue << endl;
#endif

	iShiftValue %= 256;  //0..255

#ifdef CSA_SHOW_INTERN_INFO
	cout << "shift value after modulo 255: " << iShiftValue << endl;
#endif	
	if (iShiftValue < 15)
	{
		iShiftValue += ZERO_OFFSET;
	}

#ifdef CSA_SHOW_INTERN_INFO
	cout << "shift value (after zero correction): " << iShiftValue << endl;
#endif

	return iShiftValue;
}
