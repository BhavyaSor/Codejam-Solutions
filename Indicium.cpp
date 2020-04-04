#include<bits/stdc++.h>
 
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define deb(x) cout<<#x<<":"<<x<<"\n"
#define printloop(x) cout<<#x<<":";for(auto itr:x)cout<<itr<<" ";cout<<"\n"
#define printlooppair(x) cout<<#x<<":";for(auto itr:x)cout<<itr.first<<" and "<<itr.second<<" ";cout<<"\n"
#define printlooppairpair(x) cout<<#x<<":";for(auto itr:x)cout<<itr.first.first<<","<<itr.first.second<<"->"<<itr.second<<" ";cout<<"\n"
#define printtwoloop(x) for(auto i:x){cout<<#x<<":";for(auto j:i){cout<<j<<" ";}cout<<"\n";}
#define MAX 1000000007
#define ll long long
 
using namespace std;
int mat[50][50];
int n;
bool lefttoassign(int &row, int &col){
    for(row=0;row<n;row++){
        for(col=0;col<n;col++){
            if(mat[row][col]==-1){
                return true;
            }
        }
    }
    return false;
}

bool validmove(int row,int col,int num){
    for(int i=0;i<n;i++){
        if(mat[i][col]==num){
            return false;
        }
        if(mat[row][i]==num){
            return false;
        }
    }
    return true;
}

bool fillmatrix(){
    int row,col;
    if(!lefttoassign(row,col)){
        return true;
    }
    for(int i=1;i<=n;i++){
        if(validmove(row,col,i)){
            mat[row][col]=i;
            if(fillmatrix()){
                return true;
            }
            mat[row][col]=-1;
        }
    }
    return false;
}

int main()
{
    fast
    int t;
    cin>>t;
    for(int l=1;l<=t;l++){
        int k;
        cin>>n>>k;
        if(k==n+1 || k==n*n-1){
            cout<<"Case #"<<l<<": IMPOSSIBLE\n";
            continue;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=-1;
            }
        }

        int x=k/n,y=k%n;
        if(y==1 || y==n-1){
            if(y==1){
                if(k==n+1){
                    cout<<"Case #"<<l<<": IMPOSSIBLE\n";
                    continue;
                }
                mat[0][0]=x-1;
                mat[1][1]=x+1;
                for(int i=2;i<n;i++){
                    mat[i][i]=x;
                }
                mat[n-1][n-1]++;
            }
            if(y==n-1){
                if(x==1){
                    if(n==2){
                        cout<<"Case #"<<l<<": IMPOSSIBLE\n";
                        continue;
                    }
                    mat[0][0]=1;
                    mat[1][1]=3;
                    mat[2][2]=1;
                    for(int i=3;i<n;i++){
                        mat[i][i]=2;
                    }
                }
                else{
                    mat[0][0]=x-1;
                    mat[1][1]=x+2;
                    for(int i=2;i<n;i++){
                        mat[i][i]=x+1;
                    }
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(y>0){
                    y--;
                    mat[i][i]=x+1;
                }
                else mat[i][i]=x;
            }
        }

        if(fillmatrix()){
            cout<<"Case #"<<l<<": POSSIBLE\n";
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<mat[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
        else{
            cout<<"Case #"<<l<<": IMPOSSIBLE\n";
        }
    }
    
}
