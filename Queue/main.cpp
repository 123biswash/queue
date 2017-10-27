#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//specification
class customerType
{
public:
    string fname;
    string lname;
    int id;
    int streetNum;
    string streetName;
    string streetType;
    string city;
    string state;
    int zipcode;
    char gender;
};

struct nodeType
{
    customerType info;
    nodeType* next;
};

class queueType
{
public:
    queueType();
    //~queueType();
    void enqueue(nodeType); //add to end
    nodeType dequeue(); //remove from front
    void printlist();
private:
    nodeType* qfront;
    nodeType* qrear;
};

queueType::queueType() {
    qfront = NULL;
    qrear = NULL;
}

void queueType::enqueue(nodeType n){
    
    if (qfront == NULL) {
        qfront = &n;
        qrear = &n;
    }
    
    else{
        qrear->next=&n;
        qrear=&n;
    }
}

nodeType queueType::dequeue(){
    nodeType* temp=qfront;
    if (qfront == NULL) {
        return *temp;
    }
    //one node
    nodeType* forward = qfront ->next;
    qfront = forward;
    return *temp;
    
    // if (qfront == qrear){
    
    
    // }
    // if (qfront=qrear){
    //   qfront=qrear=NULL;
    // }else{
    // qfront = qfront->next;
    // return *temp;
    // }
}

void queueType::printlist(){
    nodeType* current = qfront;
    cout << current->info.fname << " "<< current->info.lname<<endl;
    current = current->next;
    cout << current->info.fname << " "<< current->info.lname<<endl;
    
//    while (current != NULL){
//        cout << current->info.fname << " "<< current->info.lname<<endl;
//        current = current->next;
//    }
}

int main(){
    ifstream myfile;
    myfile.open("infile.txt");
    queueType q;
    while(!myfile.eof()){
        customerType x;
        myfile>>x.lname>>x.fname>>x.id>>x.streetNum>>x.streetName>>x.streetType>>x.city>>x.state>>x.zipcode>>x.gender;
//        cout << x.city;
        nodeType n;
        n.info = x;
        n.next = NULL;
        q.enqueue(n);
    }
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.printlist();
    
    myfile.close();
    return 0;
}

