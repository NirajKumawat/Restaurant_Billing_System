#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>

void generateBillHeader(char name[50],char date[30]){
    printf("\n\n\t\tXYZ Restaurant");
    printf("G.T Road, Indore, Madhya Pradesh");
    printf("\nPHONE NO : XXXXXX7461, XXXXXX9850");
    printf("--------------------------------------------------");
    printf("Date : ");
    printf("Bill No. : ");
    printf("Table No. : ");
}

int main(){

}
// struct items{
//     char item[20];
//     float price;
//     int qty;
// }

// struct orders{
//     char customer[50];
//     char date[50];
//     int num_of_items;
//     struct items itm[50];
// }

// fgets(ord.customer,50,stdin);
// ord.customer[strlen(ord.customer)-1]=0;
// strcpy(ord.date,_date_);
// ord.itm[i].itme[strlen(ord.itm[i].item)-1]=0;