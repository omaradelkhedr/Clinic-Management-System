# Clinic Management System

A Simple Clinic Management System implemented in C for Managing Patient Records, Doctor Appointments, and Admin/User access.

## Features
1. **Admin Mode**:
   - Add new patient records with unique IDs.
   - Edit existing patient information.
   - Reserve time slots with the doctor.
   - Cancel reservations.

2. **User Mode**:
   - View individual patient records.
   - View today's reservations.

3. **Secure Access**:
   - Admin mode is protected with a password and allows up to 3 login attempts.

## System Design
The system is divided into modules:
- **Admin Features**: Handles patient records and slot reservations.
- **User Features**: Provides read-only access to view records and reservations.
- **Authentication**: Ensures only authorized access to admin features.

### Slot Reservation Design:
- **Available Slots**:
  - 2:00 PM - 2:30 PM
  - 2:30 PM - 3:00 PM
  - 3:00 PM - 3:30 PM
  - 4:00 PM - 4:30 PM
  - 4:30 PM - 5:00 PM
- Slots are marked reserved once booked and can be canceled to free them.

## Technologies Used
- **Programming Language**: C
- **Data Structures**: Linked lists, arrays
- **Tools**: GCC Compiler, Makefile (optional)
- **Concepts**:
  - Authentication workflow
  - Dynamic memory management
  - CRUD operations
  - Time slot management
 
  
## Getting Started

### Prerequisites
- A C compiler (e.g., GCC)
- Basic knowledge of the terminal/command line

### Compilation
To compile the project:
```bash
gcc src/*.c -o Clinic_System.exe
```

### Running the Program
```bash
./Clinic_System.exe
```

### Example Usage
1. Admin Mode
- Enter 1 to choose Admin Mode.
  - Input the admin password (1234 by default).
- Select options:
  - Add a new patient record.
  - Edit patient details.
  - Reserve a time slot for a patient.
  - Cancel an existing reservation.
  - View all patients in the system.
  - Exit Admin Mode.
2. User Mode
- Enter 2 to choose User Mode.
- Select options:
  - View a patient’s record by entering their unique ID.
  - View the list of reserved time slots for the day.
  - Exit User Mode.


### Example Slots Table
| Slot Number | Time Range        | Status    |
|-------------|-------------------|-----------|
| 0           | 2:00 PM - 2:30 PM | Available |
| 1           | 2:30 PM - 3:00 PM | Reserved  |
| 2           | 3:00 PM - 3:30 PM | Available |
| 3           | 4:00 PM - 4:30 PM | Available |
| 4           | 4:30 PM - 5:00 PM | Reserved  |
