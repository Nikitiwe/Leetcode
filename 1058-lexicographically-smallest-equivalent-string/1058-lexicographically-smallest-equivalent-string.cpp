class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<string> arr(26, "");
        for (int i=0; i!=26; i++) arr[i] += 'a' + i;
        for (int i=0; i!=s1.size(); i++)
        {
            arr[s1[i] - 'a'] += s2[i];
        }
        for (int k=0; k<26; k++)
        {
            for (int c=0; c<26; c++)
            {
                vector<bool> isit(26, 0);
                vector<bool> v(26, 0);
                for (int i=0; i!=26; i++)
                {
                    for (int j=0; j<arr[i].size(); j++)
                    {
                        if (arr[i][j] == c + 'a')
                        {
                            isit[i] = 1;
                            break;
                        }
                    }
                }
                for (int i=0; i!=26; i++) if (isit[i] == 1)
                {
                    for (int j=0; j<arr[i].size(); j++)
                    {
                        v[arr[i][j] - 'a'] = 1;
                    }
                }
                string t;
                for (int j=0; j<26; j++)
                {
                    if (v[j] == 1) t += 'a' + j;
                }
                for (int i=0; i!=26; i++) if (isit[i] == 1)
                {
                    arr[i] = t;
                }
            }
        }
        string ans;
        for (int i=0; i!=baseStr.size(); i++)
        {
            ans += arr[baseStr[i] - 'a'][0];
        }
        return ans;
    }
};