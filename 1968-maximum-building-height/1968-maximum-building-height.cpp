class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& r) {
        sort(r.begin(), r.end());
        vector<vector<int>> arr;
        arr.push_back({1, 0});
        for (int i=0; i!=r.size(); i++)
        {
            int x = r[i][0], y = r[i][1];
            while (arr[arr.size()-1][0] + arr[arr.size()-1][1] >= x + y) arr.pop_back();
            arr.push_back({x, y});
        }
        vector<vector<int>> arr2;
        for (int i=arr.size()-1; i>=0; i--)
        {
            int x = arr[i][0], y = arr[i][1];
            while (arr2.size() > 0 && arr2[arr2.size()-1][1] - arr2[arr2.size()-1][0] >= y - x) arr2.pop_back();
            arr2.push_back({x, y});
        }
        /*stack<pair<int, int>> s;
        s.push({0, 0});*/
        int ans = 0;
        reverse(arr2.begin(), arr2.end());
        //return arr2.size();
        for (int i=0; i<arr2.size()-1; i++)
        {
            ans = max(ans, (arr2[i][1] + arr2[i+1][0] - arr2[i][0] + arr2[i+1][1])/2);
        }
        ans = max(ans, (arr2[arr2.size()-1][1] + n - arr2[arr2.size()-1][0]));
        return ans;
    }
};