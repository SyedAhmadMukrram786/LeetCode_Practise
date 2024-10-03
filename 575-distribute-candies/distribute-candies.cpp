class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int> fr;
        for(int n:candyType) {
            fr[n];
        }
        if(candyType.size()/2<=fr.size()) {
            return  candyType.size()/2;
        }
        else {
            return fr.size();
        }
    }
};