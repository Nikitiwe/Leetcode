class Solution {
public:
    bool checkIfPangram(string s) {
        vector<int> arr(26, 0);
        for (int i=0; i!=s.size(); i++)
        {
            arr[s[i]-'a']++;
        }
        for (int i=0; i!=26; i++)
        {
            if (arr[i]==0) return 0;
        }
        return 1;
    }
};