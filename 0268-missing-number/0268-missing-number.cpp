class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;

        for (int num  : nums) {
            expectedSum -= num;
        }

        return expectedSum;
    }
};