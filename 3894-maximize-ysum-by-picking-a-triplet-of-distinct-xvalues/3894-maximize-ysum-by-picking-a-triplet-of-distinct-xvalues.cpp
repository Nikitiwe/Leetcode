class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int> m;
        for (int i=0; i!=x.size(); i++)
        {
            m[x[i]] = max(m[x[i]], y[i]);
        }
        if (m.size() < 3) return -1;
        vector<int> arr(3, 0);
        for (auto i = m.begin(); i!=m.end(); i++)
        {
            if (i->second >= arr[0])
            {
                arr[2] = arr[1];
                arr[1] = arr[0];
                arr[0] = i->second;
            }
            else if (i->second >= arr[1])
            {
                arr[2] = arr[1];
                arr[1] = i->second;
            }
            else if (i->second >= arr[2])
            {
                arr[2] = i->second;
            }
        }
        return arr[0] + arr[1] + arr[2];
    }
};