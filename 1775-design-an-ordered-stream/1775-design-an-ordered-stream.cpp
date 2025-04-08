class OrderedStream {
public:
    vector<string> arr;
    int id;
    OrderedStream(int n) {
        for (int i=0; i!=n; i++) arr.push_back("");
        id = 0;
    }
    
    vector<string> insert(int idKey, string v) {
        vector<string> ans;
        arr[idKey-1] = v;
        while (id < arr.size() && arr[id] != "")
        {
            ans.push_back(arr[id]);
            id++;
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */