#include <iostream>
#include <iomanip>

using namespace std;

template <typename K>
class treap{
	public:
	struct node{
		K key;
		int priority;
		int count;
		node* parent;
		node* left;
		node* right;
		node(K data):key(data),priority(rand()),parent(NULL),left(NULL),right(NULL),count(1){}
	};
	private:
		void update_count(node* node){
			node->count = 1;
			if(node->right)
				node->count+=node->right->count;
			if(node->left)
				node->count+=node->left->count;
		}
		void rotate(node* parent,node* child, node* &parentrep,node* &childrep){
			node* babushka = parent->parent;

			parentrep = childrep;
			if(parentrep)
				parentrep->parent=parent;

			childrep = parent;
			child -> parent = babushka;
			if(babushka)
			{
				if(babushka->left==parent)
					babushka->left = child;
				else
					babushka->right = child;
			}
			else{
				root = child;
			}
			parent->parent = child;
		}
	public:
		node* search(K data){
			node* x = root;
			while(x){
				if(x->key==data)
					return x;
				if(x->key<data)
					x = x->right;
				else
					x = x->left;
			}
			return NULL;
		}
		bool before(node* a,node* b){
			if(a->priority==b->priority){
				return a->count > b->count;
			}
			return a->priority > b->priority;
		}
		node* root=NULL;
		void insert(K data){
			node* n = new node(data);
			node* parent = NULL;
			node** x = &root;
			while((*x)){
				parent = *x;
				if((*x)->key<data)
					x = &((*x)->right);
				else
					x = &((*x)->left);
			}
			*x = n;
			n->parent = parent;
			while(parent && (parent->priority) < (n->priority)){
				if(parent->left==n)
					rotate(parent,n,parent->left,n->right);
				else
					rotate(parent,n,parent->right,n->left);
				update_count(parent);
				parent = n->parent;
			}
			update_count(n);
			while(parent){
				update_count(parent);
				parent=parent->parent;
			}
		}
		void remove(K data){
			node* x = root;
			while(x){
				if(x->key==data)
					break;
				if(x->key < data){
					x->count--;
					x=x->right;
				}
				else{
					x->count--;
					x=x->left;
				}
			}
			if(!x)
				return;
			while(x->left||x->right){
				if(x->left&&x->right){
					if(before(x->left,x->right))
						rotate(x,x->left,x->left,x->left->right);
					else
						rotate(x,x->right,x->right,x->right->left);
				}
				else if(x->left){
					rotate(x,x->left,x->left,x->left->right);
				}
				else{
					rotate(x,x->right,x->right,x->right->left);
				}
				update_count(x);
				x->count--;
				update_count(x->parent);
			}
			if(x->parent){
				if(x->parent->left==x)
					x->parent->left=NULL;
				else
					x->parent->right=NULL;
			}
			else{
				root=NULL;
			}
			delete x;
		}
		int rank(K data){
			int sum = 0;
			node* n = root;
			while(n){
				if(n->key <= data){
					if(n->left)
						sum+=n->left->count + 1;
					else
						sum++;
					n=n->right;
				}
				else
					n=n->left;
			}
            		return sum;
		}
		K select(int rank){
			int sum = 0;
			int tmp;
			node* n = root;
			while(n){
				tmp = n->left? n->left->count+1:1;
				if(tmp+sum < rank){
					sum+=tmp;
					n=n->right;
				}
				else if(tmp+sum>rank)
					n=n->left;
				else
					break;
			}
			return n->key;			
		}
		void inorder(node* x){
			if(x->left){
				inorder(x->left);
			}
			printf("%d\n",x->key);
			if(x->right){
				inorder(x->right);
			}
		}
};
int main(){
	treap<int> t;
	int N;
	cin>>N;
	cout<<fixed;
	cout<<setprecision(1);
	int size = 0;
	for(int i=0;i<N;i++){
		char str[4];
		int num;
		cin>>str>>num;
		treap<int>::node* x = t.search(num);
		bool odd = size%2==1;
		if(str[0]=='r'){
			//Code for removal
			if(!x){//If the number is not found, continue
				cout<<"Wrong!"<<endl;
				continue;
			}
			t.remove(num);
			if(--size==0){
				cout<<"Wrong!"<<endl;
				continue;
			}
		}else{
			size++;
			t.insert(num);
		}
		if(!odd)
			cout<<t.select(size/2 + 1)<<endl;
		else{
			double output = (long(t.select(size/2)) + t.select(size/2 +1))/2.0;
			if(int(output)==output)
				cout<<int(output)<<endl;
			else
				cout<<output<<endl;
		}
    }
	return 0;
}
