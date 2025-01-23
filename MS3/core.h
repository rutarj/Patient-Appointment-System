/*
*****************************************************************************
                     Milestone 3
Full Name  : Rutarj Shah 

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

// SAFE-GUARD: 
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// Copy your work done from Milestone #2 (core.h) into this file
// 
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);



//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//returns an integer and receives no arguments
int inputInt(void);

//returns an integer and receives no arguments
int inputIntPositive(void);

//return an integer and receives two arguments 
int inputIntRange(int lowerBound, int upperBound);

//return a single character value and receives one argument
char inputCharOption(const char charactersList[]);

//deosnot return a value, but does return a C string via the 1st argument parameter pointer and receives three arguments
void inputCString(char* stringC, int minChar, int maxChar);

//doesnot return a value and receives one argument
void displayFormattedPhone(const char* mobilestringC);

//deosnot return a value, but does return a C string via the 1st argument parameter pointer and receives three arguments
void inputCstring(char* stringC, int minChar, int maxChar);



// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H
