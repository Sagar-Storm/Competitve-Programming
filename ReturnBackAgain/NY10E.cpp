#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;


int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

int cache[20][70];
int N;
int answer[65];

int  calculate(int digit, int assigned) {
	if(assigned ==  N) return 1;
	if(cache[digit][assigned] != -1) return cache[digit][assigned];
	int answer = 0;
	for(int i = digit; i <= 9; i++) {
		answer += calculate(i, assigned + 1);
	}
	
	return cache[digit][assigned] = answer;
}


signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t ;
	cin >> t;
	memset(answer, -1 , sizeof(answer));
	while(t--) {

		memset(cache, -1, sizeof(cache));

		int cases;

		cin >> cases >> N ;
		if(answer[N] != -1) {
			cout << cases << " " << answer[N] << endl;
			continue;
		}

		answer[N] = calculate(0, 0);

		cout << cases << " " << answer[N] << endl;

	}
}
