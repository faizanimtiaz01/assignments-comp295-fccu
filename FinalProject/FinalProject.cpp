/*
FINAL PROJECT
FAIZAN IMTIAZ CHEEMA - 241605093
SEERAT ROSHAN - 241606780
*/

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

class Renter : public Person {
private:
    string issuerID;

public:
    void issueCar() {

    }

    void returnCar() {

    }

    void viewCar(Car car) {

    }

    void searchByManufacturer(Manufacturer manuf) {

    }

    void payFine() {

    }
};

class RentalCard : public Renter {
private:
    Car rentedCars[];

public:
    RentalCard() {

    }

    void displayRentedCars() {

    }
};

class RentalPlace {
private:
    string name;
    string address;
    RentalWorker workers[];
    Car lotCars[];
    Manufacturer carMakers[];
    Renter renters[];

public:
    RentalPlace() {
        name = "";
        address = "";
    }

    RentalPlace(string name, string address) {
        this->name = name;
        this->address = address;
    }

    void setName(string name) {
        this->name = name;
    }

    void setAddress(string address) {
        this->address = address;
    }

    string getName() {
        return name;
    }

    string getAddress() {
        return address;
    }

    void displayCars() {

    }

    void displayWorkers() {

    }

    void displayRenters() {

    }
};

class Car {
private:
    string carID;
    Manufacturer manufacturer;
    string colour;
    bool isRented;

public:
    Car() {
        carID = "";
        colour = "";
        isRented = false;
    }

    Car(string carID, Manufacturer manufacturer, string colour, bool isRented) {
        this->carID = carID;
        this->manufacturer = manufacturer;
        this->colour = colour;
        this->isRented = isRented;
    }

    void setCarID(string carID) {
        this->carID = carID;
    }

    void setManufacturer(Manufacturer manufacturer) {
        this->manufacturer = manufacturer;
    }

    void setColour(string colour) {
        this->colour = colour;
    }

    string getCarID() {
        return carID;
    }

    Manufacturer getManufacturer() {
        return manufacturer;
    }

    string getColour() {
        return colour;
    }

    void displayCar() {

    }
};


class Manufacturer {
private:
    string name;
    Car producedCars[];

public:
    Manufacturer() {
        name = "";
    }

    Manufacturer(string name) {
        this->name = name;
    }

    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }

    void displayManufacturer() {

    }
};

int main() {

    return 0;
}
