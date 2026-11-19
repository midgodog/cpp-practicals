#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructors
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // --- 1. FUNCTION OVERLOADING ---
    // Overloaded print method #1: Standard display
    void display() const {
        std::cout << real << (imag >= 0 ? " + " : " - ") << std::abs(imag) << "i\n";
    }

    // Overloaded print method #2: Detailed breakdown with a custom message prefix
    void display(const std::string& prefix) const {
        std::cout << prefix << ": " << real << (imag >= 0 ? " + " : " - ") << std::abs(imag) << "i\n";
    }

    // Overloaded add method #1: Adds a scalar value to the complex number
    Complex add(double scalar) const {
        return Complex(real + scalar, imag);
    }

    // Overloaded add method #2: Adds another Complex object
    Complex add(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // --- 2. OPERATOR OVERLOADING ---
    // Overloading binary '+' operator as a member function
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloading binary '-' operator as a member function
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overloading stream insertion ('<<') operator as a friend function
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? " + " : " - ") << std::abs(c.imag) << "i";
        return os;
    }

    // Overloading stream extraction ('>>') operator as a friend function
    friend std::istream& operator>>(std::istream& is, Complex& c) {
        std::cout << "Enter real part: ";
        is >> c.real;
        std::cout << "Enter imaginary part: ";
        is >> c.imag;
        return is;
    }
};

int main() {
    std::cout << "========================================\n";
    std::cout << "    FUNCTION & OPERATOR OVERLOADING     \n";
    std::cout << "========================================\n\n";

    // Initialize objects
    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.0);

    // 1. Demonstrating Function Overloading
    std::cout << "--- Function Overloading Demo ---\n";
    std::cout << "Calling display(): ";
    c1.display();
    
    std::cout << "Calling display(prefix): ";
    c1.display("Result Number");

    Complex resScalar = c1.add(5.0); // Calls add(double)
    Complex resComplex = c1.add(c2); // Calls add(const Complex&)
    
    std::cout << "After adding scalar 5.0: ";
    resScalar.display();
    std::cout << "After adding Complex c2: ";
    resComplex.display();

    // 2. Demonstrating Operator Overloading
    std::cout << "\n--- Operator Overloading Demo ---\n";
    
    Complex sum = c1 + c2; // Uses overloaded '+' operator
    Complex diff = c1 - c2; // Uses overloaded '-' operator

    std::cout << "c1 = " << c1 << "\n";
    std::cout << "c2 = " << c2 << "\n";
    std::cout << "c1 + c2 = " << sum << "\n";
    std::cout << "c1 - c2 = " << diff << "\n";

    // Using overloaded stream extraction ('>>')
    std::cout << "\n--- Stream Extraction Operator Demo ---\n";
    Complex userComplex;
    std::cin >> userComplex;
    std::cout << "You entered: " << userComplex << "\n";

    std::cout << "\n========================================\n";
    std::cout << "       Shreyas Shirke       \n";
    std::cout << "========================================\n";

    return 0;
}
