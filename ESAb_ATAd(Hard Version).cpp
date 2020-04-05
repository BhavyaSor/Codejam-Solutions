#include<bits/stdc++.h>
 
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define deb(x) cout<<#x<<":"<<x<<"\n"
#define printloop(x) for(auto itr:x)cout<<itr<<" ";cout<<"\n"
#define printlooppair(x) cout<<#x<<":";for(auto itr:x)cout<<itr.first<<" and "<<itr.sewtd<<" ";cout<<"\n"
#define printlooppairpair(x) cout<<#x<<":";for(auto itr:x)cout<<itr.first.first<<","<<itr.first.sewtd<<"->"<<itr.sewtd<<" ";cout<<"\n"
#define printtwoloop(x) for(auto i:x){cout<<#x<<":";for(auto j:i){cout<<j<<" ";}cout<<"\n";}cout<<"\n";
#define MAX 100001
#define ll long long
 
using namespace std;
 
void convert(string& str){
    for(char& ch:str){
        if(ch=='1')ch='0';
        else if(ch=='0')ch='1';
    }
}

int main() {
    //fast_io;
    int t,n;cin>>t>>n;
    while(t--){
        int i,j,rev=-1,comp=-1;
        char l,pass;
        string s(n,'?');
        for(i=1,j=0;j<n/2;i+=2){
            if(i>10 && i%10==1){
                if(comp!=-1){
                    cout << comp+1 << endl;
                    cin >> l;
                    if(s[comp]!=l)convert(s);
                }
                else {cout << "1\n";cin>>l;}
                if(rev!=-1){
                    cout << rev+1 << endl;
                    cin >> l;
                    if(s[rev]!=l)reverse(s.begin(),s.end());
                }
                else {cout << "1\n";cin>>l;}
            }
            else{
                cout << j+1 << endl;
                cin >> s[j];
                cout << n-j << endl;
                cin >> s[n-1-j];
                if(s[j]==s[n-1-j])comp=j;
                else if(s[j]!=s[n-1-j])rev=j;
                ++j;
            }
        }
        cout << s << endl;
        cin>>pass;
        if(pass=='N')return 0;
    }
}
