class Solution {
public:
    int maxSubarrayLength(vector<int>& s, int k) {
        int ans=1, l=0, r=0, t=1;
        unordered_map<int, int> arr;
        arr[s[0]]++;
        while (r<s.size())
        {
            if (t<=k)
            {
                ans=max(ans, r-l+1);
                r++;
                if (r==s.size()) break;
                arr[s[r]]++;
                t=max(t, arr[s[r]]);
            }
            else
            {
                while (s[l]!=s[r])
                {
                    arr[s[l]]--;
                    l++;
                }
                arr[s[l]]--;
                l++;
                t=k;
                //for (auto i=arr.begin(); i!=arr.end(); i++) t=max(t, i->second);
            }
        }
        return ans;
    }
};