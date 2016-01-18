#include <bits/stdc++.h>
#define ll long long
#define MAX 100100
 
 using namespace std;
 
 ll arr[100100];
 vector <pair <ll,ll> > v;

 struct sam {
 	int lazy;
 	int yo;
 	int arr[3];
 };
 
 struct sam nodes[500100];  

void initilize(int node)
{
	nodes[node].lazy = 0;
	nodes[node].yo = 0;
	for(int i=0;i < 3;i++)
		nodes[node].arr[i] = 0;

	nodes[node].arr[0]= 1;

}

void buildtree(int node,int start,int end,int val)
{

	if(start > end)
			return;

	if(start == end)
	{
			initilize(node);
			return;
	}	
	int mid = start + end;
	mid /= 2;
	buildtree(node*2+1,start ,mid,val);
	buildtree(node*2+2,mid+1,end,val);

	initilize(node);
	nodes[node].arr[0] = end-start+1;
	return;
}	 

void update(int node,int start,int end,int qstr,int qend,int val)	
{

	

	if(nodes[node].lazy != 0) {
		int temp = nodes[node].lazy ; 
		temp %= 3;
		if(start != end)
		nodes[node*2+1].lazy += temp, nodes[node*2+2].lazy +=temp;

		int zeroes = nodes[node].arr[0], ones = nodes[node].arr[1],twos = nodes[node].arr[2];
		nodes[node].arr[temp%3] = zeroes;
		nodes[node].arr[(1+temp)% 3] = ones;
		nodes[node].arr[(2+temp)%3] = twos;
		nodes[node].lazy = 0;
	}

	if(start > end)
		return;
	

	if(qend < start || qstr > end)
		return;



	if(qstr <= start and qend >= end) {
		int	temp = val;
		temp %= 3;
		
		if(start != end)
		nodes[node*2+1].lazy += temp, nodes[node*2+2].lazy +=temp;
		
		int zeroes = nodes[node].arr[0], ones = nodes[node].arr[1],twos = nodes[node].arr[2];
		nodes[node].arr[temp%3] = zeroes;
		nodes[node].arr[(1+temp)% 3] = ones;
		nodes[node].arr[(2+temp)%3] = twos;
		nodes[node].lazy = 0;
		return;

	}

			

	int mid =start + end;
	mid /= 2;
	update(node*2 +1,start,mid,qstr,qend,val);
	update(node*2+2,mid+1,end,qstr,qend,val);

	for(int i=0;i < 3;i++)
		nodes[node].arr[i] = nodes[2*node+1].arr[i] + nodes[2*node+2].arr[i];


}

ll query(int node,int start,int end,int qstr,int qend)
{
	

	if(nodes[node].lazy != 0) {
		int temp = nodes[node].lazy ; 
		temp %= 3;

		if(start != end)
		nodes[node*2+1].lazy += temp, nodes[node*2+2].lazy +=temp;
		
		int zeroes = nodes[node].arr[0], ones = nodes[node].arr[1],twos = nodes[node].arr[2];
		nodes[node].arr[temp%3] = zeroes;
		nodes[node].arr[(1+temp)% 3] = ones;
		nodes[node].arr[(2+temp)%3] = twos;
		nodes[node].lazy = 0;
	}

	if(start > end)
		return 0;

	if(qend < start || qstr > end)
		return 0;

	if(qstr <= start and qend >= end) {
		return nodes[node].arr[0];

	}

	int mid =start + end;
	mid /= 2;
	int left = query(node*2 +1,start,mid,qstr,qend);
	int right = query(node*2+2,mid+1,end,qstr,qend);

	return left + right;
	
}

 int main()
 {
     
    #ifndef ONLINE_JUDGE
    freopen("/home/sameer/Documents/sameer/input.sam","r",stdin);
    #endif
 
 
     //ios_base::sync_with_stdio(false);
     ll i,j,k,n,m,t,cont,a,b;
   
     //cin >> t;
     scanf("%lld",&t);

     ll cases = t;
 
     while(t--){
       
          //cin >> n >> m;
          scanf("%lld %lld",&n,&m);


          memset(nodes,0,sizeof nodes);

        //  cout << "Case " << cases-t << ":"  << endl;
 			printf("Case %lld:\n",cases-t );

 		buildtree(0,0,n-1,0);			

 		//cout << "after bldng :" << nodes[1].arr[0] << " " << nodes[2].arr[0] << " "<< nodes[0].arr[2] << endl;

          for(i =0;i < m;i++) {
          	//cin >> k;
          //	cin >> a >> b;
          	scanf("%lld %lld %lld",&k,&a,&b);
          	if(k == 0){
          		update(0,0,n-1,a,b,1);	
          	}else {
         		ll ans = query(0,0,n-1,a,b) ;
         		printf("%lld\n",ans);
          	}
          }

         

       
     }
 
 
 
     return 0;
 }