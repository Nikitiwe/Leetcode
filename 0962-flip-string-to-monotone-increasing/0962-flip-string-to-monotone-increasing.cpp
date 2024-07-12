class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int> zeror(s.size(), 0), onel(s.size(), 0);
        int temp=0;
        for (int i=0; i!=s.size()-1; i++)
        {
            if (s[i]=='1') temp++;
            onel[i+1]=temp;
        }
        if (temp==0) return 0;
        temp=0;
        for (int i=s.size()-1; i>=0; i--)
        {
            if (s[i]=='0') temp++;
            zeror[i]=temp;
        }
        temp=s.size();
        for (int i=0; i!=s.size(); i++)
        {
            temp=min(onel[i]+zeror[i], temp);
        }
        temp=min(onel[s.size()-1], temp);
        return temp;
    }
};