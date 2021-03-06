#include<bits/stdc++.h>
 
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define deb(x) cout<<#x<<":"<<x<<"\n"
#define printloop(x) cout<<#x<<":";for(auto itr:x)cout<<itr<<" ";cout<<"\n"
#define printlooppair(x) cout<<#x<<":";for(auto itr:x)cout<<itr.first<<" and "<<itr.second<<" ";cout<<"\n"
#define printlooppairpair(x) cout<<#x<<":";for(auto itr:x)cout<<itr.first.first<<","<<itr.first.second<<"->"<<itr.second<<" ";cout<<"\n"
#define printtwoloop(x) cout<<#x<<endl;for(auto i:x){for(auto j:i){cout<<j.first<<","<<j.second<<" ";}cout<<"\n";}
#define MAX 1000000007
#define ll long long
 
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int l=1;l<=t;l++){
        bool poss=true;
        int n;
        cin>>n;
        vector<pair<pair<int,int>,int>> v(n);
        int x,y;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            v[i]={{x,y},i};
        }
        sort(v.begin(),v.end());
        
        vector<int> cam,jam;
        char ch,arr[n];
        arr[0]='C';
        for(int i=1;i<n;i++){
            x=v[i-1].first.first;
            y=v[i-1].first.second;
            if(y>v[i].first.first){
                //Overlapping
                ch=(arr[i-1]=='C')?'J':'C';
                while(i<n && y>v[i].first.first) arr[i++]=ch;
                i--;
            }
            else{
                //Non overlapping
                arr[i]=arr[i-1];
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]=='C') cam.pb(i);
            else jam.pb(i);
        }
        int cur,prev;
        if(cam.size()>0) prev=cam[0];
        for(int i=1;i<cam.size();i++){
            cur=cam[i];
            if(v[prev].first.second>v[cur].first.first){
                poss=false;
                break;
            }
            prev=cur;
        }
        if(poss){
            if(jam.size()>0) prev=jam[0];
            for(int i=1;i<jam.size();i++){
                cur=jam[i];
                if(v[prev].first.second>v[cur].first.first){
                    poss=false;
                    break;
                }
                prev=cur;
            }    
        }
        if(poss){
            char ans[n];
            for(int i=0;i<cam.size();i++){
                ans[ v[cam[i]].second ]='C';
            }
            for(int i=0;i<jam.size();i++){
                ans[ v[jam[i]].second ]='J';
            }
            cout<<"Case #"<<l<<": ";
            for(int i=0;i<n;i++){
                cout<<ans[i];
            }
            cout<<"\n";
        }
        else{
            cout<<"Case #"<<l<<": IMPOSSIBLE"<<"\n";
        }

    }
}

