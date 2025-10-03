#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value)
    {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};
void preorder(TreeNode *root)
{
    // Algorithm for Preorder Traversal
    // 1.Create an empty stack
    // 2.Push the root node to the stack
    // 3.While the stack is not empty:
    // a.Pop the top node from the stack and process it (e.g., print its value).
    // b.Push the right child of the popped node to the stack (if it exists).
    // c.Push the left child of the popped node to the stack (if it exists).
    if (root == nullptr)
        return;
    // Preorder Traversal: Root -> Left -> Right
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        cout << node->val << " ";
        if (node->right)
        {
            st.push(node->right);
        }
        if (node->left)
        {
            st.push(node->left);
        }
    }
}
void inorder(TreeNode *root)
{
    // Algorithm for Inorder Traversal
    // 1.Create an empty stack
    // 2.set current node to the root
    // 3.While the current node is not null or the stack is not empty:
    // a. go as left as possible from the current node, pushing each node onto the stack
    // b. when we cant go left anymore,(curr=null),pop from the stack->visit the node
    // c. move to the right child of the visited node
    if (root == nullptr)
        return;
    // Inorder Traversal: Left -> Root -> Right
    stack<TreeNode *> st;
    TreeNode *curr = root;
    while (curr != nullptr || !st.empty())
    {
        // Reach the leftmost node of the current node
        while (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        // Current must be nullptr at this point
        curr = st.top();
        st.pop();
        cout << curr->val << " ";
        // We have visited the node and its left subtree. Now, it's right subtree's turn
        curr = curr->right;
    }
}
void postorder1(TreeNode *root)
{
    if (root == nullptr)
        return;
    // Postorder Traversal: Left -> Right -> Root
    // Using single stack
    stack<TreeNode *> s1;
    TreeNode *curr = root;
    TreeNode *lastVisited = nullptr;
    while (!s1.empty() || curr)
    {
        if (curr)
        {
            s1.push(curr);
            curr = curr->left;
        }
        else
        {
            TreeNode *temp = s1.top();
            if (temp->right != nullptr && lastVisited != temp->right)
            {
                curr = temp->right;
            }
            else
            {
                cout << temp->val << " ";
                lastVisited = temp;
                s1.pop();
            }
        }
    }
}
void postorder2(TreeNode *root)
{
    if (root == nullptr)
        return;
    // Postorder Traversal: Left -> Right -> Root
    // Using two stacks
    stack<TreeNode *> s1, s2;
    s1.push(root);
    while (!s1.empty())
    {
        TreeNode *node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }
    // Print the contents of the second stack (postorder)
    while (!s2.empty())
    {
        TreeNode *node = s2.top();
        s2.pop();
        cout << node->val << " ";
    }
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    // Iterative Preorder Traversal
    preorder(root);
    // Iterative Inorder Traversal
    inorder(root);
    // Iterative Postorder Traversal
    postorder1(root);
    postorder2(root);
    return 0;
}