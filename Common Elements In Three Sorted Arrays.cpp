#include <bits/stdc++.h> 
vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{   

    int n1 = a.size();
    int n2 = b.size();
    int n3 = c.size();
    vector<int> ans; // Created Vector which will store common elements
    int i=0,j=0,k=0; // Indexes pointing to vector a,b,c respectively
    while(i<n1 && j<n2 && k<n3){
        if(a[i]==b[j] && b[j]==c[k]){ // If common elements are found
            if(ans.empty() || ans.back()!=a[i]){ //To avoid duplicates. .empty() funcyion means that there is no element in vector and .back() means that if the element at the end of vector is same as the element we are adding now then skip this element
                ans.push_back(a[i]);
            }
            i++,j++,k++;
        }
        else if(a[i]<b[j]){ 
            i++;
        }
        else if(b[j]<c[k]){
            j++;
        }
        else{
            k++;
        }
    }
    return ans;
}
