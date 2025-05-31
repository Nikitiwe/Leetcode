class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& e) {
        vector<int> arr(e.size(), 0);
        for (int i=0; i!=e.size(); i++)
        {
            arr[i] = stoi(e[i][1]);
        }
        vector<int> ans(n, 0), here(n, 1);
        priority_queue<pair<int, int>> q; // -время, id в e
        int c = 0, m = e.size();
        for (int i=0; i!=e.size(); i++)
        {
            if (e[i][0] == "MESSAGE") q.push({ - arr[i], i});
            else q.push({ - arr[i], i+m});
        }
        while (q.size() > 0)
        {
            int time = - q.top().first;
            int id = q.top().second;
            q.pop();
            if (id < m)
            {
                    string t;
                    for (int i=0; i!=e[id][2].size(); i++)
                    {
                        if (e[id][2][i] == ' ' || i+1 == e[id][2].size())
                        {
                            if (i+1 == e[id][2].size()) t += e[id][2][i];
                            if (t.size() > 0)
                            {
                                if (t == "ALL")
                                {
                                    c++;
                                }
                                else if (t == "HERE")
                                {
                                    for (int i=0; i!=n; i++) ans[i] += here[i];
                                }
                                else
                                {
                                    int add = 0;
                                    for (int j=2; j<t.size(); j++)
                                    {
                                        add *= 10;
                                        add += t[j] - '0';
                                    }
                                    ans[add]++;
                                }
                            }
                            t = "";
                        }
                        else t += e[id][2][i];
                    }
            }
            else if (id < 2*m)
            {
                here[stoi(e[id-m][2])] = 0;
                q.push({ - time - 60, id+m});
            }
            else here[stoi(e[id-2*m][2])] = 1;
        }
        for (int i=0; i!=n; i++) ans[i] += c;
        return ans;
    }
};