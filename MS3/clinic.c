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


// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"

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
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
            menuAppointment(data);
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


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    int i = 0;
    int newPatientNumber = 0;
    int index = -1;
    for (i = 0; i < max && index == -1; i++)
    {
        if (patient[i].patientNumber == 0)
        {

            index = i;
        }
    }

    if (index == -1)
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
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max)
{
    int editNum = 0;
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
// (Copy your code from MS#2)
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


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData *data)
{
   
    int index;
    int i;
    int isAllRecords = 1;
    
    displayScheduleTableHeader(&data->appointments->date,isAllRecords);
    
    for (i = 0; i < data->maxAppointments; i++)
    {
        index = findPatientIndexByPatientNum(data->appointments[i].paientNumber,
            data->patients, data->maxPatient);

        if (index != -1)
        {
            displayScheduleData(&data->patients[index], &data->appointments[i], 1);
        }
        
    }
    printf("\n");



    return;

}


// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData *data)
{
    int i = 0;
    int monthDays = 0;
    int isAllRecords = 1;
    struct Date viewDate = { 0 };
    
    printf("Year        : ");
    viewDate.year = inputIntPositive();
    
    printf("Month (1-12): ");
    viewDate.month = inputIntRange(1, 12);

    //for months Jan-July
    if (viewDate.month >= 1 && viewDate.month <= 7)
    {
        if (viewDate.month % 2 == 0)        //for the month Feb
        {
            if (viewDate.month == 2)
            {
                if (viewDate.year % 4 == 0)             //leap year
                {
                    monthDays = 29;
                }
                else
                {
                    monthDays = 28;
                }
            }
            else
            {
                monthDays = 30;
            }
        }
        else if (viewDate.month % 2 != 0)
        {
            monthDays = 31;
        }
    }

    //for months Aug-Dec
    else {
        if (viewDate.month % 2 == 0)
        {
            monthDays = 31;
        }
        else
        {
            monthDays = 30;
        }
    }


    printf("Day (1-%d)  : ", monthDays);
    viewDate.day = inputIntRange(1, monthDays);

    printf("\n");
    displayScheduleTableHeader(&viewDate,!isAllRecords);
    sortAppts(data->appointments, 15);
    int index;
    for (i = 0; i < data->maxAppointments; i++)
    {
        if (data->appointments[i].date.day == viewDate.day && 
            data->appointments[i].date.month == viewDate.month && 
            data->appointments[i].date.year == viewDate.year)
        {
           
            index = findPatientIndexByPatientNum(data->appointments[i].paientNumber,
                data->patients, data->maxPatient);

            if (index != -1)
            {
                displayScheduleData(&data->patients[index], &data->appointments[i], !isAllRecords);
            }

            
        }
    }
    
    putchar('\n');
    
        
    return;
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appointments, int maxAppointments,
    struct Patient* patients, int maxPatient)
{
    int index = 0;
    int i = 0;
    int slotAvailable = 0;
    int patientNumber = 0;
    int check = 0;
    struct Date viewDate = { 0 };
    struct Time time = { 0 };
    int monthDays = 0;
    int isRepeated = 1;
    int flag = 1;
    int slot = 0;
    int flag2 = 1;

    for (i = 0; i < maxAppointments&&flag2==1; i++)
    {
        if (appointments[i].paientNumber < 1 )
        {
            slotAvailable = 1;
            flag2 = 0;
            
        }
    }
    if (slotAvailable == 1)
    {
        printf("Patient Number: ");
        patientNumber = inputIntPositive();
        check = findPatientIndexByPatientNum(patientNumber, patients, maxPatient);
        do {
            if (check != -1)
            {
                printf("Year        : ");
                viewDate.year = inputIntPositive();

                printf("Month (1-12): ");
                viewDate.month = inputIntRange(1, 12);

                //for months Jan-July
                if (viewDate.month >= 1 && viewDate.month <= 7)
                {
                    if (viewDate.month % 2 == 0)        //for the month Feb
                    {
                        if (viewDate.month == 2)
                        {
                            if (viewDate.year % 4 == 0)             //leap year
                            {
                                monthDays = 29;
                            }
                            else
                            {
                                monthDays = 28;
                            }
                        }
                        else
                        {
                            monthDays = 30;
                        }
                    }
                    else if (viewDate.month % 2 != 0)
                    {
                        monthDays = 31;
                    }
                }

                //for months Aug-Dec
                else {
                    if (viewDate.month % 2 == 0)
                    {
                        monthDays = 31;
                    }
                    else
                    {
                        monthDays = 30;
                    }
                }


                printf("Day (1-%d)  : ", monthDays);
                viewDate.day = inputIntRange(1, monthDays);

                inputCorrectTime(&time);      //prompt user to input the desired time of appointment
                

                //need to loop all the appointments and see if the user entered appointment 
               //to check if the entered appointment matches any other record in the actual
               // if it does, print ERROR line 457
                flag = 1;
                i = 0;
                for (i = 0; i < maxAppointments && flag==1; i++)
                {
                    if (appointments[i].date.day == viewDate.day &&
                        appointments[i].date.month == viewDate.month &&
                        appointments[i].date.year == viewDate.year &&
                        appointments[i].time.hour == time.hour &&
                        appointments[i].time.min == time.min)
                    {
                        printf("\nERROR: Appointment timeslot is not available!\n");
                        printf("\n");
                        flag = 0;
                    }

                }
                if (flag != 0)
                {
                    int available = 0;
                    do {
                        
                        
                        if (((time.hour >= MIN_HOUR) && (time.hour <= MAX_HOUR)) && ((time.min ==
                            INTERVAL) || (time.min == 0)))
                        {
                            if ((time.hour == MAX_HOUR) && (time.min == INTERVAL))
                            {
                                printf("ERROR: Time must be between 10:00 and 14:00 in 30 minute intervals.\n\n");
                                inputCorrectTime(&time);   //user will be directed to re-enter the time everytime he enters the appointment time which is not currently available 
                                
                           }
                            else
                            {
                                available = 1;
                                
                            }

                        }
                        else
                        {
                            printf("ERROR: Time must be between 10:00 and 14:00 in 30 minute intervals.\n\n");
                            inputCorrectTime(&time);
                            
                        }
                       

                    } while (available == 0);

                    isRepeated = 0;
                }
            

                
            }            
        }while (isRepeated==1);

        printf("\n*** Appointment scheduled! ***\n\n");
        

       


        for (i = 0; slot==0 && i < maxAppointments; i++)
        {
            if (appointments[i].paientNumber == 0)
            {
                index = i;
                slot = 1;
                
            }
        }
        
        appointments[index].paientNumber = patientNumber;
        appointments[index].date.day = viewDate.day;
        appointments[index].date.month = viewDate.month;
        appointments[index].date.year = viewDate.year;
        appointments[index].time.hour = time.hour;
        appointments[index].time.min = time.min;
        sortAppts(appointments, maxAppointments);
    }


    else
    {
        printf("Appointments Full!!\n");
    }
    
    
    return;

    
}



// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appointments, int maxAppointments,
    struct Patient* patients, int maxPatient)
{
    struct Date viewDate = { 0 };
    int monthDays = 0;
    int index = 0;
    int patientNumber = 0;
    int i = 0;
    
    char confirmation=0;
    int indexToBeDeleted = 0;
    int flag = 1;

    printf("Patient Number: ");
    patientNumber = inputIntPositive();
    index = findPatientIndexByPatientNum(patientNumber, patients, maxPatient);

    if (index == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
    }
    else
    {
        printf("Year        : ");
        viewDate.year = inputIntPositive();

        printf("Month (1-12): ");
        viewDate.month = inputIntRange(1, 12);

        //for months Jan-July
        if (viewDate.month >= 1 && viewDate.month <= 7)
        {
            if (viewDate.month % 2 == 0)        //for the month Feb
            {
                if (viewDate.month == 2)
                {
                    if (viewDate.year % 4 == 0)             //leap year
                    {
                        monthDays = 29;
                    }
                    else
                    {
                        monthDays = 28;
                    }
                }
                else
                {
                    monthDays = 30;
                }
            }
            else if (viewDate.month % 2 != 0)
            {
                monthDays = 31;
            }
        }

        //for months Aug-Dec
        else {
            if (viewDate.month % 2 == 0)
            {
                monthDays = 31;
            }
            else
            {
                monthDays = 30;
            }
        }


        printf("Day (1-%d)  : ", monthDays);
        viewDate.day = inputIntRange(1, monthDays);

        putchar('\n');
        displayPatientData(&patients[index], FMT_FORM);

        printf("Are you sure you want to remove this appointment (y,n): ");
        confirmation = inputCharOption("yn");
        putchar('\n');

        if (confirmation == 'y')
        {
            
            for (i = 0; i < maxAppointments && flag==1; i++)
            {
                if (appointments[i].paientNumber==patientNumber && appointments[i].date.day == viewDate.day && appointments[i].date.month == viewDate.month &&
                    appointments[i].date.year == viewDate.year)
                {
                    indexToBeDeleted = i;
                   
                    flag = 0;
                }
                
            }
            
            
            appointments[indexToBeDeleted].paientNumber = 0;
            appointments[indexToBeDeleted].date.year = 0;
            appointments[indexToBeDeleted].date.month = 0;
            appointments[indexToBeDeleted].date.day = 0;

            printf("Appointment record has been removed!\n\n");
        }

    }


    return;

}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i;
    char enteredNumber[PHONE_LEN + 1] = { '\0' };
    int check = 0;
    printf("\nSearch by phone number: ");
    inputCString(enteredNumber, PHONE_LEN, PHONE_LEN);
    putchar('\n');
    displayPatientTableHeader();



    for (i = 0; i < max; i++)
    {
        if (strcmp(enteredNumber, patient[i].phone.number) == 0)
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
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i = 0;
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
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i, index = patientNumber;
    int passingValue = 0;
    int flag = 1;

    for (i = 0; i < max && flag == 1; i++)
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

//sort all the records by date and time 
void sortAppts(struct Appointment appoints[], int num)
{
    int i, index;
    struct Appointment temp[50] = { {0} };
   
    for (i=0;i<num;i++)
        {
            index = findLowsetAppts(appoints, num);
            temp[i].paientNumber = appoints[index].paientNumber;
            temp[i].date.year = appoints[index].date.year;
            temp[i].date.month = appoints[index].date.month;
            temp[i].date.day = appoints[index].date.day;
            temp[i].time.hour = appoints[index].time.hour;
            temp[i].time.min = appoints[index].time.min;

            //to make sure that the loop doesn't check for this index record we need to remove it
            appoints[index].paientNumber = 0;   
       }

    //after emptying the appoints list we need to transfer sorted data from the temp list to our original list

    for (i = 0; i < num; i++)
    {
        appoints[i].paientNumber = temp[i].paientNumber;
        appoints[i].date.year = temp[i].date.year;
        appoints[i].date.month = temp[i].date.month;
        appoints[i].date.day = temp[i].date.day;
        appoints[i].time.hour = temp[i].time.hour;
        appoints[i].time.min = temp[i].time.min;
    }

    return;
}
//find the index of the lowest appointment
int findLowsetAppts(struct Appointment appoints[], int num)
{
    

        int i, index=0;
        int lowestYear = 999999;
        int lowestMonth = 12;
        int lowestDay = 31;
        int lowestHour = 24;
        int lowestMin = 60;

        // find lowest year
        for (i = 0; i < num; i++)
        {
            if (appoints[i].date.year < lowestYear && appoints[i].paientNumber != 0)
            {
                lowestYear = appoints[i].date.year;
            }
        }

        for (i = 0; i < num; i++)
        {
            if (appoints[i].date.year == lowestYear && appoints[i].date.month < lowestMonth && appoints[i].paientNumber != 0)
            {
                lowestMonth = appoints[i].date.month;
            }
        }

        for (i = 0; i < num; i++)
        {
            if (appoints[i].date.year == lowestYear && appoints[i].date.month == lowestMonth && appoints[i].date.day < lowestDay && appoints[i].paientNumber != 0)
            {
                lowestDay = appoints[i].date.day;
            }
        }

        for (i = 0; i < num; i++)
        {
            if (appoints[i].date.year == lowestYear && appoints[i].date.month == lowestMonth && appoints[i].date.day == lowestDay && appoints[i].time.hour < lowestHour && appoints[i].paientNumber != 0)
            {
                lowestHour = appoints[i].time.hour;
            }
        }

        for (i = 0; i < num; i++)
        {
            if (appoints[i].date.year == lowestYear && appoints[i].date.month == lowestMonth && appoints[i].date.day == lowestDay && appoints[i].time.hour == lowestHour && appoints[i].time.min < lowestMin && appoints[i].paientNumber != 0)
            {
                lowestMin = appoints[i].time.min;
                index = i;
            }
        }
        
        return index;
    
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    putchar('\n');
    inputPhoneData(&patient->phone);

}


// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone)
{
    int flag = 1;
    int phoneType = 0;

    int i = 0;

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
            inputCstring(phone->number, PHONE_LEN, PHONE_LEN);
            putchar('\n');

            for (i = 0; i < PHONE_LEN; i++)
            {
                if ((phone->number[i]) >= '0' && phone->number[i] <= '9')
                {
                    flag = 0;
                }
            }
        } while (flag == 1);
    }
}

//Get user input for available hours and minutes
void inputCorrectTime(struct Time* time)
{
    printf("Hour (0-23)  : ");
    time->hour = inputIntRange(0, 23);

    printf("Minute (0-59): ");
    time->min = inputIntRange(0, 59);
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    FILE* fp = NULL;
    int i = 0;
    int value = 1;
    
    fp = fopen(datafile, "r");
    if (fp != NULL)
    {
        while (fp != NULL && i < max && value > 0)
        {
        value = fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber,
            patients[i].name, patients[i].phone.description,
            patients[i].phone.number);
            
            i++;
        }
        fclose(fp);


    }
    if (i != max)
    {
        i--;
    }
    return i;
}


// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    FILE* fp = NULL;
    int i = 0;
    int value = 1;
    fp = fopen(datafile, "r");
    if (fp != NULL)
    {
        while (fp != NULL && i < max && value>0)
        {
            value = fscanf(fp, "%d,%d,%d,%d,%d,%d",&appoints[i].paientNumber,
                &appoints[i].date.year,&appoints[i].date.month,&appoints[i].date.day,
                &appoints[i].time.hour,&appoints[i].time.min);
            i++;
        }
        fclose(fp);
    }

if (i != max)
{
    i--;
}
    sortAppts(appoints, i);
    
    return i;
}
