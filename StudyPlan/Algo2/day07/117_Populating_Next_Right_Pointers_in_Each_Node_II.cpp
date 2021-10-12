/**
 * Given a binary tree        
 * struct Node {
 *   int val;
 *   Node *left;
 *   Node *right;
 *   Node *next;
 * }
 * 
 * Populate each next pointer to point to its next right node. If there 
 * is no next right node, the next pointer should be set to NULL.           
 * Initially, all next pointers are set to NULL.           
 * 
 * Example 1:
 * Input: root = [1,2,3,4,5,null,7]          
 * Output: [1,#,2,3,#,4,5,7,#]           
 * Explanation: Given the above binary tree (Figure A), your function 
 * should populate each next pointer to point to its next right node, 
 * just like in Figure B. The serialized output is in level order as 
 * connected by the next pointers, with '#' signifying the end of each 
 * level.             
 * 
 * Example 2:       
 * Input: root = []        
 * Output: []           
 * 
 * Constraints:           
 * * The number of nodes in the tree is in the range [0, 6000].      
 * * -100 <= Node.val <= 100
 */

lass Solution {
public:
    Node* connect(Node* root) {
        if (! root) return root;
        Node* p = root;
        int level = 1;
        queue< pair<Node*, int>> q;
        if (p -> left != NULL)   q.push(make_pair( p->left, level));
        if (p ->right != NULL)   q.push(make_pair( p->right,level));
        
        while(!q.empty()){
            pair<Node*, int> tmp = q.front(); 
            q.pop();
            p = get<0>(tmp);
            level = get<1>(tmp);
            if (p -> left != NULL)   q.push(make_pair( p->left, level+1));
            if (p ->right != NULL)   q.push(make_pair( p->right,level+1));
            
            tmp = q.front(); 
            if (level == get<1>(tmp))
                p -> next = get<0>(tmp);
        }
        return root;
    }
};