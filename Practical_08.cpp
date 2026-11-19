#include <iostream>
#include <memory>
#include <string>

// 1. Product Interface
class ILogger {
public:
    virtual ~ILogger() = default;
    virtual void log(const std::string& message) const = 0;
};

// 2. Concrete Product A: Console Logger
class ConsoleLogger : public ILogger {
public:
    void log(const std::string& message) const override {
        std::cout << "[CONSOLE LOG] " << message << "\n";
    }
};

// 3. Concrete Product B: File Logger (Simulated)
class FileLogger : public ILogger {
public:
    void log(const std::string& message) const override {
        std::cout << "[FILE LOG (Simulated)] Writing to system.log -> " << message << "\n";
    }
};

// 4. Factory Class
class LoggerFactory {
public:
    // Static factory method to create and return loggers polymorphically
    static std::unique_ptr<ILogger> createLogger(const std::string& type) {
        if (type == "console") {
            return std::make_unique<ConsoleLogger>();
        } else if (type == "file") {
            return std::make_unique<FileLogger>();
        }
        return nullptr; // Unknown type
    }
};

int main() {
    std::cout << "========================================\n";
    std::cout << "      FACTORY DESIGN PATTERN DEMO       \n";
    std::cout << "========================================\n\n";

    // Client requests a console logger without knowing its concrete class
    std::unique_ptr<ILogger> logger1 = LoggerFactory::createLogger("console");
    if (logger1) {
        logger1->log("Server initialized on port 8080.");
    }

    // Client requests a file logger dynamically (e.g., based on config files)
    std::unique_ptr<ILogger> logger2 = LoggerFactory::createLogger("file");
    if (logger2) {
        logger2->log("Database connection timeout occurred.");
    }



    std::cout << "\n========================================\n";
    std::cout << "       Shreyas Shirke       \n";
    std::cout << "========================================\n";

    return 0;
}
