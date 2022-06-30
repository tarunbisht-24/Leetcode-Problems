class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> a;
        stack<char> b;
        bool flag = true;
        for(auto ch: s){
            if(ch == '#'){
                if(a.empty()){
                    continue;
                }else{
                    a.pop();
                }
            }
            else{
                a.push(ch);
            }
        }
        for(auto ch: t){
            if(ch == '#'){
                if(b.empty()){
                    continue;
                }else{
                    b.pop();
                }
            }
            else{
                b.push(ch);
            }
        }
        if(a.size()!=b.size()){
            flag = false;
            return flag;
        }
        else{
            while(!a.empty()){
                if(a.top() == b.top()){
                    a.pop();
                    b.pop();
                }
                else{
                    flag = false;
                    return flag;
                }
            }
        }
        return flag;
        
    }
};
