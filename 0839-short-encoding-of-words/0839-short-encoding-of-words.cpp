bool ssort (string a, string b)
{
    return a.size()>b.size();
}

class Solution {
public:
    int minimumLengthEncoding(vector<string>& s) {
        sort(s.begin(), s.end(), ssort);
        int ans=s[0].size()+1;
        for (int i=1; i<s.size(); i++)
        {
            bool isit=0;
            for (int j=0; j<i; j++)
            {
                int r=1;
                while (r<=s[i].size()&&s[i][s[i].size()-r]==s[j][s[j].size()-r]) r++;
                if (r>s[i].size())
                {
                    isit=1;
                    break;
                }
            }
            if (isit==0) ans+=s[i].size()+1;
        }
        return ans;
    }
};