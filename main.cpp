
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

struct Student {
    string name;
    int rollnumber;
    int grade;
    Student* next;  
};


Student* head = nullptr;

void addStudent() {
    Student* newStudent = new Student;
    
    cout << "Enter student's name: ";
    cin.ignore();
    getline(cin, newStudent->name);
    
    cout << "Enter student's roll number (1-2000): ";
    cin >> newStudent->rollnumber;
    
    cout << "Enter student's grade (0-100): ";
    cin >> newStudent->grade;
    
    newStudent->next = nullptr;
    
   
    if (head == nullptr) {
        head = newStudent;
    } else {
        
        Student* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }

    cout << "Student added successfully!" << endl;
}

void viewStudents() {
    if (head == nullptr) {
        cout << "No students present." << endl;
        return;
    }
    
    Student* temp = head;
    while (temp != nullptr) {
        cout << "Name: " << temp->name << ", Roll Number: " << temp->rollnumber << ", Grade: " << temp->grade << endl;
        temp = temp->next;
    }
}
void updateStudent() {
    if (head == nullptr) {
        cout << "No students present to update." << endl;
        return;
    }

    int rollNumber;
    cout << "Enter student's roll number to update: ";
    cin >> rollNumber;

    Student* temp = head;
    while (temp != nullptr) {
        if (temp->rollnumber == rollNumber) {
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, temp->name);
            cout << "Enter new grade (0-100): ";
            cin >> temp->grade;
            cout << "Student updated successfully!" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Student with roll number " << rollNumber << " not found." << endl;
}
void deleteStudent() {
    if (head == nullptr) {
        cout << "No students to delete." << endl;
        return;
    }

    int rollNumber;
    cout << "Enter roll number of the student to delete: ";
    cin >> rollNumber;

    // If the student to delete is the head
    if (head->rollnumber == rollNumber) {
        Student* temp = head;
        head = head->next;
        delete temp;
        cout << "Student deleted successfully!" << endl;
        return;
    }

    // Traverse the list to find the student to delete
    Student* current = head;
    Student* previous = nullptr;

    while (current != nullptr && current->rollnumber != rollNumber) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Student with roll number " << rollNumber << " not found." << endl;
        return;
    }

    previous->next = current->next;
    delete current;
    cout << "Student deleted successfully!" << endl;
}
void saveToFile() {
    ofstream outFile("students.txt");
    if (!outFile) {
        cout << "Error creating file!" << endl;
        return;
    }

    Student* temp = head;
    while (temp != nullptr) {
        outFile << temp->name << " " << temp->rollnumber << " " << temp->grade << endl;
        temp = temp->next;
    }

    outFile.close();
    cout << "Student data saved to students.txt successfully!" << endl;
}

void loadFromFile() {
    ifstream inFile("students.txt");
    if (!inFile) {
        cout << "No student data file found. Starting with an empty list." << endl;
        return;
    }

    // Clear current linked list
    while (head != nullptr) {
        Student* temp = head;
        head = head->next;
        delete temp;
    }

    // Load data from file
    string name;
    int rollnumber, grade;
    while (inFile >> name >> rollnumber >> grade) {
        Student* newStudent = new Student{name, rollnumber, grade, nullptr};
        
        if (head == nullptr) {
            head = newStudent;
        } else {
            Student* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newStudent;
        }
    }

    inFile.close();
    cout << "Student data loaded successfully!" << endl;
}
int main() {
    int choice;

    loadFromFile(); // Load data from file on startup

    do {
        cout << "\n1. Add Student\n2. View All Students\n3. Update Student\n4. Delete Student\n5. Save to File\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                saveToFile();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 6);

    saveToFile(); // Save data to file before exiting
    return 0;
}