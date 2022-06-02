#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class company{
    string name;
    int year;
    public:
    void getdetails(){

        cout<<"enter name of the company:"<<endl;
        cin.ignore();

        getline(cin,name);

        cout<<"enter year of establishment:"<<endl;
        cin>>year;
    }
    void display(){

        cout<<"name of the company:"<<name<<endl;
        
        cout<<"year of establishment:"<<year<<endl;
        
    }

};

class employee:public company{
    string emp_name;
    string desg;
    int age;
    int emp_id;
    public:
    employee()
    {
        getemp();
    }
    void getemp(){
        cout<<"enter name of the employee:"<<endl;
        cin.ignore();
        getline(cin,emp_name);
        cout<<"enter designation of the employee:"<<endl;
        cin.ignore();
        getline(cin,desg);
        cout<<"enter age of the employee:"<<endl;
        cin>>age;
        cout<<"enter emp_id of the employee:"<<endl;
        cin>>emp_id;
    }
    void displayemp()
     {
        cout<<"name of the employee:"<<emp_name<<endl;
   
        cout<<"designation of the employee:"<<desg<<endl;
  
        cout<<"age of the employee:"<<age<<endl;
    
        cout<<"emp_id of the employee:"<<emp_id<<endl;

    }
    
};

class department : public company{
    string dep_name;
    int n_employees;
    int dep_id;
    public:
    department():company()
    {
        getdetails();
        getdep();

    }

    void getdep(){
        cout<<"enter department's name:"<<endl;
        cin.ignore();
        getline(cin,dep_name);
        cout<<"enter number of employees:"<<endl;
        cin>>n_employees;
        cout<<"enter department id:"<<endl;
        cin>>dep_id;
    }
 
    
    void displaydep(){
        cout<<"department name:"<<dep_name<<endl;
        cout<<"number of employees:"<<n_employees<<endl;
        cout<<"department id:"<<dep_id<<endl;
    }

    void display1(){
        display();
        displaydep();
    }

};

int main()
{
    employee e;
    department d;
    d.display1();
    e.displayemp();

}