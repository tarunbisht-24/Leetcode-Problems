class NestedIterator {
public:
    int j = 0, n = 0;
    vector<int> v;
    void flatten(NestedInteger x){
        if (x.isInteger()) 
            v.push_back(x.getInteger());
        else 
            for (auto &&y : x.getList())
                flatten(y);
    }
    
    NestedIterator(vector<NestedInteger> &A) {
        for(auto &&i : A){
            flatten(i);
        }
        n = v.size();
    }

    int next() {
        j++;
        return v[j-1];
    }
    
    bool hasNext() {
        if(j == n) return false;
        return true;
    }
};
