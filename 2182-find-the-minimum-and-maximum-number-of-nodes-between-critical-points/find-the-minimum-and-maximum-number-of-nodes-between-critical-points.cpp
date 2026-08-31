/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> nums;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            nums.push_back(temp->val);
            temp=temp->next;
        }
        if(nums.size()<3)
        {
            return {-1,-1};
        }
        vector<int> ans;
        int n=nums.size();
        for(int i=1;i<=n-2;i++)
        {
           if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
           {
             ans.push_back(i+1);
           }
           else if(nums[i]<nums[i-1] && nums[i]<nums[i+1])
           {
             ans.push_back(i+1);
           }
        }
        if(ans.size()<2) return {-1,-1};
        int mini=INT_MAX;
        for(int i=1;i<ans.size();i++)
        {
            mini=min(mini,ans[i]-ans[i-1]);
        }
        int maxi=ans[ans.size()-1]-ans[0];
        return {mini,maxi};
    }
};