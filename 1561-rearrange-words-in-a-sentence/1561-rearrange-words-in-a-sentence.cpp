    

class Solution {
public:
    static bool ssort (const string &a, const string &b)
    {
        return a.size() < b.size();
    }

    string arrangeWords(string s) {
        vector<string> arr;
        string t;
        t += tolower(s[0]);
        s += ' ';
        for (int i=1; i!=s.size(); i++)
        {
            if (s[i] == ' ')
            {
                arr.push_back(t);
                t = "";
            }
            else t += s[i];
        }
        stable_sort(arr.begin(), arr.end(), ssort);
        
        string ans;
        for (int i=0; i!=arr.size(); i++)
        {
            if (ans.size() > 0) ans += ' ';
            ans += arr[i];
        }
        ans[0] = toupper(ans[0]);
        return ans;
    }
};

//stable_sort(arr.begin(), arr.end());