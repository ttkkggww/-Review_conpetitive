#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<ll> vll(n);
	for(auto &i:vll)cin >> i;
	ll ans  = 0;
	for(int c = 1;c<n;c++){
		int l = 0,r = n-1;
		ll tmp = 0;
		set<int> lst,rst;
		while(1){
			l+=c;
			r-=c;
			lst.insert(l);
			rst.insert(r);
			if(*lst.begin()>*rst.begin())break;
			if(rst.count(l))break;
			tmp += vll[r]+vll[l];
			ans = max(ans,tmp);
		}
	}
	cout<<ans<<endl;

}
