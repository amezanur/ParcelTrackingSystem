#include <stdio.h>
#include <stdlib.h>

char cust_ID[10], cust_Name[20], address[50],phoneNum[20],courier[10],addItem,type[10],size;
float addPrice,weightPrice,totalPostage=0,totalweightPrice=0;
int numParcel, addinfo=0,destination,destinationPrice,a,b;

int get_input();
int calc_weight();
int calc_destination();
int calc_postage(float addPrice,float totalweightPrice, int destinationPrice);

int main()
{
    FILE *input;
    input = (fopen("custPost.txt","w"));

    fprintf(input,"\t\t\t\t\tSALES RECORD\nCustomer_ID\t\tCustomer_Name\t\tDestination\t\tTotal Postage(RM)");

    fclose(input);

    do
    {
        FILE *input;
        input = (fopen("custPost.txt","a"));
        get_input();
        calc_weight();
        calc_destination();
        calc_postage(addPrice,totalweightPrice,destinationPrice);
        fprintf(input,"\n%s\t\t%s",cust_ID,cust_Name);
        fclose(input);

        printf("\nDo you want to add another record? [Yes=0/No=1]: ");
        scanf("%d",&addinfo);
    }while(addinfo=1);

    addPrice = get_input();
    totalweightPrice = calc_weight();
    destinationPrice= calc_destination();

    calc_postage(addPrice,totalweightPrice,destinationPrice);

    return 0;
}
int get_input()
{
    printf("\nCustomer ID:");
    scanf("%s",&cust_ID);
    printf("\nCustomer Name:");
    scanf("%s",&cust_Name);
    printf("\nCustomer Address:");
    scanf("%s",&address);
    printf("\nPhone number:");
    scanf("%s",&phoneNum);
    printf("\nType of Courier:");
    scanf("%s",&courier);
    printf("\nwant to Add PLASTIC or BOX[Y=YES/N=NO]: ");
    scanf("%s",&addItem);

    if (addItem == 'Y')
    {
    printf("Enter Type[Plastic|Box]: ");
    scanf("%s",&type);
    printf("Enter Size[S|M|L]: ");
    scanf("%s",&size);
    }
     if (type=="Plastic")
    {
            if(size =='S')
            {
                addPrice = 2.00;
            }
            else if(size =='M')
            {
                addPrice = 2.50;
            }
            else if(size =='L')
            {
                addPrice = 3.00;
            }
    }
        else
        {
            if(size =='S')
            {
                addPrice = 4.00;
            }
            else if(size =='M')
            {
                addPrice = 4.50;
            }
            else if(size =='L')
            {
                addPrice = 5.00;
            }
        }
        FILE *input;
        input = (fopen("custPost.txt","a"));
        fprintf(input,"\n%s\t\t%s",cust_ID,cust_Name);
        fclose(input);

        printf("Total charge: RM%.2f",addPrice);
    return addPrice;

}
int calc_weight()
{
    printf("\n\nEnter Number Parcel:");
    scanf("%d",&numParcel);

    do
    {
        if(numParcel>5)
        {
            printf("\nATTENTION!You are allow to send 5 parcel only.Please enter again.");
            printf("\nNumber Parcel:");
            scanf("%d",&numParcel);
        }

    }while(numParcel>5);

    int weightParcel[numParcel];
    float weightPrice[numParcel];

    for(a=0;a<numParcel;a++)
    {
        printf("Enter weight %d category [1/2/3/4]: ",a+1);
        scanf("%d",&weightParcel[a]);

        if(weightParcel[a] == 1)
        {
            weightPrice[a] = 4.5;
        }
        else if(weightParcel[a] == 2)
        {
             weightPrice[a] = 7;
        }
        else if(weightParcel[a] == 3)
        {
             weightPrice[a] = 10;
        }
        else
        {
             weightPrice[a] = 50;
        }
    }

    for(b=0;b<numParcel;b++)
    {
        totalweightPrice=totalweightPrice+weightPrice[b];
    }
    printf("Total Price = RM%.2f",totalweightPrice);

    return totalweightPrice;
}
int calc_destination()
{
    printf("\n\nEnter Delivery Destination [SEMENANJUNG=1|SABAH=2|SARAWAK=3]: ");
    scanf("%d",&destination);

    if (destination == 1)
    {
        destinationPrice = 3;
    }
    else
    {
        destinationPrice = 8;
    }
    FILE *input;
    input=(fopen("custPost.txt","a"));
    fprintf(input,"\t\t%d",destination);
    fclose(input);

    printf("Total Delivery Price:RM%d ",destinationPrice);
    return destinationPrice;
}
int calc_postage(float addPrice,float totalweightPrice,int destinationPrice)
{
    totalPostage = addPrice+totalweightPrice+destinationPrice;

    FILE *input;
    input=(fopen("custPost.txt","a"));
    fprintf(input,"\t\t%.2f",totalPostage);

    printf("\n\nTotal Postage = RM %.2f",totalPostage);

    return 0;
}

