class Solution {
public:
    string oddString(vector<string>& s) {
        vector<vector<int>> arr;
        int c = 1;
        for (int i=0; i!=s.size(); i++)
        {
            vector<int> t;
            for (int j=0; j+1<s[i].size(); j++) t.push_back(s[i][j+1] - s[i][j]);
            arr.push_back(t);
        }
        for (int i=1; i+1<arr.size(); i++) if (arr[i-1] != arr[i] && arr[i] != arr[i+1]) return s[i];
        if (arr[0] != arr[1] && arr[0] != arr[2]) return s[0];
        return s.back();
    }
};