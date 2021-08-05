#include <bits/stdc++.h>
using namespace std;
int binary_search(const vector<int> &arr, int B) {
    int start=0,end=arr.size()-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==B){
            return mid;            
        }
        else if(arr[mid]<B){
            start=mid+1;
        }
        else end=mid-1;
    }   
    return -1;
}
int first_occurence(const vector<int> &arr, int B){
    int n=arr.size();
    int start=0,end=n-1;int result=-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==B){
            result=mid;end=mid-1;
        }
        else if(arr[mid]<B)start=mid+1;
        else end=mid-1;
    }
    return result;
}
int last_occurence(const vector<int> &arr, int B){
    int n=arr.size();
    int start=0,end=n-1;int result=-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==B){
            result=mid;start=mid+1;
        }
        else if(arr[mid]<B)start=mid+1;
        else end=mid-1;
    }
    return result;
}
int main(){
    vector<int> arr={2,4,10,10,10,18,20};
    cout<<binary_search(arr,10)<<" "<<first_occurence(arr,10)<<" "<<last_occurence(arr,10)<<endl;
}
