#include<stdio.h>
#define TABLE_SIZE 10

struct hashmap{
    int key;
    int value;
};

int hash(int key){
    int hash;
    hash = key*9;
    return hash%TABLE_SIZE;
}

void insert(int key,int value,struct hashmap array[TABLE_SIZE]){
    int index = hash(key);
    array[index]->key = key;
    array[index]->value = value;
}

void main(){
    struct hashmap array[] = {};
}