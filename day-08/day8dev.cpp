#include<iostream>
#include<cmath>                                             // Math library for sqrt() etc.                                            //for printf and scanf in c++
using namespace std;
int isPrime(int num){                                       //Function to check Prime number
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
        if(isPrime(i)) {                                    //Calling the function
            if(prev != -1){
                cout>>prev>>" - ">>i>>" : ">>prev-1>>endl;
            }
            prev=i;
        }
    }
    return 0;
}
