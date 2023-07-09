/*
FINAL PROJECT
FAIZAN IMTIAZ CHEEMA - 241605093
SEERAT ROSHAN - 241606780
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class RentalPlace; // Forward declaration

class Person
{
private:
    string name;
    int cnic;

public:
    Person()
    {
        name = "";
        cnic = 0;
    }

    Person(string name, int cnic)
    {
        this->name = name;
        this->cnic = cnic;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setCnic(int cnic)
    {
        this->cnic = cnic;
    }

    string getName()
    {
        return name;
    }

    int getCnic()
    {
        return cnic;
    }
};

class Car
{
protected:
    int carID;
    string colour, manufacturerName;
    bool isRented;

public:
    Car()
    {
        carID = 0;
        colour = "";
        isRented = false;
    }

    Car(int carID, string manufacturer, string colour, bool isRented)
    {
        this->carID = carID;
        this->manufacturerName = manufacturer;
        this->colour = colour;
        this->isRented = isRented;
    }

    void setCarID(int carID)
    {
        this->carID = carID;
    }

    void setManufacturer(string manufacturer)
    {
        this->manufacturerName = manufacturer;
    }

    void setColour(string colour)
    {
        this->colour = colour;
    }
    void setstatus(bool x )
    {
        this->isRented = x;
    }

    int getCarID()
    {
        return carID;
    }

    string getManufacturer()
    {
        return manufacturerName;
    }

    string getColour()
    {
        return colour;
    }

    bool isRentedStatus()
    {
        return isRented;
    }

    void displayCar()
    {
        cout << "Car ID: " << carID << endl;
        cout << "Manufacturer: " << manufacturerName << endl;
        cout << "Colour: " << colour << endl;
        cout << "Rented: " << isRented << endl;
    }
};

class Renter : public Person
{
private:
    int issuerID;

public:
    Renter() : Person()
    {
        issuerID = 0;
    }

    Renter(string name, int cnic, int issuerID) : Person(name, cnic)
    {
        this->issuerID = issuerID;
    }

    void setIssuerID(int issuerID)
    {
        this->issuerID = issuerID;
    }

    int getIssuerID()
    {
        return issuerID;
    }
    void viewCar(Car *car);
    void searchByManufacturer(string manuf);
};

class RentalWorker;

class RentalPlace
{
private:
    int rentalID;
    string name, address;

public:
    RentalPlace()
    {
        rentalID = 0;
        name = "";
        address = "";
    }

    RentalPlace(int rentalID, string name, string address)
    {
        this->rentalID = rentalID;
        this->name = name;
        this->address = address;
    }

    void setRentalID(int rentalID)
    {
        this->rentalID = rentalID;
    }

    int getRentalID()
    {
        return rentalID;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setAddress(string address)
    {
        this->address = address;
    }

    string getRentalName()
    {
        return name;
    }

    string getAddress()
    {
        return address;
    }
    void addWorkers(RentalWorker *worker);
    void displayCars()
    {
        // display cars from lot file
        fstream file;
        file.open("lot.txt", ios::in);
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }

    void displayWorkers()
    {
        // display workers from worker file
        fstream file;
        file.open("worker.txt", ios::in);
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }

    void displayRenters()
    {
        // display renters from renter file
        fstream file;
        file.open("renter.txt", ios::in);
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }
};

class RentalWorker : public Person, public RentalPlace
{
private:
    string username, password;

public:
    RentalWorker() : Person(), RentalPlace()
    {
        username = "";
        password = "";
    }

    RentalWorker(int rentalID, string rentalName, string rentalAddress, string name, int cnic, string username, string password)
        : Person(name, cnic), RentalPlace(rentalID, rentalName, rentalAddress)
    {
        this->username = username;
        this->password = password;
    }

    void setUsername(string username)
    {
        this->username = username;
    }

    void setPassword(string password)
    {
        this->password = password;
    }

    string getUsername()
    {
        return username;
    }

    string getPassword()
    {
        return password;
    }

    void addRenters(Renter *renter)
    {
        // add renter to renter file
        fstream file;
        file.open("renter.txt", ios::app);
        file << renter->getName() << "\t" << renter->getCnic() << "\t" << renter->getIssuerID() << endl;
        file.close();
    }
    void addCar(Car *car)
    {
        // add car to lot file
        fstream file;
        file.open("lot.txt", ios::app);
        file << car->getCarID() << "\t" << car->getManufacturer() << "\t" << car->getColour() << "\t" << car->isRentedStatus() << endl;
        file.close();
    }
    void removeCar(int id)
    {
        // remove car from lot file
        int carID;
        string colour, manufacturerName, str;
        bool isRented;
        fstream file2;
        ofstream file3("temp.txt");
        file2.open("lot.txt", ios::in);
        while (!file2.eof()){
		
        
            getline(file2, str);
            istringstream ss(str);
            ss >> carID >> manufacturerName >> colour >> isRented;
            if (carID != id)
            {
                file3 << carID << "\t" << manufacturerName << "\t" << colour << "\t" << isRented << endl;
            }

    }
        file2.close();
        file3.close();
        // rename temp file to lot file
        remove("lot.txt");
        rename("temp.txt", "lot.txt");
    }
    void addCustomer(Person *customer)
    {
        // add customer to customer file
        fstream file;
        file.open("customer.txt", ios::app);
        file << customer->getName() << "\t" << customer->getCnic() << endl;
        file.close();
    }

    void addRenter(Renter *renter)
    {
        // add renter to renter file
        fstream file;
        file.open("renter.txt", ios::app);
        file << renter->getName() << "\t" << renter->getCnic() << "\t" << renter->getIssuerID() << endl;
        file.close();
    }

    void viewCar(int id)
    {
        // search car in lot file
        int carID;
        string colour, manufacturerName, str;
        bool isRented;
        fstream file;
        file.open("lot.txt", ios::in);
        while (!file.eof()){
		
        
            getline(file, str);
            istringstream ss(str);
            ss >> carID >> manufacturerName >> colour >> isRented;
            if (carID == id)
            {
                cout << "Car ID: " << carID << endl;
                cout << "Manufacturer: " << manufacturerName << endl;
                cout << "Colour: " << colour << endl;
                cout << "Rented: " << isRented << endl;
                break;
            }
        }
         
        file.close();
    }
    void viewCustomer(int cnic)
    {
        // search customer in customer file
        int customerCnic;
        string customerName, str;
        fstream file;
        file.open("customer.txt", ios::in);
         while (!file.eof()){
		 
        
            getline(file, str);
            istringstream ss(str);
            ss >> customerName >> customerCnic;
            if (customerCnic == cnic)
            {
                cout << "Customer Name: " << customerName << endl;
                cout << "Customer CNIC: " << customerCnic << endl;
            }
}
        file.close();
    }
    void viewRenter(int id)
    {
        // search renter in renter file
        int issuerID, cni;
        string renterName, str;
        fstream file;
        file.open("renter.txt", ios::in);
        getline(file, str);
        while (!file.eof())
        {
            istringstream ss(str);
            ss >> renterName >> cni >> issuerID;
            if (issuerID == id)
            {
                cout << "Renter ID: " << issuerID << endl;
                cout << "Renter Name: " << renterName << endl;
                cout << "Renter CNIC: " << cni << endl;
            }
            getline(file, str);
        }
        file.close();
    }
    void viewIssuedCar(int id)
    {
        // search issued car in issued file
        int issuerID, carID;
        string renterName, str;
        fstream file;
        file.open("issued.txt", ios::in);
        getline(file, str);
        while (!file.eof())
        {
            istringstream ss(str);
            ss >> issuerID >> renterName >> carID;
            if (issuerID == id)
            {
                cout << "Renter Name: " << renterName << endl;
                cout << "Renter ID: " << issuerID << endl;
                cout << "Car ID: " << carID << endl;
            }
            getline(file, str);
        }
        file.close();
    }
    void viewAllCars()
    {
        // view all cars in lot file
        int carID;
        string colour, manufacturerName, str;
        bool isRented;
        fstream file;
        file.open("lot.txt", ios::in);
        getline(file, str);
        while (!file.eof())
        {
            istringstream ss(str);
            ss >> carID >> manufacturerName >> colour >> isRented;
            cout << "Car ID: " << carID << endl;
            cout << "Manufacturer: " << manufacturerName << endl;
            cout << "Colour: " << colour << endl;
            cout << "Rented: " << isRented << endl;
            getline(file, str);
        }
        file.close();
    }
    void viewAllCustomers()
    {
        // view all customers in customer file
        int customerCnic;
        string customerName, str;
        fstream file;
        file.open("customer.txt", ios::in);
        getline(file, str);
         while (!file.eof())
        {
            istringstream ss(str);
            ss >> customerName >> customerCnic;
            cout << "Customer Name: " << customerName << endl;
            cout << "Customer CNIC: " << customerCnic << endl;
            getline(file, str);
        }
        file.close();
    }
    void viewAllRenters()
    {
        // view all renters in renter file
        int issuerID;
        string renterName, str;
        fstream file;
        file.open("renter.txt", ios::in);
        getline(file, str);
        while (!file.eof())
        {
            istringstream ss(str);
            ss >> renterName >> issuerID;
            cout << "Renter Name: " << renterName << endl;
            cout << "Renter ID: " << issuerID << endl;
            getline(file, str);
        }
        file.close();
    }
    void viewAllIssuedCars()
    {
        // view all issued cars in issued file
        int issuerID, carID;
        string renterName, str;
        fstream file;
        file.open("issued.txt", ios::in);
        getline(file, str);
        while (!file.eof())
        {
            istringstream ss(str);
            ss >> issuerID >> renterName >> carID;
            cout << "Renter Name: " << renterName << endl;
            cout << "Renter ID: " << issuerID << endl;
            cout << "Car ID: " << carID << endl;
            getline(file, str);
    
        }
        file.close();
    }

    void issueCar(Car *car, int issuerID)
    {
        if (car->isRentedStatus() ==false)
        {
            fstream file;
            file.open("issued.txt", ios::app);
            file << issuerID << "\t" << getName() << "\t" << car->getCarID() << endl;
            file.close();
            int carID;
            string colour, manufacturerName, str;
            bool isRented;
            fstream file2;
            ofstream file3("temp.txt");
            file2.open("lot.txt", ios::in);
            while (!file2.eof()){
			
            
                getline(file2, str);
                istringstream ss(str);
                ss >> carID >> manufacturerName >> colour >> isRented;
                if (carID == car->getCarID())
                {
                    isRented = true;
                    car->setstatus(isRented);
                    file3 << carID << "\t" << manufacturerName << "\t" << colour << "\t" << isRented << endl;
                }
                else
                {
                    file3 << carID << "\t" << manufacturerName << "\t" << colour << "\t" << isRented << endl;
                }
         }
            file2.close();
            file3.close();

            remove("lot.txt");
            rename("temp.txt", "lot.txt");
        }
        else
        {
            cout << "Car is already rented" << endl;
        }
    }
};

void returnCar(Car *car)
{
    int issuerID, carID;
    string name, str;
    fstream file;
    ofstream file2("temp.txt");
    file.open("issued.txt", ios::in);
    while (!file.eof()){	
        getline(file, str);
        istringstream ss(str);
        ss >> issuerID >> name >> carID;
        if (carID != car->getCarID())
        {
            file2 << issuerID << "\t" << name << "\t" << carID << endl;
        }
    }
    
    file.close();
    file2.close();
    remove("issued.txt");
    rename("temp.txt", "issued.txt");
    int carID2;
    string colour, manufacturerName, str2;
    bool isRented;
    fstream file3;
    ofstream file4("temp.txt");
    file3.open("lot.txt", ios::in);
    while (!file3.eof()){
	
        getline(file3, str2);
        istringstream ss(str2);
        ss >> carID2 >> manufacturerName >> colour >> isRented;
        if (carID2 == car->getCarID())
        {
            isRented = false;
            //file4 << carID2 << "\t" << manufacturerName << "\t" << colour << "\t" << isRented << endl;
        }
        
 }
    file3.close();
    file4.close();
    remove("lot.txt");
    rename("temp.txt", "lot.txt");
}

void Renter::viewCar(Car *car)
{
    car->displayCar();
}

void Renter::searchByManufacturer(string manufacturer)
{
    int carID;
    string colour, manufacturerName, str;
    bool isRented;
    fstream file;
    file.open("lot.txt", ios::in);
    while (!file.eof());{
    
        getline(file, str);
        istringstream ss(str);
        ss >> carID >> manufacturerName >> colour >> isRented;
        if (manufacturerName == manufacturer)
        {
            cout << "Car ID: " << carID << endl;
            cout << "Manufacturer: " << manufacturerName << endl;
            cout << "Colour: " << colour << endl;
            cout << "Rented: " << isRented << endl;
        }
}
    file.close();
}
void RentalPlace::addWorkers(RentalWorker *worker)
    {
        // add worker to worker file
        fstream file;
        file.open("worker.txt", ios::app);
        file << this->rentalID << "\t" << this->name << "\t" << this->address << "\t" << worker->getName() << "\t" << worker->getCnic() << "\t" << worker->getUsername() << "\t" << worker->getPassword() << endl;
        file.close();
    }

int main()
{
    fstream file;
    file.open("renter.txt", ios::in);
    file.close();
    Car *car = new Car(1, "Honda", "Red", false);
    Car *car2 = new Car(2, "Ford", "Blue", false);
    Car *car3 = new Car(3, "Toyota", "Green", false);
    Car *car4 = new Car(4, "Honda", "Black", false);
    Renter *renter = new Renter("Ali", 123456789, 123456);
    Renter *renter2 = new Renter("Ahmed", 987654321, 654321);
    RentalPlace *rentalPlace = new RentalPlace(1, "Islamabad F-10", "Showroom");
    RentalWorker *worker1 = new RentalWorker(1, "Islamabad F-10", "Showroom", "Ali", 35202, "ADMIN", "Head222");
    RentalWorker *worker2 = new RentalWorker(2, "Islamabad F-10", "Showroom", "Ahmed", 35202, "WORKER", "Head333");
    int option;
    while (true)
    {
        cout << "-------MAIN MENU-------" << endl;
        cout << "1. Rental Place Menu" << endl;
        cout << "2. Rental Worker Menu" << endl;
        cout << "3. Renter Menu" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter option: ";
        cin >> option;
        if (option == 1)
        {
            while (true)
            {
                cout << "-------RENTAL PLACE MENU-------" << endl;
                cout << "1. Show Details of Rental Place" << endl;
                cout << "2. Add Worker" << endl;
                cout << "3. Display Workers" << endl;
                cout << "4. Display Cars" << endl;
                cout << "5. Display Renters(Customers)" << endl;
                cout << "6. Back" << endl;
                cout << "Enter option: ";
                cin >> option;
                if (option == 1)
                {
                    cout << "-------RENTAL PLACE DETAILS-------" << endl;
                    cout << "ID: " << rentalPlace->getRentalID() << endl;
                    cout << "Name: " << rentalPlace->getRentalName() << endl;
                    cout << "Address: " << rentalPlace->getAddress() << endl;
                }
                else if (option == 2)
                {
                    string name, address, type, username, password;
                    int cnic, id;
                    cout << "Enter ID: ";
                    cin >> id;
                    cout << "Enter Name: ";
                    cin >> name;
                    cout << "Enter CNIC: ";
                    cin >> cnic;
                    cout << "Enter Address: ";
                    cin >> address;
                    cout << "Enter Type: ";
                    cin >> type;
                    cout << "Enter Username: ";
                    cin >> username;
                    cout << "Enter Password: ";
                    cin >> password;
                    RentalWorker *worker = new RentalWorker(id, address, type, name, cnic, type, password);
                    rentalPlace->addWorkers(worker);
                    cout << "Worker added successfully" << endl;
                }
                else if (option == 3)
                {
                    cout << "-------WORKERS-------" << endl;
                    rentalPlace->displayWorkers();
                }
                else if (option == 4)
                {
                    cout << "-------CARS-------" << endl;
                    rentalPlace->displayCars();
                }
                else if (option == 5)
                {
                    cout << "-------RENTERS-------" << endl;
                    rentalPlace->displayRenters();
                }
                else if (option == 6)
                {
                    break;
                }
                else
                {
                    cout << "Invalid option" << endl;
                }
            }
        }
        else if (option == 2)
        {
            while (true)
            {
                cout << "-------RENTAL WORKER MENU-------" << endl;
                cout << "1. Show Details of Rental Worker" << endl;
                cout << "2. Add Car" << endl;
                cout << "3. Remove Car" << endl;
                cout << "4. View Car" << endl;
                cout << "5. Issue Car" << endl;
                cout << "6. Return Car" << endl;
                cout << "7. View Renter" << endl;
                cout << "8. View Issued Car" << endl;
                cout << "9. View All Renters" << endl;
                cout << "10. View All Cars" << endl;
                cout << "11. View All Renters" << endl;
                cout << "12. View All Issued Cars" << endl;
                cout << "13. Add Renter" << endl;
                cout << "14. Back" << endl;
                cout << "Enter option: ";
                cin >> option;
                if (option == 1)
                {
                    cout << "-------RENTAL WORKER DETAILS-------" << endl;
                    cout << "Username: " << worker1->getUsername() << endl;
                    cout << "Password: " << worker1->getPassword() << endl;
                    cout << "Name: " << worker1->getName() << endl;
                    cout << "CNIC: " << worker1->getCnic() << endl;
                    cout << "ID of Rental Place: " << worker1->getRentalID() << endl;
                    cout << "Name of Rental Place: " << worker1->getRentalName() << endl;
                    cout << "Address of Rental Place: " << worker1->getAddress() << endl;
                }
                else if (option == 2)
                {
                    string manufacturerName, colour;
                    int carID;
                    cout << "Enter Car ID: ";
                    cin >> carID;
                    cout << "Enter Manufacturer Name: ";
                    cin >> manufacturerName;
                    cout << "Enter Colour: ";
                    cin >> colour;
                    Car *car = new Car(carID, manufacturerName, colour, false);
                    worker1->addCar(car);
                    cout << "Car added successfully" << endl;
                }
                else if (option == 3)
                {
                    int carID;
                    cout << "Enter Car ID: ";
                    cin >> carID;
                    worker1->removeCar(carID);
                    cout << "Car removed successfully" << endl;
                }
                else if (option == 4)
                {
                    int carID;
                    cout << "Enter Car ID: ";
                    cin >> carID;
                    worker1->viewCar(carID);
                }
                else if (option == 5)
                {
                    int CarIDD, issuerID;
                    cout << "Enter Car ID: ";
                    cin >> CarIDD;
                    cout << "Enter Issuer ID: ";
                    cin >> issuerID;
                    int carID;
                    string colour, manufacturerName, str;
                    bool isRented;
                    fstream file;
                    file.open("lot.txt", ios::in);
                    do
                    {
                        getline(file, str);
                        istringstream ss(str);
                        ss >> carID >> manufacturerName >> colour >> isRented;
                        if (carID == CarIDD)
                        {
                            // car object
                            Car *car = new Car(carID, manufacturerName, colour, isRented);
                            break;
                        }
                    } while (!file.eof());
                    file.close();
                    worker1->issueCar(car, issuerID);
                }
                else if (option == 6)
                {
                    int CarIDD;
                    cout << "Enter Car ID: ";
                    cin >> CarIDD;
                    int carID;
                    string colour, manufacturerName, str;
                    bool isRented;
                    fstream file;
                    file.open("lot.txt", ios::in);
                    while (!file.eof()){
					
                    
                        getline(file, str);
                        istringstream ss(str);
                        ss >> carID >> manufacturerName >> colour >> isRented;
                        if (carID == CarIDD)
                        {
                            // car object
                            Car *car = new Car(carID, manufacturerName, colour, isRented);
                            break;
                        }
                }
                    file.close();
                    returnCar(car);
                }
                else if (option == 7)
                {
                    int issuerID;
                    cout << "Enter Issuer ID: ";
                    cin >> issuerID;
                    worker1->viewRenter(issuerID);
                }
                else if (option == 8)
                {
                    int issuerID;
                    cout << "Enter Issuer ID: ";
                    cin >> issuerID;
                    worker1->viewIssuedCar(issuerID);
                }
                else if (option == 9)
                {
                    worker1->viewAllRenters();
                }
                else if (option == 10)
                {
                    worker1->viewAllCars();
                }
                else if (option == 11)
                {
                    worker1->viewAllRenters();
                }
                else if (option == 12)
                {
                    worker1->viewAllIssuedCars();
                }
                else if (option == 13)
                {
                    string name;
                    int rentalID, cnic;
                    cout << "Enter Name: ";
                    cin >> name;
                    cout << "Enter CNIC: ";
                    cin >> cnic;
                    cout << "Enter Rental ID: ";
                    cin >> rentalID;
                    Renter *newRenter = new Renter(name, cnic, rentalID);
                    worker1->addRenter(newRenter);
                    cout << "Renter added successfully" << endl;
                }
                else if (option == 14)
                {
                    break;
                }
                else
                {
                    cout << "Invalid option" << endl;
                }
            }
        }
        else if (option == 3)
        {
            while (true)
            {
                cout << "-------RENTER MENU-------" << endl;
                cout << "1. Show Details of Renter" << endl;
                cout << "2. View Car" << endl;
                cout << "3. Issue Car" << endl;
                cout << "4. Return Car" << endl;
                cout << "5. Back" << endl;
                cout << "Enter option: ";
                cin >> option;
                if (option == 1)
                {
                    cout << "-------RENTER DETAILS-------" << endl;
                    cout << "Username: " << worker2->getUsername() << endl;
                    cout << "Password: " << worker2->getPassword() << endl;
                    cout << "Name: " << worker2->getName() << endl;
                    cout << "CNIC: " << worker2->getCnic() << endl;
                    cout << "ID of Rental Place: " << worker2->getRentalID() << endl;
                    cout << "Name of Rental Place: " << worker2->getRentalName() << endl;
                    cout << "Address of Rental Place: " << worker2->getAddress() << endl;
                }
                else if (option == 2)
                {
                    int carID;
                    cout << "Enter Car ID: ";
                    cin >> carID;
                    worker2->viewCar(carID);
                }
                else if (option == 3)
                {
                    int CarIDD, issuerID;
                    cout << "Enter Car ID: ";
                    cin >> CarIDD;
                    cout << "Enter Issuer ID: ";
                    cin >> issuerID;
                    int carID;
                    string colour, manufacturerName, str;
                    bool isRented;
                    fstream file;
                    file.open("lot.txt", ios::in);
                     while (!file.eof()){
					 
                    
                        getline(file, str);
                        istringstream ss(str);
                        ss >> carID >> manufacturerName >> colour >> isRented;
                        if (carID == CarIDD)
                        {
                            // car object
                            Car *car = new Car(carID, manufacturerName, colour, isRented);
                            break;
                        }
                }
                    file.close();
                    worker2->issueCar(car, issuerID);
                }
                else if (option == 4)
                {
                    int CarIDD;
                    cout << "Enter Car ID: ";
                    cin >> CarIDD;
                    int carID;
                    string colour, manufacturerName, str;
                    bool isRented;
                    fstream file;
                    file.open("lot.txt", ios::in);
                    while (!file.eof());
                    {
					
                        getline(file, str);
                        istringstream ss(str);
                        ss >> carID >> manufacturerName >> colour >> isRented;
                        if (carID == CarIDD)
                        {
                            // car object
                            Car *car = new Car(carID, manufacturerName, colour, isRented);
                            break;
                        }
                }
                    file.close();
                    returnCar(car);
                }
                else if (option == 5)
                {
                    break;
                }
                else
                {
                    cout << "Invalid option" << endl;
                }
            }
        }
        else if (option == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid option" << endl;
        }
    }
    return 0;
}
