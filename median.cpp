#include <iostream>
#include <map>

using namespace std;

map<int,int> tree;
int mid = 0;//Median Number (Floored)
int mp = 0;//Median Pointer
int size = 0;//Number of elements
void inc(){
    map<int,int>::iterator ceil = tree.find(mid);
    if((++mp)>(*ceil).second){
        ceil++;
        pair<int,int> p = *ceil;
        mp = 1;
        mid = p.first;
    }

}

void dec(){
    if((--mp)<1){
        map<int,int>::iterator floor = tree.find(mid);
        floor--;
        pair<int,int> p = *floor;
        mp = p.second;
        mid = p.first;

    }
}

int main(){
    int N;
    cin>>N;
    tree[1]=2;
    tree[2]=5;
    tree[3]=2;
    mid = 2;
    mp = 3;
    size = 9;
   // mid = 0;
  //  mp = 0;
   // size = 0;
    for(int i=0;i<N;i++){
        char str[4];
        int num;
        cin>>str>>num;
        map<int,int>::iterator it = tree.find(num);
        bool odd = size%2==1;
        if(str[0]=='r'){
            if(it==tree.end()){
                cout<<"Wrong!"<<endl;
                continue;
            }
            (*it).second--;
            size--;
            int freq = (*it).second;
            if(freq==0){
                if(num==mid){
                    if(odd)
                        dec();
                    else
                        inc();
                }
                puts("Erasing");
                tree.erase(it);
                goto print;
            }
            if(size<1){
                cout<<"Wrong!"<<endl;
                continue;
            }
            if((num<mid)&&!odd){
                inc();
            }
            else if((num>mid)&&odd){
                dec();
            }
            else if(num==mid){
                if(odd)
                    dec();
            }
            //printf("Num: %d Freq:%d\n Mid: %d\n Mp: %d\n Size: %d\n",num,freq,mid,mp,size);
        }else{
            if(it==tree.end()){
                it = tree.insert(make_pair(num,0)).first;
            }
            (*it).second++;
            int freq = (*it).second;
            size++;
            if((num<mid)&&odd){
                dec();
            }
            else if((num>mid)&&!odd){
                inc();
            }
            else if(num==mid){
                if(odd)
                    dec();
                else
                    inc();
            }
            //printf("Num: %d Freq:%d\n Mid: %d\n Mp: %d\n Size: %d\n",num,freq,mid,mp,size);
        }
        print:
        printf("Mid %d\nMp: %d\n",mid,mp);
        for(auto lol : tree){
            for(int i=0;i<lol.second;i++){
                printf("%d ",lol.first);
            }
        }
    }


}
