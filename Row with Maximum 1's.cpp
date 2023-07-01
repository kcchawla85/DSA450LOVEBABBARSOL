int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int col=m-1;
    int row=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=col;j>=0;j--)
        {
            if(matrix[i][j]==1)
            {
                row=i;
                col--;
            }
            else{
                break;
            }
        }
    }
    return row;

}
#link : https://www.youtube.com/watch?v=1iSJhfje97I
