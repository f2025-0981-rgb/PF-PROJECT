#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct TrainTicket {
    string passengerName;
    int routeChoice;
    int tickets;
    int pricePerTicket;
    int totalCost;
};

int main() {
    string routes[5] = {
        "Lahore to Islamabad",
        "Lahore to Karachi",
        "Islamabad to Peshawar",
        "Karachi to Quetta",
        "Multan to Lahore"
    };

    int fares[5] = {1800, 4500, 1500, 4000, 1200};

    vector<TrainTicket> bookings;
    char choice;

    ofstream outFile("train_bookings.txt", ios::app);

    do {
        TrainTicket t;

        cout << "\n--- Train Reservation System ---" << endl;
        cout << "Enter passenger name: ";
        cin >> t.passengerName;

        cout << "\nAvailable Train Routes:\n";
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ". " << routes[i]
                 << " (Fare per ticket: Rs. " << fares[i] << ")" << endl;
        }

        cout << "Select route (1-5): ";
        cin >> t.routeChoice;

        while (t.routeChoice < 1 || t.routeChoice > 5) {
            cout << "Invalid choice! Select again (1-5): ";
            cin >> t.routeChoice;
        }

        t.pricePerTicket = fares[t.routeChoice - 1];

        cout << "Enter number of tickets: ";
        cin >> t.tickets;

        t.totalCost = t.pricePerTicket * t.tickets;

        bookings.push_back(t);

        outFile << t.passengerName << " "
                << routes[t.routeChoice - 1] << " "
                << t.tickets << " "
                << t.totalCost << endl;

        cout << "\nReservation Successful!" << endl;
        cout << "Total Cost: Rs. " << t.totalCost << endl;

        cout << "\nDo you want to add another reservation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    outFile.close();

    cout << "\n--- All Train Reservations (From Program) ---\n";
    for (int i = 0; i < bookings.size(); i++) {
        cout << "\nPassenger Name: " << bookings[i].passengerName;
        cout << "\nRoute: " << routes[bookings[i].routeChoice - 1];
        cout << "\nTickets: " << bookings[i].tickets;
        cout << "\nTotal Cost: Rs. " << bookings[i].totalCost << endl;
    }

    cout << "\n--- Reading From File ---\n";
    ifstream inFile("train_bookings.txt");

    string name, route;
    int tickets, total;

    while (inFile >> name >> route >> tickets >> total) {
        cout << "\nPassenger Name: " << name;
        cout << "\nRoute: " << route;
        cout << "\nTickets: " << tickets;
        cout << "\nTotal Cost: Rs. " << total << endl;
    }

    inFile.close();

    return 0;
}
