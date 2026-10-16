#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>

struct Customer {
    int arrivalTime;
    int serviceTime;
    int waitingTime;
    int timeInSystem;
};

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int numCustomers;

    std::cout << "Enter the number of customers: ";
    std::cin >> numCustomers;

    std::vector<Customer> customers(numCustomers);

    int totalWaitingTime = 0;
    int totalTimeInSystem = 0;
    int totalServiceTime = 0;
    int lastDepartureTime = 0;

    std::cout << "Customer\tArrival Time\tService Time\tWaiting Time\tTime in System\n";

    for (int i = 0; i < numCustomers; ++i) {
        customers[i].arrivalTime = rand() % 7 + 1;
        customers[i].serviceTime = rand() % 6 + 1;

        if (i == 0) {
            customers[i].waitingTime = 0;
        }
        else {
            customers[i].waitingTime = std::max(0, lastDepartureTime - customers[i].arrivalTime);
        }

        customers[i].timeInSystem = customers[i].waitingTime + customers[i].serviceTime;
        totalWaitingTime += customers[i].waitingTime;
        totalTimeInSystem += customers[i].timeInSystem;
        totalServiceTime += customers[i].serviceTime;

        lastDepartureTime = customers[i].arrivalTime + customers[i].waitingTime + customers[i].serviceTime;

        std::cout << i + 1 << "\t\t" << customers[i].arrivalTime << "\t\t"
            << customers[i].serviceTime << "\t\t"
            << customers[i].waitingTime << "\t\t"
            << customers[i].timeInSystem << "\n";
    }

    double avgWaitingTime = static_cast<double>(totalWaitingTime) / numCustomers;
    double avgTimeInSystem = static_cast<double>(totalTimeInSystem) / numCustomers;
    double avgServiceTime = static_cast<double>(totalServiceTime) / numCustomers;

    std::cout << "\nAverage Waiting Time: " << avgWaitingTime << " minutes\n";
    std::cout << "Average Time in System: " << avgTimeInSystem << " minutes\n";
    std::cout << "Average Service Time: " << avgServiceTime << " minutes\n";

    return 0;
}
