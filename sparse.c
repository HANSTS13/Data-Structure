#include <stdio.h>

int main(){
int arr1[30][30],arr2[30][30],sum[30][30],arrRep[30][30];
int r1,c1,count=0;
printf("Enter the row of and column sparse matrixes:");
scanf("%d%d",&r1,&c1);



printf("First Sparse Matrix");
printf("\n");
for(int i=0;i<r1;i++){
 for(int j=0;j<c1;j++){
   scanf("%d",&arr1[i][j]);
 }

}



printf("Second Sparse Matrix");
printf("\n");
for(int i=0;i<r1;i++){
 for(int j=0;j<c1;j++){
   scanf("%d",&arr2[i][j]);
 }

}

for(int i=0;i<r1;i++){
  for(int j=0;j<c1;j++){
  sum[i][j]=arr1[i][j]+arr2[i][j];
  if(sum[i][j]!=0)
  {
  count++;
  }
  
     
  }
 
}

arrRep[0][0] = r1;
arrRep[0][1] = c1;
arrRep[0][2] = count;

int k = 1;  
for(int i = 0; i < r1; i++)
{
    for(int j = 0; j < c1; j++)  
    {
        if(sum[i][j] != 0)
        {
            arrRep[k][0] = i;
            arrRep[k][1] = j;
            arrRep[k][2] = sum[i][j];
            k++;
        }
    }
}


for(int i = 0; i <= count; i++)  
{
    for(int j = 0; j < 3; j++)
    {
        printf("%d ", arrRep[i][j]);
    }
    printf("\n");
}

printf("Transpose");
printf("\n");




printf("%d %d %d\n", arrRep[0][1], arrRep[0][0], arrRep[0][2]);


for (int i = 1; i <= arrRep[0][2]; i++) {
    printf("%d %d %d\n", arrRep[i][1], arrRep[i][0], arrRep[i][2]);
}
return 0;
}
