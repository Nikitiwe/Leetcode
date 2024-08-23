class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans=0;
        vector<vector<int>> arr(26, vector<int> (2, -1));
        for (int j=0; j!=word.size(); j++)
        {
            if (word[j]>='a'&&word[j]<='z') arr[word[j]-'a'][0]=j;
            else if (arr[word[j]-'A'][1]==-1) arr[word[j]-'A'][1]=j;
        }
        for (int i=0; i!=26; i++)
        {
            if (arr[i][0]!=-1&&arr[i][1]!=-1&&arr[i][0]<arr[i][1]) ans++;
        }
        return ans;
    }
};