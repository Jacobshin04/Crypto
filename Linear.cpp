#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include "Caesar.hpp"
#include "Linear.hpp"
#include "Cipher.hpp"

using namespace std;

		
Linear::Linear()
{
	//prompt the user to choose between Encrypting and Decrypting
	//also calls the function to Encrypt or Decrypt
	Select_Encrypt();
	
} //end of "Linear"



void Linear::Select_Encrypt()
{	
	//User choosing Encrypt or Decrypt or menu
	int userNum;
	system("clear");
	cout << "0. Encrypt Linear Cipher" << endl << endl
		 << "1. Decrypt Linear Cipher" << endl << endl
		 << "2. Go back to menu" << endl;
		 
	do{
		cout << "Enter a number: ";
		cin >> userNum;
	} while ((userNum != 0) and (userNum != 1) and (userNum != 2)); //choosing between 0, 1, 2

	//Encrypting with Linear Cipher
	if(userNum == 0)
	{
		Encrypt_Linear();
	}

	//Decrypting with Linear Cipher
	else if(userNum == 1)
	{
		Select_Decrypt_Linear();
	}

	//Go back to menu
	else
	{
		Cipher c1;
		c1.Start();
	}
	
	
} //end of "Select_Encrypt"



void Linear::Encrypt_Linear() 
{
	int a = 0;
	int b = 0;
	int aList[12] = {1,3,5,7, 9, 11, 15, 17, 19, 21, 23, 25};
	bool aExist = false;
	system("clear");

	//Get a, b key
		do{
			cout << "\nEncrypting Linear Cipher C_i = a * P_i + b\n"
				 << "(a shoudl be relatively prime to 26)\n\nEnter a:";
			cin >> a; 

			for(int i: aList)
			{
				if(i == a)
				{
					aExist = true;
				}
			}
		} while(!aExist);

		do{
			cout << "Enter b: ";
			cin >> b; } while(b > 25 or b < 0);
	

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
			//C_i = a * P_i + b(converted to only lower case)
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
	cout << "0. Decrypt with a,b key " << endl << endl
		 << "1. Decrypt without a,b key " << endl << endl
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
			//P_i = inverse _a *(C_i - b) (converted to only lower case)
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
{
	int inv_aList[12] = {1, 9, 21, 15, 3, 19, 7, 23, 11, 5, 17, 25};
	int counter = 0;
	int rowCount = 0;
	int rowLimit;
	
	cout <<  "Enter a message you want to Decrypt: ";
	cin.ignore();
	getline(cin, original);

	rowLimit = 80 / (original.length() +1);
	cout << "\n\nResult for Decrypting " << original << " with Linear Cipher:\n\n"
 	"Results: "<<  endl;

 	for(int i = 0; i < 12; i++)
 	{
 		for(int j = 0; j < 26; ++j)
 		{
 			result.clear();
	
			for(int k = 0; k < static_cast<int>(original.length()); ++k)
			{	
				//we don't encrypt spacebar
				if(original[k] == ' ')
				{
						result += ' ';
				}
				
				else
				{
					//P_i = inverse _a *(C_i - b) (converted to only lower case)
					result += Ascii((inv_aList[i] * (Alpha(tolower(original[k])) - j + 26) ) % 26);
				}
			}

			if(i != 0 or j != 0)
			{
				cout << result << ", ";	
				++counter;
				++rowCount;
				if(rowCount == rowLimit)
				{
					rowCount = 0;
					cout << endl;
				}
			}
 		}
 	}

 	cout <<endl << counter << "many ways\n";
 	
 	 if(again())
	 {
	 	Decrypt_Linear_withoutKey();
	 } 

} // end of "Decrypt_Linear_withoutKey()"



void Linear::Decrypt_Linear_findKey()
{
	int aList[12] = {1,3,5,7, 9, 11, 15, 17, 19, 21, 23, 25};       //list of a key
																	//(relatively prime w 26)	
	int inv_aList[12] = {1, 9, 21, 15, 3, 19, 7, 23, 11, 5, 17, 25};//list of inverse a(mod 26)

	system("clear");
	original.clear();
	result.clear();
	
	do{
		cout << "Finding a key and b key\nEnter the original Message(more than 2 letters): ";
		cin.ignore();
		getline(cin, original); 
	} while(original.length() < 2);

	do{
		cout << "\nEnter the Encrypted Message: ";
		
		getline(cin, result);	
		
	} while(result.length() != original.length());

	int p = Alpha(original[0]); //first letter of original message
	int q = Alpha(original[1]); //second letter of original message
	int r = Alpha(result[0]);   //first letter of encrypted message
	int s = Alpha(result[1]);   //second letter of encrypted message
	int aKey;
	int bKey;

	int inv_pq;  //invers of p - q
	for(int i = 0; i < 12; i++)
	{
		if(aList[i] == p - q)
		{
			inv_pq = inv_aList[i];
			aKey = (inv_pq * (r - s + 26)) % 26;
		}
		else if( aList[i] == q - p)
		{
			inv_pq = inv_aList[i];
			aKey = ((inv_pq * (s - r + 26)) )% 26;
		}
	}

	bKey = (r - (aKey * p) + 26 * 26) % 26;

	cout << "\na key is " << aKey << endl;
	cout << "\nb key is " << bKey << endl;
	cout << "\nEncrypted letter = " << aKey << " * Original Letter + "
		 << bKey << endl;	

	if(again())
	 {
	 	Decrypt_Linear_findKey();
	 } 
}

bool Linear::again()
{
	char response; 
	cout << "\nDo you want to do it again?(y/n): ";
	cin >> response;
	return (tolower(response) == 'y');
}
