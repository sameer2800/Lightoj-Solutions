#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int no=1;
	int t;
	cin >>t;
	while(t--) {
		int ans = 0;
		int door = 3;
		int enter_exit = 5;
		int moving_adj = 4;
		int my_pos;
		cin >> my_pos;
		int lift_pos;
		cin >> lift_pos;
		int travlng_flors = abs(lift_pos - my_pos)+abs(my_pos - 0);
		ans = (travlng_flors*moving_adj) + (enter_exit*2) + (door*3) ;
		cout <<"Case "<<no++<<": "<<ans<<"\n";
	}
	return 0;
}