class Solution {
public:
    char slowestKey(vector<int>& t, string s) {
        vector<int> arr(26, 0);
        for (int i=1; i<s.size(); i++)
        {
            arr[s[i]-'a']=max(t[i]-t[i-1], arr[s[i]-'a']);
        }
        arr[s[0]-'a']=max(t[0], arr[s[0]-'a']);
        int a=*max_element(arr.begin(), arr.end());
        for (int i=25; i>=0; i--) if (arr[i]==a) return 'a'+i;
        return 'a'-1;
    }
};