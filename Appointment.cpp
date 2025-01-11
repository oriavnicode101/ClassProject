
#include <iostream>
#include "Appointment.h"
using namespace std;

Appointment::Appointment() {
    is_available = true;
    date = "";
    drId = "";
    ptId = "";
    time = "";
}
Appointment::Appointment(string d, string dr, string pt, string t, bool is_av) {
    is_available = is_av;
    date = d;
    drId = dr;
    ptId = pt;
    time = t;
}
void Appointment::print() const {
    cout << "Date: " << date << endl;
    cout << "Time: " << time << endl;
    cout << "Doctor ID: " << drId << endl;
    cout << "Patient ID: " << ptId << endl;
    cout << "Is available: " << (is_available ? "Yes" : "No") << endl;
    cout << "----------------------------------" << endl;
}

void Appointment::print_for_patient() const {
    cout << "Date: " << date << endl;
    cout << "Time: " << time << endl;
    cout << "Doctor ID: " << drId << endl;
    cout << "Patient ID: " << ptId << endl;
    if (is_available == true) {
        cout << "Appointment status: Approved " << endl;
    }
    else {
        cout << "Pending" << endl;
    }
    cout << endl;
}