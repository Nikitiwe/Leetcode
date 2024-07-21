class Solution {
public:
    int maxOperations(string s) {
        vector<int> count;
        int ans=0, one=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='1') one++;
            else if (s[i]=='0'&&one!=0) {count.push_back(one); one=0;}
        }
        one=0;
        for (int i=0; i!=count.size(); i++)
        {
            one+=count[i];
            ans+=one;
        }
        return ans;
    }
};