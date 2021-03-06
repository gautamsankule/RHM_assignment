#include <bits/stdc++.h> 
using namespace std; 

int dp[1000][1000]; 


int findLongestRepeatingSubSeq(string X, int m, int n) 
{ 
	
	if(dp[m][n]!=-1) 
	return dp[m][n]; 
	
	
	if (m == 0 || n == 0) 
		return dp[m][n] = 0; 

	
	if (X[m - 1] == X[n - 1] && m != n) 
		return dp[m][n] = findLongestRepeatingSubSeq(X, 
							m - 1, n - 1) + 1; 

	
	return dp[m][n] = max (findLongestRepeatingSubSeq(X, m, n - 1), 
						findLongestRepeatingSubSeq(X, m - 1, n)); 
} 


int main() 
{ 
	string str = "aabbcc"; 
	int m = str.length(); 

memset(dp,-1,sizeof(dp)); 
cout << "The length of the largest subsequence that"
			" repeats itself is : "
		<< findLongestRepeatingSubSeq(str,m,m); 

	return 0; 

} 
