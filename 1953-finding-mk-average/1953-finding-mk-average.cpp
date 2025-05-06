class MKAverage {
public:
    vector<int> nums;
    int s, k, c;
    long sum;
    multiset<int> l, r, m;
    MKAverage(int mm, int kk) {
        s = mm;
        k = kk;
        c = 0;
        sum = 0;
    }
    
    void addElement(int num) {
        if (c < s)
        {
            nums.push_back(num);
            if (c == s - 1)
            {
                vector<int> t = nums;
                sort(t.begin(), t.end());
                for (int i=0; i<k; i++) l.insert(t[i]);
                for (int i=k; i<s-k; i++)
                {
                    m.insert(t[i]);
                    sum += t[i];
                }
                for (int i=s-k; i<s; i++) r.insert(t[i]);
            }
        }
        else
        {
            nums.push_back(num);
            if (l.count(nums[c-s]) != 0)
            {
                l.erase(l.find(nums[c-s]));
                int t = *m.begin();
                if (nums[c] <= t) l.insert(nums[c]);
                else
                {
                    l.insert(t);
                    m.erase(m.find(t));
                    sum -= t;
                    int tt = *r.begin();
                    if (nums[c] <= tt)
                    {
                        m.insert(nums[c]);
                        sum += nums[c];
                    }
                    else
                    {
                        m.insert(tt);
                        r.erase(r.find(tt));
                        sum += tt;
                        r.insert(nums[c]);
                    }
                }
            }
            else if (m.count(nums[c-s]) != 0)
            {
                int t = *m.begin();
                if (nums[c] <= t)
                {
                    l.insert(nums[c]);
                    int tt = *l.rbegin();
                    l.erase(l.find(tt));
                    m.insert(tt);
                    sum += tt;
                }
                else
                {
                    int tt = *r.begin();
                    if (nums[c] <= tt)
                    {
                        m.insert(nums[c]);
                        sum += nums[c];
                    }
                    else
                    {
                        m.insert(tt);
                        r.erase(r.find(tt));
                        sum += tt;
                        r.insert(nums[c]);
                    }
                }
                m.erase(m.find(nums[c-s]));
                sum -= nums[c-s];
            }
            else
            {
                int t = *m.begin();
                if (nums[c] <= t)
                {
                    l.insert(nums[c]);
                    int tt = *l.rbegin();
                    l.erase(l.find(tt));
                    m.insert(tt);
                    sum += tt;
                    int ttt = *m.rbegin();
                    m.erase(m.find(ttt));
                    sum -= ttt;
                    r.insert(ttt);
                }
                else
                {
                    int tt = *r.begin();
                    if (nums[c] <= tt)
                    {
                        m.insert(nums[c]);
                        sum += nums[c];
                        int ttt = *m.rbegin();
                        m.erase(m.find(ttt));
                        sum -= ttt;
                        r.insert(ttt);
                    }
                    else r.insert(nums[c]);
                }
                r.erase(r.find(nums[c-s]));
            }
        }
        c++;
    }
    
    int calculateMKAverage() {
        if (c < s) return -1;
        return sum / (s-2*k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */