class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        vector<long long> ans(arr.size(), 0);
        unordered_map<int, long long> lastid, count, temp;
        for (int i=0; i!=arr.size(); i++)
        {
            temp[arr[i]] += (i - lastid[arr[i]]) * count[arr[i]];
            count[arr[i]]++;
            lastid[arr[i]] = i;
            ans[i] += temp[arr[i]];
        }
        {
            unordered_map<int, long long> lastid, count, temp;
            for (int i=arr.size()-1; i>=0; i--)
            {
                temp[arr[i]] += (lastid[arr[i]] - i) * count[arr[i]];
                count[arr[i]]++;
                lastid[arr[i]] = i;
                ans[i] += temp[arr[i]];
            }
        }
        return ans;
    }
};