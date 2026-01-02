#include <iostream>
using namespace std;

struct BusTicket {
    string passengerName;
    int tickets;
    int pricePerTicket;
    int totalCost;
};

int main() {
    BusTicket b;

    cout << "--- Bus Ticket Reservation ---" << endl;
    cout << "Enter passenger name: ";
    cin >> b.passengerName;

    cout << "Enter price per ticket: ";
    cin >> b.pricePerTicket;

    cout << "Enter number of tickets: ";
    cin >> b.tickets;

    b.totalCost = b.pricePerTicket * b.tickets;

    cout << "Total Cost: Rs. " << b.totalCost << endl;
    return 0;
}
