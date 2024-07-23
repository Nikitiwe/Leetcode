class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> arr(201, 0);
        for (int i=0; i!=nums.size(); i++)
        {
            arr[nums[i]+100]++;
        }
        int count=0, m;
        while (count<nums.size())
        {
            m=*max_element(arr.begin(), arr.end());
            for (int i=0; i!=arr.size(); i++)
            {
                if (arr[i]==m)
                {
                    while (arr[i]>0)
                    {
                        nums[count]=i-100;
                        arr[i]--;
                        count++;
                    }
                }
            }
        }
        reverse(nums.begin(), nums.end());
        return nums;
    }
};