#include <iostream>
#include <map>

using namespace std;

map<int> tree;
int mid = 0;//Median Number (Floored)
int mp = 0;//Median Pointer

void inc(){

}

void dec(){
    if(--mp<1){
        iterator del = tree.find(mid);
        iterator floor = del;
        floor--;
        tree.erase(del);
        mp = *floor;
        mid = floor;

    }
}

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        char* q;
        int num;
        cin>>q>>num;
        iterator it = tree.find(num);
        if(q[0]=='r'){
            if(it==tree.end()){
                cout<<"Wrong!"<<endl;
                continue;
            }
            int a = it.reference;
            if(a==1)
                tree.erase(it);
            *it--;
            if(num<mid){
                dec();
            }
        }else{

        }
    }


}
