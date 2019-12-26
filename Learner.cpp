#include "Learner.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
/*
the following function will look for the passed pharse in the memory file,
If there is a match, the accompanying response, stored in the memory file along with the inital phrase.
*/

void Learner::respond(string phrase)
{
	fstream memory;
	memory.open("memory/memory.txt", ios::in); //open the memory file for input

	//Search through the file until the end is reached
	while (!memory.eof())   // While not at end of file
	{
		string identifier;
		getline(memory, identifier); //Get next phrase

		if (identifier == phrase) // Is if the phrase we are looking for
		{
			string response;
			getline(memory, response); // if so, get the response
			voice.say(response); //Textually and audibly output the response
			return; 
		}
	}
	memory.close(); // Looks like we couldn't find the phrase in memory. Close the file!
	memory.open("memory/memory.txt", ios::out | ios::app); // Now open for output, and append at end of file
	memory << phrase << endl; //Record initial phrase in memory

	voice.say(phrase); //Repeat the phrase the user entered
	string userResponse;
	cout << "YOU: ";
	getline(cin, userResponse); //Get the ideal response
	memory << userResponse << endl; //Write the ideal response to memory
	memory.close(); //Close the file
}

/*
	This function simply communicates a phrase textually and audibly
*/

void Learner::say(string phrase)
{
	this->voice.say(phrase);
}