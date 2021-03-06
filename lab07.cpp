//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//
// Name: Antonio Adame
// Date: October 27, 2016
// Class: CSCI 2380
// Semester: 
//
// Program Name: Lab 07
// Program Description: Counts digits in different bases
//  For instance 232223 has 4 2's in base 10, 15 has 4 1's in base 2
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

/*
For the binary, think through an example

11 mod 2 = 1, divide by 2
5 mod 2 = 1,  divide by 2
2 mod 2 = 0,  divide by 2
1 mod 2 = 1,  divide by 2
0

11 base 2 is 1011

For another base the process is similar
Take 14 base 3

14 mod 3 = 2, divide by 3
4 mod 3 = 1,  divide by 3
1 mod 3 = 1,  divide by 3
0

14 base 3 is 112

*/


#include<iostream>
using namespace std;


 
//This should return the number of 1's in the binary representation
//of the input number (in decimal) 
int CountBinOnes(int dec_number)
{

	int count = 0;

	//base check.
	if (dec_number <= 0)
		return 0;
	//recursive case.
	else if ((dec_number % 2) == 1) 
		count++;

	return count += CountBinOnes(dec_number / 2);

}


//This should return the number of 'digits' in the 'base' representation
//of the input number (in decimal)
//This only has to work for bases between 2-10 and digits 0-9
int CountBaseDigits(int dec_number, int base, int digit)
{

	int count = 0;

	//base case.
	if (dec_number <= 0) 
		return 0;
	//recursive case.
	else if ((dec_number % base) == digit) 
		count++;

	return count += CountBaseDigits(dec_number / base, base, digit);

}

//This should display the number in the 'base' representation
void PrintBaseDigits(int dec_number, int base)
{

	int num = 0;

	if (dec_number <= 0) 
		return;
	else {
		PrintBaseDigits(dec_number / base, base);
		cout << dec_number % base;
		return;
	}

}

//a shortcut function to do error checking and ensure we have an integer
void GetInput(int &input)
{
	//get inputs
	cin >> input;
	while (!cin)
	{
		cin.clear();
		cin.ignore(2000, '\n');
		cout << "Not a legal number" << endl;
		cout << "Again: ";

		cin >> input;
	}
}


//Main program
int main()
{
	int input_dec; //the main number in decimal
	int input_base; //the base
	int input_digit; //the digit we're counting

					 //get the input number
	cout << "Please enter a number > 0:";
	GetInput(input_dec);
	//get the base
	cout << "Enter a base:";
	GetInput(input_base);
	//get the digit to find in the representation
	cout << "Enter a digit:";
	GetInput(input_digit);

	//output the results
	cout << endl << "Number of 1's in binary:" << CountBinOnes(input_dec) << endl;
	cout << endl << "Number of " << input_digit << "'s in base " << input_base << ":";
	cout << CountBaseDigits(input_dec, input_base, input_digit) << endl;

	cout << "The number " << input_dec << " in base " << input_base << " is ";
	PrintBaseDigits(input_dec, input_base);
	cout << endl;

	return 0;
}