#include<bits/stdc++.h>
using namespace std;
class Stack{
	int *data;
	int next_index;
	int capacity=1000;
	public:
	Stack(){
		data=new int[capacity];
		next_index=0;
	}
	int size(){
		return next_index;
	}
	bool isEmpty(){
		return next_index==0;
	}
	void push(int x){
		if(next_index==capacity){
			capacity*=2;
			int *newData= new int[capacity];
			for(int i=0;i<next_index;i++)
				newData[i]=data[i];
			delete []data;
			data=newData;
		}
		data[next_index]=x;
		next_index++;
	}
	void pop(){
		if(isEmpty()){
			cout<<"Stack is Empty"<<endl;
			cout<<INT_MIN;
		}
		cout<<data[next_index-1];
		next_index--;
	}
	void top(){
		if(isEmpty()){
			cout<<"Stack is Empty"<<endl;
			return;
		}
		cout<<data[next_index-1];
	}
};
int main(){
	Stack s1;
	s1.push(1);
	s1.push(1);
	s1.push(1);
	s1.push(1);
	s1.push(1);
	s1.push(1);
	s1.pop();

}