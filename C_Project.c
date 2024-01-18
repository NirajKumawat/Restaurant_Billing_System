#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void billHeader(char date[30],char name[30]){
    printf("\n\n\t\tXYZ Restaurant");
    printf("\n\tG.T Road, Indore, Madhya Pradesh");
    printf("\n\tPHONE NO : XXXXXX7461, XXXXXX9850");
    printf("\n__________________________________________________");
    printf("\nInvoice to: %s",name);
    printf("\tDate : %s",date);
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

struct Item{
    char itm[30];
    float qty;
    float price;
};
struct order{
    int choice;
    int num_of_items;
    float sub_total;
    char date[50];
    char C_name[50];
    struct Item item[50];
};

int main(){
    struct order ord;
    struct order _ord;
    char save='y';
    char Search_name[50];
    int found = 0;
    FILE *fptr;

    printf("\n=================||XYZ RESTAURANT||===============\n");
    do{
        printf("\n\nSelect Your Operation :");
        printf("\n1.Generate Invoice ");
        printf("\n2.Search Invoice ");
        printf("\n3.Show all Invoice ");
        printf("\n4.Exit \n");
        printf("\nEnter Your Choice : ");
        scanf("%d",&ord.choice);
        switch(ord.choice){
            case(1)://Generate Invoice
                system("cls");
                ord.sub_total=0;
                printf("\nEnter the Name of the Customer : ");
                fgetc(stdin);
                fgets(ord.C_name,50,stdin);
                ord.C_name[strlen(ord.C_name)-1]=0;
                printf("\nEnter the number of Items : ");
                scanf("%d",&ord.num_of_items);
                strcpy(ord.date,__DATE__);

                for(int i=1;i<=ord.num_of_items;i++){
                    fgetc(stdin);
                    printf("\n\nEnter the name of Item %d : ",i);
                    fgets(ord.item[i].itm,30,stdin);
                    ord.item[i].itm[strlen(ord.item[i].itm)-1] = 0;

                    printf("Enter the quantity of Item : ");
                    scanf("%f",&ord.item[i].qty);

                    printf("Enter the price of Item : ");
                    scanf("%f",&ord.item[i].price);

                    ord.sub_total+=(ord.item[i].qty*ord.item[i].price);
                }

                billHeader(ord.date,ord.C_name);
                for(int i=1;i<=ord.num_of_items;i++){
                    billBody(ord.item[i].itm,ord.item[i].qty,ord.item[i].price);
                }
                billFooter(ord.sub_total);
                
                printf("\nDo you want to save the invoice? [y/n] : ");
                scanf("%s",&save);
                if(save == 'y'){
                    fptr = fopen("RestaurantBills.con","a+");
                    fwrite(&ord,sizeof(struct order),1,fptr);
                    if(fwrite != 0)
                    printf("\nSuccessfully saved");
                    else 
                    printf("\nError saving");
                    fclose(fptr);
                }

            break;
            case(2)://Search Invoice
                printf("Enter the name of the Customer : ");
                fgetc(stdin);
                fgets(Search_name,50,stdin);
                Search_name[strlen(Search_name)-1] = 0;
                system("cls");
                fptr = fopen("RestaurantBills.dat","r");
                printf("\t==============|BILL of %s|==============",Search_name);
                while(fread(&ord,sizeof(struct order),1,fptr)){
                    if(!strcmp(ord.C_name,Search_name)){
                        billHeader(_ord.date,_ord.C_name);
                        for(int i=1;i<=_ord.num_of_items;i++){
                            billBody(_ord.item[i].itm,_ord.item[i].qty,_ord.item[i].price);
                        }
                        billFooter(_ord.sub_total);
                        found = 1;
                    }

                }
                if(!found){
                    printf("The invoice for %s doesnot exists .",Search_name);
                }
                fclose(fptr);


            break;
            case(3)://show all invoice
                system("cls");
                fptr = fopen("RestaurantBills.con","r");
                printf("\n==================||ALL BILLs||==================\n");
                while(fread(&_ord,sizeof(struct order),1,fptr)){
                    billHeader(_ord.date,_ord.C_name);
                    for(int i=1;i<=_ord.num_of_items;i++){
                        billBody(_ord.item[i].itm,_ord.item[i].qty,_ord.item[i].price);
                    }
                    billFooter(_ord.sub_total);
                }
                fclose(fptr);

            break;
            case(4):printf("\n\n\t\tThanks for Coming. :)\n\n");
            break;
            default:printf("you entered wrong choice!");
        }
    }while(ord.choice!=4);
}

