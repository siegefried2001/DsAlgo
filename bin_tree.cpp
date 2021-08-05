#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repA(i,a,n) for(int i=a;i<n;i++)
#define repD(i,a,n) for(int i=a;i>=n;i--)
template <typename t>
class bin_tree{
public:
	t data;
	bin_tree* left;
	bin_tree* right;
	bin_tree(t data){
		this->data=data;
		left=NULL;
		right=NULL;
	}
	void printTree(){
		if(this==NULL){
			return;
		}
		cout<<this->data<<":";
		if(left)
			cout<<"L"<<this->left->data;
		if(right)
			cout<<"R"<<this->right->data;
		cout<<endl;
		this->left->printTree();
		this->right->printTree();
	}
	~bin_tree(){
		// cout<<"deleting :"<<this->data<<endl;
		delete this->left;
		delete this->right;
	}
};
void printLevelWise(bin_tree<int>* root){
	if(!root)return;
	queue<bin_tree<int>*> pending;
	pending.push(root);
	while(!pending.empty()){
		bin_tree<int>* curr=pending.front();
		cout<<curr->data<<":L:";
		if(curr->left){
			cout<<curr->left->data<<",";
			pending.push(curr->left);
		}
		else cout<<-1<<",";
		cout<<"R:";
		if(curr->right){
			cout<<curr->right->data;
			pending.push(curr->right);
		}
		else cout<<-1;
		cout<<endl;
		pending.pop();
	}
}
bin_tree<int>* takeInput(){
	int rdata;
	cout<<"Enter Data: "<<endl;
	cin>>rdata;
	if(rdata==-1)return NULL;
	bin_tree<int>* root=new bin_tree<int>(rdata);
	root->left=takeInput();
	root->right=takeInput();
	return root;
}
bin_tree<int>* takeInputLevel(){
	int data;
	cout<<"Enter Data: "<<endl;
	cin>>data;
	bin_tree<int>* root=new bin_tree<int>(data);
	queue<bin_tree<int>*> pending;
	pending.push(root);
	while(!pending.empty()){
		bin_tree<int>* curr=pending.front();
		int rdata,ldata;cout<<"Enter L and R child: ";cin>>ldata>>rdata;
		if(ldata!=-1){
			bin_tree<int>* left=new bin_tree<int>(ldata);
			pending.push(left);curr->left=left;
		}
		if(rdata!=-1){
			bin_tree<int>* right=new bin_tree<int>(rdata);
			pending.push(right);curr->right=right;
		}
		pending.pop();
	}
	return root;
}
int height(bin_tree<int>* root){
	if(!root)return 0;
	return 1+max(height(root->left),height(root->right));
}
int diameter(bin_tree<int>* root){ // unoptimized case
	if(!root)return 0;
	int option1=height(root->left)+height(root->right);
	int option2=diameter(root->left);
	int option3=diameter(root->right);    
	return max(max(option1,option2),option3);
}
pair<int,int> optimized_diamter(bin_tree<int>* root){
	if(!root)return {0,0};
	pair<int,int> left=optimized_diamter(root->left);
	pair<int,int> right=optimized_diamter(root->right);
	int ld=left.second;
	int lh=left.first;
	int rd=right.second;
	int rh=right.first;
	int ht=1+max(lh,rh);
	int dia=max(lh+rh,max(ld,rd));
	return {ht,dia};
}
int main(){
    bin_tree<int>* root=takeInputLevel();
    printLevelWise(root);
    auto p =optimized_diamter(root);
    cout<<"diameter of tree is: "<<p.second<<" with height: "<<p.first<<endl;
    delete root;
}
// 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1 BFS
// 1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 8 -1 -1 -1 DFS