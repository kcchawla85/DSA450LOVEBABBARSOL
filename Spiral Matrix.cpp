#include <bits/stdc++.h> 

vector<int> spiralPathMatrix(vector<vector<int>> matrix, int n, int m) 

{

   vector<int> temp;

    int i;

   int row=matrix.size();

   int col=matrix[0].size();

   int count=0;

   int total=row*col;

   int startingrow=0;

   int startingcol=0;

   int endingrow=row-1;

   int endingcol=col-1;

   while(count<total){

       for(i=startingcol; i<=endingcol and count<total; i++){

           temp.push_back(matrix[startingrow][i]);

           count++;

       }

       startingrow++;

       for(i=startingrow; i<=endingrow and count<total; i++){

           temp.push_back(matrix[i][endingcol]);

           count++;

       }

       endingcol--;

       for(i=endingcol; i>=startingcol and count<total; i--){

           temp.push_back(matrix[endingrow][i]);

           count++;

       }

       endingrow--;

       for(i=endingrow; i>=startingrow and count<total; i--){

           temp.push_back(matrix[i][startingcol]);

           count++;

       }

       startingcol++;

   }

   return temp;

}
