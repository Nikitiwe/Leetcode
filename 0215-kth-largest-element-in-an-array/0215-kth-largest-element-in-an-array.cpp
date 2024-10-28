class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> m(nums.begin(), nums.end());
        while (k>1)
        {
            m.pop();
            k--;
        }
        return m.top();
    }
};