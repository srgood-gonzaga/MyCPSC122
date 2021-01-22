/*
Name: Derek Goodnow
Class: CPSC 122, Section 2
Date Submitted: January 19, 2021
File Name: project1.cpp
Assignment Name: Project 1
Description: My first C++ program, which generates a specified amount of prime numbers, and outputs them to a file formatted with a specified number of columns.
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool isPrime(int);
void makeFile(string, int, int);

int main(int argc, char* argv[])
{

   string fileName;
	int numPrimes, numColumns;

	//return 1 and exit the program if no command line arguments provided.
	if (argc == 1)
	{
		cout << "You must specify at least one command line argument for a filename." << endl;
		return 1;
	}
	
	fileName = argv[1];
	
	cout << "How many primes should be stored? "<< endl;
	cin >> numPrimes;
	
	cout << "How many columns of primes should there be? " << endl;
	cin >> numColumns;
	
	makeFile(fileName, numPrimes, numColumns);
	

	cout << numPrimes << " primes stored in " << fileName << " in " << numColumns << " columns." << endl;
	return 0;
}

/*
	Description: This function determines if a given integer is prime
	Input: One integer to be operated on
	Returns: a True/False value dependant on if the given integer is prime or not.
*/
bool isPrime(int num)
{
	if (num <= 1)
		return false;
		
	for(int i = 2; i <= num/2; i++)
	{
		if (num % i == 0)
			return false;
	}
	
	return true;
}

/*
	Description: This function creates a file with the given name, with the specified number of primes arranged in the specified number of columns
	Input: The desired file name, the number of primes to be saved, and the number of columns desired.
*/
void makeFile(string fileName, int numPrimes, int numColumns)
{
	ofstream file;
	int index, primeIndex;
	
	file.open(fileName);
	
	//iterate over numbers until the desired number of primes have been found
	while(primeIndex < numPrimes) {
		if(isPrime(index))
		{
			file << index << '\t';
			//if the number of primes found divided by the number of columns desired yeilds a remainder equal to the number of columns - 1...  
			if (primeIndex % numColumns == numColumns - 1)
				file << endl;
			
			primeIndex++;
		}
		
		index++;
	}
	
	file.close();
}
