#include<stdio.h>
void towers(int n,char beg,char aux,char end);

int main(int argc, char const *argv[])
{   
    // Number of disks in beginning tower 
    int num_disk;
    // Tower names
    char beg,inter,end;
    printf("Enter the name of begining tower : ");
    scanf("%c",&beg);
    printf("Enter the name of auxilliary tower : ");
    scanf("%c",&inter);
    printf("\nEnter the name of destination tower : ");
    scanf("%c",&end);
    printf("Enter the number of disks in beginning tower : ");
    scanf("%d",&num_disk);
    towers(num_disk,beg,inter,end);
    return 0;
}


// function 
void towers(int n,char beg,char aux,char end){
    // 1 disk write beg to end 
    if (n==1)
    {
        printf("Move %d disk from tower %c to tower %c\n",n,beg,end);
        return;
    }
    // 
    towers(n-1,beg,end,aux);
    printf("Move %d disk from tower %c to tower %c\n",n,beg,end);
    towers(n-1,aux,beg,end);
    printf("Move %d disk from tower %c to tower %c\n",n,beg,end);
}
