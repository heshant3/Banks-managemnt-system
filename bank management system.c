//This are the header file
#include<stdio.h>
#include<stdlib.h> //file handling
#include<windows.h> //system appearance

//list of global variable
int i,j;
int main_exit;
void menu();
struct date{
    int month,day,year;

    };
struct {

    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;
    
//--------------------------------------calculate interest ----heshan-----------------------------------
float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}

//--------------------------------------delay ------heshan---------------------------------
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
//--------------------------------------account create Functon---------nipuni------------------------------
void new_acc()
{
    int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    account_no:
    system("cls");
    printf("\n\n\t\t\t\xB2\xB2\xB2\ ADD RECORD  \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {printf("Account no. already in use!");
            fordelay(1000000000);
                goto account_no;

            }
    }
    add.acc_no=check.acc_no;
        printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the ID number:");
    scanf("%s",add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:Rs");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.acc_type);

        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);


    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {   system("color 4");
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
//--------------------------------------account view list Functon--------hansika-------------------------------
void view_list()
{
    FILE *view; //data handling
    view=fopen("record.dat","r"); 
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
        printf("\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {   system("color 4");
            printf("\n\t\tInvalid!\a");
            goto view_list_invalid;
        }
}

//--------------------------------------account transact Functon------pubudu---------------------------------
void transact(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

        printf("\n\n\t\tEnter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;
                if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    fordelay(1000000000);
                    system("cls");
                    menu();

                }
                printf("\n\n\t\tDo you want to\n\t\t1.Deposit\n\t\t2.Withdraw?\n\n\t\tEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("\t\tEnter the amount you want to deposit:Rs ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\n\t\tDeposited successfully!");
                }
                else
                {
                    printf("\t\tEnter the amount you want to withdraw:Rs  ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\n\t\tWithdrawn successfully!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
       printf("\n\n\t\tRecord not found!!");
       transact_invalid:
      printf("\n\n\n\t\tEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else
    {   system("color 4");
        printf("\n\t\tInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\n\t\tEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
   }

}
//--------------------------------------account remove Functon---------heshan------------------------------
void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("\n\n\t\tEnter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {test++;
            printf("\n\t\tRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {   system("color 4");
            printf("\n\t\tRecord not found!!\a\a\a");
            erase_invalid:
              printf("\n\t\tEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {system("color 4");
					printf("\n\t\tInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\n\t\tEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }

}
//--------------------------------------account View list Functon--------hansika-------------------------------
void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    printf("\n\n\tDo you want to check by\n\n\t1.Account no\n\t2.Name\n\n\tEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("\n\tEnter the account number:");
        scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   system("cls");
                test=1;
                printf("\n      _______________________________Account holder Details___________________________________");
                printf("\n\n\t\tAccount NO.:%d\n\n\t\tName:%s \n\n\t\tDOB:%d/%d/%d \n\n\t\tAge:%d \n\n\t\tAddress:%s \n\n\t\tCitizenship No:%s \n\n\t\tPhone number:%.0lf \n\n\t\tType Of Account:%s \n\n\t\tAmount deposited:Rs %.2f \n\n\t\tDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\tYou will get Rs%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\tYou will get RS.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\tYou will get Rs.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\tYou will get Rs.%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\n\t\tYou will get no interest\a\a");

                     }

            }
        }
    }
    else if (choice==2)
    {   printf("\tEnter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\n      _______________________________Account holder Details___________________________________");
                printf("\n\n\t\tAccount No.:%d\n\n\t\tName:%s \n\n\t\tDOB:%d/%d/%d \n\n\t\tAge:%d \n\n\t\tAddress:%s \n\n\t\tCitizenship No:%s \n\n\t\tPhone number:%.0lf \n\n\t\tType Of Account:%s \n\n\t\tAmount deposited:Rs%.2f \n\n\t\tDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\tYou will get Rs.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\tYou will get Rs.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\tYou will get Rs.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\tYou will get Rs.%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\n\t\tYou will get no interest\a\a");

                     }

            }
        }
    }


    fclose(ptr);
     if(test!=1)
        {   system("cls");
            printf("\n\tRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else
                    {   system("color 4");
                        system("cls");
                        printf("\n\t\tInvalid!\a");
                        goto see_invalid;}
        }
    else
        {printf("\n      _______________________________________________________________________________________");
		printf("\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            menu();
        }

        else
           {

            system("cls");
            close();
            }

}

//--------------------------------------close system Functon---------------------------------------
void close(void)
{
    printf("\n\n\n\n\t\tThis Project is developed by Group 4 team!");
    }

void teammb(void)
{   system("color 5");
    printf("\n\n\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Develop Team Members \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
    printf("\n      ____________________________________________________________________________");
    printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2 1.Heshan Tharindu");
    printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2 2.Pubudu Disanayaka");
    printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2 3.Nipuni Amasha");
    printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2 4.Hansika Ekanayaka");
    printf("\n      ____________________________________________________________________________");
    
    view_list_invalid:
        printf("\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {   system("color 4");
            printf("\n\t\tInvalid!\a");
            goto view_list_invalid;
        }
    }
//--------------------------------------menu Functon---------------------------------------
void menu(void)
{   int choice;
    system("cls");
    system("color 6");
    printf("\n\n\t\t\t\tBANKING MANAGEMENT SYSTEM");
    printf("\n      ____________________________________________________________________________");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create a new account\n\t\t2.View customer information\n\t\t3.View Transaction\n\t\t4.Removing existing account\n\t\t5.View account information\n\t\t6.About\n\t\t7.Exit");
    printf("\n      ____________________________________________________________________________");
	printf("\n\n\n\n\n\t\t Enter your choice:");
	scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:see();
        break;
        case 3:transact();
        break;
        case 4:erase();
        break;
        case 5:view_list();
        break;
        case 6:teammb();
        break;
        case 7:close();
        break;

    }
}
//-----------------------------Main Interface functions-----------------------------------------------------
int main()
{
    char pass[10],password[10]="admin";
    int i=0;
    char d[30]=" Bank Management System ";
    int z;
    system("color 2");
    printf("\n\n");
    for(z=0;z<20;z++)
    {
    Sleep(50);
    printf("*");
    }
    for(z=0;z<24;z++)
    {
    Sleep(50);
    printf("%c",d[z]);
    }
    for(z=0;z<20;z++)
    {
    Sleep(60);
    printf("*");
    }
    printf("\n\n\t\t   Enter the password to login:");
    scanf("%s",pass);

    if (strcmp(pass,password)==0)
        {printf("\n\n\tPassword Match!\n \tLOADING");
        for(i=0;i<=10;i++)
        {
            fordelay(100000000);
            printf(".");
        }
                system("cls");
            menu();
        }
    else
        {   
		    system("color 4");
		    printf("\n\n\t\tWrong password!!\a\a\a");
            login_try:
            printf("\n\t\tEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {system("color 4");
					printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }
        return 0;
}


