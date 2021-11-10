#pragma once
#include<iostream>

using namespace std;

class CircularNode {
public:
    int key;
    int data;
    CircularNode * next;

    CircularNode() {
        key = 0;
        data = 0;
        next = NULL;
    }
    CircularNode(int k,int d) {
        key = k;
        data = d;
    }
};

class CircularLinkedList {
public:
   CircularNode * head;

    CircularLinkedList() {
        head = NULL;
    }

    // 1. CHeck ifCircularNode exists using key value
   CircularNode *CircularNodeExists(int k) {

       CircularNode * temp = NULL;
       CircularNode * ptr = head;

        if (ptr == NULL) {
            return temp;
        }
        else {
            do {
                if (ptr->key == k) {
                    temp = ptr;
                }
                ptr = ptr->next;

            } while (ptr != head);
            return temp;
        }

        //return temp;
    }

    // 2. Append aCircularNode to the list
    void appendCircularCircularNode(CircularNode * new_CircularNode) {
        if (CircularNodeExists(new_CircularNode->key) != NULL) {
            cout << "CircularCircularNode Already exists with key value : " <<
                new_CircularNode->key <<
                ". Append anotherCircularNode with different Key value" <<
                endl;
        }
        else {
            if (head == NULL) {
                head = new_CircularNode;
                new_CircularNode->next = head;
                cout << "CircularNode Appended at first Head position" << endl;
            }
            else {
                CircularNode * ptr = head;
                while (ptr->next != head) {
                    ptr = ptr->next;
                }
                ptr->next = new_CircularNode;
                new_CircularNode->next = head;
                cout << "CircularNode Appended" << endl;
            }
        }

    }
    // 3. Prepend CircularNode - Attach a CircularNode at the start
    void prependCircularNode(CircularNode * new_CircularNode) {
        if (CircularNodeExists(new_CircularNode->key) != NULL) {
            cout << "CircularNode Already exists with key value : " <<
                new_CircularNode->key <<
                ". Append another CircularNode with different Key value" <<
                endl;
        }
        else {
            if (head == NULL) {
                head = new_CircularNode;
                new_CircularNode->next = head;
                cout << "CircularNode Prepended at first Head position" << endl;
            }
            else {
                CircularNode * ptr = head;
                while (ptr->next != head) {
                    ptr = ptr->next;
                }

                ptr->next = new_CircularNode;
                new_CircularNode->next = head;
                head = new_CircularNode;
                cout << "CircularNode Prepended" << endl;
            }

        }
    }

    // 4. Insert a CircularNode after a particular CircularNode in the list
    void insertCircularNodeAfter(int k,CircularNode * new_CircularNode) {
        CircularNode * ptr =CircularNodeExists(k);
        if (ptr == NULL) {
            cout << "No CircularNode exists with key value OF: " << k << endl;
        }
        else {
            if (CircularNodeExists(new_CircularNode->key) != NULL) {
                cout << "CircularNode Already exists with key value : " <<
                    new_CircularNode->key <<
                    ". Append another CircularNode with different Key value" <<
                    endl;
            }
            else {
                if (ptr->next == head) {
                    new_CircularNode->next = head;
                    ptr->next = new_CircularNode;
                    cout << "CircularNode Inserted at the End" << endl;
                }
                else {
                    new_CircularNode->next = ptr->next;
                    ptr->next = new_CircularNode;
                    cout << "CircularNode Inserted in between" << endl;
                }

            }
        }
    }

    // 5. Delete CircularNode by unique key
    void deleteCircularNodeByKey(int k) {
        CircularNode * ptr =CircularNodeExists(k);
        if (ptr == NULL) {
            cout << "No CircularNode exists with key value OF : " << k <<
                endl;
        }
        else {

            if (ptr == head) {
                if (head->next == NULL) {
                    head = NULL;
                    cout << "Head CircularNode Unlinked... List Empty";
                }
                else {
                    CircularNode * ptr1 = head;
                    while (ptr1->next != head) {
                        ptr1 = ptr1->next;
                    }
                    ptr1->next = head->next;
                    head = head->next;
                    cout << "CircularNode UNLINKED with keys value : " << k << endl;
                }
            }
            else {
                CircularNode * temp = NULL;
                CircularNode * prevptr = head;
                CircularNode * currentptr = head->next;
                while (currentptr != NULL) {
                    if (currentptr->key == k) {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }

                prevptr->next = temp->next;
                cout << "CircularNode UNLINKED with keys value : " << k << endl;

            }

        }

    }
    // 6th update CircularNode
    void updateCircularNodeByKey(int k,int new_data) {

        CircularNode * ptr =CircularNodeExists(k);
        if (ptr != NULL) {
            ptr->data = new_data;
            cout << "CircularNode Data Updated Successfully" << endl;
        }
        else {
            cout << "CircularNode Doesn't exist with key value : " << k << endl;
        }

    }

    // 7th printing
    void printList() {
        if (head == NULL) {
            cout << "No CircularNodes in Circular Linked List";
        }
        else {
            cout << endl << "head address : " << head << endl;
            cout << "Circular Linked List Values : " << endl;

            CircularNode * temp = head;

            do {
                cout << "(" << temp->key << "," << temp->data << "," << temp->next << ") --> ";
                temp = temp->next;
            } while (temp != head);
        }

    }

    static int maine() {

        CircularLinkedList obj;
        int option;
        int key1,k1,data1;
        do {
            cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
            cout << "1. appendCircularNode()" << endl;
            cout << "2. prependCircularNode()" << endl;
            cout << "3. insertCircularNodeAfter()" << endl;
            cout << "4. deleteCircularNodeByKey()" << endl;
            cout << "5. updateCircularNodeByKey()" << endl;
            cout << "6. print()" << endl;
            cout << "7. Clear Screen" << endl << endl;

            cin >> option;
            CircularNode * n1 = new CircularNode();
            //CircularNode n1;

            switch (option) {
            case 0:
                break;
            case 1:
                cout << "Append CircularNode Operation \nEnter key & data of the CircularNode to be Appended" << endl;
                cin >> key1;
                cin >> data1;
                n1->key = key1;
                n1->data = data1;
                obj.appendCircularCircularNode(n1);
                //cout<<n1.key<<" = "<<n1.data<<endl;
                break;

            case 2:
                cout << "Prepend CircularNode Operation \nEnter key & data of the CircularNode to be Prepended" << endl;
                cin >> key1;
                cin >> data1;
                n1->key = key1;
                n1->data = data1;
                obj.prependCircularNode(n1);
                break;

            case 3:
                cout << "Insert CircularNode After Operation \nEnter key of existing CircularNode after which you want to Insert this New CircularNode: " << endl;
                cin >> k1;
                cout << "Enter key & data of the New CircularNode first: " << endl;
                cin >> key1;
                cin >> data1;
                n1->key = key1;
                n1->data = data1;

                obj.insertCircularNodeAfter(k1,n1);
                break;

            case 4:

                cout << "Delete CircularNode By Key Operation - \nEnter key of the CircularNode to be deleted: " << endl;
                cin >> k1;
                obj.deleteCircularNodeByKey(k1);

                break;
            case 5:
                cout << "Update CircularNode By Key Operation - \nEnter key & NEW data to be updated" << endl;
                cin >> key1;
                cin >> data1;
                obj.updateCircularNodeByKey(key1,data1);

                break;
            case 6:
                obj.printList();

                break;
            case 7:
                system("cls");
                break;
            default:
                cout << "Enter Proper Option number " << endl;
            }

        } while (option != 0);

        return 0;
    }
};