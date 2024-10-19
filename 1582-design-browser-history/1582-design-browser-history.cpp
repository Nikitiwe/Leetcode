class BrowserHistory {
private:
vector<string> arr;
int id, idm;

public:
    BrowserHistory(string homepage) {
        arr.push_back(homepage);
        id=0;
        idm=0;

    }
    
    void visit(string url) {
        id++;
        if (id<=idm)
        {
            arr[id]=url;
            idm=id;
        }
        else
        {
            arr.push_back(url);
            idm=id;
        }
        arr.erase(arr.begin()+id+1, arr.end());       
    }
    
    string back(int s) {
        if (s>id)
        {
            id=0;
            return arr[id];
        }
        else
        {
            id-=s;
            return arr[id];
        }

    }
    
    string forward(int s) {
        if (s+id>=idm)
        {
            id=idm;
            return arr[id];
        }
        else
        {
            id+=s;
            return arr[id];
        }
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */