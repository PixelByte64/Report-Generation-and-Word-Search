///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Lab04ADriver.cpp
// Date: October 24, 2019
// Programmer: Samir Williams            
//
// Description:
//    Generate a report based on input recieved from a text file.
//                                                                  
///////////////////////////////////////////////////////////////////////


#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include"grade.h"

using namespace std;
using namespace stdGrade;

//Function Prototypes
string convertToText(letter_grade grade);

int main() {
	ifstream inFile;
	ofstream outFile;
	string firstName;
	string lastName;
	string studentSSN;
	double test1 = 0;
	double test2 = 0;
	double test3 = 0;
	double test4 = 0;

	inFile.open("student_grades.txt", ios::in);
	outFile.open("student_final.txt", ios::out);

	if (inFile.is_open() && outFile.is_open()) {
		outFile.setf(ios_base::left);
		outFile << setw(14) << "LastName" << setw(14) << "FirstName" << setw(14) << "SSN" << setw(10) << "Test1"
			<< setw(10) << "Test2" << setw(10) << "Test3" << setw(10) << "Test4" << setw(10) << "FinalLetterGrade\n";
		while (!inFile.eof()) {
			inFile >> lastName >> firstName >> studentSSN >> test1 >> test2 >> test3 >> test4;

			outFile << setw(14) << lastName << setw(14) << firstName << setw(14) << studentSSN << setw(10) << test1
				<< setw(10) << test2 << setw(10) << test3 << setw(10) << test4
				<< setw(10) << convertToText(deriveGrade((test1 + test2 + test3 + test4) / 4)) << endl;
		}
	}
	inFile.close();
	outFile.close();
	//system("pause");
	return 0;
}

///////////////////////////////////////////////////////////////////////
//
// Function: convertToText                                          
//                                                                   
// Description:
//    Checks to see what grade is found using the enum in grade.h
//
// Parameters:  
//    grade : takes the enum type and checks to see which case it is 
//				equal to
//                                                       
// Returns:  
//    string : it returns a string based on the enum type given                
//                                            
///////////////////////////////////////////////////////////////////////

string convertToText(letter_grade grade) {
	switch (grade) {
		case A_PLUS:
			return "A+";
			break;
		case A:
			return "A";
			break;
		case A_MINUS:
			return "A-";
			break;
		case B_PLUS:
			return "B+";
			break;
		case B:
			return "B";
			break;
		case B_MINUS:
			return "B-";
			break;
		case C_PLUS:
			return "C+";
			break;
		case C:
			return "C";
			break;
		case C_MINUS:
			return "C-";
			break;
		case D_PLUS:
			return "D+";
			break;
		case D:
			return "D";
			break;
		case D_MINUS:
			return "D-";
			break;
		case F:
			return "F";
			break;
		default:
			return "Why are you here?";
			break;
	}
}

///////////////////////////////////////////////////////////////////////
//
// Function: deriveGrade                                          
//                                                                   
// Description:
//    Takes a double and returns an enum type based on the doubles value
//
// Parameters:  
//    avg : average grade of all the tests from the file             
//                                                       
// Returns:  
//    letter_grade : returns an enum type from grade.h based on avg               
//                                            
///////////////////////////////////////////////////////////////////////

letter_grade stdGrade::deriveGrade(double avg) {
	
	if (avg >= 97) {
		return A_PLUS;
	}
	else if (avg >= 93 && avg < 97) {
		return A;
	}
	else if (avg >= 90 && avg < 93) {
		return A_MINUS;
	}
	else if (avg >= 87 && avg < 90) {
		return B_PLUS;
	}
	else if (avg >= 83 && avg < 87) {
		return B;
	}
	else if (avg >= 80 && avg < 83) {
		return B_MINUS;
	}
	else if (avg >= 77 && avg < 80) {
		return C_PLUS;
	}
	else if (avg >= 73 && avg < 77) {
		return C;
	}
	else if (avg >= 70 && avg < 73) {
		return C_MINUS;
	}
	else if (avg >= 67 && avg < 70) {
		return D_PLUS;
	}
	else if (avg >= 63 && avg < 67) {
		return D;
	}
	else if (avg >= 60 && avg < 63) {
		return D_MINUS;
	}
	else {
		return F;
	}

}