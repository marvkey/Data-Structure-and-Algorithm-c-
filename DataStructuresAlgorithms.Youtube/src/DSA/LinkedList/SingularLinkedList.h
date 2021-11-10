#pragma once
#include<iostream>
class Node {
public:
    int Key;
    int Data;
    Node* Next;
    
    Node()
    : Key(0), Data(0), Next(nullptr)
    {
    }

    Node(int K, int D)
        :Key(K), Data(D)
    {}
};

class SinglyLinkedList {
public:
    Node* Head;
    SinglyLinkedList()
        :Head(nullptr)
    {}
    SinglyLinkedList(Node* N)
        : Head(N)
    {}

    Node* NodeExist(int K) { // checks if a node already exist in the list
        Node* Temp = nullptr;
        Node* Ptr = this->Head;
        while (Ptr != nullptr) { //indicates the list is not empty
            if (Ptr->Key == K) {
                Temp = Ptr; 
                break;
            }
            else
                Ptr = Ptr->Next;
        }
        return Temp;
    }

    void AppendNode(Node* N) {
        if (NodeExist(N->Key) != nullptr) {
            std::cout << "Node already Exist" << std::endl;
        }
        else {
            if (Head == nullptr) {
                Head = N;
                std::cout << "Node Appended" <<std::endl;
            }
            else {
                Node* Ptr = Head;
                while (Ptr->Next != nullptr) //Goes until it gets till the  last node of the linked list
                    Ptr = Ptr->Next;
                Ptr->Next = N;
                std::cout << "Node Appended" << std::endl;
            }
        }
    }

    void PrependNode(Node* N) { // make it the Head
       if(NodeExist(N->Key) != nullptr)
           std::cout<<"Node already exist with the Key value :"<<N->Key<<". Append another node with differetn key value"<<std::endl;
       else {
           N->Next = Head; // stores value of the first Node
           Head = N;
           std::cout << "Node Prepended" << std::endl;
       }
    }

    void InsertNodeAfter(int k, Node* N) {
        Node* Ptr = NodeExist(k);
        if (Ptr == nullptr)
            std::cout << "no node exist with the key value: " << k << std::endl;
        else {
            if(NodeExist(N->Key) != nullptr)
                std::cout << "Node already exist with the Key value :" << N->Key << ". Append another node with differetn key value" << std::endl;
            else {
                N->Next = Ptr->Next;
                Ptr->Next = N;
                std::cout << "Node Inserted" << std::endl;
            }
        }
    }

    void DeleteNodeByKey(int K) {// al we are doing is unliking it from memory
        if (Head == nullptr)// means linked list is empty
            std::cout << "linked list empty. cant not be delteed" << std::endl;
        else if (Head != nullptr) {
            if (Head->Key == K) {
                Head = Head->Next;
                std::cout << "UNlinked the keys the head node now has a value of" << Head->Key;
            }
            else {
                Node* Temp = nullptr;
                Node* PrevPtr = Head; 
                Node* CurrentPtr = Head->Next; 
                while (CurrentPtr != nullptr) { // keep looping through the linked list
                    if (CurrentPtr->Key == K) {// we have reached the Node with the same key value as passed in paremter
                        Temp = CurrentPtr;// passing temp as the current ptr so that we know have the value of our current pointer
                        CurrentPtr == nullptr; // we have a match so know we can break out of the while loop
                    }
                    else {// moving to next node
                        PrevPtr = PrevPtr->Next;
                        CurrentPtr = CurrentPtr->Next;
                    }
                }
                if (Temp != nullptr) {
                    PrevPtr->Next= Temp->Next;
                    std::cout << "Node Unliked with Key values : " << K << std::endl;
                }
                else {
                    std::cout << "Node does not exist with the key value: " << K << std::endl;
                }
            }
        }
            
    }

    void UpdateNodeByKey(int K, int d) {
        Node* Ptr = NodeExist(K);
        if (Ptr != nullptr) {
            Ptr->Data = d;
            std::cout << "node Data update succesfully"<<std::endl;
        }
        else{
            std::cout << "Node does not Exist with Key Value : " << std::endl;
        }
    }

    void PrintList() {
        if(Head == nullptr)
            std::cout << std::endl << "NO Nodes in Single Linked List: ";
        else {
            std::cout << std::endl << "single Linkeed List Values : ";
            Node* Temp = Head;
            while (Temp != nullptr) {

                std::cout << "(" << Temp->Key << "," << Temp->Data << ") -->";
                Temp = Temp->Next;
            }
        }
    }

    static void Main() {
        SinglyLinkedList s; int Option, Key1, K1, Data1;

        do {
            std::cout << "what operation do you want to perorm 0 to exit" << std::endl;
            std::cout << "1. appednNode()" << std::endl;
            std::cout << "2. prependNode()" << std::endl;
            std::cout << "3. InsertNodeAfter()" << std::endl;
            std::cout << "4. DeleteNodeByKey()" << std::endl;
            std::cout << "5. UpdateNOdeByKey()" << std::endl;
            std::cout << "6. PrintLIst()" << std::endl;
            std::cout << "7. clear Screen()" << std::endl;
            cin >> Option;
            Node* n1 = new Node();
            switch (Option) {
            case 0:
                break;
            case 1:
                std::cout << "Append NOde operation \n Enter key & data of the NOde to be Appended" << std::endl;
                cin >> Key1;
                cin >> Data1;
                n1->Key = Key1;
                n1->Data = Data1;
                s.AppendNode(n1);
                break;
            case 2:
                std::cout << "Prependd NOde operation \n Enter key & data of the NOde to be Prepend" << std::endl;
                cin >> Key1;
                cin >> Data1;
                n1->Key = Key1;
                n1->Data = Data1;
                s.PrependNode(n1);
                break;
            case 3:
                cout << "Insert NOde Afte Operation \n Enter key of existin NOde" << std::endl;
                cin >> K1;
                std::cout << "Enter Key & Data of the New Node first : " << std::endl;
                cin >> Key1;
                cin >> Data1;
                n1->Key = Key1;
                n1->Data = Data1;
                s.InsertNodeAfter(K1, n1);
                break;
            case 4:
                std::cout << "delte node by operation \n Enter Key of hte Nodde to be delted: " << std::endl;
                cin >> K1;
                s.DeleteNodeByKey(K1);
                break;
            case 5:
                std::cout << "Update Node By Key Operation - \n Enter Key & New Data to be Updated" << std::endl;
                cin >> Key1;
                cin >> Data1;
                s.UpdateNodeByKey(Key1, Data1);
                break;
            case 6:
                s.PrintList();
                break;
            case 7:
                system("cls");
                break;
            default:
                std::cout << "Enter proper Option NUmber " << std::endl;
            }

        } while (Option != 0);
    }
};