class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int, int> Tfreq;
        unordered_map<int, int> Bfreq;
        vector<int> tempTops=tops;
        vector<int> tempBottoms=bottoms;
        int ans=0;
        int ans1=0;
        int t_max = 0, b_max = 0;
        int t_max_num = 0, b_max_num = 0;

        for (int i = 0; i < tops.size(); ++i) {
            int t = tops[i];
            int b = bottoms[i];

            Tfreq[t]++;
            if (Tfreq[t] > t_max) {
                t_max = Tfreq[t];
                t_max_num = t;
            }

            Bfreq[b]++;
            if (Bfreq[b] > b_max) {
                b_max = Bfreq[b];
                b_max_num = b;
            }
        }
        if(b_max==tops.size())
            return 0;
        else if(t_max==tops.size())
            return 0;
        if((t_max + Bfreq[t_max_num]) >= tops.size())
        {
            for(int i=0;i<tops.size();i++)
            {
                if(t_max_num!=tops[i])
                {
                    if(t_max_num!=bottoms[i]) {
                        ans=-1;
                        break;
                    }
                    ans++;
                    swap(tempBottoms[i],tops[i]);
                }
            }
        }
        if(b_max + Tfreq[b_max_num] >= tops.size())
        {
            for(int i=0;i<bottoms.size();i++) {
                if(b_max_num!=bottoms[i]) {
                    if(b_max_num!=tops[i]) {
                        ans1=-1;
                        break;
                    }
                    ans1++;
                    swap(bottoms[i],tempTops[i]);
                }
            }
        }
        return (ans > 0 && ans1 > 0)? min(ans , ans1) : (ans > 0)? ans : (ans1 > 0)? ans1 : -1;
    }
};
