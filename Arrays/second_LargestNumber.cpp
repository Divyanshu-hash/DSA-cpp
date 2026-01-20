#include <bits/stdc++.h>

using namespace std;


int SecondlargestNumber(vector<int>& number){
    int n=number.size();
    int largest=INT_MIN;
    int secondLargest=INT_MIN;
    for(int i=0;i<n;i++){
        if(largest<number[i]){
            secondLargest=largest;
            largest=number[i];
            }
        else if(secondLargest<number[i]){
            secondLargest=number[i];
        }
    }
    return secondLargest;
}

int main(){
    vector<int> number={2,6,7,9,3};
    int maxi2=SecondlargestNumber(number);
    cout<<"Second Largest number of array :"<<maxi2;
    return 0;
}