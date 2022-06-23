class Solution {
public:
    static bool comp(const vector<int> a, const vector<int> b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comp);
        priority_queue<int> q;
        int sum = 0;
        for (auto& i : courses)
        {   
            q.push(i[0]);
            sum += i[0];   
            if (sum > i[1])
            {
                sum -= q.top();
                q.pop();
            }
        }
        return q.size();
    }
};
