#include <bits/stdc++.h>
#define ll long long
#define MAX 100100
  
using namespace std;
  
ll arr[40]; 
ll temp1[20],temp2[20];
vector <ll> haflans;
ll ans =0;

void yooda(ll curr,ll maxi,ll currsum,ll wt)
{

	if(curr == maxi){
		if(currsum <= wt ){
	
			haflans.push_back(currsum);
		}

		return;
	}


	yooda(curr+1,maxi,currsum + temp1[curr],wt);
	yooda(curr+1,maxi,currsum,wt);

	return;
}

void secondepic(ll curr,ll maxi,ll currsum,ll wt)
{

	if(curr == maxi){
		if(currsum <= wt ){
		//	cout << " sum here " <<  currsum << endl;
 		//	ans++;

			 vector <ll>::iterator low = upper_bound(haflans.begin(),haflans.end(),wt-currsum);	
			
			ans +=  (low - haflans.begin());
		}

		return;
	}


	secondepic(curr+1,maxi,currsum + temp2[curr],wt);
	secondepic(curr+1,maxi,currsum,wt);

	return;
}

int main()
{
     
 	#ifndef ONLINE_JUDGE
 	freopen("/home/placements2016/input.sam","r",stdin);
 	#endif
  
     ll i,j,k,n,m,t,cont,a,b,w;
    
     scanf("%lld",&t);
     ll cases = t;
  
     while(t--){

     	ans = 0;
     	haflans.clear();
     	memset(temp1,0,sizeof temp1);
     	memset(temp2,0,sizeof temp2);

  		 printf("Case %lld: ",cases-t );
  		 scanf("%lld %lld",&n,&w);

  		 for(i =0;i < n;i++) {
  			scanf("%lld",&arr[i]);
  		 }

     	sort(arr,arr+n);

     	for(i=0;i < n/2;i++){
     		temp1[i] = arr[i];
     	}

     	  
     	for(i=n/2;i < n;i++){
     		temp2[i-n/2] = arr[i];
     	}

  		 yooda(0,n/2,0,w);

  		 sort(haflans.begin(),haflans.end());

    	 secondepic(0, n-n/2,0,w);


    	 printf("%lld\n",ans);
     }
  
    
     return 0;
}