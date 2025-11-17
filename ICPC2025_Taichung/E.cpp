#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define ll long long
#define pp pair<int,int>
using namespace std;

int main(){
    int t;
    cin>>t;
    string s1="12",s2="123",s3="1234";
    vector<string>str1;
    vector<string>str2;
    vector<string>str3;
    do{
        str1.push_back(s1);
    }while(next_permutation(s1.begin(),s1.end()));
    do{
        str2.push_back(s2);
    }while(next_permutation(s2.begin(),s2.end()));
    do{
        str3.push_back(s3);
    }while(next_permutation(s3.begin(),s3.end()));

    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    sort(str3.begin(),str3.end());

    while(t--){
        string s;
        int id1,id2;
        cin>>s>>id1>>id2;
        if(s.size()==2){
            int dif=0;
            for(int i=0;i<2;i++){
                if(str1[id1-1][i]!=str1[id2-1][i])dif++;
            }
            cout<<2-dif<<"A"<<dif<<"B\n";
        }
        else if(s.size()==3){
            int dif=0;
            for(int i=0;i<3;i++){
                if(str2[id1-1][i]!=str2[id2-1][i])dif++;
            }
            cout<<3-dif<<"A"<<dif<<"B\n";
        }
        else{
            int dif=0;
            for(int i=0;i<4;i++){
                if(str3[id1-1][i]!=str3[id2-1][i])dif++;
            }
            cout<<4-dif<<"A"<<dif<<"B\n";
        }
    }
    return 0;
}
