int firstCircularTour(vector<int>& petrol, vector<int>& distance, int N)

{

long long deficit=0;

long long balance=0;

int start=0;

for(int i=0;i<N;i++)

{

balance+=petrol[i] - distance[i];

if(balance<0)

{

deficit+=balance;

start=i+1;

balance=0;

}

}

if(balance+deficit>=0)

{

return start;

}

else{

return -1;

}

}
// link: https://www.youtube.com/watch?v=_gJ3to4RyeQ&t=5s
