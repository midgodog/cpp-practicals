#include <iostream>
#include <memory>
#include <string>
class Resource {
private:
    std::string name;
public:
    Resource(std::string n) : name(std::move(n)) {
        std::cout << "[Acquired] " << name << "\n";
    }
    ~Resource() {
        std::cout << "[Released] " << name << "\n";
    }
    void action() const {
        std::cout << "Executing operation on: " << name << "\n";
    }
};
// 1. std::unique_ptr Demonstration (Exclusive Ownership)
void testUniquePtr() {
    std::cout << "\n--- std::unique_ptr (Exclusive) ---\n";
    
    // Preferred way to create a unique_ptr
    std::unique_ptr<Resource> res1 = std::make_unique<Resource>("FileStream");
    res1->action();

    // std::unique_ptr<Resource> res2 = res1; // ERROR: Copying is explicitly deleted!
    
    // Ownership is transferred via move semantics
    std::unique_ptr<Resource> res2 = std::move(res1);
    
    if (!res1) {
        std::cout << "res1 is now null (ownership transferred).\n";
    }
    res2->action();
} // res2 goes out of scope here; memory is automatically freed (no 'delete' needed).

// 2. std::shared_ptr Demonstration (Shared Ownership)
void testSharedPtr() {
    std::cout << "\n--- std::shared_ptr (Shared) ---\n";
    std::shared_ptr<Resource> sh1 = std::make_shared<Resource>("NetworkSocket");
    std::cout << "Reference count after sh1: " << sh1.use_count() << "\n";

    {
        std::shared_ptr<Resource> sh2 = sh1; // Copying is allowed; increments ref count
        std::cout << "Reference count inside inner scope: " << sh1.use_count() << "\n";
        sh2->action();
    } // sh2 goes out of scope; reference count decrements

    std::cout << "Reference count after inner scope exit: " << sh1.use_count() << "\n";
} // sh1 goes out of scope, ref count drops to 0, memory is automatically freed.

int main() {
    std::cout << "=== SMART POINTER DEMO START by Shreyas Shirke ===\n";
    testUniquePtr();
    testSharedPtr();
    std::cout << "=== PROGRAM TERMINATED CLEANLY ===\n";
    return 0;
}
