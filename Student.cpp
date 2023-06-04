#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<stdlib.h>
using namespace std;

int main();

void show_data(int searchkey);     
void get_data(int i);           
void search_student(int searchkey);
void add_student();     
void edit_student(int idnumber);  
void fullscreen();
int ts;

struct student    
{ 

  int  rollno; 
  string  name;
  string  fname;
  string  cell;
  string  dob;
  string address;
  string section;
  string bloodgroup;
  
};

 student rec[50]; 
int main()
{



  int choice;   
  int idnumber;  
  int searchkey;  
  cout<<             "\t\t\t********************************************************"<<endl;
  cout<<             "\t\t\t*                                                      *"<<endl;
  cout<<             "\t\t\t*          STUDENT MANEGMENT SYSTEM                    *"<<endl;
  cout<<             "\t\t\t*                                                      *"<<endl;
  cout<<             "\t\t\t********************************************************"<<endl;
  cout<<"Enter The Total Number of Student(s)- Max 50: ";
  cin>>ts;
  if(ts>50){
  	cout<<"Invalid number:"<<endl;
  }
  else{
  	
  

 while(ts--)
 {
  cout<<"\n\t\tWhat do you want to do?"<<endl;
  cout<<"\t\t----------------------"<<endl;
  cout<<"\t\t1-Add student"<<endl;
  cout<<"\t\t2-Edit student"<<endl;
  cout<<"\t\t3-Search student"<<endl;
  cout<<"\t\t4-Quit Program"<<endl;
  cout<<"\t\t----------------------"<<endl;
  cout<<"Enter your choice: ";

  cin>>choice;
  switch(choice)
 {
   case 1:        
    add_student();
    break;
   case 2:         
    if(rec[0].rollno==0)
   {
     cout<<"Please Add sudents first."<<endl;
     system("pause");
    main();
   }
    else       
   {
     cout<<endl;
     cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
     cout<<"---------------------------Student record Table---------------------------------------------------------------------"<<endl;
     cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl; 
     cout<<"ID   "<<"Roll   "<<"Name      "<<"Father\tCell no.      "<<"DOB          "<<"Address	"<<"Section     "<<"BloodgrouP\n\n";
     cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl; 
     
     for(int i=0;i<=ts;i++)
    {
      show_data(i);    
     }

     cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
     cout<<"Which ID number your want to edit: ";
   
     cin>>idnumber;           
       
    if(idnumber>ts || idnumber<0)  
    {      
          cout<<"\nInvalid ID Number."<<endl;
       }
       else
    {
          edit_student(idnumber);    
       }
   }
   break;
   
  case 3:
    if(rec[0].rollno==0)     
   {   
     cout<<"Please Add sudents first."<<endl;
     system("pause");
     main();         
    }
    else
   {
     cout<<"Enter roll_no of student you want to search: ";
     cin>>searchkey;    
     search_student(searchkey);
    
	 }
     break;
   case 4:
   	
    return 0;        
    break;
   default:         
    cout<<"Invalid number."<<endl;
    system("pause");
  main();
}
  }
 }
  cout<<"Enter The Total Number of Student(s)- Max 50: ";
  cin>>ts;
  

 while(ts--)
 {
  cout<<"\n\t\tWhat do you want to do?"<<endl;
  cout<<"\t\t----------------------"<<endl;
  cout<<"\t\t1-Add student"<<endl;
  cout<<"\t\t2-Edit student"<<endl;
  cout<<"\t\t3-Search student"<<endl;
  cout<<"\t\t4-Quit Program"<<endl;
  cout<<"\t\t----------------------"<<endl;
  cout<<"Enter your choice: ";

  cin>>choice;
  
  switch(choice)
 {
   case 1:        
    add_student();

    break;
   case 2:         
    if(rec[0].rollno==0)
   {
     cout<<"Please Add sudents first."<<endl;
     system("pause");
    main();
   }
    else       
   {
     cout<<endl;
     cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
     cout<<"---------------------------Student record Table---------------------------------------------------------------------"<<endl;
     cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl; 
     cout<<"ID   "<<"Roll   "<<"Name      "<<"Father\tCell no.      "<<"DOB          "<<"Address	"<<"Section     "<<"BloodgrouP\n\n";
     cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl; 

     for(int i=0;i<=ts;i++)
    {
      show_data(i);    
     }

     cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
     cout<<"Which ID number your want to edit: ";
   
     cin>>idnumber;
	 
    if(idnumber>ts || idnumber<0)  
    {      
          cout<<"\nInvalid ID Number."<<endl;
       }
       else
    {
          edit_student(idnumber);    
       }
   }
   break;
   
  case 3:
    if(rec[0].rollno==0)     
   {   
     cout<<"Please Add sudents first."<<endl;
     system("pause");
     main();         
    }
    else
   {
     cout<<"Enter roll_no of student you want to search: ";
     cin>>searchkey;    
     search_student(searchkey);}
     
      
     break;
   case 4: 
    return 0;        
    break;
   default:         
    cout<<"Invalid number."<<endl;
    system("pause");
  main();

  }
 }
  return 0;
}



  

  
void get_data(int i)        
{   
  cout<<"Enter student roll number in  format(1XXX): ";
  
  cin>>rec[i].rollno;
  cin.ignore();
  cout<<"Enter student name: ";
  getline(cin,rec[i].name);
  cout<<"Enter student's Father name: ";
  getline(cin,rec[i].fname);
    cout<<"Enter student's cell phone number: ";
  getline(cin,rec[i].cell);


  cout<<"Enter student's Date of Birth(dd/mm/yyyy): ";
  getline(cin,rec[i].dob);
  cout<<"Enter student's Address: ";
  getline(cin,rec[i].address);
  cout<<"Enter student's Section: ";
  getline(cin,rec[i].section);
  cout<<"Enter student's Bloodgroup: ";
  getline(cin,rec[i].bloodgroup);
  
}

void show_data(int searchkey)    
{    
  int i=searchkey;
  cout<<i<<"    ";
  cout<<rec[i].rollno<<"   ";
  cout<<rec[i].name<<"     ";
  cout<<rec[i].fname<<"  ";
  cout<<rec[i].cell<<"  ";
  cout<<rec[i].dob<<"   ";
  cout<<rec[i].address<<" ";
  cout<<rec[i].section<<"  ";
  cout<<rec[i].bloodgroup<<"\n\n";
  fstream studentRecord;
  studentRecord.open("studentsRecord.txt", ios::out | ios::app);
  studentRecord<<"Roll No: "<<rec[i].rollno<<"\n"<<"Name: "<<rec[i].name<<"\n"<<"Father Name: "<<rec[i].fname<<"\n"<<"Mobile no: "<<rec[i].cell<<"\n"<<"Date of Birth: "<<rec[i].dob<<"\n"<<"Address: "<<rec[i].address<<"\n"<<"Section: "<<rec[i].section<<"\n"<<"BloodGroup: "<<rec[i].bloodgroup<<endl;
  studentRecord.close();
}

void search_student(int searchkey)
{
  for(int i=0;i<=ts;i++)       
 { 
   if(rec[i].rollno==searchkey)   
  {   
    cout<<"ID		"<<"Roll		"<<"Name		"<<"Father  "<<"Cell no.		"<<"DOB			"<<"Address			"<<"Section			"<<"Bloodgroup\n\n";
    show_data(i);      
   }
  } 
}

void add_student()         
{    
  for(int i=0;i<=ts;i++)
 {
    get_data(i);         
  }
    cout <<  "Data entered successfully.";

  system("CLS");
  cout<<endl;
  cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
  cout<<"---------------------------Student record Table------------------------------------------------------------------"<<endl;
  cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
  cout<<"ID   "<<"Roll   "<<"Name      "<<"Father\tCell no.      "<<"DOB          "<<"Address   "<<"Section   "<<"Bloodgroup\n\n";
  cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;

  for(int i=0;i<=ts;i++)
 {
    show_data(i);       
  }
  cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;
  cout<<"-----------------------------------------------------FINISH-------------------------------------------------------"<<endl;
  cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;
  system("pause");

  main();         
}

void edit_student(int idnumber)     
{  
  for(int i=0;i<=ts;i++)       
 {  
   if(idnumber==i)      
  {         
    cout<<"\nExisted information about this record.\n\n";
    cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"ID   "<<"Roll   "<<"Name      "<<"Father\tCell no.      "<<"DOB          "<<"Address   "<<"Section   "<<"Bloodgroup\n\n";
    cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
    show_data(i);    
    cout<<"\n\nEnter new data for above shown record.\n\n";
    get_data(i);        
    cout<<"\n\nRecord updated successfully."<<endl;
    system("pause");
  main();

   }
  }
}
