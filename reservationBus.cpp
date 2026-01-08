#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct BusTicket {
    string passengerName;
    int cityChoice;
    int tickets;
    int pricePerTicket;
    int totalCost;
};

int main() {
    string cities[5] = {"Lahore", "Islamabad", "Karachi", "Peshawar", "Quetta"};
    int fares[5] = {1500, 2000, 3500, 1800, 4000};

    vector<BusTicket> bookings;
    char choice;

    ofstream outFile("bus_bookings.txt", ios::app);

    do {
        BusTicket b;

        cout << "\n--- Bus Ticket Reservation ---" << endl;
        cout << "Enter passenger name: ";
        cin >> b.passengerName;

        cout << "\nAvailable Cities:\n";
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ". " << cities[i]
                 << " (Fare: Rs. " << fares[i] << ")" << endl;
        }

        cout << "Select city (1-5): ";
        cin >> b.cityChoice;

        while (b.cityChoice < 1 || b.cityChoice > 5) {
            cout << "Invalid choice! Select again (1-5): ";
            cin >> b.cityChoice;
        }

        b.pricePerTicket = fares[b.cityChoice - 1];

        cout << "Enter number of tickets: ";
        cin >> b.tickets;

        b.totalCost = b.pricePerTicket * b.tickets;

        bookings.push_back(b);

        outFile << b.passengerName << " "
                << cities[b.cityChoice - 1] << " "
                << b.tickets << " "
                << b.totalCost << endl;

        cout << "\nBooking Successful!" << endl;
        cout << "Total Cost: Rs. " << b.totalCost << endl;

        cout << "\nDo you want to add another booking? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    outFile.close();

    cout << "\n--- All Bus Ticket Bookings (From Program) ---\n";
    for (int i = 0; i < bookings.size(); i++) {
        cout << "\nPassenger Name: " << bookings[i].passengerName;
        cout << "\nCity: " << cities[bookings[i].cityChoice - 1];
        cout << "\nTickets: " << bookings[i].tickets;
        cout << "\nTotal Cost: Rs. " << bookings[i].totalCost << endl;
    }

    cout << "\n--- Reading From File ---\n";
    ifstream inFile("bus_bookings.txt");
    string name, city;
    int tickets, total;

    while (inFile >> name >> city >> tickets >> total) {
        cout << "\nPassenger: " << name
             << "\nCity: " << city
             << "\nTickets: " << tickets
             << "\nTotal Cost: Rs. " << total << endl;
    }

    inFile.close();

    return 0;
}
