class Solution {
public:
    vector<string> commonChars(vector<string>& w) {
        vector<int> arr(26, 100);
        for (int i=0; i!=w.size(); i++)
        {
            vector<int> t(26, 0);
            for (int j=0; j!=w[i].size(); j++)
            {
                t[w[i][j]-'a']++;
            }
            for (int i=0; i!=26; i++) arr[i]=min(t[i], arr[i]);
        }
        vector<string> ans;
        for (int i=0; i!=26; i++)
        {
            if (arr[i]>0)
            {
                string s;
                s+='a'+i;
                while (arr[i]>0)
                {
                    ans.push_back(s);
                    arr[i]--;
                }
            }
        }
        return ans;
    }
};