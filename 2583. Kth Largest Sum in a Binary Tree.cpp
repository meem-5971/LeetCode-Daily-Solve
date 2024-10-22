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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long>pq;

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            //Get the number of nodes in the current level,
            long sz=q.size();
            long sum=0;

            //The for loop runs sz times, once for each node in the current level
            for(int i=0;i<sz;i++){
                TreeNode* pn=q.front();
                q.pop();
                sum+= pn->val;

                //child pushing into queue
                if(pn->left != nullptr){
                    q.push(pn->left);
                }
                if(pn->right != nullptr){
                    q.push(pn->right);
                }
            }
            pq.push(sum);
        }
        // If there are fewer than k levels in the tree, return -1 because it's impossible to find the k-th largest sum.
        if(pq.size()<k) return -1;
        //removes the largest sums and leaves the k-th largest sum at the top
        for(int i=0;i<k-1;i++){
            pq.pop();
        }
        return pq.top();
    }
};