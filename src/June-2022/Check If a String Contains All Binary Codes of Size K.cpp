class Solution {
public:
    bool hasAllCodes(string s, int k) {
         unordered_set<string> ds;

    for (int i = 0; i < s.size(); i++)
    {
        string temp = s.substr(i, k);
        if (temp.size() == k)
        {
            ds.insert(temp);
        }
    }

    if (ds.size() == pow(2, k))
    {
        return true;
    }

    return false;
    }
};
