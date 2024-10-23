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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*>q;
        TreeNode *r=root;
        root->val=0;
        q.push(r);
        while(!q.empty()){
            queue<TreeNode*>q2;
            map<TreeNode*,int>mp;
            while(!q.empty()){
                if(q.front()->left !=nullptr){
                    q2.push(q.front()->left);
                    mp[q.front()]+=q.front()->left->val;
                }
                if(q.front()->right !=nullptr){
                    q2.push(q.front()->right);
                    mp[q.front()]+=q.front()->right->val;
                }
                q.pop();
            }
            int sum=0;
            for(auto u:mp){
                sum+=u.second;
            }
            for(auto u:mp){
                int tmp=0;
                if(u.first->left !=nullptr){
                    tmp+=u.first->left->val;
                }
                if(u.first->right !=nullptr){
                    tmp+=u.first->right->val;
                }
                tmp=sum-tmp;

                 if(u.first->left !=nullptr){
                   u.first->left->val=tmp;
                }
                if(u.first->right !=nullptr){
                    u.first->right->val=tmp;
                }


            }
            q=q2;
        }
        return root;
        
    }
};