#include <bits/stdc++.h>
 #define ll long long
 #define MAX 100100
 
 using namespace std;
 
 ll arr[100100];
 vector <pair <ll,ll> > v;
 
double l,temp,h_c,new_l,teta;

double binarysearch_theta(double low,double high)
{
	ll j = 32;
	double mid;


	while(j--) {

		mid = low+high;
			mid /= 2.0;   // mid is thetha
 		
 		//cout << "loop " << j << "mid : " << mid << endl;

		double rad = new_l/(double)mid;
		
		double new_k = rad*sin(mid);	

		double half_l = l/2.0;

	

		if(new_k < half_l) {
			high = mid;
		}else {
			low = mid;
		}
	}

	return mid;

}


 int main()
 {
     
    #ifndef ONLINE_JUDGE
    freopen("/home/sameer/Documents/sameer/input.sam","r",stdin);
    #endif
 
 
     ios_base::sync_with_stdio(false);
     ll i,j,k,n,m,t,cont,a,b;
   
     cin >> t;
     
     ll cases = t;
 
     while(t--){
       
          
          v.clear();

          
          		cin >> l >> temp >> h_c;
          

		new_l = (1 + temp*h_c)*l;	

		new_l /= 2.0; 


		double angl =binarysearch_theta(0.0, acos(-1)/2.0);
		
		double radi = new_l/(double)angl;

		double yoo = radi * cos(angl);

		double ans = radi - yoo;
         cout<< fixed << setprecision(7)<< "Case " << cases-t << ": "  << ans << endl;
 
                     
       
     }
 
 
 
     return 0;
 }