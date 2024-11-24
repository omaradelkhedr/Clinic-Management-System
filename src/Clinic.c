/******************************************************************************
 *
 * Project: Clinic Management System
 *
 * File Name: Clinic.c
 *
 * Description: Source file containing clinic-related functions for the system.
 *
 * Author: Omar Khedr
 ******************************************************************************/
#include "../inc/Clinic.h" /* Includes the Clinic header file for required definitions and functions */

/* Static array to store the details of slots */
static Slots slots[MAXIMUM_SLOTS];

/* Initializes the slots with default values and names */
void initSlots(void)
{
    /* Slot 0: Initializes slot details for the time range "2pm to 2:30pm" */
    slots[0].isReserved = 0; /* Slot is not reserved */
    slots[0].patientID = 0; /* No patient is associated */
    strcpy(slots[0].slotName,"2pm    to 2:30pm"); /* Copies the slot name */
    slots[0].slotName[strlen("2pm    to 2:30pm")] = '\0'; /* Ensures null termination */

    /* Slot 1: Initializes slot details for the time range "2:30pm to 3pm" */
    slots[1].isReserved = 0;
    slots[1].patientID = 0;
    strcpy(slots[1].slotName,"2:30pm to 3pm   ");
    slots[1].slotName[strlen("2:30pm to 3pm   ")] = '\0';

    /* Slot 2: Initializes slot details for the time range "3pm to 3:30pm" */
    slots[2].isReserved = 0;
    slots[2].patientID = 0;
    strcpy(slots[2].slotName,"3pm    to 3:30pm");
    slots[2].slotName[strlen("3pm    to 3:30pm")] = '\0';

    /* Slot 3: Initializes slot details for the time range "4pm to 4:30pm" */
    slots[3].isReserved = 0;
    slots[3].patientID = 0;
    strcpy(slots[3].slotName,"4pm    to 4:30pm");
    slots[3].slotName[strlen("4pm    to 4:30pm")] = '\0';

    /* Slot 4: Initializes slot details for the time range "4:30pm to 5pm" */
    slots[4].isReserved = 0;
    slots[4].patientID = 0;
    strcpy(slots[4].slotName,"4:30pm to 5pm   ");
    slots[4].slotName[strlen("4:30pm to 5pm   ")] = '\0';
}

/* Displays the status of all slots (Reserved/Available) */
void displaySlots(void)
{
    printf("**********Available Slots**********\n");
    u8 iterator;

    /* Iterates through all the slots to display their reservation status */
    for(iterator = 0; iterator < MAXIMUM_SLOTS; iterator++)
    {
        if(slots[iterator].isReserved == 1) /* Checks if the slot is reserved */
        {
            printf("%d]Slot: %s is Reserved\n", iterator, slots[iterator].slotName);
        }
        else /* Slot is available */
        {
            printf("%d]Slot: %s is Available\n", iterator, slots[iterator].slotName);
        }
    }
    printf("***********************************\n\n");
}

/* Displays all reserved slots and their associated patient IDs */
void displayReservations(void)
{
    printf("**********Reserved Slots**********\n");
    u8 iterator;

    /* Iterates through all slots to display reserved ones */
    for(iterator = 0; iterator < MAXIMUM_SLOTS; iterator++)
    {
        if(slots[iterator].isReserved == 1) /* Checks if the slot is reserved */
        {
            printf("Slot %s is Reserved for Patient with ID: %d\n", slots[iterator].slotName, slots[iterator].patientID);
        }
        else
        {
            continue; /* Continues to the next slot */
        }
    }
    printf("**********************************\n\n");
}

/* Reserves a specific slot for a given patient ID */
void reserveSlot(u8 slot, u32 id)
{
    slots[slot].isReserved = 1; /* Marks the slot as reserved */
    slots[slot].patientID = id; /* Associates the slot with the given patient ID */
}

/* Cancels the reservation for a specific patient ID */
void cancelReservation(u32 id)
{
    u8 iterator;

    /* Iterates through all slots to find the reservation with the given patient ID */
    for(iterator = 0; iterator < MAXIMUM_SLOTS; iterator++)
    {
        if (slots[iterator].patientID == id) /* Finds the matching reservation */
        {
            slots[iterator].isReserved = 0; /* Cancels the reservation */
            slots[iterator].patientID = 0; /* Clears the patient ID */
            break; /* Exits the loop once the reservation is canceled */
        }
        else
        {
            /* Do Nothing */
        }
    }

    /* Checks if no matching reservation was found */
    if(iterator == MAXIMUM_SLOTS)
    {
        printf("Invalid ID\n");
    }
    else
    {
        /* Do Nothing */
    }
}

/* Handles admin authentication by validating the entered password */
u8 authentication(void)
{
    u8 *password = "1234"; /* The predefined admin password */
    u8 returnValue = FALSE; /* Tracks whether authentication was successful */
    u8 entry[MAXIMUM_PASS_CHAR]; /* Buffer for the entered password */

    printf("Please Enter your Password: \n");
    gets(entry); /* Reads the entered password */

    /* Allows up to MAXIMUM_NUM_TRIALS for entering the correct password */
    u8 iterator;
    for(iterator = 0; iterator < MAXIMUM_NUM_TRIALS; iterator++)
    {
        if(strcmp(password, entry) == SUCCESFUL_TRIAL) /* Checks if the password matches */
        {
            printf("Authentication Granted!\n");
            returnValue = TRUE;
            break; /* Exits the loop if authentication is successful */
        }
        else /* Password does not match */
        {
            printf("Unsuccessful trial, please try again!\n");
            gets(entry); /* Prompts for another attempt */
        }
    }

    if(returnValue == TRUE) /* If authentication is successful */
    {
        /* Do Nothing */
    }
    else /* All trials exhausted */
    {
        printf("You Exceeded Maximum Number of Trials!\n");
    }

    return returnValue; /* Returns TRUE for success, FALSE otherwise */
}

/* Main Clinic Management System function */
void clinicSystem(void)
{
    printf("********* Welcome to Clinic Management System *********\n");
    patientNode* head = NULL; /* Linked list head for patients */
    u8 authenticated = FALSE; /* Tracks admin authentication status */
    u8 choice = 0; /* Stores the user's mode selection */
    u8 firstPatient = TRUE; /* Tracks if the first patient has been added */

    initSlots(); /* Initializes the reservation slots */

    while(1) /* Infinite loop for the system */
    {
        /* Prompts the user to select a mode */
        printf("1] Admin Mode\n2] User Mode\n");
        scanf("%d", &choice);
        fflush(stdin);

        if (choice == ADMIN_MODE) /* Enters Admin Mode */
        {
            while(1) /* Infinite loop for Admin Mode */
            {
                /* Handles admin authentication */
                if (authenticated == FALSE && authentication() == FALSE)
                {
                    printf("System is now closed.\n");
                    return; /* Exits the system if authentication fails */
                }
                authenticated = TRUE; /* Authentication successful */

                /* Displays admin options */
                printf("\nAdmin Mode:\n");
                printf("1] Add a New Patient\n2] Edit Patient Record\n");
                printf("3] Reserve a Slot with the Doctor\n4] Cancel Reservation\n");
                printf("5] Display Patients\n6] Exit Admin Mode\n");

                u8 adminChoice;
                scanf("%d", &adminChoice);
                fflush(stdin);

                switch (adminChoice)
                {
                    case ADD_PATIENT: /* Adds a new patient */
                    {
                        if(firstPatient == TRUE)
                        {
                            head = initPatient(); /* Initializes the first patient */
                            firstPatient = FALSE;
                        }
                        else
                        {
                            head = addPatient(head); /* Adds subsequent patients */
                        }
                        break;
                    }
                    case EDIT_PATIENT: /* Edits an existing patient record */
                    {
                        u32 patientID;
                        printf("Enter Patient ID to Edit: ");
                        scanf("%d", &patientID);
                        fflush(stdin);
                        editPatient(head, patientID);
                        break;
                    }
                    case RESERVE_SLOT: /* Reserves a slot for a patient */
                    {
                        displaySlots(); /* Displays available slots */
                        u8 slotNumber;
                        u32 patientID;
                        printf("Enter Slot Number (0-4): ");
                        scanf("%d", &slotNumber);
                        fflush(stdin);
                        printf("Enter Patient ID for Reservation: ");
                        scanf("%d", &patientID);
                        fflush(stdin);
                        if (findPatient(head, patientID) != NULL && slotNumber < MAXIMUM_SLOTS)
                        {
                            reserveSlot(slotNumber, patientID); /* Reserves the selected slot */
                            printf("Slot reserved successfully.\n");
                        }
                        else
                        {
                            printf("Invalid Slot or Patient ID.\n");
                        }
                        break;
                    }
                    case CANCEL_RESERVATION: /* Cancels a reservation */
                    {
                        u32 patientID;
                        printf("Enter Patient ID to Cancel Reservation: ");
                        scanf("%d", &patientID);
                        fflush(stdin);
                        cancelReservation(patientID); /* Cancels the reservation */
                        printf("Reservation canceled successfully.\n");
                        break;
                    }
                    case DISPLAY_PATIENTS: /* Displays all patient records */
                    {
                        displayPatient(head);
                        break;
                    }
                    case EXIT_ADMIN: /* Exits Admin Mode */
                    {
                        printf("Exiting Admin Mode...\n");
                        break;
                    }
                    default: /* Handles invalid input */
                    {
                        printf("Invalid choice. Try again.\n");
                    }
                }
                break; /* Exits the inner Admin Mode loop */
            }
        }
        else if(choice == USER_MODE) /* Enters User Mode */
        {
            /* Displays user options */
            printf("\nUser Mode:\n");
            printf("1] View Patient Record\n2] View Today's Reservations\n");
            printf("3] Exit User Mode\n");

            u8 userChoice;
            scanf("%d", &userChoice);
            fflush(stdin);

            switch (userChoice)
            {
                case PATIENT_RECORD: /* Views a patient's record */
                {
                    u32 patientID;
                    printf("Enter Patient ID to View Record: ");
                    scanf("%d", &patientID);
                    fflush(stdin);
                    patientNode* patient = findPatient(head, patientID);
                    if (patient != NULL)
                    {
                        /* Displays the patient record */
                        printf("**********Patient's Info**********\n");
                        printf("Patient's Name: %s\n", patient->data.name);
                        printf("Patient's Gender: %s\n", patient->data.gender);
                        printf("Patient's Age: %d\n", patient->data.age);
                        printf("Patient's ID: %d\n", patient->data.id);
                        printf("**********************************\n\n");
                    }
                    else
                    {
                        printf("No patient found with ID: %u\n", patientID);
                    }
                    break;
                }
                case TODAY_RESERVATIONS: /* Displays all reservations */
                {
                    displayReservations();
                    break;
                }
                case EXIT_USER: /* Exits User Mode */
                {
                    printf("Exiting User Mode...\n");
                    break;
                }
                default: /* Handles invalid input */
                {
                    printf("Invalid choice. Try again.\n");
                }
            }
        }
        else /* Handles invalid mode selection */
        {
            printf("Invalid mode selected. System closing...\n");
            break;
        }
    }
}
