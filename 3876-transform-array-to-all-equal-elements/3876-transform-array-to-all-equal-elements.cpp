class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        /*int sum = 0;
        for (int i=0; i!=nums.size(); i++) sum += nums[i];
        if (sum % 2 == 1 || sum % 2 == -1) return 0;*/
        int c = 0; // превращаем в 1
        vector<int> arr = nums;
        for (int i=0; i+1<arr.size(); i++)
        {
            if (arr[i] == -1)
            {
                arr[i+1] *= -1;
                c++;
            }
        }
        if (c <= k && arr.back() == 1) return 1;
        c = 0;
        arr = nums;
        for (int i=0; i+1<arr.size(); i++)
        {
            if (arr[i] == 1)
            {
                arr[i+1] *= -1;
                c++;
            }
        }
        if (c <= k && arr.back() == -1) return 1;
        return 0;
    }
};