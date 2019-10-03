#include <iostream>

using namespace std;

template <typename K>
class treap{
	struct node{
		K key;
		int priority;
		node* parent;
		node* left;
		node* right;
		node(K data):key(data),priority(rand()%100),parent(NULL),left(NULL),right(NULL){}
	};
	private:
		void rotR(node* parent){
			node* child = parent->left;
			node* babushka = parent->parent;

			parent->left = child->right;
			if(parent->left)
				parent->left->parent=parent;

			child -> right = parent;
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
		void rotL(node* parent){
			node* child = parent->right;
			node* babushka = parent->parent;

			parent->right = child->left;
			if(parent->right)
				parent->right->parent=parent;

			child->left = parent;
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
					rotR(parent);
				else
					rotL(parent);
				parent = n->parent;
			}
		}
		void inorder(node* x){
			if(x->left){
				inorder(x->left);
			}
			cout<<(x->key)<<endl;
			if(x->right){
				inorder(x->right);
			}
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
