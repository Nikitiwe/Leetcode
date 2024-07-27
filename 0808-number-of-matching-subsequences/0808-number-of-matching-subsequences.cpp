class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0, l;
        unordered_map<string, int> m;
        string a;
        for (int i=0; i!=words.size(); i++)
        {
            if (m.count(words[i])==0) m[words[i]]=1;
            else m[words[i]]++;
        }
        for (auto it=m.begin(); it!=m.end(); it++)
        {
            l=0;
            a=it->first;
            for (int j=0; j!=s.size(); j++)
            {
                if (a[l]==s[j]) l++;
                if (l==a.size()) {ans+=it->second ; break;}
            }
        }
        return ans;
    }
}; //Time Limit Exceeded 45/53 testcases passed