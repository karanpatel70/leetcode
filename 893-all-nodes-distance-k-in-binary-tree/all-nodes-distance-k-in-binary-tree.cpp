
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> m;
    void makeparent(TreeNode* parent,TreeNode* val)
    {
        if(parent==NULL)
        {
            return;
        }
        m[parent]=val;
        if(parent->left){
            makeparent(parent->left,parent);
        }
        if(parent->right)
        {
            makeparent(parent->right,parent);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        makeparent(root,NULL);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int distance=0;
        while(q.size()>0)
        {
            int size=q.size();
            if(distance==k)
            {
                vector<int> ans;
                while(!q.empty())
                {
                   ans.push_back(q.front()->val);
                   q.pop();
                }
                return ans;
            }
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && !visited.count(temp->left))
                {
                    visited.insert(temp->left);
                    q.push(temp->left);
                }
                if(temp->right && !visited.count(temp->right))
                {
                    visited.insert(temp->right);
                    q.push(temp->right);
                }
                if(m[temp] && !visited.count(m[temp]))
                {
                    visited.insert(m[temp]);
                    q.push(m[temp]);
                }
            }
            distance++;
        }
        return {};
    }
};