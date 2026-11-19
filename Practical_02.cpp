 #include <iostream>
#include <string>
#include <vector>
#include <memory>

// 1. ABSTRACT BASE CLASS (Abstraction)
class Vehicle {
protected:
    std::string brand;
    std::string model;
    int year;

public:
    // Constructor with member initializer list
    Vehicle(std::string b, std::string m, int y) 
        : brand(std::move(b)), model(std::move(m)), year(y) {}

    // Virtual destructor for safe polymorphic deletion
    virtual ~Vehicle() = default;

    // Pure virtual function (makes Vehicle an abstract class)
    virtual void startEngine() const = 0;

    // Virtual function for polymorphism
    virtual void displayInfo() const {
        std::cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year << "\n";
    }

    // Encapsulation: Getter methods
    std::string getBrand() const { return brand; }
    std::string getModel() const { return model; }
    int getYear() const { return year; }
};

// 2. FIRST-LEVEL DERIVED CLASS: Car
class Car : public Vehicle {
protected:
    int numDoors;

public:
    Car(std::string b, std::string m, int y, int doors)
        : Vehicle(std::move(b), std::move(m), y), numDoors(doors) {}

    void startEngine() const override {
        std::cout << "[Car] Vroom! Internal combustion engine started for " << brand << " " << model << ".\n";
    }

    void displayInfo() const override {
        Vehicle::displayInfo();
        std::cout << "Type: Standard Car | Doors: " << numDoors << "\n";
    }
};

// 3. SECOND-LEVEL DERIVED CLASS: ElectricCar (Multilevel Inheritance)
class ElectricCar : public Car {
private:
    int batteryCapacityKWh;

public:
    ElectricCar(std::string b, std::string m, int y, int doors, int battery)
        : Car(std::move(b), std::move(m), y, doors), batteryCapacityKWh(battery) {}

    void startEngine() const override {
        std::cout << "[ElectricCar] Silent hum... Electric powertrain initialized for " << brand << " " << model << ".\n";
    }

    void displayInfo() const override {
        Vehicle::displayInfo();
        std::cout << "Type: Electric Vehicle | Doors: " << numDoors 
                  << " | Battery: " << batteryCapacityKWh << " kWh\n";
    }
};

// 4. ANOTHER DERIVED CLASS: Truck
class Truck : public Vehicle {
private:
    double payloadCapacityTons;

public:
    Truck(std::string b, std::string m, int y, double payload)
        : Vehicle(std::move(b), std::move(m), y), payloadCapacityTons(payload) {}

    void startEngine() const override {
        std::cout << "[Truck] Heavy-duty diesel engine roaring to life for " << brand << " " << model << ".\n";
    }

    void displayInfo() const override {
        Vehicle::displayInfo();
        std::cout << "Type: Heavy Truck | Payload Capacity: " << payloadCapacityTons << " Tons\n";
    }
};

int main() {
    std::cout << "========================================\n";
    std::cout << "     VEHICLE CLASS HIERARCHY DEMO       \n";
    std::cout << "========================================\n\n";

    // Runtime Polymorphism using Smart Pointers (`std::unique_ptr`) stored in a vector
    std::vector<std::unique_ptr<Vehicle>> garage;

    garage.push_back(std::make_unique<Car>("Honda", "Civic", 2022, 4));
    garage.push_back(std::make_unique<ElectricCar>("Tesla", "Model 3", 2024, 4, 75));
    garage.push_back(std::make_unique<Truck>("Ford", "F-150", 2023, 1.5));

    // Iterating through the collection polymorphically
    for (size_t i = 0; i < garage.size(); ++i) {
        std::cout << "--- Vehicle #" << (i + 1) << " ---\n";
        garage[i]->startEngine();
        garage[i]->displayInfo();
        std::cout << "\n";
    }

    std::cout << "========================================\n";
    std::cout << "     Shreyas Shirke         \n";
    std::cout << "========================================\n";

    return 0;
}
