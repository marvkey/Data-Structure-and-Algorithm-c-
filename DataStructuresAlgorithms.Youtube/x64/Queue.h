#pragma once
#include <iostream>
using namespace std;
class Queue {
private:
    int front;
    int rear;
    int arr[5];
public:
    Queue() {
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++) {
            arr[i] = 0;
        }
    }
    bool IsEmpty() {
        if (front == -1 && rear == -1)
            return true;
        return false;
    }
    bool IsFull() {
        if (rear == 4) // we know array is 5 so hard coding 4 in here
            return true;
        return false;
    }

    void Enqueue(int val) {
        if (IsFull()) {
            cout << "Que is full" << endl;
            return;
        }
        else if (IsEmpty()) {
            rear = 0;
            front = 0;
            arr[rear] = val;
        }
        else {
            rear++;
            arr[rear] = val;
        }
    }

    int Dequeue() { 
        int X;
        if (IsEmpty()) {
            cout << " Que is empty" << endl;
            return 0;
        }
        else if (front == rear) { // when there is one object left in the queue
            X = arr[front];
            arr[front] = 0; // make it zero to reflect the change of the remove
            rear = -1;
            front =-1;
            return X;
        }
        else { //Multiple values in teh queue
            X = arr[front];
            arr[front] = 0; // make zero to reflect the change
            front++;
            return X;
        }
    }
    int Count() {
        return rear - front + 1; // formula gives the exact number of element present in que
    }

    void Display() {
        cout << "all values of the que " << endl;
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << " ";
        }
    }
    static void QueueMain() {
        int Option, Value;
        Queue Q1;
        do {
            std::cout << "Operation perform Entor 0 to exit" << endl;
            cout << "1. Enqueue()" << endl;
            cout << "2.  Dequeue()" << endl;
            cout << "3. IsEmpty()" << endl;
            cout << "4. IsFull()" << endl;
            cout << "4. count()" << endl;
            cout << "5. Count()" << endl;
            cout << "6. Dispal()" << endl;
            cout << "7. clear screen()" << endl;

            cin >> Option;
            switch (Option) {
            case 1:
                cout << "enter value to enque" << endl;
                cin >> Value;
                Q1.Enqueue(Value);
                break;
            case 2:
                cout << " Deque value is : " << Q1.Dequeue() << endl;
                break;
            case 3:
                if (Q1.IsEmpty())
                    cout << "Que is empty" << endl;
                else
                    cout << "Queue is not empty" << endl;
                break;
            case 4:
                if (Q1.IsFull())
                    cout << "Que is full" << endl;
                else
                    cout << "Que is not full" << endl;
                break;
            case 5:
                cout << "the size of the que is" << Q1.Count() << endl;
                break;
            case 6:
                cout << "Display function" << endl;
                Q1.Display();
                break;
            case 7:
                system("cls");
                break;
            default:
                cout << "number is out of the option number index";
                break;
            }
        } while (Option != 0);
    }
};