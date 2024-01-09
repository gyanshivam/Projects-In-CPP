#include <iostream>
#include <cmath>

using namespace std;

class Calculator {
    
public:

    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b == 0) {
            throw runtime_error("Cannot divide by zero");
        }
        return a / b;
    }

    double square(double a) {
        return a * a;
    }

    double squareRoot(double a) {
        if (a < 0) {
            throw domain_error("Cannot calculate square root of a negative number");
        }
        return sqrt(a);
    }

    double cube(double a) {
        return a * a * a;
    }

    double cubeRoot(double a) {
        return cbrt(a);
    }

    double percentage(double a, double percent) {
        return (a * percent) / 100.0;
    }
};

int main() {
    Calculator calculator;
    double num1, num2, result;
    char operation;

    while (true) {
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter operation (+ for addition, - for substraction, * for multiplication, / for divison, s for square, r for square root, c for cube, v for Cube Root, p for Perecentage, x for exit): ";
        cin >> operation;

        if (operation == 'x') {
            break;
        }

        try {
            switch (operation) {
                case '+':
                    cout << "Enter second number: ";
                    cin >> num2;
                    result = calculator.add(num1, num2);
                    break;
                case '-':
                    cout << "Enter second number: ";
                    cin >> num2;
                    result = calculator.subtract(num1, num2);
                    break;
                case '*':
                    cout << "Enter second number: ";
                    cin >> num2;
                    result = calculator.multiply(num1, num2);
                    break;
                case '/':
                    cout << "Enter second number: ";
                    cin >> num2;
                    result = calculator.divide(num1, num2);
                    break;
                case 's':
                    result = calculator.square(num1);
                    break;
                case 'r':
                    result = calculator.squareRoot(num1);
                    break;
                case 'c':
                    result = calculator.cube(num1);
                    break;
                case 'v':
                    result = calculator.cubeRoot(num1);
                    break;
                case 'p':
                    cout << "Enter percentage: ";
                    cin >> num2;
                    result = calculator.percentage(num1, num2);
                    break;
                default:
                    throw invalid_argument("Invalid operation");
            }

            cout << "Result: " << result << endl;

        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }

        cout << "----------------------" << endl;
    }

    cout << "Calculator exited." << endl;

    return 0;
}
