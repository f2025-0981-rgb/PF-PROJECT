#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct AirlineTicket {
    string passengerName;
    int destinationChoice;
    int tickets;
    int pricePerTicket;
    int totalCost;
};

int main() {
    string destinations[5] = {"Lahore", "Dubai", "Islamabad", "Karachi", "Jeddah"};
    int airFares[5] = {18000, 95000, 20000, 22000, 120000};

    vector<AirlineTicket> bookings;
    char choice;

    ofstream outFile("airline_bookings.txt", ios::app);

    do {
        AirlineTicket a;

        cout << "\n--- Airline Ticket Reservation ---" << endl;
        cout << "Enter passenger name: ";
        cin >> a.passengerName;

        cout << "\nAvailable Destinations:\n";
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ". " << destinations[i]
                 << " (Air Fare: Rs. " << airFares[i] << ")" << endl;
        }

        cout << "Select destination (1-5): ";
        cin >> a.destinationChoice;

        while (a.destinationChoice < 1 || a.destinationChoice > 5) {
            cout << "Invalid choice! Select again (1-5): ";
            cin >> a.destinationChoice;
        }

        a.pricePerTicket = airFares[a.destinationChoice - 1];

        cout << "Enter number of tickets: ";
        cin >> a.tickets;

        a.totalCost = a.pricePerTicket * a.tickets;

        bookings.push_back(a);

        outFile << a.passengerName << " "
                << destinations[a.destinationChoice - 1] << " "
                << a.tickets << " "
                << a.totalCost << endl;

        cout << "\nBooking Successful!" << endl;
        cout << "Total Cost: Rs. " << a.totalCost << endl;

        cout << "\nDo you want to add another booking? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    outFile.close();

    cout << "\n--- All Airline Ticket Bookings (From Program) ---\n";
    for (int i = 0; i < bookings.size(); i++) {
        cout << "\nPassenger Name: " << bookings[i].passengerName;
        cout << "\nDestination: " << destinations[bookings[i].destinationChoice - 1];
        cout << "\nTickets: " << bookings[i].tickets;
        cout << "\nTotal Cost: Rs. " << bookings[i].totalCost << endl;
    }

    cout << "\n--- Reading From File ---\n";
    ifstream inFile("airline_bookings.txt");
    string name, destination;
    int tickets, total;

    while (inFile >> name >> destination >> tickets >> total) {
        cout << "\nPassenger: " << name
             << "\nDestination: " << destination
             << "\nTickets: " << tickets
             << "\nTotal Cost: Rs. " << total << endl;
    }

    inFile.close();

    return 0;
}
