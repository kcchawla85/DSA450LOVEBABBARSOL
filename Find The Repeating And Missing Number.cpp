vector<int> findRepeatingAndMissingNumbers(vector<int> nums)
{
    vector<int>v;
    int n = nums.size();
    for(int i=0;i<n;i++){
        int j = abs(nums[i])-1;
        if(nums[j]>=0){
            nums[j] *= -1;
        }else{
            v.push_back(abs(nums[i])); //repeated number
        }
    }
    for(int i=0;i<n;i++){
        if(nums[i]>0){
            v.push_back(i+1); //missing number
        }
    }
    return v;
}
