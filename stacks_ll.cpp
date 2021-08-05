#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Node{
public:
	T data{};
	Node<T> *next;

	Node(int data){
		this->data=data;
		next=NULL;
	}
};
template <typename T>
class Stack{
public:
	Node<T> *head=NULL;
	int size=0;
	void push(T x){
		Node<T> *te=new Node<T>(x);
		te->next=head;
		head=te;
		size++;
	}
	bool isEmpty(){
		return size==0;
	}
	T pop(){
		T ans=head->data; 
		Node<T> *te=head;
		head=head->next;
		delete te;
		size--;
		return ans;
	}
	int sizec(){
		return size;
	}
	T top(){
		return head->data;
	}
};

int main(){
    Stack<int> s1;
    s1.push(1);
    s1.push(1);
    s1.push(1);
    s1.push(1);
    cout<<s1.pop()<<" "<<s1.isEmpty()<<endl;

}