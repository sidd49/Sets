#include <stdio.h>
#include <limits.h>
void Union(int a[],int b[]);
void intersection(int a[],int b[]);
void diff(int a[],int b[]);
void symdiff(int a[],int b[]);
void accept(int *a);
void display(int *a,int n);
int n=5;
int main(void) {
  int a[5];
  int b[5];
  printf("Enter Set A\n");
  accept(a);
  printf("Enter Set B\n");
  accept(b);
int ce=0;
while(1)
{
printf("Select from one of the options given below\n");
printf("1.Union of two sets\n");
printf("2.Intersection of two sets\n");
printf("3.Difference of two sets\n");
printf("4.Symmetric Difference of two sets\n");
printf("Press -1 to end the program\n");
scanf("%d",&ce);
if(ce==-1)
break;
switch(ce)
{
  case 1:
  Union(a,b);
  break;
  case 2:
intersection(a,b);
break;
case 3:
diff(a,b);
break;
case 4:
symdiff(a,b);
break;
default:
printf("Invalid Input please try again\n");

}
}

//int a[]={1,2,3,4,5};
//int b[]={4,5,6,7,8};
//symdiff(a,b);
  return 0;
}
void accept(int *a)
{
  for(int i=0;i<n;i++)
  {
    scanf("%d",a+i);
   
  }
}
void display(int *a, int l)
{
  printf("{ ");
  for(int i=0;i<l;i++)
  {
    printf("%d ",*(a+i));
  }
   printf("}\n");
}
void Union(int a[],int b[])
{
int x[n*2];
for(int i=0;i<n*2;i++)
{
  x[i]=INT_MAX;
}
for(int i=0;i<n;i++)
{
  x[i]=a[i];
}
int k=n,count=0;
for(int i=0;i<n;i++)
{
  int j=0;
  for( j=0;j<n;j++)
  {
    if(b[i]==x[j])
    {
      count++;
    break;
    }
    
  }
  if(j==n)
  {
  x[k]=b[i];
  k++;
  }
}
  for (int i = 0; i < n*2; i++)     
 {      
       for (int j = 0; j < n*2-1; j++)
           if (x[j] > x[j+1])
           {
              int temp=x[j+1];
              x[j+1]=x[j];
              x[j]=temp;

           }

}
display(x,n*2-count);
}
void intersection(int a[], int b[])
{
 int i=0,j=0,k=0;
 int x[n*2];
 while(i<n && j<n)
 {
   if(a[i]>b[j])
   {
     j++;
   }
   else if(a[i]<b[j])
   {
     i++;
   }
   else
   {
     x[k]=a[i];
     i++;
     j++;
     k++;
   }
 }
 display(x,k);
}
void diff(int a[],int b[])
{
   int i=0,j=0,k=0,u=0;
 int x[n];

 while(i<n )
 {
   if(a[i]>b[j])
   {
    // if(x[u]!=x[u+1])
    // {
   //x[u]=a[i];
  // u++;
   
     j++;
   }
   else if(a[i]<b[j])
   {
     x[u]=a[i];
     u++;
     i++;
   }
   else
   {
     i++;
     j++;
    k++;
   }
 }
 display(x,n-k);
 
}
void symdiff(int a[],int b[])
{
  int i=0,j=0,k=0;
 int x[n*2];
 while(i<n || j<n)
 {
   if(a[i]>b[j] )
   {
     
     x[k]=b[j];
     k++;
     j++;
   }
   else if(a[i]<b[j])
   {
     x[k]=a[i];
     i++;
     k++;
   }
   else
   {
    
     i++;
     j++;
     
   }
 }
 display(x,k);
}
