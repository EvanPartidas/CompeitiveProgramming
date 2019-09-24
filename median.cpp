#include <iostream>
#include <map>

using namespace std;

map<int,int> tree;
int mid = 0;//Median Number (Floored)
int mp = 0;//Median Pointer
int size = 0;//Number of elements

void inc(){//Increment the Median Postion
    map<int,int>::iterator ceil = tree.find(mid);
    if((++mp)>(*ceil).second){//If the position (in this number) overflows, move the median up a number
        ceil++;
        pair<int,int> p = *ceil;
        mp = 1;
        mid = p.first;
    }

}

void dec(){//Decrement the Median Position
    if((--mp)<1){//Decrement the median down a number if position hits 0
        map<int,int>::iterator floor = tree.find(mid);
        floor--;
        pair<int,int> p = *floor;
        mp = p.second;
        mid = p.first;

    }
}

int nextUp(){//Return next biggest number
    map<int,int>::iterator itr = tree.find(mid);
    if(mp==(*itr).second){
        itr++;
        return (*itr).first;
    }
    return mid;
}

int main(){
    int N;
    cin>>N;
    mid = 0;
    mp = 0;
    size = 0;
    for(int i=0;i<N;i++){
        char str[4];
        int num;
        cin>>str>>num;
        map<int,int>::iterator it = tree.find(num);
        bool odd = size%2==1;
        if(str[0]=='r'){
            //Code for removal
            if(it==tree.end()){//If the number is not found, continue
                cout<<"Wrong!"<<endl;
                continue;
            }
            (*it).second--;
            size--;
            if(size<1){//If we have emptied our list, continue
                tree.erase(it);
                cout<<"Wrong!"<<endl;
                continue;
            }

            int freq = (*it).second;
            if(freq==0){//If we need to remove this number from our list
                if(num==mid){//If it was our mid, adjust MP
                    if(odd){
                        dec();
                    }
                    else{
                        inc();
                    }
                    tree.erase(it);
                    goto print;
                }
                tree.erase(it);
            }

            //If statements to adjust MP accordingly
            if((num<mid)&&!odd){
                inc();
            }
            else if((num>=mid)&&odd){
                dec();
            }
            else if(num==mid&&mp>(*it).second){//Special case
                it++;
                mp = 1;
                mid = (*it).first;
            }
            //printf("Num: %d Freq:%d\n Mid: %d\n Mp: %d\n Size: %d\n",num,freq,mid,mp,size);
        }else{
            if(it==tree.end()){
                it = tree.insert(make_pair(num,0)).first;
            }
            (*it).second++;
            int freq = (*it).second;
            size++;
            if(size==1){
                mid = num;
                mp = 1;
                goto print;
            }
            if((num<mid)&&odd){
                dec();
            }
            else if((num>=mid)&&!odd){
                inc();
            }
            //printf("Num: %d Freq:%d\n Mid: %d\n Mp: %d\n Size: %d\n",num,freq,mid,mp,size);
        }
        print:
        if(!odd)
            cout<<mid<<endl;
        else{
            cout<<(mid+nextUp())/2.0<<endl;
        }
        /*printf("Mid %d\nMp: %d\n",mid,mp);
        for(auto lol : tree){
            for(int i=0;i<lol.second;i++){
                printf("%d ",lol.first);
            }
            printf("\n");
        }*/
    }


}
