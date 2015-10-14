#include <bits/stdc++.h>
#define ll long long
#define MAX 100100
 
using namespace std;
 
ll arr[100100];
 
stack <string > back;
stack <string > front;

int main()
{
    
	#ifndef ONLINE_JUDGE
	freopen("/home/placements2016/input.sam","r",stdin);
	#endif
 
 
    ios_base::sync_with_stdio(false);
    ll i,j,k,n,m,t,cont,a,b;
   
    cin >> t;
    ll cases = t;
 
 	string s,s1,s2;
    while(t--){
 		
    	string cur = "http://www.lightoj.com/";

        cout << "Case " << cases - t  << ":"  << endl;

        while(!front.empty())
                front.pop();

            while(!back.empty())
                back.pop();

 		while(1){
 			cin >> s;
        
        	if(s == "QUIT")
        	break;
 				
        	if(s == "VISIT"){
        		cin >> s1;

        		back.push(cur);
        		cur = s1;
                
                cout << cur << endl;

                while(!front.empty())
        		front.pop();

        	}else if(s == "BACK"){

                if(!back.empty()){
                    front.push(cur);
                    cur = back.top();
                    back.pop();
                    cout << cur << endl;
                }else{
                    cout << "Ignored" << endl;
                }

        	}else {

                if(!front.empty()){
                    back.push(cur);
                    cur = front.top();
                    front.pop();
                    cout << cur << endl;
                }else {
                    cout << "Ignored" << endl;
                }

        	}


         
       
        }
    }
 
 
    return 0;
}