//pizza parlor
#include <iostream>
#include <string>
using namespace std;
class pizzaparlor{
public:
int front,rear,size;
int capacity;
string*orders;
//initialize
pizzaparlor(int maxorders){
    capacity=maxorders;
    front=-1;
    rear=-1;
    size=0;
    orders=new string[capacity];
}

~pizzaparlor(){
    delete orders;
}

bool isfull(){
return size==capacity;
}
bool isempty(){
    return size==0;
}
void addorder(string order){
if (isfull()){
cout<<"Sorry the pizza parlor is full";
return;
}
if (front=-1){
front=0;}
rear=(rear+1)%capacity;
orders[rear]=order;
size++;
cout<<"order added:"<<order;
}

void serveorder(){
    if (isempty()){
        cout<<"no order to serve";
    return;
    }
cout<<"serving order:"<<orders[front];
front=(front+1)%capacity;
size--;
}

void displayorders(){
    if(isempty()){
        cout<<"no orders in the queue";
        return;
    }
    cout<<"current orders in the queue:";
    int i=front;
    for(int count=1;count<=size;count++){
        cout<<orders[i]<<endl;
        i=(i+1)%capacity;
    }
}

int getordercount(){
    return size;
}
};

int main(){
    int maxorders;
    cout<<"Enter maximum number of orders pizza parlor can accept\n";
    cin>>maxorders;
    pizzaparlor M(maxorders);
    int choice;
    string order;
    while(true){
        cout<<"MANGE PIZZA PARLOR MENU:\n";
        cout<<"1.Add order\n";
        cout<<"2.Serve order\n";
        cout<<"3.Display orders\n";
        cout<<"4.Exit\n";
        cout<<"Enter your choice-";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"Enter the pizza order-";
            cin.ignore();
            getline(cin,order);
            M.addorder(order);
            break;
            case 2:
            M.serveorder();
            break;
            case 3:
            M.displayorders();
            break;
            case 4:
            cout<<"Exiting the system******";
            default:
            cout<<"Invalid input\n";
            return 0;


        }
    }

}