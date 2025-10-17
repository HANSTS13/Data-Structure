#include<stdio.h>
void bubbleSort(int arr[],int n1)
{
  int temp=0;
  for (int i=0;i<n1-1;i++)
  {
    for(int j=0;j<n1-i-1;j++)
    {
      if(arr[j]>arr[j+1])
      {
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        }
      }
    }
    printf("The sorted array");
  for (int i=0;i<n1;i++)
  {
    printf("\t%d",arr[i]);
  }
}
void main()
{
  int n;
  printf("Enter the size of the array\n");
  scanf("%d",&n);
  int array[n];
  printf("Enter the array elements\n");
  for (int i=0;i<n;i++)
    scanf("%d",&array[i]);
  bubbleSort(array,n);
}
    
    
