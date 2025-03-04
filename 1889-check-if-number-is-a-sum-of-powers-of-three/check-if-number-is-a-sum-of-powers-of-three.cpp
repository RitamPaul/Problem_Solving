class Solution {
public:
    bool checkPowersOfThree(int n) {
        int temp = n;
        while(temp) {
            int rem = temp % 3;
            if(rem == 2)
                return false;
            temp = temp / 3;
        }
        return true;
    }
};