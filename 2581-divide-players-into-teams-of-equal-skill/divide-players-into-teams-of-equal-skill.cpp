class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long chemsum=0;
        int n = skill.size();
        
        sort(skill.begin(), skill.end());
        
        int sum=skill.front()+skill.back();

        for(int i=0; i<n/2; ++i){
            if(skill[i]+skill[n-1-i] != sum)
                return -1;
            chemsum += (skill[i] * skill[n-1-i]);
        }
        return chemsum;
    }
};