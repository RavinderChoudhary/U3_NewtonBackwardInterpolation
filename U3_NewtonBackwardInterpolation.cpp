#include<stdio.h> 
int fact(int);

int main()
{
	#ifndef ONLINE_JUDGE 
      freopen("input.txt", "r", stdin); 
      freopen("output.txt", "w", stdout); 
  #endif 
int n,i,j,ch=30;
float arr[10][11],px=1,x,y,p,h;
scanf("%d",&n);

for(i=0;i<n;i++)
{
scanf("%f",&arr[i][0]);
scanf("%f",&arr[i][1]);
}
//forming the difference table
for(j=2;j<=n;j++)
{for(i=0;i<n-1;i++)
arr[i][j]=arr[i+1][j-1]-arr[i][j-1];
}
//printing table
printf("\nThe Backward difference table");
printf("\n\tX \tY");
for(i=0;i<n-1;i++)
printf("\t%c^%d",ch,i+1);
for(i=0;i<n;i++)
{printf("\n");
for(j=0;j<n+1-i;j++)
printf("\t%.4f",arr[i][j]);
}
scanf("%f",&x);
//calculate the value of f(x) for x
h=arr[n-1][0]-arr[n-2][0];
p=(x-arr[n-1][0])/h;
y=arr[n-1][1];
for(i=1;i<n;i++)
{
px=px*(p+(i-1));
y=y+(arr[n-1-i][i+1]*px)/fact(i);
}
printf("\nthe value of f(x) at x=%f is %f",x,y);
}
int fact(int n)
{ int f=1,i;
for(i=1;i<=n;i++)
f=f*i;
return f;
}

/*
6
0.5 0.479   
0.7 0.644 
0.9 0.783  
1.1 0.891    
1.3 0.963  
1.5 0.997
0.54
*/