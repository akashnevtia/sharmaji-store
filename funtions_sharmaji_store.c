//defining admin()

void admin()
{
	int key,choice;
	printf("Enter your password\n");
	scanf("%d",&key);
	if(key==password) //checking if correct passwword
	{
		printf("Select from following\n1.Stock view\n2.Profit view\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: stock_view();
				 break;
			case 2: profit();
				 break;
		}
	}
	else
	{
		printf("Entered wrong password\n");
	}
}

//void stock_update()
void entry_new_stock()
{
	struct node *new,*temp;
	new=(struct node *)malloc(sizeof(struct node));
	new->next=NULL;
	printf("Enter new product name\n");
	scanf("%s",&new->name);
	printf("Enter quantity\n");
	scanf("%d",&new->quantity);
	printf("Enter MRP\n");
	scanf("%d",&new->mrp);
	printf("Enter our purchase price\n");
	scanf("%f",&new->purchase_price);
	printf("Enter profit(i.e. mrp-purchase_price)\n");
	scanf("%d",&new->profit);
	if(head==NULL)
	{
		head=new;
	}	
	else
	{
	
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new;
	}	
}

void staff()
{
	int choice;
	printf("Enter choice\n1.Enter new stock\n2.Stock view\n3.stock_upadte");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: entry_new_stock();
			 break;
		case 2: stock_view();
			 break;
		case 3: stock_update();
			 break;
	}
}


void stock_view()
{
	struct node *temp;
	{
		temp=head;
		if(head==NULL)
		{
			printf("Stock Empty\n");
		}
		else
		{
			while(temp!=NULL)
			{
				printf("Product name=\n",puts(temp->name));
				printf("Quantity=%d\n",temp->quantity);
				temp=temp->next;
			}
		}
	}
}



void stock_update()
{
	char item[20];
	int choice,quantity,mrp;
	float purchase_price,profit;
	printf("Enter stock name to be updated\n");
	scanf("%s",item);
	if(stock_present(item)==1)
	{
		printf("Enter\n1.Quantity update\n2.Price update");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter new Quantity\n");
				 scanf("%d",&quantity);
				 item_location->quantity=quantity;
				 break;
			case 2: printf("Enter new MRP\n");
				 scanf("%d",&mrp);
				 item_location->mrp=mrp;
				 printf("Enter new Purchase price\n");
				 scanf("%f",&purchase_price);
				 item_location->purchase_price=purchase_price;
				 printf("Enter new profit\n");
				 scanf("%f",&profit); 
				 item_location->profit=profit;
		}
	}
	else
	{
		printf("Stock not present\n");
	}
}


int stock_present(char a[20])
{
	struct node *temp,*loc;
	item_location=head;
	if(head==NULL)
	{
		printf("Stock is empty\n");
		return 0;
	}
	else
	{
		while(item_location!=NULL)
		{
			if(item_location->name==a)
			{
				//item_location=temp;
				return 1;
			}
			else
			{
				return 0;
			}
			item_location=item_location->next;
		}
	}
}



void profit()
{
	struct node *temp;
	float profit=0;
	temp=head;
	if(head==NULL)
	{
		printf("No stock Exiting Profit Viewer\n");
	}
	else
	{
		do
		{
			profit=profit+(temp->profit);
			temp=temp->next;
		}while(temp!=NULL);
		printf("Total Profit of stock=%f\n",profit);
	}
}
