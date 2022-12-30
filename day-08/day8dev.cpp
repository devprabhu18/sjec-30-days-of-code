#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int isPrime(int num){
    if(num<2){
        return 0;
    }
    for(int i=2;i<=sqrt(num);i++){
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int m,n;
    cout<<"Enter the numbers"<<endl;
    cin>>m>>n;
    int prev=-1;
    for(int i=m;i<=n;i++){
        if(isPrime(i)) {
            if(prev != -1){
                printf("%d - %d : %d\n",prev,i,i-prev-1)
            }
            prev=i;
        }
    }
    return 0;
}