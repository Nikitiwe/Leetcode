class Solution {
public:
    int numSub(string s) {
        int ans;
        long count=0, an=0;
        for (int i=0; i!=s.size()-1; i++)
        {
            if (s[i]=='1') count++;
            else {an=an+count*(count+1)/2; count=0;}
        }
        if (s[s.size()-1]=='1') {count++; an=an+count*(count+1)/2;}
        else {an=an+count*(count+1)/2;}
        ans=an%1000000007;
        return ans;
    }
};