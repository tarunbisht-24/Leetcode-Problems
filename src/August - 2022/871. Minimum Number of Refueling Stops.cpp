class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        auto comp = [](vector<int> a, vector<int> b){ return a[1] < b[1]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        int i = 0, distance = startFuel, refillCount = 0;
        while(distance < target ){
            while(i < stations.size() && distance >= stations[i][0]){
                pq.push(stations[i++]);
            }
            if(pq.empty()) return -1;
            distance += pq.top()[1];
            refillCount++;
            pq.pop();
        }
        return refillCount;
    }
};
