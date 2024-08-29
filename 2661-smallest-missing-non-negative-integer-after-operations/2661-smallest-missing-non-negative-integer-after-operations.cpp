class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> arr(value, 0);
        for (int i=0; i!=nums.size(); i++) arr[(nums[i]%value+value)%value]++;
        int ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (arr[i%value]>0)
            {
                ans++;
                arr[i%value]--;
            }
            else return ans;
        }
        return ans;
    }
};