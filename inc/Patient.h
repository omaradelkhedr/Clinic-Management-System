/******************************************************************************
 *
 * Project: Clinic Management System
 *
 * File Name: Patient.h
 *
 * Description: Header file containing patient-related functions for the system.
 *
 * Author: Omar Khedr
 ******************************************************************************/
#ifndef _PATIENT_H_ /* Header guard to prevent multiple inclusions of the file */
#define _PATIENT_H_

/* Inclusion of standard libraries and custom type definitions */
#include <stdlib.h> /* For memory allocation functions */
#include <stdio.h>  /* For input/output operations */
#include <string.h> /* For string manipulation functions */
#include "STD_TYPES.h" /* Custom type definitions (e.g., u8, u32) */

/* Constants and macro definitions */

/* Maximum number of characters allowed for a patient's name */
#define MAXIMUM_NAME_CHAR   (u8)25

/* Maximum number of characters allowed for a patient's gender */
#define MAXIMUM_GENDER_CHAR (u8)10

/* Option to modify a patient's name */
#define NAME_MODIFICATION (u8)1

/* Option to modify a patient's gender */
#define GENDER_MODIFICATION (u8)2

/* Option to modify a patient's age */
#define AGE_MODIFICATION (u8)3

/* Option to modify a patient's ID */
#define ID_MODIFICATION (u8)4

/* Structure to store patient data */
typedef struct
{
    u32 id; /* Unique ID for the patient */
    u32 age; /* Age of the patient */
    u8 name[MAXIMUM_NAME_CHAR]; /* Name of the patient */
    u8 gender[MAXIMUM_GENDER_CHAR]; /* Gender of the patient */
} patientData;

/* Node structure for the linked list of patients */
typedef struct 
{
    patientData data; /* Data field storing patient information */
    struct patientNode * next; /* Pointer to the next node in the list */
} patientNode;

/* Function declarations */

/* Initializes and returns a pointer to the first patient node */
patientNode* initPatient(void);

/* Displays all patient records in the linked list */
void displayPatient(patientNode * head);

/* Adds a new patient to the linked list */
patientNode* addPatient(patientNode * head);

/* Edits an existing patient's record in the linked list */
void editPatient(patientNode * head, int id);

/* Searches for a patient in the linked list by their unique ID */
patientNode* findPatient(patientNode* head, u32 id);

#endif /* End of header guard _PATIENT_H_ */
