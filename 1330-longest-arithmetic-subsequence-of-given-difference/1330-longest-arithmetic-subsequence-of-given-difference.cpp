class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> m;
        int t, ans=1;
        for (int i=0; i!=arr.size(); i++)
        {
            t=1;
            if (m.count(arr[i]-difference) > 0) {t=m[arr[i]-difference]+1; ans=max(ans, t);}
            if (m.count(arr[i]) == 0) m.insert(make_pair(arr[i], t));
            else m[arr[i]] = max(m[arr[i]], t);
        }
        return ans;
    }
};