#include <iostream>
using namespace std;

int n[13], k, i[7] = { -1 };
bool o=0;

void comb(int p){
	if (p>6){
		cout << n[i[1]] << ' ' << n[i[2]] << ' ' << n[i[3]] << ' ' << n[i[4]] << ' ' << n[i[5]] << ' ' << n[i[6]]<<'\n';
	}else 
	for (i[p] = i[p - 1] + 1; i[p] < k - 6 + p; i[p]++)
		comb(p + 1);
}

int main(){
//	freopen("www.txt","w",stdout);
	cin.tie(NULL);
	int i,tc=0;
		while (cin>>k,k){
			for (i = 0; i < k; i++)
				cin >> n[i];
			if (tc++)cout <<'\n';
			comb(1);
	}
}
