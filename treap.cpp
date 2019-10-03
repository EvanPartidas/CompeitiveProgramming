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
		void inorder(node* x){
			if(x->left){
//				printf("<L%d>\n",x->key);
				inorder(x->left);
//				printf("</L%d>\n",x->key);
			}
			printf("%d\n",x->key);
			if(x->right){
//				printf("<R%d>\n",x->key);
				inorder(x->right);
//				printf("</R%d>\n",x->key);
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
	return 0;
}
