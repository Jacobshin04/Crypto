#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include "Caesar.h"
#include "Linear.h"

using namespace std;

		
Linear::Linear()
{
	//prompt the user to choose between Encrypting and Decrypting
	//also calls the function to Encrypt or Decrypt
	(Linear::Select_Encrypt()? Encrypt_Linear(): Select_Decrypt_Linear());
	
} //end of "Linear"



bool Linear::Select_Encrypt()
{	
	//User choosing Encrypt or Decrypt
	int userNum;
	system("clear");
	cout << "0. Encrypt Linear Cipher" << endl
		 << "1. Decrypt Linear Cipher" << endl;
		 
	do{
		cout << "Enter a number: ";
		cin >> userNum;
	} while ((userNum != 0) and (userNum != 1)); //choosing between 0 and 1

	//return Encrypt -> True, Decrypt -> false
	return !(userNum);
	
} //end of "Select_Encrypt"



void Linear::Encrypt_Linear() 
{
	int a = 0;
	int b = 0;
	system("clear");

	//Get a, b key
		cout << "Linear Cipher C_i = a * P_i + b\nEnter a:";
		cin >> a;
		cout << "Enter b: ";
		cin >> b;
	

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
			result += Ascii((a * Alpha(tolower(original[i])) + b ) % 26);
		}		
	}

	//display Encrypted message
	cout << "\n\nResult for Encrypting " << original << " with Linear Cipher:\n\n "
	 << result << endl;

	 if(again())
	 {
	 	Encrypt_Linear();
	 } 
}

void Linear::Select_Decrypt_Linear()
{
	int userNum;
	system("clear");	
	cout << "0. Decrypt with a,b key " << endl
		 << "1. Decrypt without a,b key " << endl
		 << "2. find a, b  with Decrypted message " << endl;
		 
	do{
		cout << "Enter a number: ";
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cin >> userNum;
	} while ((userNum != 0) and (userNum != 1) and (userNum != 2)); //choosing between 0 and 1

	switch(userNum)
	{
		case 0:
		Decrypt_Linear_withKey();
		break;

		case 1:
		Decrypt_Linear_withoutKey();
		break;

		case 2:
		Decrypt_Linear_findKey();
		break;	
	}
}

void Linear::Decrypt_Linear_withKey()
{
	int a;
	int inv_a;
	int b;
	
	int aList[12] = {1,3,5,7, 9, 11, 15, 17, 19, 21, 23, 25};
	int inv_aList[12] = {1, 9, 21, 15, 3, 19, 7, 23, 11, 5, 17, 25};
	
	bool a_check = false;
	
	system("clear");

	do{
		cout << "Decrypt Linear Cipher C_i = a * P_i + b\nEnter a key (co prime with 26):";
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cin >> a;
		for(int i = 0; i < 12; ++i)
		{
			if(aList[i] == a)
			{
				a_check = true;
				inv_a = inv_aList[i];
			}
		}	
	} while(!a_check);

	do{
		cout << "\nEnter b key (0~25):";
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		
		cin >> b;
	} while((b < 0) or (b > 25));
	

	

	cout <<  "Enter a message you want to Decrypt: ";
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
			result += Ascii((inv_a * (Alpha(tolower(original[i])) - b + 26) ) % 26);
		}		
	}

	system("clear");

	cout << "\n\nResult for Decrypting " << original << " with Linear Cipher:\n\n"
	 << "a key: " << a << "\nb key: " << b << "\nResult: "<< result << endl;

	 if(again())
	 {
	 	Decrypt_Linear_withKey();
	 } 
	 
} //end of "Decrypt_Linear_withKey"

void Linear::Decrypt_Linear_withoutKey()
{return;}
void Linear::Decrypt_Linear_findKey()
{return;}

bool Linear::again()
{
	char response; 
	cout << "Do you want to do it again?(y/n): ";
	cin >> response;
	return (tolower(response) == 'y');
}
