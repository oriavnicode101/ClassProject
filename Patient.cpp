
#include "Patient.h"


Patient::Patient() {
    name = "";
    gender = "";
    id = "";
    age = "";
    password = "";
    disease = "";
    email = "";
}
Patient::Patient(string n, string g, string i, string a, string p, string d, string em) {
    name  = n;
    gender = g;
    id = i;
    age = a;
    password = p;
    disease = d;
    email = em;
}
Patient::~Patient() {
}
string Patient::getId() const {
    return id;
}
string Patient::getPassword() const {
    return password;
}
string Patient::getName() const {
    return name;
}
string Patient::getGender() const {
    return gender;
}
string Patient::getAge() const {
    return age;
}
string Patient::getEmail() const {
    return email;
}
string Patient::getDisease() const {
    return disease;
}

void Patient::printPatient() const {
    cout << name << endl;
    cout << id << endl;
    cout << gender << endl;
    cout << age << endl;
    cout << password << endl;
    cout << email << endl;
    cout << disease << endl;
    cout << "----------------------------------" << endl;
}
