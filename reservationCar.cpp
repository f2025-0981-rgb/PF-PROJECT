#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct CarRental {
    string customerName;
    int carChoice;
    int days;
    int pricePerDay;
    int totalCost;
};

int main() {
    string cars[5] = {"Suzuki Alto", "Toyota Corolla", "Honda Civic", "Toyota Fortuner", "Kia Sportage"};
    int rentPerDay[5] = {3000, 5000, 7000, 12000, 9000};

    vector<CarRental> rentals;
    char choice;

    ofstream outFile("car_rentals.txt", ios::app);

    do {
        CarRental c;

        cout << "\n--- Car Rental System ---" << endl;
        cout << "Enter customer name: ";
        cin >> c.customerName;

        cout << "\nAvailable Cars:\n";
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ". " << cars[i]
                 << " (Rent per day: Rs. " << rentPerDay[i] << ")" << endl;
        }

        cout << "Select car (1-5): ";
        cin >> c.carChoice;

        while (c.carChoice < 1 || c.carChoice > 5) {
            cout << "Invalid choice! Select again (1-5): ";
            cin >> c.carChoice;
        }

        c.pricePerDay = rentPerDay[c.carChoice - 1];

        cout << "Enter number of days: ";
        cin >> c.days;

        c.totalCost = c.pricePerDay * c.days;

        rentals.push_back(c);

        outFile << c.customerName << " "
                << cars[c.carChoice - 1] << " "
                << c.days << " "
                << c.totalCost << endl;

        cout << "\nRental Successful!" << endl;
        cout << "Total Cost: Rs. " << c.totalCost << endl;

        cout << "\nDo you want to add another rental? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    outFile.close();

    cout << "\n--- All Car Rental Records (From Program) ---\n";
    for (int i = 0; i < rentals.size(); i++) {
        cout << "\nCustomer Name: " << rentals[i].customerName;
        cout << "\nCar: " << cars[rentals[i].carChoice - 1];
        cout << "\nDays: " << rentals[i].days;
        cout << "\nTotal Cost: Rs. " << rentals[i].totalCost << endl;
    }

    cout << "\n--- Reading From File ---\n";
    ifstream inFile("car_rentals.txt");

    string name, car;
    int days, total;

    while (inFile >> name >> car >> days >> total) {
        cout << "\nCustomer Name: " << name;
        cout << "\nCar: " << car;
        cout << "\nDays: " << days;
        cout << "\nTotal Cost: Rs. " << total << endl;
    }

    inFile.close();

    return 0;
}