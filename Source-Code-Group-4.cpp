#include <iostream>
#include <queue>
#include <stack>
using namespace std;

        string RMNO[5] = {"SR-101","TR-201","DR-301", "RV-401", "PS-501"};
        string RMDESC[5] = {
            "One of the most common types of room at any hotel is the single. Typically, this means that the room has one bed meant for one person or a couple, but it doesn't necessarily mean \t\t\t\t that the room is small.",
            "Both a twin and double room contain two beds in the space, the difference pertaining to the size of the beds and the number of guests that can stay in the room. A twin room contains \t\t\t two single size beds.",
            "A deluxe room is one of the most popular choices of guests because of its comfort and supply of amenities, without being too over-the-top or expensive. It has at least two beds which \t\t\t can fit up to four people so is perfect for those traveling in a group or for small families.",
            "Our hotel is located in a picturesque destination, many of your guests may find it important that their room provides a great view of the surrounding area. Not every room at a 5-star \t\t\t hotel has a fantastic view of the city or countryside, which ours have.",
            "A presidential or executive suite emphasizes comfort and luxury above all else and is often the most expensive room. A presidential suite will vary based on each hotel, but are often \t\t\t constructed in the style as a regular suite, but with more space, nicer décor, and more amenities and services."
                        };
        string RMTYPE[5] = {
                    "Single Room",
                    "Twin or Double Room",
                    "Deluxe Room",
                    "Room with a View",
                    "Presidential Suite"
                        };
        string PRICE[5] = {
                    "1000php/day",
                    "2000php/day",
                    "4000php/day",
                    "6000php/day",
                    "8000php/day"
                    };
        string BOOKST[2] = {
                    "Vacant",
                    "Occupied"
                    };
        string line = "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
        //for stack
        string oldRMNO[15] = {
            "SR101", "SR102", "SR103",
            "TR201", "TR202", "TR203",
            "DR401", "DR402", "DR403",
            "RV601", "RV602", "RV603",
            "PS801", "PS802", "PS803"
        };
        string shallowcopy[15] = {
            "SR101", "SR102", "SR103",
            "TR201", "TR202", "TR203",
            "DR401", "DR402", "DR403",
            "RV601", "RV602", "RV603",
            "PS801", "PS802", "PS803"
        };
        string oldBOOKST[3] = {
            "VC",
            "VD",
            "OC"
        };
        string store[15];

//Structure of the Node
struct Node{
    int data;
    string stats;
    Node *link;
    Node *link2;
};

// top pointer to keep track of the top of the stack
Node *top = NULL;
Node *stats = NULL;

//Function to check if stack is empty or not
bool isempty(){
    if(top == NULL)
    return true; else
    return false;
}

//Function to insert an element in stack
void push (int value,string stat){

    Node *ptr = new Node();
    ptr->data = value;
    ptr->link = top;
    top = ptr;



}

// Function to Display the stack
void displayStack(){

    if ( isempty() ) {
        cout<<"Stack is Empty";
    }
    else
    {
        Node *temp=top;
        while(temp!=NULL) {
            cout<<"ROOMS ID NO:" <<oldRMNO[14 - temp->data]<< endl;
            cout<<"BOOKS STATUS:" <<store[temp->data]<< endl;
            temp=temp->link;
        }
        cout<<"\n";
    }
}

void UpdateRoom(string avail, int counterCase4) {
    if (!isempty())
    {
        Node *temp=top;
        while(temp!=NULL) {

            if (oldRMNO[14 - temp->data] == avail && store[temp -> data] == oldBOOKST[2]) {
                cout << "This Room is already Occupied" << endl;
                counterCase4 = 0;
            }
            if (oldRMNO[14 - temp->data] == avail) {
                cout <<"Booking Success" << endl;
                store[temp -> data] = oldBOOKST[2];
            }
            temp=temp->link;
        }
        cout<<"\n";
    }
}

void DeleteRoom(string avail, int counterCase4) {
    if (!isempty())
    {

        Node *temp=top;
        while(temp!=NULL) {

            if (oldRMNO[14 - temp->data] == avail && store[temp -> data] == oldBOOKST[0]) {
                cout << "This room is already vacant" << endl;
                counterCase4 = 0;
            }
            if (oldRMNO[14 - temp->data] == avail) {
                cout <<"Room Book ID:" << shallowcopy[14-temp->data] << " has been deleted" << endl;
                store[temp -> data] = oldBOOKST[0];
                oldRMNO[14 - temp -> data] = shallowcopy[14-temp->data];
            }
            temp=temp->link;
        }
        cout<<"\n";
    }
}

void ChangeAvailability(string avail) {
    if (!isempty())
    {
        Node *temp=top;
        while(temp!=NULL) {
            if (oldRMNO[14 - temp->data] == avail && store[temp -> data] == oldBOOKST[0]) {
                cout<<"ROOMS ID:" << avail << "is now Vacant!" << endl;
            }
            temp=temp->link;
        }
        cout<<"\n";
    }
}

void AvailabilityRooms(int counterCase3) {
    if (!isempty())
    {
        Node *temp=top;
        while(temp!=NULL) {
            if (store[14 - temp -> data] == oldBOOKST[0]) {

                cout<<"ROOMS ID NO:" <<oldRMNO[14 - temp->data]<< endl;
                counterCase3 = 0;
            }
            temp=temp->link;
        }
        cout<<"\n";
    }
}

void AvailableStack(){
    if (!isempty())
    {
        Node *temp=top;
        while(temp!=NULL) {

            if (store[temp->data] == oldBOOKST[0]) {
                cout<<"ROOMS ID NO. AVAILABALE:" <<oldRMNO[14 - temp->data]<< endl;
            }
            temp=temp->link;
        }
        cout<<"\n";
    }
}

void stackDataStructure(){

    int choice = -1;
    stack <string> status;
    int loop;

    //
    int value;
    int choice2;
    int flag = 1;
    //

    for(loop = 0; loop < 15; loop++) {
        status.push(oldBOOKST[0]);
        store[loop] = status.top();
        push(loop,oldBOOKST[0]);
    }


    while (choice != 0) {
        stack <string> temp;
        cout << "Stack" << endl;
        cout << "[1] Stack using Array" << endl;
        cout << "[2] Stack using Linkedlist" << endl;
        cout << "[3] Stack Using C++ STL" << endl;
        cout << "[0] Back to Main Menu" << endl;
        cout << "Enter your Choice -> ";
        cin >> choice;
        string avail;
        system("CLS");
        int i = 0;

        int answer = -1;

        if (choice == 0) {
            break;
        } else if (choice == 3) {
            while(answer != 0) {
                i = 0;
                cout <<"Stack using C++ STL" << endl;
                cout << "[1] Rooms" << endl;
                cout << "[2] Available Rooms" << endl;
                cout << "[3] Update Rooms Availability" << endl;
                cout << "[4] Book Room" << endl;
                cout << "[5] Delete Room Book Id" << endl;
                cout << "[0] Back to Main Menu" << endl;
                cout << "Enter your Choice:";
                int counterCase3 = -1, counterCase4 = -1, ifCounter = -1;
                cin >> answer;
                system("CLS");

                if(answer == 0) {
                    break;
                } else if (answer == 1) {
                    cout <<"Rooms in our Hotel" << endl << endl;

                    for (int j = 0;j <= 14; j++) {
                        cout << "ROOMS ID NO :" << oldRMNO[j] << endl;
                        // cout << "DESCRIPTION :" << RMDESC[j] << endl;
                        // cout << "ROOM TYPE   :" << RMTYPE[j] << endl;
                        // cout << "PRICE       :" << PRICE[j] << endl;
                        cout << "BOOK STATUS :" << status.top() << endl;
                        store[i] = status.top();
                        status.pop();
                    }

                    if (status.empty() == true) {
                        while (i < sizeof(store) / sizeof(store[0])) {
                            status.push(store[14-i]);
                            i++;
                        }
                    }

                } else if (answer == 2) {
                    cout<< "Available Rooms" << endl;
                    for (int j = 0; j <= 14; j++) {
                        if (status.top() == oldBOOKST[0]) {
                            cout << "ROOMS ID NO. AVAILABLE:" << oldRMNO[j] << endl;
                        }
                        status.pop();
                    }
                    if (status.empty() == true) {
                        while (i < sizeof(store) / sizeof(store[0])) {
                            status.push(store[14-i]);
                            i++;
                        }
                    }

                } else if (answer == 3 ) {
                    cout<<"These are the Occupied Rooms: "<<endl<<endl;

                    if (status.empty() == true) {
                        while (i < sizeof(store) / sizeof(store[0])) {
                            status.push(store[14-i]);
                            i++;
                        }
                        i = 0;
                    }

                    for(int j = 0 ; j <= 14; j++) {
                        cout << status.top() << " ";
                        if (status.top() == oldBOOKST[2]) {
                            cout << "ROOMS ID NO :" << oldRMNO[j] << endl;
                            counterCase3 = 0;
                        }
                        status.pop();
                    }

                    while (i < sizeof(store) / sizeof(store[0])) {
                        status.push(store[14-i]);
                        i++;
                    }
                    i = 0;
                    if (counterCase3 == -1) {
                        cout << "No Occupied Rooms" << endl;
                    }
                    else {
                        cout << "Enter 0 to Back" << endl;
                        cout << "Enter your Room ID to Change Availability:";
                        cin >> avail;
                        if (avail == "0")  {
                            cout << endl;
                        }
                        else {
                            for(int j = 0; j <= 14; j++) {
                                if (oldRMNO[j] == avail && status.top() == oldBOOKST[0]) {
                                    ifCounter = 0;
                                    cout <<"Room ID:" << avail << " is now Vacant!" << endl;
                                    store[j] = oldBOOKST[2];
                                }
                                status.pop();
                            }
                            while (i < sizeof(store) / sizeof(store[0])) {
                                status.push(store[14-i]);
                                i++;
                            }
                        }
                    }
                    // break;

                } else if (answer == 4 ) {
                    cout<<"Enter Room Id you want to book: ";
                    cin >> avail;
                    for(int j = 0; j<=14;j++) {
                        if(status.top() == oldBOOKST[2] && oldRMNO[j] == avail){
                            cout << "This Room is already Occupied" << endl;
                            counterCase4 = 0;
                        }
                        if (oldRMNO[j] == avail) {
                            cout <<"Booking Success" << endl;
                            counterCase4 = 0;
                            store[j] = oldBOOKST[2];
                        }
                        status.pop();
                    }
                    if (status.empty() == true) {
                        while (i < sizeof(store) / sizeof(store[0])) {
                            status.push(store[14-i]);
                            i++;
                        }
                    }
                } else if (answer == 5 ){
                    cout<<"Enter Room Id You want to VC: ";
                    cin >> avail;

                    for(int j = 0; j<=14;j++) {
                        if(status.top() == oldBOOKST[0] && oldRMNO[j] == avail){
                            cout << "This room is already vacant" << endl;
                            counterCase4 = 0;
                        }
                        if (oldRMNO[j] == avail) {
                            cout <<"Room Book ID:" << shallowcopy[j] << " has been deleted" << endl;
                            counterCase4 = 0;
                            store[j] = oldBOOKST[0];
                            oldRMNO[j] = shallowcopy[j];
                        }
                        status.pop();
                    }
                    if (status.empty() == true) {
                        while (i < sizeof(store) / sizeof(store[0])) {
                            status.push(store[14-i]);
                            i++;
                        }
                    }
                }

            }
            break;
        } else if (choice == 2) {
            while(answer != 0) {
                i = 0;
                cout <<"Stack using LinkedList" << endl;
                cout << "[1] Rooms" << endl;
                cout << "[2] Available Rooms" << endl;
                cout << "[3] Update Rooms Availability" << endl;
                cout << "[4] Book Room" << endl;
                cout << "[5] Delete Room Book" << endl;
                cout << "[0] Back to Main Menu" << endl;
                cout << "Enter your Choice:";
                int counterCase3 = -1, counterCase4 = -1, ifCounter = -1;
                cin >> answer;
                system("CLS");

                if (answer == 0) {
                    break;
                }
                else if (answer == 1) {
                    cout << "Rooms in our Hotel" << endl;
                    displayStack();
                }
                else if (answer == 2) {
                    cout << "Available Rooms" << endl;
                    AvailableStack();
                }
                else if (answer == 3) {

                    AvailabilityRooms(counterCase3);

                    if (counterCase3 == -1) {
                        cout << "No Occupied Rooms" << endl;
                    }
                    else {
                        cout << "Enter 0 to Back" << endl;
                        cout << "Enter your Room ID to Change Availability:";
                        cin >> avail;
                        if (avail == "0")  {
                            cout << endl;
                        }
                        else {
                            ChangeAvailability(avail);
                        }
                    }
                }
                else if (answer == 4) {
                    cout<<"Enter Room Id you want to book: ";
                    cin >> avail;

                    UpdateRoom(avail,counterCase4);
                } else if (answer == 5) {
                    cout<<"Enter Room Id you want to VC: ";
                    cin >> avail;

                    DeleteRoom(avail,counterCase4);
                }

            }
            break;
        } else if (choice == 1) {
            while (answer != 0) {
                cout <<"Stack using Array" << endl;
                cout << "[1] Rooms" << endl;
                cout << "[2] Available Rooms" << endl;
                cout << "[3] Update Rooms Availability" << endl;
                cout << "[4] Book Room" << endl;
                cout << "[5] Delete Room Book" << endl;
                cout << "[0] Back to Main Menu" << endl;
                cout << "Enter your Choice:";
                int counterCase3 = -1, counterCase4 = -1, ifCounter = -1;
                cin >> answer;
                system("CLS");

                if (answer == 0 ) {
                    break;
                }
                else if ( answer == 1) {
                    cout <<"Rooms in our Hotel" << endl << endl;
                    for (int j = 0;j <= 14; j++) {
                        cout << "ROOMS ID NO :" << oldRMNO[j] << endl;
                        cout << "BOOK STATUS :" << store[j] << endl;
                        store[j] = store[j];
                    }
                }
                else if ( answer == 2) {
                    cout<< "Available Rooms" << endl;
                    for (int j = 0; j <= 14; j++) {
                        if (store[j] == oldBOOKST[0]) {
                            cout << "ROOMS ID NO. AVAILABLE:" << oldRMNO[j] << endl;
                        }
                    }
                }
                else if ( answer == 3) {
                    cout<<"These are the Occupied Rooms: "<<endl;


                    for(int j = 0 ; j <= 14; j++) {
                        if (store[j] == oldBOOKST[2]) {
                            cout << "ROOMS ID NO :" << oldRMNO[j] << endl;
                            counterCase3 = 0;
                        }
                    }


                    if (counterCase3 == -1) {
                        cout << "No Occupied Rooms" << endl;
                    }
                    else {
                        cout << "Enter 0 to Back" << endl;
                        cout << "Enter your Room ID to Change Availability:";
                        cin >> avail;
                        if (avail == "0")  {
                            cout << endl;
                        }
                        else {
                            for(int j = 0; j <= 14; j++) {
                                if (oldRMNO[j] == avail && store[j] == oldBOOKST[0]) {
                                    ifCounter = 0;
                                    cout <<"Room ID:" << avail << " is now Vacant!" << endl;
                                    store[j] = oldBOOKST[2];
                                }
                            }
                        }
                    }
                }
                else if ( answer == 4) {
                    cout<<"Enter Room Id you want to book: ";
                    cin >> avail;
                    for(int j = 0; j<=14;j++) {
                        if(store[j]== oldBOOKST[2] && oldRMNO[j] == avail){
                            cout << "This Room is already Occupied" << endl;
                            counterCase4 = 0;
                        }
                        if (oldRMNO[j] == avail) {
                            cout <<"Booking Success" << endl;
                            counterCase4 = 0;
                            store[j] = oldBOOKST[2];
                        }
                    }
                } else if (answer == 5) {
                    cout << "Enter Room Id you want to VC";
                    cin >> avail;
                    for(int j = 0; j<=14;j++) {
                        if(store[j]== oldBOOKST[0] && oldRMNO[j] == avail){
                            cout << "This room is already vacant" << endl;
                            counterCase4 = 0;
                        }
                        if (oldRMNO[j] == avail) {
                            cout <<"Room Book ID:" << shallowcopy[j] << " has been deleted" << endl;
                            counterCase4 = 0;
                            store[j] = oldBOOKST[0];
                            oldRMNO[j] = shallowcopy[j];
                        }
                    }
                }

            }
            // break;
        } else {
            cout << "Invalid selected number" << endl;
        }

    }
}



void groupMembers(){
    int choice;
    do{
    cout<<"Group Members"<<endl<<endl;
    cout<<"[1] Leader"<<endl;
    cout<<"[2] Member 1"<<endl;
    cout<<"[3] Member 2"<<endl;
    cout<<"[4] Member 3"<<endl;
    cout<<"[5] Member 4"<<endl;
    cout<<"[6] Member 5"<<endl;
    cout<<"[7] Member 6"<<endl;
    cout<<"[8] Member 7"<<endl;
    cout<<"[0] Back to Main Menu"<<endl;
    cout<<"Enter your Choice -> ";
    cin>>choice;
    system("CLS");

    switch(choice){
    case 0: system("CLS"); break;
    case 1: cout<<"Leader"<<endl<<endl;
            cout<<"Name: Johndel B. Bernardo"<<endl;
            cout<<"Age: 19"<<endl;
            cout<<"Year and Course: BSIT - 2B"<<endl;
            cout<<"Address: Barihan Malolos city of Bulacan"<<endl;
            cout<<"Motto/Saying in Programming: Sa papel walang error"<<endl<<endl;
            break;
    case 2: cout<<"Name: Marc William P. Valiente"<<endl;
            cout<<"Age: 19"<<endl;
            cout<<"Year and Course: BSIT - 2B"<<endl;
            cout<<"Address: San Isidro, Hagonoy, Bulacan"<<endl;
            cout<<"Motto/Saying in Programming: C++ is !Easy"<<endl<<endl;
            break;
    case 3: cout<<"Name: Jashfer C. Chin"<<endl;
            cout<<"Age: 19"<<endl;
            cout<<"Year and Course: BSIT - 2B"<<endl;
            cout<<"Address: Malolos City, Bulacan"<<endl;
            cout<<"Motto/Saying in Programming: Walang kamatayang Hello world"<<endl<<endl;
            break;
    case 4: cout<<"Name: Caleb David G. Santos"<<endl;
            cout<<"Age: 19"<<endl;
            cout<<"Year and Course: BSIT - 2B"<<endl;
            cout<<"Address: San Francisco Bulakan ,Bulacan"<<endl;
            cout<<"Motto/Saying in Programming: Kalimutan mo na lahat wag lang semi colon at ako"<<endl<<endl;
            break;
    case 5: cout<<"Name: Mharienell P. Matawaran"<<endl;
            cout<<"Age: 19"<<endl;
            cout<<"Year and Course: BSIT - 2B"<<endl;
            cout<<"Address: Balubad Bulakan Bulacan"<<endl;
            cout<<"Motto/Saying in Programming:  Kung di mo mahanap ang error, ipa code mo nalang saming mga babae tutal kami naman lagi ang tama"<<endl<<endl;
            break;
    case 6: cout<<"Name: Angelo Jamir B. Velada"<<endl;
            cout<<"Age: 20"<<endl;
            cout<<"Year and Course: BSIT - 2B"<<endl;
            cout<<"Address: Mambog Malolos, Bulacan"<<endl;
            cout<<"Motto/Saying in Programming: Being an honor student easy why? Diko din alam diko pa na try"<<endl<<endl;
            break;
    case 7: cout<<"Name: Mark Jervey S. Evangelista"<<endl;
            cout<<"Age: 19"<<endl;
            cout<<"Year and Course: BSIT - 2B"<<endl;
            cout<<"Address: Balayong Malolos,Bulacan "<<endl;
            cout<<"Motto/Saying in Programming: Pag dina kaya mag shift na"<<endl<<endl;
            break;
    case 8: cout<<"WALANG PARAMDAM"<<endl<<endl;    break;
    default: cout<<"Invalid Choice Selected"<<endl<<endl;
    }
    }while(choice != 0);
}

//for interpolation sort
string room="";
string surname="";
int HotelRoom[5] = {101,201,301,401,501};
int ID, low, high, mid, flag, number, cmps = 0;
void getData(){
    cout << "\nPlease enter Room id number that you want: ";
    cin >> ID;
    cout<<"Please enter your prefer room Category: \n";
    cin>>room;
    cout<<"Enter Your Surname:\n";
    cin>>surname;
}
void Search(){
    low = 0;
    high = 5 - 1;
    flag = -1;

    while (HotelRoom[low] <= ID && HotelRoom[high] >= ID){//initializing the array values
        mid = low + ((ID - HotelRoom[low]) * (high - low)) / (HotelRoom[high] - HotelRoom[low]);
        cmps++;
        if (HotelRoom[mid] < ID){
            low = mid + 1;
            }
        else if (HotelRoom[mid] > ID)
            {
            high = mid - 1;
            }
        else
            {
            number = mid;
            flag = 1;
            break;
            }
    }//indicates end of while loop
    }
void displayInter(){
    cout<<" "<<endl;
    cout<<"Your Prefer RoomType is : "<<room<<endl;
    cout<<"Your Surname is : "<<surname<<endl;
        if (flag == -1)
            cout << "\nSorry your given RoomID - " << ID<< " is not in the our list" << endl; //Indicates that the value given is not in the arra
        else{
            cout << "\nGiven roomID - " << ID << " is in our list " << number+1 << endl; //Indicates that the array is listed
            cout<<"Do you want to book now?"<<endl;
        }
}
//for queue
class Hotel{
    public:
    string Rate;
    int RoomID;
    float Bill;
    Hotel* next;
};
Hotel* front = NULL;
Hotel* rear = NULL;
bool isEmpty(){
    return(front == NULL && rear == NULL);
}
void insert(string Rate, int RoomID, float Bill){
     Hotel* temp = new Hotel;
     temp->Rate = Rate;
     temp->RoomID = RoomID;
     temp->Bill = Bill;
     temp->next = NULL;

    if(front == NULL) front = rear = temp;
    else{
        rear->next = temp;
        rear = temp;
    }
    cout<<"\nInsert Success";
}
void remove(){
    if(isEmpty()){
        cout<<"\nRate is empty"<<endl<<endl;
        return;
    }

    else if( front == rear) front = rear = NULL;
    else{
        Hotel* temp = front;
        front = front->next;
        delete(temp);
    }
    cout<<"\nDeleting Success"<<endl<<endl;
}
void display(){
    if(isEmpty()){
        cout<<"\nRate is empty"<<endl<<endl;
        return;
    }
    int i=1;
    Hotel* temp = front;

    while(temp){
        cout<<"\nRate #"<<i<<endl;
        cout<<"Rate      : "<<temp->Rate<<endl;
        cout<<"RoomID    : "<<temp->RoomID<<endl;
        cout<<"Bill      : "<<temp->Bill<<endl;
        temp = temp->next;
        i++;
    }
    cout<<endl<<endl;
}
void rcategory(){
     for (int i=0; i<5; i++)
{

    cout<<"ROOMID NUMBER: "<<RMNO[i]<<endl;
    cout<<"DESCRIPTION "<<RMDESC[i]<<endl;
    cout<<"ROOM TYPE: "<<RMTYPE[i]<<endl;
    cout<<"ROOM PRICE: "<<PRICE[i]<<endl;
    cout<<line<<endl<<endl;
}
}
void input(){
    string Rate;
    int RoomID;
    float Bill;

    cout<<"Enter Rate"<<endl;
    cout<<"Please choose if it is: "<<endl;
    cout<<"[Bad][Fair][Excellent]: ";
    cin>>Rate;
    cout<<"RoomID                : ";
    cin>>RoomID;
    cout<<"Bill                  : ";
    cin>>Bill;
    insert(Rate, RoomID, Bill);
    cout<<endl<<endl;
}
class Queue{
   private:
    int front;
    int rear;
     string arr[5];
  public:
    Queue()
    {
        front= -1;
        rear= -1;
        for(int i=0; i<5; i++)
        {
            arr[i]="";
        }
    }
    bool nothing()
    {
        if(front==-1 && rear==-1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if(rear==4)
            return true;
        else
            return false;
    }
    void insert(string val)
    {
        if(isFull())
        {
            cout<<"Queue is full"<<endl;
            return;
        }
        else if(nothing())
        {
            rear=0;
            front=0;
            arr[rear]=val;
        }
        else
        {
            rear++;
            arr[rear]=val;
        }
    }
    string remove()
    {
        string x;
        if(nothing())
        {
            cout<<"Rate is Empty"<<endl;
            return 0;
        }
        else if(front == rear)
        {
            x = arr[front];
            arr[front] = "";
            rear = -1;
            front = -1;
            return x;
        }
        else
        {
            x=arr[front];
            arr[front] = "";
            front++;
            return x;
        }
    }

    int count()
    {
        return (rear-front);
    }
    void display()
    {
        cout<<"\nRate so far are : "<<endl;
        for (int i=0; i<5; i++)
        {
          cout<<arr[i]<<"    "<<endl;
        }
    }
 void rcategory()
        {      for (int i=0; i<5; i++)
        {

            cout<<"ROOMID NUMBER: "<<RMNO[i]<<endl;
            cout<<"DESCRIPTION "<<RMDESC[i]<<endl;
            cout<<"ROOM TYPE: "<<RMTYPE[i]<<endl;
            cout<<"ROOM PRICE: "<<PRICE[i]<<endl;
            cout<<line<<endl<<endl;
        }
        }
};


class hotelAndTourism{
        public:
            string roomNum;
            string description;
            string type;
            string price;
            string status;
            hotelAndTourism* next;
            hotelAndTourism* prev;
 };

void searchAndSorting(){
   int choice;
    do{
       int case1choice;
       int case2choice;

       cout<<"Search & Sorting Algorithm"<<endl<<endl;
       cout<<"[1] Search Algorithms (3 kinds)"<<endl;
       cout<<"[2] Sorting Algorithms (3 kinds)"<<endl;
       cout<<"[3] Sample Application"<<endl;
       cout<<"[0] Back to Main Menu"<<endl;
       cout<<"Enter your Choice -> ";
       cin>>choice;
       system("CLS");

       switch(choice){
        case 0: break;
        case 1: do{
                //for linear
                string roomID;
                int i;
                //for binary
                int left = 0, right = 4, mid;
                int a = -1;
                int roomPos;
                cout<<"===== Searching Algorithms ====="<<endl<<endl;
                cout<<"[1] Linear Search"<<endl;
                cout<<"[2] Binary Search"<<endl;
                cout<<"[3] Interpolation Search"<<endl;
                cout<<"[0] Back"<<endl;
                cout<<"Enter your Choice -> ";
                cin>>case1choice;
                system("CLS");

                switch(case1choice){
                    case 0: break;
                    case 1: cout<<"Enter Room ID you want to Search: ";
                            cin>>roomID;
                            system("CLS");

                            for(i = 0; i<5; i++){
                                if(RMNO[i] == roomID){
                                    cout<<"This is the Room that you are Searching for : "<<endl<<endl;
                                    cout<<"ROOM ID NO.  : "<<RMNO[i]<<endl;
                                    cout<<"DESCRIPTION  : "<<RMDESC[i]<<endl;
                                    cout<<"ROOM TYPE    : "<<RMTYPE[i]<<endl;
                                    cout<<"PRICE        : "<<PRICE[i]<<endl;
                                    cout<<"BOOK STATUS  : "<<BOOKST[i]<<endl<<endl;
                                    break;
                                }
                            }
                            if(i == 5) cout<<"Room ID: "<<roomID<<" does not exist in our Hotel"<<endl<<endl;
                            break;
                    case 2: cout<<"Enter Room ID you want to Search: ";
                            cin>>roomID;
                            system("CLS");
                            //para ma compare sya sa else if, pag roomID kasi icocompare di pede kasi string sya
                            if(roomID == "SR-101") roomPos = 0;
                            else if(roomID == "TR-201") roomPos = 1;
                            else if(roomID == "DR-301") roomPos = 2;
                            else if(roomID == "RV-401") roomPos = 3;
                            else if(roomID == "PS-501") roomPos = 4;


                            while(left <= right){
                                mid = left + (right - left)/2;

                                if(RMNO[mid] == roomID){
                                    cout<<"This is the Room that you are Searching for : "<<endl<<endl;
                                    cout<<"ROOM ID NO.  : "<<RMNO[mid]<<endl;
                                    cout<<"DESCRIPTION  : "<<RMDESC[mid]<<endl;
                                    cout<<"ROOM TYPE    : "<<RMTYPE[mid]<<endl;
                                    cout<<"PRICE        : "<<PRICE[mid]<<endl;
                                    cout<<"BOOK STATUS  : "<<BOOKST[mid]<<endl<<endl;
                                    a = 0;
                                    break;
                                }
                                else if(mid < roomPos){
                                    left = mid+1;
                                }
                                else {
                                    right = mid-1;
                                }
                            }
                            if(a == -1) cout<<"Room ID: "<<roomID<<" does not exist in our Hotel"<<endl<<endl;

                         break;

                    case 3: getData();
                            Search();
                            displayInter();
                            break;
                    default:  cout<<"Invalid Choice Selected"<<endl<<endl;

                }
                }while(case1choice != 0);

                break;
        case 2: do{
                int tempPrice[5] = {6000, 2000, 8000, 1000, 4000};
                //bubble
                int temp;
                //selection
                int chk;
                int index;
                int small;
                //for insertion
                int j;
                int key;
                cout<<"===== Sorting Algorithms ====="<<endl<<endl;
                cout<<"[1] Bubble Sort"<<endl;
                cout<<"[2] Selection Sort"<<endl;
                cout<<"[3] Insertion Sort"<<endl;
                cout<<"[0] Back"<<endl;
                cout<<"Enter your Choice -> ";
                cin>>case2choice;
                system("CLS");

                switch(case2choice){
                    case 0: break;
                    case 1: cout<<"===== Sorted using Bubble Sort (by Price) ====="<<endl<<endl;

                            for(int i = 0; i<5; i++){
                                for(int j = i+1; j<5; j++){
                                    if(tempPrice[i] > tempPrice[j]){
                                        temp = tempPrice[i];
                                        tempPrice[i] = tempPrice[j];
                                        tempPrice[j] = temp;
                                    }
                                }
                            }
                            for(int i = 0; i<5; i++){
                                cout<<"ROOM ID NO.  : "<<RMNO[i]<<endl;
                                cout<<"DESCRIPTION  : "<<RMDESC[i]<<endl;
                                cout<<"ROOM TYPE    : "<<RMTYPE[i]<<endl;
                                cout<<"PRICE        : "<<tempPrice[i]<<" php/day"<<endl;
                                cout<<"BOOK STATUS  : "<<BOOKST[0]<<endl<<endl;
                                cout<<line<<endl<<endl;
                                }

                            break;
                    case 2: cout<<"===== Sorted using Selection Sort (by Price) ====="<<endl<<endl; //source - https://codescracker.com/cpp/program/cpp-program-selection-sort.htm
                            for(int i=0; i<4; i++){
                                chk=0;
                                small = tempPrice[i];
                                for(int j=i+1; j<5; j++){
                                    if(small>tempPrice[j]){
                                        small = tempPrice[j];
                                        chk++;
                                        index = j;
                                    }
                                }
                                    if(chk!=0){
                                        temp = tempPrice[i];
                                        tempPrice[i] = small;
                                        tempPrice[index] = temp;
                                }
                            }
                                for(int i = 0; i<5; i++){
                                cout<<"ROOM ID NO.  : "<<RMNO[i]<<endl;
                                cout<<"DESCRIPTION  : "<<RMDESC[i]<<endl;
                                cout<<"ROOM TYPE    : "<<RMTYPE[i]<<endl;
                                cout<<"PRICE        : "<<tempPrice[i]<<" php/day"<<endl;
                                cout<<"BOOK STATUS  : "<<BOOKST[0]<<endl<<endl;
                                cout<<line<<endl<<endl;
                                }
                            break;
                    case 3: cout<<"===== Sorted using Insertion Sort (by Price) ====="<<endl<<endl; //https://www.programiz.com/dsa/insertion-sort
                            for (int i = 1; i < 5; i++) {
                                 key = tempPrice[i];
                                 j = i - 1;
                                while (key < tempPrice[j] && j >= 0) {
                                  tempPrice[j + 1] = tempPrice[j];
                                  --j;
                                }
                                tempPrice[j + 1] = key;
                              }
                             for(int i = 0; i<5; i++){
                                cout<<"ROOM ID NO.  : "<<RMNO[i]<<endl;
                                cout<<"DESCRIPTION  : "<<RMDESC[i]<<endl;
                                cout<<"ROOM TYPE    : "<<RMTYPE[i]<<endl;
                                cout<<"PRICE        : "<<tempPrice[i]<<" php/day"<<endl;
                                cout<<"BOOK STATUS  : "<<BOOKST[0]<<endl<<endl;
                                cout<<line<<endl<<endl;
                                }

                        break;
                    default:  cout<<"Invalid Choice Selected"<<endl<<endl;
                }
                }while(case2choice != 0);

                break;
        case 3: break;
        default:  cout<<"Invalid Choice Selected"<<endl<<endl;


       }


    }while(choice != 0);




}

void linkedlist(){
    int choice;
    hotelAndTourism* hotel1 = new hotelAndTourism;
    hotelAndTourism* hotel2 = new hotelAndTourism;
    hotelAndTourism* hotel3 = new hotelAndTourism;
    hotelAndTourism* hotel4 = new hotelAndTourism;
    hotelAndTourism* hotel5 = new hotelAndTourism;


    do{
       string avail;
       int answer;
       cout<<"===== Linked Lists ====="<<endl<<endl;
       cout<<"[1] Singly Linked List"<<endl;
       cout<<"[2] Doubly Linked List"<<endl;
       cout<<"[3] Circular Linked List"<<endl;
       cout<<"[0] Back to Main Menu"<<endl;
       cout<<"Enter your Choice -> ";
       cin>>choice;
       system("CLS");
       switch(choice){
        case 0: system("CLS"); break;
        case 1: hotel1->roomNum = RMNO[0];
                hotel1->description = RMDESC[0];
                hotel1->type = RMTYPE[0];
                hotel1->price = PRICE[0];
                hotel1->status = BOOKST[0];
                hotel1->next = hotel2;

                hotel2->roomNum = RMNO[1];
                hotel2->description = RMDESC[1];
                hotel2->type = RMTYPE[1];
                hotel2->price = PRICE[1];
                hotel2->status = BOOKST[0];
                hotel2->next = hotel3;

                hotel3->roomNum = RMNO[2];
                hotel3->description = RMDESC[2];
                hotel3->type = RMTYPE[2];
                hotel3->price = PRICE[2];
                hotel3->status = BOOKST[0];
                hotel3->next = hotel4;

                hotel4->roomNum = RMNO[3];
                hotel4->description = RMDESC[3];
                hotel4->type = RMTYPE[3];
                hotel4->price = PRICE[3];
                hotel4->status = BOOKST[0];
                hotel4->next = hotel5;

                hotel5->roomNum = RMNO[4];
                hotel5->description = RMDESC[4];
                hotel5->type = RMTYPE[4];
                hotel5->price = PRICE[4];
                hotel5->status = BOOKST[0];
                hotel5->next = NULL;

            do{
                    //counter para sa case 3 & 4(singly)
                    //ginamit to para sa mga error (ex. no occupied room)
                    int case1_cntr_1 = -1;
                    int case1_cntr_2 = -1;

                    //counter sa mga pag output
                    hotelAndTourism * counter = hotel1;
                    hotelAndTourism * counterForVacant = hotel1;

                    cout<<"===== Singly Linked List ====="<<endl<<endl;
                    cout<<"[1] Rooms"<<endl;
                    cout<<"[2] Available Rooms"<<endl;
                    cout<<"[3] Update Rooms Availability"<<endl;
                    cout<<"[4] Book Room"<<endl;
                    cout<<"[0] Back to Main Menu"<<endl;
                    cout<<"Enter your Choice -> ";
                    cin>>answer;
                    system("CLS");
                    switch(answer){
                        case 0: system("CLS"); break;
                        case 1: cout<<"Rooms in Our Hotel"<<endl<<endl;
                                while(counter){
                                    cout<<"ROOM ID NO.  : "<<counter->roomNum<<endl;
                                    cout<<"DESCRIPTION  : "<<counter->description<<endl;
                                    cout<<"ROOM TYPE    : "<<counter->type<<endl;
                                    cout<<"PRICE        : "<<counter->price<<endl;
                                    cout<<"BOOK STATUS  : "<<counter->status<<endl<<endl;
                                    cout<<line<<endl<<endl;
                                    counter = counter->next;
                                    }
                                    break;
                        case 2: cout<<"Available Rooms"<<endl<<endl;
                                while(counter){
                                        if(counter->status == BOOKST[0]){
                                            cout<<"ROOM ID NO.  : "<<counter->roomNum<<endl;
                                            cout<<"DESCRIPTION  : "<<counter->description<<endl;
                                            cout<<"ROOM TYPE    : "<<counter->type<<endl;
                                            cout<<"PRICE        : "<<counter->price<<endl;
                                            cout<<"BOOK STATUS  : "<<counter->status<<endl<<endl;
                                            cout<<line<<endl<<endl;
                                            counter = counter->next;
                                            }
                                            else counter = counter->next;
                                            }
                                    break;

                        case 3: cout<<"These are the Occupied Rooms: "<<endl<<endl;
                                while(counter){
                                        if(counter->status == BOOKST[1]){
                                            cout<<"ROOM ID NO.  : "<<counter->roomNum<<endl;
                                            cout<<"DESCRIPTION  : "<<counter->description<<endl;
                                            cout<<"ROOM TYPE    : "<<counter->type<<endl;
                                            cout<<"PRICE        : "<<counter->price<<endl;
                                            cout<<"BOOK STATUS  : "<<counter->status<<endl<<endl;
                                            cout<<line<<endl<<endl;
                                            counter = counter->next;
                                            case1_cntr_1 = 0;
                                            }
                                        else {
                                            case1_cntr_1 == -1;
                                            counter = counter->next;
                                        }
                                        }

                                            if(case1_cntr_1 == -1) {
                                                cout<<"No Occupied Room!"<<endl<<endl;
                                                break;}
                                            else {
                                                cout<<"Enter 0 to Back"<<endl;
                                                cout<<"Enter your Room ID to change the Availability: ";
                                                cin>>avail;
                                                system("CLS");

                                                while(counterForVacant){
                                                    if(avail == "0"){
                                                        case1_cntr_2 = 0;
                                                        break;
                                                    }
                                                    else if(counterForVacant->roomNum == avail){
                                                        counterForVacant->status = BOOKST[0];
                                                        cout<<"Room Id: "<<avail<<" is now Vacant!"<<endl<<endl;
                                                        case1_cntr_2 = 0;
                                                        break;
                                                    }
                                                    else {
                                                        case1_cntr_2 == -1;
                                                        counterForVacant = counterForVacant->next;
                                                        }
                                                }
                                                if(case1_cntr_2 == -1) cout<<"Our hotel does not have Room ID: "<<avail<<endl<<endl;}

                             break;
                        case 4: cout<<"Enter Room Id you want to book: ";
                                cin>>avail;
                                system("CLS");
                                while(counter){
                                    if(counter->roomNum == avail){
                                        if(counter->status == BOOKST[1]){
                                            cout<<"This Room is already Occupied"<<endl<<endl;
                                            case1_cntr_1 = 0;
                                            break;
                                        }
                                        else{
                                        counter->status = BOOKST[1];
                                        cout<<"Booking Success!"<<endl<<endl;
                                        case1_cntr_1 = 0;
                                        break;}
                                    }
                                    else {
                                        case1_cntr_1 = -1;
                                        counter = counter->next;
                                         }
                                }
                                if(case1_cntr_1 == -1) cout<<"Our hotel does not have Room ID: "<<avail<<endl<<endl;

                            break;

                    default: cout<<"Invalid Choice Selected"<<endl<<endl;
                    }
                }while(answer!=0);
               break;
       case 2:  hotel1->roomNum = RMNO[0];
                hotel1->description = RMDESC[0];
                hotel1->type = RMTYPE[0];
                hotel1->price = PRICE[0];
                hotel1->status = BOOKST[0];
                hotel1->prev = NULL;
                hotel1->next = hotel2;

                hotel2->roomNum = RMNO[1];
                hotel2->description = RMDESC[1];
                hotel2->type = RMTYPE[1];
                hotel2->price = PRICE[1];
                hotel2->status = BOOKST[0];
                hotel2->prev = hotel1;
                hotel2->next = hotel3;

                hotel3->roomNum = RMNO[2];
                hotel3->description = RMDESC[2];
                hotel3->type = RMTYPE[2];
                hotel3->price = PRICE[2];
                hotel3->status = BOOKST[0];
                hotel3->prev = hotel2;
                hotel3->next = hotel4;

                hotel4->roomNum = RMNO[3];
                hotel4->description = RMDESC[3];
                hotel4->type = RMTYPE[3];
                hotel4->price = PRICE[3];
                hotel4->status = BOOKST[0];
                hotel4->prev = hotel3;
                hotel4->next = hotel5;

                hotel5->roomNum = RMNO[4];
                hotel5->description = RMDESC[4];
                hotel5->type = RMTYPE[4];
                hotel5->price = PRICE[4];
                hotel5->status = BOOKST[0];
                hotel5->prev = hotel4;
                hotel5->next = NULL;


             do{
                    //counter para sa case 3&4(doubly)
                     //ginamit to para sa mga error (ex. no occupied room)
                    int case2_cntr_1 = -1;
                    int case2_cntr_2 = -1;

                    //counter sa mga pag output
                    hotelAndTourism * counter = hotel1;
                    hotelAndTourism * counterForVacant = hotel1;

                    cout<<"===== Doubly Linked List ====="<<endl<<endl;
                    cout<<"[1] Rooms"<<endl;
                    cout<<"[2] Available Rooms"<<endl;
                    cout<<"[3] Update Rooms Availability"<<endl;
                    cout<<"[4] Book Room"<<endl;
                    cout<<"[0] Back to Main Menu"<<endl;
                    cout<<"Enter your Choice -> ";
                    cin>>answer;
                    system("CLS");
                    switch(answer){
                        case 0: system("CLS"); break;
                        case 1: cout<<"Rooms in Our Hotel"<<endl<<endl;
                                while(counter){
                                    cout<<"ROOM ID NO.  : "<<counter->roomNum<<endl;
                                    cout<<"DESCRIPTION  : "<<counter->description<<endl;
                                    cout<<"ROOM TYPE    : "<<counter->type<<endl;
                                    cout<<"PRICE        : "<<counter->price<<endl;
                                    cout<<"BOOK STATUS  : "<<counter->status<<endl<<endl;
                                    cout<<line<<endl<<endl;
                                    counter = counter->next;
                                    }
                                    break;
                        case 2: cout<<"Available Rooms"<<endl<<endl;
                                while(counter){
                                        if(counter->status == BOOKST[0]){
                                            cout<<"ROOM ID NO.  : "<<counter->roomNum<<endl;
                                            cout<<"DESCRIPTION  : "<<counter->description<<endl;
                                            cout<<"ROOM TYPE    : "<<counter->type<<endl;
                                            cout<<"PRICE        : "<<counter->price<<endl;
                                            cout<<"BOOK STATUS  : "<<counter->status<<endl<<endl;
                                            cout<<line<<endl<<endl;
                                            counter = counter->next;
                                            }
                                            else counter = counter->next;
                                            }
                                    break;

                        case 3: cout<<"These are the Occupied Rooms: "<<endl<<endl;
                                while(counter){
                                        if(counter->status == BOOKST[1]){
                                            cout<<"ROOM ID NO.  : "<<counter->roomNum<<endl;
                                            cout<<"DESCRIPTION  : "<<counter->description<<endl;
                                            cout<<"ROOM TYPE    : "<<counter->type<<endl;
                                            cout<<"PRICE        : "<<counter->price<<endl;
                                            cout<<"BOOK STATUS  : "<<counter->status<<endl<<endl;
                                            cout<<line<<endl<<endl;
                                            counter = counter->next;
                                            case2_cntr_1 = 0;
                                            }
                                        else {
                                            case2_cntr_1 == -1;
                                            counter = counter->next;
                                        }
                                        }

                                            if(case2_cntr_1 == -1) {
                                                cout<<"No Occupied Room!"<<endl<<endl;
                                                break;}
                                            else {
                                                cout<<"Enter 0 to Back"<<endl;
                                                cout<<"Enter your Room ID to change the Availability: ";
                                                cin>>avail;
                                                system("CLS");

                                                while(counterForVacant){
                                                    if(avail == "0"){
                                                        case2_cntr_2 = 0;
                                                        break;
                                                    }
                                                    else if(counterForVacant->roomNum == avail){
                                                        counterForVacant->status = BOOKST[0];
                                                        cout<<"Room Id: "<<avail<<" is now Vacant!"<<endl<<endl;
                                                        case2_cntr_2 = 0;
                                                        break;
                                                    }
                                                    else {
                                                        case2_cntr_2 == -1;
                                                        counterForVacant = counterForVacant->next;
                                                        }
                                                }
                                                if(case2_cntr_2 == -1) cout<<"Our hotel does not have Room ID: "<<avail<<endl<<endl;}

                             break;
                        case 4: cout<<"Enter Room Id you want to book: ";
                                cin>>avail;
                                system("CLS");
                                while(counter){
                                    if(counter->roomNum == avail){
                                        if(counter->status == BOOKST[1]){
                                            cout<<"This Room is already Occupied"<<endl<<endl;
                                            case2_cntr_1 = 0;
                                            break;
                                        }
                                        else{
                                        counter->status = BOOKST[1];
                                        cout<<"Booking Success!"<<endl<<endl;
                                        case2_cntr_1 = 0;
                                        break;}
                                    }
                                    else {
                                        case2_cntr_1 = -1;
                                        counter = counter->next;
                                         }
                                }
                                if(case2_cntr_1 == -1) cout<<"Our hotel does not have Room ID: "<<avail<<endl<<endl;

                            break;

                    default: cout<<"Invalid Choice Selected"<<endl<<endl;
                    }
                }while(answer!=0);
               break;
       case 3:  hotel1->roomNum = RMNO[0];
                hotel1->description = RMDESC[0];
                hotel1->type = RMTYPE[0];
                hotel1->price = PRICE[0];
                hotel1->status = BOOKST[0];
                hotel1->next = hotel2;

                hotel2->roomNum = RMNO[1];
                hotel2->description = RMDESC[1];
                hotel2->type = RMTYPE[1];
                hotel2->price = PRICE[1];
                hotel2->status = BOOKST[0];
                hotel2->next = hotel3;

                hotel3->roomNum = RMNO[2];
                hotel3->description = RMDESC[2];
                hotel3->type = RMTYPE[2];
                hotel3->price = PRICE[2];
                hotel3->status = BOOKST[0];
                hotel3->next = hotel4;

                hotel4->roomNum = RMNO[3];
                hotel4->description = RMDESC[3];
                hotel4->type = RMTYPE[3];
                hotel4->price = PRICE[3];
                hotel4->status = BOOKST[0];
                hotel4->next = hotel5;

                hotel5->roomNum = RMNO[4];
                hotel5->description = RMDESC[4];
                hotel5->type = RMTYPE[4];
                hotel5->price = PRICE[4];
                hotel5->status = BOOKST[0];
                hotel5->next = hotel1;

            do{
                    //counter para sa case 3&4(circular)
                    //ginamit to para sa mga error (ex. no occupied room)
                    int case3_cntr_1 = -1;
                    int case3_cntr_2 = -1;
                    //para to sa pampigil ng loop kasi circular sya
                    int circularCntr = 0;
                    //para to sa case 3 update availability kasi kapag yung circularCntr ginamit di na sya magloloop, 5 na agad value nya
                    int circularCntr2 = 0;

                    //counter sa mga pag output
                    hotelAndTourism * counter = hotel1;
                    hotelAndTourism * counterForVacant = hotel1;

                    cout<<"===== Circular Linked List ====="<<endl<<endl;
                    cout<<"[1] Rooms"<<endl;
                    cout<<"[2] Available Rooms"<<endl;
                    cout<<"[3] Update Rooms Availability"<<endl;
                    cout<<"[4] Book Room"<<endl;
                    cout<<"[0] Back to Main Menu"<<endl;
                    cout<<"Enter your Choice -> ";
                    cin>>answer;
                    system("CLS");
                    switch(answer){
                        case 0: system("CLS"); break;
                        case 1: cout<<"Rooms in Our Hotel"<<endl<<endl;
                                while(circularCntr<5){
                                    cout<<"ROOM ID NO.  : "<<counter->roomNum<<endl;
                                    cout<<"DESCRIPTION  : "<<counter->description<<endl;
                                    cout<<"ROOM TYPE    : "<<counter->type<<endl;
                                    cout<<"PRICE        : "<<counter->price<<endl;
                                    cout<<"BOOK STATUS  : "<<counter->status<<endl<<endl;
                                    cout<<line<<endl<<endl;
                                    circularCntr++;
                                    counter = counter->next;
                                    }
                                    break;
                        case 2: cout<<"Available Rooms"<<endl<<endl;
                                while(circularCntr<5){
                                        if(counter->status == BOOKST[0]){
                                            cout<<"ROOM ID NO.  : "<<counter->roomNum<<endl;
                                            cout<<"DESCRIPTION  : "<<counter->description<<endl;
                                            cout<<"ROOM TYPE    : "<<counter->type<<endl;
                                            cout<<"PRICE        : "<<counter->price<<endl;
                                            cout<<"BOOK STATUS  : "<<counter->status<<endl<<endl;
                                            cout<<line<<endl<<endl;
                                            circularCntr++;
                                            counter = counter->next;
                                            }

                                        else {
                                            circularCntr++;
                                            counter = counter->next;
                                        }

                                            }
                                    break;

                        case 3: cout<<"These are the Occupied Rooms: "<<endl<<endl;
                                while(circularCntr<5){
                                        if(counter->status == BOOKST[1]){
                                            cout<<"ROOM ID NO.  : "<<counter->roomNum<<endl;
                                            cout<<"DESCRIPTION  : "<<counter->description<<endl;
                                            cout<<"ROOM TYPE    : "<<counter->type<<endl;
                                            cout<<"PRICE        : "<<counter->price<<endl;
                                            cout<<"BOOK STATUS  : "<<counter->status<<endl<<endl;
                                            cout<<line<<endl<<endl;
                                            circularCntr++;
                                            counter = counter->next;
                                            case3_cntr_1 = 0;
                                            }
                                        else {
                                            case3_cntr_1 == -1;
                                            circularCntr++;
                                            counter = counter->next;
                                        }
                                        }

                                            if(case3_cntr_1 == -1) {
                                                cout<<"No Occupied Room!"<<endl<<endl;
                                                break;}
                                            else {
                                                cout<<"Enter 0 to Back"<<endl;
                                                cout<<"Enter your Room ID to change the Availability: ";
                                                cin>>avail;
                                                system("CLS");

                                                while(circularCntr2<5){
                                                    if(avail == "0"){
                                                        case3_cntr_2 = 0;
                                                        break;
                                                    }
                                                    else if(counterForVacant->roomNum == avail){
                                                        counterForVacant->status = BOOKST[0];
                                                        cout<<"Room Id: "<<avail<<" is now Vacant!"<<endl<<endl;
                                                        case3_cntr_2 = 0;
                                                        break;
                                                    }
                                                    else {
                                                        case3_cntr_2 == -1;
                                                        circularCntr2++;
                                                        counterForVacant = counterForVacant->next;
                                                        }
                                                }
                                                if(case3_cntr_2 == -1) cout<<"Our hotel does not have Room ID: "<<avail<<endl<<endl;}

                             break;
                        case 4: cout<<"Enter Room Id you want to book: ";
                                cin>>avail;
                                system("CLS");
                                while(circularCntr<5){
                                    if(counter->roomNum == avail){
                                        if(counter->status == BOOKST[1]){
                                            cout<<"This Room is already Occupied"<<endl<<endl;
                                            case3_cntr_1 = 0;
                                            break;
                                        }
                                        else{
                                        counter->status = BOOKST[1];
                                        cout<<"Booking Success!"<<endl<<endl;
                                        case3_cntr_1 = 0;
                                        break;}
                                    }
                                    else {
                                        case3_cntr_1 == -1;
                                        circularCntr++;
                                        counter = counter->next;
                                         }
                                }
                                if(case3_cntr_1 == -1) cout<<"Our hotel does not have Room ID: "<<avail<<endl<<endl;

                            break;

                    default: cout<<"Invalid Choice Selected"<<endl<<endl;
                    }
                }while(answer!=0);
                break;
       default: cout<<"Invalid Choice Selected"<<endl<<endl;
       }
    }while(choice!=0);
     }

void arrAndPointer(){
    int choice;
    string status[5] = {BOOKST[0],BOOKST[0],BOOKST[0],BOOKST[0],BOOKST[0]};
    //para sa display lang to sa 2d case 1
    string label[5] = {"ROOM ID NO.  : ", "DESCRIPTION  : ", "ROOM TYPE    : ", "PRICE        : ", "BOOK STATUS  : "};


    string hotelInfo[5][5] = {{RMNO[0], RMDESC[0], RMTYPE[0], PRICE[0], BOOKST[0]},
                              {RMNO[1], RMDESC[1], RMTYPE[1], PRICE[1], BOOKST[0]},
                              {RMNO[2], RMDESC[2], RMTYPE[2], PRICE[2], BOOKST[0]},
                              {RMNO[3], RMDESC[3], RMTYPE[3], PRICE[3], BOOKST[0]},
                              {RMNO[4], RMDESC[4], RMTYPE[4], PRICE[4], BOOKST[0]}
                                };
     do{
       int answer;
       cout<<"===== Array & Pointers ====="<<endl<<endl;
       cout<<"[1] Array (One Dimensional)"<<endl;
       cout<<"[2] Array (Two Dimensional)"<<endl;
       cout<<"[3] Pointers"<<endl;
       cout<<"[0] Back to Main Menu"<<endl;
       cout<<"Enter your Choice -> ";
       cin>>choice;
       system("CLS");

       switch(choice){
        case 0: break;
        case 1:   do{
                    string avail;
                    int i = 0;
                    int cntrCase3 = -1, cntrCase4 = -1, ifCntr = -1;
                    cout<<"===== One Dimensional Array ====="<<endl<<endl;
                    cout<<"[1] Rooms"<<endl;
                    cout<<"[2] Available Rooms"<<endl;
                    cout<<"[3] Update Rooms Availability"<<endl;
                    cout<<"[4] Book Room"<<endl;
                    cout<<"[0] Back to Main Menu"<<endl;
                    cout<<"Enter your Choice -> ";
                    cin>>answer;
                    system("CLS");

                    switch(answer){
                        case 0: system("CLS"); break;
                        case 1: cout<<"Rooms in our Hotel"<<endl<<endl;
                                for(int i = 0; i<5; i++){
                                    cout<<"ROOM ID NO.  : "<<RMNO[i]<<endl;
                                    cout<<"DESCRIPTION  : "<<RMDESC[i]<<endl;
                                    cout<<"ROOM TYPE    : "<<RMTYPE[i]<<endl;
                                    cout<<"PRICE        : "<<PRICE[i]<<endl;
                                    cout<<"BOOK STATUS  : "<<status[i]<<endl<<endl;
                                    cout<<line<<endl<<endl;
                                }
                                break;
                        case 2: cout<<"Available Rooms"<<endl<<endl;
                                for(int i = 0; i<5; i++){
                                    if(status[i] == BOOKST[0]){
                                        cout<<"ROOM ID NO.  : "<<RMNO[i]<<endl;
                                        cout<<"DESCRIPTION  : "<<RMDESC[i]<<endl;
                                        cout<<"ROOM TYPE    : "<<RMTYPE[i]<<endl;
                                        cout<<"PRICE        : "<<PRICE[i]<<endl;
                                        cout<<"BOOK STATUS  : "<<status[i]<<endl<<endl;
                                        cout<<line<<endl<<endl;
                                    }
                                }

                                break;
                        case 3: cout<<"These are the Occupied Rooms: "<<endl<<endl;

                                while(i<5){
                                if(status[i] == BOOKST[1]){
                                    cout<<"ROOM ID NO.  : "<<RMNO[i]<<endl;
                                    cout<<"DESCRIPTION  : "<<RMDESC[i]<<endl;
                                    cout<<"ROOM TYPE    : "<<RMTYPE[i]<<endl;
                                    cout<<"PRICE        : "<<PRICE[i]<<endl;
                                    cout<<"BOOK STATUS  : "<<status[i]<<endl<<endl;
                                    cout<<line<<endl<<endl;
                                    cntrCase3 = 0;}
                                i++;
                                }
                                if(cntrCase3 == -1){
                                    cout<<"No Occupied Rooms"<<endl<<endl;

                                    break;}

                                else {
                                     cout<<"Enter 0 to Back"<<endl;
                                     cout<<"Enter your Room ID to change the Availability: ";
                                     cin>>avail;
                                     system("CLS");

                                     //para sa exit
                                     if(avail == "0"){
                                        break;}
                                    else{
                                     for(int i = 0; i<5; i++){
                                        if(RMNO[i] == avail && status[i] == BOOKST[1]){
                                            ifCntr = 0;
                                            cout<<"Room Id: "<<avail<<" is now Vacant!"<<endl<<endl;
                                            switch(i){
                                                case 0: status[0] = BOOKST[0]; break;
                                                case 1: status[1] = BOOKST[0]; break;
                                                case 2: status[2] = BOOKST[0]; break;
                                                case 3: status[3] = BOOKST[0]; break;
                                                case 4: status[4] = BOOKST[0]; break;
                                            }
                                        }

                                     }
                                        if(ifCntr == -1) {
                                            cout<<"Our hotel does not have Room ID: "<<avail<<endl<<endl;
                                            break;}

                                 break;   }
                                }

                             break;
                        case 4: cout<<"Enter Room Id you want to book: ";
                                cin>>avail;
                                system("CLS");
                                for(int i = 0; i<5; i++){
                                    if(status[i] == BOOKST[1] && RMNO[i] == avail){
                                        cout<<"This Room is already Occupied"<<endl<<endl;
                                        cntrCase4 = 0;
                                        break;
                                        }
                                    if(RMNO[i] == avail){
                                        cout<<"Booking Success"<<endl<<endl;
                                        cntrCase4 = 0;
                                        switch(i){
                                            case 0: status[0] = BOOKST[1]; break;
                                            case 1: status[1] = BOOKST[1]; break;
                                            case 2: status[2] = BOOKST[1]; break;
                                            case 3: status[3] = BOOKST[1]; break;
                                            case 4: status[4] = BOOKST[1]; break;
                                            }
                                    }
                                }
                                    if(cntrCase4 == -1) cout<<"Our hotel does not have Room ID: "<<avail<<endl<<endl;

                             break;
                        default: cout<<"Invalid Choice Selected"<<endl<<endl;

                    }
                 }while(answer != 0);
                    break;

        case 2: do{
                    string avail;
                    int cntrCase3 = -1, cntrCase4 = -1, ifCntr = -1;
                    int checkLine, checkLine2;
                    cout<<"===== Two Dimensional Array ====="<<endl<<endl;
                    cout<<"[1] Rooms"<<endl;
                    cout<<"[2] Available Rooms"<<endl;
                    cout<<"[3] Update Rooms Availability"<<endl;
                    cout<<"[4] Book Room"<<endl;
                    cout<<"[0] Back to Main Menu"<<endl;
                    cout<<"Enter your Choice -> ";
                    cin>>answer;
                    system("CLS");

                    switch(answer){
                        case 0: system("CLS"); break;
                        case 1: cout<<"Rooms in our Hotel"<<endl<<endl;
                                for(int i = 0; i<5; i++){
                                    for(int j = 0; j<5; j++){
                                        cout<<label[j]<<hotelInfo[i][j]<<endl;
                                    }
                                    cout<<endl<<line<<endl<<endl;
                                }
                                break;
                        case 2: cout<<"Available Rooms"<<endl<<endl;
                                for(int i = 0; i<5; i++){
                                    checkLine = 0; // para lang to sa line design
                                    for(int j = 0; j<5; j++){
                                        if(hotelInfo[i][4] == BOOKST[0] ){
                                            cout<<label[j]<<hotelInfo[i][j]<<endl;
                                            checkLine = 1;
                                            }
                                        }
                                        if(checkLine == 1)cout<<line<<endl<<endl;
                                    }
                                break;
                        case 3: cout<<"These are the Occupied Rooms: "<<endl<<endl;
                               for(int i = 0; i<5; i++){
                                    checkLine2 = 0; // para lang to sa line design
                                    for(int j = 0; j<5; j++){
                                        if(hotelInfo[i][4] == BOOKST[1] ){
                                            cout<<label[j]<<hotelInfo[i][j]<<endl;
                                             cntrCase3 = 0;
                                             checkLine2 = 1;
                                            }
                                        }
                                          if(checkLine2 == 1)cout<<line<<endl<<endl;
                                }
                                if(cntrCase3 == -1){
                                    cout<<"No Occupied Rooms"<<endl<<endl;
                                    break;}
                                else {
                                     cout<<"Enter 0 to Back"<<endl;
                                     cout<<"Enter your Room ID to change the Availability: ";
                                     cin>>avail;
                                     system("CLS");

                                     //para sa exit
                                     if(avail == "0"){
                                        break;}
                                    else
                                        for(int i = 0; i<5; i++){
                                            if(hotelInfo[i][0] == avail && hotelInfo[i][4] == BOOKST[1] ){
                                                ifCntr = 0;
                                                cout<<"Room Id: "<<avail<<" is now Vacant!"<<endl<<endl;
                                                    switch(i){
                                                        case 0: hotelInfo[0][4] = BOOKST[0]; break;
                                                        case 1: hotelInfo[1][4] = BOOKST[0]; break;
                                                        case 2: hotelInfo[2][4] = BOOKST[0]; break;
                                                        case 3: hotelInfo[3][4] = BOOKST[0]; break;
                                                        case 4: hotelInfo[4][4] = BOOKST[0]; break;}
                                                    }

                                            }
                                                if(ifCntr == -1) {
                                                    cout<<"Our hotel does not have Room ID: "<<avail<<endl<<endl;
                                                    break;}

                                         break;   }

                                break;
                        case 4: cout<<"Enter Room Id you want to book: ";
                                cin>>avail;
                                system("CLS");
                                for(int i = 0; i<5; i++){
                                    if(hotelInfo[i][0] == avail && hotelInfo[i][4] == BOOKST[1]){
                                        cout<<"This Room is already Occupied"<<endl<<endl;
                                        cntrCase4 = 0;
                                        break;
                                        }
                                    if(hotelInfo[i][0] == avail){
                                        cout<<"Booking Success"<<endl<<endl;
                                        cntrCase4 = 0;
                                        switch(i){
                                            case 0: hotelInfo[0][4] = BOOKST[1]; break;
                                            case 1: hotelInfo[1][4] = BOOKST[1]; break;
                                            case 2: hotelInfo[2][4] = BOOKST[1]; break;
                                            case 3: hotelInfo[3][4] = BOOKST[1]; break;
                                            case 4: hotelInfo[4][4] = BOOKST[1]; break;}
                                    }
                                }
                                    if(cntrCase4 == -1) cout<<"Our hotel does not have Room ID: "<<avail<<endl<<endl;

                             break;
                        default: cout<<"Invalid Choice Selected"<<endl<<endl;

                    }
                 }while(answer != 0);

                break;
        case 3: do{
                cout<<"===== Pointers ====="<<endl<<endl;
                cout<<"[1] Address of Room No. in Memory"<<endl;
                cout<<"[2] Address of Room Description in Memory"<<endl;
                cout<<"[3] Address of Room Type in Memory"<<endl;
                cout<<"[4] Address of Room Price in Memory"<<endl;
                cout<<"[5] Address of Room Book Status in Memory"<<endl;
                cout<<"[0] Back to Main Menu"<<endl;
                cout<<"Enter your Choice -> ";
                cin>>answer;
                system("CLS");

                switch(answer){
                    case 0: break;
                    case 1: cout<<"Room No. Address: "<<&RMNO<<endl<<endl;    break;
                    case 2: cout<<"Room Description Address: "<<&RMDESC<<endl<<endl;   break;
                    case 3: cout<<"Room Type Address: "<<&RMTYPE<<endl<<endl;   break;
                    case 4: cout<<"Room Price Address: "<<&PRICE<<endl<<endl;     break;
                    case 5: cout<<"Room Book Status Address: "<<&BOOKST<<endl<<endl;     break;
                    default: cout<<"Invalid Choice Selected"<<endl<<endl;


                }

                }while(answer != 0);

                break;
                default: cout<<"Invalid Choice Selected"<<endl<<endl;
       }
     }while(choice != 0);


}

void queueDataStruc(){
    int choice;
    int RMNO[5] = {101,201,301, 401, 501};
    //for stl
    queue<string> roomID;
    queue<string> roomType;
    queue<string> roomPrice;
    int choiceSTL;
    string id,type,price;
    do{

       int roomNo;
       string i="";
       Queue j1;
       Hotel* stud;
       string rate;
       string roomid;
       cout<<"===== Queue ====="<<endl<<endl;
       cout<<"[1] Queue using Array"<<endl;
       cout<<"[2] Queue using Linked list"<<endl;
       cout<<"[3] Queue in C++ STL"<<endl;
       cout<<"[0] Back to Main Menu"<<endl;
       cout<<"Enter your Choice -> ";
       cin>>choice;
       system("CLS");

       switch(choice){
        case 0: break;
        case 1:  do{
                cout<<" "<<endl;
                cout<<"Select what do you want to do."<<endl;
                cout<<"[1] Room Description "<<endl;
                cout<<"[2] Make a Rate "<<endl;
                cout<<"[3] Remove Rate "<<endl;
                cout<<"[4] Display Rate "<<endl;
                cout<<"[0] Back to Main Menu"<<endl;
                cin>>choice;
                system("CLS");
                switch(choice)
                {
                case 0: break;
                case 1: j1.rcategory(); break;
                case 2: cout<<"Enter your Rate: "<<endl;
                        cout<<"Please choose if it is: "<<endl;
                        cout<<"[Bad]  [Fair]  [Excellent]: ";
                        cin>>rate;
                        cout<<"Enter RoomID: ";
                        cin>>roomid;
                        j1.insert(rate);
                        break;
                case 3: cout<<"Remove Rate: "<<j1.remove()<<endl;
                        cout<<"\n";
                        break;
                case 4: j1.display();
                        break;
                default: cout<<"Invalid Choice";
                         break;

                }

            }while(choice!=0);
                    break;
        case 2:do{
                    cout<<"Enter what you want to do:"<<endl;
                    cout<<"[1] Room Details"<<endl;
                    cout<<"[2] Insert Rate"<<endl;
                    cout<<"[3] Remove Rate"<<endl;
                    cout<<"[4] Display Rate"<<endl;
                    cout<<"[0] Back to Main Menu"<<endl;
                    cout<<"Enter your Choice -> ";
                    cin>>choice;
                    system("CLS");
                    switch(choice){
                        case 0:  break;
                        case 1: rcategory(); break;
                        case 2: input(); break;
                        case 3: remove(); break;
                        case 4: display(); break;
                        system("CLS");
                        default: cout<<"Enter valid number"<<endl<<endl;
                    }
                }while(choice != 0);
            break;
        case 3: do{
                    cout<<"===== Queue using STL ====="<<endl;
                    cout<<"\n[1] Insert Data";
                    cout<<"\n[2] Delete Data";
                    cout<<"\n[3] Display and Delete Data";
                    cout<<"\n[0] Back to Main Menu\n";
                    cout<<"Your Choice ==> " ;
                    cin >> choiceSTL;
                    system("CLS");
                    switch(choiceSTL){
                        case 0: break;
                        case 1: cout<<"Enter Room roomID: ";
                                cin>>id;
                                roomID.push(id);
                                cout<<"Enter Room Type: ";
                                cin>>type;
                                roomType.push(type);
                                cout<<"Enter Room Price: ";
                                cin>>price;
                                roomPrice.push(price);
                                system("CLS");
                                cout<<"Inserting Success!"<<endl<<endl;
                        break;
                        case 2: if(roomID.empty()) cout<<"Stack is Empty"<<endl<<endl;
                                else{
                                    roomID.pop();
                                    roomType.pop();
                                    roomPrice.pop();
                                    cout<<"Deleting Success!"<<endl<<endl;
                                }
                                break;
                        case 3: if(roomID.empty()) cout<<"Stack is Empty"<<endl<<endl;
                                else{
                                    cout<<"===== Data List ====="<<endl<<endl;
                                while(!roomID.empty()){
                                    cout<<"Room ID   : "<<roomID.front()<<endl;
                                    cout<<"Room Type : "<<roomType.front()<<endl;
                                    cout<<"Room Price: "<<roomPrice.front()<<endl<<endl;

                                    roomID.pop();
                                    roomType.pop();
                                    roomPrice.pop();
                                }
                            }


                        break;
                        default:cout<<"Invalid Choice"<<endl<<endl;
                    }

                }while(choiceSTL != 0);
        break;
     default: cout<<"Invalid Choice";


       }
     }while(choice != 0);

}


int main()
{
    int answer;
    string userID[] = {" ", " "};
    string password[] = {" ", " "};
    string forgot;
    int account;
    do{
        cout<<"-------------------- Hotel and Tourism Category --------------------"<<endl<<endl;
        cout<<"1. Log in"<<endl;
        cout<<"2. Register"<<endl;
        cout<<"3. Forgot Password"<<endl;
        cout<<"0. Exit"<<endl<<endl;
        cout<<"--------------------------------------------------------------------"<<endl;
        cout<<"Enter your Choice -> ";
        cin>>account;
        system("CLS");
        switch(account){
            case 0: system("CLS");
                    cout<<"Thank You!";
                    break;
            case 1: cout<<"Enter User ID: ";
                    cin>>userID[1];
                    cout<<"Enter Password: ";
                    cin>>password[1];
                    system("CLS");
                    if(userID[0] == userID[1] && password[0] == password[1]){
                        cout<<"Login Success!"<<endl<<endl;
                          do{
                                cout<<"Hotel and Tourism Category"<<endl<<endl;
                                cout<<"Rooms Data"<<endl;
                                cout<<"[0] Exit"<<endl;
                                cout<<"[1] Array & Pointers"<<endl;
                                cout<<"[2] Linked Lists"<<endl;
                                cout<<"[3] Stack Data Structure"<<endl;
                                cout<<"[4] Queue Data Structure"<<endl;
                                cout<<"[5] Search & Sorting Algorithms"<<endl;
                                cout<<"[6] Group Members"<<endl;
                                cout<<"Enter your Choice -> ";
                                cin>>answer;
                                system("CLS");
                                switch(answer){
                                    case 0: cout<<"Thank You!"; break;
                                    case 1: arrAndPointer();    break;
                                    case 2: linkedlist();       break;
                                    case 3: stackDataStructure();   break;
                                    case 4: queueDataStruc();   break;
                                    case 5: searchAndSorting(); break;
                                    case 6: groupMembers();     break;
                                    default: cout<<"Invalid Choice Selected"<<endl<<endl;
                                    }
                                }while(answer != 0);
                    }
                    else cout<<"User ID or Password is Incorrect, try again!"<<endl<<endl;


                    break;
            case 2: cout<<"Create User ID: ";
                    cin>>userID[0];
                    cout<<"Create Password: ";
                    cin>>password[0];
                    system("CLS");
                    cout<<"Account Successfully Created!"<<endl<<endl;
                    break;
            case 3: cout<<"Enter your User ID: ";
                    cin>>forgot;
                    if(userID[0] == forgot){
                        cout<<"Enter New Password: ";
                        cin>>password[0];
                        system("CLS");
                        cout<<"Success, Your Password has been Updated!"<<endl<<endl;
                    }
                    else {
                        system("CLS");
                        cout<<"User ID not Found"<<endl<<endl;}
                    break;
            default: cout<<"Invalid Choice"<<endl<<endl;
        }

    }while(account != 0);



    system("pause>0");
    return 0;
}
