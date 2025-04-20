class KthLargest {
public:
    vector<int> arr;
    int k;
    KthLargest(int kk, vector<int>& nums) {
        arr = nums;
        if (arr.size() > 0) sort(arr.rbegin(), arr.rend());
        k = kk - 1;
        while (arr.size() > k + 1) arr.pop_back();
    }
    
    int add(int val) {
        arr.push_back(val);
        {
            for (int i=arr.size()-1; i>=1; i--)
            {
                if (arr[i-1] < arr[i]) swap(arr[i-1], arr[i]);
                else break;
            }
        }
        while (arr.size() > k + 1) arr.pop_back();
        return arr[k];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */