class Solution
{
  public:
    vector <int> rotate (int n, int d){
        d = d % 16;
        unsigned short int num = n;
        unsigned short int left = (num >> (16 - d)) | (num << d);
        unsigned short int right = (num << (16 - d)) | (num >> d);
        return {left, right};
    }
};