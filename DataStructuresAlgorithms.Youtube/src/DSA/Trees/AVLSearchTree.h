#pragma once
#include<iostream>
#include "TreeNode.h"
#define SPACE 10
class AVLTree {
public:
    TreeNode* root;
    AVLTree() {
        root = nullptr;
    }
    bool isTreeEmpty() {
        if (root == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }
    // Get Height  
    int height(TreeNode* r) {
        if (r == nullptr)
            return -1;
        else {
            /* compute the height of each subtree */
            int lheight = height(r->Left);
            int rheight = height(r->Right);

            /* use the larger one */
            if (lheight > rheight)
                return (lheight + 1);
            else return (rheight + 1);
        }
    }

    // Get Balance factor of node N  
    int getBalanceFactor(TreeNode* n) {
        if (n == nullptr)
            return -1;
        return height(n->Left) - height(n->Right);
    }

    TreeNode* RightRotate(TreeNode* y) {
        TreeNode* x = y->Left;
        TreeNode* T2 = x->Right;

        // Perform rotation  
        x->Right = y;
        y->Left = T2;

        return x;
    }

    TreeNode* LeftRotate(TreeNode* x) {
        TreeNode* y = x->Right;
        TreeNode* T2 = y->Left;

        // Perform rotation  
        y->Left = x;
        x->Right = T2;

        return y;
    }

    TreeNode* insert(TreeNode* r, TreeNode* new_node) {
        if (r == nullptr) {
            r = new_node;
            std::cout << "Value inserted successfully" << std::endl;
            return r;
        }

        if (new_node->Value < r->Value) {
            r->Left = insert(r->Left, new_node);
        }
        else if (new_node->Value > r->Value) {
            r->Right = insert(r->Right, new_node);
        }
        else {
            std::cout << "No duplicate Values allowed!" << std::endl;
            return r;
        }

        int bf = getBalanceFactor(r);
        // Left Left Case  
        if (bf > 1 && new_node->Value < r->Left->Value)
            return RightRotate(r);

        // Right Right Case  
        if (bf < -1 && new_node->Value > r->Right->Value)
            return LeftRotate(r);

        // Left Right Case  
        if (bf > 1 && new_node->Value > r->Left->Value) {
            r->Left = LeftRotate(r->Left);
            return RightRotate(r);
        }

        // Right Left Case  
        if (bf < -1 && new_node->Value < r->Right->Value) {
            r->Right = RightRotate(r->Right);
            return LeftRotate(r);
        }

        /* return the (unchanged) node pointer */
        return r;

    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        /* loop down to find the Leftmost leaf */
        while (current->Left != nullptr) {
            current = current->Left;
        }
        return current;
    }

    TreeNode* deleteNode(TreeNode* r, int v) {
        // base case 
        if (r == nullptr) {
            return nullptr;
        }
        // If the key to be deleted is smaller than the root's key, 
        // then it lies in Left subtree 
        else if (v < r->Value) {
            r->Left = deleteNode(r->Left, v);
        }
        // If the key to be deleted is greater than the root's key, 
        // then it lies in Right subtree 
        else if (v > r->Value) {
            r->Right = deleteNode(r->Right, v);
        }
        // if key is same as root's key, then This is the node to be deleted 
        else {
            // node with only one child or no child 
            if (r->Left == nullptr) {
                TreeNode* temp = r->Right;
                delete r;
                return temp;
            }
            else if (r->Right == nullptr) {
                TreeNode* temp = r->Left;
                delete r;
                return temp;
            }
            else {
                // node with two children: Get the inorder successor (smallest 
                // in the Right subtree) 
                TreeNode* temp = minValueNode(r->Right);
                // Copy the inorder successor's content to this node 
                r->Value = temp->Value;
                // Delete the inorder successor 
                r->Right = deleteNode(r->Right, temp->Value);
                //deleteNode(r->Right, temp->Value); 
            }
        }

        int bf = getBalanceFactor(r);
        // Left Left Imbalance/Case or Right rotation 
        if (bf == 2 && getBalanceFactor(r->Left) >= 0)
            return RightRotate(r);
        // Left Right Imbalance/Case or LR rotation 
        else if (bf == 2 && getBalanceFactor(r->Left) == -1) {
            r->Left = LeftRotate(r->Left);
            return RightRotate(r);
        }
        // Right Right Imbalance/Case or Left rotation	
        else if (bf == -2 && getBalanceFactor(r->Right) <= -0)
            return LeftRotate(r);
        // Right Left Imbalance/Case or RL rotation 
        else if (bf == -2 && getBalanceFactor(r->Right) == 1) {
            r->Right = RightRotate(r->Right);
            return LeftRotate(r);
        }

        return r;
    }

    void print2D(TreeNode* r, int space) {
        if (r == nullptr) // Base case  1
            return;
        space += SPACE; // Increase distance between levels   2
        print2D(r->Right, space); // Process Right child first 3 
        std::cout << std::endl;
        for (int i = SPACE; i < space; i++) // 5 
            std::cout << " "; // 5.1  
        std::cout << r->Value << "\n"; // 6
        print2D(r->Left, space); // Process Left child  7
    }
    void printPreorder(TreeNode* r) //(current node, Left, Right) 
    {
        if (r == nullptr)
            return;
        /* first print data of node */
        std::cout << r->Value << " ";
        /* then recur on Left sutree */
        printPreorder(r->Left);
        /* now recur on Right subtree */
        printPreorder(r->Right);
    }

    void printInorder(TreeNode* r) //  (Left, current node, Right)
    {
        if (r == nullptr)
            return;
        /* first recur on Left child */
        printInorder(r->Left);
        /* then print the data of node */
        std::cout << r->Value << " ";
        /* now recur on Right child */
        printInorder(r->Right);
    }
    void printPostorder(TreeNode* r) //(Left, Right, Root)
    {
        if (r == nullptr)
            return;
        // first recur on Left subtree 
        printPostorder(r->Left);
        // then recur on Right subtree 
        printPostorder(r->Right);
        // now deal with the node 
        std::cout << r->Value << " ";
    }

    /* Print nodes at a given level */
    void printGivenLevel(TreeNode* r, int level) {
        if (r == nullptr)
            return;
        else if (level == 0)
            std::cout << r->Value << " ";
        else // level > 0  
        {
            printGivenLevel(r->Left, level - 1);
            printGivenLevel(r->Right, level - 1);
        }
    }
    void printLevelOrderBFS(TreeNode* r) {
        int h = height(r);
        for (int i = 0; i <= h; i++)
            printGivenLevel(r, i);
    }

    TreeNode* iterativeSearch(int v) {
        if (root == nullptr) {
            return root;
        }
        else {
            TreeNode* temp = root;
            while (temp != nullptr) {
                if (v == temp->Value) {
                    return temp;
                }
                else if (v < temp->Value) {
                    temp = temp->Left;
                }
                else {
                    temp = temp->Right;
                }
            }
            return nullptr;
        }
    }

    TreeNode* recursiveSearch(TreeNode* r, int val) {
        if (r == nullptr || r->Value == val)
            return r;

        else if (val < r->Value)
            return recursiveSearch(r->Left, val);

        else
            return recursiveSearch(r->Right, val);
    }



    static int maine() {
        AVLTree obj;
        int option, val;

        do {
            std::cout << "What operation do you want to perform? " <<
                " Select Option number. Enter 0 to exit." << std::endl;
            std::cout << "1. Insert Node" << std::endl;
            std::cout << "2. Search Node" << std::endl;
            std::cout << "3. Delete Node" << std::endl;
            std::cout << "4. Print/Traversal AVL Tree Values" << std::endl;
            std::cout << "5. Height of Tree" << std::endl;
            std::cout << "6. Clear Screen" << std::endl;
            std::cout << "0. Exit Program" << std::endl;

            std::cin >> option;
            //Node n1;
            TreeNode* new_node = new TreeNode();

            switch (option) {
            case 0:
                break;
            case 1:
                std::cout << "AVL INSERT" << std::endl;
                std::cout << "Enter Value of TREE NODE to INSERT in AVL Tree: ";
                std::cin >> val;
                new_node->Value = val;
                obj.root = obj.insert(obj.root, new_node);
                std::cout << std::endl;
                break;
            case 2:
                std::cout << "SEARCH" << std::endl;
                std::cout << "Enter Value of TREE NODE to SEARCH in AVL Tree: ";
                std::cin >> val;
                //new_node = obj.iterativeSearch(val);
                new_node = obj.recursiveSearch(obj.root, val);
                if (new_node != nullptr) {
                    std::cout << "Value found" << std::endl;
                }
                else {
                    std::cout << "Value NOT found" << std::endl;
                }
                break;
            case 3:
                std::cout << "DELETE" << std::endl;
                std::cout << "Enter Value of TREE NODE to DELETE in AVL: ";
                std::cin >> val;
                new_node = obj.recursiveSearch(obj.root, val);
                if (new_node != nullptr) {
                    obj.root = obj.deleteNode(obj.root, val);
                    std::cout << "Value Deleted" << std::endl;
                }
                else {
                    std::cout << "Value NOT found" << std::endl;
                }
                break;
            case 4:
                std::cout << "PRINT 2D: " << std::endl;
                obj.print2D(obj.root, 5);
                std::cout << std::endl;
                std::cout << "Print Level Order BFS: \n";
                obj.printLevelOrderBFS(obj.root);
                std::cout << std::endl;
                std::cout << "PRE-ORDER: ";
                obj.printPreorder(obj.root);
                std::cout << std::endl;
                std::cout << "IN-ORDER: ";
                obj.printInorder(obj.root);
                std::cout << std::endl;
                std::cout << "POST-ORDER: ";
                obj.printPostorder(obj.root);
                break;
            case 5:
                std::cout << "TREE HEIGHT" << std::endl;
                std::cout << "Height : " << obj.height(obj.root) << std::endl;
                break;
            case 6:
                system("cls");
                break;
            default:
                std::cout << "Enter Proper Option number " << std::endl;
            }

        } while (option != 0);

        return 0;
    };

};