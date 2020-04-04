#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    int b;
    cin>>t>>b;
    while(t--){
        int arr[b];
        for(int i=1;i<=10;i++){
            cout<<i<<endl;
            cin>>arr[i-1];
        }
        for(int i=0;i<b;i++){
            cout<<arr[i];
        }
        cout<<endl;
        char ch;
        cin>>ch;
        if(ch=='N') break; 
    }
    return 0;   
}
