#include <iostream>

class Event {
public:
    virtual Event* clone() const {
        return new Event(*this);
    }

    virtual void execute() {
        std::cout << "Base Event" << std::endl;
    }
};

class CustomEvent : public Event {
public:
    CustomEvent(int value) : value(value) {}

    CustomEvent* clone() const override {
        return new CustomEvent(*this);
    }

    void execute() override {
        std::cout << "Custom Event: " << value << std::endl;
    }

private:
    int value;
};

int main() {
    Event* event1 = new CustomEvent(42);
    Event* event2 = event1->clone(); // Глубокое копирование объекта с динамическим полиморфизмом

    event1->execute();
    event2->execute();

    delete event1;
    delete event2;

    return 0;
}
