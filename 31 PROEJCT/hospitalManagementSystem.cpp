#include<iostream>
#include<vector>
using namespace std;
int pid,did;
class Patient
{
    public:
    string name,gender;
    int age,ID;
    Patient(string s,int n,string g)
    {
        ID = pid;
        pid++;
        name = s;
        gender = g;
        age = n;
    }
};
class Doctor
{
    public:
    string name,gender;
    int age,ID;
    Doctor(string s,int n,string g)
    {
        ID = did;
        did++;
        name = s;
        gender = g;
        age = n;
    }
};
class Appointment
{
    public:
    int doctorID,patientID;
    string date;
    Appointment(int d,int p,string date)
    {
        doctorID = d;
        patientID = p;
        this->date = date;
    }
};
vector<Patient> allPatients;
vector<Doctor> allDoctors;
vector<Appointment> allAppointments;
void addPatient()
{
    string s,g;
    int n;
    cin.ignore();
    cout<<"Enter the patient's name:- ";
    getline(cin,s);
    cout<<"Enter the age of the patient:- ";
    cin>>n;
    cout<<"Enter the gender of the patient(F/M):- ";
    cin>>g;
    Patient temp(s,n,g);
    allPatients.push_back(temp);
}
void addDoctor()
{
    string s,g;
    int n;
    cin.ignore();
    cout<<"Enter the doctor's name:- ";
    getline(cin,s);
    cout<<"Enter the age of the doctor:- ";
    cin>>n;
    cout<<"Enter the gender of the doctor(F/M):- ";
    cin>>g;
    Doctor temp(s,n,g);
    allDoctors.push_back(temp);
}
void scheduleAppointment()
{
    int d,p;
    string date;
    cout<<"Enter the doctor id:- ";
    cin>>d;
    bool presentDoctor = false;
    for(int i=0;i<allDoctors.size();i++)
    {
        if(allDoctors[i].ID == p)
        {
            presentDoctor = true;
            break;
        }
    }
    if(presentDoctor == false)
    {
        cout<<"There is no doctor in the database with ID "<<d<<endl;
        return;
    }
    cout<<"Enter the patient id:- ";
    cin>>p;
    bool presentPatient = false;
    for(int i=0;i<allPatients.size();i++)
    {
        if(allPatients[i].ID == p)
        {
            presentPatient = true;
            break;
        }
    }
    if(presentPatient == false)
    {
        cout<<"There is no patient in the database with ID "<<p<<endl;
        return;
    }
    cin.ignore();
    cout<<"Enter the date in DD-MM-YYYY:- ";
    cin>>date;
    Appointment temp(d,p,date);
    allAppointments.push_back(temp);
}
void viewPatient()
{
    for(int i=0;i<allPatients.size();i++)
    {
        cout<<"Patient name - "<<allPatients[i].name<<endl;
        cout<<"Patient age - "<<allPatients[i].age<<endl;
        cout<<"Patient gender - "<<allPatients[i].gender<<endl;
    }
}
void viewDoctor()
{
    for(int i=0;i<allDoctors.size();i++)
    {
        cout<<"Doctor name - "<<allDoctors[i].name<<endl;
        cout<<"Doctor age - "<<allDoctors[i].age<<endl;
        cout<<"Doctor gender - "<<allDoctors[i].gender<<endl;
    }
}
void viewAppointment()
{
    for(int i=0;i<allAppointments.size();i++)
    {
        cout<<"Patient ID - "<<allAppointments[i].patientID;
        cout<<" has appointment with Doctor ID - "<<allAppointments[i].doctorID;
        cout<<" on Date - "<<allAppointments[i].date<<endl;
    }
}
int main()
{
    pid = 1,did = 1;
    int choice;
    do
    {
        cout<<"1 Add Patient."<<endl;
        cout<<"2 Add Doctor."<<endl;
        cout<<"3 Schedule Appointments."<<endl;
        cout<<"4 View Patient."<<endl;
        cout<<"5 View Doctors."<<endl;
        cout<<"6 View Appointments."<<endl;
        cout<<"0 Exit."<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        if(choice == 1) addPatient();
        else if(choice == 2) addDoctor();
        else if(choice == 3) scheduleAppointment();
        else if(choice == 4) viewPatient();
        else if(choice == 5) viewDoctor();
        else if(choice == 6) viewAppointment();
        else if(choice == 0) break;
        else cout<<"Invalid choice!";
        cout<<"\n\n\n";
    } while (choice != 0);
    
}