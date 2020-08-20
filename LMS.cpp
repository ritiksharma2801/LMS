#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<iomanip>
#include<fstream>
using namespace std;

void AdministratorMenu();
void MainMenu();
void CreateBookRecord();
void ModifyStudentRecord();
void ModifyBookRecord();
void DisplaySpecificStudent(char);
void DisplaySpecificBook(char);
void BookIssue();
void DisplayAllBooks();
void DisplayAllStudents();
void CreateStudentRecord();
void DeleteStudentRecord();
void DeleteBookRecord();
void BookDeposit();

class Book
{
	char bookno[10];
	char bookname[50];
	char authorname[20];
	
	public:
		
		void CreateBook()
		{
			cout<<"\n\n\t\t\t\t\t\t NEW BOOK ENTRY ";
		
			cout<<"\n\n\t\t\t\t\t Enter Book Name:  ";
			gets(bookname);
		
			cout<<"\n\t\t\t\t\t Enter Book No. :  ";
			cin>>bookno;
		
			cout<<"\n\t\t\t\t\t Enter Author's Name:  ";
			gets(authorname);
			
			cout<<"\n\n\n\t\t\t\t\t\t Creating Book...";
			sleep(2);
			cout<<"\n\n\n\t\t\t\t\t\t\t BOOK CREATED :) ";
		}
		
		void DisplayBook()
		{
			cout<<"\n\n\t\t\t\t\t\t BOOK DETAILS...";
			
			cout<<"\n\n\t\t\t\t\t Book Name:  ";
			puts(bookname);
			
			cout<<"\n\t\t\t\t\t Book No. :  "<<bookno;
			
			cout<<"\n\t\t\t\t\t Author's Name:  ";
			puts(authorname);
		}
		
		void ModifyBook()
		{
			cout<<"\n\n\t Book Number:  "<<bookno;
			
			cout<<"\n\t Modified Book Name:  ";
			gets(bookname);
			
			cout<<"\n\t Modified Author's Name:  ";
			gets(authorname);
		}
		
		char* returnbookno()
		{
			return bookno;
		}
		
		void report()
		{
			cout<<bookno<<setw(10)<<bookname<<setw(10)<<authorname;	
		}
		
};

class Student
{
	char rollno[10];
	char studentname[20];
	char studentbookno[10];
	int token;
	
	public:
		
		void CreateStudent()
		{
			cout<<"\n\n\t\t\t\t\t\t NEW STUDENT ENTRY ";
		
			cout<<"\n\n\t\t\t\t\t Enter Student Name:  ";
			gets(studentname);
		
			cout<<"\n\t\t\t\t\t Enter Student No. :  ";
			cin>>rollno;			
			
			token=0;
			studentbookno[0]="\o";
			
			cout<<"\n\n\n\t\t\t\t\t\t Creating Student Record...";
			sleep(2);
			cout<<"\n\n\n\t\t\t\t\t\t\t STUDENT RECORD CREATED :) ";
		}
		
		void DisplayStudent()
		{
			cout<<"\n\n\t\t\t\t\t\t STUDENT DETAILS...";
			
			cout<<"\n\n\t\t\t\t\t Student Name:  ";
			puts(studentname);
			
			cout<<"\n\t\t\t\t\t Roll No. :  "<<rollno;
			
			cout<<"\n\t\t\t\t\t Book Issued by the Student are:  "<<token;
			if(token==1)
				cout<<"\n\t\t\t\t\t Book No. :  "<<studentbookno;
			
		}
		
		void ModifyStudent()
		{
			cout<<"\n\n\t\t\t\t\t\t Roll No. :  "<<rollno;
			
			cout<<"\n\n\t\t\t\t\t\t Enter Name you want to Modify:  ";
			gets(studentname);
		}
		
		char* returnrollno()
		{
			return rollno;
		}
		
		char* returnbookno(int bno[])
		{
			return studentbookno(bno[]);
		}
		
		int returntoken()
		{
			return token;
		}
		
		int addtoken()
		{
			token=1;
		}
		
		int resettoken()
		{
			token=0;
		}
		
		void studentbookno(char t[])
		{
			strcpy(studentbookno,t);
		}
		
		void report()
		{
			cout<<rollno<<setw(30)<<studentname<<setw(30)<<token;	
		}
					
};

fstream fbook, fstudent;
Book book;
Student student;

main()
{	
	cout<<"\t\t\t\t\t\t LIBRARY MANAGEMENT SYSTEM \n\n\n";
	cout<<"\t\t\t\t Developer: RITIK SHARMA";
	
	sleep(2);
	system("CLS");
	
	MainMenu();
	
}

void MainMenu()
{
	int choice;
	
	do
	{
	
	cout<<"\n\t\t\t\t\t\t MAIN MENU \n\n";
	cout<<"\t\t\t\t 1. BOOK ISSUE. \n";
	cout<<"\t\t\t\t 2. BOOK DEPOSIT. \n";
	cout<<"\t\t\t\t 3. AMINISTRATOR MENU. \n";
	cout<<"\t\t\t\t 4. EXIT(). \n";
	cout<<"\n\n\t\t\t\t Enter your Choice(1-4):  ";
	cin>>choice;
	
	switch(choice)
	{
		case 1: BookIssue();
				break;
				
		case 2: BookDeposit();
				break; 
		
		case 3: sleep(1);
				system("CLS");
				AdministratorMenu();				
				break;  
								
		case 4: cout<<"Exiting...";
				sleep(2);
				exit(0);   
								
		default: 	cout<<"Ivalid Input!!! \n";
					cout<<"Terminating...";
					sleep(1);
					exit(0);      
					
	}
	
	}
	while(choice!=4);
}

void AdministratorMenu()
{
	int choicenum;
	
	cout<<"\n\t\t\t\t\t\t	ADMINISTRATOR MENU ";
	cout<<"\n\n\t\t\t\t\t 1.  Create Student Record.";
	cout<<"\n\t\t\t\t\t 2.  Display All Students Record.";
	cout<<"\n\t\t\t\t\t 3.  Display Specific Student Record.";
	cout<<"\n\t\t\t\t\t 4.  Modify Student Record.";
	cout<<"\n\t\t\t\t\t 5.  Delete Student Record.";
	cout<<"\n\t\t\t\t\t 6.  Create Book Record.";
	cout<<"\n\t\t\t\t\t 7.  Display All Books.";
	cout<<"\n\t\t\t\t\t 8.  Display Specific Book.";
	cout<<"\n\t\t\t\t\t 9.  Modify Book Record.";
	cout<<"\n\t\t\t\t\t 10. Delete Book Record.";
	cout<<"\n\n\t\t\t\t\t 11. BACK TO MAIN MENU.";
	cout<<"\n\n\t\t\t\t\t Enter Your Choice:  ";
	cin>>choicenum;
	
	switch(choicenum)
	{
		case 1: CreateStudentRecord();
				break;
				
		case 2: DisplayAllStudents();
				break;
				
		case 3: char rollno[10];
				cout<<"\n Enter the Roll no. of the Student you Record of:  ";
				cin>>rollno;
				DisplaySpecificStudent(rollno); 
				break;
				
		case 4:	ModifyStudentRecord();
				break;
				
		case 5: DeleteStudentRecord();
				break;
				
		case 6: CreateBookRecord();
				break;
				
		case 7: DisplayAllBooks();
				break;
				
		case 8: char bookno[10];
				cout<<"Enter the No. of the Book you Want to See:  ";
				cin>>bookno; 
				DisplaySpecificBook(bookno);
				break;
	
		case 9: ModifyBookRecord();
				break;
		
		case 10: DeleteBookRecord();
				break;
				
		case 11: break;
				 
		default: cout<<"\n\t INVALI INPUT !!! ";
				 cout<<"\n\t TRY AGAIN !";
				 sleep(1);
				 system("CLS");
				 AdministratorMenu();
				 break;
				 
				 	
	}
	
	sleep(1);
	system("CLS");
	MainMenu();
}

void CreateBookRecord()
{
	char choice;
	
	fbook.open("Book.dat",ios::out|ios::app);
	
	do
	{
		book.CreateBook();
		fbook.write((char*)&book,sizeof(Book));
		
		cout<<"\n Do you want to Add More Record (yes/no)?:  ";
		cin>>choice;
	}
	while(choice!='no'||choice!='No');
	
	fbook.close();
}

void CreateStudentRecord()
{
	char choice;
	
	fstudent.open("Student.dat",ios::out|ios::app);
	
	do
	{
		student.CreateStudent();
		fstudent.write((char*)&student,sizeof(Student));
		
		cout<<"\nDo you want to Add More Record (yes/no)?:  ";
		cin>>choice;
	}
	while(choice!='no'||choice!='No');
	
	fstudent.close();
}

void DisplaySpecificBook(char n[])
{
	int flag=0;
	
	fbook.open("Book.dat", ios::in);
	
	while(fbook.read((char *)&book,sizeof(Book)))
	{
		if(strcmpi(book.returnbookno(),n)==0)
		{
			book.DisplayBook();
			flag++;
		}
	}
	
	fbook.close();
	
	if(flag==0)
		cout<<"\n Book Record Not Found !!! ";
		
	sleep(2);
	AdministratorMenu();
}

void DisplaySpecificStudent(char n[])
{
	int flag=0;
	
	fstudent.open("Student.dat", ios::in);
	
	while(fstudent.read((char *)&student,sizeof(Student)))
	{
		if(strcmpi(student.returnrollno(),n)==0)
		{
			student.DisplayStudent();
			flag++;
		}
	}
	
	fstudent.close();
	
	if(flag==0)
		cout<<"\n Student Record Not Found !!! ";
		
	sleep(2);
	AdministratorMenu();
}

void ModifyBookRecord()
{
	char n[10];
	int found=0,pos;
	
	cout<<"\n MODIFY BOOK RECORD ";
	cout<<"\n\n Enter th Book No. :  ";
	cin>>n;
	
	fbook.open("Book.dat",ios::in||ios::out);
	
	while(fbook.read((char*)&book,sizeof(Book)))
	{
		if(strcmpi(book.returnbookno(),n)==0)
		{
			book.DisplayBook();
			cout<<"\n Enter the Details of New Book:  ";
			book.ModifyBook();
			
			int position= -1*sizeof(book);
			
			fbook.seekp(pos,ios::cur);
			fbook.write((char *)&book,sizeof(Book));
			
			cout<<"\n\n\t\t UPDATING RECORD... ";
			sleep(2);
			cout<<"\n\n\t\t RECORD UPDATED... ";
			
			found=1;
		}
	}
	
	fbook.close();
	
	if(found==0)
		cout<<"\n\nt RECORD NOT FOUND !!! ";
}

void ModifyStudentRecord()
{
	char n[10];
	int found=0,pos;
	
	cout<<"\n MODIFY STUDENT RECORD ";
	cout<<"\n\n Enter th Roll No. :  ";
	cin>>n;
	
	fstudent.open("Student.dat",ios::in||ios::out);
	
	while(fstudent.read((char*)&student,sizeof(Student)))
	{
		if(strcmpi(student.returnrollno(),n)==0)
		{
			student.DisplayStudent();
			cout<<"\n Enter the Details of New Student:  ";
			student.ModifyStudent();
			
			int position= -1*sizeof(student);
			
			fstudent.seekp(pos,ios::cur);
			fstudent.write((char *)&student,sizeof(Student));
			
			cout<<"\n\n\t\t UPDATING RECORD... ";
			sleep(2);
			cout<<"\n\n\t\t RECORD UPDATED... ";
			
			found=1;
		}
	}
	
	fstudent.close();
	
	if(found==0)
		cout<<"\n\nt RECORD NOT FOUND !!! ";
}

void DeleteStudentRecord()
{
	char n[10];
	int flag=0;
	
	cout<<"\n\t\t\t\t\t\t DELETE STUDENT ";
	cout<<"\n\n\t\t\t\t\t Enter the Roll no. of the Student you want to delete Record of:  ";
	cin>>n;
	
	fstudent.open("Student.dat",ios::in||ios::out);
	
	fstream file;
	
	file.open("Temporary.dat",ios::out);
	fstudent.seekg(0,ios::beg);
	
	while(fstudent.read((char*)&student,sizeof(Student)))	
	{
		if(strcmpi(student.returnrollno(),n)!=0)
		{
			file.write((char*)&student,sizeof(Student));
		}
		
		else
		{
			flag=1;
		}
	}
	
	file.close();
	fstudent.close();
	
	remove("Student.dat");
	rename("Temporary.dat","Student.dat");
	
	if(flag==1)
	{	cout<<"\n\n\t\t\t\t\tRECORD FOUND...DELETING ";
		sleep(2);
		cout<<"\n\t\t\t\t\tRECORD DELETED... ";
	}
	else
	{
		cout<<"\n\n\t\t\t\t\t RECORD NOT FOUND !!! ";
	}
		
}

void DeleteBookRecord()
{
	char n[10];
	int flag=0;
	
	cout<<"\n\t\t\t\t\t\t DELETE BOOK ";
	cout<<"\n\n\t\t\t\t\t Enter the Book no. of the Book you want to delete Record of:  ";
	cin>>n;
	
	fbook.open("Book.dat",ios::in||ios::out);
	
	fstream file;
	
	file.open("Temporary.dat",ios::out);
	fbook.seekg(0,ios::beg);
	
	while(fbook.read((char*)&book,sizeof(Book)))	
	{
		if(strcmpi(book.returnbookno(),n)!=0)
		{
			file.write((char*)&book,sizeof(Book));
		}
		
		else
		{
			flag=1;
		}
	}
	
	file.close();
	fbook.close();
	
	remove("Book.dat");
	rename("Temporary.dat","Book.dat");
	
	if(flag==1)
	{	cout<<"\n\n\t\t\t\t\tRECORD FOUND...DELETING ";
		sleep(2);
		cout<<"\n\t\t\t\t\tRECORD DELETED... ";
	}
	else
	{
		cout<<"\n\n\t\t\t\t\t RECORD NOT FOUND !!! ";
	}
		
}

void DisplayAllStudents()
{
	fstudent.open("Student.dat",ios::in);
	
	if(!fstudent)
		cout<<"\n\n\t\t\t\t\t File Not Found or Could Not Be Opened !!! ";
		
	else
	{
		cout<<"\n\n\t\t\t\t\t\t STUDENTS LIST ";
		cout<<"\n\n\t ROLL NO. "<<setw(10)<<"\t NAME "<<setw(10)<<"\t BOOK ISSUED ";
		
		while(fstudent.read((char *)&student,sizeof(Student)))
		{
			student.report();
		}
	}
	
	fstudent.close();
	
}

void DisplayAllBooks()
{
	fbook.open("Book.dat",ios::in);
	
	if(!fbook)
		cout<<"\n\n\t\t\t\t\t File Not Found or Could Not Be Opened !!! ";
		
	else
	{
		cout<<"\n\n\t\t\t\t\t\t BOOKS LIST ";
		cout<<"\n\n\t BOOK NO. "<<setw(10)<<"\t BOOK NAME "<<setw(10)<<"\t AUTHOR NAME ";
		
		while(fbook.read((char *)&book,sizeof(Book)))
		{
			book.report();
		}
	}
	
	fbook.close();
	
}

void BookIssue()
{
	char studentrollno[10], bookno[10];
	int found=0,flag=0;
	
	cout<<"\n\n\t\t\t\t\t\t BOOK ISSUE ";
	cout<<"\n\n\t\t\t\t\t Enter the Roll no. of the Student:  ";
	cin>>studentrollno;
	
	fstudent.open("Student.dat", ios::in||ios::out);
	fbook.open("Book.dat",ios::in || ios::out);
	
	while(fstudent.read((char*)&student,sizeof(Student)) && found==0)
	{
		if(strcmpi(student.returnrollno(),studentrollno)==0)
		{
			found=1;
			
			if(student.returntoken()==0)
			{
				cout<<"\n\t ENter the Book no. :  ";
				cin>>bookno;
				
				while(fbook.read((char*)&book,sizeof(Book)) && flag==0)
				{
					
					if(strcmpi(book.returnbookno(),bookno)==0)
					{
						flag=1;
						
						student.addtoken();
						student.studentbookno(book.returnbookno());
						int pos = -1*sizeof(student);
						
						fstudent.seekg(pos,ios::cur);
						fstudent.write((char *)&student,sizeof(Student));
						
						cout<<"\n\n BOOK ISSUED SUCCESSFULLY... \n\n\t\t PLEASE NOTE: BOOK IS ISSUED FOR 15 DAYS, AFTER THAT THERE WILL BE FINE ";
						cout<<"OF RS 10/- AFTER THAT RETURNING PERIOD... \n\n\t\t\t\t HAVE A NICE DAY ";
					}
				}
				
				if(flag==0)
					cout<<"\n\n\t BOOK RECORD NOT FOUND...";
			}
			
			else
				cout<<"\n\n\t You have not Returned the Last Book... ";
		}
	}
	
	if(found==0)
		cout<<"\n\n\t STUDENT RECORD DOES NOT FOUND... ";
		
	fstudent.close();
	fbook.close();	
	
}


void BookDeposit()
{
	char studentrollno[10], bookno[10];
	int found=0,flag=0,day,fine,pos;
	
	cout<<"\n\n\t\t\t\t\t\t BOOK DEPOSIT ";
	cout<<"\n\n\t\t\t\t\t Enter the Roll no. of the Student:  ";
	cin>>studentrollno;
	
	fstudent.open("Student.dat", ios::in||ios::out);
	fbook.open("Book.dat",ios::in || ios::out);
	
	while(fstudent.read((char*)&student,sizeof(Student)) && found==0)
	{
		if(strcmpi(student.returnrollno(),studentrollno)==0)
		{
			found=1;
			
			if(student.returntoken()==0)
			{				
				while(fbook.read((char*)&book,sizeof(Book)) && flag==0)
				{					
					if(strcmpi(book.returnbookno(),student.studentbookno()==0))
					{
						flag=1;
						book.DisplayBook();
						
						cout<<"Enter the Days in which the book is Returned:  ";
						cin>>day;
						
						if(day>15)
						{	fine=(day-15)*10;
							cout<<"Fine that is to be Deposited is Rs. "<<fine;
						}
						
						student.resettoken();
						
						int pos = -1*sizeof(student);
						
						fstudent.seekg(pos,ios::cur);
						fstudent.write((char *)&student,sizeof(Student));
						
						cout<<"\n\n BOOK DEPOSITED SUCCESSFULLY... ";
					}
				}
				
				if(flag==0)
					cout<<"\n\n\t BOOK RECORD NOT FOUND...";
			}
			
			else
				cout<<"\n\n\t NO BOOK IS ISSUED UNDER YOUR NAME... ";
		}
	}
	
	if(found==0)
		cout<<"\n\n\t STUDENT RECORD DOES NOT FOUND... ";
		
	fstudent.close();
	fbook.close();	
	
}














