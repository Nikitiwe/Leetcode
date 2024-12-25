class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& s) {
        vector<vector<vector<int>>> arr(s.size(), vector<vector<int>> (26, vector<int> (26, 60000)));
        arr[0][s[0][0]-'a'][s[0].back()-'a']=s[0].size();
        for (int i=1; i<s.size(); i++)
        {
            for (int j=0; j!=26; j++)
            {
                for (int k=0; k!=26; k++)
                {
                    if (s[i].back()-'a'!=j) arr[i][s[i][0]-'a'][k]=min(arr[i-1][j][k]+(int)s[i].size(), arr[i][s[i][0]-'a'][k]);
                    else arr[i][s[i][0]-'a'][k]=min(arr[i-1][j][k]+(int)s[i].size()-1, arr[i][s[i][0]-'a'][k]);

                    if (s[i][0]-'a'!=k) arr[i][j][s[i].back()-'a']=min(arr[i-1][j][k]+(int)s[i].size(), arr[i][j][s[i].back()-'a']);
                    else arr[i][j][s[i].back()-'a']=min(arr[i-1][j][k]+(int)s[i].size()-1, arr[i][j][s[i].back()-'a']);
                }
            }
        }
        int ans=60000;
        for (int j=0; j!=26; j++)
        {
            for (int k=0; k!=26; k++)
            {
                ans=min(ans, arr[s.size()-1][j][k]);
            }
        }
        return ans;
    }
};