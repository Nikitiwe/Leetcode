class Solution {
public:
    int maximumLength(string s) {
        vector<vector<int>> arr(26, vector<int>(3, -1));
        int ans=-1, t=1;
        arr[s[0]-'a'][0]=1;
        for (int i=1; i<s.size(); i++)
        {
            if (s[i]==s[i-1])
            {
                t++;
                if (t>=arr[s[i]-'a'][0])
                {
                    arr[s[i]-'a'][2]=arr[s[i]-'a'][1];
                    arr[s[i]-'a'][1]=arr[s[i]-'a'][0];
                    arr[s[i]-'a'][0]=t;
                }
                else if (t>=arr[s[i]-'a'][1])
                {
                    arr[s[i]-'a'][2]=arr[s[i]-'a'][1];
                    arr[s[i]-'a'][1]=t;
                }
                else if (t>=arr[s[i]-'a'][2])
                {
                    arr[s[i]-'a'][2]=t;
                }
            }
            else
            {
                t=1;
                if (t>=arr[s[i]-'a'][0])
                {
                    arr[s[i]-'a'][2]=arr[s[i]-'a'][1];
                    arr[s[i]-'a'][1]=arr[s[i]-'a'][0];
                    arr[s[i]-'a'][0]=t;
                }
                else if (t>=arr[s[i]-'a'][1])
                {
                    arr[s[i]-'a'][2]=arr[s[i]-'a'][1];
                    arr[s[i]-'a'][1]=t;
                }
                else if (t>=arr[s[i]-'a'][2])
                {
                    arr[s[i]-'a'][2]=t;
                }
            }
        }
        for (int i=0; i!=arr.size(); i++)
        {
            ans=max(ans, arr[i][2]);
        }
        return ans;
    }
};