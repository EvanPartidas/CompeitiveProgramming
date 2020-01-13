#include <iostream>
#include <bitset>

using namespace std;
typedef long long ll;

const ll mods[] = {0x7fffffff,(ll)(1e9+7)};


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string str;
	cin>>str;
	ll hashfront[] = {0,0};
	ll hashback[] = {0,0};
	ll pows[] = {1,1};
	for(int i=0;i<str.length()-1;i++){
		bool epic = true;
		for(int j=0;j<2;j++){
			hashfront[j] += (str[i]-'a'+1)*pows[j];
			hashfront[j] %= mods[j];
			hashback[j] *= 27;
			hashback[j] %=mods[j];
			hashback[j] += str[str.length()-i-1]-'a'+1;
			hashback[j] %= mods[j];
			epic&=hashfront[j]==hashback[j];
			pows[j]*=27;
			pows[j]%=mods[j];
		}
		if(epic)
			cout<<(i+1)<<" ";
	}
	return 0;
}
