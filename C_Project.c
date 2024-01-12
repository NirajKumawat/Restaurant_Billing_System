#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void generateInvoice();
void billHeader();
int billBody(char item[30],int qty,float price);
void billfooter();

    // int TBnum, itm_qty, num_of_items;
    // char item_name[50];
    // float itm_price;
struct Item{
    char itm[30];
    int qty;
    float price;
};

int main(){
    int choice;
    printf("\n=================||XYZ RESTAURANT||===============\n");
    printf("\nSelect Your Operation :");
    printf("\n1.Generate Invoice ");
    printf("\n2.Search Invoice ");
    printf("\n3.Show all Invoice ");
    printf("\n4.Exit \n");

    do{
        printf("\nEnter Your Choice : ");
        scanf("%d",&choice);
        switch(choice){
            case(1):generateInvoice();
            break;
            case(2):
            break;
            case(3):
            break;
            case(4):
            printf("\n\n\t\tThanks for Coming. :)\n\n");
            break;
            default:printf("you entered wrong choice!");
        }
    }while(choice!=4);
}

void generateInvoice(){
    int num_of_items;
    struct Item item[30];
    float sub_total=0,total_incl_taxes=0;
    printf("\nEnter the number of Items : ");
    scanf("%d",&num_of_items);

    for(int i=1;i<=num_of_items;i++){
        fgetc(stdin);
        printf("\n\nEnter the name of Item %d : ",i);
        fgets(item[i].itm,30,stdin);
        item[i].itm[strlen(item[i].itm)-1] = 0;

        printf("Enter the quantity of Item : ");
        scanf("%d",&item[i].qty);

        printf("Enter the price of Item : ");
        scanf("%f",&item[i].price);

        sub_total+=(item[i].qty*item[i].price);

    }
    printf("%.2f",sub_total);
    billHeader();
    for(int i=1;i<=num_of_items;i++){
        billBody(item[i].itm,item[i].qty,item[i].price);
    }

    // printf("\nall food items :)");
    // billHeader();
    // billBody();
}

void billHeader(){//char name[50],char date[30]
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int TBnum;
    printf("Enter Table No. : ");
    scanf("%d",&TBnum);
    printf("\n\n\t\tXYZ Restaurant");
    printf("\n\tG.T Road, Indore, Madhya Pradesh");
    printf("\n\tPHONE NO : XXXXXX7461, XXXXXX9850");
    printf("\n__________________________________________________");
    printf("\nBill No. : ");
    printf("\t\tDate : %02d/%02d/%02d %02d:%02d",tm.tm_mday,tm.tm_mon,tm.tm_year,tm.tm_hour,tm.tm_min);
    printf("\nTable No. : %d",TBnum);
    printf("\n__________________________________________________");
    printf("\n\tItem\t\tQty.\t\tPrice");
    printf("\n__________________________________________________");
    
}

int billBody(char item[30],int qty,float price){
        // printf("\ntandoori roti\t\t4\t\t60.00");
    printf("%s\t\t%d\t\t%.2f",item,qty,price);
    printf("bill body");
}

void billFooter(){
    printf("\n__________________________________________________");
    printf("FOOTER  ");
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
// ord.customer[strlen(ord.customer)-1]=0;//this is to stop conflict of scanf and fgets
// strcpy(ord.date,_date_); 
// ord.itm[i].itme[strlen(ord.itm[i].item)-1]=0;