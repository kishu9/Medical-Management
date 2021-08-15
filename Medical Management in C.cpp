#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<dos.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>

COORD coord = {0, 0};
void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


//functions names------------------------

int i;
int getc_id();

void main_menu();
void bill();
void medicine();
void msale();
void mstock();
void mupdate();
void mentry();
void msearch();
void remainder();
void customer();
void csearch();
void cidsearch();
void cnamesearch();
void centry();
void clist();
void cupdate();
void report_menu();
void sale_rpt();
void sale_rpt_daily();
void profit_rpt();
void pur_rpt();
void pur_rpt_daily();




//===================================structures =========================
struct medical
{
	char id[6];
	char medi_name[20];
	int rack;
	char cabnit[2];
	int quantity;
	float sale;
	float total;
	float unit;
	float cost;
	float profit;
	float bye;
	int qty;
	char pur_date[15];
	char exp_date[15];
	char manu_date[15];
	int bill_no;
	char comp_name[20];
	char supp_name[30];
 };

struct medical temp;
struct medical x[20];
FILE *ptr;

char a[10];
struct supplier
{
	int supp_id;
	char supp_name[25];
	char city[20];
	char mob_no[11];
	char email[30];

};
struct supplier temp1;

struct customer
{
	int cust_id;
	char cust_name[30];
	char city[20];
	char mob_no[11];
	char email[50];

};
struct customer temp_c;
FILE *ptr1;

struct bill
{
	char billno[6];
	char cname[30];
	char mediname[30];
	int medi_qty;
	float medi_rate;
	float total;
	int day;
	int month;
	int year;

};
struct bill bil;
FILE *ptrbill;
struct sales_report
{
	char medi_id[6];
	char medir_name[20];
	char cust_name[30];
	int sDay,sMonth,sYear;
	int qty;
	float rate;
	float total;
};
struct sales_report s_r;
FILE *ptrs_r;

struct purchase_report
{
	char medi_id[6];
	char medir_name[20];
	char supp_name[30];
	int sDay,sMonth,sYear;
	int qty;
	float rate;
	float total;
};
struct purchase_report p_r;
FILE *ptrp_r;

struct profit_report
{
	char medi_id[6];
	char medir_name[20];
	int sDay,sMonth,sYear;
	int qty;
	float rate;
	float unit;
	float profit;
};
struct profit_report pr_r;
FILE *ptrpr_r;

void linkfloat()
{
	float f,*p;
	p=&f;
	f=*p;
}


//time-----------------
int t(){
time_t t= time(0);
struct tm * now=localtime(&t);
printf("date: %d-%d-%d",now->tm_mday,now->tm_mon,now->tm_year);
	printf("Time: %d:%d:%d",now->tm_hour, now->tm_min,now->tm_sec);
	return 0;
}

void ventry(char t[],int code)
{
  int i=0;
	if(code==0)
	{
		while((t[i]=getch())!='\r' && i<30)
		if((t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) || t[i]==32 || t[i]=='_')
		{
			printf("%c",t[i]);
			i++;
		}
		else if(t[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;              //Length counter is decremented.

		}
	}
	else if(code==1)
	{
		while((t[i]=getch())!='\r' && i<10 )
		if((t[i]>=48 && t[i]<=57) || t[i]==46 ||  t[i]=='-')
		{
			printf("%c",t[i]);
			i++;
		}
		else if(t[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;              //Length counter is decremented.

		}
	}
	else if(code==2)
	{
		while((t[i]=getch())!='\r' && i<30 )
		if((t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) ||(t[i]>=48 && t[i]<=57) || t[i]==32 || t[i]==8 ||t[i]=='@'||t[i]=='.')
		{
			printf("%c",t[i]);
			i++;
		}
		else if(t[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;              //Length counter is decremented.

		}
	}

	t[i]='\0';
}

//getc_id_id------------
int getc_id()
{
FILE *fp;
fp=fopen("customer.txt","r");
if(fp==NULL){
printf("DATA NOT FOUND");
getch();
}
else{
temp_c.cust_id=100;
rewind(fp);
while(fscanf(fp,"%d %s %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email)!=EOF)
{
}
}
fclose(fp);
return temp_c.cust_id+1;
}

//main---------------
int main()
{
	char name[15];
	char pass[15];
	int count=0,i;

	system("cls");

	start:

	printf(" LOGIN \n\n\n");


	printf("\nEnter user name :");

	printf("\tEnter password  :");
	
	strcpy(gets(name),name);

	

	i=0;
	do
	{
		pass[i] = getch();
		if(pass[i] == 13 )
		{
			break;
		}
		else if(pass[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;
		}
		else
		{
			printf("*");
			i++;
		}
	}while(pass[i]!=13);
	pass[i] = '\0';

	if(strcmp(name,"hrishabh") || strcmp(pass,"patel"))
	{
	 system("cls");
	
	 printf("\n\nPlease Enter vailid Username & Passward!!!!!\n");
	 count++;
	 
	 printf("%d chance left!!!!",3-count);
	 getch();
	 system("cls");
	 if(count==3)
	 exit(0);
	 else
	 goto start;
	}
	else
	{
	 //welcome();
	 main_menu();
	}

}

//===========================main_menu-------------
void main_menu ()
{
   char ch;
    do
   {
    system("cls");
	printf("Customer Info\n");
	printf("Medicine\n");
	printf("Report\n");
	printf("Bill\n");
	printf("Exit\n");
	t();
	printf("Welcome To Medical Store of Bhopal");
	remainder();
	printf("\n\n\nPress any character for further menu\n\n\n");
	
	ch=getche();
	switch(ch)
	{
		case 'a': customer();
		          break;
	    case 'b': medicine();
		          break;
		case 'c': report_menu();
		          break;
		case 'd': bill();
		          break;
		case 'e': 
		        printf("\n\n Do you want to continue? y/n : ");
		        Sleep(100);
				ch=getch();
				if(ch=='y')
				{
					system("cls");
					printf("\n\n\nWAIT....\n\n");
					Sleep(2000);
					exit(0);
				}
				else
				{
				    main_menu();
				}
				default:
				printf("Please Enter {'a','b','c','d','e'} ");
				getch();
			}
		}while(ch!='e');
	}
	
//-----------------------customer----	
void customer ()
{
char ch;
do{
	system("cls");

	  printf("\n\n\nCustomer Menu.");
	
	  printf("\nAdd New Customer\n");
	  printf("\nUpdate Customer\n");
      printf("\nSearch Customer\n");
	  printf("\nList of Existing Customer\n");

	  printf("\nMain Menu\n");

	  
	  printf("Press First Character for further Operations  ");

	ch=(getche());
	  switch(ch)
	  {
		case 'a':
			 centry();
			 break;
		case 'b':
			 cupdate();
			 break;
		case 'c':
			 clist();
			 break;
		case 'd':csearch();
			 break;
		case 'e':main_menu();
			 break;
		default:
			
			printf("Plese Enter right character ONLY (a,b,c,d,e).");
			getch();
	  }
	}while(ch!='e');


}
	
//=======================MEDICINE FUNCTION============

 void medicine()
{
	char ch;
	do
	{
	  system("cls");

	  printf("MEDICINE MENU:-");
	  
	 
	  printf("\nPurchase New Medicine\n");
	  printf("\nSale Medicine\n");
	  printf("\nStock of Medicine\n");
	  printf("\nSearch Medicine\n");
	  printf("\nMain Menu\n");
	 
	  printf("Press First Character for further Operations  ");


	  ch=(getche());
	  switch(ch)
	  {
		case 'a':mentry();
			 break;
		case 'b':msale();
			 break;
		case 'c':mstock();
			 break;
		case 'd':msearch();
			 break;
		case 'e':main_menu();
			 break;
		default:
			printf("Plese Enter right character ONLY (a,b,c,d,e).");
			getch();
	  }
	}while(ch!='e');

}

//===================REPORT FUNCTION========
void report_menu()
{
	char ch;
	do
	{
	  system("cls");

	  printf("REPORT MENU");

	  printf("\nPurchase Report\n");
	  printf("\nSale Report\n");
	  printf("\nProfit Report\n");
	  printf("\nDaily Sale Report\n");
	  printf("\nDaily Purchase Report\n");
	  printf("\nMain Menu\n");

	  printf("Press First Character for further Operations  ");


	  ch=(getche());
	  switch(ch)
	  {
		case 'a':pur_rpt();
			 break;
		case 'b':sale_rpt();
			 break;
		case 'c':sale_rpt_daily();
			 break;
		case 'd':profit_rpt();
			 break;
		case 'e':pur_rpt_daily();
			 break;
		case 'f':main_menu();
			 break;
		default://textcolor(4+BLINK);
			gotoxy(11,34);
			printf("Plese Enter right character ONLY (a,b,c,d,e,f).");
			getch();
	  }
	}while(ch!='f');

}


//======================Remainder for medicine stock ===============
void remainder()
{
	ptr1=fopen("medical.txt","r");
	if(ptr1==NULL)
	{
	//	printf("\n\t Can not open File! ");
	}
	while((fread(&temp,sizeof(temp),1,ptr1))==1)
	{
		if(temp.quantity<10)
		{
		
			printf("%s : ",temp.medi_name);
			printf("Quantity of this medicine is less then 10");
		}
	}
}


//========================for bill =============================
void bill()
{
  
    time_t td = time(0);   // get time 
    struct tm * now = localtime( & td );

	   FILE *ptrbill;
	   char id[6];
	   int j=1,d1,m,y,k;
	   float netamt=0.0;
	 
	   d1=now->tm_mday;
	   m=now->tm_mon;
	   y=now->tm_year;
	   system("cls");
	   ptrbill=fopen("dbbill.txt","r");
	   
	   printf("Enter bill no : ");
	   scanf("%s",&id);
	   system("cls");
	 
	
	   printf("Bill No: ");
	   printf(" %s",id);
	 
	   printf("Customer Name: ");

	   printf("Date : ");
	   printf("%d-%d-%d",d1,m,y);
	   gotoxy(7,12);
	   printf("Sr.No\n Medicine Name\n Qty\n Rate\n Total \n ");
	   
	   while(fscanf(ptrbill,"%s %s %s %d %f %f %d %d %d",bil.billno,bil.cname,bil.mediname,&bil.medi_qty,&bil.medi_rate,&bil.total,&bil.day,&bil.month,&bil.year)!=EOF)
	   {

		   do
		  {
			if(strcmp(id,bil.billno)==0)
			{
				
				printf(" %d\n",j);
				
				printf(" %s\n",bil.mediname);
				
				printf(" %s\n",bil.cname);
				
				printf(" %d\n",bil.medi_qty);
				
				printf(" %.2f\n",bil.medi_rate);
				
				printf(" %.2f\n",bil.total);
				
				netamt=netamt+bil.total;
				
				
				printf("Press Any key to go to  MENU ...........\n");

			       //	break;
			}


		}while(feof(ptrbill));

	   }


	   
	   printf("Net Amount : ");
	   printf("%.2f\n\n",netamt);

	   fclose(ptrbill);
	   getch();
}

//==========CUSTOMER FUNCTIONS--------------

//--------------CUSTOMER ENTRY-------------

void centry()
{
 char ch;
 int id;
 FILE *fp;
 system("cls");
	   fp=fopen("customer.txt","a");
	   if(fp==NULL)
	   {
		printf("\n Can not open file!!");
		exit(0);
	   }
	   system("cls");
	   ch='y';
	   while(ch=='y')
	   {
		system("cls");
		
		t();
		
		printf(" CUSTOMER ENTRY \n\n");
		
		temp_c.cust_id=getc_id();
		printf("CUSTOMER ID :%d",temp_c.cust_id);
		
		printf("CUSTOMER NAME : ");
		
		printf("CITY        : ");
		
		printf("CONTACT NO.   : ");
		
		printf("EMAIL ID    : ");

		
		ventry(temp_c.cust_name,0);
		
		ventry(temp_c.city,0);
		
		ventry(temp_c.mob_no,1);
		
		gets(temp_c.email);
		
		
		printf("Save\n");
		
		printf("\nCancel");
		printf("\nPress First charecter for the operation : ");
		ch=getch();
		if(ch=='s' || ch=='S')
		{
			fprintf(fp,"%d %s %s %s %s\n",temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email);
			fprintf(fp,"\n");
			fflush(stdin);
			system("cls");
			
			printf("Customer Added Successfully!!!!!");
			
			printf("More entries  [y/n] ");
			ch=getche();

		}
	   }
	   fclose(fp);
}

//---------------CUSTOMER DISPLAY LIST--------------------

void clist()
{
 char ch;
 system("cls");
	   ptr1=fopen("customer.dat","r");
	   if(ptr1==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	   system("cls");
	  
	   printf("Press Anykey to go to CUSTOMER MENU!!!");
	  
	   printf(" CUSTOMER LIST ");
	  
	  
	   
	   printf(" ID.\n CUSTOMER NAME. \nCITY. \nMOBILE.NO. \nEMAIL. ");
	   
	   while(fscanf(ptr1,"%d %s %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email)!=EOF)
	   {
		
		printf(" %d",temp_c.cust_id);
		
		printf(" %s",temp_c.cust_name);
		
		printf(" %s",temp_c.city);
		
		printf(" %s",temp_c.mob_no);
		
		printf(" %s",temp_c.email);
		
	   }
	   getche();
}
//======================SEARCH FOR CUSTOMER==================
void csearch()
{
  int ch;

	do
	 {
	   system("cls");
	   
	   printf(" Two options Available for searching ");
	   
	   printf("Search by ID NO. \n");

	   
	   printf("Search by NAME\n");
	   
	   printf("\nReturn");
	  
	   printf("Press First charecter for the operation : ");
	   ch=(getche());
	   switch(ch)
	   {
		case 'a':
			cidsearch();
			break;
		case 'b':
			cnamesearch();
			break;
		case 'c':
			customer();
			break;
		default:
			printf("You entered wrong choice!!!!!");
			getch();
	   }
	   }while(ch!='c');
       getche();
}


//===========================Search by CustomerId=========================
void cidsearch()
{
  int id;
  system("cls");

	   ptr1=fopen("customer.txt","rb");
	   
	   printf("\n\n Enter id to be searched:");
	   scanf("%d",&id);
	 
	   printf(" ID.\n CUSTOMER NAME. \nCITY. \nMOBILE.NO. \nEMAIL. ");
	  
	   while(fscanf(ptr1,"%d %s %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email)!=EOF)
	   {
		if(temp_c.cust_id==id)
		{
			
			printf(" %d",temp_c.cust_id);
			
			printf(" %s",temp_c.cust_name);
			
			printf(" %s",temp_c.city);
			
			printf(" %s",temp_c.mob_no);
		
			printf(" %s",temp_c.email);
			
			printf("Press Any key to go to CUSTOMER MENU ...........");
			break;
		}
	   }
	   if(temp_c.cust_id!=id)
	   {
		
		printf("\t\n\nRecord not found!");
	   }
	   fclose(ptr1);
       getche();
}


//*****************************search by CUSTOMERname******************************
void cnamesearch()
{
  char name[20];
  system("cls");
 
	   ptr1=fopen("customer.txt","rb");
	   
	   printf("\n\n  Enter Customer Name to be searched:");
	   scanf("%s",&name);
	   
	
	
	   printf(" ID. \nCUSTOMER NAME. \nCITY. \nMOBILE.NO. \nEMAIL. ");
	   
	   while(fscanf(ptr1,"%d %s %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email)!=EOF)
	   {
		if(strcmp(temp_c.cust_name,name)==0)
		{
			
			printf(" %d",temp_c.cust_id);
			
			printf(" %s",temp_c.cust_name);
			
			printf(" %s",temp_c.city);
			
			printf(" %s",temp_c.mob_no);
			
			printf(" %s",temp_c.email);
		
			
			printf("Press Any key to go to CUSTOMER MENU ...........");
			break;
		}
	   }
	   if(strcmp(temp_c.cust_name,name)!=0)
	   {
		
		printf("\n\nRecord not found!");
	   }
	   fclose(ptr1);
	getche();
}

//============CUSTOMER update=================
void cupdate()
{
  int i;
  char ch;
  int cid;
  FILE *ft;
  system("cls");
  
	   ptr1=fopen("customer.txt","rb+");
	   if(ptr1==NULL)
	   {
		printf("\n\t Can not open file!! ");
		exit(0);
	   }
	   
	   printf(" Modifying customer ");
	  
	   printf("Enter the CUSTOMER ID : ");
	   scanf("%d",&cid);
	   

		ft=fopen("temp.txt","w");
		if(ft==NULL)
		{
			printf("\n Can not open file");
			exit(0);
		}
		else
		{

			while(fscanf(ptr1,"%d %s %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email)!=EOF)
			{
				if(temp_c.cust_id==cid)
				{
					
					printf("*** Existing Record ***");
					
					printf("%d\t %s \t%s \t%s \t%s",temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email);
					
					printf("Enter New Name         : ");
					
					ventry(temp_c.cust_name,0);
					
					printf("Enter New mobile no    : ");
					
					ventry(temp_c.mob_no,1);
					
					printf("Enter New City         : ");
					
					ventry(temp_c.city,0);
					
					printf("Enter New email        : ");
					
					scanf("%s",temp_c.email);
					
					
					printf("\n Update");
					
					printf("\n Cancel");
					
					
					printf("Press First charecter for the operation : ");
					ch=getche();
					if(ch=='u' || ch=='U')
					{
					fprintf(ft,"%d %s %s %s %s\n",temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email);
				       //	fprintf(ft,"\n");
					fflush(stdin);
					
					printf("Customer updated successfully...");
					remove("customer.txt");
					rename("temp.txt","customer.txt");
					}					}
					else
					{
					fprintf(ft,"%d %s %s %s %s\n",temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email);
					fflush(stdin);
					}
				  }


	   fclose(ft);
	   fclose(ptr1);
      }

}


//============================ FOR MEDICINE PURCHASE    ===================
void mentry()
{
  char ch,id[6];

    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
  int f;
  FILE *fp;
  system("cls");
	  

	  ptrp_r=fopen("purreport.txt","a");
	  ch='Y';
	  while(ch=='Y')
	  {
		system("cls");
		
    
		
		printf(" MEDICINE PURSHASE  ");
		{
			
			printf("MEDICINE ID    :\n ");

		
			printf("MEDICINE NAME  : \n ");

			
			printf("ENTER RACK NO  :\n ");

			
			printf("CABNIT NO      :\n ");

			
			printf("COMPANY NAME   :\n");


			
			printf("UNIT COST   Rs.:\n ");

			
			printf("SALE COST   Rs.:\n ");

			
			printf("QUANTITY       :\n  ");

			
			printf("MFG.DATE(dd-mm-yyyy):\n ");

			
			printf("EXP.DATE(dd-mm-yyyy):\n ");

			
			ventry(temp.id,1);
			strcpy(id,temp.id);

			fp=fopen("medical.txt","r");
			while((fread(&temp,sizeof(temp),1,fp))==1)
			{

			if(strcmp(id,temp.id)==0)
			{
				f=1;
				break;
			}
			}
			fclose(fp);
			if(f==1)
			{
				
				printf("ID Allready Exists");
				getche();
				system("cls");
				mentry();
			}
			else
			{
			ptr=fopen("medical.txt","a+b");
			strcpy(temp.id,id);
			strcpy(p_r.medi_id,temp.id);
			}
			
			ventry(temp.medi_name,0);
			strcpy(p_r.medir_name,temp.medi_name);
			
			
			ventry(a,1);
			temp.rack= atoi(a);//atoi() used for convert str to int.
			
			ventry(temp.cabnit,2);
			
			ventry(temp.comp_name,0);
			
			
			
			ventry(a,1);
			temp.unit= atof(a);
			
			p_r.rate=temp.unit;
			
			ventry(a,1);
			temp.sale= atof(a);
			
			
			ventry(a,1);
			temp.quantity= atoi(a);
			p_r.qty=temp.quantity;
		

			ventry(temp.manu_date,1);
			
			
			ventry(temp.exp_date,1);

			
			temp.total=temp.quantity*temp.sale;

			
			printf("TOTAL SALE COST = Rs. %.2f",temp.total);
			temp.cost=(temp.unit*temp.quantity);
			
			printf("TOTAL UNIT COST = Rs. %.2f",temp.cost);
			p_r.total=temp.cost;
			p_r.sDay=now->tm_mday;
			p_r.sMonth=now->tm_mon;
			p_r.sYear=now->tm_year;
		 }
		
		
		
		printf("\n Save ");
		printf("\n Cancel");
		
		printf("Press First charecter for the operation : ");


		ch=(getche());

		if(ch=='s' || ch=='S')
		{
			fwrite(&temp,sizeof(temp),1,ptr);
			fflush(stdin);
			
			fprintf(ptrp_r,"%s %s %s %d %.2f %.2f %d %d %d\n",p_r.medi_id,p_r.medir_name,p_r.supp_name,p_r.qty,p_r.rate,p_r.total,p_r.sDay,p_r.sMonth,p_r.sYear);
			system("cls");
			
			printf("Medicine Added sucessfully!!!!!!");
			
			printf("More entries  [y/n]");
			ch=(getche());
		    if(ch=='y')
			{
				system("cls");
				mentry();
			}
		}

	   }
	   fclose(ptr);
	   fclose(ptrp_r);
}


//===========FOR MEDICINE SALE=========================
void msale()
{
  struct bill bil;
  
  time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
  int j,n,i,a,billno;
  int d1,m,y;
  float b,total,rate;
  char tar[30],ch,mediname[30],c_name[30],cname[30];
  FILE *fp,*fpc;
  int count=0;
 
  d1=now->tm_mday;
  m=now->tm_mon;
  y=now->tm_year;
	   ch='y';
	   while(ch=='y')
	   {
		fp = fopen("dbbill.txt","a");
		ptr1 = fopen("customer.txt","r");
		ptr = fopen("medical.txt","r");
		ptrs_r=fopen("saleRpt.txt","a");
		ptrpr_r=fopen("profitRpt.txt","a");
		system("cls");
		
		
	
		printf("Cust_ID   \n Cust_Name");
		
		while(fscanf(ptr1,"%d %s %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email)!=EOF)
		{
			
			printf("%d\n",temp_c.cust_id);
			
			printf("%s\n",temp_c.cust_name);
			
		}

		
		printf("ENTER MEDICINE ID TO BE SOLD  : ");
		ventry(tar,1);
		//scanf("%s",&tar);
		j=0;
		while((fread(&temp,sizeof(temp),1,ptr))==1)
		{
			if((strcmp(temp.id,tar)<0) || (strcmp(temp.id,tar)>0))
			{
				x[j] = temp;
				j++;
			}
			else if((strcmp(temp.id,tar)==0))
			{

				printf(" Medicine Name        : %s\n",temp.medi_name);
				
				printf(" Quantity in stock    : %d\n",temp.quantity);
				
				printf(" Sales price          : %.2f\n",temp.sale);
				
				printf("Enter bill number     : ");
				
				ventry(bil.billno,1);
				scanf("%s",&bil.billno);
				
				printf("Enter customer Name   : ");
				
				ventry(c_name,0);
				scanf("%s\n",&c_name);
				
				printf("Quantity want to sale : ");
			
				scanf("%d\n",&a);

				pr_r.profit=(temp.sale-temp.unit)*a;
				x[j]=temp;
				x[j].quantity=(x[j].quantity-a);
				x[j].total=(x[j].quantity*temp.sale);
				x[j].cost=(x[j].quantity*temp.unit);
				x[j].bye=(x[j].sale*a);
				b=x[j].bye;
				x[j].qty=a;
				j++;
				count++;
				strcpy(bil.cname,c_name);
				strcpy(s_r.cust_name,c_name);
				strcpy(bil.mediname,temp.medi_name);
				bil.medi_qty=a;
				bil.medi_rate=temp.sale;
				bil.total=temp.sale*a;

				bil.day=d1;
				bil.month=m;
				bil.year=y;

				fprintf(fp,"%s %s %s %d %.2f %.2f %d %d %d\n",bil.billno,bil.cname,bil.mediname,bil.medi_qty,bil.medi_rate,bil.total,bil.day,bil.month,bil.year);
				fflush(stdin);

				fclose(fp);

				s_r.sDay=d1;
				s_r.sMonth=m;
				s_r.sYear=y;
				strcpy(s_r.medi_id,tar);
				strcpy(s_r.medir_name,temp.medi_name);
				s_r.qty=a;
				s_r.rate=temp.sale;
				s_r.total=temp.sale*a;

				//sale report enter
				fprintf(ptrs_r,"%s %s %s %d %.2f %.2f %d %d %d\n",s_r.medi_id,s_r.medir_name,s_r.cust_name,s_r.qty,s_r.rate,s_r.total,s_r.sDay,s_r.sMonth,s_r.sYear);
				fflush(stdin);
				fclose(ptrs_r);
				//profit report here

				pr_r.sDay=d1;
				pr_r.sMonth=m;
				pr_r.sYear=y;
				strcpy(pr_r.medi_id,tar);
				strcpy(pr_r.medir_name,temp.medi_name);
				pr_r.qty=a;
				pr_r.rate=temp.sale;
				pr_r.unit=temp.unit;
				fprintf(ptrpr_r,"%s %s %d %d %d %d %.2f %.2f  %.2f\n",pr_r.medi_id,pr_r.medir_name,d1,pr_r.sMonth,pr_r.sYear,pr_r.qty,pr_r.unit,pr_r.rate,pr_r.profit);
				fflush(stdin);
				fclose(ptrpr_r);

			}
		}
		if (count==0)
		{
			system("cls");
			
			printf("Not in stock!!!!!");
			getch();
			return;
		}
		fclose(ptr1);
		fclose(ptr);
		n = j;
		system("cls");
		ptr=fopen("medical.txt","wb");
		for(i=0; i<n; i++)
		fwrite(&x[i],sizeof(x[i]),1,ptr);
		fclose(ptr);
		system("cls");
		
		
		printf("Price paid by customer = %.2f\n",b);
		
		printf("Quantity sold          = %d\n",a);
		getch();
		
		printf("more enteries=(y/n) :");
		ch=getche();
	   }

}
//===========================MEDICINE STOCK=====================================
void mstock()
{
  char ch;
  int i,c;
	   do
	   {
		system("cls");
		ptr1=fopen("medical.dat","r");
		if(ptr1==NULL)
		{
			printf("\n\t Can not open File! ");
			exit(1);
		}
		system("cls");
		
		printf(" STOCK OF MEDICINE ");
		
		printf("ID.\n  MEDICINE NAME. \nQTY.    \nExp.Date. ");
		
		
		while((fread(&temp,sizeof(temp),1,ptr1))==1)
		{
			
			printf(" %s\n",temp.id);
			
			printf(" %s\n",temp.medi_name);
			
			printf(" %d\n",temp.quantity);
			
			
			printf(" %s\n",temp.exp_date);
			
		}
		
		printf("\nPress [1] for Update Medicine Stock  & [0] for main menu ");
		c = (getche());
		switch (c)
		{
			case '0':
				 main_menu();
				 break;
			case '1':mupdate();
				 break;
		}

	   }while(c != '1');
	   getche();
}
//=============================== FOR MEDICINE SEARCH ====================
void msearch()
{
  char mid[6];
  int i,c;
  system("cls");
	   ptr1=fopen("medical.txt","r");
	   if(ptr1==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	   system("cls");
	  

	  
	   printf("Enter Medicine Id to be searched : ");
	   scanf("%s",&mid);
	   system("cls");
	   
	   printf(" MEDICINE ");
	   
	   
	   printf("ID.   MEDICINE NAME.    QTY     Supplier Name     Exp.Date");
	   
	   
	   while((fread(&temp,sizeof(temp),1,ptr1))==1)
	   {
		if(strcmp(mid,temp.id)==0)
		{

			printf(" %s\n",temp.id);
			
			printf(" %s\n",temp.medi_name);
			
			printf(" %d\n",temp.quantity);
			
			
			printf(" %s\n",temp.exp_date);
			
			break;
		}

	   }
	   if(strcmp(mid,temp.id)!=0)
	   {
		
		printf("\n\nNot in Stock.....\n\n");
	   }
	   getche();

}
//============================ FOR MEDICINE UPDATE =====================
void mupdate()
{
  char mid[6];
  int j,a,count=0,n;
  system("cls");
	   ptr=fopen("medical.txt","rb");
	   if(ptr==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	   system("cls");
	   
	   printf("Press Enter to go to MENU ...........");
	  
	   printf(" UPDATE MEDICINE QUANTITY ");
	  
	  
	   printf("Enter medicine id to be update qty: ");
	   scanf("%s",&mid);
	   j=0;

	   while((fread(&temp,sizeof(temp),1,ptr))==1)
	   {
		if((strcmp(temp.id,mid)<0) || (strcmp(temp.id,mid)>0))
		{
			x[j] = temp;
			j++;
		}
		else
		{
			
			printf("Medicine Name     : %s\n",temp.medi_name);
			
			printf("Quantity in stock : %d\n",temp.quantity);
			
			printf("Quantity want to update : ");
			scanf("%d\n",&a);
			x[j]=temp;
			x[j].quantity=(x[j].quantity+a);
			x[j].total=(x[j].quantity*temp.sale);
			x[j].cost=(x[j].quantity*temp.unit);
			x[j].bye=(x[j].sale*a);
			x[j].qty=a;
			j++;
			count++;
		}
	   }
	   if (count==0)
	   {
		 system("cls");
		
		 printf("Not in stock!!!!!!");
		 getch();
		 return;
	   }
	   fclose(ptr);
	   n = j;
	   system("cls");
	   ptr=fopen("medical.txt","wb");
	   for(i=0; i<n; i++)
	   fwrite(&x[i],sizeof(x[i]),1,ptr);
	   fclose(ptr);
}

//===================== view report functions =============================/
void sale_rpt()
{
  char ch;
  int j;
  system("cls");
	   ptrs_r=fopen("saleRpt.dat","r");
	   if(ptrs_r==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	   system("cls");
	  
	   printf("Press any key to go to REPORT MENU ...........");
	  
	   printf("SALES REPORTS");
	  
	   printf("ID.\n Medicine Name.\n Customer Name.\n   Qty. \n Rate.\n Total.\n  Date.\n");
	  
	   
	   while(fscanf(ptrs_r,"%s %s %s %d %f %f %d %d %d\n",s_r.medi_id,s_r.medir_name,s_r.cust_name,&s_r.qty,&s_r.rate,&s_r.total,&s_r.sDay,&s_r.sMonth,&s_r.sYear)!=EOF)
	   {
		
		printf("%s\n",s_r.medi_id);
		
		printf("%s\n",s_r.medir_name);
		
		printf("%s\n",s_r.cust_name);
		
		printf("%d\n",s_r.qty);
		
		printf("%.2f\n",s_r.rate);
		
		printf("%.2f\n",s_r.total);
		
		printf("%d-%d-%d",s_r.sDay,s_r.sMonth,s_r.sYear);
		
	   }
	   getche();
}
//======================= VIEW PURCHASE REPORT ===========================
void pur_rpt()
{
  char ch;
  int j;
  system("cls");
  t();
  
	   ptrp_r=fopen("purreport.txt","r");
	   if(ptrp_r==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	  
	   printf("Press Enter to go to REPORT MENU ...........");
	  
	   printf("PURCHASE REPORT");
	   
	   printf("ID.\n Medicine Name.\n  Supplier Name.\n   Qty.\n  Rate.\n  Total.\n   Date.\n");
	   
	   while(fscanf(ptrp_r,"%s %s %d %f %f %d %d %d\n",p_r.medi_id,p_r.medir_name,&p_r.qty,&p_r.rate,&p_r.total,&p_r.sDay,&p_r.sMonth,&p_r.sYear)!=EOF)
	   {
		
		printf("%s\n",p_r.medi_id);
		
		printf("%s\n",p_r.medir_name);

		
        printf("%d\n",p_r.qty);
		
		printf("%.2f\n",p_r.rate);
		
		printf("%.2f\n",p_r.total);
		
		printf("%d-%d-%d",p_r.sDay,p_r.sMonth,p_r.sYear);
		
	   }
	   getche();
}


//========================= report of profit ===========================
void profit_rpt()
{
  char ch;
  int j;
  system("cls");
  t();
 
	   ptrpr_r=fopen("profitRpt.dat","r");
	   if(ptrpr_r==NULL)
	   {
		printf("\n\t Can not open File! ");
	       //	exit(0);
	   }
	   
	   printf("Press Enter to go to REPORT MENU ...........");
	  
	   printf("Profit Report");
	  
	  
	   printf("ID.\n Medicine Name.\n   Date.\n  Qty.\n  Unit Price.\n  SalePrice.\n Profit.\n ");
	  
	  
	   while(fscanf(ptrpr_r,"%s %s %d %d %d %d %f %f %f \n",pr_r.medi_id,pr_r.medir_name,&pr_r.sDay,&pr_r.sMonth,&pr_r.sYear,&pr_r.qty,&pr_r.unit,&pr_r.rate,&pr_r.profit)!=EOF)
	   {
		
		printf("%s\n",pr_r.medi_id);
		
		printf("%s\n",pr_r.medir_name);
		
		printf("%d-%d-%d\n",pr_r.sDay,pr_r.sMonth,pr_r.sYear);
		
		printf("%d\n",pr_r.qty);
		
		printf("%.2f\n",pr_r.unit);
		
		printf("%.2f\n",pr_r.rate);
		
		printf("%.2f\n",pr_r.profit);
		
		printf("%c\n",124);
		

	   }
	   getche();
}



//----------------------DAILY SALE REPORT------------------
void sale_rpt_daily()
{
  char ch;
  int j,d,m,y;
  float total=0.00;
  system("cls");
	   ptrs_r=fopen("saleRpt.dat","r");
	   if(ptrs_r==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	   system("cls");
	   
	   printf("Enter Date(dd-mm-yyyy):  ");
	   scanf("%d-%d-%d",&d,&m,&y);
	   system("cls");
	   
	   printf("Press any key to go to REPORT MENU ...........");
	  
	   printf("Sales Report");
	   
	   printf("ID.\n Medicine Name.\n  Customer Name.\n   Qty.\n  Rate.\n  Total.\n   Date.\n");
	   
	   
	   while(fscanf(ptrs_r,"%s %s %s %d %f %f %d %d %d\n",s_r.medi_id,s_r.medir_name,s_r.cust_name,&s_r.qty,&s_r.rate,&s_r.total,&s_r.sDay,&s_r.sMonth,&s_r.sYear)!=EOF)
	   {
		if(d==s_r.sDay &&m== s_r.sMonth && y==s_r.sYear)
		{
		
		printf("%s\n",s_r.medi_id);
		
		printf("%s\n",s_r.medir_name);
		
		printf("%s\n",s_r.cust_name);
		
		printf("%d\n",s_r.qty);
		
		printf("%.2f\n",s_r.rate);
		
		printf("%.2f\n",s_r.total);
		
		printf("%d-%d-%d\n",s_r.sDay,s_r.sMonth,s_r.sYear);
		
		total=total+s_r.total;
		}
	   }
	   
	   printf("Total:        %.2f\n",total);
	   getche();
}


//---------------------DAILY PURCHASE REPORT--------------- 
void pur_rpt_daily()
{
  char ch;
  int j,d,m,y;
  float total=0.00;

	   ptrp_r=fopen("purreport.dat","r");
	   if(ptrp_r==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	   system("cls");
	   
	   printf("Enter Date(dd-mm-yyyy):  ");
	   scanf("%d-%d-%d",&d,&m,&y);
	   system("cls");
	   
	   printf("Press Enter to go to REPORT MENU ...........");
	   t();
	   
	  
	   printf("Purchase Report");
	   ;
	   printf("ID.\n Medicine Name.\n  Supplier Name.\n   Qty.\n  Rate.\n  Total.\n   Date.\n");
	   
	   
	   while(fscanf(ptrp_r,"%s %s %s %d %f %f %d %d %d\n",p_r.medi_id,p_r.medir_name,p_r.supp_name,&p_r.qty,&p_r.rate,&p_r.total,&p_r.sDay,&p_r.sMonth,&p_r.sYear)!=EOF)
	   {
		if(d==p_r.sDay &&m== p_r.sMonth && y==p_r.sYear)
		{
		
		printf("%s\n",p_r.medi_id);
		
		printf("%s\n",p_r.medir_name);
		
		printf("%s\n",p_r.supp_name);
		
		printf("%d\n",p_r.qty);
		
		printf("%.2f\n",p_r.rate);
		
		printf("%.2f\n",p_r.total);
		
		printf("%d-%d-%d\n",p_r.sDay,p_r.sMonth,p_r.sYear);
		
		total=total+p_r.total;
		}
	   }
	  
	   printf("\nTotal:        %.2f\n",total);
	   getche();
}



















