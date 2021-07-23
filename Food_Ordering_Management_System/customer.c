void register_order(void);

void customer_order_section(void)
{
	register_order();
	customer_section();
}


void register_order(void)
{
	int itm,qty,item_count;
	char ch='y';
	struct menu m;
	struct customer c;
	FILE *f,*l;
	c.ono=0,
	
	f=fopen("customer_list.txt","r");
	while(fread(&c, sizeof(struct customer), 1, f));
	c.ono++;
	fclose(f);
	
	system("cls");
	
	printf("                                 **************************************************************************\n");
	printf("                                                        WELCOME TO ORDER SECTION\n");
	printf("                                                            REGISTER DETAILS\n");
	printf("                                 **************************************************************************\n\n\n");

	printf("\nEnter Your Details...\n");
	printf("\nEnter Name: ");
	getchar();
	scanf ("%[^\n]%*c", c.cstmr);
	printf("\nEnter Phone Number: ");
	scanf("%s", c.phno);
	printf("\nEnter Number Of Food Items: ");
	scanf("%d", &item_count);
	
	l=fopen("order_list.txt","a");
	fprintf(l,"Item Count: %d\n",item_count);
	fprintf(l,"Order Number: %d\nCustomer Name: %s\n",c.ono,c.cstmr);
	fprintf(l,"Food Item:\tQuantity\n");		
	
	system("cls");

	printf("                                 **************************************************************************\n");
	printf("                                                        WELCOME TO ORDER SECTION\n");
	printf("                                                               ORDER FOOD\n");
	printf("                                 **************************************************************************\n\n\n");
	
	printf("Food Id.\tFood Item\tRate\n\n\n");
	
	f=fopen("menu.txt","r");
	while(fread(&m, sizeof(struct menu), 1, f))
	{	
		printf("-> (%d) \t%s\t%lf\n\n", m.sno, m.itm, m.rt);
	}
	fclose(f);
	
	c.prc=0;	
	while(ch=='y' || ch=='Y')
	{
		printf("\nEnter Food Id. To Select The Food Item: ");
		scanf("%d", &itm);
		printf("\nEnter Item Quantity: ");
		scanf("%d", &qty);
		item_count+=qty;
		
		f=fopen("menu.txt","r");
		while(fread(&m, sizeof(struct menu), 1, f))
		{	
			if(itm==m.sno)
			{
				c.prc = c.prc + (qty * m.rt);
				fprintf(l,"%s:\t%d\n",m.itm,qty);
			}
		}
		fclose(f);
		
		printf("\nEnter (y) to continue: ");
		getchar();
		scanf("%c", &ch);
	}
		
	fprintf(l,"\n");
	fclose(l);
	
	l=fopen("customer_list.txt","a");
	fwrite (&c, sizeof(struct customer), 1, l); 
	fclose(l);
	
	printf("\n\n\n");
	printf("                                                       .....HAPPY ORDERING.....\n");
		
	printf("\n\nPRESS ENTER <--\n\nTO RETURN TO ORDER SECTION...");
	getchar();
	getchar();
}
	
