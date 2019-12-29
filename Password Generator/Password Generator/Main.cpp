#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

static const char alphanum[] = "0123456789" "!@#$%^&*" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";

int size = sizeof(alphanum) - 1;

int main()
{
	
	int length; //password length
	cout << "How long do you want your password to be? ";
	cin >> length;
	
	srand(time(0));

	for (int i = 0; i < length; i++)
	{
		cout << alphanum[rand() % ::size];
	}
	cin.ignore();
	getchar();
	return 0;
}