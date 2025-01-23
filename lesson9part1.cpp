// Siddharth Sriram, CS1436.010, Lab 9
// The following program will display the status of an order.

#include <iostream>
#include <iomanip>

using namespace std;

// Normal shipping and handling cost and price per spool
const double SpoolPrice = 104.00;
const double RegularShippingCost = 12.99;


void ReadinOrderDetails (
    int &SpoolsInStock,
    int &SpoolsOrdered,
    double &CostofShipping
    );

// Read and check input by the user for spools in stock, order, and cost for shipping
void ShowOrderDetails (
    int SpoolsInStock, 
    int SpoolsOrdered, 
    double CostofShipping
    );

int main(){

    // Variables for order details
    int SpoolsOrdered = 0;
    int SpoolsInStock = 0;
    double CostofShipping = RegularShippingCost;

    // Reads in what user puts in
    ReadinOrderDetails (SpoolsInStock, SpoolsOrdered, CostofShipping);

    // Outputs the calculated details of the order
    ShowOrderDetails (SpoolsInStock, SpoolsOrdered, CostofShipping);

    return 0;
}

// Reads in and checks the details the user inputted
void ReadinOrderDetails (int &SpoolsInStock, int &SpoolsOrdered, double &CostofShipping){

    // For when the special cost of shipping is chosen
    char SpecialCostofShipping = 'n';
    
    // Asks the user for the spools that need to be ordered
    cout << "Spools to be ordered" << "\n";
    while (!(cin >> SpoolsOrdered) || SpoolsOrdered < 1){
        cout << "Spools order must be 1 or more\n"; // Checks input
        cout << "Spools to be ordered" << "\n"; // Asks the same thing again
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Spools in stock" << "\n";
    while (!(cin >> SpoolsInStock) || SpoolsInStock < 0){
        cout << "Spools in stock must be 0 or more\n";
        cout << "Spools in stock" << "\n";
        cin. clear();
        cin.ignore(10000, '\n');
    }

    // Asks user if he wants special shipping and handling
    cout << "Special shipping and handling (y or n)" << "\n"; 
    cin >> SpecialCostofShipping;

    // Is the input chosen by user valid?
    while (SpecialCostofShipping != 'y' && SpecialCostofShipping !='n'){
        cout << "Please enter 'y' or 'n' for special shipping.\n";
        cout << "Special shipping and handling (y or n)" << "\n";
        cin >> SpecialCostofShipping;

    }
    // Special shipping has been chosen, asks for the cost
    if (SpecialCostofShipping == 'y'){
        cout << "Shipping and handling amount" << "\n";
        while (!(cin >> CostofShipping) || CostofShipping < 0){

            // Checks input
            cout << "The spool shipping and handling charge must be 0.0 or more\n";
            cout << "Shipping and handling amount" << "\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } else {

        CostofShipping = RegularShippingCost;

    }

}

// Calculations for order properties

void ShowOrderDetails(int SpoolsInStock, int SpoolsOrdered, double CostofShipping){
    int SpoolsReadyToShip = min(SpoolsOrdered, SpoolsInStock);
    int SpoolsOnBackOrder = max(0, SpoolsOrdered - SpoolsInStock);
    double SubtotalReadyToShip = SpoolsReadyToShip * SpoolPrice;
    double ShippingCharges = SpoolsReadyToShip * CostofShipping;
    double Total = SubtotalReadyToShip + ShippingCharges;

    // Outputs all code

    cout << fixed << setprecision(2);
    cout << "Spools ready to ship: " << SpoolsReadyToShip << "\n";
    cout << "Spools on back-order: " << SpoolsOnBackOrder << "\n";
    cout << "Subtotal ready to ship: $" << setw(10) << SubtotalReadyToShip << "\n";
    cout << "Shipping and handling:  $" << setw(10) << ShippingCharges << "\n";
    cout << "Total shipping charges: $" << setw(10) << Total << "\n";
}

