#include <iostream>
#include <string>
#include <exception>
#include <utility>

// 1. BASE CUSTOM EXCEPTION CLASS (Inherits from std::exception)
class BankingException : public std::exception {
protected:
    std::string message;

public:
    explicit BankingException(std::string msg) : message(std::move(msg)) {}

    // Override what() to return the custom error description
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// 2. SPECIFIC DERIVED EXCEPTION: Insufficient Funds
class InsufficientFundsException : public BankingException {
private:
    double currentBalance;
    double requestedAmount;

public:
    InsufficientFundsException(double balance, double requested)
        : BankingException("Insufficient funds available for this transaction."),
          currentBalance(balance), requestedAmount(requested) {}

    double getBalance() const { return currentBalance; }
    double getRequested() const { return requestedAmount; }
};

// 3. SPECIFIC DERIVED EXCEPTION: Invalid Amount
class InvalidAmountException : public BankingException {
public:
    explicit InvalidAmountException(const std::string& details)
        : BankingException("Invalid amount error: " + details) {}
};

// 4. BANK ACCOUNT CLASS
class BankAccount {
private:
    std::string accountNumber;
    double balance;

public:
    BankAccount(std::string accNum, double initialBalance)
        : accountNumber(std::move(accNum)), balance(initialBalance) {
        if (initialBalance < 0.0) {
            throw InvalidAmountException("Initial account balance cannot be negative.");
        }
    }

    void deposit(double amount) {
        if (amount <= 0.0) {
            throw InvalidAmountException("Deposit amount must be strictly greater than zero.");
        }
        balance += amount;
        std::cout << "[SUCCESS] Deposited ₹" << amount << ". New Balance: ₹" << balance << "\n";
    }

    void withdraw(double amount) {
        if (amount <= 0.0) {
            throw InvalidAmountException("Withdrawal amount must be strictly greater than zero.");
        }
        if (amount > balance) {
            throw InsufficientFundsException(balance, amount);
        }
        balance -= amount;
        std::cout << "[SUCCESS] Withdrawn ₹" << amount << ". Remaining Balance: ₹" << balance << "\n";
    }

    double getBalance() const { return balance; }
};

int main() {
    std::cout << "========================================\n";
    std::cout << "      BANKING EXCEPTION HANDLING DEMO   \n";
    std::cout << "========================================\n\n";

    // Test Scenario A: Triggering InvalidAmountException
    try {
        BankAccount account("ACC9988", 5000.0);
        std::cout << "Account created with opening balance: ₹5000.0\n";
        
        std::cout << "\nAttempting invalid deposit of -₹500...\n";
        account.deposit(-500.0);
    } 
    catch (const InvalidAmountException& e) {
        std::cout << "[Caught Specific Exception] " << e.what() << "\n";
    } 
    catch (const BankingException& e) {
        std::cout << "[Caught Base Exception] " << e.what() << "\n";
    }

    std::cout << "\n----------------------------------------\n\n";

    // Test Scenario B: Triggering InsufficientFundsException
    try {
        BankAccount account("ACC9988", 3000.0);
        std::cout << "Account created with opening balance: ₹3000.0\n";

        std::cout << "\nAttempting withdrawal of ₹4500...\n";
        account.withdraw(4500.0);
    } 
    catch (const InsufficientFundsException& e) {
        std::cout << "[Caught Specific Exception] " << e.what() << "\n";
        std::cout << "-> Details: Available Balance = ₹" << e.getBalance() 
                  << ", Attempted Withdrawal = ₹" << e.getRequested() << "\n";
    } 
    catch (const BankingException& e) {
        std::cout << "[Caught Base Exception] " << e.what() << "\n";
    }

    std::cout << "\n========================================\n";
    std::cout << "       Shreyas Shirke       \n";
    std::cout << "========================================\n";

    return 0;
}
