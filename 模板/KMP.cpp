class Solution {
public:
    int strStr(string haystack, string needle) {
        int kmp[needle.size()];
        kmp[0]=0;
        int j=0;
        for(int i=1;i<needle.size();i++){
            while(j>0&&needle[i]!=needle[j]){
                j=kmp[j-1];
            }
            kmp[i]=needle[i]==needle[j]?++j:0;
        }
        j=0;
        for(int i=0;i<haystack.size();){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            else if(j>0){
                j=kmp[j-1];
            }
            else {
                i++;
            }
            if(j==needle.size()){
                return i-j;
            }
        }
        return -1;
    }
};
