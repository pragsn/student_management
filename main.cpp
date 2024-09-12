#include<bits/stdc++.h>
using namespace std;

struct student{
    string name;
    int rollnumber;
    int grade;
};

vector<student> students;

void showMenu(){
  cout<<"\n1. Add Student\n";
  cout<<"2. View All Students\n";
  cout<<"3. Update Studenr Details\n";
  cout<<"4. Delete Student\n";
  cout<<"5. Calculate Average Grade\n";
  cout<<"6. Find Highest and Lowest Grades\n";
  cout<<"7. Exit\n";
  cout<<"Choose an option\n";
}


void addStudent(){
    student s;
    cout<<"enter student's name:";
    cin.ignore();
    getline(cin,s.name);
    cout<<"enter student's grade(0-100):";
    while(!(cin>>s.grade||s.grade<0 || s.grade>100)){
        cout<<"Inavlid grade entered";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout<<"enter student's rollnumber(1-2000):";
    while(!(cin>>s.rollnumber || s.rollnumber<1 || s.rollnumber>2000)){
       cout<<"invalid roll call";
       cin.clear();
       cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    students.push_back(s);
    cout<<"student added successfully";
}
void viewStudents(){
    if(students.empty()){
        cout<<"NO STUDENTS PRESENT CURRENTLY!";
        return;
    }
    else{
        cout<<"student List:\n";
        for(size_t i = 0; i<students.size(); i++){
            cout<<i+1<<". Name:"<<students[i].name<<". Grade"<<students[i].grade<<". Roll Number"<<students[i].rollnumber;
        }
    }
}
void viewSinglestudent(){
    if(students.empty()) return;
    cout<<"enter student roll number:";
    int choice;
    cin>>choice;
    for(size_t i = 0; i<students.size(); i++){
        if(i == choice-1){
            cout<<i+1<<". Name:"<<students[i+1].name<<". Grade"<<students[i+1].grade<<". Rollnumber"<<students[i+1].rollnumber;
        }
        else{
            cout<<"invalid";
        }
    }
}
void updateStudent() {
    viewStudents();
    
    if (students.empty()) return;
    
    int choice;
    cout << "Enter the student number you want to update: ";
    cin >> choice;

    if (choice > 0 && choice <= students.size()) {
        cin.ignore(); 
        cout << "Enter new name for student: ";
        getline(cin, students[choice - 1].name);

        cout << "Enter new grade (0-100): ";
        while (!(cin >> students[choice - 1].grade) || students[choice - 1].grade < 0 || students[choice - 1].grade > 100) {
            cout << "Invalid grade! Please enter a number between 0 and 100: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Student details updated successfully!\n";
    } else {
        cout << "Invalid student number.\n";
    }
}
void deleteStudent(){
    if(students.empty()){
        cout<<"No students present to delete";
    }
    viewStudents();
    int choice;
    cout<<"enter student's rollcall:";
    cin>>choice;
    if(choice>0 && choice<=students.size()){
        students.erase(students.begin() + (choice - 1));
        cout<<"student deleted successfully";
    }
    else{
        cout<<"Invalid rollcall";
    }

}
void calculateAverageGrade(){
    if(students.empty()){
        cout<<" No student is present in the list";
        return;

    }
    int sum = 0;
    for (const auto& s : students) {
        sum += s.grade;
    }
    double average = static_cast<double>(sum) / students.size();
    cout<<"Average grade:"<<average<<endl;
}
void findHighestandLowestGrades(){
    if(students.empty()){
        cout<<"no students present";
    }
    int highestGrade = students[0].grade;
    int lowestGrade = students[0].grade;
    for (const auto& s : students) {
        if (s.grade > highestGrade) highestGrade = s.grade;
        if (s.grade < lowestGrade) lowestGrade = s.grade;
    }
    cout<<"'highest grade is:'"<<highestGrade<<endl;
    cout<<"'lowest grade is:'"<<lowestGrade<<endl;
}
int main(){
    int choice;
    
    do{
        showMenu();
        cout<<"enter your choice:"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
            addStudent();
            break;
            case 2:
            viewStudents();
            break;
            case 3:
            viewSinglestudent();
            break;
            case 4:
            updateStudent();
            break;
            case 5:
            deleteStudent();
            break;
            case 6:
            calculateAverageGrade();
            break;
            case 7:
            findHighestandLowestGrades();
            break;
            default:
            cout<<"invalid choice taken";
            break;
        }
    }
    while(choice<8 && choice>0);
    return 0;
}