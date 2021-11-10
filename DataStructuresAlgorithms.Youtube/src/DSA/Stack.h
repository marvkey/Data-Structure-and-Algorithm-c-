#pragma once
#include<iostream>
#include <string>

class Stack {
private:
	int top;
	int arr[5];
public:
	Stack() {
		top = -1;
		for (int i = 0; i < 5; i++) {
			arr[i] = 0;

		}
	}
	bool isEmpty() {
		if (top == -1) {

			return true;
		}
		return false;
	}

	bool isFull() {
		if (top == 4) {
			return true;
		}
		else
			return false;
	}

	void push(int val) {
		if (isFull() == true) {
			std::cout << "Stack Overflow" << std::endl;
		}
		else {
			top++;
			arr[top] = val;

		}
	}

	int pop() {
		if (isEmpty() == true) {
			std::cout << "stack underflow" << std::endl;
			return 0;
		}
		else {
			int popValue = arr[top];
			arr[top] = 0;
			top--;
			return popValue;
		}
	}

	int Count() {
		return (top + 1);
	}

	int peek(int pos) {
		if (isEmpty() == true) {
			std::cout << "stack underflow" << std::endl;
			return 0;
		}
		else
		{
			return arr[pos];

		}
	}

	void change(int pos, int val) {
		arr[pos] = val;
		std::cout << "Value changed at location " << pos << std::endl;
	}
	void display() {
		std::cout << "All value of the stack are " << std::endl;
		for (int i = 4; i >= 0; i--) { // prints out all items backward
			std::cout << arr[i] << std::endl;
		}
	}

	int maine() { // this what it would look  in main function
		Stack s1;
		int option, position, value;

		do {
			std::cout << "Operation want 0, to exit" << std::endl;
			std::cout << "1. Push" << std::endl;
			std::cout << "2. pop" << std::endl;
			std::cout << "3. isEmpty()" << std::endl;
			std::cout << "4. isFull()" << std::endl;
			std::cout << "5. Peek()" << std::endl;
			std::cout << "6. count" << std::endl;
			std::cout << "7. change()" << std::endl;
			std::cout << "8. display()" << std::endl;
			std::cout << "9. Clear Screen" << std::endl;

			std::cin >> option;
			switch (option)
			{
			case 0:
				break;
			case 1:
				std::cout << "enter an item to push " << std::endl;
				std::cin >> value;
				s1.push(value);
				break;
			case 2:
				std::cout << "Pop value is :" << s1.pop() << std::endl;
				break;
			case 3:
				if (s1.isEmpty() == true) {
					std::cout << "Stack is empty" << std::endl;
				}
				else {
					std::cout << "Stack is not empty " << std::endl;
				}
				break;
			case 4:
				if (s1.isFull() == true) {
					std::cout << "Stack is Full" << std::endl;
				}
				else {
					std::cout << "Stack is not Full " << std::endl;
				}
				break;
			case 5:
				std::cout << "Enter position of item you want to peek: " << std::endl;
				std::cin >> position;
				std::cout << "Peak is called - value at position" << position << "is" << std::endl << s1.peek(position) << std::endl;

				break;
			case 6:
				std::cout << "Count Number of items in stack are: " << s1.Count() << std::endl;
				break;
			case 7:
				std::cout << "change function -" << std::endl;
				std::cout << "position of item to be changed ";
				std::cin >> position;
				std::cout << std::endl;
				std::cout << "enter a value of item to be swapped: ";
				std::cin >> value;
				s1.change(position, value);
				break;
			case 8:
				std::cout << "Display function " << std::endl;
				s1.display();
				break;
			case 9:
				system("cls");
				break;
			default:
				std::cout << "Enter a proper option Number " << std::endl;
			}




		} while (option != 0);
	}
};


class DynamicStack {
private:
	int StackNum;
	int top;
	int arr[];
public:
	DynamicStack() {
		std::cout << "How many elements do you want to store in the stack "; 
		std::cin >> StackNum;
		top = -1;
		arr[StackNum];

		for (int i = 0; i < StackNum; i++) {
			arr[i] = 0;
			

		}
	}
	bool isEmpty() {
		if (top == -1) {

			return true;
		}
		return false;
	}

	bool isFull() {
		if (top == (StackNum-1)) {
			return true;
		}
		else
			return false;
	}

	void push(int val) {
		if (isFull() == true) {
			std::cout << "Stack Overflow" << std::endl;
		}
		else {
			top++;
			arr[top] = val;

		}
	}

	int pop() {
		if (isEmpty() == true) {
			std::cout << "stack underflow" << std::endl;
			return 0;
		}
		else {
			int popValue = arr[top];
			arr[top] = 0;
			top--;
			return popValue;
		}
	}

	int Count() {
		return (top + 1);
	}

	int peek(int pos) {
		if (isEmpty() == true) {
			std::cout << "stack underflow" << std::endl;
			return 0;
		}
		else
		{
			return arr[pos];

		}
	}

	void change(int pos, int val) {
		arr[pos] = val;
		std::cout << "Value changed at location " << pos << std::endl;
	}
	void display() {
		std::cout << "All value of the stack are " << std::endl;
		for (int i = StackNum-1; i >= 0; i--) { // prints out all items backward
			std::cout << arr[i] << std::endl;
		}
	}

	
};

void DynamicStackmain() { // this what it would look  in main function
	DynamicStack s1;
	int option, position, value;

	do {
		std::cout << "Operation want 0, to exit" << std::endl;
		std::cout << "1. Push" << std::endl;
		std::cout << "2. pop" << std::endl;
		std::cout << "3. isEmpty()" << std::endl;
		std::cout << "4. isFull()" << std::endl;
		std::cout << "5. Peek()" << std::endl;
		std::cout << "6. count" << std::endl;
		std::cout << "7. change()" << std::endl;
		std::cout << "8. display()" << std::endl;
		std::cout << "9. Clear Screen" << std::endl;

		std::cin >> option;
		switch (option)
		{
		case 0:
			break;
		case 1:
			std::cout << "enter an item to push " << std::endl;
			std::cin >> value;
			s1.push(value);
			break;
		case 2:
			std::cout << "Pop value is :" << s1.pop() << std::endl;
			break;
		case 3:
			if (s1.isEmpty() == true) {
				std::cout << "Stack is empty" << std::endl;
			}
			else {
				std::cout << "Stack is not empty " << std::endl;
			}
			break;
		case 4:
			if (s1.isFull() == true) {
				std::cout << "Stack is Full" << std::endl;
			}
			else {
				std::cout << "Stack is not Full " << std::endl;
			}
			break;
		case 5:
			std::cout << "Enter position of item you want to peek: " << std::endl;
			std::cin >> position;
			std::cout << "Peak is called - value at position" << position << "is" << std::endl << s1.peek(position) << std::endl;

			break;
		case 6:
			std::cout << "Count Number of items in stack are: " << s1.Count() << std::endl;
			break;
		case 7:
			std::cout << "change function -" << std::endl;
			std::cout << "position of item to be changed ";
			std::cin >> position;
			std::cout << std::endl;
			std::cout << "enter a value of item to be swapped: ";
			std::cin >> value;
			s1.change(position, value);
			break;
		case 8:
			std::cout << "Display function " << std::endl;
			s1.display();
			break;
		case 9:
			system("cls");
			break;
		default:
			std::cout << "Enter a proper option Number " << std::endl;
		}




	} while (option != 0);

}