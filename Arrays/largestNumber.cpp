#include <bits/stdc++.h>

using namespace std;


int largestNumber(vector<int>& number){
    int n=number.size();
    int largest=INT_MIN;
    for(int i=0;i<n;i++){
        if(largest<number[i]) largest=number[i];
    }
    return largest;
}

int main(){
    vector<int> number={2,6,7,9,3};
    int maxi=largestNumber(number);
    cout<<"Largest number of array :"<<maxi;
    return 0;
}