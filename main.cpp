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


void Patient_login() {

    // parameters
    string password;
    string id;

    //user input
    cout << "Enter your id: " << endl;
    cin >> id;
    cout << "Enter your password: " << endl;
    cin >> password;


    for (auto &pair: newPatients) { // patients log in menu
        if (pair.first == id && pair.second.getPassword() == password) {
            cout << "Logged in successfully!" << endl;

            int choice = 0;
            while (choice != 7) {
                cout << "-----------------------" << endl;
                cout << "Input the number from the menu you would like to choose from: " << endl;
                cout << "1. Schedule an appointment " << endl;
                cout << "2. Cancel an appointment " << endl;
                cout << "3. View your appointments " << endl;
                cout << "4. Edit medical history " << endl;
                cout << "5. Change Password " << endl;
                cout << "6. Rate your visit" << endl;
                cout << "7. Exit" << endl;

                cin >> choice;

                switch (choice) {
                    case 1: {   // schedule an appointment
                        // parameters
                        string d,m,y;
                        string time;
                        string special;
                        string drID;
                        bool isAvailable = true;

                        //user input
                        cout << "Enter a specific date to schedule (DD MM YYYY): ";
                        cin >> d >> m >> y;
                        string date = d + m + y;
                        cout << "choose from these hours: 10:00 | 10:30 | 11:00 | 11:30 " << endl;
                        cin >> time;
                        cout << "Enter the specialty of the doctor:" << endl;
                        cout << "options: " << endl;

                        for (auto &pair: newDoctors) { // prints the specializations of the doctors to choose from
                            cout << pair.second.getSpecialization() << endl;
                        }

                        cin >> special;

                        for (auto &pair: newDoctors) { // saves the id of the doctor who has the specialization into drID
                            if (pair.second.getSpecialization() == special) {
                                drID = pair.first;
                            }
                        }

                        cout << "id:" << drID << endl;
                        string key = date + time + id;

                        for (auto &pair: newAppointments) { // checks if the appointment is already booked
                            if (pair.first == key && pair.second.getTime() == time && pair.second.get_date() == date) {
                                cout << "The appointment is already booked" << endl;
                                isAvailable = false;
                            }
                        }

                        if (isAvailable) { // creates a new appointment
                            Appointment appointment(date,drID,id,time,true);
                            newAppointments[key] = appointment;
                            saveAppointments(newAppointments);
                            cout << "Appointment successfully booked" << endl;
                            cout << "-------------------------------" << endl;
                            cout << "Appointment details: " << endl;
                            appointment.print();
                        }
                        break;
                    }
                    case 2: {   // cancel an appointment
                        // parameters
                        string d, m, y, date, key;
                        int confirm;
                        bool appointmentFound = false;

                        // User input for cancellation
                        cout << "Enter a specific date to cancel (DD MM YYYY): ";
                        cin >> d >> m >> y;
                        date = d + m + y;

                        // Loop to find and cancel appointment safely
                        for (auto it = newAppointments.begin(); it != newAppointments.end(); ) {
                            if (it->second.get_ptId() == id && it->second.get_date() == date) {
                                cout << "Details of your appointment to cancel:" << endl;
                                it->second.print();
                                cout << "Are you sure you want to cancel this appointment? 1 = YES | 2 = NO ";
                                cin >> confirm;

                                if (confirm == 1) {
                                    it = newAppointments.erase(it);  // Erase safely and update iterator
                                    cout << "Appointment successfully cancelled." << endl;
                                    saveAppointments(newAppointments);
                                    appointmentFound = true;
                                } else {
                                    cout << "Appointment not cancelled." << endl;
                                    ++it;
                                }
                            } else {
                                ++it;
                            }
                        }

                        if (!appointmentFound) {
                            cout << "No appointment found for the given date." << endl;
                        }

                        break;
                    }
                    case 3: {    // prints the appointment
                        // parameters
                        string d,m,y;

                        // user input
                        cout << "Enter the date of your appointment (DD MM YYYY): " << endl;
                        cin >> d >> m >> y;
                        string date = d + m + y;

                        for (auto &pair: newAppointments) { // prints
                            if (pair.second.get_ptId() == id && pair.second.get_date() == date) {
                                cout << "Details of your appointment: " << endl;
                                pair.second.print_for_patient();
                            }
                            else
                                cout << "You have no appointments at that date" << endl;
                        }
                        break;
                    }
                    case 4: {  // adds to the patients history
                        // parameters
                        string disease;

                        // user input
                        cout << "Enter your new history: " << endl;
                        cin >> disease;

                        for (auto &pair: newPatients) { // adds to disease
                            if (pair.first == id) {
                                pair.second.set_disease(disease);
                                cout << "History added" << endl;
                            }
                        }
                        savePatients(newPatients);
                        break;
                    }
                    case 5: { // change password
                        // parameters
                        bool valid_pass = false;
                        string old_pass,new_pass;

                        do {

                            // user input
                            cout << "Enter your previous password for confirmation: " << endl;
                            cin >> old_pass;

                            for (auto &pair: newPatients) { // changes password
                                if (pair.first == id && pair.second.getPassword() == old_pass) {
                                    cout << "Password confirmed" << endl;
                                    cout << "------------------" << endl;
                                    cout << "Enter new password: " << endl;
                                    cin >> new_pass;
                                    pair.second.set_password(new_pass);
                                    cout << "Password changed successfully" << endl;
                                    valid_pass = true;
                                    savePatients(newPatients);
                                    break;
                                }
                            }
                            if (!valid_pass) {
                                cout << "Wrong password" << endl;
                            }
                        }
                        while (!valid_pass);
                        break;
                    }
                    case 6: {  // updates the doctors rating

                        // parameters
                        int rating;
                        string doc_id,nameDoc;

                        // user input

                        cout << "list of doctors: " << endl;
                        for (const auto &pair: newDoctors) { // prints the names of the doctors
                            cout << pair.second.getName() << endl;
                        }

                        cout << "Type the name of the doctor you wish to rate: " << endl;
                        cin >> nameDoc;

                        for (const auto &pair: newDoctors) {
                            if (pair.second.getName() == nameDoc) {
                                doc_id = pair.first;
                            }
                        }

                        cout << "Rate your appointment: 1-10 " << endl;
                        cin >> rating;

                        for (auto &pair: newDoctors) { // updates rating
                            if (pair.first == doc_id) {
                                pair.second.set_rate(rating);
                                cout << "Rating added successfully" << endl;
                                saveDoctors(newDoctors);
                            }
                        }
                        break;
                    }
                    case 7: {
                        // exit
                        cout << "Exiting..." << endl;
                        break;
                    }
                    default: {
                        cout << "Invalid choice, please try again." << endl;
                        break;
                    }
                }
            }

        }
    }
}
void Doctor_login() {

    // parameters
    string id,password;
    bool idFound = false;
    bool passwordFound = false;

    // user input
    cout << "Enter your id: " << endl;
    cin >> id;
    cout << "Enter your password: " << endl;
    cin >> password;

    for (const auto& pair : newDoctors ) {
        if (pair.first == id && pair.second.getPassword() == password) {
            idFound = true;
            passwordFound = true;
            break;
        }
    }

    if (idFound && passwordFound) { // checks if the login is valid
        cout << "Logged in successfully!" << endl;
        // parameters
        int choice;

        while (choice != 3) {
            // Doctor's first menu
            cout << "-----------------------" << endl;
            cout << "Input the number from the menu you would like to choose from: " << endl;
            cout << "1. Enter doctor's menu" << endl;
            cout << "2. Enter patient's menu" << endl;
            cout << "3. Exit" << endl;
            cin >> choice;
            switch (choice) {
                // doctor's personal menu
                case 1: {
                    int choice1 = 0;
                    while (choice1 != 4) {
                        cout << "------------------------------------------------------------" << endl;
                        cout << "Input the number from the menu you would like to choose from: " << endl;
                        cout << "1. View current appointments " << endl;
                        cout << "2. Block a certain date for an appointment " << endl;
                        cout << "3. Edit your profile " << endl;
                        cout << "4. Exit" << endl;
                        cin >> choice1;
                        switch (choice1) {
                            case 1: {
                                // View current appointments
                                // parameters
                                bool appointmentFound = false;
                                string d,m,y;

                                // user input
                                cout << "Enter a specific date to view your appointments: DD/MM/YEAR " << endl;
                                cin >> d >> m >> y;
                                string date = d + m + y;

                                for (const auto& pair : newAppointments) { // print appointments
                                    if (pair.second.get_drId() == id && pair.second.get_date() == date) {
                                        appointmentFound = true;
                                        pair.second.print();
                                    }
                                }

                                if (!appointmentFound) {
                                    cout << "You have no appointments at that date!" << endl;
                                }
                                break;
                            }
                            case 2: {  // block a date for an appointment
                                // parameters
                                string d,m,y;
                                // user input
                                cout << "Enter a specific date in which you want to block: DD/MM/YEAR" << endl;
                                cin >> d >> m >> y;
                                string date = d + m + y;

                                for (auto& pair : newAppointments) { // set the is_available to false
                                    if (pair.second.get_drId() == id && pair.second.get_date() == date) {
                                        pair.second.set_is_available(false);
                                        cout << "Date blocked successfully" << endl;
                                    }
                                    else
                                        cout << "No appointments at that date" << endl;
                                }
                                saveAppointments(newAppointments);
                                break;
                            }
                            case 3: {
                                // Edit your profile
                                // parameters
                                string name,password, email, special;
                                int choice1;

                                do {
                                    cout << "What would you like to edit? " << endl;
                                    cout << "1. Name " << endl;
                                    cout << "2. Password " << endl;
                                    cout << "3. Email " << endl;
                                    cout << "4. Specialization " << endl;
                                    cout << "5. Exit " << endl;
                                    cin >> choice1;
                                    switch (choice1) {
                                        case 1: { // edit name
                                            cout << "Enter your new name: " << endl;
                                            cin >> name;
                                            for (auto& pair : newDoctors) {
                                                if (pair.first == id) {
                                                    pair.second.setName(name);
                                                }
                                            }
                                            saveDoctors(newDoctors);
                                            break;
                                        }
                                        case 2: { // edit password
                                            bool valid_pass = false;
                                            do {
                                                string old_pass;
                                                cout << "Enter your previous password for confirmation: " << endl;
                                                cin >> old_pass;
                                                for (auto &pair: newDoctors) {
                                                    if (pair.first == id && pair.second.getPassword() == old_pass) {
                                                        cout << "Password confirmed" << endl;
                                                        cout << "------------------" << endl;
                                                        cout << "Enter new password: " << endl;
                                                        cin >> password;
                                                        pair.second.setPassword(password);
                                                        cout << "Password changed successfully" << endl;
                                                        valid_pass = true;
                                                    }
                                                    else {
                                                        cout << "Wrong password" << endl;
                                                        valid_pass = false;
                                                    }
                                                }
                                            }
                                            while (!valid_pass);
                                            saveDoctors(newDoctors);
                                            break;
                                        }
                                        case 3: { // edit email
                                            cout << "Enter your new Email: " << endl;
                                            cin >> email;
                                            for (auto& pair : newDoctors) {
                                                if (pair.first == id) {
                                                    pair.second.setEmail(email);
                                                }
                                            }
                                            saveDoctors(newDoctors);
                                            break;
                                        }
                                        case 4: { // edit specialization
                                            cout << "Enter your new specialization: " << endl;
                                            cin >> special;
                                            for (auto& pair : newDoctors) {
                                                if (pair.first == id) {
                                                    pair.second.setSpecialization(special);
                                                }
                                            }
                                            saveDoctors(newDoctors);
                                            break;
                                        }
                                        case 5: { // exit
                                            cout << "Exiting..." << endl;
                                            break;
                                        }
                                        default: {
                                            cout << "Invalid choice, please try again." << endl;
                                            break;
                                        }
                                    }
                                }
                                while (choice1 != 5);
                                break;
                            }
                            case 4: { // exit
                                break;
                            }
                            default: {
                                cout << "Invalid choice, please try again." << endl;
                                break;
                            }
                        }
                    }
                    break;
                }
                case 2: {  // patients menu for the doctor
                    // user input
                    cout << "Input the number from the menu you would like to choose from: " << endl;
                    cout << "1. Edit patient's medical history " << endl;
                    cout << "2. View medicine list" << endl;
                    cout << "3. Exit " << endl;
                    cin >> choice;

                    if (choice == 1) { // edit patients medical history

                        // parameters
                        string patient_id;
                        int choice7;

                        // user input
                        cout << "Enter the patient's id: " << endl;
                        cin >> patient_id;

                        for ( auto& pair: newPatients)  { // options for the medical history
                            if (pair.first == patient_id) {

                                // user input
                                cout << "1. Edit patient's medical history" << endl;
                                cout << "2. View patient's medical history" << endl;
                                cin >> choice7;

                                if (choice7 == 1) { // edit history

                                    // parameters
                                    string disease;

                                    // user input
                                    cout << "Enter the new medical history: " << endl;
                                    cin >> disease;
                                    cout << "Medical history added successfully" << endl;

                                    pair.second.set_disease(disease); // adds to the patients history
                                }
                                if (choice7 == 2) { // view patients history

                                    // user input
                                    cout << "Patient's medical history: " << endl;
                                    cout << pair.second.getDisease() << endl;
                                }
                                if (choice7 == 3) { // exit
                                    cout << "Exiting..." << endl;
                                    cout << "------------------------------------------------------------" << endl;
                                }
                            }
                        }
                        savePatients(newPatients);
                    }
                    if (choice == 2) { // prints medicine list
                        printMedicineList();
                    }
                    else
                        break;
                    break;
                }
                case 3: { // exit
                    cout << "Exiting..." << endl;
                    cout << "------------------------------------------------------------" << endl;
                    break;
                }
                default: {
                    cout << "Invalid choice, please try again." << endl;
                    break;
                }
            }
        }
    }

}
void registerPatientMenu() {
    Patient patient1 = register_patient();

    newPatients[patient1.getId()] = patient1;
    savePatients(newPatients);
}
void registerDoctorMenu() {
    Doctor doc1 = register_doctor();

    newDoctors[doc1.getId()] = doc1;
    saveDoctors(newDoctors);
}


bool main_menu() {
    displayWelcomeMessage();

    cout << "Would you like to login or register to the system?" << endl;
    int choice;
    cout << "Enter your choice: | 1 = register | 2 = login " << endl;
    cin >> choice;

    if (choice == 1) { // if the user chooses to register
        int choice1;
        cout << "Are you a doctor or a patient? " << endl;
        cout << "Enter your choice: | 1 = doctor | 2 = patient " << endl;
        cin >> choice1;

        if (choice1 == 1) {  // if the user decided to register as a doctor
            int choice2;
            registerDoctorMenu();
            saveDoctors(newDoctors);
            cout << "Do you want to connect to the system? | 1 = YES | 2 = NO " << endl;
            cin >> choice2;
            if (choice2 == 1) {
                Doctor_login();
            }
            else {
                cout << "Exiting..." << endl;
            }

        }

        if (choice1 == 2) { // if the user decided to register as a patient
            int choice2;
            registerPatientMenu();
            savePatients(newPatients);
            cout << "Do you want to connect to the system? | 1 = YES | 2 = NO " << endl;
            cin >> choice2;
            if (choice2 == 1) {
                Patient_login();
            }
            else {
                cout << "Exiting..." << endl;
            }
        }
    }

    if (choice == 2) { // if the user chooses to log in
        int choice2;
        cout << "Are you a doctor or a patient? " << endl;
        cout << "Enter your choice: | 1 = doctor | 2 = patient " << endl;
        cin >> choice2;

        if (choice2 == 1) {
            // if the user decided to log in as a doctor
            Doctor_login();
        }
        if (choice2 == 2) {
            Patient_login();
        }
    }
}


int main () {
    main_menu();

    return 0;
}
