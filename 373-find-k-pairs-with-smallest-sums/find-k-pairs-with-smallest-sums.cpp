class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1=nums1.size(), n2=nums2.size();
        // items = {-1*sum, {index1,index2}}
        priority_queue< pair<int,pair<int,int>> >pq;
        pq.push({-1*(nums1[0]+nums2[0]), {0,0}});
        vector<vector<int>> ans;
        set<pair<int,int>> st;
        st.insert({0,0});
        while(k--){
            int minDif = pq.top().first;
            int ind1 = pq.top().second.first;
            int ind2 = pq.top().second.second;
            pq.pop();
            ans.push_back({nums1[ind1],nums2[ind2]});
            if(ind1+1<n1 and !st.count({ind1+1,ind2})){
                pq.push({-1*(nums1[ind1+1]+nums2[ind2]), {ind1+1,ind2}});
                st.insert({ind1+1,ind2});
            }
            if(ind2+1<n2 and !st.count({ind1,ind2+1})){
                pq.push({-1*(nums1[ind1]+nums2[ind2+1]), {ind1,ind2+1}});
                st.insert({ind1,ind2+1});
            }
        }
        return ans;
    }
};