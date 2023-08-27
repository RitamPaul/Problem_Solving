class Solution
{
    public:
    string reverseWord(string &str)
    {
        int low=0, high=str.size()-1;
        while(low <= high){
            char temp = str[low];
            str[low] = str[high];
            str[high] = temp;
            ++low;
            --high;
        }
        return str;
    }
};