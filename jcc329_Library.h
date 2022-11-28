 /**
    @file jcc329_Library.h.cpp
    @author Jasen Carroll
    @date 02-13-2010
    @version 1.0 
 */

 /* Copyright 2010 Jasen Carroll */

 /**
    This fuction allows the user to input a string. This can be very useful and time saving.    
    @param prompt This is the string that will be created.   
    @return returns the string that was created.
 */

#include <string>
using namespace std;

	string prompt; // Creates the sting named prompt so it can be used globally.
	static string promptForString(string prompt) // Funtion that prompts for a string.
	{
		cout << "Please enter your input file: "; // Asks the user to input a string.
		getline(cin, prompt); // Uses getline in case the user inputs more than one word.
		if (prompt == "QUIT")
		{
			exit(1);
		}
		
		return prompt; // Returns the string so it can be used in other programs instead of just terminating the string.
	}

