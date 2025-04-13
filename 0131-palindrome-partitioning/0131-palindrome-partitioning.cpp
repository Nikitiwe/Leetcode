class Solution {
public:
    bool ispal(string &s)
    {
        bool res = 1;
        for (int i=0; i<s.size()/2; i++)
        {
            if (s[i] != s[s.size()-1-i])
            {
                res = 0;
                break;
            }
        }
        return res;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<vector<string>>> ans(s.size(), vector<vector<string>>());
        ans[0].push_back({string(1, s[0])});
        int n = s.size();
        /*for (int i=1; i<s.size(); i++)
        {
            for (int j=i; j<s.size(); j++)
            {
                string t = s.substr(i, j-i+1);
                if (ispal(t) == 1)
                {
                    for (int k = 0; k!=ans[i-1].size(); k++)
                    {
                        ans[j].push_back(ans[i-1][k] + t);
                    }
                }
            }
        }*/
        for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            string current = s.substr(j, i - j + 1); // Подстрока s[j..i]
            if (ispal(current)) { // Если текущая подстрока является палиндромом
                if (j == 0) {
                    // Если это весь префикс, добавляем его как отдельное разбиение
                    ans[i].push_back({current});
                } else {
                    // Добавляем current к каждому разбиению из ans[j-1]
                    for (auto &partition : ans[j - 1]) {
                        vector<string> new_partition = partition;
                        new_partition.push_back(current);
                        ans[i].push_back(new_partition);
                    }
                }
            }
        }
    }
        return ans.back();
    }
};