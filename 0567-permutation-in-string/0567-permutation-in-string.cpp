class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size()>s2.size()) return 0;
        vector<int> arr1(26, 0), arr2(26, 0);
        int i=0;
        for (i; i!=s1.size(); i++)
        {
            arr1[s1[i]-'a']++;
            arr2[s2[i]-'a']++;
        }
        for (i; i<s2.size(); i++)
        {
            if (arr1==arr2) return 1;
            arr2[s2[i]-'a']++;
            arr2[s2[i-s1.size()]-'a']--;
        }
        if (arr1==arr2) return 1;
        return 0;
    }
};