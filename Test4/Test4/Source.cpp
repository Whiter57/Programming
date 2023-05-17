#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Truck {
    string make_model;
    int max_load_capacity;
    int max_volume_capacity;
    bool is_available;
};

struct Driver {
    string name;
    Truck truck;
    int total_loads_carried;
    int total_earnings;

    bool operator==(const Driver& other) const {
        return name == other.name && truck.make_model == other.truck.make_model;
    }
};

struct Application {
    int load_capacity;
    int volume_capacity;
    string destination;
    int price;
};

struct Flight {
    Application application;
    Driver* driver;
    string note;
};

int main() {
    setlocale(LC_ALL, "");
    vector<Truck> available_trucks = {
        {"Volvo", 3000, 50, true},
        {"Man", 3500, 60, true},
        {"Scania", 4000, 70, true},
        {"Renault", 2500, 40, true}
    };

    vector<Driver> drivers = {
        {"����", available_trucks[0], 0, 0},
        {"����", available_trucks[1], 0, 0},
        {"���", available_trucks[2], 0, 0},
        {"���������", available_trucks[3], 0, 0}
    };

    vector<Flight> flights;

    cout << "������� ����������������, ����������� ��� �����: ";
    int load_capacity;
    cin >> load_capacity;
    cout << "������� ����� �������, ����������� ��� �����: ";
    int volume_capacity;
    cin >> volume_capacity;
    cout << "������� ����� ���������� ������: ";
    string destination;
    cin.ignore();
    getline(cin, destination);
    cout << "������� ���� ������ : ";
    int price;
    cin >> price;

    Application application = { load_capacity, volume_capacity, destination, price };

    auto it = find_if(available_trucks.begin(), available_trucks.end(), [&](const Truck& truck) {
        return truck.is_available && truck.max_load_capacity >= application.load_capacity && truck.max_volume_capacity >= application.volume_capacity;
        });

    if (it != available_trucks.end()) {
        Truck& truck = *it;
        truck.is_available = false;

        auto it2 = find_if(drivers.begin(),
            drivers.end(), [&](const Driver& driver) {
                return driver.truck.make_model == truck.make_model;
            });    if (it2 != drivers.end()) {
                Driver& driver = *it2;
                driver.total_loads_carried++;
                driver.total_earnings += application.price;

                Flight flight = { application, &driver, "" };
                flights.push_back(flight);

                cout << "������� ���������� � �����: ";
                cin.ignore();
                getline(cin, flight.note);

                cout << "���� �������� �� " << driver.name << " � ���������� " << driver.truck.make_model << endl;
                cout << "����������������: " << application.load_capacity << " ����" << endl;
                cout << "�������: " << application.volume_capacity << " ���������� ������" << endl;
                cout << "Destination: " << application.destination << endl;
                cout << "����: $" << application.price << endl;
                cout << "����������: " << flight.note << endl;
            }
            else {
                cout << "�������� ��������� �� ������" << endl;
            }
    }
    else {
        cout << "�� ������ ��������� �������� ��� ����� ������" << endl;
    }

    int total_loads_carried = 0;
    int total_earnings = 0;
    int max_earnings = 0;
    string driver_with_max_earnings;
    vector<int> loads_per_driver(drivers.size());
    vector<int> loads_per_destination;
    vector<string> destinations;

    for (const Flight& flight : flights) {
        total_loads_carried++;
        total_earnings += flight.application.price;

        loads_per_driver[distance(drivers.begin(), find(drivers.begin(), drivers.end(), *(flight.driver)))]++;

        auto it = find(destinations.begin(), destinations.end(), flight.application.destination);
        if (it != destinations.end()) {
            int index = distance(destinations.begin(), it);
            loads_per_destination[index]++;
        }
        else {
            destinations.push_back(flight.application.destination);
            loads_per_destination.push_back(1); 
        }

        if (flight.driver->total_earnings > max_earnings) {
            max_earnings = flight.driver->total_earnings;
            driver_with_max_earnings = flight.driver->name;
        }
    }

    cout << "\n---����������---" << endl;
    cout << "����� ���������� ������: " << total_loads_carried << endl;
    cout << "����� �����: $" << total_earnings << endl;
    cout << "������� �� ������ ��������:" << endl;
    for (int i = 0; i < drivers.size(); i++) {
        cout << drivers[i].name << ": " << loads_per_driver[i] << endl;
    }
    cout << "�����, ����������� �� ������� ����������:" << endl;
    for (int i = 0; i < destinations.size(); i++) {
        cout << destinations[i] << ": " << loads_per_destination[i] << endl;
    }
    cout << "�������� � ����� ������� ����������: " << driver_with_max_earnings << " ($" << max_earnings << ")" << endl;

    ofstream log_file("completed_trips.log", ios::app);

    for (const Flight& flight : flights) {
        log_file << "��������: " << flight.driver->name << endl;
        log_file << "���������: " << flight.driver->truck.make_model << endl;
        log_file << "����������������: " << flight.application.load_capacity << " ����" << endl;
        log_file << "�����: " << flight.application.volume_capacity << " cubic feet" << endl;
        log_file << "����� ����������: " << flight.application.destination << endl;
        log_file << "����: $" << flight.application.price << endl;
        log_file << "����������: " << flight.note << endl;
        log_file << endl;
    }

    log_file.close();
}