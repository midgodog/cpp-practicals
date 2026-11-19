#include <iostream>
#include <string>
#include <iomanip>

// Define a macro constant
#define PI 3.14159

int main() {
    // 1. CONSTANTS
    const int MAX_LIMIT = 100; // Named constant (read-only variable)

    // 2. VARIABLES & DATA TYPES
    int age = 19;                     // Integer data type
    double salary = 45500.50;         // Double precision floating-point
    float temperature = 98.6f;        // Single precision floating-point
    char section = 'A';               // Character data type
    bool isActive = true;             // Boolean data type
    std::string userName;             // String data type (non-primitive object)

    // 3. INPUT / OUTPUT (I/O)
    std::cout << "========================================\n";
    std::cout << "      C++ FUNDAMENTALS DEMO PROGRAM     \n";
    std::cout << "========================================\n\n";
    std::cout << "Enter your full name: ";
    std::getline(std::cin, userName); // Read line including spaces
    std::cout << "\n--- Welcome, " << userName << "! ---\n\n";

    // Displaying Variables and Constants
    std::cout << "[Variables & Data Types Output]\n";
    std::cout << "Age: " << age << " years\n";
    std::cout << "Salary: $" << std::fixed << std::setprecision(2) << salary << "\n";
    std::cout << "Temperature: " << temperature << " F\n";
    std::cout << "Section: " << section << "\n";
    std::cout << "Is Active? " << (isActive ? "Yes" : "No") << "\n";
    std::cout << "Max Limit (const): " << MAX_LIMIT << "\n";
    std::cout << "PI (macro): " << PI << "\n\n";

    // 4. OPERATORS DEMONSTRATION
    double num1, num2;
    std::cout << "Enter two numbers (e.g., 10 4) for operator testing: ";
    std::cin >> num1 >> num2;

    std::cout << "\n[Operators Output]\n";
    
    // Arithmetic Operators (+, -, *, /, %)
    std::cout << "--- Arithmetic Operators ---\n";
    std::cout << "num1 + num2 = " << (num1 + num2) << "\n";
    std::cout << "num1 - num2 = " << (num1 - num2) << "\n";
    std::cout << "num1 * num2 = " << (num1 * num2) << "\n";
    if (num2 != 0) {
        std::cout << "num1 / num2 = " << (num1 / num2) << "\n";
        
        // Modulus requires integer operands
        int int1 = static_cast<int>(num1);
        int int2 = static_cast<int>(num2);
        if (int2 != 0) {
            std::cout << "int1 % int2 (Modulus) = " << (int1 % int2) << "\n";
        }
    } else {
        std::cout << "Division by zero skipped.\n";
    }

    // Relational Operators (==, !=, >, <, >=, <=)
    std::cout << "\n--- Relational Operators ---\n";
    std::cout << "num1 == num2: " << (num1 == num2) << "\n";
    std::cout << "num1 != num2: " << (num1 != num2) << "\n";
    std::cout << "num1 > num2:  " << (num1 > num2) << "\n";
    std::cout << "num1 < num2:  " << (num1 < num2) << "\n";

    // Logical Operators (&&, ||, !)
    std::cout << "\n--- Logical Operators ---\n";
    bool cond1 = (num1 > 0);
    bool cond2 = (num2 > 0);
    std::cout << "(num1 > 0) && (num2 > 0): " << (cond1 && cond2) << "\n";
    std::cout << "(num1 > 0) || (num2 > 0): " << (cond1 || cond2) << "\n";
    std::cout << "!(num1 > 0): " << (!cond1) << "\n";

    // Bitwise Operators (&, |, ^, <<, >>)
    int bit1 = static_cast<int>(num1);
    int bit2 = static_cast<int>(num2);
    std::cout << "\n--- Bitwise Operators (using integer casts) ---\n";
    std::cout << "bit1 & bit2 = " << (bit1 & bit2) << "\n";
    std::cout << "bit1 | bit2 = " << (bit1 | bit2) << "\n";
    std::cout << "bit1 ^ bit2 = " << (bit1 ^ bit2) << "\n";
    std::cout << "bit1 << 1   = " << (bit1 << 1) << "\n";

    std::cout << "\n========================================\n";
    std::cout << "       PROGRAM EXECUTED SUCCESSFULLY    \n";
    std::cout << "========================================\n";

    return 0;
}
