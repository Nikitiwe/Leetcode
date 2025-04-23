class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        vector<vector<int>> arr(nums1.size(), vector<int>(2, 0));
        for (int i=0; i!=nums1.size(); i++)
        {
            arr[i][0] = nums2[i];
            arr[i][1] = nums1[i];
        }
        sort(arr.rbegin(), arr.rend());
        long long mi = 1000000;
        long long sum = 0;
        priority_queue<int> q;
        for (int i=0; i<k; i++)
        {
            q.push( - arr[i][1]);
            sum += arr[i][1];
            mi = arr[i][0];
        }
        ans = max(ans, mi * sum);
        for (int i=k; i<arr.size(); i++)
        {
            sum += q.top();
            q.pop();
            q.push( - arr[i][1]);
            sum += arr[i][1];
            mi = arr[i][0];
            ans = max(ans, mi * sum);
        }
        return ans;
    }
};