class Solution {
public:
    bool isPossible(vector<int>& nums) {
        vector<int> arr(2003, 0);
        for (int i=0; i!=nums.size(); i++) arr[nums[i]+1001]++;
        for (int i=0; i<arr.size()-1; i++)
        {
            while (arr[i] > 0)
            {
                int t = 0;
                for (int j=i; j<arr.size(); j++)
                {
                    t++;
                    arr[j]--;
                    if (arr[j] >= arr[j+1])
                    {
                        if (t < 3) return 0;
                        else break;
                    }
                }
            }
        }
        return 1;
    }
};