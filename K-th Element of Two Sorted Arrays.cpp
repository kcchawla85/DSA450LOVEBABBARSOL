int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    int count=0;
    int i=0;
    int j=0;
    vector<int> ans;
    while(i<n && j<m && count<k )
    {
        if(arr1[i]<=arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
        }
        else
        {
            ans.push_back(arr2[j]);
            j++;
        }
        count++;

    }
     while (i < n && count < k) {
        ans.push_back(arr1[i]);
        i++;
        count++;
    }
    
    while (j < m && count < k) {
        ans.push_back(arr2[j]);
        j++;
        count++;
    }
    return ans.back();
    

} 
//link : https://www.youtube.com/watch?v=nv7F4PiLUzo
