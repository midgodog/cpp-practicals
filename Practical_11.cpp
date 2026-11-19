 #include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>

// Fixed-size structure for direct random-access file operations
struct Student {
    int id;
    char name[30];
    double gpa;
};

int main() {
    std::string filename = "students_record.dat";

    // 1. WRITING RECORDS & DEMONSTRATING tellp() / seekp()
    std::ofstream outFile(filename, std::ios::out | std::ios::binary);
    if (!outFile) {
        std::cerr << "Error opening file for writing!\n";
        return 1;
    }

    Student s1 = {101, "Aarav Patel", 8.8};
    Student s2 = {102, "Priya Sharma", 9.2};
    Student s3 = {103, "Rohan Verma", 8.5};

    std::cout << "========================================\n";
    std::cout << "      WRITING RECORDS & tellp()        \n";
    std::cout << "========================================\n";

    std::streampos pos1 = outFile.tellp(); // Get current put position
    std::cout << "Writing s1 at byte offset: " << pos1 << "\n";
    outFile.write(reinterpret_cast<const char*>(&s1), sizeof(Student));

    std::streampos pos2 = outFile.tellp();
    std::cout << "Writing s2 at byte offset: " << pos2 << "\n";
    outFile.write(reinterpret_cast<const char*>(&s2), sizeof(Student));

    std::streampos pos3 = outFile.tellp();
    std::cout << "Writing s3 at byte offset: " << pos3 << "\n";
    outFile.write(reinterpret_cast<const char*>(&s3), sizeof(Student));

    outFile.close();

    // 2. READING RECORDS & DEMONSTRATING tellg() / seekg()
    std::ifstream inFile(filename, std::ios::in | std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening file for reading!\n";
        return 1;
    }

    std::cout << "\n========================================\n";
    std::cout << "      READING RECORDS & seekg()        \n";
    std::cout << "========================================\n";

    // Jump directly to the second record using seekg()
    inFile.seekg(pos2, std::ios::beg);
    std::cout << "Get pointer moved to offset: " << inFile.tellg() << " using seekg()\n";

    Student temp;
    inFile.read(reinterpret_cast<char*>(&temp), sizeof(Student));
    std::cout << "Retrieved Record -> ID: " << temp.id << ", Name: " << temp.name << ", GPA: " << temp.gpa << "\n";

    inFile.close();

    // 3. MODIFYING A RECORD IN-PLACE USING seekp()
    std::fstream ioFile(filename, std::ios::in | std::ios::out | std::ios::binary);
    if (ioFile) {
        std::cout << "\n========================================\n";
        std::cout << "      UPDATING IN-PLACE & seekp()      \n";
        std::cout << "========================================\n";

        // Move put pointer to the exact location of the first record (s1)
        ioFile.seekp(pos1, std::ios::beg);
        std::cout << "Put pointer positioned at offset: " << ioFile.tellp() << " for update\n";

        Student updatedS1 = {101, "Aarav P. (Updated)", 9.1};
        ioFile.write(reinterpret_cast<const char*>(&updatedS1), sizeof(Student));
        ioFile.close();
    }

    // 4. VERIFYING ALL RECORDS
    std::cout << "\n========================================\n";
    std::cout << "         FINAL FILE CONTENTS            \n";
    std::cout << "========================================\n";

    inFile.open(filename, std::ios::in | std::ios::binary);
    while (inFile.read(reinterpret_cast<char*>(&temp), sizeof(Student))) {
        std::cout << "ID: " << temp.id << " | Name: " << std::left << std::setw(20) << temp.name 
                  << " | GPA: " << temp.gpa << "\n";
    }
    inFile.close();

    std::cout << "\n==========================================================\n";
    std::cout << "       PROGRAM TERMINATED CLEANLY BY SHREYAS SHIRKE\n";
    std::cout << "============================================================\n";

    return 0;
}
