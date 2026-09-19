class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // column -> values
        map<int, vector<int>> mp;

        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {

            int n = q.size();

            // Store nodes of CURRENT LEVEL
            map<int, vector<int>> level;

            while (n--) {

                auto [node, col] = q.front();
                q.pop();

                level[col].push_back(node->val);

                if (node->left)
                    q.push({node->left, col - 1});

                if (node->right)
                    q.push({node->right, col + 1});
            }

            // Same row + same column → sort by value
            for (auto &it : level) {
                sort(it.second.begin(), it.second.end());

                for (int val : it.second) {
                    mp[it.first].push_back(val);
                }
            }
        }

        vector<vector<int>> ans;

        for (auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};