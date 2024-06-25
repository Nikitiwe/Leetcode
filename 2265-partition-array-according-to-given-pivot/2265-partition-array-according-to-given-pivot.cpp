class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int countP=0;
        vector<int> ans, big;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]<pivot) ans.push_back(nums[i]);
            else if (nums[i]==pivot) countP++;
            else big.push_back(nums[i]);
        }
        for (int i=0; i!=countP; i++) ans.push_back(pivot);
        nums=ans;
        for (int i=0; i!= big.size(); i++) nums.push_back(big[i]);
        return nums;
    }
};