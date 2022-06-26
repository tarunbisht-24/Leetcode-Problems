class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      
        int currentcardsum=0;
        
        int maxsum=0;
        for (int i = 0; i < k; i++)
        {
            currentcardsum+=cardPoints[i];
          
        }
        maxsum=currentcardsum;
        for (int i = k-1; i >=0; i--)
        {
            currentcardsum-=cardPoints[i];
            currentcardsum+=cardPoints[cardPoints.size()-k+i];
            maxsum=max(maxsum,currentcardsum);
        }
        return maxsum;
    }
};
