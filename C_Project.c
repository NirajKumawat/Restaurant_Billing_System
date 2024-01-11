#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void generateInvoice();
void billHeader();
void billBody();
void billfooter();



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
    int TBnum, itm_qty, num_of_items;
    char item_name[50];
    float itm_price;

    printf("Enter the number of Items : ");
    scanf("%d",&num_of_items);
    for(int i=0;i<num_of_items;i++){
        printf("Enter the name of Item : ");
        fgets(item_name,50,stdin);
        // item_name[strlen(item_name)-1] = 0;

        printf("Enter the quantity of Item : ");
        scanf("%d",&itm_qty);

        printf("Enter the price of Item : ");
        scanf("%f",&itm_price);
    }
    printf("%d",itm_qty);
    // printf("\ntandoori roti\t\t4\t\t60.00");
    printf("\nall food items :)");
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

void billBody(){
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