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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        //base case

        //Selected nodes of 2 trees are null at a time
        if(root1==NULL && root2==NULL){
            return true;
        }
        //only one selected node is null at a time
        if(root1==NULL || root2==NULL){
            return false;
        }

        //Recursion calls
        //the selected nodes are considered as root nodes and they must be equal
        if(root1->val == root2->val){
           bool withflip=flipEquiv(root1->left, root2->right) && flipEquiv(root1->right , root2->left);
           bool withoutflip=flipEquiv(root1->left, root2->left) && flipEquiv(root1->right , root2->right);

            return withflip || withoutflip;
        }
        return false;
    }
};