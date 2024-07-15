class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size(), temp, count;
        if (nums.size()%k!=0) return 0;
        if (k==1) return 1;
        sort(nums.begin(), nums.end());
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]!=0) {
            temp=nums[i];
            count=1;
            temp++;
            for (int j=i+1; j!=nums.size(); j++)
            {
                if (nums[j]==temp) {nums[j]=0; temp++; count++; if (count==k) break; }
            }
            if (count<k) return 0; }
        }
        return 1;
    }
};