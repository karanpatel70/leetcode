class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> ans(10,0);
        for(int i=0;i<digits.size();i++)
        {
            ans[digits[i]]++;
        }
        int cnt=0;
        for(int i=100;i<1000;i+=2)
        {
            int d1=i/100;
            int d2=(i/10)%10;
            int d3=i%10;
           vector<int> check(10,0);
           check[d1]++;
           check[d2]++;
           check[d3]++;
           bool canform=true;
           for(int i=0;i<10;i++)
           {
            if(ans[i]<check[i])
            {
              canform=false;
              break;
            }
           }
           if(canform)
           {
            cnt++;
           } 
        }
        return cnt;
    }
};