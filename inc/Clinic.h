/******************************************************************************
 *
 * Project: Clinic Management System
 *
 * File Name: STD_TYPES.h
 *
 * Description: Header file defining standard data types for the system.
 *
 * Author: Omar Khedr
 ******************************************************************************/

#ifndef __CLINIC_H_ /* Header guard to prevent multiple inclusions of the file */
#define __CLINIC_H_

#include "Patient.h" /* Includes the Patient header file for required structures and functions */

/* Constants and macro definitions */

/* Maximum number of slots available for reservation */
#define MAXIMUM_SLOTS   (u8)5

/* Maximum number of characters allowed for the password */
#define MAXIMUM_PASS_CHAR   (u8)10

/* Maximum number of password trials allowed for authentication */
#define MAXIMUM_NUM_TRIALS  (u8)2

/* Indicates a successful trial (e.g., password match) */
#define SUCCESFUL_TRIAL     (u8)0

/* Boolean value for TRUE */
#define TRUE    (u8)1

/* Boolean value for FALSE */
#define FALSE   (u8)0

/* Mode selection for Admin */
#define ADMIN_MODE  (u8)1

/* Mode selection for User */
#define USER_MODE   (u8)2

/* Option to add a new patient */
#define ADD_PATIENT (u8)1

/* Option to edit an existing patient record */
#define EDIT_PATIENT    (u8)2

/* Option to reserve a slot with the doctor */
#define RESERVE_SLOT    (u8)3

/* Option to cancel a reservation */
#define CANCEL_RESERVATION  (u8)4

/* Option to display all patients */
#define DISPLAY_PATIENTS    (u8)5

/* Option to exit Admin Mode */
#define EXIT_ADMIN (u8)6

/* Option to view a specific patient's record */
#define PATIENT_RECORD  (u8)1

/* Option to view all today's reservations */
#define TODAY_RESERVATIONS  (u8)2

/* Option to exit User Mode */
#define EXIT_USER   (u8)3

/* Boolean value for YES */
#define YES (u8)1

/* Boolean value for NO */
#define NO  (u8)2

/* Structure definition for managing slots */
typedef struct 
{
    u8 isReserved; /* Indicates whether the slot is reserved (1 for reserved, 0 for available) */
    u32 patientID; /* Stores the ID of the patient who reserved the slot */
    u8 slotName[MAXIMUM_NAME_CHAR]; /* Stores the name/description of the slot */
} Slots;

/* Function declarations */

/* Initializes all the slots with default values */
void initSlots(void);

/* Displays all the slots and their reservation status */
void displaySlots(void);

/* Displays all the reserved slots and the associated patient IDs */
void displayReservations(void);

/* Reserves a specific slot for a patient ID */
void reserveSlot(u8 slot, u32 id);

/* Cancels the reservation for a specific patient ID */
void cancelReservation(u32 id);

/* Authenticates the admin by validating the password */
u8 authentication(void);

/* Main function to run the Clinic Management System */
void clinicSystem(void);

#endif /* End of header guard __CLINIC_H_ */
