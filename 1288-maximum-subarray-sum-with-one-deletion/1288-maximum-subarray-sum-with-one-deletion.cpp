class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int ans = arr[0];
        int sum = arr[0], sump = 0;
        for (int i=1; i<arr.size(); i++)
        {
            sump = max(sump + arr[i], sum);
            sum += arr[i];
            sum = max(sum, arr[i]);
            ans = max(ans, sum);
            ans = max(ans, sump);
        }
        return ans;
    }
};