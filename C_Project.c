#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void billHeader(){//char name[50],char date[30]
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int TBnum;
    printf("\nEnter Table No. : ");
    scanf("%d",&TBnum);
    printf("\n\n\t\tXYZ Restaurant");
    printf("\n\tG.T Road, Indore, Madhya Pradesh");
    printf("\n\tPHONE NO : XXXXXX7461, XXXXXX9850");
    printf("\n__________________________________________________");
    printf("\n Bill No. : ");
    printf("\t\tDate : %02d/%02d/%02d %02d:%02d",tm.tm_mday,tm.tm_mon,tm.tm_year,tm.tm_hour,tm.tm_min);
    printf("\n Table No. : %d",TBnum);
    printf("\n__________________________________________________");
    printf("\n\tItem\t\t\tQty.\tPrice");
    printf("\n__________________________________________________");
    
}

void billBody(char item[30],float qty,float price){
    if(strlen(item)<7){
    printf("\n %s\t\t\t\t%.2f\t%.2f",item,qty,price);
    }
    else if(strlen(item)<15){
    printf("\n %s\t\t\t%.2f\t%.2f",item,qty,price);
    }
    else if(strlen(item)<23){
    printf("\n %s\t\t%.2f\t%.2f",item,qty,price);
    }
    else if(strlen(item)<31){
    printf("\n %s\t%.2f\t%.2f",item,qty,price);
    }
}

void billFooter(float sub_total){
    float tax,total;
    tax=sub_total*0.09;  
    total=sub_total+(2*tax);
    printf("\n__________________________________________________");
    printf("\n Sub Total \t\t\t\t%.2f",sub_total);
    printf("\n CGST@9 on %.2f \t\t\t%.2f",sub_total,tax);
    printf("\n SGST@9 on %.2f \t\t\t%.2f",sub_total,tax);
    printf("\n Amount incl of all taxes \t\t%.2f\n",total);
}

struct Item{
    char itm[30];
    float qty;
    float price;
};

int main(){
    int choice;
    int num_of_items;
    struct Item item[30];
    float sub_total=0,total_incl_taxes=0;
    printf("\n=================||XYZ RESTAURANT||===============\n");

    do{
        printf("\n\nSelect Your Operation :");
        printf("\n1.Generate Invoice ");
        printf("\n2.Search Invoice ");
        printf("\n3.Show all Invoice ");
        printf("\n4.Exit \n");
        printf("\nEnter Your Choice : ");
        scanf("%d",&choice);
        switch(choice){
            case(1):
                printf("\nEnter the number of Items : ");
                scanf("%d",&num_of_items);

                for(int i=1;i<=num_of_items;i++){
                    fgetc(stdin);
                    printf("\n\nEnter the name of Item %d : ",i);
                    fgets(item[i].itm,30,stdin);
                    item[i].itm[strlen(item[i].itm)-1] = 0;

                    printf("Enter the quantity of Item : ");
                    scanf("%f",&item[i].qty);

                    printf("Enter the price of Item : ");
                    scanf("%f",&item[i].price);

                    sub_total+=(item[i].qty*item[i].price);
                }

                billHeader();
                for(int i=1;i<=num_of_items;i++){
                    billBody(item[i].itm,item[i].qty,item[i].price);
                }
                billFooter(sub_total);

            break;
            case(2)://search invoice
            break;
            case(3)://show all invoice
            break;
            case(4):printf("\n\n\t\tThanks for Coming. :)\n\n");
            break;
            default:printf("you entered wrong choice!");
        }
    }while(choice!=4);
}

