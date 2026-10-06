class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> m;
    unordered_map<int, TreeNode*> nodes;

    void makeparent(TreeNode* parent, TreeNode* val)
    {
        if(parent == NULL)
            return;

        m[parent] = val;
        nodes[parent->val] = parent;

        if(parent->left)
            makeparent(parent->left, parent);

        if(parent->right)
            makeparent(parent->right, parent);
    }

    int amountOfTime(TreeNode* root, int start)
    {
        // Create parent map and value -> node map
        makeparent(root, NULL);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        // Get actual TreeNode* from start value
        TreeNode* startNode = nodes[start];

        q.push(startNode);
        visited.insert(startNode);

        int time = 0;

        while(!q.empty())
        {
            int size = q.size();

            for(int i = 0; i < size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                // Left child
                if(temp->left && !visited.count(temp->left))
                {
                    visited.insert(temp->left);
                    q.push(temp->left);
                }

                // Right child
                if(temp->right && !visited.count(temp->right))
                {
                    visited.insert(temp->right);
                    q.push(temp->right);
                }

                // Parent
                if(m[temp] && !visited.count(m[temp]))
                {
                    visited.insert(m[temp]);
                    q.push(m[temp]);
                }
            }

            // One minute has passed
            time++;
        }

        // Last increment happens after the final level
        return time - 1;
    }
};