/*
 Modify the class OverflowCounter of execise 10 so that it informs a single observer, when an overflow has
 occurred. The Observer is an interface class that any class can implement, if it wants to be informed about
 an overflow. Usually this class is a class that uses the counter. The advantage of this pattern is that when
 the OverflowCounter class has been implemented and tested, it does not need any modification even when we use
 it from any kind of “counter user objects”. Only thing we need to do to get our counter user class to be
 informed is to implement the Observer interface in the counter user class.

To make this work and see how it works in practice you need the following modifications to the OverflowCounter
class:
 • Add a data member that points to the Observer interface class. Observer* obs;
 • Add function SetObserver, that sets the pointer member to point to any object that implements the
 Observer interface.
   void SetObserver(Observer *)
 • Add private function Notify, that informs the observer by calling the function HandleLimitReached() of the
 observer.
Only one function is needed in the interface of the observer. The function is called HandleLimitReached.
This function is used in a way to pass the message “Limit has been reached” from the OverflowCounter to the
observer. This member function of observer is called from the member function Notify of the OverflowCounter.

class Observer {
public:
virtual void HandleLimitReached() = 0;
};

To test the new version of OverflowCounter, write a class CounterUser, that uses an overflow counter. It has an
OverflowCounter as a data member and it implements the observer interface. To keep the test class as simple as
possible only the following member functions are necessary:
    • Constructor where the limited counter is initialized with a limit value (5 for example). In the constructor body CounterUser object (“this”) is set as the observer of the OverflowCounter.
    • IncrementBy, where counter is incremented n times, where n is passed as a parameter.
    • HandleLimitReached() that displays that the limit has been reached.

Use the following test program where CounterUser object is declared, member function IncrementBy is called (with
parameter value 12). When you run the program, you should see the message “Limit reached” twice from the first
counter user, because limit is 5 and number of increments is 12) and once from the second.

void main() {
    CounterUser cu(5);
    cu.IncrementBy(12); //OUTPUT: two times "Limit has been reached"
    CounterUser cu2(9);
    cu2.IncrementBy(9);
    std::cout << "Just passing time" << std::endl;
    cu2.IncrementBy(1); //OUTPUT: "Limit has been reached"
}
*/

#include <iostream>

// Observer Interface
class Observer {
public:
    virtual void HandleLimitReached() = 0;  // Pure virtual function to handle the limit reached notification
    virtual ~Observer() = default;          // Virtual destructor for proper cleanup of derived classes
};

// Base Counter class
class Counter {
public:
    virtual void inc() = 0;                 // Pure virtual function to increment the counter
    virtual void dec() = 0;                 // Pure virtual function to decrement the counter
    virtual explicit operator int() = 0;    // Pure virtual function to get the counter value as int
    virtual ~Counter() = default;           // Virtual destructor for proper cleanup of derived classes
};

// OverflowCounter class implementing Counter
class OverflowCounter final : public Counter {
public:
    // Constructor initializing the counter and upper limit
    OverflowCounter(const int initial, const int upperLimit)
        : obs(nullptr), counter(initial), upperLimit(upperLimit) {}

    // Increment counter with overflow behavior
    void inc() override {
        if (counter < upperLimit) {
            counter++;
        } else {
            counter = 0;  // Overflow, reset to 0
            Notify();     // Notify the observer when overflow occurs
        }
    }

    // Decrement counter with underflow behavior
    void dec() override {
        if (counter > 0) {
            counter--;
        } else {
            counter = upperLimit;  // Underflow, reset to upper limit
        }
    }

    // Convert counter value to int
    explicit operator int() override { return counter; }

    // Set observer to notify on overflow
    void SetObserver(Observer *obs) {
        this->obs = obs;
    }

    ~OverflowCounter() override = default;

private:
    Observer *obs;       // Observer to be notified
    int counter;         // Current counter value
    int upperLimit;      // Maximum limit for the counter

    // Notify the observer if one is set
    void Notify() const {
        if (obs) {
            obs->HandleLimitReached();
        }
    }
};

// CounterUser class that uses the OverflowCounter and implements Observer
class CounterUser final : public Observer {
public:
    // Constructor initializing the counter with the upper limit
    explicit CounterUser(const int upperLimit) : oc(0, upperLimit) {
        oc.SetObserver(this);  // Set the current object as observer for the OverflowCounter
    }

    // Increment the counter by a given number of times
    void IncrementBy(const int n) {
        for (int i = 0; i < n; ++i) {
            oc.inc();
            std::cout << "Counter value: " << static_cast<int>(oc) << std::endl;
        }
    }

    // Implementation of the observer method to handle limit reached
    void HandleLimitReached() override {
        std::cout << "Limit has been reached" << std::endl;
    }

private:
    OverflowCounter oc;  // OverflowCounter instance
};

// Test program
int main() {
    CounterUser cu(5);       // Create a CounterUser with limit 5
    cu.IncrementBy(12);      // OUTPUT: "Limit has been reached" twice

    CounterUser cu2(9);      // Create another CounterUser with limit 9
    cu2.IncrementBy(9);      // No limit reached
    std::cout << "Just passing time" << std::endl;
    cu2.IncrementBy(1);      // OUTPUT: "Limit has been reached"

    return 0;
}
