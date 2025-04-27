class FindSumPairs {
public:
    unordered_map<int, int> m;
    vector<int> arr, brr;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr = nums1;
        brr = nums2;
        for (int i=0; i!=brr.size(); i++) m[brr[i]]++;
    }
    
    void add(int index, int val) {
        m[brr[index]]--;
        brr[index] += val;
        m[brr[index]]++;
    }
    
    int count(int sum) {
        int ans = 0;
        for (int i=0; i!=arr.size(); i++)
        {
            if (m.count(sum - arr[i]) != 0) ans += m[sum-arr[i]];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */