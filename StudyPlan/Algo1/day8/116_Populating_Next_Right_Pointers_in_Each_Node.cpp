/** 
 * You are given a perfect binary tree where all leaves are on the same 
 * level, and every parent has two children. The binary tree has the 
 * following definition:           
 * 
 * struct Node {
 * int val;
 * Node *left;
 * Node *right;
 * Node *next;
 * }
 * 
 * Populate each next pointer to point to its next right node. If there 
 * is no next right node, the next pointer should be set to NULL.       
 * Initially, all next pointers are set to NULL.        
 * 
 * Example 1:          
 * Input: root = [1,2,3,4,5,6,7]           
 * Output: [1,#,2,3,#,4,5,6,7,#]           
 * Explanation: Given the above perfect binary tree (Figure A), your 
 * function should populate each next pointer to point to its next 
 * right node, just like in Figure B. The serialized output is in 
 * level order as connected by the next pointers, with '#' signifying 
 * the end of each level.            
 * 
 * Example 2:       
 * Input: root = []         
 * Output: []            
 * 
 * Constraints:           
 * The number of nodes in the tree is in the range [0, 212 - 1].           
 * -1000 <= Node.val <= 1000
 */
 
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
        list<Node*> nodeList;
        int count = 0, layer = 1;
        nodeList.push_back(root);
        while(!nodeList.empty()){
            Node* thisNode = nodeList.front();
            nodeList.pop_front();
            count ++;
            if ((int)pow(2, layer) == count+1){
                thisNode-> next = NULL;
                layer++;
            }
            else
                thisNode -> next = nodeList.front();
            if (thisNode -> left && thisNode -> right){
                nodeList.push_back(thisNode -> left);
                nodeList.push_back(thisNode -> right);
            }
        }
        return root;
    }

    Node* connect_discuss(Node* root) {
        if (!root) return root;
        Node* currNode = root;
        while(currNode -> left){
            currNode -> left -> next = currNode -> right;
            Node* p = currNode;
            while(p -> next){
                p -> right -> next = p -> next -> left;
                p = p -> next;
                p -> left -> next = p -> right;
            }
            p -> next = NULL;
            currNode = currNode -> left;
        }
        return root;
    }
};