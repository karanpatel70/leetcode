class Solution {
public:
    int check(int n) {
        string s = to_string(n);
        int cnt = 0;
        for (int i = 1; i + 1 < (int)s.size(); i++) {
            if (s[i] > s[i-1] && s[i] > s[i+1]) cnt++;      // peak
            else if (s[i] < s[i-1] && s[i] < s[i+1]) cnt++; // valley
        }
        return cnt;
    }

    int totalWaviness(int num1, int num2) {
        int total = 0;
        for (int x = num1; x <= num2; x++)
            total += check(x);
        return total;
    }
};