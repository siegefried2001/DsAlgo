#include<bits/stdc++.h>
using namespace std;
void mergeRow(int **input,int a,int endr,int c,int midcol,int d)
{
    int sorted[d-c+1];
    int curr=a;
    while(curr<=endr)
    {
        int i=c;
        int j=midcol+1;
        int k=0;
        while(i<=midcol && j<=d)
        {
            if(input[curr][i]<input[curr][j])
            {
                sorted[k]=input[curr][i];
                k++; i++;
            }
            else
            {
                sorted[k]=input[curr][j];
                k++; j++;
            }
        }
        if(i>midcol)
        {
            while(j<=d)
            {
                sorted[k]=input[curr][j];
                j++; k++;
            }
        }
        else if(j>d)
        {
            while(i<=midcol)
            {
                sorted[k]=input[curr][i];
                i++; k++;
            }
        }
        int out=c;
        for(int &x:sorted)
        {
            input[curr][out]=x;
            out++;
        }
        curr++;
    }
}
void mergeCol(int **input, int c,int endc,int a, int midr,int b)
{
    int sorted[b-a+1];
    int curr=c;
    while(curr<=endc)
    {
        int i=a;
        int j=midr+1;
        int k=0;
        while(i<=midr && j<=b)
        {
            if(input[i][curr]<input[j][curr])
            {
                sorted[k]=input[i][curr];
                k++; i++;
            }
            else
            {
                sorted[k]=input[j][curr];
                k++; j++;
            }
        }
        if(i>midr)
        {
            while(j<=b)
            {
                sorted[k]=input[j][curr];
                j++; k++;
            }
        }
        else if(j>b)
        {
            while(i<=midr)
            {
                sorted[k]=input[i][curr];
                i++; k++;
            }
        }
        int out=a;
        for(int &x:sorted)
        {
            input[out][curr]=x;
            out++;
        }
        curr++;
    }
}
void mergeSort(int **input, int a, int b, int c, int d)
{
    if(a>=b && c>=d)
        return;
    int midrow=a+(b-a)/2;
    int midcol=c+(d-c)/2;
    if(b==a){
        mergeSort(input,a,b,c,midcol);
        mergeSort(input,a,b,midcol+1,d);
        mergeRow(input,a,b,c,midcol,d);
    }
    else if(c==d){
        mergeSort(input,a,midrow,c,d);
        mergeSort(input,midrow+1,b,c,d);
        mergeCol(input,c,d,a,midrow,b);
    }
    else{
    mergeSort(input,a,midrow,c,midcol);
    mergeSort(input,a,midrow,midcol+1,d);
    mergeSort(input,midrow+1,b,c,midcol);
    mergeSort(input,midrow+1,b,midcol+1,d);
    mergeRow(input,a,midrow,c,midcol,d);
    mergeRow(input,midrow+1,b,c,midcol,d);
    mergeCol(input,c,d,a,midrow,b);

    }

}
int main()
{
    int m,n; cin>>m>>n;
    int **input=new int *[m];
    for(int i=0; i<m;i++)
    {
        input[i]= new int[n];
        for(int j=0; j<n; j++)
        {
            cin>>input[i][j];
        }
    }
    mergeSort(input,0,m-1,0,n-1);
    for(int i{};i<m;i++){
        for(int j{};j<n;j++){
            cout<<input[i][j]<<" ";
        }
    }
    cout<<endl;
}