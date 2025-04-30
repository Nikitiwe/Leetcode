class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        map<int, int> m;
        int ans = 0;
        for (int i=0; i!=arr.size(); i++) m[arr[i][0]]++;
        for (int i=0; i!=arr.size(); i++)
        {
            m[arr[i][0]]--;
            if (m[arr[i][0]] == 0) m.erase(arr[i][0]);
            ans = max(ans, arr[i].back() - m.begin()->first);
            m[arr[i][0]]++;
        }
        return ans;
    }
};