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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> result;

        if(!root) return result;

        queue<TreeNode*> q;

        q.push(root);
        int reverse=0;
        while(!q.empty())
        {
            int levelsize=q.size();
            vector<int> level;
            for(int i=0;i<levelsize;i++)
            {
                 TreeNode* temp=q.front();
                 q.pop();
                 level.push_back(temp->val);
                 if(temp->left) q.push(temp->left);
                 if(temp->right) q.push(temp->right);
            }
            if(reverse%2==0)
            result.push_back(level);
            else
            {
               vector<int> reverse(level.rbegin(),level.rend());
                result.push_back(reverse);
            }
            reverse++;
        } 
        return result;
    }
};