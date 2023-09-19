class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      // using FLOYD's Cycle Detection Algorithm
      // Chain (containing cycle) is formed using INDEX
      int slow = nums[0];
      int fast = nums[0];
      do{
        slow = nums[slow];
        fast = nums[nums[fast]];
      }while(slow != fast);
      cout<<fast;
      slow = nums[0];
      while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
      }
      return slow;
    }
};