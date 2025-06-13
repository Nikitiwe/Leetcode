class ExamRoom {
public:
    set<int> s;
    int n;

    ExamRoom(int nn) {
        n = nn;
    }
    
    int seat() {
        if (s.size() == 0)
        {
            s.insert(0);
            return 0;
        }
        else
        {
            int l = -1, id = -1, d = 0;
            for (auto i = s.begin(); i!=s.end(); i++)
            {
                int t = *i - l;
                int dist;
                if (l == -1)
                {
                    dist = t - 1;
                }
                else dist = (*i + l)/2 - l;
                if (dist > 0)
                {
                    if (dist > d)
                    {
                        d = dist;
                        if (l == -1)
                        {
                            id = 0;
                        }
                        else id = l + d;
                    }
                }
                l = *i;
            }
            {
                int t = n - l - 1;
                int dist = t;
                if (dist > d)
                {
                    d = dist;
                    id = l + d;
                }
            }
            s.insert(id);
            return id;
        }
    }
    
    void leave(int p) {
        s.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */