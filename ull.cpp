#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node * next=NULL;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

void Create(int arr[],int n,Node *p){
	Node *temp,*last;
	p->data=arr[0];
	last= p;
	for(int i{1};i<n;i++){
		temp= new Node();
		temp->data=arr[i];
		last->next=temp;
		last=temp;
	}
}
int Max(Node *p){
	int max{p->data};
	p=p->next;
	while(p){
		if(p->data > max)
			max=p->data;
		p=p->next;
	} 
	return max;
}
void Insert(int pos,int x){
	Node* t = new Node();
	Node* p =first;
	if(pos==0){
		t->next=first;
		t->data=x;
		first=t;
	}
	else{
		pos--;
		while((pos)-- && p){
			p=p->next;
		}
		if(p==NULL){
			p=t;
			t->data=x;

		}
		t->next=p->next;
		p->next=t;
		t->data=x;
	}
}
void Sorted_Insert(Node*p,int x){
	Node* q;
	while(p->data<x && p){
		q=p;
		p=p->next;
	}
	if(p==first){
		Node* t= new Node();
		t->data=x;
		t->next=first;
		first=t;
	}
	else{
		Node* t= new Node();
		q->next=t;
		t->data=x;
		t->next=p;
	}
}
void Delete(int pos,Node* p){
	Node* q;
	if(pos==1){
		first=p->next;
		delete p;
	}
	else{
		pos--;
		while((pos)--&&p){
			q=p;
			p=p->next;
		}
		if(p){
			q->next=p->next;
			delete p;
		}
	}
}
void Duplicate_Delete(Node *p){
	Node *q=p->next;
	while(q){
		if(p->data==q->data){
			p->next=q->next;
			delete q;
			q=p->next;
		}
		else{
			p=p->next;
			q=q->next;
		}
	}
}
void Reverse(Node *p){
	Node *q{NULL} ,*r{NULL};
	while(p){
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	first=q;
}
void Recursive_Reverse(Node *p,Node *q =NULL){
	if(p){
		Recursive_Reverse(p->next,p);
		p->next=q;
	}
	else
		first=q;
}
void Sorted_Merge(Node *f,Node *s){
	Node *last;
	if(f->data<s->data){
		third=f;
		last=f;
		f=f->next;
		last->next=0;
	}
	else{
		third=s;
		last=s;
		s=s->next;
		last->next=0;
	}
	while(f && s){
		if(f->data<s->data){
			last->next=f;
			last=last->next;
			f=f->next;
			last->next=0;
		}
		else{
			last->next=s;
			last=last->next;
			s=s->next;
			last->next=0;
		}
	}
	if(f)
		last->next=f;
	else
		last->next=s;

}
int Check_Loop(Node *f){
	Node *p,*q;
	p=q=f;
	// if(!p & !p->next)
	// 	return 0;
	do{
		p=p->next;
		q=q->next;
		q=q?q->next:q;
	}
	while(p && q && q!=p);
	if(p==q){
		return 1;
	}
	else
		return 0;
}
void Display(Node *p){
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
}
int main(){
	int A[10] ={10,20,23,46,52,65,77,79,90,100};
	int B[7] ={2,20,24,32,67,90,94};
	Create(A,10,first);
	Node *t1,*t2;
	t1=first->next->next->next->next;
	t2=first->next->next->next->next->next->next;
	t2->next=t1;
	// Create(B,7,second);
	// Sorted_Insert(first,45);
	// Sorted_Insert(first,1);
	// Reverse(first);
	// Recursive_Reverse(first);
	// Sorted_Merge(first,second);
	// Display(third);
	cout<<Check_Loop(first)<<endl;
}