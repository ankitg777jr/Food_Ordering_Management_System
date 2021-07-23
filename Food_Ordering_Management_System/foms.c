#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct menu  
{ 
    int sno;
    char itm[20];
	double rt;
};

struct customer 
{ 
    int ono;
    char cstmr[20];
	char phno[14];	
	double prc;
};

void admin_section(void);
void customer_section(void);
void about_us(void);
void exit_program(void);
void main_section(void);

#include"administrator.c"
#include"customer.c"


void main()
{
	main_section();
}


void main_section(void)
{
	system("cls");
	
	printf("                                 **************************************************************************\n");
	printf("                                                 WELCOME TO FOOD ORDERING MANAGEMENT SYSTEM\n");
	printf("                                                               MAIN SECTION\n");
	printf("                                 **************************************************************************\n\n\n");
	printf("\tENTER...\n\n\t--> (1) FOR ADMIN SECTION\n\n\t--> (2) FOR CUSTOMER SECTION\n\n\t--> (3) FOR ABOUT US\n\n\t--> (4) TO EXIT\n\n\n");
	
	printf("\t\tENTER HERE: ");
	int x;
	scanf("%d",&x);
	
	switch (x) 
   { 
       case 1: admin_section(); 
               break; 
       case 2: customer_section();
               break; 
       case 3: about_us();
       		   main_section();
               break;
	   case 4: exit_program();
               break; 
       default: printf("\n\nINVALID OPERATION..!");
	   			printf("\n\nPRESS ENTER TO CONTINUE...");
       			getchar();
       			getchar();
       			main_section();
       		    break; 
    }
}


void admin_section(void)
{
	system("cls");
	
	printf("                                 **************************************************************************\n");
	printf("                                                          WELCOME TO ADMIN SECTION\n");
	printf("                                 **************************************************************************\n\n\n");
	printf("\tENTER...\n\n\t--> (1) FOR MENU SECTION\n\n\t--> (2) FOR ORDER SECTION\n\n\t--> (3) TO RETURN TO MAIN SECTION\n\n\n");
	
	printf("\t\tENTER HERE: ");
	int x;
	scanf("%d",&x);
	
	switch (x) 
   { 
       case 1: menu_section(); 
               break; 
       case 2: admin_order_section(); 
               break; 
       case 3: main_section(); 
               break; 
       default: printf("\n\nINVALID OPERATION..!");
	   			printf("\n\nPRESS ENTER TO CONTINUE...");
       			getchar();
       			getchar();
       			admin_section();
       		    break; 
    }
}


void customer_section(void)
{
	system("cls");
	
	printf("                                 **************************************************************************\n");
	printf("                                                        WELCOME TO CUSTOMER SECTION\n");
	printf("                                 **************************************************************************\n\n\n");
	printf("\tENTER...\n\n\t--> (1) TO ORDER FOOD\n\n\t--> (2) TO RETURN TO MAIN SECTION\n\n\n");
	
	printf("\t\tENTER HERE: ");
	int x;
	scanf("%d",&x);
	
	switch (x) 
   { 
       case 1: customer_order_section(); 
               break; 
       case 2: main_section(); 
               break; 
       default: printf("\n\nINVALID OPERATION..!");
	   			printf("\n\nPRESS ENTER TO CONTINUE...");
       			getchar();
       			getchar();
       			customer_section();
       		    break; 
    }
}

void about_us(void)
{
	system("cls");
	
	printf("                                 **************************************************************************\n");
	printf("                                                       PEOPLE BEHIND THIS PROJECT\n");
	printf("                                 **************************************************************************\n\n\n");
	printf("\n\n");
		
	FILE *f;
	f=fopen("about.txt","r");
	char s[100];
	while(fgets(s, 100, f))
	{	
	printf("%s",s);
	}
	fclose(f);
	
	printf("\n\n\n\n");
	printf("                                 ******************************* THANK YOU ********************************\n\n\n");
	printf("\nPRESS ENTER <--\n\nTO RETURN TO MAIN SECTION...");
	
	getchar();
	getchar();
}


void exit_program(void)
{
	system("cls");
	
    printf("\n\n\n");
    printf("                                 ******************************* THANK YOU **************************************\n");
    printf("\n\n\n");
    
	exit(0);
}
