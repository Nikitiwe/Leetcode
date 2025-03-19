class Solution {
public:
    string reorganizeString(string s) {
        vector<int> arr(26, 0);
        for (int i=0; i!=s.size(); i++) arr[s[i]-'a']++;
        vector<int> b = arr;
        sort(arr.rbegin(), arr.rend());
        if (arr[0]>(s.size()+1)/2) return "";
        unordered_set<int> d;
        unordered_map<int, int> m;
        for (int i=0; i!=26; i++)
        {
            for (int j=0; j!=26; j++)
            {
                if (b[i]==arr[j] && d.count(j) == 0)
                {
                    m[j] = i;
                    d.insert(j);
                    break;
                }
            }
        }
        int l=0;
        for (int i=0; i<s.size(); i+=2)
        {
            while (arr[l]==0) l++;
            s[i] = 'a' + m[l];
            arr[l]--;
        }
        for (int i=1; i<s.size(); i+=2)
        {
            while (arr[l]==0) l++;
            s[i] = 'a' + m[l];
            arr[l]--;
        }
        return s;
    }
};