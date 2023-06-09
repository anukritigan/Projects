    #include<stdio.h>
    #include<iostream>
    #include<stdlib.h>
    #include<string.h>
    #include<fstream>
    using namespace std;
     class ice
     {
     string name;
     int code;
     int rate;
     string qty;

    public:

    void add();
    void view();
    void getdata();
    void sale1();
    void read();
    void write();
    void delete_record();
    void add1();
    void menu();


    }o1;


    void ice::menu()
    {
    int ch;
     do
     {
      

     cout<<"\n\t\t\t|-------------------------|";
     cout<<"\n\t\t\t|         Main Menu       |";
     cout<<"\n\t\t\t|-------------------------|";

     cout<<"\n\n\t\t|-------------------------------------------|";
     cout<<"\n\t\t|             1. Add stock                  |";
     cout<<"\n\t\t|-------------------------------------------|";
     cout<<"\n\t\t|             2. Delete item                |";
     cout<<"\n\t\t|-------------------------------------------|";
     cout<<"\n\t\t|             3. Sale item                  |";
     cout<<"\n\t\t|-------------------------------------------|";
     cout<<"\n\t\t|             4. View Items                 |";
     cout<<"\n\t\t|-------------------------------------------|";
     cout<<"\n\t\t|             5. Exit                       |";
     cout<<"\n\t\t|-------------------------------------------|";
     cout<<"\n\n\t\t\t Enter your choice:";
     cin>>ch;

     switch(ch)
     {
      case 1: o1.add();
      break;
     case 2: o1.delete_record();
     break;
     // case 3: o1.sale1();
      //break;
      case 4: o1.read();
      break;
      case 5: exit(0);
      break;
     }

     }
      while(ch!=5);
     }


    void ice::add()
    {
     
    int ch1;

    cout<<"\n\n\t\t|------------------------------------------|";
     cout<<"\n\t\t|           1.Add new item                  |";
     cout<<"\n\t\t|-------------------------------------------|";
     cout<<"\n\t\t|           2.Add Existing item Quantity    |";
     cout<<"\n\t\t|-------------------------------------------|";
     cout<<"\n\n\t\t\tEnter your choice:";
      cin>>ch1;
      cout<<"\n\t-------------------------------------------\n";
    switch(ch1)
     {
      case 1: write();
      break;
      //case 2: add1();
      //break;
      case 3: exit(0);
      break;
     }

      }

    /* void ice :: add1()
    {

     fstream fp;
     int pos;
     int n;
     int q;

     read();

     fp.seekg(0);
     fp.open("ice1.dat",ios::binary|ios::in|ios::out);
     cout<<"\n\n\n\t\tEnter code of ice cream flavour:";
     cin>>n;

     while(fp.read((char*)&o1,sizeof(o1)))
     {
     if(n==code)
     {
     cout<<"\n\t\tEnter quantity:";
     cin>>q;
     pos= -1 * sizeof(o1);
     fp.seekp(pos,ios::cur);
     qty=qty+q;
     fp.write((char*)&o1,sizeof(o1));
      fp.close();
     break;
     }
     }
    read();
     }*/



    /* void ice :: sale1()
    {
          
     fstream fp;
     int pos;
     int n;
     int q;

     read();

     fp.seekg(0);
     fp.open("ice1.dat",ios::binary|ios::in|ios::out);
     cout<<"\n\n\n\t\tEnter code of ice cream flavour:";
     cin>>n;
     while(fp.read((char*)&o1,sizeof(o1)))
     {
     if(n==code)
     {
     cout<<"\n\t\tEnter quantity:";
     cin>>q;
     pos= -1 * sizeof(o1);
     fp.seekp(pos,ios::cur);
     qty=qty-q;
     fp.write((char*)&o1,sizeof(o1));
     fp.close();

     break;
     }
     }
    read();
     }*/

     void ice::delete_record()
     {
      int n;
      ifstream fp1;
      ofstream fp2;

        read();
      fp1.open("ice1.dat",ios::in);
      fp2.open("ice2.dat",ios::out);
      cout<<"\n\n\t\tEnter code of ice cream flavour:";
     cin>>n;

      while(fp1.read((char *)&o1,sizeof(o1)))
      {
      if(n!=code)
      {
      fp2.write((char *)&o1,sizeof(o1));
      }
       cout<<"\n\n\t\t---------Item Deleted Successfully-----------";
      }
      fp1.close();
      fp2.close();

      remove("ice1.dat");
      rename("ice2.dat","ice1.dat");

      read();
      }



     void ice::view()
     {
    cout<<"\n"<<name;
    cout<<"\t\t";
    cout<<code;
    cout<<"\t\t";
    cout<<rate;
    cout<<"\t\t";
    cout<<qty;
    }

     void ice::getdata()
     {
     
     cout<<"\nEnter ice cream flavour to be added:";
     fflush(stdin);
     cin>>name;
     cout<<"\nEnter ice cream flavour code to be added:";
     cin>>code;
     cout<<"\nEnter ice cream flavour price:";
     cin>>rate;
     cout<<"\nEnter the quantity:";
     cin>>qty;
     }

     void ice:: write()
     {
      
      ofstream f1;
      f1.open("ice1.dat",ios::app);
      o1.getdata();

      f1.write((char*)&o1,sizeof(o1));
      f1.close();
      read();
     }

     void ice::read()
     {
      
      ifstream f1;
      f1.open("ice1.dat",ios::in);
      f1.seekg(ios::beg);
      cout<<"\n\n"<<"Name"<<"\t\t"<<"Code"<<"\t\t"<<"Rate"<<"\t\t"<<"Quantity\n";
      cout<<"\n---------------------------------------------------------------\n";

      while(f1.read((char *)&o1,sizeof(o1)))
    {
     view();
     }
    f1.close();
     }


     int main()
     {

      char user[15];
char pwd[5];
int i;
int y=3;
         int x = 0;

remove("ice1.dat");

while(y!=0)
{

cout<<"\n\n****************************";
cout<<"\n\n\t\t\tEnter the user name:";
cin>>user;
cout<<"\n\n****************************";
cout<<"\n\t\t\tEnter the password:";

for(i=0;i<5;i++)
{
cin>>pwd[i];

cout<<"*";
}
pwd[i]='\0';



if(strcmp(user,"admin")==0)
{
if(strcmp(pwd,"admin")==0)
{
cout<<"\n\t\t\tWelcome\n";
o1.menu();
}

else
{


cout<<"\n\n\n\n\n\n\n\n\t\t\t|-------------------------|";
cout<<"\n\t\t\t| Incorrect Password !! |";
cout<<"\n\t\t\t| Please Try Again |";
cout<<"\n\t\t\t|-------------------------|";

x=y-1;

cout<<"\n\n\n\t\t\tYou have left with "<<x<<" attempts";
}

if(x==0)
{
cout<<"\n\t\t\tThank you come soon ......";
exit(0);
}
}

else
{


cout<<"\n\n\n\n\n\n\n\n\t\t\t|-------------------------|";
cout<<"\n\t\t\t| Incorrect Password !! |";
cout<<"\n\t\t\t| Please Try Again |";
cout<<"\n\t\t\t|-------------------------|";

x=y-1;

cout<<"\n\n\n\t\t\tYou have left with "<<x<<" attempts";
}

if(x==0)
{
cout<<"\n\t\t\tThank you come soon ......";
exit(0);
}

y--;
}
}
