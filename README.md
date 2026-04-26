# Airline Reservation System

A console-based backend application developed in C++ that handles the core operations of flight booking, passenger management, and scheduling. It utilizes Object-Oriented Programming (OOP) principles and file handling to simulate a real-world airline reservation desk.

## 🌟 Key Features
* **Flight Scheduling:** Displays real-time departure, arrival, and cost data for multiple airlines (PIA, Emirates, Air Blue, Qatar Airways, Serene Airlines).
* **Reservation Desk:** Allows users to book flights from Karachi to Lahore, Islamabad, or Skardu, capturing passenger details, seat selection, and meal preferences.
* **Automated Billing:** Calculates dynamic ticket pricing based on the selected airline and destination.
* **Data Logging:** Utilizes C++ `fstream` to persistently read flight data from text files and log successful passenger bookings into a reservations database.
* **Seat Management:** Tracks the status of booked versus remaining seats for active sessions.

## 🛠️ Tech Stack
* **Language:** C++
* **Concepts:** Object-Oriented Programming (Inheritance), File I/O, Exception Handling
* **Environment:** Windows Console (`windows.h` used for UI color formatting)

## 📁 Repository Structure
* `ARS.cpp`: The main source code containing the `Airlines` and `Menu` classes, and the execution logic.
* `Flight_data.txt`: The database file used by the program to display flight schedules and pricing. 
* `reservations.txt`: The output log file where passenger booking records are stored.

## 🚀 How to Run Locally

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/FarisDosani/Airline-Reservation-System.git](https://github.com/FarisDosani/Airline-Reservation-System.git)
