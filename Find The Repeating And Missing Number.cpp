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
    //second approach using xor(^)
    int res = 0;

   for(int i = 0 ; i<nums.size();i++){
       res = res^nums[i];
   }
   for (int i = 1; i <= nums.size(); i++) {
     res = res^i;
   }

   int bit = res & ~(res -1);

   int x = 0,y=0;
   for(int i = 0 ; i<nums.size() ;i++){
       if(nums[i]&bit){
           x=x^nums[i];
       }else{
         y = y ^ nums[i];
       }
   }
   for (int i = 1; i <= nums.size(); i++) {
     if (i & bit) {
       x = x ^ i;
     } else {
       y = y ^ i;
     }
   }


   for(int i = 0 ; i<nums.size();i++){
    if(nums[i]==x){
        return {x,y};
    }
  
   }

   return {y,x};
}
