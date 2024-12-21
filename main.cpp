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

// saving functions from maps into files
void saveDoctors(const unordered_map<string, Doctor>& doctors) {
    ofstream file("Doctors.txt", ios::trunc); // Open in truncate mode to clear the file
    if (!file) { // if the file doesnt exist
        cerr << "Unable to open Doctors.txt for writing!" << endl;
        return;
    }

    for (const auto& pair : newDoctors) { // inserts all the information from the maps into the files
        const Doctor& doctor = pair.second;
        file << doctor.getName() << endl;
        file << doctor.getId() << endl;
        file << doctor.getGender() << endl;
        file << doctor.getAge() << endl;
        file << doctor.getPassword() << endl;
        file << doctor.getEmail() << endl;
        file << doctor.getSpecialization() << endl;
        file << doctor.getRate() << endl;
        file << "----------------------------------" << endl;
    }
    file.close();
}
void savePatients(const unordered_map<string, Patient>& patients) {
    ofstream file("Patients.txt", ios::trunc); // Open in truncate mode to clear the file
    if (!file) {
        cerr << "Unable to open Patients.txt for writing!" << endl;
        return;
    }

    for (const auto& pair : newPatients) { // inserts all the information from the maps into the files
        const Patient& patient = pair.second;
        file << patient.getName() << endl;
        file << patient.getId() << endl;
        file << patient.getGender() << endl;
        file << patient.getAge() << endl;
        file << patient.getPassword() << endl;
        file << patient.getEmail() << endl;
        file << patient.getDisease() << endl;
        file << "----------------------------------" << endl;
    }
    file.close();
}
void saveAppointments(const unordered_map<string, Appointment>& appointments) {
    ofstream file("Appointments.txt", ios::trunc); // Open in truncate mode to clear the file
    if (!file) {
        cerr << "Unable to open Appointments.txt for writing!" << endl;
        return;
    }

    for (const auto& pair : newAppointments) { // inserts all the information from the maps into the files
        const Appointment& appointment = pair.second;
        file << appointment.get_date()+appointment.getTime()+appointment.get_ptId() << endl;
        file << appointment.get_date() << endl;
        file << appointment.getTime() << endl;
        file << appointment.get_drId() << endl;
        file << appointment.get_ptId() << endl;
        file << (appointment.get_is_available() ? "1" : "0") << endl;
        file << "----------------------------------" << endl;
    }
    file.close();
}

// main menu functions
Doctor register_doctor() {

    // parameters
    string name;
    string id;
    string gender;
    string age;
    string password;
    string email;
    string special;
    string rate = "0";

    // user interface
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your id: ";
    cin >> id;
    cout << "Enter your gender: ";
    cin >> gender;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your password: ";
    cin >> password;
    cout << "Enter your email: ";
    cin >> email;
    cout << "Enter your special: ";
    cin >> special;

    // inputting the user information
    Doctor doctor(name,gender,id,age,password,special,rate,email);
    // returning the doctor to main
    return doctor;
}
Patient register_patient() {

    // parameters
    string name;
    string id;
    string gender;
    string age;
    string password;
    string email;
    string disease;

    // user interface
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your id: ";
    cin >> id;
    cout << "Enter your gender: ";
    cin >> gender;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your password: ";
    cin >> password;
    cout << "Enter your email: ";
    cin >> email;
    cout << "Enter your disease: ";
    cin >> disease;

    // inputting the user interface
    Patient patient(name,gender,id,age,password,disease,email);
    // returning the patient to main
    return patient;
}
void displayWelcomeMessage() { // prints the welcome page
    string line = "=======================================================";
    string message = " Welcome to the Patient and Doctor appointment System! ";

    cout << line << endl;
    cout << message;
    cout << endl;
    cout << line << endl;

    cout <<endl;

}
void printMedicineList() {
    cout << "Medicine List:" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "1. Paracetamol (Acetaminophen)" << endl;
    cout << "   Use: Pain relief and fever reduction" << endl;
    cout << endl;
    cout << "2. Ibuprofen" << endl;
    cout << "   Use: Pain, inflammation, and fever" << endl;
    cout << endl;
    cout << "3. Amoxicillin" << endl;
    cout << "   Use: Treatment of bacterial infections" << endl;
    cout << endl;
    cout << "4. Metformin" << endl;
    cout << "   Use: Management of type 2 diabetes" << endl;
    cout << endl;
    cout << "5. Atorvastatin" << endl;
    cout << "   Use: Lowering cholesterol and preventing cardiovascular disease" << endl;
    cout << endl;
    cout << "6. Omeprazole" << endl;
    cout << "   Use: Treatment of acid reflux and stomach ulcers" << endl;
    cout << endl;
    cout << "7. Ciprofloxacin" << endl;
    cout << "   Use: Treatment of various bacterial infections, including UTIs" << endl;
}
