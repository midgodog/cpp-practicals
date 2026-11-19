 #include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <iomanip>

// 1. ABSTRACT BASE CLASS
class Shape {
public:
    // Pure virtual function making Shape abstract
    virtual double area() const = 0;
    
    // Virtual destructor for safe polymorphic cleanup
    virtual ~Shape() = default;

    virtual void display() const = 0;
};

// 2. DERIVED CLASS: Circle
class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    void display() const override {
        std::cout << "Circle -> Radius: " << radius << ", Area: " << area() << "\n";
    }
};

// 3. DERIVED CLASS: Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    void display() const override {
        std::cout << "Rectangle -> Width: " << width << ", Height: " << height << ", Area: " << area() << "\n";
    }
};

// 4. DERIVED CLASS: Triangle
class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double area() const override {
        return 0.5 * base * height;
    }

    void display() const override {
        std::cout << "Triangle -> Base: " << base << ", Height: " << height << ", Area: " << area() << "\n";
    }
};

int main() {
    std::cout << "========================================\n";
    std::cout << "       SHAPE AREA POLYMORPHISM DEMO     \n";
    std::cout << "========================================\n\n";

    // Set output formatting for floating-point numbers
    std::cout << std::fixed << std::setprecision(2);

    // Polymorphic collection using smart pointers
    std::vector<std::unique_ptr<Shape>> shapes;

    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));
    shapes.push_back(std::make_unique<Triangle>(3.0, 8.0));

    // Iterating through shapes polymorphically
    for (size_t i = 0; i < shapes.size(); ++i) {
        std::cout << "Shape #" << (i + 1) << ": ";
        shapes[i]->display();
    }

    std::cout << "\n========================================\n";
    std::cout << "       Shreyas Shirke    \n";
    std::cout << "========================================\n";

    return 0;
}
