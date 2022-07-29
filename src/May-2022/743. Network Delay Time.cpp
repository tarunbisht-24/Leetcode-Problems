class Solution {
public:
    
	vector<int> dijkstraPriorityQueue( map<int,vector<pair<int,int>>> &adj,int src,int n){
        vector<int> d(n+1,INT_MAX);
        d[src]=0;
        vector<bool> vis(n+1,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        while(!pq.empty()){
            int curnode = pq.top().second;
            pq.pop();
            if(vis[curnode]) continue;
            vis[curnode]=true;
            
                for(auto adjnode: adj[curnode]){
                    int nextnode = adjnode.first;
                    int cost = adjnode.second;

                    if(d[curnode]+cost < d[nextnode]){
                        d[nextnode] = d[curnode]+cost;
                        pq.push({d[nextnode],nextnode});
                    }
                }
        }
        
        return d;
    }
