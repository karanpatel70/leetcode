class Solution {
public:
    int splitNum(int num) {
        vector<int> ans;
        // Extract digits
        while (num > 0) {
            ans.push_back(num % 10);
            num /= 10;
        }
        
        // Sort digits in ascending order
        sort(ans.begin(), ans.end());
        
        int num1 = 0;
        int num2 = 0;
        
        // Alternately assign digits to num1 and num2
        for (int i = 0; i < ans.size(); i++) {
            if (i % 2 == 0) {
                num1 = num1 * 10 + ans[i];
            } else {
                num2 = num2 * 10 + ans[i];
            }
        }
        
        return num1 + num2;
    }
};