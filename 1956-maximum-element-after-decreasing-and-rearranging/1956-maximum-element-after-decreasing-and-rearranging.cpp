class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0]=1;
        for (int i=1; i!=arr.size(); i++)
        {
            arr[i]=min(arr[i-1]+1, arr[i]);
        }
        return arr[arr.size()-1];
    }
};