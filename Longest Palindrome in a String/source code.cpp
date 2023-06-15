class Solution {
  public:
    string longestPalin (string &s) {
        int n = s.size();
        if(n==1)    return s;
        
        vector<char> help(n+n+1);
        vector<int> length(n+n+1);
        help[0] = '|';
        int ind=1;
        for(auto i:s){
            help[ind]=i;        ++ind;
            help[ind]='|';      ++ind;
        }

        int center=0, radius=0;
        while(center < n+n+1){
            while(center-(radius+1)>=0 && center+(radius+1)<n+n+1 && 
                    help[center-(radius+1)]==help[center+(radius+1)])
                radius += 1;
            
            length[center] = radius;
            int oldcenter = center, oldradius=radius;
            center += 1;
            radius = 0;
            while(center <= (oldcenter+oldradius)){
                int mirroredcenter = oldcenter - (center - oldcenter);
                int maxmirroredradius = oldcenter + (oldradius - center);
                if(length[mirroredcenter] < maxmirroredradius){
                    length[center] = length[mirroredcenter];
                    center += 1;
                }
                else if(length[mirroredcenter] > maxmirroredradius){
                    length[center] = maxmirroredradius;
                    center += 1;
                }
                else{
                    radius = maxmirroredradius;
                    break;
                }
            }
        }

        int ans=INT_MIN, ansind;
        for(int i=0; i<n+n+1; i++){
            if(length[i]>ans){
                ans = length[i];
                ansind = i;
            }
        }
        
        string final="";
        if(help[ansind]!='|')
            final = final + help[ansind];
        ind=1;
        while(ans--){
            if(help[ansind-ind]!='|')
                final = help[ansind-ind] + final + help[ansind+ind];
            ++ind;
        }
        return final;
    }
};