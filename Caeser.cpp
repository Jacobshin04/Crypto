#include <iostream>
#include <string>
#include <cctype>
#include "Caeser.h"

using namespace std;
//

Caeser::Caeser()
{	
	//prompt the user to choose between Encrypting and Decrypting
	//also calls the function to Encrypt or Decrypt
	(Select_Encrypt()? Encrypt_Caesar(): Decrypt_Caesar());

	//giving time to the user to see the results
	cout << "Enter any key to continue" << endl;
	cin.ignore();
	
} // end of "Caeser"


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
	} while ((userNum != 0) and (userNum != 1)); //choosing between 0 and 1

	//return Encrypt -> True, Decrypt -> false
	return !(userNum);
	
} //end of "Select_Encrypt"

void Caeser::Encrypt_Caesar()
{
	system("clear");

	//prompt user to input the message
	cout <<  "Enter a message you want to Encrypt: ";
	cin.ignore();
	getline(cin, original);

	//empty result in case there are garnage value inside
	result.clear();
	
	for(int i = 0; i < static_cast<int>(original.length()); ++i)
	{	
		//we don't encrypt spacebar
		if(original[i] == ' ')
		{
			result += ' ';
		}
		else
		{
			//C_i = P_i +3 (converted to only lower case)
			result += Ascii(Alpha(tolower(original[i] + 3)) % 26);
		}		
	}

	//display Encrypted message
	cout << "\n\nResult for Encrypting " << original << " with Caeser Cipher:\n\n "
	 << result << endl;
	
} // end of "Encrypt_Caesar"

void Caeser::Decrypt_Caesar()
{
	system("clear");

	//prompt user to input the Encrypted message
	cout <<  "Enter a message you want to Decrypt: ";
	cin.ignore();
	getline(cin, original);

	//empty result in case there are garnage value inside
	result.clear();
	
	for(int i = 0; i < static_cast<int>(original.length()); ++i)
	{	
		//we don't decrypt spacebar
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

	//display decrypted message
	cout << "\n\nResult for Decrypting " << original << " with Caeser Cipher: \n\n"
	 << result << endl << endl;
}


