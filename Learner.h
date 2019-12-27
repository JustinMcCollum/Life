#ifndef LEARNER_H
#define LEARNER_H

#include <iostream>
#include <fstream>
#include "Voice.h"

using namespace std;

class Learner
{
public:
	void respond(string phrase); //used to get, or teach a response.
	void say(string phrase); // used to textually and audibly communicate a phrase

	Voice voice; //The Learner's voice that will audibly communicate a response.

};
#endif