class Solution {
public:
    int balancedString(string s) {
        vector<int> arr(4, 0);
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='Q') arr[0]++;
            else if (s[i]=='W') arr[1]++;
            else if (s[i]=='E') arr[2]++;
            else arr[3]++;
        }
        int n=s.size()/4;
        for (int i=0; i!=4; i++)
        {
            arr[i]-=n;
        }
        
        if (*max_element(arr.begin(), arr.end())<=0) return 0;
        int l=0, r=0, ans=s.size();
        if (s[0]=='Q') arr[0]--;
        else if (s[0]=='W') arr[1]--;
        else if (s[0]=='E') arr[2]--;
        else arr[3]--;
        if (*max_element(arr.begin(), arr.end())<=0) ans=min(ans, r-l+1);
        while (r<s.size())
        {
            if (*max_element(arr.begin(), arr.end())<=0)
            {
                ans=min(ans, r-l+1);
                if (s[l]=='Q') arr[0]++;
                else if (s[l]=='W') arr[1]++;
                else if (s[l]=='E') arr[2]++;
                else arr[3]++;
                l++;
            }
            else
            {
                r++;
                if (r==s.size()) break;
                if (s[r]=='Q') arr[0]--;
                else if (s[r]=='W') arr[1]--;
                else if (s[r]=='E') arr[2]--;
                else arr[3]--;
            }
        }
        return ans;
    }
};