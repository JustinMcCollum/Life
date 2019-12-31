#include <iostream>
#include <string>
#include "Learner.h"

using namespace std;

int main()
{
	Learner AI; //Create a learner object

	/*
		The following is the main loop. It will continue until the applications is closed.
		The user enters their input, and then the Learner will respond.
	*/
	for (;;)
	{
		cout << "\nYOU: "; //User prompt
		string phrase;
		getline(cin, phrase); //Using getline for multi word input, then store in phrase.


		cout << "COMPUTER: "; 
		AI.respond(phrase); //Pass the user input to the Learner and see if he can respond.
	}
}