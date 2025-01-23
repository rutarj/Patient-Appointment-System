# Patient-Appointment-System
This system allows veterinary clinic staff to manage pet information, schedule and track appointments, and maintain appointment history using C language

Basic Patient Appointment System for Veterinary Clinic
This C-based system helps veterinary clinic staff efficiently manage patient (pet) details, schedule appointments, and maintain appointment history. Designed with three milestones, the system evolves in complexity while remaining user-friendly.

Milestone 1: Patient Contact Information Management
The first milestone focuses on storing and managing essential pet and owner details:

Owner Information: Name, contact number, and address.
Pet Information: Pet’s name, type (dog, cat, etc.), breed, age, and medical history.
Using structures and arrays, users can add, view, and update pet and owner details seamlessly.

Milestone 2: Appointment Scheduling
The second milestone introduces an intuitive appointment scheduling system, where clinic staff can:

Set appointment details: date, time, and visit type (checkup, vaccination, etc.).
Assign a veterinarian to each appointment.
Track appointment status (pending, completed, canceled).
The system stores appointment information and allows for easy scheduling and updates.

Milestone 3: Appointment Management & History
The final milestone adds comprehensive appointment management and history tracking:

View Upcoming Appointments: Clinic staff can easily access upcoming appointments.
Track Appointment History: Review past appointments and services rendered.
Search: Quickly find appointments by pet name, owner name, or date.
This stage includes added features like data validation, error handling, and file storage for patient and appointment data.

Key Features:
Contact Management: Store and retrieve pet and owner details effortlessly.
Scheduling System: Intuitive interface to schedule and manage appointments.
Appointment History: View past appointments and track pet health progress.
Data Persistence: Safely store patient and appointment data using file handling.
Appointment Scheduling: Intuitive scheduling system with easy-to-view time slots and veterinarian assignments.
Appointment History: Organized history of all appointments, making it easy to track the health progress of pets over time.
Data Storage: Persistence of patient and appointment data using file handling.




#include <stdio.h>
#include "clinic.h"

#define MAX_PETS 20
#define MAX_APPOINTMENTS 50

int main(void)
{
    struct Patient pets[MAX_PETS] = { {0} };
    struct Appointment appoints[MAX_APPOINTMENTS] = { {0} };
    struct ClinicData data = { pets, MAX_PETS, appoints, MAX_APPOINTMENTS };

    // Import patient and appointment records
    int patientCount = importPatients("patientData.txt", pets, MAX_PETS);
    int appointmentCount = importAppointments("appointmentData.txt", appoints, MAX_APPOINTMENTS);

    // Output imported records
    printf("Imported %d patient records...\n", patientCount);
    printf("Imported %d appointment records...\n\n", appointmentCount);

    // Show main menu for further actions
    menuMain(&data);
    
    return 0;
}

