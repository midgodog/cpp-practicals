
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Student {
    int id;
    string name;
    double marks;
};

int main() {

    cout << "========================================\n";
    cout << "       CSV STUDENT RECORD SYSTEM\n";
    cout << "========================================\n";
    cout << "Submitted by: Shreyas Ganesh Shirke\n";
    cout << "Roll No: E26B00S1246\n\n";

    // Open CSV file for reading and writing
    fstream file("students.csv",
                 ios::in | ios::out | ios::trunc | ios::binary);

    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    Student students[] = {
        {101, "Aarav Patel", 85.5},
        {102, "Priya Sharma", 92.0},
        {103, "Rohan Verma", 78.5}
    };

    streampos positions[3];

    // 1. Write CSV header
    file << "ID,Name,Marks\n";

    // 2. Write student records
    cout << "--- Writing Student Records ---\n";

    for (int i = 0; i < 3; i++) {

        positions[i] = file.tellp();

        file << students[i].id << ","
             << students[i].name << ","
             << fixed << setprecision(2)
             << students[i].marks << "\n";

        cout << "Written: " << students[i].name << endl;
    }

    file.flush();

    // 3. Demonstrate tellp()
    cout << "\ntellp(): Current write position = "
         << file.tellp() << endl;

    // 4. Demonstrate seekg() and tellg()
    file.seekg(positions[1]);

    cout << "\nseekg(): Moved read position to second record\n";

    cout << "tellg(): Current read position = "
         << file.tellg() << endl;

    string line;
    getline(file, line);

    cout << "Record read using seekg(): "
         << line << endl;

    // 5. Demonstrate seekp()
    file.clear();

    file.seekp(positions[1]);

    // Update second student's marks
    file << "102,Priya Sharma,95.00\n";

    file.flush();

    cout << "\nseekp(): Moved write position to second record\n";

    cout << "tellp(): Current write position = "
         << file.tellp() << endl;

    // 6. Read all updated CSV records
    file.clear();
    file.seekg(0);

    cout << "\n--- Final CSV Records ---\n";

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();

    cout << "\nStudent records saved successfully in students.csv\n";

    cout << "\n========================================\n";
    cout << "Submitted by: Shreyas Ganesh Shirke\n";
    cout << "Roll No: E26B00S1246\n";
    cout << "========================================\n";

    return 0;
}

