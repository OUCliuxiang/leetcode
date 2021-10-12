/**
 * Given the roots of two binary trees root and subRoot, return true 
 * if there is a subtree of root with the same structure and node va-
 * lues of subRoot and false otherwise.           
 * A subtree of a binary tree tree is a tree that consists of a node 
 * in tree and all of this node's descendants. The tree tree could al-
 * so be considered as a subtree of itself.            
 * 
 * Example 1:        
 * Input: root = [3,4,5,1,2], subRoot = [4,1,2]         
 * Output: true          
 * 
 * Example 2:            
 * Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]      
 * Output: false           
 */

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        int subVal = subRoot -> val, 
            rootVal = root -> val;
        
        deque<TreeNode*> q;
        q.emplace_back(root);
        while(!q.empty()){
            TreeNode* p = q.front(); q.pop_front();
            if( subVal == p -> val && judge(p, subRoot))
                return true;
            if(p ->left) q.emplace_back(p -> left);
            if(p->right) q.emplace_back(p ->right);
        }
        return false;
    }
private:
    bool judge(TreeNode* root, TreeNode* subRoot){
        while(root && subRoot){
            if(root -> val != subRoot -> val) return false;
            return ( judge(root -> left, subRoot -> left) &&
                     judge(root ->right, subRoot ->right));
        }
        return (!root && !subRoot) ? true : false;
    }
};