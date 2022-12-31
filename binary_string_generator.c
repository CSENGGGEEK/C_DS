#include<stdio.h>
#include<math.h>
int bin_gen(int n,int array[],int index);

void main(){
    int num,array[21000];
    printf("Enter the bits : ");
    scanf("%d",&num);
    bin_gen(num,array,0);
}


int bin_gen(int n,int array[],int index){
     if(index==n){
		for (size_t i = 0; i < n; i++)
		{
			printf("%d ",array[i]);
		}
		printf("\n");
	 }else{    
        array[index] = 0;
        bin_gen(n,array,index+1);
        array[index] = 1;
        bin_gen(n,array,index+1);
     }
}
