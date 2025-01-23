/*
*****************************************************************************
                     Milestone 2
Full Name  : Rutarj Shah

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

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




