class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        int maxUnits=0;
        for(int i=0;i<n;i++){
            int index=i;
            for(int j=1+i;j<n;j++)
                if(boxTypes[index][1]<boxTypes[j][1])
                    index=j;
            if(truckSize>=boxTypes[index][0]){
                maxUnits+=boxTypes[index][0]*boxTypes[index][1];
                truckSize-=boxTypes[index][0];
            }
            else{
                maxUnits+=truckSize*boxTypes[index][1];
                truckSize=0;
            }
            if(truckSize==0)
                break;
            swap(boxTypes[index],boxTypes[i]);
        }
        return maxUnits;
    }
};
