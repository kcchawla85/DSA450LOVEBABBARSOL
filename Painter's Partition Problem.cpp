bool possible( vector<int>boards ,int k, long long int mid) {

     long long int length=0;

    int painterCount=1;

    for(int i=0;i<boards.size();i++){

        if(length+boards[i]<=mid){

        length=length+boards[i];}

        else{

        painterCount++;

        if(painterCount>k||boards[i]>mid){

            

            return false;}

            length=boards[i];

        }

        

    }

    return true;

}

 long long int findLargestMinDistance(vector<int> &boards, int k)

{

    long long   int s=0;

long long   int sum=0;

long long   int ans=-1;

    for(int i=0;i<boards.size();i++){

        sum=sum+boards[i];

    }

    long long int e=sum;

long long int mid=s+(e-s)/2;

    while(s<=e){

        if(possible(boards,k,mid)){

            ans=mid;

            e=mid-1;

        }

        else

        {

          s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }

    return ans;
 }
//link : https://www.youtube.com/watch?v=YTTdLgyqOLY&t=1836s
