#include <iostream>
#include <vector>
using namespace std;

// Class to handle calculations
class Calculator {
public:
    // Function to add two numbers
    double add(double a, double b) {
        return a + b;
    }

    // Function to subtract two numbers
    double subtract(double a, double b) {
        return a - b;
    }

    // Function to multiply two numbers
    double multiply(double a, double b) {
        return a * b;
    }

    // Function to divide two numbers
    double divide(double a, double b) {
        if (b == 0) {
            throw runtime_error("Error: Division by zero is not allowed.");
        }
        return a / b;
    }
};

// Class to handle input and output
class CalculatorUI {
private:
    Calculator calc;
    vector<string> history; // To store calculation history

public:
    // Function to display the menu
    void displayMenu() {
        cout << "Simple Calculator" << endl;
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "5. View History" << endl;
        cout << "6. Exit" << endl;
    }

    // Function to get user input
    void getUserInput(double &num1, double &num2, int &choice) {
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        cout << "Enter your choice (1-6): ";
        cin >> choice;
    }

    // Function to perform the calculation based on user choice
    void performCalculation(double num1, double num2, int choice) {
        double result = 0;
        string operation;

        try {
            switch (choice) {
                case 1:
                    result = calc.add(num1, num2);
                    operation = " + ";
                    break;
                case 2:
                    result = calc.subtract(num1, num2);
                    operation = " - ";
                    break;
                case 3:
                    result = calc.multiply(num1, num2);
                    operation = " * ";
                    break;
                case 4:
                    result = calc.divide(num1, num2);
                    operation = " / ";
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    return;
            }

            // Store the calculation in history
            string historyEntry = to_string(num1) + operation + to_string(num2) + " = " + to_string(result);
            history.push_back(historyEntry);

            // Display the result
            cout << "Result: " << result << endl;
        } catch (const runtime_error &e) {
            cout << e.what() << endl;
        }
    }

    // Function to display calculation history
    void displayHistory() {
        if (history.empty()) {
            cout << "No history available." << endl;
        } else {
            cout << "Calculation History:" << endl;
            for (const string &entry : history) {
                cout << entry << endl;
            }
        }
    }
};

int main() {
    CalculatorUI ui;
    double num1, num2;
    int choice;

    while (true) {
        ui.displayMenu();
        ui.getUserInput(num1, num2, choice);

        if (choice == 5) {
            ui.displayHistory();
        } else if (choice == 6) {
            cout << "Exiting the calculator. Goodbye!" << endl;
            break;
        } else {
            ui.performCalculation(num1, num2, choice);
        }

        cout << "-------------------------" << endl;
    }

    return 0;
}