class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> m(nums1.begin(), nums1.end());
        vector<vector<int>> arr(nums2.size(), vector<int> (2, 0));
        for (int i=0; i!=nums2.size(); i++)
        {
            arr[i][0]=nums2[i];
            arr[i][1]=i;
        }
        sort(arr.begin(), arr.end());
        vector<int> ans(nums1.size(), -1);
        for (int i=arr.size()-1; i>=0; i--)
        {
            if (m.top()>arr[i][0])
            {
                ans[arr[i][1]]=m.top();
                m.pop();
            }
        }
        for (int i=0; i!=ans.size(); i++)
        {
            if (ans[i]==-1)
            {
                ans[i]=m.top();
                m.pop();
            }
        }
        return ans;
    }
};