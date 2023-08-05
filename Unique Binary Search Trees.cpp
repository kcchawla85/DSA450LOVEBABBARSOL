/*
	Time Complexity : O(N)
	Space Complexity : O(1)

	Where 'N' is the number of nodes.
*/

// Calculate binomial coefficient.
long long int calculateCoeff(int n, int k)
{
	long res = 1;

	if (k > n - k)
	{
		k = n - k;
	}

	for (int i = 0; i < k; i++)
	{
		res *= (n - i);
		res /= (i + 1);
	}
	return res;
}

long long int numTrees(int n) 
{

	long long int answer = calculateCoeff(2 * n, n) / (n + 1);
	
	return answer;
}
