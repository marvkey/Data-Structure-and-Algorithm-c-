#pragma once
class TreeNode {
public:
	int Value = 0;
	TreeNode* Left = nullptr;
	TreeNode* Right = nullptr;
	TreeNode() = default;
	TreeNode(int data) :
		Value(data)
	{}

};