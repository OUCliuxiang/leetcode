/**
 * You are given two binary trees root1 and root2.
 * Imagine that when you put one of them to cover the other, some 
 * nodes of the two trees are overlapped while the others are not. 
 * You need to merge the two trees into a new binary tree. The 
 * merge rule is that if two nodes overlap, then sum node values 
 * up as the new value of the merged node. Otherwise, the NOT null 
 * node will be used as the node of the new tree.
 * 
 * Return the merged tree.
 * 
 * Note: The merging process must start from the root nodes of both trees.
 * 
 * Example 1:
 * Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
 * Output: [3,4,5,5,4,null,7]
 * 
 * Example 2:
 * Input: root1 = [1], root2 = [1,2]
 * Output: [2,2]
 * 
 * Constraints:
 * The number of nodes in both trees is in the range [0, 2000].
 * -104 <= Node.val <= 104
 */
 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && ! root2)  return nullptr;
        TreeNode* root = new TreeNode();
        Traverse(root, root1, root2);
        return root;
    }

    TreeNode* mergeTrees_discuss(TreeNode* t1, TreeNode* t2) {
        if (t1 && t2) { 
            t1->val+=t2->val;
            t1->left = mergeTrees(t1->left,t2->left);  
            t1->right = mergeTrees(t1->right, t2->right);
        } else { 
            return t1 ? t1 : t2;  
        }
        return t1; 
        }

private:
    void Traverse(TreeNode* root, TreeNode* root1, TreeNode* root2){
        if (root1 && root2) {
            root -> val = root1 -> val + root2 -> val;
            if(root1 -> left || root2 -> left){
                root -> left = new TreeNode();
                Traverse(root -> left, root1 -> left, root2 -> left);
            }
            if(root1 -> right || root2 -> right){
                root -> right = new TreeNode();
                Traverse(root -> right, root1 -> right, root2 -> right);
            }
        }else if(root1 && !root2){
            root -> val = root1 -> val;
            if(root1 -> left){
                root -> left = new TreeNode();
                Traverse(root -> left, root1 -> left, nullptr);
            }
            if(root1 -> right){
                root -> right = new TreeNode();
                Traverse(root -> right, root1 -> right, nullptr);
            }
        }
        else if (!root1 && root2){
            root -> val = root2 -> val;
            if(root2 -> left){
                root -> left = new TreeNode();
                Traverse(root -> left, nullptr, root2 -> left);
            }
            if(root2 -> right){
                root -> right = new TreeNode();
                Traverse(root -> right, nullptr, root2 -> right);
            }
        }
        else
            return;
    }
};

