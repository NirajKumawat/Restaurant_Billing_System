#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct items{
    char item[20];
    float price;
    int qty;
}

struct orders{
    char customer[50];
    char date[50];
    int num_of_items;
    struct items itm[50];
}