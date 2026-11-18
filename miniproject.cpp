#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Member {
protected:
    int id, age;
    string name, mobile;
public:
    void getDetails() {
        cout << "Enter Member ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Mobile Number: ";
        cin >> mobile;
    }

    void displayDetails() {
        cout << "\nMember ID: " << id;
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nMobile: " << mobile;
    }
};


class Membership : public Member {
    int duration, fees;
public:
  
    int getMembership() {
        int choice;
        cout << "\n\nSelect Membership Plan";
        cout << "\n1. 1 Month  - Rs. 1000";
        cout << "\n2. 3 Months - Rs. 2500";
        cout << "\n3. 6 Months - Rs. 4500";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: duration = 1; fees = 1000; break;
            case 2: duration = 3; fees = 2500; break;
            case 3: duration = 6; fees = 4500; break;
            default:
                cout << "Invalid Plan!";
                return 0;
        }
        return 1;
    }

    void displayMembership() {
        displayDetails();
        cout << "\nMembership Duration: " << duration << " Months";
        cout << "\nTotal Fees: Rs. " << fees << endl;
    }

    
    void saveToFile() {
        ofstream file("members.txt", ios::app);
        if (!file) {
            cout << "\nFile not opened!";
            return;
        }
        file << "Member ID: " << id << endl;
        file << "Name: " << name << endl;
        file << "Age: " << age << endl;
        file << "Mobile: " << mobile << endl;
        file << "Duration: " << duration << " Months" << endl;
        file << "Fees: Rs. " << fees << endl;
        file << "----------------------" << endl;
        file.close();
        cout << "\nMember details saved successfully!\n";
    }
};


void viewAllMembers() {
    ifstream file("members.txt");
    if (!file) {
        cout << "\nNo records found!\n";
        return;
    }
    string line;
    cout << "\n===== ALL MEMBERS =====\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}


int main() {
    int option;

    do {
        cout << "\n===== GYM MEMBERSHIP SYSTEM =====";
        cout << "\n1. Add New Member";
        cout << "\n2. View All Members";
        cout << "\n0. Exit";
        cout << "\nEnter option: ";
        cin >> option;

        if (option == 1) {
            Membership m;
            m.getDetails();
            if (m.getMembership() == 1) {
                cout << "\n===== MEMBERSHIP DETAILS =====";
                m.displayMembership();
                m.saveToFile();
            }
        }
        else if (option == 2) {
            viewAllMembers();
        }
    } while (option != 0);

    cout << "\nThank you!\n";
    return 0;
}