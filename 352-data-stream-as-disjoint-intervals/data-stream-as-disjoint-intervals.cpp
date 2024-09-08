class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(const auto &i : st){
            if(ans.empty())
                ans.push_back({i,i});
            else{
                int backfirst = ans.back()[0];
                int backsecond = ans.back()[1];

                if(i == backsecond+1)
                    ans.back()[1] = i;
                else
                    ans.push_back({i,i});
            }
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */