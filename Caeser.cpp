#include <iostream>
#include <string>
#include <cctype>
#include "Caeser.h"

using namespace std;

Caeser::Caeser()
{
	(Select_Encrypt()? Encrypt_Caesar(): Decrypt_Caesar());
	cout << "Enter any key to continue" << endl;
	cin.ignore();
}


bool Caeser::Select_Encrypt()
{	
	//User choosing Encrypt or Decrypt
	int userNum;
	system("clear");
	
	cout << "0. Encrypt Caeser Cipher" << endl
		 << "1. Decrypt Caeser Cipher" << endl;
		 
	do{
	cout << "Enter a number: ";
	cin >> userNum;
	} while ((userNum != 0) and (userNum != 1));

	return !(userNum);
}

void Caeser::Encrypt_Caesar()
{
	system("clear");
	cout <<  "Enter a message you want to Encrypt: ";
	cin.ignore();
	getline(cin, original);

	result.clear();
	
	for(int i = 0; i < static_cast<int>(original.length()); ++i)
	{	
		if(original[i] == ' ')
		{
			result += ' ';
		}
		else
		{

		//C_i = P_i +3
		result += Ascii(Alpha(tolower(original[i] + 3)) % 26);
		}
		
	}

	cout << "\n\nResult for Encrypting " << original << " with Caeser Cipher:\n\n "
	 << result << endl;
	
}

void Caeser::Decrypt_Caesar()
{
	system("clear");
	cout <<  "Enter a message you want to Decrypt: ";
	cin.ignore();
	getline(cin, original);

	result.clear();
	
	for(int i = 0; i < static_cast<int>(original.length()); ++i)
	{
		if(original[i] == ' ')
		{
			result += ' ';
		}
		else
		{

			//C_i = P_i +3
			result += Ascii((Alpha(original[i] - 3) + 26) % 26);
		}
	}
	
	cout << "\n\nResult for Decrypting " << original << " with Caeser Cipher: \n\n"
	 << result << endl << endl;
}

// wkh txlfn eurzq ira mxpsv ryhu wkh odcb grj 
//asdfasdf
