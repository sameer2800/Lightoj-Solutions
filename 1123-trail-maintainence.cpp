#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

vector < pair <ll ,ll > > v[210];
vector < pair <ll ,ll > > ans[210];

class Compare
{
public:
    bool operator()(pair<ll, pair <ll ,ll> > n1,pair<ll, pair <ll ,ll> > n2) {
        return n1.first > n2.first;
    }
};

priority_queue < pair <ll , pair < ll, ll > > , vector < pair <ll ,pair < ll, ll > > >, Compare > pq;

int mark[210];
ll globalflag = 0,n;

bool primexists()
{
	for(int i=1;i <=n;i++){
		if(v[i].size() == 0)
			return 0;
	}	

	return 1;
}

ll buildprimgfirst()
{
	memset(mark,-1,sizeof mark);

	int head = 1;

	pq.push(make_pair(0,make_pair(head,0)));

	int counter =0;

	ll prev = 0;

	ll total_len = 0;

	while(!pq.empty()) {

	//	cout << " length upto nw : " <<  total_len << endl;

		pair <ll , pair < ll, ll > > pr =  pq.top();

		pq.pop();

		int yo = pr.second.first;		

		if(mark[yo] == 1)
			continue;
		
		if(prev != 0){
			ans[yo].push_back(make_pair(pr.second.second,pr.first));
			ans[pr.second.second].push_back(make_pair(yo,pr.first ));
		}			

		total_len += pr.first;

		mark[yo] = 1;
		counter++;

		if(counter == n)
			break;

		for(int i =0;i < v[yo].size();i++) {
			if(mark[v[yo][i].first] == -1){
				pq.push(make_pair(v[yo][i].second ,make_pair( v[yo][i].first,yo )  ));
			}
		}

		prev = yo;

	}

	if(counter == n)
		return total_len;
	else
		return -1;

}

ll build_on_ans(ll a, ll b,ll c)
{	
	memset(mark,-1,sizeof mark);

	vector < pair <ll ,ll > > temp[210];

	priority_queue < pair <ll , pair < ll, ll > > , vector < pair <ll ,pair < ll, ll > > >, Compare > pqtemp;

	for(int i=1;i <=n;i++) {
		for(int j=0;j < ans[i].size();j++)
			temp[i].push_back(ans[i][j]);

		ans[i].clear();
	}

	temp[a].push_back(make_pair(b,c));
	temp[b].push_back(make_pair(a,c));

	pqtemp.push(make_pair(0,make_pair(1,0)));

	int counter =0;

	ll prev = 0;

	ll total_len = 0;

	while(!pqtemp.empty()) {

	//	cout << " length upto nw : " <<  total_len << endl;

		pair <ll , pair < ll, ll > > pr =  pqtemp.top();

		pqtemp.pop();

		int yo = pr.second.first;		

		if(mark[yo] == 1) {
		//	cout << "hey";
			continue;
		}	

		if(prev != 0){
			ans[yo].push_back(make_pair(pr.second.second,pr.first));
			ans[pr.second.second].push_back(make_pair(yo,pr.first ));
		}			

		total_len += pr.first;

		mark[yo] = 1;
		counter++;

		if(counter == n)
			break;

		for(int i =0;i < temp[yo].size();i++) {
			if(mark[temp[yo][i].first] == -1){
				pqtemp.push(make_pair(temp[yo][i].second ,make_pair( temp[yo][i].first,yo )  ));
			}
		}

		prev = yo;

	}

	return total_len;


}
 
ll buildprim(ll a,ll  b,ll c)
{

	if(globalflag  == 0) {

		if(primexists() ){
			
			ll yooo = buildprimgfirst();

			if(yooo != -1){
				globalflag = 1;

				return yooo;
			}
			else {
					
					return -1; 
			}	

		}else{
			return -1;
		}

	}else {

		build_on_ans(a,b,c);
	}


}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("/home/sameer/sameer/sam.sam","r",stdin);
	#endif


	//ios_base::sync_with_stdio(false);
	ll i,j,k,m,t,cont,a,b,c;
	
	//cin >> t;
	scanf("%lld",&t);
	ll cases = t;

	while(t--){

		for(i=0;i < 205;i++) {
			v[i].clear();
			ans[i].clear();

		}

		while(!pq.empty())
			pq.pop();

		globalflag = 0;

	//	cout << "Case " << cases - t  << ": "  << endl;
		printf("Case %lld:\n",cases-t);

	//	cin >> n >> m;
		scanf("%lld %lld",&n,&m);

		for(i = 0; i < m ; i++) {
		//	cin >> a >> b >> c;
			
			scanf("%lld %lld %lld",&a,&b,&c);	
			v[a].push_back(make_pair(b,c));
			v[b].push_back(make_pair(a,c));
			
			//cout <<	buildprim(a,b,c) << endl;
			printf("%lld\n", buildprim(a,b,c));
		}

	}


	return 0;
}
