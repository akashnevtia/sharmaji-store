#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//structure for linked list

struct node
{	
	char name[20];
	int quantity;
	int mrp;
	int code;
	float purchase_price;
	float profit;
	struct node *next;
	
};

//gobal declartions

struct node *head;
struct node *head1;
int password=12345;
int code=1;

//funtion prototyping
void entry_new_stock();
void admin();
void staff();
void stock_view();
int stock_present(int);
void stock_update();
void profit();


//void main starts
void main()
{
	int choice;
	printf("Welcome to Sharma General Store\nEnter your choice\n");
	do
	{
		printf("1.Admin login\n2.Staff login\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: admin();
				 break;
			case 2: staff();
				 break;
			default: printf("Entered choice is invalid try again");
		}
	}while(1);
}


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
	
	new->code=code;
	code++;
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
	printf("Enter choice\n1.Enter new stock\n2.Stock view\n3.stock_upadte\n4.new\n");
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
				printf("Product code=%d\n",(temp->code));
				printf("Quantity=%d\n",temp->quantity);
				temp=temp->next;
			}
		}
	}
}



void stock_update()
{
	struct node * temp;
	int i,choice,quantity,mrp,code;
	float purchase_price,new_profit;
	stock_view();
	temp=head;
	
		printf("Enter stock code to be updated\n");
		scanf("%d",&code);
	
		if(stock_present(code))
		{	
				
				for(i=1;i<code;i++)
				{
					temp=temp->next;
				}
		
				printf("Enter\n1.Quantity update\n2.Price update\n");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1: printf("Enter new Quantity\n");
						 scanf("%d",&quantity);
						 temp->quantity=quantity;
						 break;
					case 2: printf("Enter new MRP\n");
						 scanf("%d",&mrp);
						 temp->mrp=mrp;
						 printf("Enter new Purchase price\n");
						 scanf("%f",&purchase_price);
						 temp->purchase_price=purchase_price;
						 printf("Enter new profit\n");
						 scanf("%f",&new_profit); 
						 temp->profit=new_profit;
				}
		}
}



int stock_present(int a)
{
	struct node *temp;
	temp=head;
	if(head==NULL)
	{
		printf("Stock is empty\n");
		return 0;
	}
	else
	{
		while(temp!=NULL)
		{
			if(temp->code==a)
			{
				
				return 1;
			}
			//else
			//{
			//	return 0;
			//}
			temp=temp->next;
		}
		return 0;
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



