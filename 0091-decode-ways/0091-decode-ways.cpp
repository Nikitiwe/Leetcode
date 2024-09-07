class Solution {
public:
    int numDecodings(string s) {
        vector<int> arr(s.size(), 0);
        if (s[0]=='0') return 0;
        else arr[0]=1;
        if (s.size()==1) return 1;
        if ((s[0]-'0')*10+(s[1]-'0')<=26) arr[1]=1;
        if (s[1]!='0') arr[1]+=arr[0];
        for (int i=2; i<s.size(); i++)
        {
            if (s[i]!='0') arr[i]+=arr[i-1];
            if (s[i-1]!='0'&&(s[i-1]-'0')*10+(s[i]-'0')<=26) arr[i]+=arr[i-2];
            if (arr[i]==0) return 0;
        }
        return arr[arr.size()-1];
    }
};