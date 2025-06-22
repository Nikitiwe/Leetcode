class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_set<int> s{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
        vector<int> arr(101, 0);
        for (int i=0; i!=nums.size(); i++) arr[nums[i]]++;
        bool isit = 0;
        for (int i=0; i!=arr.size(); i++) if (s.count(arr[i]) == 1) isit = 1;
        return isit;
    }
};