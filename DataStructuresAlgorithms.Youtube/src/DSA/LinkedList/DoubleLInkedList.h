#pragma once
#include <iostream>

class DoubleNode {
public:
	int Key;
	int Data;
	DoubleNode* Previous;
	DoubleNode*Next;

	DoubleNode() {
		Key = 0;
		Data = 0;
		Next = nullptr;
		Previous == nullptr;
	}

	DoubleNode(int K,int D) {
		Key = K;
		Data = D;
	}
};

class DoubleLinkedList {
public:
	DoubleNode* Head;

	DoubleLinkedList() {
		Head = nullptr;
	}

	DoubleLinkedList(DoubleNode* N) {
		Head = N;
	}

	DoubleNode* CheckIfNodeExist(int K) {
		DoubleNode* Temp = nullptr;
		DoubleNode* Ptr = Head;

		while (Ptr != nullptr) {
			if (Ptr->Key == K) {
				Temp = Ptr;
			}
			Ptr = Ptr->Next;
		}
	}

	void AppendNode(DoubleNode* N) {
		if (CheckIfNodeExist(N -> Key) != nullptr) {
			std::cout << "node exist " << N->Key << ". try a new node " << std::endl;
		}
		else {
			if (Head == nullptr) {
				Head = N;
				std::cout << "node appendes as head node " << std::endl;
			}
			else {
				DoubleNode* Ptr = Head;
				while (Ptr != nullptr) {
					Ptr = Ptr->Next;
				}
				Ptr->Next = N;
				N->Previous = Ptr;
				std::cout << "Node Appended" << std::endl;
			}
		}
	}

	void PrependNode(DoubleNode* N) { // make it the Head
		if (CheckIfNodeExist(N->Key) != nullptr)
			std::cout << "Node already exist with the Key value :" << N->Key << ". Append another node with differetn key value" << std::endl;
		else {
			if (Head == nullptr) {
				Head = N;
				std::cout << "Node Prepended as head Node" << std::endl;
				return;
			}
			Head->Previous = N;
			N->Next = Head;
			Head = N;
			std::cout << "Node Prepended" << std::endl;
		}
	}


	void InsertNodeAfter(int k,DoubleNode* N) {
		DoubleNode* Ptr = CheckIfNodeExist(k);
		if (Ptr == nullptr)
			std::cout << "no node exist with the key value : " << k << std::endl;
		else {
			if (CheckIfNodeExist(N->Key) != nullptr)
				std::cout << "Node already exist with the Key value at the end of the list:" << N->Key << ". Append another node with differetn key value" << std::endl;
			else {
				DoubleNode* NextNode = Ptr->Next;
				if (NextNode == nullptr) {
					Ptr->Next = N;
					N->Previous = Ptr;
					std::cout << "Node inseerted at the End" << std::endl;
				}
				else {
					N->Next = NextNode;
					NextNode->Previous = N;
					N->Previous = Ptr;
					Ptr->Next = N;
					std::cout << "Node inseerted at the between" << std::endl;
				}
			}
		}
	}

	void DeleteNodeByKey(int K) {// al we are doing is unliking it from memory
		DoubleNode* Ptr = CheckIfNodeExist(K);
		if (Ptr == nullptr) {
			std::cout << "No Node exist with key value : " << K << std::endl;
		}
		else {
			if (Head->Key == K) {
				Head = Head->Next;
				std::cout << "Node unliked" << std::endl;
			}
			else {
				DoubleNode* NextNode = Ptr->Next;
				DoubleNode* PrevNode = Ptr->Previous;

				if (NextNode == nullptr) {
					PrevNode->Next = nullptr;
					std::cout << "Node deleted at the END" << std::endl;
				}
				else {
					PrevNode->Next = NextNode;
					NextNode->Previous = PrevNode;
					std::cout << "node deleted in between"<<std::endl;
				}
			}
		}

	}


	void UpdateNodeByKey(int K,int d) {
		DoubleNode* Ptr = CheckIfNodeExist(K);
		if (Ptr != nullptr) {
			Ptr->Data = d;
			std::cout << "node Data update succesfully" << std::endl;
		}
		else {
			std::cout << "Node does not Exist with Key Value : " << std::endl;
		}
	}

	void PrintList() {
		if (Head == nullptr)
			std::cout << std::endl << "NO Nodes in Single Linked List: ";
		else {
			std::cout << std::endl << "single Linkeed List Values : ";
			DoubleNode* Temp = Head;
			while (Temp != nullptr) {
				std::cout << "(" << Temp->Key << "," << Temp->Data << ") -->";
				Temp = Temp->Next;
			}
		}
	}

	static void Main() {
		DoubleLinkedList s; int Option,Key1,K1,Data1;

		do {
			std::cout << "what operation do you want to perorm 0 to exit" << std::endl;
			std::cout << "1. appednNode()" << std::endl;
			std::cout << "2. prependNode()" << std::endl;
			std::cout << "3. InsertNodeAfter()" << std::endl;
			std::cout << "4. DeleteNodeByKey()" << std::endl;
			std::cout << "5. UpdateNOdeByKey()" << std::endl;
			std::cout << "6. PrintLIst()" << std::endl;
			std::cout << "7. clear Screen()" << std::endl;
			std::cin >> Option;
			DoubleNode* n1 = new DoubleNode();
			switch (Option) {
			case 0:
				break;
			case 1:
				std::cout << "Append NOde operation \n Enter key & data of the NOde to be Appended" << std::endl;
				std::cin >> Key1;
				std::cin >> Data1;
				n1->Key = Key1;
				n1->Data = Data1;
				s.AppendNode(n1);
				break;
			case 2:
				std::cout << "Prependd NOde operation \n Enter key & data of the NOde to be Prepend" << std::endl;
				std::cin >> Key1;
				std::cin >> Data1;
				n1->Key = Key1;
				n1->Data = Data1;
				s.PrependNode(n1);
				break;
			case 3:
				std::cout << "Insert NOde Afte Operation \n Enter key of existin NOde" << std::endl;
				std::cin >> K1;
				std::cout << "Enter Key & Data of the New Node first : " << std::endl;
				std::cin >> Key1;
				std::cin >> Data1;
				n1->Key = Key1;
				n1->Data = Data1;
				s.InsertNodeAfter(K1,n1);
				break;
			case 4:
				std::cout << "delte node by operation \n Enter Key of hte Nodde to be delted: " << std::endl;
				std::cin >> K1;
				s.DeleteNodeByKey(K1);
				break;
			case 5:
				std::cout << "Update Node By Key Operation - \n Enter Key & New Data to be Updated" << std::endl;
				std::cin >> Key1;
				std::cin >> Data1;
				s.UpdateNodeByKey(Key1,Data1);
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