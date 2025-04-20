class Solution {
public:
    string rankTeams(vector<string>& v) {
        vector<vector<int>> arr(26, vector<int> (v[0].size(), 0));
        vector<bool> u(26, 0);
        for (int i=0; i!=v.size(); i++)
        {
            for (int j=0; j!=v[i].size(); j++)
            {
                arr[v[i][j] - 'A'][j]++;
                u[v[i][j] - 'A'] = 1;
            }
        }
        string ans;
        for (int i=0; i!=v[0].size(); i++)
        {
            int id = 0;
            for (int j=0; j!=26; j++)
            {
                if (u[j] == 1)
                {
                    id = j;
                    break;
                }
            }
            for (int j=0; j<26; j++)
            {
                if (u[j] == 1)
                {
                    if (arr[j] > arr[id]) id = j;
                }
            }
            ans += 'A' + id;
            u[id] = 0;
        }
        return ans;
    }
};