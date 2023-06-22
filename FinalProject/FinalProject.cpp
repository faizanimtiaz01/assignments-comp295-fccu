#include <iostream>
#include <limits>
#include <string>
#include <fstream>

using namespace std;

class Person {
private:
    string name;
    string cnic;

public:
    Person() {
        name = "";
        cnic = "";
    }

    Person(string name, string cnic) {
        this->name = name;
        this->cnic = cnic;
    }

    void setName(string name) {
        this->name = name;
    }

    void setCnic(string cnic) {
        this->cnic = cnic;
    }

    string getName() {
        return name;
    }

    string getCnic() {
        return cnic;
    }

    bool login() {
        return false;
    }
};

class RentalWorker : public Person {
private:
    string id;
    string password;

public:
    RentalWorker() {
        id = "";
        password = "";
    }

    RentalWorker(string id, string password) {
        this->id = id;
        this->password = password;
    }

    void setId(string id) {
        this->id = id;
    }

    void setPassword(string password) {
        this->password = password;
    }

    string getId() {
        return id;
    }

    string getPassword() {
        return password;
    }

    void addCar() {

    }

    void removeCar() {

    }

    void addCustomer() {

    }

    void removeCustomer() {

    }
};