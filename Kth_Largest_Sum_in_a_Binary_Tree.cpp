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
    void compute(TreeNode* root, vector<long long>& result){
        if(root==nullptr){
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
        int levelSize = q.size();
        long long levelSum = 0;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                levelSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(levelSum);
        }
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> result;
        compute(root, result);
        if (result.size() < k) return -1;
        sort(result.begin(),result.end(),greater<long long>());
        return result[k-1];
    }
};