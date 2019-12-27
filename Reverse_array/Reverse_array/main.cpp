#include <stdlib.h>
#include<iostream>
#include <cstring>
#include <fstream>
#pragma warning(disable:4996)

using namespace std;

int *reverseArray(int arr[], int size)
{
	int sourceIndex;
	int targetIndex;


	if (size <= 0)
	{
		return 0;
	}
	int *copy = new int[size];

	for (sourceIndex = size - 1, targetIndex = 0; sourceIndex >= 0; sourceIndex--, targetIndex++)
	{
		copy[targetIndex] = arr[sourceIndex];
	}

	return copy;
}

void showArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", arr[i]);
	}
}


int main()
{
	const int SIZE = 50; 
	int values[SIZE];
	int n = 0;

	cout << "Enter a number between 1 - 10:";
	cin >>  n;

	if (n <= 0 || n >= SIZE)
	{
		return 0;
	}
	getchar();

	ifstream InFile; 
	InFile.open("data.txt");
	for (int i = 0; i < n; i++)
	{
		InFile >> values[i];
	}
	InFile.close();
		
	int *arrCopy = reverseArray(values, n);
	showArray(arrCopy, n);
	
	getchar();
	return 0;
}