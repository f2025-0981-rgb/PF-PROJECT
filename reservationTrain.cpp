#include <iostream>
using namespace std;

struct TrainTicket {
    string passengerName;
    int tickets;
    int pricePerTicket;
    int totalCost;
};

int main() {
    TrainTicket t;

    cout << "--- Train Ticket Reservation ---" << endl;
    cout << "Enter passenger name: ";
    cin >> t.passengerName;

    cout << "Enter price per ticket: ";
    cin >> t.pricePerTicket;

    cout << "Enter number of tickets: ";
    cin >> t.tickets;

    t.totalCost = t.pricePerTicket * t.tickets;

    cout << "Total Cost: Rs. " << t.totalCost << endl;
    return 0;
}
