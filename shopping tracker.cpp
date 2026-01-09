#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Order {
    int orderID;
    string customerName;
    int itemCount;
    double pricePerItem;
};


double calculateTotal(int items, double price) {
    return items * price;
}

int main() {
    
    vector<Order> orders;
    int n;

   
    cout << "Enter total number of orders: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Order ord;

        cout << "\nEnter details for Order " << i + 1 << endl;

        cout << "Order ID: ";
        cin >> ord.orderID;

        cout << "Customer Name: ";
        cin.ignore();
        getline(cin, ord.customerName);

     
        do {
            cout << "Number of items: ";
            cin >> ord.itemCount;
        } while (ord.itemCount <= 0);

        do {
            cout << "Price per item: ";
            cin >> ord.pricePerItem;
        } while (ord.pricePerItem <= 0);

        orders.push_back(ord);
    }

   
    ofstream outFile("priority_orders.txt");

    if (!outFile) {
        cout << "Error: Unable to open file for writing." << endl;
        return 1;
    }

    for (auto ord : orders) {
        double totalAmount = calculateTotal(ord.itemCount, ord.pricePerItem);

        if (totalAmount > 5000) {
            outFile << ord.orderID << " "
                    << ord.customerName << " "
                    << ord.itemCount << " "
                    << ord.pricePerItem << " "
                    << totalAmount << endl;
        }
    }

    outFile.close();
    cout << "\nHigh-value orders saved successfully." << endl;

    /
    ifstream inFile("priority_orders.txt");

    if (!inFile) {
        cout << "Error: Unable to open file for reading." << endl;
        return 1;
    }

    cout << "\nPriority Orders (Total > 5000):\n";
    cout << "----------------------------------\n";

    int id, items;
    string name;
    double price, total;

    while (inFile >> id >> name >> items >> price >> total) {
        cout << "Order ID: " << id
             << ", Customer: " << name
             << ", Items: " << items
             << ", Price per item: " << price
             << ", Total: " << total << endl;
    }

    inFile.close();

    return 0;
}

