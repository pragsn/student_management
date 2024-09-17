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
  cout<<"3. view only single student\n";
  cout<<"4. Update Studenr Details\n";
  cout<<"5. Delete Student\n";
  cout<<"6. Calculate Average Grade\n";
  cout<<"7. Find Highest and Lowest Grades\n";
  cout<<"8. Exit\n";
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
        if(students[i].rollnumber == choice){
            cout<<i+1<<". Name:"<<students[i].name<<". Grade"<<students[i].grade<<". Rollnumber"<<students[i].rollnumber;
        }
        
    }
}
void updateStudent() {
    if (students.empty()) {
        cout << "No students to update.\n";
        return;
    }
    
    int choice;
    cout << "Enter student's roll number: ";
    cin >> choice;

    bool studentFound = false;
    
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].rollnumber == choice) {  
            studentFound = true;
            cin.ignore(); 

         
            cout << "Enter new student's name: ";
            getline(cin, students[i].name);

           
            cout << "Enter new student's grade (0-100): ";
            while (!(cin >> students[i].grade) || students[i].grade < 0 || students[i].grade > 100) {
                cout << "Invalid grade! Please enter a number between 0 and 100: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Student details updated successfully!\n";
            break;
        }
    }

    if (!studentFound) {
        cout << "Student with roll number " << choice << " not found.\n";
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
    for(size_t i = 0; i<students.size(); i++){
        sum += students[i].grade;
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
            case 8:
            cout<<"exiting...\n";
            break;
            default:
            cout<<"invalid choice taken";
            break;
        }
    }
    while(choice<8 && choice>0);
    return 0;
}