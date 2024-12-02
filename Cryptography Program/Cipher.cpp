#include <iostream>
#include "Cipher.hpp"
#include "Caesar.hpp"
#include "Linear.hpp"
#include "Rsa.hpp"
using namespace std;


void Cipher::Start()
{
	// intializing user's choice
	int menu = -1;

	//list of Ciphers
	enum Cipher {CAESAR, LINEAR, RSA, EXIT};

	//prompting the user to pick the Cipher
	system("clear");

	cout << "Choose the menu" <<  endl << endl;
	cout << "0. Caeser Cipher" << endl << endl;
	cout << "1. Linear Cipher" << endl << endl;
	cout << "2. RSA Crypto System" << endl << endl;
	cout << "3. exit" << endl;


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
			
			//num 2
			case RSA:{
			  Rsa Rsa1;
			}
			break;	
			
			//num 3 -> program terminates
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


