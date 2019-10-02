#include <iostream>

using namespace std;

template <typename K>
class treap{
	struct node{
		K key;
		int priority;
		node* left;
		node* right;
		node(K data):key(data),priority(rand()%100){}
	};
	public:
		node* root;
		void insert(K data){
			node* n = new node(data);
			node** x = &root;
			while((*x)){
				if((*x)->priority<=n->priority)
					break;
				if((*x)->key<data)
					x = &((*x)->right);
				else
					x = &((*x)->left);
			}
			if((*x)->key>data)
				n->right = *x;
			else
				n->left = *x;
			*x = n;
			printf("root %d\n",root->key);
		}
		void inorder(node* x){
			if(x->left)
				inorder(x->left);
			cout<<(x->key)<<endl;
			if(x->right)
				inorder(x->right);
		}
};
int main(){
	treap<int> t;
	t.insert(25);
	t.insert(10);
	t.insert(6);
	t.insert(2);
	t.insert(3);
	t.insert(12);
	t.insert(5);
	t.insert(7);
	t.insert(8);
	t.insert(1);
	t.inorder(t.root);
	return 0;
}
