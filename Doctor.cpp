


#include "Doctor.h"
#include <iostream>

Doctor::Doctor() {
    name = "";
    gender = "";
    id = "";
    age = "";
    password = "";
    rate = "";
    email = "";
    specialization = "";
    ratings++;
    totalRating = 0;
    ratingCount = 0;
}

Doctor::Doctor(string n, string g, string i, string a, string p, string s, string r, string em) {
    name  = n;
    gender = g;
    id = i;
    age = a;
    password = p;
    email = em;
    specialization = s;
    rate = r;
    ratings++;
    totalRating = 0;
    ratingCount = 0;
}

string Doctor::getId() const {
    return id;
}
string Doctor::getPassword() const {
    return password;
}
string Doctor::getSpecialization() const {
    return specialization;
}
string Doctor::getName() const {
    return name;
}
string Doctor::getGender() const {
    return gender;
}
string Doctor::getAge() const {
    return age;
}
string Doctor::getEmail() const {
    return email;
}
void Doctor::printDoctors() const {
    cout << name << endl;
    cout << id << endl;
    cout << gender << endl;
    cout << age << endl;
    cout << password << endl;
    cout << email << endl;
    cout << specialization << endl;
    cout << rate << endl;
    cout << "----------------------------------" << endl;
}
void Doctor:: set_rate(int newRating) {
    totalRating += newRating;
    ratingCount++;
    rate = to_string(totalRating / ratingCount);
}
float Doctor:: getAverageRating() const {
    return ratingCount > 0 ? totalRating / ratingCount : 0;
}
