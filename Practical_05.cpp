#include <iostream>
#include <string>
#include <vector>
#include <memory>

// 1. BASE CLASS: Person
class Person {
protected:
    std::string name;
    int age;
    std::string email;

public:
    Person(std::string n, int a, std::string e)
        : name(std::move(n)), age(a), email(std::move(e)) {}

    virtual ~Person() = default;

    virtual void displayInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << ", Email: " << email << "\n";
    }

    std::string getName() const { return name; }
};

// 2. DERIVED CLASS: Student (Inherits from Person)
class Student : public Person {
protected:
    std::string studentId;
    std::string major;
    double gpa;

public:
    Student(std::string n, int a, std::string e, std::string id, std::string maj, double g)
        : Person(std::move(n), a, std::move(e)), studentId(std::move(id)), major(std::move(maj)), gpa(g) {}

    void displayInfo() const override {
        Person::displayInfo();
        std::cout << "Student ID: " << studentId << ", Major: " << major << ", GPA: " << gpa << "\n";
    }
};

// 3. MULTI-LEVEL DERIVED CLASS: GraduateStudent (Inherits from Student)
class GraduateStudent : public Student {
private:
    std::string thesisTitle;
    std::string researchAdvisor;

public:
    GraduateStudent(std::string n, int a, std::string e, std::string id, std::string maj, double g, 
                    std::string thesis, std::string advisor)
        : Student(std::move(n), a, std::move(e), std::move(id), std::move(maj), g),
          thesisTitle(std::move(thesis)), researchAdvisor(std::move(advisor)) {}

    void displayInfo() const override {
        Student::displayInfo();
        std::cout << "Thesis Title: \"" << thesisTitle << "\" | Advisor: " << researchAdvisor << "\n";
    }
};

int main() {
    std::cout << "========================================\n";
    std::cout << "   UNIVERSITY MANAGEMENT HIERARCHY DEMO \n";
    std::cout << "========================================\n\n";

    // Polymorphic container holding base class pointers
    std::vector<std::unique_ptr<Person>> universityDirectory;

    universityDirectory.push_back(std::make_unique<Person>("Dr. Sharma", 45, "sharma@uni.edu"));
    universityDirectory.push_back(std::make_unique<Student>("Aarav Patel", 20, "aarav@uni.edu", "CS202401", "Computer Science", 8.8));
    universityDirectory.push_back(std::make_unique<GraduateStudent>("Priya Sharma", 24, "priya@uni.edu", "GS202499", "Cybersecurity", 9.2, "AI-Driven Threat Detection", "Dr. Rao"));

    for (size_t i = 0; i < universityDirectory.size(); ++i) {
        std::cout << "--- Record #" << (i + 1) << " ---\n";
        universityDirectory[i]->displayInfo();
        std::cout << "\n";
    }

    std::cout << "========================================\n";
    std::cout << "       Shreyas Shirke      \n";
    std::cout << "========================================\n";

    return 0;
}
