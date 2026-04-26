#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>

using namespace std;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

#define size 100
int reserve = 999;

// Classes List
class Airline;
class menu;

// Creating Class For Airline Reservation System
class Airlines
{
public:
    // Declaring Data Members
    int to;
    string name[100];
    int age[100];
    long long int phone_number[100];
    char gender[100];
    int seat_number[100];
    int meal[100];
    int choice;
    int n = 0;
    int bill;

    // Declaring Member Functions
    void flight_schedule();
    void flight_details();
    void get_details(int n);
    void printdetails(int n);
    void billing(int n);
    void print_list(int n);
    void print_report(int n);
    void displayMenu();
};

// Inheritance::(Inherited Class Airlines By Class Menu)
class Menu : public Airlines
{
public:
    // Declaring Member Function
    void displayMenu();
};

// Function For Printing The Flights Schedule
void Airlines::flight_schedule()
{
    ifstream file("Flight_data.txt");
    string line;
    while (getline(file, line))
        cout << line << endl;
    file.close();
}

// Function For Printing The Available Flights
void Airlines::flight_details()
{
    cout << "Available Flights:\n\n";
    cout << "************************************************************\n";
    cout << "\t NAME OF FLIGHT      ACCESS CODE\n\n";
    cout << "\t PIA                 ------ [1]\n";
    cout << "\t EMIRATES            ------ [2]\n";
    cout << "\t AIR BLUE            ------ [3]\n";
    cout << "\t QATAR AIRWAYS       ------ [4]\n";
    cout << "\t SERENE AIRLINES     ------ [5]\n";
    cout << "************************************************************\n\n";
    cout << "Please Enter Your Flight Choice:: ";
    cin >> choice;

    try {
        if (choice < 1 || choice > 5) throw "Error";
    } catch (const char*) {
        cout << "Enter valid Choice\n";
    }

    switch (choice) {
        case 1: cout << "\n--- Welcome to PIA ---\n\n"; break;
        case 2: cout << "\n--- Welcome to EMIRATES ---\n\n"; break;
        case 3: cout << "\n--- Welcome to AIR BLUE ---\n\n"; break;
        case 4: cout << "\n--- Welcome to QATAR AIRWAYS ---\n\n"; break;
        case 5: cout << "\n--- Welcome to SERENE AIRLINES ---\n\n"; break;
    }
}

// Function For Getting The Details Of Passenger (with filing)
void Airlines::get_details(int n)
{
    // open reservations file in append mode
    ofstream reservFile("reservations.txt", ios::app);
    if (!reservFile) {
        cerr << "Warning: could not open reservations.txt for writing\n";
    }

    cout << "Please Enter Your Flight Destination Preference:\n\n";
    cout << "  KARACHI => LAHORE    ..... '1'\n";
    cout << "  KARACHI => ISLAMABAD ..... '2'\n";
    cout << "  KARACHI => SKARDU    ..... '3'\n\n";
    cout << "Enter Destination Choice :: ";
    cin >> to;
    cout << "\nENTER YOUR PERSONAL DETAILS:\n\n";

    for (int i = 1; i <= n; ++i)
    {
        cin.ignore();  // clear newline
        cout << "Enter the name of passenger " << i << " :: ";
        getline(cin, name[i]);

        cout << "Enter the age of passenger " << i << " :: ";
        cin >> age[i];
		cin.ignore();
        cout << "Enter the Phone Number of passenger " << i << " :: ";
        cin >> phone_number[i];
		cin.ignore();
        cout << "Enter the gender of passenger " << i << " (M/F) :: ";
        cin >> gender[i];
		cin.ignore();
        cout << "Please Enter the Seat Number for passenger " << i << " :: ";
        cin >> seat_number[i];
        while (seat_number[i] > size) {
            cout << "Invalid seat. Try again:: ";
            cin >> seat_number[i];
        }

        cout << "Please Enter Your Menu Preference:\n";
        cout << "  Biryani ..... '1'\n";
        cout << "  Salad   ..... '2'\n";
        cout << "  No meal ..... '3'\n";
        cout << "Enter Meal Choice :: ";
        cin >> meal[i];

        cout << "----------------------------------------------\n";
        cout << "\tRESERVATION COMPLETED\n";
        cout << "----------------------------------------------\n\n";

        // write this passenger's data to the file
        if (reservFile) {
            reservFile
                << "Passenger " << i
                << " | Name: " << name[i]
                << " | Age: " << age[i]
                << " | Phone: " << phone_number[i]
                << " | Gender: " << gender[i]
                << " | Seat: " << seat_number[i]
                << " | Meal code: " << meal[i]
                << "\n";
        }
    }

    if (reservFile) reservFile.close();
}

// Function For Printing The Details Of Passenger
void Airlines::printdetails(int n)
{
    cout << "\nTHE DETAILS OF PASSENGER:\n\n";
    static const char* flights[] = {
        "", "PIA", "EMIRATES", "AIR BLUE", "QATAR AIRWAYS", "SERENE AIRLINES"
    };
    cout << "Flight Choice: " << flights[choice] << "\n\n";

    const char* dest = (to == 1 ? "KARACHI => LAHORE"
                      : to == 2 ? "KARACHI => ISLAMABAD"
                                : "KARACHI => SKARDU");
    cout << "Flight Destination: " << dest << "\n\n";

    for (int i = 1; i <= n; ++i) {
        cout << "Passenger " << i << ":\n";
        cout << "  Name    : " << name[i] << "\n";
        cout << "  Age     : " << age[i] << "\n";
        cout << "  Phone   : " << phone_number[i] << "\n";
        cout << "  Gender  : " << (toupper(gender[i])=='M' ? "Male" : "Female") << "\n";
        cout << "  Seat    : " << seat_number[i] << "\n";
        cout << "  Meal    : " << (meal[i]==1?"Biryani":meal[i]==2?"Salad":"No Meal") << "\n";
        cout << "**************************************************\n\n";
    }
}

// Function For Printing The Total Bill
void Airlines::billing(int n)
{
    int rate = 0;
    if (to == 1)    rate = (choice==1?1000:choice==2?1250:choice==3?1750:choice==4?1110:1550);
    else if (to==2) rate = (choice==1?1200:choice==2?1400:choice==3?1950:choice==4?1250:1250);
    else            rate = (choice==1?1400:choice==2?1350:choice==3?1550:choice==4?1750:1470);

    bill = n * rate;
    cout << "The Total Bill Is : " << bill << "\n";
}

// Function For Printing The Details Of All Passenger
void Airlines::print_list(int n)
{
    cout << "\nPRINTING THE LIST OF PASSENGERS WITH DETAILS::\n\n";
    static const char* flights[] = {
        "", "PIA", "EMIRATES", "AIR BLUE", "QATAR AIRWAYS", "SERENE AIRLINES"
    };
    cout << "Flight Choice :: " << flights[choice] << "\n\n";

    const char* dest = (to == 1 ? "KARACHI => LAHORE"
                      : to == 2 ? "KARACHI => ISLAMABAD"
                                : "KARACHI => SKARDU");
    cout << "Flight Destination :: " << dest << "\n\n";

    for (int i = 1; i <= n; ++i) {
        reserve++;
        cout << "Passenger " << i << " (Res# " << reserve << "):\n";
        cout << "  Name   :: " << name[i] << "\n";
        cout << "  Age    :: " << age[i] << "\n";
        cout << "  Phone  :: " << phone_number[i] << "\n";
        cout << "  Gender :: " << (toupper(gender[i])=='M'?"Male":"Female") << "\n";
        cout << "  Seat   :: " << seat_number[i] << "\n";
        cout << "  Meal   :: " << (meal[i]==1?"Biryani":meal[i]==2?"Salad":"No Meal") << "\n";
        cout << "**************************************************\n\n";
    }
}

// Function For Printing The Flight Seats Status
void Airlines::print_report(int n)
{
    cout << "\nPrinting The Status Of Flight Seats =====>\n\n";
    cout << "The Total Booked Seats    :: " << n << "\n";
    cout << "The Total Remaining Seats :: " << (size - n) << "\n";
    cout << "**************************************************\n";
}

// Function For Printing ARS Menu
void Menu::displayMenu()
{
    int menu = 0;
    do {
        cout << "******************** AIRLINE RESERVATION SYSTEM *********************\n\n";
        cout << "---------------------------------------------------------------------\n";
        cout << "\tOPTIONS::\tOPTION CODE\n\n";
        cout << "\tFlight Schedule  ------ [1]\n";
        cout << "\tMake Reservation ------ [2]\n";
        cout << "\tPrint list         ------ [3]\n";
        cout << "\tSeat Status        ------ [4]\n";
        cout << "\tQuit               ------ [5]\n";
        cout << "---------------------------------------------------------------------\n";
        cout << "Enter Your Option Code :: ";
        cin >> menu;

        try {
            if (menu < 1 || menu > 5) throw "Error";
        } catch (const char*) {
            cout << "Enter valid Number\n";
        }

        switch (menu) {
            case 1: {
                cout << "\n*** WELCOME TO FLIGHT SCHEDULE ***\n\n";
                flight_schedule();
                char r;
                cout << "\nReturn to menu? (Y/N): ";
                cin >> r;
                if (toupper(r)!='Y') exit(0);
                break;
            }
            case 2:
                cout << "\n*** WELCOME TO RESERVATION DESK ***\n\n";
                flight_details();
                cout << "Enter The Number Of Passenger :: ";
                cin >> n;
                get_details(n);
                printdetails(n);
                billing(n);
                cout << endl;
                break;
            case 3:
                print_list(n);
                billing(n);
                cout << endl;
                break;
            case 4:
                print_report(n);
                break;
            case 5:
                cout << "\nThank you, come again!\n\n";
                exit(0);
        }

        cout << "   PROCESS COMPLETED...\n";
        cout << "   THANKS FOR VISIT, HAVE A GOOD DAY ...\n";
        cout << "*********************************************************************\n\n";

    } while (menu != 5);
}

// Main Function
int main()
{
    setColor(10);  // Light green

    cout << "\n---------------------------------------------------------------------\n";
    cout << "************************* WELCOME TO AIR FAST ***********************\n";
    cout << "---------------------------------------------------------------------\n\n";

    Menu m;
    m.displayMenu();
    return 0;
}