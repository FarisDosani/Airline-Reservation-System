<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:0f172a,50:1d4ed8,100:06b6d4&height=165&section=header&text=Airline%20Reservation%20System&fontSize=34&fontColor=ffffff&fontAlignY=36&desc=C%2B%2B%20Console%20Booking%20Application&descAlignY=58&descSize=15" alt="Airline Reservation System" width="100%" />

**A Windows console application for browsing schedules and recording passenger reservations.**

<img src="https://img.shields.io/badge/C%2B%2B-Console%20Application-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++" />
<img src="https://img.shields.io/badge/Storage-Text%20Files-06B6D4?style=for-the-badge" alt="Text-file storage" />
<img src="https://img.shields.io/badge/Platform-Windows-0078D4?style=for-the-badge&logo=windows&logoColor=white" alt="Windows" />

</div>

## Overview

This project simulates a small airline reservation desk in C++. Users can read a flight schedule, choose from five airlines, book one or more passengers on three routes from Karachi, select seats and meals, calculate the bill, and inspect seat availability for the active session.

Reservation details are appended to `reservations.txt`, while schedule information is read from `Flight_data.txt`.

## Features

- Schedule display from a text file.
- Five selectable airlines: PIA, Emirates, Air Blue, Qatar Airways, and Serene Airlines.
- Routes from Karachi to Lahore, Islamabad, and Skardu.
- Passenger name, age, phone, gender, seat, and meal capture.
- Route- and airline-based ticket calculation.
- Passenger summary and active-session seat report.
- Reservation logging through C++ file streams.
- Menu inheritance through `Menu : public Airlines`.

## Project Structure

```text
Airline-Reservation-System/
├── ARS.cpp            # Application source
├── Flight_data.txt    # Displayed schedule data
├── reservations.txt   # Appended booking records
├── ARS.exe            # Included Windows executable
└── README.md
```

## Build and Run

The source uses `windows.h` for console colors, so it is intended for Windows.

```powershell
git clone https://github.com/FarisDosani/Airline-Reservation-System.git
cd Airline-Reservation-System

g++ -std=c++17 ARS.cpp -o ARS.exe
.\ARS.exe
```

Keep `Flight_data.txt` in the working directory. The application creates or appends to `reservations.txt` when passengers are booked.

## Usage

1. Select **Flight Schedule** to view the current text-based schedule.
2. Select **Make Reservation** and choose an airline.
3. Enter the destination and passenger count.
4. Provide passenger, seat, and meal details.
5. Review the calculated bill and passenger list.
6. Use **Seat Status** to view booked and remaining seats for the current run.

> Seat status is maintained in memory for the active session. Existing reservation records are logged but are not reloaded into seat availability on startup.

---

<div align="center">

<a href="https://github.com/FarisDosani/Airline-Reservation-System">View repository</a>

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:0f172a,50:1d4ed8,100:06b6d4&height=80&section=footer" alt="" width="100%" />

</div>
