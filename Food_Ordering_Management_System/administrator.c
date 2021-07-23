void display_menu(void);
void add_menu(void);

void display_customer_list(void);
void display_order_list(void);
void update_order_list(void);
void display_updated_order_list(void);



void menu_section(void)
{
	system("cls");

	printf("                                 **************************************************************************\n");
	printf("                                                          WELCOME TO MENU SECTION\n");
	printf("                                 **************************************************************************\n\n\n");
	printf("\tENTER...\n\n\t--> (1) TO DISPLAY MENU\n\n\t--> (2) TO AAD MENU\n\n\t--> (3) TO RETURN TO ADMIN SECTION\n\n\n");
	
	printf("\t\tENTER HERE: ");
	int x;
	scanf("%d",&x);
	
	switch (x) 
   { 
       case 1: display_menu(); 
       		   menu_section();
               break; 
       case 2: add_menu();
	   		   menu_section(); 
               break; 
       case 3: admin_section(); 
               break; 
       default: printf("\n\nINVALID OPERATION..!");
	   			printf("\n\nPRESS ENTER TO CONTINUE...");
       			getchar();
       			getchar();
       			menu_section();
       		    break; 
    }
}

void display_menu(void)
{	
	system("cls");

	printf("                    ****************************************\n");
	printf("                                    FOOD MENU\n");
	printf("                    ****************************************\n\n\n\n");
	
	printf("S.No.\tFood Item\tRate\n\n\n");
	
	FILE *f;
	f=fopen("menu.txt","r");
	struct menu m;
	while(fread(&m, sizeof(struct menu), 1, f))
	{	
	printf("%d.\t%s\t%lf\n\n", m.sno, m.itm, m.rt);
	}
		
	fclose(f);
	
	printf("\n\nPRESS ENTER <--\n\nTO RETURN TO MENU SECTION...");
	getchar();
	getchar();
	
}

void add_menu(void)
{	
	system("cls");
		
	printf("                    ****************************************\n");
	printf("                                  AAD FOOD MENU\n");
	printf("                    ****************************************\n\n\n\n");
	
	struct menu m;
	m.sno=0;
	FILE *f;
	
	f=fopen("menu.txt","r");
	while(fread(&m, sizeof(struct menu), 1, f));
	m.sno++;
	fclose(f);
	
	printf("\nEnter Food Item: ");
	getchar();
	scanf ("%[^\n]%*c", m.itm);
	printf("\nEnter Rate: ");
	scanf("%lf", &m.rt);
	
	f=fopen("menu.txt","a");
	fwrite (&m, sizeof(struct menu), 1, f); 
	fclose(f);
	
	printf("\n\nPRESS ENTER <--\n\nTO RETURN TO MENU SECTION...");
	getchar();
	getchar();
	
}

void admin_order_section(void)
{
	system("cls");

	printf("                                 **************************************************************************\n");
	printf("                                                          WELCOME TO ORDER SECTION\n");
	printf("                                 **************************************************************************\n\n\n");
	printf("\tENTER...\n\n\t--> (1) TO DISPLAY CUSTOMER LIST\n\n\t--> (2) TO DISPLAY ORDER LIST\n\n\t--> (3) TO UPDATE ORDER LIST\n\n\t--> (4) TO DISPLAY UPDATED ORDER LIST\n\n\t--> (5) TO RETURN TO ADMIN SECTION\n\n\n");
	
	printf("\t\tENTER HERE: ");
	int x;
	scanf("%d",&x);
	
	switch (x) 
   { 
       case 1: display_customer_list(); 
       		   admin_order_section();
               break; 
       case 2: display_order_list();
       		   admin_order_section();
               break;
	   case 3: update_order_list();
	   		   admin_order_section();
	   		   break;
	   case 4: display_updated_order_list();
	   		   admin_order_section();
	   		   break;	   
       case 5: admin_section(); 
               break; 
       default: printf("\n\nINVALID OPERATION..!");
	   			printf("\n\nPRESS ENTER TO CONTINUE...");
       			getchar();
       			getchar();
       			admin_order_section();
       		    break; 
    }
}

void display_customer_list(void)
{	
	system("cls");

	printf("                    ****************************************\n");
	printf("                                 CUSTOMER LIST\n");
	printf("                    ****************************************\n\n\n\n");
	
	printf("Order No.\tCustomer Name\tPhone No.\tGrand Total\n\n\n");
	
	FILE *f;
	f=fopen("customer_list.txt","r");
	struct customer c;
	while(fread(&c, sizeof(struct customer), 1, f))
	{	
	printf("%d.\t%s\t%s\t%lf\n\n", c.ono, c.cstmr, c.phno, c.prc);
	}
		
	fclose(f);
	
	printf("\n\nPRESS ENTER <--\n\nTO RETURN TO MENU SECTION...");
	getchar();
	getchar();
	
}

void display_order_list(void)
{	
	system("cls");

	printf("                    ****************************************\n");
	printf("                                   ORDER LIST\n");
	printf("                    ****************************************\n\n\n\n");
	
	FILE *f;
	f=fopen("order_list.txt","r");
	char s[20];
	while(fgets(s, 20, f))
	{	
	printf("%s",s);
	}
		
	fclose(f);
	
	printf("\n\nPRESS ENTER <--\n\nTO RETURN TO MENU SECTION...");
	getchar();
	getchar();
	
}

void update_order_list(void)
{	
	system("cls");

	printf("                    ****************************************\n");
	printf("                               ORDER LIST UPDATED\n");
	printf("                    ****************************************\n\n");
	
	FILE *f,*l;
	char s[25]="1\n",st[25]="Item Count: ",c;
	int item_count=1,ascii_item_count,flag=0,max_item_count=1;
	strcat(st,s);
	f=fopen("order_list.txt","r");
	while(fgets(s, 25, f))
	{	
		if(s[12]>(max_item_count+48))
		max_item_count=s[12]-48;
	}
	fclose(f);
	l=fopen("updated_order_list.txt","w");
	fclose(l);
	while(item_count<=max_item_count)
	{
		f=fopen("order_list.txt","r");
		l=fopen("updated_order_list.txt","a");
		while(fgets(s, 25, f))
		{	
			if(strcmp(s,st)==0)
			flag=1;
			if(flag==1)
			fprintf(l,"%s",s);
			if(strcmp(s,"\n")==0)
			flag=0;
		}
		
		flag=0;
		item_count++;
		ascii_item_count=48+item_count;
		s[0]=ascii_item_count;
		s[1]='\0';
		strcat(s,"\n");
		strcpy(st,"Item Count: ");
		strcat(st,s);
		fclose(l);
		fclose(f);
    }
		
	printf("\n\nPRESS ENTER <--\n\nTO RETURN TO MENU SECTION...");
	getchar();
	getchar();
	
}

void display_updated_order_list(void)
{	
	system("cls");

	printf("                    ****************************************\n");
	printf("                                UPDATED ORDER LIST\n");
	printf("                    ****************************************\n\n\n\n");
	
	FILE *f;
	f=fopen("updated_order_list.txt","r");
	char s[20];
	while(fgets(s, 20, f))
	{	
	printf("%s",s);
	}
		
	fclose(f);
	
	printf("\n\nPRESS ENTER <--\n\nTO RETURN TO MENU SECTION...");
	getchar();
	getchar();
	
}
