#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<ll> inx(n),iny(n),x(n),y(n);
	for(int i = 0;i< n;i++){
		cin >> inx[i] >> iny[i];
	}
	for(int i = 0;i<n;i++){
		if((abs(inx[i])+abs(iny[i]))%2!=(abs(inx[0])+abs(iny[0]))%2){
			cout<<-1<<endl;
			return 0;
		}
	}

	vector<ll> d;
	for(int i =0;i<39;i++){
		d.push_back(1LL<<(38-i));
	}
	for(int i = 0;i<n;i++){
		x[i] = inx[i]+iny[i];
		y[i] = inx[i]-iny[i];
	}
	if(x[0]%2==0)d.push_back(1);
	
	cout<<d.size()<<endl;
	for(auto &i:d)cout<<i<<' ';cout<<endl;
	for(int i = 0;i<n;i++){
		ll nx=0,ny=0;
		string ans;
		for(auto &j:d){
			int p=15;
			if(nx-x[i]<0){
				nx += j;
				p&=3;
			}else{
				nx -= j;
				p&=12;
			}
			if(ny-y[i]<0){
				ny += j;
				p &=5;
			}
			else{
				ny -= j;
				p &= 10;
			}
			if(p==1)ans.push_back('R');
			if(p==2)ans.push_back('U');
			if(p==4)ans.push_back('D');
			if(p==8)ans.push_back('L');
		}
		cout<<ans<<endl;
	}
	
}
