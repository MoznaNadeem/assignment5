#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Employee {
    int id;
    string name;
    double monthlySalary;
};

int main() {
    
    vector<Employee> employees;
    int n;

   
    cout << "Enter number of employees: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Employee emp;

        cout << "\nEnter details for Employee " << i + 1 << endl;
        cout << "ID: ";
        cin >> emp.id;

        cout << "Name: ";
        cin.ignore();
        getline(cin, emp.name);

        cout << "Monthly Salary: ";
        cin >> emp.monthlySalary;

        employees.push_back(emp);
    }

    ofstream outFile("high_salary.txt");

    if (!outFile) {
        cout << "Error: File could not be opened for writing." << endl;
        return 1;
    }

    double threshold;
    cout << "\nEnter yearly salary threshold: ";
    cin >> threshold;

    for (auto emp : employees) {
        /* =========================
           Step 4: Calculate Yearly Salary
           ========================= */
        double yearlySalary = emp.monthlySalary * 12;

        if (yearlySalary > threshold) {
            outFile << emp.id << " "
                    << emp.name << " "
                    << yearlySalary << endl;
        }
    }

    outFile.close();
    cout << "\nHigh salary employees saved to file successfully." << endl;

    ifstream inFile("high_salary.txt");

    if (!inFile) {
        cout << "Error: File could not be opened for reading." << endl;
        return 1;
    }

    cout << "\nEmployees with High Yearly Salary:\n";
    cout << "---------------------------------\n";

    int id;
    string name;
    double salary;

    while (inFile >> id >> name >> salary) {
        cout << "ID: " << id
             << ", Name: " << name
             << ", Yearly Salary: " << salary << endl;
    }

    inFile.close();

    return 0;
}

