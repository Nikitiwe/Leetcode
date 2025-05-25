class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> arr;
        for (int i=0; i!=words.size(); i++)
        {
            arr[words[i]]++;
        }
        char a = 'a', b;
        int ans = 0, ans1 = 0, ans2 = 0;
        for (int i=0; i!=26; i++)
        {
            a = 'a' + i;
            for (int j=i+1; j<26; j++)
            {
                
                b = 'a' + j;
                string temp{a, b}, temp1{b, a};
                ans += min(arr[temp], arr[temp1]);
            }
        }
        for (int i=0; i!=26; i++)
        {
            a = 'a' + i;
            string temp{a, a};
            ans1 += arr[temp]/2;
            if (ans2 == 0 && arr[temp]%2 == 1) {ans2 = 1;}
        }
        return 4*ans + 4*ans1 + 2*ans2;
    }
};