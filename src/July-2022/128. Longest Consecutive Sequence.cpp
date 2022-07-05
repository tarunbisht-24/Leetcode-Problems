class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashSet; 
        for (int num : nums) {
            hashSet.insert(num);
        }

        int longestStreak = 0;

        for (auto &num : hashSet) { 
            if (!hashSet.count(num-1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (hashSet.count(currentNum+1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};
