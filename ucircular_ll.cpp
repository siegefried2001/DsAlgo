#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data{};
	Node *next{NULL};   
};
Node* head;
void Create(int a[],int n){
	head=new Node();
	head->data=a[0];
	head->next=head;
	Node *last=head;
	Node *t;
	for(int i{1};i<n;i++){
		t= new Node();
		t->data=a[i];
		t->next=last->next;
		last->next=t;
		last=t;
	}
}
void Display(Node *p){
	do{
		cout<<p->data<<" ";
		p=p->next;
	}
	while(p!=head);
}
void Insert(Node *p,int pos,int x){ 
	if(pos==0){//not accounting for the fact that head might be NULL.
		Node *t=new Node();
		while(p->next!=first){
			p=p->next;
		}
		t->data=x;
		t->next=p->next;
		p->next=t;
	}
	else{
		pos--;
		while(pos--)p=p->next;
		Node *t=new Node();
		t->data=
	}
}
int main(){
	int arr[8]={1,2,4,83,43,23,41,56};
	Create(arr,8);
	Display(head);
}