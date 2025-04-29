class Solution {
public:
    int minJumps(vector<int>& arr) {
        vector<int> isit(arr.size(), -1);
        vector<vector<int>> s(arr.size(), vector<int>());
        unordered_map<int, int> f; // переводит число в индеекс в s
        int a = 0;
        for (int i=0; i!=arr.size(); i++)
        {
            if (f.count(arr[i]) == 0)
            {
                f[arr[i]] = a;
                a++;
            }
            s[f[arr[i]]].push_back(i);
        }
        isit[0] = 0;
        queue<int> id;
        id.push(0);
        while (id.size() > 0)
        {
            int i = id.front();
            id.pop();
            if (i > 0 && isit[i-1] == -1)
            {
                isit[i-1] = isit[i] + 1;
                id.push(i-1);
            }
            if (i+1 < arr.size() && isit[i+1] == -1)
            {
                isit[i+1] = isit[i] + 1;
                id.push(i+1);
            }
            if (s[f[arr[i]]].size() > 0)
            {
                for (int j=s[f[arr[i]]].size()-1; j>=0; j--)
                {
                    if (isit[s[f[arr[i]]][j]] == -1)
                    {
                        isit[s[f[arr[i]]][j]] = isit[i] + 1;
                        id.push(s[f[arr[i]]][j]);
                    }
                }
                s[f[arr[i]]].clear();
            }
            if (isit[arr.size()-1] != -1) return isit[arr.size()-1];
        }
        return -1;
    }
};