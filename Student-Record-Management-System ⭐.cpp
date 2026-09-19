#include <iostream>
#include<fstream>

using namespace std;
void addstudent()
{
    ofstream out("students.txt",ios::app);

    string name;
    int roll, marks;

    cin.ignore();

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter roll number: ";
    cin >> roll;

    cout << "Enter marks: ";
    cin >> marks;

    out << name << endl;
    out << roll << endl;
    out << marks << endl;

    out.close();

    cout << "Student added successfully!" << endl;
}
void display()
{
    ifstream in("students.txt");
    string name;
    int roll,marks;
    while(getline(in,name)){
            in >> roll;
        in >> marks;
        in.ignore();

        cout << "Name: " << name << endl;
        cout << "Roll: " << roll << endl;
        cout << "Marks: " << marks << endl;
        cout << "----------------" << endl;
    }
    in.close();
}
void search()
{
    ifstream in("students.txt");
    string name;
    int roll,marks,r;
   bool found=false;
   cout<<"Enter roll number: "<<endl;
   cin>>r;
   while(getline(in,name))
   {
       in>>roll;
       in>>marks;
       in.ignore();
       if(r==roll){
       cout<<"Name: "<<name<<endl;
       cout<<"Marks: "<<marks<<endl;
        found=true;
       }

   }
       if(!found){
        cout<<"student not found...."<<endl;
    }
 in.close();
     cout<<"----------------------"<<endl;

}
void average()
{
    ifstream in("students.txt");
    string name;
    int marks,roll,count=0;
    int sum=0;
    int average=0;
    while(getline(in,name))
    {
        in>>roll;
        in>>marks;
        in.ignore();
        sum=sum+marks;
        count++;
    }
    in.close();
    average=sum/count;
    cout<<"Average: "<<average<<endl;

  cout<<"---------------------------------"<<endl;
}
void highest()
{
    ifstream in("students.txt");
    string name,title;
    int roll,r=0,marks,max=0;
    while(getline(in,name))
    {
        in>>roll;
        in>>marks;
        in.ignore();
        if(marks>max){
            max=marks;
            title=name;
            r=roll;
        }
    }
    in.close();
    cout<<"Maximum: "<<max<<endl;
    cout<<"Name: "<<title<<endl;
    cout<<"Roll Number: "<<r<<endl;
    cout<<"----------------------"<<endl;
}
int main()
{
    int choice;
    do
    {
        cout<<"1. Add Student"<<endl;
        cout<<"2. Display Student"<<endl;
        cout<<"3. Search"<<endl;
        cout<<"4. Average"<<endl;
        cout<<"5. Highest"<<endl;
        cout<<"6. exit"<<endl;
        cout<<"......................."<<endl;
  cout<<"Enter the choice..!"<<endl;
  cin>>choice;


    switch(choice){
case 1:
     addstudent();
    break;
case 2:
     display();
    break;
case 3:
    search();
    break;
case 4:
    average();
    break;
case 5:
    highest();
    break;
case 6:
    cout<<"Program exit"<<endl;
    break;
default:
    cout<<"invalid choice";
    break;
    }

}while(choice!=6);
    return 0;
}
