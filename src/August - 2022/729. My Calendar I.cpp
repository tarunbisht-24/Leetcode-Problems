class MyCalendar {
public:
    vector<pair<long long int,long long int>> v;
MyCalendar() {
    
}

bool book(int start, int end) {
    
    if(v.size()==0)
    {
        pair<long long int,long long int> p;
        p.first=start;
        p.second=end;
        v.push_back(p);
        return true;
    }
    else if(v.size()>0)
    {
        sort(v.begin(),v.end());
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            if((start>=v[i].first&&start<v[i].second)||
                (end>v[i].first&&end<=v[i].second)|| 
				(start<=v[i].first&&end>v[i].second))
            {
                return false;
            }
            
        }
        pair<long long int,long long int> p;
        p.first=start;
        p.second=end;
        v.push_back(p);
       
    }
    return true;
    
}
};
