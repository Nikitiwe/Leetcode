class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> arr;
        int c = 0;
        if (s[0] == '1') arr.push_back(0);
        if (s.back() == '1') s += '0';
        else s += '1';
        int ans = 0, sum = 0;
        for (int i=0; i!=s.size(); i++)
        {
            //if (i > 0 && ( (s[i] != s[i-1]) || i+1 == arr.size() ) )
            if (i > 0 && (s[i] != s[i-1]) )
            {
                arr.push_back(c);
                c = 0;
                if (arr.size() % 2 == 0 && arr.size() > 0) sum += arr.back();
            }
            c++;
        }
        if (arr.size() > 2 && arr[0] > 0)
        {
            int add = arr[0] + arr[2];
            ans = max(ans, add);
        }
        if (arr.size() > 2) for (int i=3; i+1<arr.size(); i += 2)
        {
            int add = arr[i-1] + arr[i+1];
            ans = max(ans, add);
        }
        return sum + ans;
    }
};