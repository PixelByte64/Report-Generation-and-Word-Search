///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Lab04BDriver.cpp
// Date: October 24, 2019
// Programmer: Samir Williams            
//
// Description:
//    Searchs an input data file for a word specified by the user.
//                                                                  
///////////////////////////////////////////////////////////////////////

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<cctype>

using namespace std;

enum punctuation { 
	PERIOD = '.',
	QUESTION = '?',
	EXCLAMATION = '!',
	QUOTE = '\"',
	OPEN_PARA = '(',
	CLOSED_PARA = ')',
	COMMA = ',',
	SEMICOLON = ';',
	COLON = ':' 
};

//Function Prototypes
bool punctuationCheck(char charToCheck);
void processFile(ifstream& inFile, string& word, int& wordCount, int& nonVowelCount);
void displayResult(string word, int wordCount, int nonVowelCount);

int main() {
	ifstream inFile;
	string word;
	int wordCount = 0;
	int nonVowelCount = 0;

	cout << "Please enter the word you want to search for.\n";
	cin >> word;

	inFile.open("paragraph.dat", ios::in);
	
	if (inFile.is_open()) {
		processFile(inFile, word, wordCount, nonVowelCount);
		displayResult(word, wordCount, nonVowelCount);
	}
	
	inFile.close();
	system("pause");
	return 0;
}

///////////////////////////////////////////////////////////////////////
//
// Function: processFile()                                          
//                                                                   
// Description:
//    Iterates through the file and counts how many words are equal to 
//		the user input and how many characters are not vowels
//
// Parameters:  
//    &inFile  : File to parse through          
//    &word : User generated search input
//	  &wordCount : Variable to hold number of words that match search input
//	  &nonVowelCount : Variable to hold number of characters that are NOT vowels
//                                            
///////////////////////////////////////////////////////////////////////

void processFile(ifstream& inFile, string& word, int& wordCount, int& nonVowelCount) {
	string search;
	string tempString;

	while (!inFile.eof()) {
		inFile >> search;

		for (int i = 0; i < search.length(); i++) {
			if (!punctuationCheck(search[i])) {
				tempString += search[i];
			}
		}

		transform(tempString.begin(), tempString.end(), tempString.begin(), tolower);
		transform(word.begin(), word.end(), word.begin(), tolower);

		if (word == tempString) {
			wordCount++;
			tempString.clear();
		}else {
			tempString.clear();
		}

		for (int i = 0; i < search.length(); i++) {
			if (search[i] != 'a' || search[i] != 'e' || search[i] != 'i' || search[i] != 'o' || search[i] != 'u') {
				nonVowelCount++;
			}

		}
	}
}

///////////////////////////////////////////////////////////////////////
//
// Function: displayResult                                          
//                                                                   
// Description:
//    Display strings for the different parameters
//
// Parameters:  
//    word : User input word that was searched for          
//    wordCount : Counts how many times the word has been found
//	  nonVowelCount : counts the number of characters that are NOT vowels                
//                                            
///////////////////////////////////////////////////////////////////////

void displayResult(string word, int wordCount, int nonVowelCount) {
	cout << "The word \"" << word << "\" appears " << wordCount << " times\n";
	cout << "The number of characters that are not vowels is " << nonVowelCount << endl;
}

///////////////////////////////////////////////////////////////////////
//
// Function: punctuationCheck                                          
//                                                                   
// Description:
//    Checks to see if the character given is a punctuation or not
//		using enum punctuation defined on line 21
//
// Parameters:  
//     charToCheck : character used to check if it's a punctuation or not                       
//                                                       
// Returns:  
//    boolean : returns true if the character is found in the punctuation enum
//				returns false if the character is NOT found in the punctuation enum
//                                            
///////////////////////////////////////////////////////////////////////

bool punctuationCheck(char charToCheck) {
	switch ((charToCheck)){
	case PERIOD:
	case QUESTION:
	case EXCLAMATION:
	case QUOTE:
	case OPEN_PARA:
	case CLOSED_PARA:
	case COMMA:
	case SEMICOLON:
	case COLON:
		return true;
		break;
	default:
		return false;
		break;
	}
}