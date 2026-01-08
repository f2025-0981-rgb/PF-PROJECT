#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct CinemaTicket {
    string customerName;
    int movieChoice;
    int tickets;
    int pricePerTicket;
    int totalCost;
};

int main() {
    string movies[5] = {"Avatar", "Joker", "Avengers", "Frozen", "The Nun"};
    int ticketPrices[5] = {900, 750, 1000, 650, 800};

    vector<CinemaTicket> bookings;
    char choice;

    ofstream outFile("cinema_bookings.txt", ios::app);

    do {
        CinemaTicket c;

        cout << "\n--- Cinema Ticket Booking ---" << endl;
        cout << "Enter customer name: ";
        cin >> c.customerName;

        cout << "\nAvailable Movies:\n";
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ". " << movies[i]
                 << " (Ticket Price: Rs. " << ticketPrices[i] << ")" << endl;
        }

        cout << "Select movie (1-5): ";
        cin >> c.movieChoice;

        while (c.movieChoice < 1 || c.movieChoice > 5) {
            cout << "Invalid choice! Select again (1-5): ";
            cin >> c.movieChoice;
        }

        c.pricePerTicket = ticketPrices[c.movieChoice - 1];

        cout << "Enter number of tickets: ";
        cin >> c.tickets;

        c.totalCost = c.pricePerTicket * c.tickets;

        bookings.push_back(c);

        outFile << c.customerName << " "
                << movies[c.movieChoice - 1] << " "
                << c.tickets << " "
                << c.totalCost << endl;

        cout << "\nBooking Successful!" << endl;
        cout << "Total Cost: Rs. " << c.totalCost << endl;

        cout << "\nDo you want to add another booking? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    outFile.close();

    cout << "\n--- All Cinema Ticket Bookings (From Program) ---\n";
    for (int i = 0; i < bookings.size(); i++) {
        cout << "\nCustomer Name: " << bookings[i].customerName;
        cout << "\nMovie: " << movies[bookings[i].movieChoice - 1];
        cout << "\nTickets: " << bookings[i].tickets;
        cout << "\nTotal Cost: Rs. " << bookings[i].totalCost << endl;
    }

    cout << "\n--- Reading From File ---\n";
    ifstream inFile("cinema_bookings.txt");
    string name, movie;
    int tickets, total;

    while (inFile >> name >> movie >> tickets >> total) {
        cout << "\nCustomer: " << name
             << "\nMovie: " << movie
             << "\nTickets: " << tickets
             << "\nTotal Cost: Rs. " << total << endl;
    }

    inFile.close();

    return 0;
}
