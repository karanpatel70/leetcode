class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, 
             int original, int color) {
        
        int m = image.size();
        int n = image[0].size();

        // Out of bounds
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;

        // Not the original color
        if (image[i][j] != original)
            return;

        // Change color
        image[i][j] = color;

        // Visit 4 directions
        dfs(image, i + 1, j, original, color); // down
        dfs(image, i - 1, j, original, color); // up
        dfs(image, i, j + 1, original, color); // right
        dfs(image, i, j - 1, original, color); // left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, 
                                  int sr, int sc, int color) {
        
        int original = image[sr][sc];

        // Important: avoid infinite recursion
        if (original == color)
            return image;

        dfs(image, sr, sc, original, color);

        return image;
    }
};