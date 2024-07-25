class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<bool> arr(words.size(), 0);
        vector<int> ans(queries.size(), 0), sum(words.size()+1, 0);
        for (int i=0; i!=arr.size(); i++)
        {
            if ((words[i][0]=='a'||words[i][0]=='o'||words[i][0]=='i'||words[i][0]=='e'||words[i][0]=='u')&&(words[i][words[i].size()-1]=='a'||words[i][words[i].size()-1]=='o'||words[i][words[i].size()-1]=='i'||words[i][words[i].size()-1]=='e'||words[i][words[i].size()-1]=='u')) arr[i]=1;
        }
        for (int i=1; i!=sum.size(); i++)
        {
            sum[i]=sum[i-1]+arr[i-1];
        }
        for (int i=0; i!=queries.size(); i++)
        {
            ans[i]=sum[queries[i][1]+1]-sum[queries[i][0]];
        }
        return ans;
    }
};