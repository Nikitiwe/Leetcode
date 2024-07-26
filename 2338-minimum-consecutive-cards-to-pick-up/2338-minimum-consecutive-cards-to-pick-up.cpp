class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans=100001, l=0, r=0;
        unordered_map<int, int> m;
        m[cards[0]]=1;
        while (r<cards.size())
        {
            if (m[cards[r]]>1)
            {
                ans=min(ans, r-l+1);
                /*if (m[cards[l]]>1) m[cards[l]]=1;
                else m.erase(cards[l]);*/
                m[cards[l]]--;
                l++;
            }
            else
            {
                if (r==cards.size()-1) break;
                r++;
                if (m.count(cards[r])==0) {m[cards[r]]=1;}
                else {m[cards[r]]++; ans=min(ans, r-l+1);}
            }
        }
        if (ans==100001) return -1;
        return ans;
    }
};