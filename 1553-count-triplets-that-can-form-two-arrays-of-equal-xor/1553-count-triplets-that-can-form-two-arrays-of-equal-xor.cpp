class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0;
        for (int i=1; i<arr.size(); i++)
        {
            int l = 0, r =0;
            unordered_map<int, int> m;
            for (int j=i-1; j>=0; j--)
            {
                l ^= arr[j];
                m[l]++;
            }
            for (int j=i; j<arr.size(); j++)
            {
                r ^= arr[j];
                if (m.count(r) > 0) ans += m[r];
            }
        }
        return ans;
    }
};