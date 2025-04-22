class Solution {
public:
    long long appealSum(string s) {
        long long ans = 0;
        for (int k = 0; k!=26; k++) if (s.find('a' + k) != string::npos)
        {
            long long count = 0;
            vector<long long> arr;
            for (int i=0; i!=s.size(); i++)
            {
                if (s[i] == 'a' + k)
                {
                    arr.push_back(count + 1);
                    count = 0;
                }
                else count++;
            }
            arr.push_back(count + 1);
            long long sum = 0;
            for (int i=0; i!=arr.size(); i++) sum += arr[i];
            for (int i=0; i!=arr.size(); i++)
            {
                sum -= arr[i];
                ans += arr[i] * sum;
            }
        }
        return ans;
    }
};