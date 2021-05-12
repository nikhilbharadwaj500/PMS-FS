//HEADER FILES
#include<stdio.h>//Use for standard I/O Operation
#include<windows.h>
#include<conio.h>//Use for delay(),getch(),gotoxy(),etc.
#include<ctype.h>//se for toupper(), tolower(),etc
#include<string.h>//Use for strcmp(),strcpy(),strlen(),etc
#include<stdlib.h>

char ans=0; 
int ok;
int b, valid=0;
//FUNCTION DECLERATIONS
void WelcomeScreen(void);//WelcomeScreen function decleration
void Title(void);//Title function decleration
void MainMenu(void);//MainMenu function decleration
void SupplierMenu(void);//SupplierMenu function decleration
void Add_Supplier(void);
void List_Supplier(void);
void Search_Supplier(void);
void Edit_Supplier(void);
void Delete_Supplier(void);
void CustomerMenu(void);//CustomerMenu function decleration
void Add_Customer(void);
void List_Customer(void);
void Search_Customer(void);
void Edit_Customer(void);
void Delete_Customer(void);
void MedicineMenu(void);//MedicineMenu function decleration
void Add_Medicine(void);
void List_Medicine(void);
void View_Medicine(void);
void Search_Medicine(void);
void Edit_Medicine(void);
void Delete_Medicine(void);
void PurchaseMenu(void);//PurchaseMenu function decleration
void Add_Purchase(void);
void List_Purchase(void);
void Search_Purchase(void);
void Edit_Purchase(void);
void Delete_Purchase(void);
void Bill_Menu(void);//PurchaseMenu function decleration
void Add_Bill(void);
void List_Bill(void);
void Search_Bill(void);
void Edit_Bill(void);
void Delete_Bill(void);

void LoginScreen(void);//LoginScreen function decleration
void ex_it(void);//exit function declaration


//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y)
{
	COORD pos = {x, y};//sets co-ordinates in (x,y).
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

struct supplier
{
	char id[20];
	char fname[20];
	char lname[20];
	char address[20];
	char email[20];
	char phone[20];
}s;

struct customer
{
	char id[20];
	char fname[20];
	char lname[20];
	char phone[20];
	char email[20];
}c;

struct medicine
{
	char id[20];
	char fname[20];
	char lname[20];
	char mdate[20];
	char edate[20];
	char price[20];	
}m;


struct purchase
{	
	char no[20];
	char medicine_name1[20];
	char medicine_name2[20];
	char quantity[20];
}p;

struct bill
{
	char billno[20];
	char cfname[20];
	char clname[20];
	char mfname[20];
	char mlname[20];
	int quantity;
	int price;
	int total;	
}bill;

main(void)
{
	
    WelcomeScreen();//Use to call WelcomeScreen function
    system("cls");
	Title();//Use to call Title function
	LoginScreen();//Use to call Menu function

}
/* ************************************************* Welcome Screen ********************************************* */
void WelcomeScreen(void) //function for welcome screen
{
	gotoxy(25,6);
	printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
	gotoxy(25,7);
	printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
	gotoxy(25,8);
	printf("        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	gotoxy(25,9);
	printf("        =                 WELCOME                   =");
	gotoxy(25,10);
	printf("        =                   TO                      =");
	gotoxy(25,11);
	printf("        =                  EWIT                     =");
	gotoxy(25,12);
	printf("        =                PHARMACY                   =");
	gotoxy(25,13);
	printf("        =            MANAGEMENT SYSTEM              =");
	gotoxy(25,14);
	printf("        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	gotoxy(25,15);
	printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
	gotoxy(25,16);
	printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
	gotoxy(28,22);
	printf(" Enter any key to continue.....");
	getch();
	
}
/* ************************************************* Title Screen ********************************************* */
void Title(void)//function for title screen
{
	printf("\n\n\t\t----------------------------------------------------------------------------------");
	printf("\n\t\t\t\t      	             PHARMACY STORE         ");
	printf("\n\t\t----------------------------------------------------------------------------------");
}

/* ************************************************* Exit Screen ********************************************* */
void ex_it(void)//function to exit
{
	system("cls");
	Title();// call Title function
	printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING :)");
	getch();//holds screen
	
}
/* ************************************************* Login Screen ********************************************* */
void LoginScreen(void)//function for login screen
{
//list of variables	
int i=0,e=0	;
char Username[15];
char Password[15];
char c= ' ';
char original_Username[25]="ewit";
char original_Password[15]="ewit";

	do
	{
		printf("\n\n\n\n\t\t\t\tEnter your Username and Password :)");
		printf("\n\n\n\t\t\t\t\tUSERNAME:");
		scanf("%s",&Username);
	
		printf("\n\n\t\t\t\t\tPASSWORD:");
		while(i<10)
		{
	    	Password[i]=getch();
	    	c=Password[i];
	    	if(c==13) break;
	    	else printf("*");
	    	i++;
		}
		Password[i]='\0';
		if (strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)
		{
			printf("\n\n\n\t\t\t\t\t...Login Successfull...");
			getch();
			MainMenu();//call MainMenu function
			break;
		}
		else
		{
			printf("\n\t\t\tPassword in incorrect:( Try Again :)");
			e++;
			system("cls");
			Title();
			LoginScreen();
		}

	}
	while(e<=2);
	system("cls");
}	
/* ************************************************* Main Menu ********************************************* */
void MainMenu(void)//function decleration
{
	system("cls");
	int choose;
	Title();// call Title function
	
	printf("\n\n\n\n\t\t\t\t1. Supplier Information\n");
	printf("\n\t\t\t\t2. Medicine Information\n");
	printf("\n\t\t\t\t3. Customer Information\n");
	printf("\n\t\t\t\t4. Purchase Information\n");
	printf("\n\t\t\t\t5. Billing Information\n");
	printf("\n\t\t\t\t6. Exit\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 6:");
	scanf("%i", &choose);
	
	switch(choose)//switch to differeht case
	{
	

    case 1:
    		SupplierMenu();//SupplierMenu funcion is called
    		break;
	case 2:
		    MedicineMenu();//MedicineMenu funcion is called
    		break;
    case 3:
			CustomerMenu();//CustomerMenu funcion is called
    		break;
    case 4:
			PurchaseMenu();//PurchaseMenu funcion is called
    		break;
    case 5:
			Bill_Menu();//Bill_Menu function is call
    		break;
	case 6:
			ex_it();//ex_it function is call
    		break;

	default:
		printf("\t\t\tInvalid entry. Please enter right option :)");
		getch();//holds screen
	}//end of switch
		
	
}
/* ************************************************* Supplier Menu ********************************************* */
void SupplierMenu(void)//function decleration
{
	system("cls");
	int choose;
	Title();// call Title function
	
	printf("\n\n\n\n\t\t\t\t1. Add Supplier Information\n");
	printf("\n\t\t\t\t2. List Supplier Information\n");
	printf("\n\t\t\t\t3. Search Supplier Information\n");
	printf("\n\t\t\t\t4. Edit Supplier Information\n");
	printf("\n\t\t\t\t5. Delete Supplier Information\n");
	printf("\n\t\t\t\t6. Back to Main Menu\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 6:");
	scanf("%i", &choose);
	
	switch(choose)//switch to differeht case
	{
	

    case 1:
    		Add_Supplier();
    		break;
	case 2:
			List_Supplier();
    		break;
    case 3:
			Search_Supplier();
    		break;
    case 4:
			Edit_Supplier();
    		break;
    case 5:
			Delete_Supplier();
    		break;
	case 6:
			MainMenu();
    		break;

	default:
		printf("\t\t\tInvalid entry. Please enter right option :)");
		getch();//holds screen
	}//end of switch
		
	
}

/* **************************************ADD SUPPLIER*******************************************/
void Add_Supplier(void)
{
	system("cls");
	Title();// call Title function
	char ans;
	FILE*ek;//file pointer
	ek=fopen("supplier.txt","a");//open file in write mode
	printf("\n\t\t*******************************************************");
	printf("\n\t                     ADD NEW SUPPLIER                    ");
	printf("\n\t\t*******************************************************");
	printf("\n\n\t\t  ENTER THE DETAILS BELOW:");
/* ******************************************* SUPPLIER ID ************************************************************** */	    
	
	printf("\n\t\t\tSupplier ID: ");
    scanf("%s",s.id);

/* ******************************************* First Name ************************************************************** */	    

	A:
	printf("\n\t\t\tFirst Name: ");
	scanf("%s",s.fname);
	s.fname[0]=toupper(s.fname[0]);
	if(strlen(s.fname)>20||strlen(s.fname)<2)
	{
		printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)");
		goto A;
	}
	else
	{
		for (b=0;b<strlen(s.fname);b++)
		{
			if (isalpha(s.fname[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t First name contain Invalid character :(  Enter again :)");
			goto A;
		}
	}
/* ******************************************* Last Name ************************************************************** */	    
	
	printf("\n\t\t\tLast Name: ");
    scanf("%s",s.lname);
/* **************************************** Address ******************************************************************* */    
    do
    {
    C:
    printf("\n\t\t\tAddress: ");
    scanf("%s",s.address);
    s.address[0]=toupper(s.address[0]);
    if(strlen(s.address)>20||strlen(s.address)<4)
	{
		printf("\n\t Invalid :( \t The max range for address is 20 and min range is 4 :)");
		goto C;
	}
	
}while(!valid);
/* ******************************************* Contact no. ***************************************** */
do
{
	D:
    printf("\n\t\t\tContact no: ");
    scanf("%s",s.phone);
    if(strlen(s.phone)>10||strlen(s.phone)!=10)
	{
		printf("\n\t Sorry :( Invalid. Contact no. must contain 10 numbers. Enter again :)");
		goto D;
	}
	else
	{
		for (b=0;b<strlen(s.phone);b++)
		{
			if (!isalpha(s.phone[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Contact no. contain Invalid character :(  Enter again :)");
			goto D;
		}
	}
}while(!valid);
/* ************************************************** Email ******************************************** */
do
{
    printf("\n\t\t\tEmail: ");
    scanf("%s",s.email);
    if (strlen(s.email)>30||strlen(s.email)<8)
    {
       printf("\n\t Invalid :( \t The max range for email is 30 and min range is 8 :)");	
	}
}while(strlen(s.email)>30||strlen(s.email)<8);


	fprintf(ek,"%s %s %s %s %s %s \n",s.id,s.fname,s.lname,s.address,s.phone,s.email);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(ek);//ek file is closed
    sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
	{
    	Add_Supplier();
	}
    else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
    	getch();
    	SupplierMenu();
	}
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
}
/* ******************************************* List Supplier ***************************************** */
void List_Supplier()
{
	int row;
	system("cls");
	Title();
	FILE *ek;
	ek=fopen("supplier.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! List Suppliers Record !!!!!!!!!!!!!\n");
		gotoxy(1,15);
		printf("Supplier ID");
		gotoxy(20,15);
		printf("Full Name");
		gotoxy(45,15);
		printf("Address");
		gotoxy(60,15);
		printf("Phone No.");
		gotoxy(75,15);
		printf("Email-id");	
		gotoxy(1,16);
		printf("=======================================================================================================================");
		row=17;
		while(fscanf(ek,"%s %s %s %s %s %s \n",s.id,s.fname,s.lname,s.address,s.phone,s.email)!=EOF)
		{
			gotoxy(1,row);
			printf("%s",s.id);
			gotoxy(20,row);
			printf("%s %s",s.fname,s.lname);
			gotoxy(45,row);
			printf("%s",s.address);
			gotoxy(60,row);
			printf("%s",s.phone);
			gotoxy(75,row);
			printf("%s", s.email);
			row++;
		}
		fclose(ek);
		getch();
		SupplierMenu();
}
/* ******************************************* Search Suppliers ***************************************** */

void Search_Supplier(void)
{
	int row;
	char name[20];
	system("cls");
	Title();// call Title function
	FILE *ek;
	ek=fopen("supplier.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Search Suppliers Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Supplier Id to be viewed:");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %s %s %s %s \n",s.id,s.fname,s.lname,s.address,s.phone,s.email)!=EOF)
	{
		if(strcmp(s.id,name)==0)
		{
		gotoxy(1,15);
		printf("Supplier ID");
		gotoxy(20,15);
		printf("Full Name");
		gotoxy(45,15);
		printf("Address");
		gotoxy(60,15);
		printf("Phone No.");
		gotoxy(75,15);
		printf("Email-id");	
		gotoxy(1,16);
		printf("=======================================================================================================================");
		row=17;
			gotoxy(1,row);
			printf("%s",s.id);
			gotoxy(20,row);
			printf("%s %s",s.fname,s.lname);
			gotoxy(45,row);
			printf("%s",s.address);
			gotoxy(60,row);
			printf("%s",s.phone);
			gotoxy(75,row);
			printf("%s", s.email);
			break;
		}
	   }
	   if(strcmp(s.id,name)!=0)
	   {
		gotoxy(5,10);
		printf("Record not found!");
		getch();
	   }
	fclose(ek);
	L:
	getch();
	printf("\n\n\t\t\tDo you want to view more[Y/N]??");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        Search_Supplier();
    }
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
    	getch();
		SupplierMenu();
    }
	else
    {
    	printf("\n\tInvalid Input.\n");
    	goto L;
    }
}
/* ******************************************* Edit Supplier ***************************************** */

void Edit_Supplier(void)
{
	FILE *ek, *ft;
  int i,b, valid=0;
  char ch;
  char name[20];

  system("cls");
  	Title();// call Title window
 		ft=fopen("temp2.txt","w+");
	   ek=fopen("supplier.txt","r");
	   if(ek==NULL)
	   {
		printf("\n\t Can not open file!! ");
		getch();
		SupplierMenu();
	   }
       	printf("\n\n\t\t\t!!!!!!!!!!!!!! Edit Supplier Record !!!!!!!!!!!!!\n");
	   	gotoxy(12,13);
	   	printf("Enter the Supplier ID of the Supplier : ");
	   	scanf(" %s",name);
	   	fflush(stdin);
	   	name[0]=toupper(name[0]);
		gotoxy(12,15);
		
		if(ft==NULL)
		{
			printf("\n Can not open file");
			getch();
			SupplierMenu();
		}
		while(fscanf(ek,"%s %s %s %s %s %s \n",s.id,s.fname,s.lname,s.address,s.phone,s.email)!=EOF)
		{
			if(strcmp(s.id,name)==0)
			{
				valid=1;
				gotoxy(25,17);
				printf("*** Existing Record ***");
				gotoxy(10,19);
				printf("%s \t%s \t%s \t%s \t%s \t%s \n",s.id,s.fname,s.lname,s.address,s.phone,s.email);
				gotoxy(12,22);
				printf("Enter New Supplier ID:");
				scanf("%s",s.id);
				gotoxy(12,24);	
				printf("Enter New First Name: ");
				scanf("%s",s.fname);    
				gotoxy(12,26);
				printf("Enter Last Name: ");
				scanf("%s",s.lname);
				gotoxy(12,28);
				printf("Enter Address: ");
				scanf("%s",s.address);
			    s.address[0]=toupper(s.address[0]);
			    gotoxy(12,30);
				printf("Enter Contact no: ");
				scanf("%s",s.phone);
				gotoxy(12,32);
			    printf("Enter email-id: ");
			    scanf("%s",s.email);
			    printf("\nPress U character for the Updating operation : ");
				ch=getche();
				if(ch=='u' || ch=='U')
				{
				fprintf(ft,"%s %s %s %s %s %s \n",s.id,s.fname,s.lname,s.address,s.phone,s.email);
				printf("\n\n\t\t\tSupplier record updated successfully...");
				}					
			}
			else
			{
			fprintf(ft,"%s %s %s %s %s %s \n",s.id,s.fname,s.lname,s.address,s.phone,s.email);	
			}
		 }
		 if(!valid) printf("\n\t\tNO RECORD FOUND...");
	   fclose(ft);
	   fclose(ek);
	   remove("supplier.txt");
   	   rename("temp2.txt","supplier.txt");
		getch();
		SupplierMenu();		
}

/* ******************************************* Delete Suppliers ***************************************** */

void Delete_Supplier()
{
	char name[20];
	int found=0;
	system("cls");
	Title();// call Title function
	FILE *ek, *ft;
	ft=fopen("temp.txt","w+");
	ek=fopen("supplier.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Delete Supplier Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Supplier ID to delete: ");
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);
	
	while (fscanf(ek,"%s %s %s %s %s %s \n",s.id,s.fname,s.lname,s.address,s.phone,s.email)!=EOF)
	{
		if (strcmp(s.id,name)!=0)
		fprintf(ft,"%s %s %s %s %s %s \n",s.id,s.fname,s.lname,s.address,s.phone,s.email);
		else 
		{
			printf("%s %s %s %s %s %s \n",s.id,s.fname,s.lname,s.address,s.phone,s.email);
			found=1;
		}
	}//while loop ends
	if(found==0)
	{
		printf("\n\n\t\t\t Record not found....");
		getch();
		SupplierMenu();
	}
	else
	{
		fclose(ek);
		fclose(ft);
		remove("supplier.txt");
		rename("temp.txt","supplier.txt");
		printf("\n\n\t\t\t Record deleted successfully :) ");
		getch();
		SupplierMenu();
	}

}
/* ************************************************* Customer Menu ********************************************* */
void CustomerMenu(void)//function decleration
{
	system("cls");
	int choose;
	Title();// call Title function
	
	printf("\n\n\n\n\t\t\t\t1. Add Customer Information\n");
	printf("\n\t\t\t\t2. List Customer Information\n");
	printf("\n\t\t\t\t3. Search Customer Information\n");
	printf("\n\t\t\t\t4. Edit Customer Information\n");
	printf("\n\t\t\t\t5. Delete Customer Information\n");
	printf("\n\t\t\t\t6. Back to Main Menu\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 6:");
	scanf("%i", &choose);
	
	switch(choose)//switch to differeht case
	{
	

    case 1:
    		Add_Customer();
    		break;
	case 2:
			List_Customer();
    		break;
    case 3:
			Search_Customer();
    		break;
    case 4:
			Edit_Customer();
    		break;
    case 5:
			Delete_Customer();
    		break;
	case 6:
			MainMenu();//ex_it function is call
    		break;

	default:
		printf("\t\t\tInvalid entry. Please enter right option :)");
		getch();//holds screen
	}//end of switch
		
	
}

/* **************************************ADD CUSTOMER*******************************************/
void Add_Customer(void)
{
	system("cls");
	Title();// call Title function
	char ans;
	FILE*ek;//file pointer
	ek=fopen("customer.txt","a");//open file in write mode
	printf("\n\t\t*******************************************************");
	printf("\n\t                     ADD NEW CUSTOMER                    ");
	printf("\n\t\t*******************************************************");
	printf("\n\n\t\t  ENTER THE DETAILS BELOW:");
/* ******************************************* STAFF ID ************************************************************** */	    
	
	printf("\n\t\t\tCustomer ID: ");
    scanf("%s",c.id);

/* ******************************************* First Name ************************************************************** */	    

	A:
	printf("\n\t\t\tFirst Name: ");
	scanf("%s",c.fname);
	c.fname[0]=toupper(c.fname[0]);
	if(strlen(c.fname)>20||strlen(c.fname)<2)
	{
		printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)");
		goto A;
	}
	else
	{
		for (b=0;b<strlen(c.fname);b++)
		{
			if (isalpha(c.fname[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t First name contain Invalid character :(  Enter again :)");
			goto A;
		}
	}
/* ******************************************* Last Name ************************************************************** */	    
	
	printf("\n\t\t\tLast Name: ");
    scanf("%s",c.lname);
/* ******************************************* Contact no. ***************************************** */
do
{
	D:
    printf("\n\t\t\tContact no: ");
    scanf("%s",c.phone);
    if(strlen(c.phone)>10||strlen(c.phone)!=10)
	{
		printf("\n\t Sorry :( Invalid. Contact no. must contain 10 numbers. Enter again :)");
		goto D;
	}
	else
	{
		for (b=0;b<strlen(c.phone);b++)
		{
			if (!isalpha(c.phone[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Contact no. contain Invalid character :(  Enter again :)");
			goto D;
		}
	}
}while(!valid);
/* ************************************************** Email ******************************************** */
do
{
    printf("\n\t\t\tEmail: ");
    scanf("%s",c.email);
    if (strlen(c.email)>30||strlen(c.email)<8)
    {
       printf("\n\t Invalid :( \t The max range for email is 30 and min range is 8 :)");	
	}
}while(strlen(c.email)>30||strlen(c.email)<8);


	fprintf(ek,"%s %s %s %s %s \n",c.id,c.fname,c.lname,c.phone,c.email);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    
    fclose(ek);//ek file is closed
    getch();
    List_Medicine();
	
}
/* ******************************************* List Customer ***************************************** */
void List_Customer()
{
	int row;
	system("cls");
	Title();
	FILE *ek;
	ek=fopen("customer.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! List Customer Record !!!!!!!!!!!!!\n");
		gotoxy(1,15);
		printf("Customer ID");
		gotoxy(20,15);
		printf("Full Name");
		gotoxy(45,15);
		printf("Phone No.");
		gotoxy(60,15);
		printf("Email-id");	
		gotoxy(1,16);
		printf("=======================================================================================================================");
		row=17;
		while(fscanf(ek,"%s %s %s %s %s  \n",c.id,c.fname,c.lname,c.phone,c.email)!=EOF)
		{
			gotoxy(1,row);
			printf("%s",c.id);
			gotoxy(20,row);
			printf("%s %s",c.fname,c.lname);
			gotoxy(45,row);
			printf("%s",c.phone);
			gotoxy(60,row);
			printf("%s", c.email);
			row++;
		}
		fclose(ek);
		getch();
		CustomerMenu();
}
/* ******************************************* Search Customer ***************************************** */
void Search_Customer(void)
{
	int row;
	char name[20];
	system("cls");
	Title();// call Title function
	FILE *ek;
	ek=fopen("customer.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Search Customer Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Customer Id to be viewed:");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %s %s %s",c.id,c.fname,c.lname,c.phone,c.email )!=EOF)
	{
		if(strcmp(c.id,name)==0)
		{
		gotoxy(1,15);
		printf("Customer ID");
		gotoxy(20,15);
		printf("Full Name");
		gotoxy(45,15);
		printf("Phone No.");
		gotoxy(60,15);
		printf("Email-id");
		gotoxy(1,16);
		printf("=======================================================================================================================");
		row=17;
			gotoxy(1,row);
			printf("%s",c.id);
			gotoxy(20,row);
			printf("%s %s",c.fname,c.lname);
			gotoxy(45,row);
			printf("%s",c.phone);
			gotoxy(60,row);
			printf("%s", c.email);
			break;
		}
	   }
	   if(strcmp(c.id,name)!=0)
	   {
		gotoxy(5,10);
		printf("Record not found!");
		getch();
	   }
	fclose(ek);
	L:
	getch();
	printf("\n\n\t\t\tDo you want to view more[Y/N]??");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        Search_Customer();
    }
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
    	getch();
		CustomerMenu();
    }
	else
    {
    	printf("\n\tInvalid Input.\n");
    	goto L;
    }
}
/* ******************************************* Edit Customer ***************************************** */
void Edit_Customer(void)
{
	FILE *ek, *ft;
  int i,b, valid=0;
  char ch;
  char name[20];

  system("cls");
  	Title();// call Title window
 		ft=fopen("temp2.txt","w+");
	   ek=fopen("customer.txt","r");
	   if(ek==NULL)
	   {
		printf("\n\t Can not open file!! ");
		getch();
		CustomerMenu();
	   }
       	printf("\n\n\t\t\t!!!!!!!!!!!!!! Edit Customer Record !!!!!!!!!!!!!\n");
	   	gotoxy(12,13);
	   	printf("Enter the Customer ID of the Customer : ");
	   	scanf(" %s",name);
	   	fflush(stdin);
	   	name[0]=toupper(name[0]);
		gotoxy(12,15);
		
		if(ft==NULL)
		{
			printf("\n Can not open file");
			getch();
			CustomerMenu();
		}
		while(fscanf(ek,"%s %s %s %s %s  \n",c.id,c.fname,c.lname,c.phone,c.email)!=EOF)
		{
			if(strcmp(c.id,name)==0)
			{
				valid=1;
				gotoxy(25,17);
				printf("*** Existing Record ***");
				gotoxy(10,19);
				printf("%s \t%s \t%s \t%s \t%s  \n",c.id,c.fname,c.lname,c.phone,c.email);
				gotoxy(12,22);
				printf("Enter New Customer ID:");
				scanf("%s",c.id);
				gotoxy(12,24);	
				printf("Enter New First Name: ");
				scanf("%s",c.fname);    
				gotoxy(12,26);
				printf("Enter Last Name: ");
				scanf("%s",c.lname);
				gotoxy(12,28);
				printf("Enter Contact no: ");
				scanf("%s",c.phone);
				gotoxy(12,30);
			    printf("Enter email-id: ");
			    scanf("%s",c.email);
			    printf("\nPress U character for the Updating operation : ");
				ch=getche();
				if(ch=='u' || ch=='U')
				{
				fprintf(ft,"%s %s %s %s %s  \n",c.id,c.fname,c.lname,c.phone,c.email);
				printf("\n\n\t\t\tCustomer record updated successfully...");
				}					
			}
			else
			{
			fprintf(ft,"%s %s %s %s %s  \n",c.id,c.fname,c.lname,c.phone,c.email);	
			}
		 }
		 if(!valid) printf("\n\t\tNO RECORD FOUND...");
	   fclose(ft);
	   fclose(ek);
	   remove("customer.txt");
   	   rename("temp2.txt","customer.txt");
		getch();
		CustomerMenu();		
}
/* ******************************************* Delete Customer ***************************************** */
void Delete_Customer()
{
	char name[20];
	int found=0;
	system("cls");
	Title();// call Title function
	FILE *ek, *ft;
	ft=fopen("temp.txt","w+");
	ek=fopen("customer.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Delete Customer Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Customer ID to delete: ");
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);
	
	while (fscanf(ek,"%s %s %s %s %s  \n",c.id,c.fname,c.lname,c.phone,c.email)!=EOF)
	{
		if (strcmp(c.id,name)!=0)
		fprintf(ft,"%s %s %s %s %s  \n",c.id,c.fname,c.lname,c.phone,c.email);
		else 
		{
			printf("%s %s %s %s %s  \n",c.id,c.fname,c.lname,c.phone,c.email);
			found=1;
		}
	}//while loop ends
	if(found==0)
	{
		printf("\n\n\t\t\t Record not found....");
		getch();
		CustomerMenu();
	}
	else
	{
		fclose(ek);
		fclose(ft);
		remove("customer.txt");
		rename("temp.txt","customer.txt");
		printf("\n\n\t\t\t Record deleted successfully :) ");
		getch();
		CustomerMenu();
	}

}
/* ************************************************* Medicine Menu ********************************************* */
void MedicineMenu(void)//function decleration
{
	system("cls");
	int choose;
	Title();// call Title function
	
	printf("\n\n\n\n\t\t\t\t1. Add Medicine Information\n");
	printf("\n\t\t\t\t2. View Medicine Information\n");
	printf("\n\t\t\t\t3. Search Medicine Information\n");
	printf("\n\t\t\t\t4. Edit Medicine Information\n");
	printf("\n\t\t\t\t5. Delete Medicine Information\n");
	printf("\n\t\t\t\t6. Back to Main Menu\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 6:");
	scanf("%i", &choose);
	
	switch(choose)//switch to differeht case
	{
	

    case 1:
    		Add_Medicine();
    		break;
    case 2:
			View_Medicine();
    		break;
	case 3:
			Search_Medicine();
    		break;
    case 4:
			Edit_Medicine();
    		break;
    case 5:
			Delete_Medicine();
    		break;
	case 6:
			MainMenu();//ex_it function is call
    		break;

	default:
		printf("\t\t\tInvalid entry. Please enter right option :)");
		getch();//holds screen
	}//end of switch
		
	
}

/* **************************************ADD Medicine*******************************************/
void Add_Medicine(void)
{
	system("cls");
	Title();// call Title function
	char ans;
	FILE*ek;//file pointer
	ek=fopen("medicine.txt","a");//open file in write mode
	printf("\n\t\t*******************************************************");
	printf("\n\t                     ADD NEW MEDICINE                    ");
	printf("\n\t\t*******************************************************");
	printf("\n\n\t\t  ENTER THE DETAILS BELOW:");
/* ******************************************* Medicine ID ************************************************************** */	    
	
	printf("\n\t\t\tMedicine ID: ");
    scanf("%s",m.id);

/* ******************************************* First Name ************************************************************** */	    

	printf("\n\t\t\tMedicine Name: ");
	scanf("%s %s",m.fname,m.lname);
	
/* ******************************************* Manufacture Date ***************************************** */
	printf("\n\t\t\tManfacturing Date: ");
    scanf("%s",m.mdate);
/* ******************************************* Expiry Date ***************************************** */
	printf("\n\t\t\tExpiry Date: ");
    scanf("%s",m.edate);
    
/* ******************************************* Medicine Price ***************************************** */
	printf("\n\t\t\tMedicine Price: ");
    scanf("%s",m.price);

	fprintf(ek,"%s %s %s %s %s %s \n",m.id,m.fname,m.lname,m.mdate,m.edate,m.price);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(ek);//ek file is closed
    sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
	{
    	Add_Medicine();
	}
    else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
    	getch();
    	MedicineMenu();
	}
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
}
/* ******************************************* List Medicine ***************************************** */
void List_Medicine()
{
	int row;
	system("cls");
	Title();
	FILE *ek;
	ek=fopen("medicine.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! List Medicine Record !!!!!!!!!!!!!\n");
		gotoxy(1,10);
		printf("Medicine ID");
		gotoxy(20,10);
		printf("Medicine Name");
		gotoxy(45,10);
		printf("Manufacture-Date");
		gotoxy(70,10);
		printf("Expiry-Date");	
		gotoxy(85,10);
		printf("Price: ");
		gotoxy(1,11);
		printf("=======================================================================================================================");
		row=12;
		while(fscanf(ek,"%s %s %s %s %s %s  \n",m.id,m.fname,m.lname,m.mdate,m.edate,m.price)!=EOF)
		{
			gotoxy(1,row);
			printf("%s",m.id);
			gotoxy(20,row);
			printf("%s %s",m.fname,m.lname);
			gotoxy(45,row);
			printf("%s",m.mdate);
			gotoxy(70,row);
			printf("%s", m.edate);
			gotoxy(85,row);
			printf("%s",m.price);
			row++;
		}
		fclose(ek);
		Add_Purchase();
}
/* ******************************************* View Medicine ***************************************** */
void View_Medicine()
{
	int row;
	system("cls");
	Title();
	FILE *ek;
	ek=fopen("medicine.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! View Medicine Record !!!!!!!!!!!!!\n");
		gotoxy(1,15);
		printf("Medicine ID");
		gotoxy(20,15);
		printf("Medicine Name");
		gotoxy(45,15);
		printf("Manufacture-Date");
		gotoxy(70,15);
		printf("Expiry-Date");	
		gotoxy(85,15);
		printf("Price: ");
		gotoxy(1,16);
		printf("=======================================================================================================================");
		row=17;
		while(fscanf(ek,"%s %s %s %s %s %s  \n",m.id,m.fname,m.lname,m.mdate,m.edate,m.price)!=EOF)
		{
			gotoxy(1,row);
			printf("%s",m.id);
			gotoxy(20,row);
			printf("%s %s",m.fname,m.lname);
			gotoxy(45,row);
			printf("%s",m.mdate);
			gotoxy(70,row);
			printf("%s", m.edate);
			gotoxy(85,row);
			printf("%s",m.price);
			row++;
		}
		fclose(ek);
		getch();
		MedicineMenu();
}

/* ******************************************* Search Medicine ***************************************** */
void Search_Medicine(void)
{
	int row;
	char name[20];
	system("cls");
	Title();// call Title function
	FILE *ek;
	ek=fopen("medicine.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Search Medicine Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Medicine Id to be viewed:");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %s %s %s %s",m.id,m.fname,m.lname,m.mdate,m.edate,m.price )!=EOF)
	{
		if(strcmp(m.id,name)==0)
		{
		gotoxy(1,15);
		printf("Medicine ID");
		gotoxy(20,15);
		printf("Medicine Name");
		gotoxy(45,15);
		printf("Manufacture-Date");
		gotoxy(70,15);
		printf("Expiry-Date");	
		gotoxy(85,15);
		printf("Price: ");
		gotoxy(1,16);
		printf("=======================================================================================================================");
		row=17;
			gotoxy(1,row);
			printf("%s",m.id);
			gotoxy(20,row);
			printf("%s %s",m.fname,m.lname);
			gotoxy(45,row);
			printf("%s",m.mdate);
			gotoxy(70,row);
			printf("%s", m.edate);
			gotoxy(85,row);
			printf("%s",m.price);
			break;
		}
	   }
	   if(strcmp(m.id,name)!=0)
	   {
		gotoxy(5,10);
		printf("Record not found!");
		getch();
	   }
	fclose(ek);
	L:
	getch();
	printf("\n\n\t\t\tDo you want to view more[Y/N]??");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        Search_Medicine();
    }
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
    	getch();
		MedicineMenu();
    }
	else
    {
    	printf("\n\tInvalid Input.\n");
    	goto L;
    }
}
/* ******************************************* Edit Medicine ***************************************** */
void Edit_Medicine(void)
{
	FILE *ek, *ft;
  int i,b, valid=0;
  char ch;
  char name[20];

  system("cls");
  	Title();// call Title window
 		ft=fopen("temp2.txt","w+");
	   ek=fopen("medicine.txt","r");
	   if(ek==NULL)
	   {
		printf("\n\t Can not open file!! ");
		getch();
		MedicineMenu();
	   }
       	printf("\n\n\t\t\t!!!!!!!!!!!!!! Edit Medicine Record !!!!!!!!!!!!!\n");
	   	gotoxy(12,13);
	   	printf("Enter the Medicine ID of the Medicine : ");
	   	scanf(" %s",name);
	   	fflush(stdin);
	   	name[0]=toupper(name[0]);
		gotoxy(12,15);
		
		if(ft==NULL)
		{
			printf("\n Can not open file");
			getch();
			MedicineMenu();
		}
		while(fscanf(ek,"%s %s %s %s %s %s  \n",m.id,m.fname,m.lname,m.mdate,m.edate,m.price)!=EOF)
		{
			if(strcmp(m.id,name)==0)
			{
				valid=1;
				gotoxy(25,17);
				printf("*** Existing Record ***");
				gotoxy(10,19);
				printf("%s \t%s \t%s \t%s \t%s \t%s \n",m.id,m.fname,m.lname,m.mdate,m.edate,m.price);
				gotoxy(12,22);
				printf("Enter New Medicine ID:");
				scanf("%s",m.id);
				gotoxy(12,24);	
				printf("Enter New Medicine  Name: ");
				scanf("%s %s",m.fname,m.lname);    
				gotoxy(12,26);
				printf("Enter Manufactured Date: ");
				scanf("%s",m.mdate);
				gotoxy(12,28);
			    printf("Enter Expiry Date: ");
			    scanf("%s",m.edate);
			    gotoxy(12,30);
			    printf("Enter New Price: ");
			    scanf("%s",m.price);
				printf("\nPress U character for the Updating operation : ");
				ch=getche();
				if(ch=='u' || ch=='U')
				{
				fprintf(ft,"%s %s %s %s %s %s \n",m.id,m.fname,m.lname,m.mdate,m.edate,m.price);
				printf("\n\n\t\t\tMedicine record updated successfully...");
				}					
			}
			else
			{
			fprintf(ft,"%s %s %s %s %s %s\n",m.id,m.fname,m.lname,m.mdate,m.edate,m.price);	
			}
		 }
		 if(!valid) printf("\n\t\tNO RECORD FOUND...");
	   fclose(ft);
	   fclose(ek);
	   remove("medicine.txt");
   	   rename("temp2.txt","medicine.txt");
		getch();
		MedicineMenu();		
}
/* ******************************************* Delete Medicine ***************************************** */
void Delete_Medicine()
{
	char name[20];
	int found=0;
	system("cls");
	Title();// call Title function
	FILE *ek, *ft;
	ft=fopen("temp.txt","w+");
	ek=fopen("medicine.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Delete Medicine Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Medicine ID to delete: ");
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);
	
	while (fscanf(ek,"%s %s %s %s %s %s  \n",m.id,m.fname,m.lname,m.mdate,m.edate,m.price)!=EOF)
	{
		if (strcmp(m.id,name)!=0)
		fprintf(ft,"%s %s %s %s %s %s  \n",m.id,m.fname,m.lname,m.mdate,m.edate,m.price);
		else 
		{
			printf("%s %s %s %s %s %s  \n",m.id,m.fname,m.lname,m.mdate,m.edate,m.price);
			found=1;
		}
	}//while loop ends
	if(found==0)
	{
		printf("\n\n\t\t\t Record not found....");
		getch();
		MedicineMenu();
	}
	else
	{
		fclose(ek);
		fclose(ft);
		remove("medicine.txt");
		rename("temp.txt","medicine.txt");
		printf("\n\n\t\t\t Record deleted successfully :) ");
		getch();
		MedicineMenu();
	}

}

/* ************************************************* Purchase Menu ********************************************* */
void PurchaseMenu(void)//function decleration
{
	system("cls");
	int choose;
	Title();// call Title function
	

	printf("\n\t\t\t\t1. List Purchase Information\n");
	printf("\n\t\t\t\t2. Search Purchase Information\n");
	printf("\n\t\t\t\t3. Edit Purchase Information\n");
	printf("\n\t\t\t\t4. Delete Purchase Information\n");
	printf("\n\t\t\t\t5. Back to Main Menu\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 5:");
	scanf("%i", &choose);
	
	switch(choose)//switch to differeht case
	{
	

	case 1:
			List_Purchase();
    		break;
    case 2:
			Search_Purchase();
    		break;
    case 3:
			Edit_Purchase();
    		break;
    case 4:
			Delete_Purchase();
    		break;
	case 5:
			MainMenu();//ex_it function is call
    		break;

	default:
		printf("\t\t\tInvalid entry. Please enter right option :)");
		getch();//holds screen
	}//end of switch
		
	
}

/* **************************************ADD Purchase*******************************************/
void Add_Purchase(void)
{

	char ans;
	FILE*ek;//file pointer
	ek=fopen("purchase.txt","a");//open file in write mode
	
	printf("\n\t\t*******************************************************");
	printf("\n\t                     PURCHASE MEDICINE                   ");
	printf("\n\t\t*******************************************************");
	printf("\n\n\t\t  ENTER THE DETAILS BELOW:");
/* ******************************************* Medicine ID ************************************************************** */	    
	
	printf("\n\t\t\tPurchase ID: ");
    scanf("%s",p.no);

/* ******************************************* Medicine Name ************************************************************** */	    
	printf("\n\t\t\tMedicine Name: ");
	scanf("%s %s",p.medicine_name1,p.medicine_name2);

/* ******************************************* Quantity ************************************************************** */	    
	
	printf("\n\t\t\tQuantity : ");
    scanf("%s",p.quantity);

	fprintf(ek,"%s %s %s %s \n",p.no,p.medicine_name1,p.medicine_name2,p.quantity);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(ek);//ek file is closed
    sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
	{
    	Add_Purchase();
	}
    else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
    	getch();
    	Add_Bill();
	}
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
}
/* ******************************************* List Purchase ***************************************** */
void List_Purchase()
{
	int row;
	system("cls");
	Title();
	FILE *ek;
	ek=fopen("purchase.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! List Purchase Record !!!!!!!!!!!!!\n");
		gotoxy(1,15);
		printf("Purchase ID");
		gotoxy(20,15);
		printf("Medicine Name");
		gotoxy(50,15);
		printf("Quantity: ");
		gotoxy(1,16);
		printf("=======================================================================================================================");
		row=17;
		while(fscanf(ek,"%s %s %s %s  \n",p.no,p.medicine_name1,p.medicine_name2,p.quantity)!=EOF)
		{
			gotoxy(1,row);
			printf("%s",p.no);
			gotoxy(20,row);
			printf("%s %s",p.medicine_name1,p.medicine_name2);
			gotoxy(50,row);
			printf("%s",p.quantity);
			row++;
		}
		fclose(ek);
		getch();
		PurchaseMenu();
}
/* ******************************************* Search Purchase ***************************************** */
void Search_Purchase(void)
{
	int row;
	char name[20];
	system("cls");
	Title();// call Title function
	FILE *ek;
	ek=fopen("purchase.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Search Purchase Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Purchase Id to be viewed:");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %s %s",p.no,p.medicine_name1,p.medicine_name2,p.quantity )!=EOF)
	{
		if(strcmp(p.no,name)==0)
		{
		gotoxy(1,15);
		printf("Purchase ID");
		gotoxy(20,15);
		printf("Medicine Name");
		gotoxy(50,15);
		printf("Quantity: ");
		gotoxy(1,16);
		printf("=======================================================================================================================");
		row=17;
				gotoxy(1,row);
			printf("%s",p.no);
			gotoxy(20,row);
			printf("%s %s",p.medicine_name1,p.medicine_name2);
			gotoxy(50,row);
			printf("%s",p.quantity);
			break;
		}
	   }
	   if(strcmp(p.no,name)!=0)
	   {
		gotoxy(5,10);
		printf("Record not found!");
		getch();
	   }
	fclose(ek);
	L:
	getch();
	printf("\n\n\t\t\tDo you want to view more[Y/N]??");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        Search_Purchase();
    }
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
    	getch();
		PurchaseMenu();
    }
	else
    {
    	printf("\n\tInvalid Input.\n");
    	goto L;
    }
}
/* ******************************************* Edit Purchase ***************************************** */
void Edit_Purchase(void)
{
	FILE *ek, *ft;
  int i,b, valid=0;
  char ch;
  char name[20];

  system("cls");
  	Title();// call Title window
 		ft=fopen("temp2.txt","w+");
	   ek=fopen("purchase.txt","r");
	   if(ek==NULL)
	   {
		printf("\n\t Can not open file!! ");
		getch();
		PurchaseMenu();
	   }
       	printf("\n\n\t\t\t!!!!!!!!!!!!!! Edit Purchase Record !!!!!!!!!!!!!\n");
	   	gotoxy(12,13);
	   	printf("Enter the Purchase ID : ");
	   	scanf(" %s",name);
	   	fflush(stdin);
	   	name[0]=toupper(name[0]);
		gotoxy(12,15);
		
		if(ft==NULL)
		{
			printf("\n Can not open file");
			getch();
			PurchaseMenu();
		}
		while(fscanf(ek,"%s %s %s %s   \n",p.no,p.medicine_name1,p.medicine_name2,p.quantity)!=EOF)
		{
			if(strcmp(p.no,name)==0)
			{
				valid=1;
				gotoxy(25,17);
				printf("*** Existing Record ***");
				gotoxy(10,19);
				printf("%s \t%s \t%s \t%s  \n",p.no,p.medicine_name1,p.medicine_name2,p.quantity);
				gotoxy(12,22);
				printf("Enter New Purchase ID:");
				scanf("%s",p.no);
				gotoxy(12,24);	
				printf("Enter New Medicine Name: ");
				scanf("%s %s",p.medicine_name1,p.medicine_name2);    
				gotoxy(12,26);
				printf("Enter Quantity: ");
				scanf("%s",p.quantity);
				printf("\nPress U character for the Updating operation : ");
				ch=getche();
				if(ch=='u' || ch=='U')
				{
				fprintf(ft,"%s %s %s %s  \n",p.no,p.medicine_name1,p.medicine_name2,p.quantity);
				printf("\n\n\t\t\tMedicine record updated successfully...");
				}					
			}
			else
			{
			fprintf(ft,"%s %s %s %s \n",p.no,p.medicine_name1,p.medicine_name2,p.quantity);	
			}
		 }
		 if(!valid) printf("\n\t\tNO RECORD FOUND...");
	   fclose(ft);
	   fclose(ek);
	   remove("purchase.txt");
   	   rename("temp2.txt","purchase.txt");
		getch();
		PurchaseMenu();		
}
/* ******************************************* Delete Purchase ***************************************** */
void Delete_Purchase()
{
	char name[20];
	int found=0;
	system("cls");
	Title();// call Title function
	FILE *ek, *ft;
	ft=fopen("temp.txt","w+");
	ek=fopen("purchase.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Delete Purchase Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Purchase ID to delete: ");
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);
	
	while (fscanf(ek,"%s %s %s %s  \n",p.no,p.medicine_name1,p.medicine_name2,p.quantity)!=EOF)
	{
		if (strcmp(p.no,name)!=0)
		fprintf(ft,"%s %s %s %s   \n",p.no,p.medicine_name1,p.medicine_name2,p.quantity);
		else 
		{
			printf("%s %s %s %s  \n",p.no,p.medicine_name1,p.medicine_name2,p.quantity);
			found=1;
		}
	}//while loop ends
	if(found==0)
	{
		printf("\n\n\t\t\t Record not found....");
		getch();
		PurchaseMenu();
	}
	else
	{
		fclose(ek);
		fclose(ft);
		remove("purchase.txt");
		rename("temp.txt","purchase.txt");
		printf("\n\n\t\t\t Record deleted successfully :) ");
		getch();
		PurchaseMenu();
	}

}
/* ************************************************* Billing Menu ********************************************* */
void Bill_Menu(void)//function decleration
{
	system("cls");
	int choose;
	Title();// call Title function
	

	printf("\n\t\t\t\t1. View Bill Information\n");
	printf("\n\t\t\t\t2. Search Bill  Information\n");
	printf("\n\t\t\t\t3. Delete Bill Information\n");
	printf("\n\t\t\t\t4. Back to Main Menu\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 4:");
	scanf("%i", &choose);
	
	switch(choose)//switch to differeht case
	{
	

	case 1:
			List_Bill();
    		break;
    case 2:
			Search_Bill();
    		break;
    case 3:
			Delete_Bill();
    		break;
	case 4:
			MainMenu();//ex_it function is call
    		break;

	default:
		printf("\t\t\tInvalid entry. Please enter right option :)");
		getch();//holds screen
	}//end of switch
		
	
}

/* **************************************ADD Bill*******************************************/
void Add_Bill(void)
{
	
	system("cls");
	Title();// call Title function
	char ans;
	FILE*ek;//file pointer
	ek=fopen("bill.txt","a");//open file in write mode
	
	printf("\n\t\t*******************************************************");
	printf("\n\t                     MEDICINE BILL                       ");
	printf("\n\t\t*******************************************************");
	printf("\n\n\t\t  ENTER THE DETAILS BELOW:");
/* ******************************************* Bill ID ************************************************************** */	    
	
	printf("\n\t\t\tBill Number: ");
    scanf("%s",bill.billno);

/* ******************************************* Customer Name ************************************************************** */	    
	printf("\n\t\t\tCustomer Name: ");
	scanf("%s %s",bill.cfname,bill.clname);

/* ******************************************* Medicine Name ************************************************************** */	    
	printf("\n\t\t\tMedicine Name: ");
	scanf("%s %s",bill.mfname,bill.mlname);
	
/* ******************************************* Quantity ************************************************************** */	    
	printf("\n\t\t\tQuantity : ");
    scanf("%i",&bill.quantity);
/* ******************************************* Price ************************************************************** */	    
	printf("\n\t\t\tPrice for each  : ");
    scanf("%i",&bill.price);

	bill.total= bill.quantity*bill.price;

	fprintf(ek,"%s %s %s %s %s %i %i %i \n",bill.billno,bill.cfname,bill.clname,bill.mfname,bill.mlname,bill.quantity,bill.price,bill.total);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(ek);//ek file is closed
    getch();
    List_Bill();
}
/* ******************************************* List Bill ***************************************** */
void List_Bill()
{
	int row;
	system("cls");
	Title();
	FILE *ek;
	ek=fopen("bill.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! List Bill Record !!!!!!!!!!!!!\n");
		gotoxy(1,15);
		printf("Bill No.");
		gotoxy(10,15);
		printf("Customer Name");
		gotoxy(35,15);
		printf("Medicine Name");
		gotoxy(60,15);
		printf("Quantity ");
		gotoxy(70,15);
		printf("Price-for-each ");
		gotoxy(90,15);
		printf("Total ");
		gotoxy(1,16);
		printf("=======================================================================================================================");
		row=17;
		while(fscanf(ek,"%s %s %s %s %s %i %i %i \n",bill.billno,bill.cfname,bill.clname,bill.mfname,bill.mlname,&bill.quantity,&bill.price,&bill.total)!=EOF)
		{
			gotoxy(1,row);
			printf("%s",bill.billno);
			gotoxy(10,row);
			printf("%s %s",bill.cfname,bill.clname);
			gotoxy(35,row);
			printf("%s %s",bill.mfname,bill.mlname);
			gotoxy(60,row);
			printf("%i",bill.quantity);
			gotoxy(70,row);
			printf("%i",bill.price);
			gotoxy(90,row);
			printf("%i",bill.total);
			row++;
		}
		fclose(ek);
		getch();
		MainMenu();
}
/* ******************************************* Search Bill ***************************************** */
void Search_Bill(void)
{
	int row;
	char name[20];
	system("cls");
	Title();// call Title function
	FILE *ek;
	ek=fopen("bill.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Search Bill Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Bill Number to be viewed:");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %s %s %s %i %i %i \n",bill.billno,bill.cfname,bill.clname,bill.mfname,bill.mlname,&bill.quantity,&bill.price,&bill.total)!=EOF)
	{
		if(strcmp(bill.billno,name)==0)
		{
		gotoxy(1,15);
		printf("Bill No.");
		gotoxy(10,15);
		printf("Customer Name");
		gotoxy(35,15);
		printf("Medicine Name");
		gotoxy(60,15);
		printf("Quantity ");
		gotoxy(70,15);
		printf("Price-for-each ");
		gotoxy(90,15);
		printf("Total ");
		gotoxy(1,16);
		printf("=======================================================================================================================");
		row=17;
			gotoxy(1,row);
			printf("%s",bill.billno);
			gotoxy(10,row);
			printf("%s %s",bill.cfname,bill.clname);
			gotoxy(35,row);
			printf("%s %s",bill.mfname,bill.mlname);
			gotoxy(60,row);
			printf("%i",bill.quantity);
			gotoxy(70,row);
			printf("%i",bill.price);
			gotoxy(90,row);
			printf("%i",bill.total);
			break;
		}
	   }
	   if(strcmp(bill.billno,name)!=0)
	   {
		gotoxy(5,10);
		printf("Record not found!");
		getch();
	   }
	fclose(ek);
	L:
	getch();
	printf("\n\n\t\t\tDo you want to view more[Y/N]??");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        Search_Bill();
    }
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
    	getch();
		Bill_Menu();
    }
	else
    {
    	printf("\n\tInvalid Input.\n");
    	goto L;
    }
}
/* ******************************************* Delete Bill ***************************************** */
void Delete_Bill()
{
	char name[20];
	int found=0;
	system("cls");
	Title();// call Title function
	FILE *ek, *ft;
	ft=fopen("temp.txt","w+");
	ek=fopen("bill.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Delete Bill Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Bill Number to delete: ");
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);
	
	while (fscanf(ek,"%s %s %s %s %s %i %i %i \n",bill.billno,bill.cfname,bill.clname,bill.mfname,bill.mlname,&bill.quantity,&bill.price,&bill.total)!=EOF)
	{
		if (strcmp(bill.billno,name)!=0)
		fprintf(ft,"%s %s %s %s %s %i %i %i \n",bill.billno,bill.cfname,bill.clname,bill.mfname,bill.mlname,bill.quantity,bill.price,bill.total);
		else 
		{
			printf("%s %s %s %s %s %i %i %i \n",bill.billno,bill.cfname,bill.clname,bill.mfname,bill.mlname,bill.quantity,bill.price,bill.total);
			found=1;
		}
	}//while loop ends
	if(found==0)
	{
		printf("\n\n\t\t\t Record not found....");
		getch();
		Bill_Menu();
	}
	else
	{
		fclose(ek);
		fclose(ft);
		remove("bill.txt");
		rename("temp.txt","bill.txt");
		printf("\n\n\t\t\t Record deleted successfully :) ");
		getch();
		Bill_Menu();
	}

}


