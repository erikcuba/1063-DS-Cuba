/*Erik Cuba
1063 Data Structures
This program reads employee data into a list and uses methods to interact with the list*/


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool substringMatch(string Macro, string Micro){ //searches all code for words
        return (Macro.find(Micro) != std::string::npos);
    }
//Struct that contains all employee information
struct Employee{
    string emp_id; 
    string first_name;
    string last_name;
    string gender;
    string email;
    double hourly_pay;
    Employee *Next;

    Employee(){
      return;
    }

    Employee(string id,string first,string last,string sex,string mail, double pay){
        emp_id = id;
        first_name = first;
        last_name = last;
        gender = sex;
        email = mail;
        hourly_pay = pay;
    }
    void print(){
        cout << emp_id << first_name << last_name << gender << email << hourly_pay;
    }
};

//struct to hold employees data in a single node
struct Node
{
    Employee person;
    Node *Next;
    Node(Employee data, Node *n = NULL)
    {
        person = data;
        Next = n;
    }
};

//Class to perform methods with the employee data
class LinkedList{
private:
    Node* Head;

public:
    LinkedList(){
        Head = NULL;
    }
    //Funtion: Push adds a new node to the beginning of the list
    void push(Employee person){ 
        Node* temp = new Node(person, Head);
        Head = temp;
    }
    //Function pop deletes the first member of the list
    Employee pop(){
        Employee result = Head->person;
        Node* temp_del = Head;
        Head = Head->Next;
        delete temp_del;
        return result;

    }
    //Function find: finds a certain email and returns true or false
    bool find(string key){
        Node *temp = Head;
        while(temp != NULL){
            if(temp->person.email == key){
                return true;
            }else{
                temp = temp->Next;
            }
        }
        return false;
    }
    //Function del: deletes a certain employee's data
    void del(string key){
        Node *temp = Head;
         while(temp != NULL){
            if(temp->person.last_name == key){
             
            }else{
                temp = temp->Next;
            }
        }
    }
    //Function menu: Prints menu to the console
    int menu(){
        int choice = 0;
        while(choice < 1 || choice > 3){
            cout<<"\nMenu of Operations:\n";
            cout<<"    1 - Find Employee\n";
            cout<<"    2 - Delete Employee\n";
            cout<<"    3 - Quit\n";
            cout<<"Choice: ";
            cin>>choice;
        }
        return choice;
    }


};

int main(){

    LinkedList EmpList;
    ifstream fin;
    Employee inemp;
    fin.open("employees.dat");
    ofstream fout;
    fout.open("output.txt");


    while(!fin.eof()){
        
        fin>>inemp.emp_id>>inemp.first_name>>inemp.last_name>>inemp.email>>inemp.gender>>inemp.hourly_pay;

        //cout<<empid<<", "<<first<<", "<<last<<", "<<email<<", "<<gender<<", "<<pay<<endl;

        EmpList.push(inemp);
    }

    for(int i=0; i <30; i++){
       fout << inemp.emp_id << '\n';
    }
    fout << EmpList.find("salon") << endl;

    fin.close();
    fout.close();
    return 0;
}
