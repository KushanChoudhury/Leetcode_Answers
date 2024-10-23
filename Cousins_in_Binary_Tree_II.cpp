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
        queue<TreeNode*> q;
        q.push(root);
        vector<int> levelSum;
        while(!q.empty())
        {
            int currlevelSum=0;
            int n=q.size();
            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                currlevelSum+=curr->val;
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            levelSum.push_back(currlevelSum);
        }
        q.push(root);
        int i=1;
        root->val=0;
        while(!q.empty())
        {
            int n=q.size();
            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                int sibblingSum=curr->left!=NULL?curr->left->val:0;
                sibblingSum+=curr->right!=NULL?curr->right->val:0;
                if(curr->left){
                    curr->left->val=levelSum[i]-sibblingSum;
                    q.push(curr->left);
                }
                if(curr->right){
                    curr->right->val=levelSum[i]-sibblingSum;
                    q.push(curr->right);
                }
            }
            i++;
        }
        return root;
    }
};