class Solution {
public:
    int minDeletions(string s) {
        vector<int> arr(26, 0);
        for (int i=0; i!=s.size(); i++)
        {
            arr[s[i]-'a']++;
        }
        sort(arr.begin(), arr.end());
        int ans=0;
        for (int i=25; i>0; i--)
        {
            while (arr[i-1]>=arr[i]&&arr[i-1]>0)
            {
                arr[i-1]--;
                ans++;
            }
        }
        return ans;
    }
};