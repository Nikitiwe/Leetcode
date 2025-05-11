/*bool ssort(vector<int> &a, vector<int> &b)
{
    
}*/

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& r, vector<vector<int>>& p) {
        vector<int> ans(p.size(), 0);
        vector<int> v(101, 0);
        vector<vector<int>> arr(p.size(), vector<int>(3, 0));
        for (int i=0; i!=p.size(); i++)
        {
            arr[i][0] = p[i][0];
            arr[i][1] = p[i][1];
            arr[i][2] = i;
        }
        sort(arr.begin(), arr.end());
        sort(r.begin(), r.end());
        int id = r.size()-1;
        for (int i=arr.size()-1; i>=0; i--)
        {
            vector<int> t(101, 0);
            while (id >= 0 && r[id][0] >= arr[i][0])
            {
                t[r[id][1]]++;
                id--;
            }
            for (int j = 100; j >= 1; j--)
            {
                t[j-1] += t[j];
                v[j] += t[j];
            }
            ans[arr[i][2]] = v[arr[i][1]];
        }
        return ans;
    }
};