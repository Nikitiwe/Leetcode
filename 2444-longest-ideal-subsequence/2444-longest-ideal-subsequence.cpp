class Solution {
public:
    int longestIdealString(string s, int k) {
        if (s.size()==1) return 1;
        int m=1;
        vector<int> row(26, 0);
        vector<vector<int>> arr(s.size(), row);
        arr[0][s[0]-'a']++;
        for (int i=1; i!=s.size(); i++)
        {
            for (int j=0; j!=26; j++)
            {
                if (abs('a'+j-s[i])<=k) {arr[i][s[i]-'a']=max(arr[i-1][j]+1, arr[i][s[i]-'a']); m=max(m, arr[i][s[i]-'a']);}
                arr[i][j]=max(arr[i-1][j], arr[i][j]);
            }
        }
        return m;
    }
};