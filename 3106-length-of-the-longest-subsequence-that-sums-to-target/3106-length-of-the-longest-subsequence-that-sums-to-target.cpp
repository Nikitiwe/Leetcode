class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> arr(k+1, -1); // ответ для i
        arr[0] = 0;
        for(int i=0; i!=nums.size(); i++)
        {
            for (int j=arr.size()-1; j>=0; j--)
            {
                if (arr[j] > -1 && j + nums[i] < arr.size())
                {
                    arr[j + nums[i]] = max(arr[j + nums[i]], arr[j] + 1);
                }
            }
        }
        if (arr[k] == 0) return -1;
        else return arr[k];
    }
};