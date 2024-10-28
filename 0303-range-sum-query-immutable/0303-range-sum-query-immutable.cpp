class NumArray {
private:
    vector<int> arr;
public:
    NumArray(vector<int>& nums) {
        int t=0;
        arr.push_back(t);
        for (int i=0; i!=nums.size(); i++)
        {
            t+=nums[i];
            arr.push_back(t);
        }
    }
    
    int sumRange(int l, int r) {
        return arr[r+1]-arr[l];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */