class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> arr;
        int z=0, o=0;
        if (s[0]=='0') z++;
        else o++;
        for (int i=1; i<s.size(); i++)
        {
            if (s[i]=='0')
            {
                if (z>0) z++;
                else
                {
                    arr.push_back(o);
                    o=0;
                    z++;
                }
            }
            else
            {
                if (o>0) o++;
                else
                {
                    arr.push_back(z);
                    z=0;
                    o++;
                }
            }
        }
        arr.push_back(max(z, o));
        int ans=0;
        for (int i=1; i<arr.size(); i++)
        {
            ans+=min(arr[i], arr[i-1]);
        }
        return ans;
    }
};