class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>> m;
        int t=k;
        for (int i=0; i!=nums1.size(); i++)
        {
            for (int j=0; j!=nums2.size(); j++)
            {
                m.push({-nums1[i]-nums2[j], {nums1[i], nums2[j]}});
                if (j>t) break;
            }
            t=k/(i+2)+1;
        }
        vector<vector<int>> ans;
        for (int i=0; i!=k; i++)
        {
            ans.push_back({m.top().second.first, m.top().second.second});
            m.pop();
        }
        return ans;
    }
};