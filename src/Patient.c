/******************************************************************************
 *
 * Project: Clinic Management System
 *
 * File Name: Patient.c
 *
 * Description: Source file containing patient-related functions for the system.
 *
 * Author: Omar Khedr
 ******************************************************************************/

#include "../inc/Patient.h"

/* Finds a patient in the linked list by their unique ID */
patientNode* findPatient(patientNode* head, u32 id) 
{
    patientNode* currentPatient = (patientNode*) malloc(sizeof(patientNode)); /* Allocates memory for a temporary pointer */
    patientNode* returnValue = NULL; /* Stores the result of the search */

    /* Checks if memory allocation failed */
    if (currentPatient == NULL) 
    {
        printf("findPatient function failure\n");
        returnValue = NULL;
    } 
    else 
    {
        currentPatient = head; /* Start searching from the head of the list */

        /* Checks if the list is empty */
        if (currentPatient == NULL) 
        {
            printf("List of patients is empty\n");
            returnValue = NULL;
        }

        /* Traverses the linked list */
        while (currentPatient != NULL) 
        {
            if (currentPatient->data.id == id) 
            { 
                /* Compares IDs to find the matching patient */
                returnValue = currentPatient; /* Returns the matched patient node */
                break;
            }
            currentPatient = currentPatient->next; /* Move to the next node */
        }
    }
    return returnValue; /* Returns the patient node if found, or NULL if not found */
}

/* Initializes the first patient in the linked list */
patientNode* initPatient(void) 
{
    patientData data; /* Stores patient information */
    patientNode* head = (patientNode*) malloc(sizeof(patientNode)); /* Allocates memory for the first node */

    /* Collects patient data from the user */
    printf("Enter Patient's Name: ");
    gets(data.name); 
    printf("Enter Patient's Gender: ");
    gets(data.gender);
    printf("Enter Patient's Age: ");
    scanf("%d", &data.age);
    printf("Enter Patient's ID: ");
    scanf("%d", &data.id);
    fflush(stdin); /* Clears input buffer */

    /* Checks if memory allocation for the node failed */
    if (head == NULL) 
    {
        printf("Failed to allocate memory for the first patient\n");
        return NULL;
    } 
    else 
    {
        head->data = data; /* Stores the collected data in the node */
        head->next = NULL; /* Sets the next pointer to NULL */
        printf("Patient Added Successfully\n");
    }
    return head; /* Returns the head of the list */
}

/* Displays all patient records in the linked list */
void displayPatient(patientNode* head) 
{
    if (head == NULL) 
    {
        printf("Invalid Patient Data\n");
    } 
    else 
    {
        patientNode* iterator = head; /* Starts from the head of the list */

        /* Traverses the list and prints each patient's data */
        while (iterator != NULL) 
        {
            printf("**********Patient's Info**********\n");
            printf("Patient's Name: %s\n", iterator->data.name);
            printf("Patient's Gender: %s\n", iterator->data.gender);
            printf("Patient's Age: %d\n", iterator->data.age);
            printf("Patient's ID: %d\n", iterator->data.id);
            printf("**********************************\n\n");
            iterator = iterator->next; /* Moves to the next node */
        }
    }
}

/* Adds a new patient to the linked list */
patientNode* addPatient(patientNode* head) 
{
    patientNode* currentPatient = (patientNode*) malloc(sizeof(patientNode)); /* Allocates memory for a new patient node */
    patientNode* returnValue = NULL; /* Stores the updated head of the list */
    patientData data; /* Temporarily stores the new patient's data */

    /* Checks if memory allocation for the new node failed */
    if (currentPatient == NULL) 
    {
        printf("Can't allocate memory for another patient\n");
    } 
    else 
    {
        /* Collects patient data from the user */
        printf("Enter Patient's Name: ");
        gets(data.name);
        fflush(stdin);
        printf("Enter Patient's Gender: ");
        gets(data.gender);
        fflush(stdin);
        printf("Enter Patient's Age: ");
        scanf("%d", &data.age);
        printf("Enter Patient's ID: ");
        scanf("%d", &data.id);
        fflush(stdin);

        /* Checks if the ID already exists in the list */
        if (findPatient(head, data.id) == NULL) 
        {
            currentPatient->data = data; /* Stores the data in the new node */
            currentPatient->next = head; /* Links the new node to the list */
            head = currentPatient; /* Updates the head of the list */
            printf("Patient Added Successfully\n");
            returnValue = head;
        } 
        else 
        {
            printf("Entry rejected as ID exists for another patient\n");
            free(currentPatient); /* Frees memory if the ID is not unique */
            returnValue = head; /* Keeps the list unchanged */
        }
    }
    return returnValue; /* Returns the updated head of the list */
}

/* Edits a patient's record in the linked list */
void editPatient(patientNode* head, int id) 
{
    patientNode* modifiedPatient = NULL;
    modifiedPatient = findPatient(head, id); /* Finds the patient by ID */

    /* Checks if the patient exists */
    if (modifiedPatient != NULL) 
    {
        u8 choice = 0; /* Stores the user's choice for modification */
        printf("What do you want to edit?\n1] Patient's Name\n2] Patient's Gender\n3] Patient's Age\n4] Patient's ID\n");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) 
        {
            case NAME_MODIFICATION: 
            {
                u8 iterator =0;
                u8 newName[MAXIMUM_NAME_CHAR]; /* Temporary storage for the new name */
                printf("Enter new Patient's Name: ");
                gets(newName);
                u8 lenNew = strlen(newName);
                strncpy(modifiedPatient->data.name,newName,lenNew); /* Updates the name */
                modifiedPatient->data.name[lenNew]='\0'; /* Ensures null termination */
                break;
            }
            case GENDER_MODIFICATION: 
            {
                u8 newGender[MAXIMUM_GENDER_CHAR]; /* Temporary storage for the new gender */
                printf("Enter new Patient's Gender: ");
                gets(newGender);
                u8 lenNew = strlen(newGender);
                strncpy(modifiedPatient->data.gender, newGender, lenNew); /* Updates the gender */
                modifiedPatient->data.gender[lenNew] = '\0'; /* Ensures null termination */
                break;
            }
            case AGE_MODIFICATION: 
            {
                printf("Enter new Patient's Age: ");
                scanf("%d", &modifiedPatient->data.age); /* Updates the age */
                fflush(stdin);
                break;
            }
            case ID_MODIFICATION: 
            {
                u32 newID = 0; /* Temporary storage for the new ID */
                printf("Enter new Patient's ID: ");
                scanf("%d", &newID);
                fflush(stdin);
                /* Check if ID already exists*/
                if (findPatient(head, newID) == NULL) 
                {
                    modifiedPatient->data.id = newID; /* Updates the ID */
                } 
                else 
                {
                    printf("Entry Rejected as ID exists for another Patient\n");
                }
                break;
            }
            default:
                printf("Invalid Choice\n");
                break;
            }
        } 
    else 
    {
        printf("There's no Patient with ID: %d\n", id);
    }
}



