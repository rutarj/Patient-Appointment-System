
// Copy the below commented "header" section to all your source code files!

/*
*****************************************************************************
                     Milestone 1
Full Name  : Rutarj Shah 

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/





#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "core.h"

void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


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

    } while (posNumber<=0);

    return posNumber;

    
}

int inputIntRange(int lowerBound, int upperBound)
{
    int number;
    
    do
    {
        number = inputInt();
        if (number > upperBound || number < lowerBound)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ",lowerBound,upperBound);
        }

    } while (number > upperBound || number < lowerBound);
    
    return number;
}

char inputCharOption(const char charactersList[])
{
    char letter;
    int i, flag=1;
    char anotherChar;
    
    
    do {
        
        scanf("%c%c", &letter,&anotherChar);
        
        

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
       
        
    } while (flag==1);

    return letter;
    
}


void inputCString(char* stringC, int minChar, int maxChar)
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
            printf("ERROR: String length must be exactly %d chars: ",minChar);
        }

        else if (length > maxChar)
        {
            printf("ERROR: String length must be no more than %d chars: ",maxChar);
        }

        else if (length < minChar)
        {
            printf("ERROR: String length must be between %d and %d chars: ",minChar,maxChar);
        }

        else if (length<=maxChar && length>=minChar)
        {
            for (i = 0; i < length; i++)
            {
                stringC[i] = inputString[i];
                
            }
            flag = 0;
            
        }
    } while (flag==1);

    
    return;

}

void displayFormattedPhone(const char* mobilestringC)
{
    int length;
    int i = 0,j;
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

            for (j = 0; j < length&&flag==0; j++)
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

