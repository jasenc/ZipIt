/*
   The purpose of this program is to read information from a file,
   check the information for validity, prduce some output files and
   take some statistics along the way.

   Jasen Carroll
   CS171-064
   Zip_It!
   Assignment 5/Homework 5
   2/13/2010

   The program opens a tab-delimited text file that contains cities, 
   state abbreviations and zip codes. It will then check for errors
   in the zip code field. Making sure that it is either a 5 digit
   number or a hyphenated 9 digit number. If it is not in the
   correct formats, the program will then put the field in the
   correct formats. The program will also count the number of
   records in the file, display statistics and finally create two
   different output files. One being tab-delimited form and the
   other containing information solely for Pennsylvania. It also
   takes some statistics and prints the information on screen.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "jcc329_Library.h"
using namespace std;

void introduction() // Introduction, explains to the user what is going to happen.
{
	cout << "After entering your file name, the program will run. After completion there \n"
		"will be two output files made. The files will be named 'zipCodes_results.txt' \n"
		"containing all of the information and another file named 'PA_results.txt' \n"
		"containing just the results within the state of Pennsylvania. Finally, at the \n"
		"end of the program you will see ten statistics shown." << endl << endl;
}



bool validForm(string zipCode) // Function for checking if the zip  code is of proper form.
{
	const int X = zipCode.length(); // Takes the length of the zip code.
	if(X == 5 || X == 10) // If the zipcode has a length of 5 or 10 (with a hyphen) it is of correct length. 
	{
		return true;
	}
	else // If it has a length of anything else, then it is wrong.
	{
		return false;
	}
}

int main()
{
	introduction(); // Prints the introduction on screen
	string filename =promptForString(prompt); // Uses the function in jcc329_Library.h
	ifstream fin (filename.c_str()); // Creates input file from string
	ofstream fout ("zipCodes_results.txt"); // Creates output file
	ofstream pout ("PA_results.txt"); // Creates output file for PA only
	bool x = fin.is_open(); // Checks to make sure the file is open
	while (x == false) // If the program could not find the propgram it will ask you again.
	{
		cout << "Sorry your .txt could not be found. Please try again. \n" << 
			"Alternatively you could type QUIT to end the program." << endl;
		filename = promptForString(prompt);
		ifstream fin (filename.c_str()); 
		x = fin.is_open(); // Checks again to see if the input file could be found.
	}
	fout << "City" << "\t" << "State" << "\t" << "ZipCode" << endl; 
			// Prints a header for the output file containing all data.
	pout << "City" << "\t" << "State" << "\t" << "ZipCode" << endl; 
			// Prints a header for the output file containing only PA data.
	string line; // Creates a string for each line of the input file.
	int lSize = 0; // How many lines there are in the input file.
	int hSize = 0; // How many hyphen are in zip codes in the input file.
	int paSize = 0; // How many entries there are for Pennsylvania in the input file.
	int njSize = 0; // How many entries there are for New Jersey in the input file.
	int mdSize = 0; // How many entries there are for Maryland in the input file.
	int phSize = 0; // How many entries there are for Philadelphia in the input file.
	int zipSize = 0; // How many entries there are for 19104 in the input file.
	int bMSize = 0; // How many entries there are for Berlin, MD in the input file.
	int bNSize = 0; // How many entries there are for Berlin, NJ in the input file.
	int twoSize = 0; // How many entries there are for cities with more than one word in the input file.
					// The reason these were all intialized a head of time is because they needed to exist outside of the loops.		
	while(getline(fin, line)) 
	{
		lSize++; // Increments size by one for every line
		const int TAB = line.find("\t"); // Finds the first tab in the line
		const int TAB2 = line.find("\t", TAB+1); // Finds the second tab in the line
		string city = line.substr(0, TAB); // Extracts the city from the line
		string state = line.substr(TAB+1, 2); // Extracts the state from the line
		string zipCode = line.substr(TAB2+1); // Extracts the zip code from the line
		int hyphen = zipCode.find("-"); // Determines if and where a hypen is in the zipcode
		int space = city.find(" "); // Determines if and where a space is in a line
		if(hyphen >= 0) // If there is a hypen this increments the number of hyphens by one
		{
			hSize++;
		}
		bool correct = validForm(zipCode); // Uses the function for correct zip code length
		if(correct == false) // If the zipcode does not have the proper length a zero will be added in front
		{
			zipCode = "0" + zipCode;
		}
		if(state == "PA") // If the line is for Pennsylvania...
		{
			paSize++; // increments the count by one and...
			pout << city << "\t" << state << "\t" << zipCode << endl; 
					// addes these entries to a new file named 'PA_results.txt'
		}
		if(state == "NJ") // Counts the number of entries for New Jersey
		{
			njSize++;
		}
		if(state == "MD") // Counts the number of entries for Maryland
		{
			mdSize++;
		}
		if(city == "Philadelphia") // Counts the number of entires for Philadelphia
		{
			phSize++;
		}
		if(zipCode == "19104") // Counts the number of entries for 19104
		{
			zipSize++;
		}
		if(city == "Berlin" && state == "MD") // Counts the number of entries for Berlin, MD
		{
			bMSize++;
		}
		if(city == "Berlin" && state == "NJ") // Counts the number of entries for Berlin, NJ
		{
			bNSize++;
		}
		if(space >= 0) // Counts the number of entries for cities with more than one word, 
					   // by using the space integer already determinded
		{
			twoSize++;
		}
		fout << city << "\t" << state << "\t" << zipCode << endl; // Prints everything to 'zipCodes_results.txt'
	
	}
	cout << "1. There are " << lSize << " entries in the input file" << endl; 
			// Prints the number of lines in the input file
	cout << "2. There are " << hSize << " entries with a hyphenated zipcode" << endl; 
			// Prints the number of lines in the input file
	cout << "3. There are " << paSize << " entries involving Pennsylvania" << endl; 
			// Prints the number of lines in the input file
	cout << "4. There are " << njSize << " entries involving New jersey" << endl; 
			// Prints the number of lines in the input file
	cout << "5. There are " << mdSize << " entries involving Maryland" << endl; 
			// Prints the number of lines in the input file
	cout << "6. There are " << phSize << " entries involving Philadelphia" << endl; 
			// Prints the number of lines in the input file
	cout << "7. There are " << zipSize << " entries involving 19104 for the zip code" << endl; 
			// Prints the number of lines in the input file
	cout << "8. There are " << bMSize << " entries involving Berlin, MD" << endl; 
			// Prints the number of lines in the input file
	cout << "9. There are " << bNSize << " entries involving Berlin, NJ" << endl; 
			// Prints the number of lines in the input file
	cout << "10. There are " << twoSize << " entries involving cities with more than one word" << endl; 
			// Prints the number of lines in the input file

	fin.close();
	fout.close();
	pout.close();

	
	return 0;
}