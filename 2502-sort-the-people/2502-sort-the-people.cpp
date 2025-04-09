class Solution {
public:
    vector<string> sortPeople(vector<string>& n, vector<int>& h) {
        vector<pair<int, string>> arr;
        for (int i=0; i!=n.size(); i++) arr.push_back({h[i], n[i]});
        sort(arr.rbegin(), arr.rend());
        vector<string> ans;
        for (int i=0; i!=n.size(); i++) ans.push_back(arr[i].second);
        return ans;
    }
};