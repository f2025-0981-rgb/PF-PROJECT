#include <iostream>
using namespace std;

struct CarRental {
    string customerName;
    int days;
    int pricePerDay;
    int totalCost;
};

int main() {
    CarRental c;

    cout << "--- Car Rental System ---" << endl;
    cout << "Enter customer name: ";
    cin >> c.customerName;

    cout << "Enter price per day: ";
    cin >> c.pricePerDay;

    cout << "Enter number of days: ";
    cin >> c.days;

    c.totalCost = c.pricePerDay * c.days;

    cout << "Total Cost: Rs. " << c.totalCost << endl;
    return 0;
}
