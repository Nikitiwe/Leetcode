class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> bl(s.size()+1, 0), ar(s.size()+1, 0);
        int temp=0, ans=s.size();
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='b') temp++;
            bl[i+1]=temp;
        }
        temp=0;
        for (int i=s.size()-1; i>=0; i--)
        {
            if (s[i]=='a') temp++;
            ar[i]=temp;
        }
        for (int i=0; i!=s.size()+1; i++)
        {
            ans=min(ans, bl[i]+ar[i]);
        }
        return ans;
    }
};