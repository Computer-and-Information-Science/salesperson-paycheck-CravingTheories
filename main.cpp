#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
  
  string filename, firstname, lastname;
  double salary, commissionpercent, totalsales, expenses;

  cout << "Enter file name: ";
  cin >> filename;

  ifstream inputFile(filename);
  
  if (!inputFile) {
        cerr << "Unable to open file " << filename << endl;
        return 1;
    }

  inputFile >> firstname >> lastname;
  inputFile >> salary >> commissionpercent;
  inputFile >> totalsales;
  inputFile >> expenses;

  inputFile.close();

  double commission = (commissionpercent / 100) * totalsales;
  double pay = salary + commission- expenses;

  cout << fixed << setprecision(2);

    cout << "\nPayroll data for " << firstname << " " << lastname << "\n\n";
    cout << "Base Salary:   " << setw(9) << salary << endl;

    cout << "Commission:    " << setw(9) << commission
         << " (" << setprecision(1) << commissionpercent
         << "% of " << fixed << setprecision(2) << totalsales << ")" << endl;

    cout << "Expenses:      " << setw(9) << expenses << endl;
    cout << "              --------\n";
    cout << "Total:         " << setw(9) << pay << endl;

}
