///////////////////////////////////////////////////////////////////////
//
// Header: grade.h                                          
//                                                                   
// Description:
//    Description of the class and its purpose         
//
//    List of data types:
//	  enum letter_grade
//
//    List of functions:
//	  dervieGrade
// 
///////////////////////////////////////////////////////////////////////

#pragma once

namespace stdGrade {
	enum letter_grade { A, A_PLUS, A_MINUS, B, B_PLUS, B_MINUS, C, C_PLUS, C_MINUS, D, D_PLUS, D_MINUS, F };
	letter_grade deriveGrade(double);
}



