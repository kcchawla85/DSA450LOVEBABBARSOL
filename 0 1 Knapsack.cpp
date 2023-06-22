#include <bits/stdc++.h> 

int Recursion(vector<int> &weight, vector<int> &value, int index, int capacity){
	// base case
	if (index == 0){
		if (weight[0] <= capacity) return value[0];
		else return 0;
	}

	int include = 0;
	if (weight[index] <= capacity){
		include = value[index] + Recursion(weight, value, index-1, capacity-weight[index]);
	}

	int exclude = Recursion(weight, value, index-1, capacity);

	int ans = max(include, exclude);

	return ans;
}

int RecurMemo(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp){
	// base case
	if (index == 0){
		if (weight[0] <= capacity) return value[0];
		else return 0;
	}

	if (dp[index][capacity] != -1) return dp[index][capacity];

	int include = 0;
    if (weight[index] <= capacity) {
        include = value[index] + RecurMemo(weight, value, index - 1, capacity-weight[index], dp);
    }

    int exclude = RecurMemo(weight, value, index - 1, capacity, dp);

    dp[index][capacity] = max(include, exclude);

    return dp[index][capacity];
}

int Tabulation(vector<int> &weight, vector<int> &value, int n, int capacity){

	vector<vector<int> > dp(n, vector<int>(capacity+1, 0));

	for (int w=weight[0]; w<=capacity; w++){
		if (weight[0] <= capacity) dp[0][w] = value[0];
		else dp[0][w] = 0;
	}

	for (int index=1; index<n; index++){
		for (int w=0; w<=capacity; w++){
			int include = 0;
			if (weight[index] <= w){
				include = value[index] + dp[index-1][w-weight[index]];
			}

			int exclude = 0 + dp[index-1][w];
			dp[index][w] = max(include, exclude);
		}
	}

	return dp[n-1][capacity];
}

int Space_Optimize(vector<int> &weight, vector<int> &value, int n, int capacity){

	vector<int> prev(capacity+1, 0);
	vector<int> curr(capacity+1, 0);

	for (int w=weight[0]; w<=capacity; w++){
		if (weight[0] <= capacity) prev[w] = value[0];
		else prev[w] = 0;
	}

	for (int index=1; index<n; index++){
		for (int w=0; w<=capacity; w++){
			int include = 0;
			if (weight[index] <= w){
				include = value[index] + prev[w-weight[index]];
			}

			int exclude = prev[w];
			curr[w] = max(include, exclude);
		}
		prev = curr;
	}

	return prev[capacity];
}

int Improved(vector<int> &weight, vector<int> &value, int n, int capacity){

	vector<int> curr(capacity+1, 0);

	for (int w=weight[0]; w<=capacity; w++){
		if (weight[0] <= capacity) curr[w] = value[0];
		else curr[w] = 0;
	}

	for (int index=1; index<n; index++){
		for (int w=capacity; w>=0; w--){
			int include = 0;
			if (weight[index] <= w){
				include = value[index] + curr[w-weight[index]];
			}

			int exclude = curr[w];
			curr[w] = max(include, exclude);
		}
	}
	return curr[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Using Recursion
	// return Recursion(weight, value, n-1, maxWeight);

	// Using Recursion + Memoization
	// vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	// return RecurMemo(weight, value, n-1, maxWeight, dp);
	
	// Using Tabulation
	// return Tabulation(weight, value, n, maxWeight);

	// Using Space_Optimize
	// return Space_Optimize(weight, value, n, maxWeight);
	
	// Using Further Improved solution - Only single array
	return Improved(weight, value, n, maxWeight);
}
