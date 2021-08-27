#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>
#include<process.h>
#include<string.h>
#include<fstream.h>
#include<graphics.h>

void linel();
void welcome1();
void forl();
void deposit_withdraw(int);
//void write_account();
void display_sp();
void display_all();
void delete_account();
void modify_account();
void loginru();
void loginbm();
void mainpage();
class account
{
	int acno, deposit, withdraw, x;
	char name[50];
	char type;
	public:
	void read()
	{
	   gotoxy(60,8);
	   cin>>acno;
	   gotoxy(60,10);
	   gets(name);
	   gotoxy(60,12);
	   cin>>type;
	   gotoxy(60,14);
	   cin>>deposit;
	   }
	   void show_account()
{
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
setbkcolor(0);
setcolor(14);
settextstyle(1,0,4);
outtextxy(175,25,"ACCOUNT STATUS:");
setcolor(11);
settextstyle(8,0,1);
outtextxy(45,100,"ACCOUNT NUMBER:");
gotoxy(60,8);
cout<<acno;
outtextxy(45,135,"ACCOUNT HOLDER NAME:");
gotoxy(60,10);
cout<<name;
outtextxy(45,170,"TYPE OF ACCOUNT:");
gotoxy(60,12);
cout<<type;
outtextxy(45,205,"BALANCE:");
gotoxy(60,14);
cout<<deposit;
}

	void modify_account()
	{       setcolor(10);
		settextstyle(8,0,1);
		outtextxy(45,275,"Account No.: ");
		gotoxy(60,19);
		cin>>acno;
		outtextxy(45,310,"Modify Account Holder Name : ");
		gotoxy(60,21);
		gets(name);
		outtextxy(45,345,"Modify Type of Account : ");
		gotoxy(60,23);
		cin>>type;
		outtextxy(45,380,"Modify Balance amount: ");
		gotoxy(60,25);
		cin>>deposit;
	}
	void dep(int x)
	{
		deposit+=x;
	}
	void draw(int x)
	{
		deposit-=x;
	}
	void report()
	{
		gotoxy(8,13);cout<<acno<<"\t\t"<<name<<"\t\t"<<type<<"\t\t" 			<<deposit<<endl;
	}
	int retacno()
	{
		return acno;
	}
	float retdeposit()
	{	return deposit;
	}
	char rettype()
	{
		return type;
	}
};

fstream fp;
account ac;

	void create_account()
	{       cleardevice();
		setcolor(9);
		outtextxy(80,25,"NEW ACCOUNT ENTRY FORM");
		settextstyle(8,0,1);
		setcolor(10);
		outtextxy(45,100,"Enter The account Number");
		outtextxy(45,135,"Name of The account Holder: ");
		outtextxy(45,170,"Type of account (C/S) : ");
		outtextxy(45,200,"Amount>=500 for S & >=1000 for C");
		fp.open("account.dat",ios::out|ios::app);
		ac.read();
		fp.write((char*)&ac,sizeof(ac));
		fp.close();
		getch();
		mainpage();
	}
void exit()
{
  exit(0);

}
void bankem()
{
int choice;
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
setbkcolor(0);
forl();
linel();
setcolor(11);
settextstyle(1,0,4);
setcolor(7);
outtextxy(155,50,"BANK EMPLOYEE PORTAL");
settextstyle(7,0,4);
setcolor(10);
outtextxy(150,100,"1.Deposit amount");
outtextxy(150,150,"2.Withdraw amount");
outtextxy(150,200,"3.All account holder list");
outtextxy(150,250,"4.Close an account");
outtextxy(150,300,"5.Modify an account");
outtextxy(150,350,"6.Exit");
cin>>choice;
switch(choice)
{
case 1:
deposit_withdraw(1);
getch();
break;
case 2:
deposit_withdraw(2);
getch();
break;
case 3:
display_all();
getch();
break;
case 4:
delete_account();
getch();
break;
case 5:
modify_account();
getch();
break;
case 6:
exit();
getch();
break;
};
}
void registered_user()
{
int choice;
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
forl();
linel();
setbkcolor(0);
settextstyle(1,0,4);
setcolor(10);
outtextxy(155,50,"Registered User");
settextstyle(7,0,4);
setcolor(11);
outtextxy(150,100,"1.New account");
outtextxy(150,150,"2.Balance enquiry");
outtextxy(150,200,"3.Close an account");
outtextxy(150,250,"4.Exit");
cin>>choice;
switch(choice)
{
case 1:
create_account();
getch();
break;
case 2:
display_sp();
getch();
break;
case 3:
delete_account();
getch();
break;
case 4:
exit();
getch();
break;
};
}
void linel()
{
setcolor(14);
line(15,10,622,10);
delay(150);
line(15,10,15,466);
delay(150);
line(15,466,622,466);
delay(150);
line(622,466,622,10);
delay(150);
line(25,20,611,20);
delay(150);
line(25,20,25,455);
delay(150);
line(25,455,611,455);
delay(150);
line(611,455,611,20);
}
void mainpage();
void mainpage()
{
int choice;
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
setbkcolor(0);
forl();
linel();
settextstyle(1,0,4);
setcolor(10);
outtextxy(155,50,"CHOOSE ANY OPTION...");
settextstyle(7,0,4);
setcolor(11);
outtextxy(150,100,"1.BANK EMPLOYEE");
outtextxy(150,150,"2.REGISTERED USER");
outtextxy(150,200,"3.NEW USER");
outtextxy(150,250,"4.EXIT");
cin>>choice;
switch(choice)
{
case 1:
loginbm();
getch();
break;
case 2:
loginru();
getch();
break;
case 3:
create_account();
getch();
break;
case 4:
exit();
getch();
break;
};
}
void loginbm()
{
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
char *username,*password;
forl();
linel();
setbkcolor(0);
settextstyle(4,0,4);
setcolor(10);
outtextxy(50,30,"BANKING MANAGEMENT SYSTEM");
setcolor(14);
settextstyle(1,0,4);
outtextxy(100,100,"LOGIN FOR BANK EMOPLYEE");
settextstyle(7,0,1);
setcolor(3);
rectangle(270,170,420,195);
outtextxy(150,170,"USERNAME");
settextstyle(7,0,1);
rectangle(270,220,420,245);
outtextxy(150,220,"PASSWORD");
setcolor(7);
settextstyle(3,0,3);
setcolor(14);
ellipse(300,315,0,360,75,25);
gotoxy(35,12);
gets(username);
int i;
for(i=0;i<12;i++)
{
gotoxy(35+i,15);
password[i]=getch();
cout<<"*";
}
password[i]='\0';
if((strcmpi(username,"username")==0)&&(strcmpi(password,"bankemployee")==0))
{
while(!kbhit())
{
setcolor(BLUE);
outtextxy(250,300,"continue");
delay(80);
setcolor(CYAN);
outtextxy(250,300,"continue");
delay(200);
bankem();
 }
}
else
{
while(!kbhit())
{
setcolor(BLUE);
outtextxy(250,300,"incorrect");
delay(200);
setcolor(CYAN);
outtextxy(250,300,"incorrect");
delay(500);
mainpage();
}
exit();
}
getch();
}
void loginru()
{
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
char *username,*password;
setbkcolor(0);
forl();
linel();
settextstyle(4,0,4);
setcolor(8);
outtextxy(50,30,"BANKING MANAGEMENT SYSTEM");
setcolor(9);
settextstyle(1,0,4);
outtextxy(175,100,"LOGIN FOR USER");
settextstyle(7,0,1);
setcolor(6);
rectangle(270,170,420,195);
outtextxy(150,170,"USERNAME");
settextstyle(7,0,1);
rectangle(270,220,420,245);
outtextxy(150,220,"PASSWORD");
setcolor(7);
settextstyle(3,0,3);
setcolor(14);
ellipse(300,315,0,360,75,25);
gotoxy(35,12);
gets(username);
int i;
for(i=0;i<10;i++)
{
gotoxy(35+i,15);
password[i]=getch();
cout<<"*";
}
password[i]='\0';
if((strcmpi(username,"username")==0)&&(strcmpi(password,"registered")==0))
{
while(!kbhit())
{
setcolor(BLUE);
outtextxy(250,300,"continue");
delay(80);
setcolor(CYAN);
outtextxy(250,300,"continue");
delay(200);
registered_user();
 }
}
else
{
while(!kbhit())
{
setcolor(BLUE);
outtextxy(250,300,"incorrect");
delay(200);
setcolor(CYAN);
outtextxy(250,300,"incorrect");
delay(500);
mainpage();
}
}
getch();
}
void forl()
{
	setcolor(14);
	int x;
	for(x=1;x<635;x++)
	{
		outtextxy(x,1,"/");
		delay(1);
	}
		for(x=1;x<635;x++)
	{
		outtextxy(x,470,"/");
		delay(1);
	}
	for(x=1;x<1000;x++)
	{
		outtextxy(632,x,"/");
		delay(1);
		outtextxy(1,x,"/");
		delay(1);
	}

}

void welcome()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	setbkcolor(0);
	forl();
	setcolor(2);
	line(325,75,25,300);
	delay(250);
	line(325,75,600,300);
	delay(250);
	line(25,300,600,300);
	delay(250);
	line(325,375,600,150);
	delay(250);
	line(325,375,25,150);
	delay(250);
	line(25,150,600,150);
	outtextxy(250,180,"Please Wait....");
	int u=0;
	for(int i=1;i<=10;i++)
	{
		outtextxy(250+u,200,"%");
		delay(200);
		u=u+15;
	}
	outtextxy(400,200,"100%");
	outtextxy(250,220,"Ready to go");
	delay(200);
	outtextxy(370,220,"!");
	delay(200);
	outtextxy(380,220,"!");
	outtextxy(380,350,"PRESS ANY KEY TO CONTINUE");
	getch();
	welcome1();
}
void welcome1()
{       cleardevice();
	forl();
	setbkcolor(0);
	settextstyle(1,0,4);
	setcolor(5);
	delay(250);
	outtextxy(225,50,"WELCOME TO");
	settextstyle(1,0,4);
	delay(250);
	outtextxy(80,100,"BANKING MANAGEMENT SYSTEM");
	settextstyle(6,0,1);
	delay(250);
	setcolor(11);
	outtextxy(20,200,"Devloped By:-1.Vaibhav");
	outtextxy(130,220,"2.Vaibhavi");
	outtextxy(130,240,"3.Sharon");
	outtextxy(130,260,"4.Priyanshi");
	outtextxy(130,280,"5.Rakshita");
	outtextxy(130,300,"6.Ritik");
	outtextxy(130,320,"7.Taksh");
	settextstyle(6,0,1);
	delay(250);
	setcolor(2);
	outtextxy(375,400,"Press any key to continue..");
	getch();
}
void display_sp()
{
	cleardevice();
	linel();
	int n;
	settextstyle(1,0,4);
	setcolor(10);
	outtextxy(175,25,"BALANCE DETAILS");
	settextstyle(8,0,4);
	setcolor(6);
	settextstyle(8,0,1);
	outtextxy(45,100,"Enter the Account Number : ");
	gotoxy(60,8);
	cin>>n;
	int flag=0;
	fp.open("account.dat",ios::in);
	while(fp.read((char*)&ac,sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
	{
	       outtextxy(60,18,"Account Number does not exist");
	}
	getch();
}

void modify_account()
{       cleardevice();
	linel();
	int no,found=0;
	settextstyle(1,0,4);
	setcolor(10);
	outtextxy(175,25,"MODIFY RECORD");
	settextstyle(8,0,1);
	setcolor(6);
	outtextxy(45,100,"Enter the Account No. : ");
	gotoxy(60,8);
	cin>>no;
	fp.open("account.dat",ios::in|ios::out);
	while(fp.read((char*)&ac,sizeof(account)) && found==0)
	{
		if(ac.retacno()==no)
		{       cleardevice();
			linel();
			ac.show_account();
			settextstyle(8,0,2);
			setcolor(11);
			outtextxy(65,240,"Enter the New Details");
			ac.modify_account();
			int pos=-1*sizeof(ac);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&ac,sizeof(ac));
			outtextxy(65,400,"Record Updated");
			found=1;
			//mainpage();
		}
	}
	fp.close();
	if(found==0)
	{
		outtextxy(45,205," Record Not Found ");
	}
	getch();
}

void delete_account()
{       cleardevice();
	linel();
	int no;
	settextstyle(1,0,4);
	setcolor(5);
	outtextxy(175,25,"Delete Record");
	settextstyle(8,0,1);
	setcolor(6);
	outtextxy(45,100,"Enter The Account No. : ");
	gotoxy(60,8);
	cin>>no;
	fp.open("account.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&ac,sizeof(ac)))
	{
		if(ac.retacno()==no)
		{
			fp2.close();
			fp.close();
			remove("account.dat");
			rename("Temp.dat","account.dat");
			outtextxy(45,170,"Record Deleted ..");
		}
		else
		 outtextxy(45,170,"Record not found");
	}

	getch();
}

void display_all()
{       cleardevice();
	linel();
	fp.open("account.dat",ios::in);
	if(!fp)
	{
		setcolor(4);
		settextstyle(8,0,2);
		outtextxy(45,100," ERROR!!! FILE COULD NOT BE OPEN ");
		getch();
		return;
	}
	setcolor(5);
	settextstyle(1,0,4);
	outtextxy(135,25,"ACCOUNT HOLDER LIST");
	setcolor(6);
	settextstyle(8,0,1);
	outtextxy(25,100,"_____________________________________________");
	outtextxy(50,135,"A/c no.      NAME      Type      Balance");
	outtextxy(25,150,"_____________________________________________");
	while(fp.read((char *)&ac,sizeof(account)))
	{
		ac.report();
	}
	fp.close();
	getch();
}

void deposit_withdraw(int option)
{       cleardevice();
	linel();
	int no,found=0,amt;
	setcolor(7);
	settextstyle(1,0,4);
	outtextxy(80,25,"ACCOUNT TRANSCATION FORM");
	setcolor(9);
	settextstyle(8,0,1);
	outtextxy(45,100,"Enter The account No. : ");
	gotoxy(60,8);
	cin>>no;
	fp.open("account.dat",ios::in|ios::out);
	while(fp.read((char*)&ac,sizeof(account)) && found==0)
	{
		if(ac.retacno()==no)
		{
			ac.show_account();
			if(option==1)
			{
				outtextxy(45,300,"Enter The amount to DEPOSIT : ");
				gotoxy(60,20);
				cin>>amt;
				ac.dep(amt);
			}
			if(option==2)
			{
				outtextxy(45,300,"Enter The amount to WITHDRAW : ");
				gotoxy(60,20);
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 &&ac.rettype()=='S')||(bal<1000&&ac.rettype()=='C'))
					outtextxy(45,240,"Insufficient balance");
				else
					ac.draw(amt);
			}
			int pos=-1*sizeof(ac);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&ac,sizeof(account));
			found=1;
		}
	}
	fp.close();
	if(found==0)
	{
		outtextxy(45,205," Record Not Found");
	}
	getch();
}


void main()
{	char ch;
	welcome();
	mainpage();
}
