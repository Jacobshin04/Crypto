#include <iostream>
#include "Cipher.hpp"
#include "Caesar.hpp"
#include "Linear.hpp"
using namespace std;


void Cipher::Start()
{
	// intializing user's choice
	int menu = -1;

	//list of Ciphers
	enum Cipher {CAESAR, LINEAR, VIGENERE, AUTOKEY, HILL, VERMAN, RSA, EXIT};

	//prompting the user to pick the Cipher
	system("clear");

	cout << "Choose the menu" <<  endl << endl;
	cout << "0. Caeser Cipher" << endl << endl;
	cout << "1. Linear Cipher" << endl << endl;
	cout << "2. Vigenere Cipher" << endl << endl;
	cout << "3. AutoKey Cipher" << endl << endl;
	cout << "4. Hill Cipher" << endl << endl;
	cout << "5. Verman Cipher" << endl << endl;
	cout << "6. RSA Crypto System" << endl << endl;
	cout << "7. exit" << endl;


	//boolean to determine repeating the switch statement
	bool repeat = false;
	do
	{
		//get number from the user
		cout << "Enter a Number: ";
		cin >> menu;

		switch(menu)
		{
			//num 0
			case CAESAR:{
				//initializing the Caesar Class object
				Caesar caesar1;	
			}
			break;

			//num 1
			case LINEAR:{
				//initializing the Linear Class object
				Linear linear1;	
			}
			break;
/*
			case VIGENERE:
			Vigenere();
			break;
			
			case AUTOKEY:
			AutoKey();
			break;
			
			case HILL:
			Hill();
			break;
			
			case VERMAN:
			Verman();
			break;

			case RSA:
			Rsa();
			break;	
			*/

			//num 7 -> program terminates
			case EXIT:
			exit(EXIT_SUCCESS);
			break;

			//prompting the user to enter the number again
			default:
				cout << "Enter a number again: ";
				repeat = true;
				break;
		}
	} while(repeat == true); //iterates until user inputs a appropriate number

	//go back to the starting menu again	
	Start();
	
} //end of "Start"


