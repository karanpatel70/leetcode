/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool find(TreeNode* root,vector<TreeNode*>& path,TreeNode* target)
    {
        if(root==NULL)
        {
            return false;
        }
        path.push_back(root);
        if(root==target)
        {
            return true;
        }
        if(find(root->left,path,target)||find(root->right,path,target))
        {
            return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      vector<TreeNode*>  pathp;
      vector<TreeNode*> pathq;
      find(root,pathp,p);
      find(root,pathq,q);
      int i=0;
      TreeNode* ans=NULL;
      while(i<pathp.size() && i<pathq.size())
      {
         if(pathp[i]!=pathq[i])
         {
            break;
         }
         ans=pathp[i];
         i++;
      }
      return ans;
    }
};