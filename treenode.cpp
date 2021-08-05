#include<bits/stdc++.h>
using namespace std;
template <typename t>
class Treenode{
	public:
	t data;
	vector<Treenode<t>*> ch;
	Treenode(t data){
		this->data=data;
	}
	void printTree(){ //recursive
		cout<<this->data<<":";
		for(int i{};i<this->ch.size();i++){
			cout<<this->ch[i]->data<<" ";
		}
		cout<<endl;
		for(int i{};i<this->ch.size();i++){
			this->ch[i]->printTree();
		}
	}
	~Treenode(){
		cout<<"deleting :"<<this->data<<endl;
		for(int i{};i<this->ch.size();i++)
			delete this->ch[i];
	}

};
Treenode<int>* takeInput_level(){
	cout<<"Enter Data: ";
	int r_data;cin>>r_data;
	Treenode<int>* root= new Treenode<int>(r_data);
	queue<Treenode<int>*> pending;
	pending.push(root);
	while(pending.size()!=0){
		Treenode<int>* curr=pending.front();
		cout<<"Enter number of children: ";int num;
		cin>>num;
		for(int i{};i<num;i++){
			cout<<"Enter child: ";
			int data;cin>>data;
			Treenode<int>* node=new Treenode<int>(data); //dynamically allocated bcoz if we allocate statically
			pending.push(node);							 //memory will be lost in next iteration of while loop
			curr->ch.push_back(node);
		}
		pending.pop();
	}
	return root;
} 
Treenode<int>* takeInput(){
	int r_data{};
	cout<<"Enter Data: ";
	cin>>r_data;
	Treenode<int> *root=new Treenode<int>(r_data);
	cout<<"Enter number of children: ";
	int s{};
	cin>>s;
	for(int i{};i<s;i++){
		Treenode<int> * child =takeInput();
		root->ch.push_back(child);
	}
	return root;
}
void preorder(Treenode<int>* root){
	if(root==NULL)return;
	cout<<root->data<<" ";
	for(int i{};i<root->ch.size();i++){
		preorder(root->ch[i]);
	}
}
void postorder(Treenode<int>* root){
	if(root==NULL)return;
	for(int i{};i<root->ch.size();i++)
		postorder(root->ch[i]);
	cout<<root->data<<" ";
}
int main(){
	Treenode<int> * mytree= takeInput_level();
	mytree->printTree();
	preorder(mytree);postorder(mytree);
	delete mytree;
	// cout<<mytree->data<<endl;
}

// input- 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0