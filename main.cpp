#include <iostream>
#include <fstream>
#include "Appointment.h"
#include "Doctor.h"
#include "Patient.h"
#include <unordered_map>

using namespace std;

int Doctor::ratings = 0; // static parameter from the doctor class

// loading functions into the maps
unordered_map<string, Doctor> loadDoctors() { // loads the information inside Doctors.txt into Doctors map
    unordered_map<string, Doctor> doctors;

    ifstream file("Doctors.txt");
    string line;

    while (getline(file, line)) { // reads first line
        string name = line;

        getline(file, line); // reads second line
        string id = line;

        getline(file, line); // reads third line
        string gender = line;

        getline(file, line); // reads fourth line
        string age = line;

        getline(file, line); // reads fifth line
        string password = line;

        getline(file, line); // reads sixth line
        string email = line;

        getline(file, line); // reads seventh line
        string specialization = line;

        getline(file, line); // reads eighth line
        string rate = line;

        getline(file, line); // skips line  --------------

        Doctor doctor(name,gender,id, age,password,specialization,rate,email);

        doctors[id] = doctor;
    }
    file.close();
    return doctors; // returns the loaded map
}
unordered_map<string, Patient> loadPatients() { // loads the information inside Patients.txt into patients map
    unordered_map<string, Patient> patients;

    ifstream file("Patients.txt");
    string line;

    while (getline(file, line)) { // reads first line
        string name = line;

        getline(file, line); // reads second line
        string id = line;

        getline(file, line); // reads third line
        string gender = line;

        getline(file, line); // reads fourth line
        string age = line;

        getline(file, line); // reads fifth line
        string password = line;

        getline(file, line); // reads sixth line
        string email = line;

        getline(file, line); // reads seventh line
        string disease = line;

        getline(file, line); // skips line  --------------

        Patient patient(name,gender,id,age,password,disease,email);

        patients[id] = patient;
    }
    file.close();
    return patients; // returns the loaded patients
}
unordered_map<string, Appointment> loadAppointments() { // loads the information inside Appointments.txt into appointments map
    unordered_map<string, Appointment> appointments;
    ifstream file("Appointments.txt");

    string line;
    while (getline(file, line)) {  // reads first line
        string key = line;

        getline(file, line); // reads second line
        string date = line;

        getline(file, line); // reads second line
        string time = line;

        getline(file, line); // reads third line
        string doctorId = line;

        getline(file, line); // reads fourth line
        string patientId = line;

        getline(file, line); // reads fifth line
        bool isBooked = line == "1";

        getline(file, line); // skips line  --------------

        Appointment appointment(date, doctorId, patientId, time, isBooked);
        key = date + time + patientId;

        appointments[key] = appointment;
    }
    file.close();
    return appointments; // returns the loaded appointments
}

// creating and loading the unordered maps
unordered_map<string, Appointment> newAppointments = loadAppointments();
unordered_map<string,Doctor> newDoctors = loadDoctors();
unordered_map<string,Patient> newPatients = loadPatients();
/////////////////////
