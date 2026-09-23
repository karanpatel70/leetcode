/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
Node* connect(Node* root) {
    if (!root) return root;

    Node* leftmost = root; // leftmost node of current level

    while (leftmost->left) {  // while there's a level below
        Node* head = leftmost;
        while (head) {
            // connect the two children of the same parent
            head->left->next = head->right;

            // connect across parents (skip if no next parent)
            if (head->next) {
                head->right->next = head->next->left;
            }

            head = head->next; // move to next node in current level
        }
        leftmost = leftmost->left; // move down to next level
    }

    return root;
}

};