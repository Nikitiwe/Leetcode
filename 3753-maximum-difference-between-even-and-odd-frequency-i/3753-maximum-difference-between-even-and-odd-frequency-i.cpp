class Solution {
public:
    int maxDifference(string s) {
        vector<int> arr(26, 0);
        for (int i=0; i!=s.size(); i++)
        {
            arr[s[i]-'a']++;
        }
        int mi = 1000000, ma = -1000000;
        for (int i=0; i!=26; i++)
        {
            if (arr[i] != 0 && arr[i]%2==0) mi = min(mi, arr[i]);
            else if (arr[i] != 0 && arr[i]%2==1) ma = max(ma, arr[i]);
        }
        return ma - mi;
    }
};