#include <iostream>
#include <algorithm>
#include <utility>
#include <string>

class Buffer {
private:
    size_t size;
    int* data;
    std::string name;

public:
    // 1. Default Constructor
    Buffer() : size(0), data(nullptr), name("Default") {
        std::cout << "[Default Constructor] Created empty buffer: " << name << "\n";
    }

    // 2. Parameterized Constructor
    Buffer(size_t s, std::string n) : size(s), data(new int[s]{}), name(std::move(n)) {
        std::cout << "[Parameterized Constructor] Created '" << name << "' of size " << size << "\n";
    }

    // --- THE RULE OF FIVE ---

    // 3. Destructor
    ~Buffer() {
        delete[] data;
        std::cout << "[Destructor] Cleaned up memory for '" << name << "'\n";
    }

    // 4. Copy Constructor (Deep Copy)
    Buffer(const Buffer& other) 
        : size(other.size), data(new int[other.size]), name(other.name + "_copy") {
        std::copy(other.data, other.data + other.size, data);
        std::cout << "[Copy Constructor] Deep copied '" << other.name << "' to '" << name << "'\n";
    }

    // 5. Copy Assignment Operator (Copy-and-Swap Idiom)
    Buffer& operator=(const Buffer& other) {
        std::cout << "[Copy Assignment] Copying '" << other.name << "' into '" << name << "'\n";
        if (this != &other) {
            Buffer temp(other); // Create a temporary deep copy
            swap(*this, temp);  // Swap resources
        }
        return *this;
    }

    // 6. Move Constructor (Resource Stealing)
    Buffer(Buffer&& other) noexcept 
        : size(other.size), data(other.data), name(std::move(other.name) + "_moved") {
        other.size = 0;
        other.data = nullptr;
        std::cout << "[Move Constructor] Stole resources into '" << name << "'\n";
    }

    // 7. Move Assignment Operator
    Buffer& operator=(Buffer&& other) noexcept {
        std::cout << "[Move Assignment] Moving resources into '" << name << "'\n";
        if (this != &other) {
            delete[] data; // Release current resources
            
            size = other.size;
            data = other.data;
            name = std::move(other.name);

            other.size = 0;
            other.data = nullptr;
        }
        return *this;
    }

    // Friend swap function for copy-and-swap idiom
    friend void swap(Buffer& first, Buffer& second) noexcept {
        using std::swap;
        swap(first.size, second.size);
        swap(first.data, second.data);
        swap(first.name, second.name);
    }

    void display() const {
        std::cout << "-> Buffer Name: " << name << ", Size: " << size << ", Data Ptr: " << data << "\n";
    }
};

int main() {
    std::cout << "=== 1. Creating Objects ===\n";
    Buffer b1(10, "Alpha");
    Buffer b2; // Default constructor

    std::cout << "\n=== 2. Copy Constructor ===\n";
    Buffer b3 = b1; // Invokes Copy Constructor
    b3.display();

    std::cout << "\n=== 3. Move Constructor ===\n";
    Buffer b4 = std::move(b1); // Invokes Move Constructor
    b4.display();
    b1.display(); // b1's resources have been stolen (nullified)

    std::cout << "\n=== 4. Copy Assignment Operator ===\n";
    Buffer b5(5, "Beta");
    b5 = b3; // Invokes Copy Assignment Operator
    b5.display();

    std::cout << "\n=== 5. Move Assignment Operator ===\n";
    Buffer b6(3, "Gamma");
    b6 = std::move(b3); // Invokes Move Assignment Operator
    b6.display();

    std::cout << "\n=== Program Ending by Shreyas Shirke (Destructors called automatically) ===\n";
    return 0;
}
