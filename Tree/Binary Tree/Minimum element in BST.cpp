#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to find minimum element in BST
int findMin(Node *root)
{
    if (root == nullptr)
    {
        return -1; // Meaningful value indicating empty BST
    }
    Node *curr = root;
    while (curr->left != nullptr)
    {
        curr = curr->left;
    }
    return curr->data;
}
