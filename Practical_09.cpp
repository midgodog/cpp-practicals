#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

// Generic Stack Class Template
template <typename T>
class Stack {
private:
    std::vector<T> elements; // Underlying container

public:
    // Push an element onto the stack
    void push(const T& val) {
        elements.push_back(val);
    }

    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow: Cannot pop from an empty stack!");
        }
        elements.pop_back();
    }

    // Return the top element without removing it
    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty: No top element available!");
        }
        return elements.back();
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Get the current size of the stack
    size_t size() const {
        return elements.size();
    }

    // Display stack elements
    void display() const {
        std::cout << "[Bottom -> Top]: ";
        for (const auto& item : elements) {
            std::cout << item << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    std::cout << "========================================\n";
    std::cout << "      GENERIC TEMPLATE STACK DEMO       \n";
    std::cout << "========================================\n\n";

    // 1. Testing with Integer Stack
    std::cout << "--- 1. Testing Stack<int> ---\n";
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.display();
    
    std::cout << "Top element: " << intStack.peek() << "\n";
    intStack.pop();
    std::cout << "After one pop:\n";
    intStack.display();

    // 2. Testing with Float Stack
    std::cout << "\n--- 2. Testing Stack<float> ---\n";
    Stack<float> floatStack;
    floatStack.push(3.14f);
    floatStack.push(6.28f);
    floatStack.push(9.42f);
    floatStack.display();
    
    std::cout << "Top element: " << floatStack.peek() << "\n";
    floatStack.pop();
    std::cout << "After one pop:\n";
    floatStack.display();

    // 3. Testing with std::string Stack
    std::cout << "\n--- 3. Testing Stack<std::string> ---\n";
    Stack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("C++");
    stringStack.push("Templates");
    stringStack.display();

    std::cout << "Top element: " << stringStack.peek() << "\n";
    stringStack.pop();
    std::cout << "After one pop:\n";
    stringStack.display();

    std::cout << "\n========================================\n";
    std::cout << "       Shreyas Shirke        \n";
    std::cout << "========================================\n";

    return 0;
}
