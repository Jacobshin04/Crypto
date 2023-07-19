#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include "Caesar.h"



using namespace std;
int Alpha(char alpha) {return alpha - 'a';}	  //changing Ascii value to 0~26 
char Ascii(char alpha) {return alpha + 'a';}  //changing 0~26 to Ascii Value

Caesar::Caesar()
{	
	//prompt the user to choose between Encrypting and Decrypting
	//also calls the function to Encrypt or Decrypt
	(Select_Encrypt()? Encrypt_Caesar(): Decrypt_Caesar());

	
} // end of "Caeser"


bool Caesar::Select_Encrypt()
{	
	//User choosing Encrypt or Decrypt
	int userNum;
	system("clear");
	cout << "0. Encrypt Caeser Cipher" << endl
		 << "1. Decrypt Caeser Cipher" << endl;
		 
	do{
		cout << "Enter a number: ";	
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cin >> userNum;
	} while ((userNum != 0) and (userNum != 1)); //choosing between 0 and 1

	//return Encrypt -> True, Decrypt -> false
	return !(userNum);
	
} //end of "Select_Encrypt"

void Caesar::Encrypt_Caesar()
{
	system("clear");

	//prompt user to input the message
	cout <<  "Enter a message you want to Encrypt (English): ";
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
			result += Ascii(Alpha(tolower(original[i]) + 3) % 26);
		}		
	}

	//display Encrypted message
	cout << "\n\nResult for Encrypting " << original << " with Caeser Cipher:\n\n "
	 << result << endl;

	 if(again())
	 {
	 	Encrypt_Caesar();
	 } 
	
} // end of "Encrypt_Caesar"

void Caesar::Decrypt_Caesar()
{
	system("clear");

	//prompt user to input the Encrypted message
	cout <<  "Enter a message you want to Decrypt(English): ";
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

	 if(again())
	 {
	 	Decrypt_Caesar();
	 } 
}

bool Caesar::again()
{
	char response; 
	cout << "Do you want to do it again?(y/n): ";
	cin >> response;
	return (tolower(response) == 'y');
}
