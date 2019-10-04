#include <iostream>

using namespace std;

template <typename K>
class treap{
	struct node{
		K key;
		int priority;
		int count;
		node* parent;
		node* left;
		node* right;
		node(K data):key(data),priority(rand()%100),parent(NULL),left(NULL),right(NULL),count(1){}
	};
	private:
		void update_count(node* node){
			node->count = 1;
			if(node->right)
				node->count+=node->right->count;
			if(node->left)
				node->count+=node->left->count;
		}
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
			node* x = search(data);
			if(!x)
				return;
			while(x->left||x->right){
				if(x->left&&x->right){
					if(before(x->left,x->right))
						rotR(x);
					else
						rotL(x);
				}
				else if(x->left){
					rotR(x);
				}
				else{
					rotL(x);
				}
			}
			if(x->parent->left==x)
				x->parent->left=NULL;
			else
				x->parent->right=NULL;
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
	printf("Root %d\n",t.root->key);
	t.inorder(t.root);
	printf("Count: %d\n",t.root->count);
	int r = 3;
	printf("Rank %d: %d\n",r,t.rank(r));
	t.remove(5);
	t.inorder(t.root);
	printf("Rank %d: %d\n",r,t.rank(r));
	return 0;
}
