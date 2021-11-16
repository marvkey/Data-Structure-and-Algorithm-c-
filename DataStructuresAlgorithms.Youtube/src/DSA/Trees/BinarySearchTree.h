#pragma once
#include<iostream>
class TreeNode{
public:
	int Value=0;
	TreeNode* Left =nullptr;
	TreeNode* Right=nullptr;
	TreeNode() =default;
	TreeNode(int data):
		Value(data)
	{}

};
// binary search tree
class BST{
public:
	TreeNode* Root =nullptr;
	bool IsEmpty(){
		return Root!=nullptr;
	}

    void InsertNode(TreeNode* newNode){
        if(Root==nullptr){
            Root = newNode;
            return;
        }
        TreeNode* tempNode = Root;
        while(tempNode !=nullptr){
            if(newNode->Value == tempNode->Value){
                std::cout<<"Value already exist,"<<"Insert another avlue"<<std::endl;
                return;
            }
            if(newNode->Value < tempNode->Value && tempNode->Left==nullptr){
                tempNode->Left = newNode;
                std::cout<<"Value Inserted to the left"<<std::endl;
                break;
            }
            if(tempNode->Value >newNode->Value){
                tempNode = tempNode->Left;
                return;
            }

            if(tempNode->Value<newNode->Value && tempNode->Right==nullptr){
                tempNode->Right = newNode;
                std::cout << "Value Inserted to the right" << std::endl;
                break;
            }
            tempNode = tempNode->Right;
        };

    }
    void PrintPreOrder(TreeNode* node) {  //(Node,Left,Right)
        if (node == nullptr)return;
        std::cout << node->Value << " ";
        PrintPreOrder(node->Left);
        PrintPreOrder(node->Right);
    }
    void PrintInOrder(TreeNode* node){//(left,Node,Right)
        if(node==nullptr)return;
        PrintInOrder(node->Left);
        std::cout<<node->Value<<" ";
        PrintInOrder(node->Right);
    }
    void PrintPostOrder(TreeNode* node) {//(left,Right,Node)
        if (node == nullptr)return;
        PrintPostOrder(node->Left);
        PrintPostOrder(node->Right);
        std::cout << node->Value << " ";
    }
    #define SPACE 10
    void print2D(TreeNode* r,int space) {
        if (r == NULL) // Base case  1
            return;
        space += SPACE; // Increase distance between levels   2
        print2D(r->Right,space); // Process right child first 3 
        std::cout << std::endl;
        for (int i = SPACE; i < space; i++) // 5 
            std::cout << " "; // 5.1  
        std::cout << r->Value << "\n"; // 6
        print2D(r->Left,space); // Process left child  7
    }
    static void Maine() {
        BST obj;
        int option,val;

        do {
            std::cout << "What operation do you want to perform? " <<
                " Select Option number. Enter 0 to exit." << std::endl;
            std::cout << "1. Insert Node" << std::endl;
            std::cout << "2. Search Node" << std::endl;
            std::cout << "3. Delete Node" << std::endl;
            std::cout << "4. Print/Traversal BST values" << std::endl;
            std::cout << "5. Height of Tree" << std::endl;
            std::cout << "6. Clear Screen" << std::endl;
            std::cout << "0. Exit Program" << std::endl;

            std::cin >> option;
            //Node n1;
            TreeNode* new_node = new TreeNode();

            switch (option) {
            case 0:
            break;
            case 1: //INSERT
                std::cout<<"INSERT"<<std::endl;
                std::cout<<"Enter Value of Tre Node to INSERT in BST: ";
                std::cin>>val;
                new_node->Value = val;
                obj.InsertNode(new_node);
                std::cout<<"/n";
            break;

            case 2:
            break;
            case 3:

            break;
            case 4: // PRINT
                std::cout<<"PRINT\n";
                std::cout<<"Pre order: ";
                obj.PrintPreOrder(obj.Root);
                std::cout << std::endl;
                std::cout << "Pre Inorder: ";
                obj.PrintInOrder(obj.Root);
                std::cout << std::endl;
                std::cout << "Post Order: ";
                obj.PrintPostOrder(obj.Root);
                std::cout << std::endl;
            break;
            case 5:
            break;
            case 6:
            system("cls");
            break;
            default:
            std::cout << "Enter Proper Option number " << std::endl;
            }

        } while (option != 0);

    }
};