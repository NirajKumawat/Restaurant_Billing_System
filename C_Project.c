#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void billHeader(char date[50]){//char name[50],char date[30]
    // time_t t = time(NULL);
    // struct tm tm = *localtime(&t);

    printf("\n\n\t\tXYZ Restaurant");
    printf("\n\tG.T Road, Indore, Madhya Pradesh");
    printf("\n\tPHONE NO : XXXXXX7461, XXXXXX9850");
    printf("\n__________________________________________________");
    printf("\n Bill No. : ");
    printf("\t\tDate : %s",date);
    // printf("\t\tDate : %02d/%02d/%02d %02d:%02d",tm.tm_mday,tm.tm_mon,tm.tm_year,tm.tm_hour,tm.tm_min);
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
    printf("\n CGST@9 \t\t\t\t%.2f",tax);
    printf("\n SGST@9 \t\t\t\t%.2f",tax);
    printf("\n Amount incl of all taxes \t\t%.2f\n",total);
}

struct order{
    char itm[30];
    float qty;
    float price;
    char _date[50];
};

int main(){
    struct order item[30];
    int choice,num_of_items;
    float sub_total=0,total_incl_taxes=0;
    char save='y';
    FILE *fptr;

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
            case(1)://Generate Invoice
                system("cls");
                sub_total=0;
                printf("\nEnter the number of Items : ");
                scanf("%d",&num_of_items);

                strcpy(item->date,__DATE__);

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

                billHeader(item->date);
                for(int i=1;i<=num_of_items;i++){
                    billBody(item[i].itm,item[i].qty,item[i].price);
                }
                billFooter(sub_total);
                
                printf("\nDo you want to save the invoice? [y/n] : ");
                scanf("%s",&save);
                if(save == 'y'){
                    fptr = fopen("RestaurantBills.txt","a+");
                    fwrite(&item,sizeof(struct order),1,fptr);
                    if(fwrite != 0)
                    printf("\nSuccessfully saved");
                    else 
                    printf("\nError saving");
                    fclose(fptr);
                }

            break;
            case(2)://Search Invoice
            printf("%.2f",item[1].price);


            break;
            case(3)://show all invoice
                system("cls");
                fptr = fopen("RestaurantBills.txt","r");
                printf("\n==================||ALL BILLs||==================\n");
                while(fread(&item,sizeof(struct order),1,fptr)){
                    float tot = 0;
                    billHeader();
                    for(int i=1;i<=num_of_items;i++){
                        billBody(item[i].itm,item[i].qty,item[i].price);
                    }
                    billFooter(sub_total);
                }
                fclose(fptr);

            break;
            case(4):printf("\n\n\t\tThanks for Coming. :)\n\n");
            break;
            default:printf("you entered wrong choice!");
        }
    }while(choice!=4);
}

