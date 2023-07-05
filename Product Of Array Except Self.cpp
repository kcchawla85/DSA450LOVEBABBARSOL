#define mod 1000000007

int *getProductArrayExceptSelf(int *arr, int n)
{
    int *product = new int[n];
    long long int prefixProduct = 1;
    long long int suffixProduct = 1;

    // Calculate prefix product
    for (int i = 0; i < n; i++)
    {
        product[i] = prefixProduct;
        prefixProduct = (prefixProduct * arr[i]) % mod;
    }

    // Calculate suffix product and multiply with prefix product
    for (int i = n - 1; i >= 0; i--)
    {
        product[i] = (product[i] * suffixProduct) % mod;
        suffixProduct = (suffixProduct * arr[i]) % mod;
    }

    return product;
}
//link : https://www.youtube.com/watch?v=gREVHiZjXeQ&t=127s
