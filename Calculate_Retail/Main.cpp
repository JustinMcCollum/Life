
#include <iostream>
#include <iomanip>
using namespace std;

double calculateRetail(double wholesale, double markupPct)
{
	double retail = wholesale * markupPct / 100;
	return wholesale + retail;
}


int main()
{
	double wholesale, retail, markupPercent;

	cout << "Enter the items wholesale cost: ";
	cin >> wholesale;
	while (wholesale < 0)
	{
		cout << "Enter a non negative number: ";
		cin >> wholesale;
	}
	cout << "Enter the items mark up percentage: ";
	cin >> markupPercent;
	while (markupPercent < 0)
	{
		cout << "Enter a non negative number: ";
		cin >> markupPercent;
	}
	getchar();
	retail = calculateRetail(wholesale, markupPercent);
	cout << "The retail price is $" << setprecision(2) << fixed << retail << endl;
	getchar();
	return 0;
}
