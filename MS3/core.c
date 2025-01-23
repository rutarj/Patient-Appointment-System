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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>

#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//

//returns an integer and receives no arguments
int inputInt(void)
{
    int number;
    char character;
    do
    {
        scanf("%d%c", &number, &character);
        if (character != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");


        }

    } while (character != '\n');

    return number;

}

//returns an integer and receives no arguments
int inputIntPositive(void)
{

    int posNumber;

    do
    {

        posNumber = inputInt();
        if (posNumber <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }

    } while (posNumber <= 0);

    return posNumber;


}

//return an integer and receives two arguments
int inputIntRange(int lowerBound, int upperBound)
{
    int number;

    do
    {
        number = inputInt();
        if (number > upperBound || number < lowerBound)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        }

    } while (number > upperBound || number < lowerBound);

    return number;
}

//return a single character value and receives one argument
char inputCharOption(const char charactersList[])
{
    char letter;
    int i, flag = 1;
    char anotherChar;


    do {

        scanf("%c%c", &letter, &anotherChar);



        if (anotherChar != '\n')
        {
            clearInputBuffer();
            printf("ERROR: Character must be one of [%s]: ", charactersList);

        }



        else {
            for (i = 0; charactersList[i] != '\0'; i++)
            {
                if (letter == charactersList[i])
                {
                    flag = 0;
                }
            }
            if (flag == 1) {
                printf("ERROR: Character must be one of [%s]: ", charactersList);
            }
        }


    } while (flag == 1);

    return letter;

}

//deosnot return a value, but does return a C string via the 1st argument parameter pointer and receives three arguments

void inputCString(char* stringC, int minChar, int maxChar)
{
    char inputString[123];
    int length = 0;
    int flag = 1;
    int i;


    do {

        scanf("%[^\n]", inputString);
       
        clearInputBuffer();

       /* for (length = 0; inputString[length] != '\0'; length++)
        {
            ;
        }*/
        length = strlen(inputString);

        if (minChar == maxChar && length != minChar)
        {
            printf("ERROR: String length must be exactly %d chars: ", minChar);
        }

        else if (length > maxChar)
        {
            printf("ERROR: String length must be no more than %d chars: ", maxChar);
        }

        else if (length < minChar)
        {
            printf("ERROR: String length must be between %d and %d chars: ", minChar, maxChar);
        }

        else if (length <= maxChar && length >= minChar)
        {
            for (i = 0; inputString[i]!='\0'; i++)
            {
                stringC[i] = inputString[i];

            }
            stringC[i] = '\0';
            flag = 0;

        }
    } while (flag == 1);


    return;

}







//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

//doesnot return a value and receives one argument
void displayFormattedPhone(const char* mobilestringC)
{
    int length;
    int i = 0, j;
    int check = 1;
    int flag = 0;
    if (mobilestringC == NULL)
    {
        printf("(___)___-____");
    }
    else {
        for (length = 0; mobilestringC[length] != '\0'; length++)
        {
            ;
        }
        if (length != 10)
        {
            printf("(___)___-____");
        }



        else {

            for (j = 0; j < length && flag == 0; j++)
            {
                if (mobilestringC[j] >= '0' && mobilestringC[j] <= '9')
                {

                    check = 0;
                }
                else
                {
                    check = 1;
                    flag = 1;

                }

            }


            if (check == 0)
            {
                printf("(");
                while (i < 3)
                {
                    printf("%c", mobilestringC[i]);
                    i++;
                }
                printf(")");

                while (i < 6)
                {
                    printf("%c", mobilestringC[i]);
                    i++;
                }
                printf("-");

                while (i < 10)
                {
                    printf("%c", mobilestringC[i]);
                    i++;
                }
            }
            else
            {
                printf("(___)___-____");

            }
        }
    }

    return;
}

//deosnot return a value, but does return a C string via the 1st argument parameter pointer and receives three arguments
void inputCstring(char* stringC, int minChar, int maxChar)
{
    char inputString[123];
    int length = 0;
    int flag = 1;
    int i;


    do {

        scanf("%[^\n]", inputString);
        clearInputBuffer();

        for (length = 0; inputString[length] != '\0'; length++)
        {
            ;
        }

        if (minChar == maxChar && length != minChar)
        {
            printf("Invalid %d-digit number! Number: ", minChar);
        }

        else if (length > maxChar)
        {
            printf("Invalid %d-digit number! Number: ", minChar);
        }

        else if (length < minChar)
        {
            printf("Invalid %d-digit number! Number: ", minChar);
        }

        else if (length <= maxChar && length >= minChar)
        {
            for (i = 0; i < length; i++)
            {
                stringC[i] = inputString[i];

            }
            flag = 0;

        }
    } while (flag == 1);

}
