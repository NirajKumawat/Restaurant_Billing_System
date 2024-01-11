#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
// #include<dos.h>

void generateBillHeader(){//char name[50],char date[30]
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("\n\n\t\tXYZ Restaurant");
    printf("\n\tG.T Road, Indore, Madhya Pradesh");
    printf("\n\tPHONE NO : XXXXXX7461, XXXXXX9850");
    printf("\n__________________________________________________");
    printf("\nBill No. : ");
    printf("\t\tDate : %02d/%02d/%02d %02d:%02d",tm.tm_mday,tm.tm_mon,tm.tm_year,tm.tm_hour,tm.tm_min);
    printf("\nTable No. : ");
    printf("\n__________________________________________________");
    printf("\n\tItem\t\tQty.\t\tRate");
    printf("\n__________________________________________________");
    
}

void generateBillBody(){
    printf("\ntandoori roti\t\t4\t\t60.00");
    printf("\nall food items :)");
    printf("\n__________________________________________________");
}

void generateBillFooter(){
    printf("FOOTER  ");
}

int main(){
    generateBillHeader();
    generateBillBody();
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
// strcpy(ord.date,_date_); //this is to stop conflict of scanf and fgets
// ord.itm[i].itme[strlen(ord.itm[i].item)-1]=0;