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

#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"

//include the string functions' library 
#include <string.h>

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i = 0, count = 0;
    

    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            count++;
        }
    }
    
    if (count == 0)
    {
         printf("*** No records found ***\n\n");
    }

    putchar('\n');
        
}

// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void searchPatientData(const struct Patient patient[], int max)
{
    int number = 0;
    do {
        
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        number = inputIntRange(0, 2);
        if (number == 1)
        {
            searchPatientByPatientNumber(patient, max);
            suspend();
            
        }

        else if (number == 2)
        {
            searchPatientByPhoneNumber(patient, max);
            suspend();
        }

        else
        {
            putchar('\n');
        }

        
        
    } while (number != 0);

    

    return;


}
// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void addPatient(struct Patient patient[], int max)
{
    int i = 0;
    int newPatientNumber=0;
    int index = -1;
    for (i = 0; i < max && index == -1; i++)
    {
        if (patient[i].patientNumber == 0)
        {

            index = i;
        }
    }
        
    if(index==-1)
    {
        printf("ERROR: Patient listing is FULL!\n");
    }
    else
    {
        newPatientNumber = nextPatientNumber(patient, max);
        patient[index].patientNumber = newPatientNumber;
        inputPatient(&patient[index]);
        printf("*** New patient record added ***\n");
    }
    
    putchar('\n');


}
// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void editPatient(struct Patient patient[], int max)
{
    int editNum=0;
    int index = 0;
    printf("Enter the patient number: ");
    editNum = inputIntPositive();
    putchar('\n');

    index = findPatientIndexByPatientNum(editNum, patient, max);

    if (index != -1)
    {
        menuPatientEdit(&patient[index]);
    }
    else
    {
        printf("ERROR: Patient record not found!");
    }


}
// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void removePatient(struct Patient patient[], int max)
{
    int removeNum = 0;
    int index = 0;
    char selection;
    printf("Enter the patient number: ");
    removeNum = inputIntPositive();
    putchar('\n');

    index = findPatientIndexByPatientNum(removeNum, patient, max);

    if (index != -1)
    {
        displayPatientData(&patient[index], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        selection = inputCharOption("yn");
        
        
        if (selection == 'y')
        {
            patient[index].patientNumber = 0;
            strcpy(patient[index].name, "");
            strcpy(patient[index].phone.description, "");
            strcpy(patient[index].phone.number, "");
            printf("Patient record has been removed!\n\n");
        }

        else
        {
            printf("Operation aborted.\n\n");
            
        }


    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }

    
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int number;
    int index;
    printf("\nSearch by patient number: ");
    number = inputIntPositive();
    putchar('\n');
    index = findPatientIndexByPatientNum(number, patient, max);

    if (index != -1)
    {
        displayPatientData(&patient[index], FMT_FORM);
    }
    else
    {
        printf("*** No records found ***\n");
    }

    putchar('\n');
    


}

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i;
    char enteredNumber[PHONE_LEN + 1]={'\0'};
    int check = 0;
    printf("\nSearch by phone number: ");
    inputCString(enteredNumber,PHONE_LEN,PHONE_LEN);
    putchar('\n');
    displayPatientTableHeader();
    
    
    
    for (i = 0; i<max; i++)
    {
        if (strcmp(enteredNumber,patient[i].phone.number) == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            check++;
        }
        
    }

    if (!check)
    {
        printf("\n*** No records found ***\n");
    }

    
    putchar('\n');

}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

int nextPatientNumber(const struct Patient patient[], int max)
{
    int i=0;
    int largestNumber = patient[0].patientNumber;
    int newPatientNumber = 0;
    
    for (i = 0; i < max; i++)
    {
        if (largestNumber < patient[i].patientNumber)
        {
            largestNumber = patient[i].patientNumber;
        }
    }
    newPatientNumber = largestNumber + 1;

    return newPatientNumber;
}

// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

int findPatientIndexByPatientNum(int patientNumber,const struct Patient patient[], int max)
{
    int i, index = patientNumber;
    int passingValue=0;
    int flag = 1;

    for (i = 0; i<max && flag==1; i++)
    {
        if (index == patient[i].patientNumber)
        {
            passingValue = i;
            flag = 0;

        }
        else
        {
            passingValue = -1;
        }
    }
        
    return passingValue;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n",patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    putchar('\n');
    inputPhoneData(&patient->phone);




}

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void inputPhoneData(struct Phone* phone)
{
    int flag = 1;
    int phoneType=0;
    
    int i=0;

    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    phoneType = inputIntRange(1, 4);
    putchar('\n');

    if (phoneType == 1)
    {
        strcpy(phone->description, "CELL");
       

    }

    else if (phoneType == 2)
    {
        strcpy(phone->description, "HOME");
    }

    else if (phoneType == 3)
    {
        strcpy(phone->description, "WORK");
    }

    else if (phoneType == 4)
    {
        strcpy(phone->description, "TBD");
        strcpy(phone->number, "\0");
        
    }

    
    if ((strcmp(phone->description, "TBD")) != 0)
    {
        printf("Contact: %s\n", phone->description);
        do {
            
            printf("Number : ");
            inputCString(phone->number, PHONE_LEN, PHONE_LEN);
            putchar('\n');

            for (i = 0; i < PHONE_LEN; i++)
            {
                if ((phone->number[i])>='0' && phone->number[i]<='9')
                {
                    flag = 0;
                }
            }
        } while (flag == 1);
    }
    
    

    


}