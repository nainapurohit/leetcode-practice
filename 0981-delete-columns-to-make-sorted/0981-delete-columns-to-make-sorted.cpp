class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        if (strs.size()==0 || strs.size()==1) return 0;
        int res=0;
        for(int i=0;i<strs[0].length();i++){
            for (int j=1;j<strs.size();j++){
                if(strs[j][i]<strs[j-1][i]){
                    res+=1;
                    break;   //remember, use break instead of continue!
                }
            }
        }return res;
    }
};