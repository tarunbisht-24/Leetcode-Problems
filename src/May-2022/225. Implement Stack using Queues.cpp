class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        
           int s = q.size();
           q.push(x);
        
           for(int i=0;i<s;i++)
           {
               q.push(q.front());
               q.pop();
           }
    }
    
    int pop() {
        
        if(q.empty())
            return -1;
        else
        {
           int ans = q.front();
           q.pop();
           return ans; 
        }   
    }
    
    int top() {
        
        return q.empty() ? -1 : q.front();
    }
    
    bool empty() {
        
        return q.empty();
    }
};
