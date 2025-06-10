class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int> m;
        for (int i=0; i!=x.size(); i++)
        {
            m[x[i]] = max(m[x[i]], y[i]);
        }
        if (m.size() < 3) return -1;
        vector<int> arr;
        for (auto i = m.begin(); i!=m.end(); i++) arr.push_back(i->second);
        sort(arr.rbegin(), arr.rend());
        return arr[0] + arr[1] + arr[2];
    }
};