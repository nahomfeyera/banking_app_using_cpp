#include <iostream>
#include <fstream>
#include<cstdlib>
#include<conio.h>
#include<string>
#include<ctime>
#include <Windows.h>
#include <stdio.h>
#include <iomanip>
using namespace std;

/*class defined with private and public members*/
class cbe
{


   private:
       string fname[15];
       string lname[15];
       int pin[4];
       double accBalance[15];
       long long accNumber[13];
   public:
      bool checkaccnumb(int p);
      bool pincheck(int n);
       void balance();
       void withdarw();
       void transfer();
       void pinchange();
       void transaction(string f,string l,long long int a,float v,string wt);
       int accountreturn(int n);
       void submenu();
       void continueorexit();
       void acc();
       void acc1();
       int usersnum();
       int account;
 const int size = usersnum();



};

     int cbe:: usersnum()//gives an out put of the number of user on file
      {
            ifstream file;
            file.open("userinfo.txt");
            char* number = new char[1000];   //assigning a pointer and reserving a memory
            int getnumber=0;
	                    while(!file.eof())
	                    {
		                 file.getline(number,200,'\n');
                         getnumber++;
                         }file.close();
            delete [] number;            //deleting the reserved memory bc its no longer useful

            return getnumber-1;
     }

       void text_anime(char a[100])
 {
     int i; double k;
     for (i=0; a[i]!='\0'; ++i)
     {
         for (k=0; k<30000000; ++k);
         cout<<a[i];
     }
 }
 void slide_anime(char* a)
 {
     int i,k;
     double j;
     for (k=0; k<100; k++)
     {
         for(i=0; i<k; ++i)
         {
             cout<< " ";
         }
         cout<<a;
         for(j=0; j<1000; ++j);
         system("cls");
     }
     cout<<"                                      "<<a<<"                           ";
 }

     void cbe::continueorexit()   //provides continue or exit options
     {   int c;
         cout<<"\n\n\t\t\tchoose to proceed :"<<endl;
          cout<<"\n\n\t\t\t1.continue\t\t2.Exit"<<endl;
          cin>>c;
          system("cls");

          switch(c)  {
                        case 1:submenu();break;
                        case 2: return exit(0); break; }    //assigning an exit value

     }
         void cbe::acc()   //reading the file and create an array of users info in the class
    {
         const int size = usersnum();
           ifstream file("userinfo.txt");
             for(int i=0;i<size;i++)
              {
                   file>>fname[i];
                   file>>lname[i];
                   file>>accNumber[i];
                   file>>pin[i];
                   file>>accBalance[i];
              } file.close();
                           }

        void cbe::acc1()
    {
        const int size = usersnum();
         ifstream file("userinfo.txt");
         for(int j=0;j<size;j++)
    {
             file>>fname[j];
             file>>lname[j];
              file>>accNumber[j];
                file>>pin[j];
                 file>>accBalance[j];
                   } file.close();

    }

       int cbe::accountreturn(int n)  //Identify which account is logged in and assign index value of the array(object)
       {   const int size = usersnum();
            acc();

              for (int i=0;i<size;i++)
               {
                   if(n==pin[i])
                  {

                      account= i;

                         break;
                          }
                           }
                            return account;
                               }

         bool cbe::pincheck(int n)
    {      acc();
           const int size = usersnum();
           bool ispin=false;
           for (int i=0;i<size;i++)
        {
           if(n==pin[i] )
            {
                cout<<"\n\n\n\t\t\tWELLCOME "<<fname[i]<<" "<<lname[i]<<endl;

                account= i;
                ispin= true;
                break;
            }
        }
             if(!ispin) {cout<<"\n\n\n\t\tLOGIN FAILED!!"<<endl;
                      }

        return ispin;
   }
   //SUB MENU FUNCTION
    void cbe::submenu()
         {
              int choice;

             while(true)
    {

             {cout<<"\n\n\n\t\t\t\t1.Balance\t\t\t3.Transfer\n\n"<<endl;
                    cout<<"\t\t\t\t2.Withdraw\t\t\t4.Pin change\n\n";
                    cout<<"\t\t\t\t\t\t5.Exit"<<endl;
             }
     cin>>choice;

     system("cls");



     switch(choice)
     {
         case 1:  balance();
                  continueorexit();

                 break;
         case 2: withdarw();
                 continueorexit();
                 break;
         case 3: transfer();
                         continueorexit();
                         break;
         case 4: pinchange();
                  continueorexit();
                           break;
         case 5: return exit(0);
                          break;
        default : cout<<"\n\n\n\t\t\tWRONG CHOICE PLEASE TRY AGAIN  "<<endl;
                    submenu(); break;



     }
     }

         }

          void cbe::balance()
       {
             acc();
             cout<<"\n\n\n\t\t\tYour Account balance is " << fixed << setprecision(3) << accBalance[account]<<"ETB";
             transaction(fname[account],lname[account],accNumber[account],0,"Balance Check" );

       }

//WITHDRAW FUNCTION
            void cbe::withdarw()

       {    const int size = usersnum();

            double amount,atmamount;
            cout<<"\n\n\n\t\t\tEnter Amount :\n\n\t\t\t ";

            cin>>amount;
            ifstream atmfile1("ATMstatus.txt");
            atmfile1>>atmamount;
            atmfile1.close();

      while ((amount>accBalance[account] ) || (amount>atmamount) || atmamount<=0 || accBalance[account]<=0)
            {

              if (amount>accBalance[account] && accBalance[account]!=0)
               {cout<<"\n\n\n\t\t\tSORRY!!  Your account has insufficient Amount.\n Please try another amount "<<endl;
               cin>>amount; }
               else if(accBalance[account]==0){cout<<"\n\n\t\t\tYour Account balance is "<<accBalance[account]<<"ETB"<<"\n\t\t\tYou can not withdraw "<<amount<<endl;
                                                                    continueorexit();                                    }


                else if(amount>atmamount && atmamount!=0) {cout<<"\n\t\t\tSORRY!! ATM has not enough Amount!! "<<endl;
                                                     continueorexit();}



                else  {cout<<"\n\n\t\t\t\tATM is out of cash!!"<<endl;
                            return exit(0);}

                system("cls");
            }



             cout<<"\n\n\n\t\t\t\tYOUR REQUEST HAS BEEN ACCEPTED";
             ofstream atmfile2("ATMstatus.txt");
               atmfile2<<(atmamount-amount);
               atmfile2.close();

                 ofstream file("userinfo.txt");

                   accBalance[account] -= amount;


                   for ( int i=0; i<size;i++)
                {
                   file<<fname[i]<<" "<<lname[i]<<" "<<accNumber[i]<<" "<<pin[i]<<" "<<accBalance[i]<<endl;
                } file.close();
                transaction(fname[account],lname[account],accNumber[account],amount,"Withdrawal");
       }
           void cbe::transfer()
           {
               acc();
               acc1();
               int acnb,transferamount;
               const int size = usersnum();
               bool accountexist=false;
               cout<<"\n\n\n\t\t\tEnter account number :\n\n\t\t\t ";
               cin>>acnb;
               cout<<"\n\n\n\t\t\tEnter amount :\n\n\n\t\t\t";
               cin>>transferamount;
               system("cls");

               for(int j=0;j<size;j++)
               {
                   if(acnb==accNumber[j])
                   {       accountexist=true;
                       cout<<"\n\n\n\t\t\tAccount exist and account holder name is "<<fname[j]<<" "<<lname[j]<<endl;
                        if(accBalance[account]>=transferamount && accountexist)
                         {
                           ofstream file("userinfo.txt");
                            accBalance[j]+=transferamount;
                           for ( int j=0; j<size;j++)
                         {
                            file<<fname[j]<<" "<<lname[j]<<" "<<accNumber[j]<<" "<<pin[j]<<" "<<accBalance[j]<<endl;
                         }  file.close();


                         }  else  {cout<<"\n\n\n\t\t\tSORRY Your account does not have sufficient amount!!"<<endl;
                                    }
                   }
               }
 for(int j=0;j<size;j++)
               {
                   if(acnb==accNumber[j])
                   {       accountexist=true;}}
             if (accountexist && accBalance[account]>=transferamount)
             {
                         ofstream file("userinfo.txt");
                          accBalance[account]-=transferamount;

                          for ( int i=0; i<size;i++)
                       {
                           file<<fname[i]<<" "<<lname[i]<<" "<<accNumber[i]<<" "<<pin[i]<<" "<<accBalance[i]<<endl;
                       }   file.close();
                          cout<<"\n\n\n\t\t\tTRANSFER SUCCESSFUL !!"<<endl;
                          transaction(fname[account],lname[account],accNumber[account],transferamount,"Transfer");


             }    else if(!accountexist)
                        { cout<<"\n\n\n\t\t\tThe account does not exist!! please try another account!!"<<endl;
                                   continueorexit();
                        }                    else cout<<endl;


             }
    //PIN CHANGE FUNCTION


void cbe::pinchange()
   {

        const int Size = usersnum();
        int currentPin, newPin, newPin2;

        ifstream file1("userinfo.txt");
        for(int i=0;i<Size;  i++)
        {
             file1 >>fname[i] >>lname[i]>> accNumber[i] >>pin[i] >> accBalance[i];
        }
       file1.close();
       cout << "\n\n\n\t\t\tEnter your current PIN for verification: ";
       cin >> currentPin;

       short trials=0;

       for(int i=0; i<size&&trials<2; i++)
       {
         while(currentPin!=pin[account])
         {
             cout << "Please enter the correct PIN again:";
             cin >> currentPin;

             trials++;
         }
          if(currentPin==pin[account])
             {
                cout << "\n\n\n\t\t\tEnter your new PIN:";
                cin >> newPin;
                cout << "\n\n\n\t\t\tVerify your new PIN:";
                cin >> newPin2;

             }

        if(newPin==newPin2)
        {
            cout << "\n\n\n\t\t\tYou have successfully changed your PIN." << endl;
            ofstream file2("userinfo.txt");
            pin[account]=newPin;


            for(int i=0; i<Size; i++)
            {
               file2<<fname[i]<< " "<<lname[i]<< accNumber[i]<<" "<<pin[i]<<" "<<accBalance[i]<<endl;
            }
            file2.close();
            break;
        }
        else
        cout << "\n\n\n\t\t\tYou can not change your PIN, because you have entered 2 different numbers. Try again later!" ;
    }

}

void cbe::transaction(string f,string l,long long int a,float v, string wt)
{

   time_t now=time(0);

	struct tm nowlocal;

	nowlocal=*localtime(&now);


    ofstream trans;
    trans.open("transaction.txt",ios::app);
    trans<<"Operation Performed: "<<wt<<endl;
    trans<<"Account Owner: "<<f<<" "<<l<<endl;
    trans<<"Transaction Card: "<<a<<endl;
    trans<<"Type of Transaction: ";
    if(v!=0){
    	trans<<wt<<endl;
    	trans<<"Amount of "<<wt<<":"<<v<<endl;
	}
	else{
		trans<<"None"<<endl;	}
    trans<<"Date:> "<<nowlocal.tm_year+1900<<"-"<<nowlocal.tm_mon+1<<"-"<<nowlocal.tm_mday<<endl;
	trans<<"Time:> "<<nowlocal.tm_hour<<"-"<<nowlocal.tm_min<<"-"<<nowlocal.tm_sec<<endl;

	trans<<endl<<endl<<endl;
    trans.close();
}

         bool cbe::checkaccnumb(int p)
         {
                acc();
           const int size = usersnum();
           bool isacc=false;
           for (int i=0;i<size;i++)
        {
           if( p==accNumber[i])
            {



                isacc= true;
                break;

            }
        }



        return isacc;
   }



   int main()
{
   int login;
    system("color 9e");
                  cout<<"\t\t\t *******************       *********************     ***********************\n";
                  cout<<"\t\t\t**********************     **********************    ***********************\n";
                  cout<<"\t\t\t*******        *******     *******        *******    *******\n";
                  cout<<"\t\t\t*******                    *******        *******    *******\n";
                  cout<<"\t\t\t*******                    *********************     **********************\n";
                  cout<<"\t\t\t*******                    *******************       **********************\n";
                  cout<<"\t\t\t*******                    *******************       **********************\n";
                  cout<<"\t\t\t*******                    *******      *******      **********************\n";
                  cout<<"\t\t\t*******                    *******        *******    *******\n";
                  cout<<"\t\t\t*******        *******     *******        *******    *******\n";
                  cout<<"\t\t\t**********************     **********************    ***********************\n";
                  cout<<"\t\t\t**********************     **********************    ***********************\n";
                  cout<<"\t\t\t ********************      *********************     ***********************\n";

cout<<"\t\t-------------------------------------------------------------------------------------------------\n";
cout<<"\t\t-------------------------------------------------------------------------------------------------\n";

        // declaring argument of time()
    time_t my_time = time(NULL);

    // ctime() used to give the present time
    cout<<"\t\t\t\t\t\t\t\t\t\t";
	printf("%s", ctime(&my_time));
    text_anime( "\n\n\n\n\t\t\t\t\t\tWELCOME TO CBE ");
    cout<<endl;
    text_anime("\n\n\n\t\t\t\tEnter 1 to login or press any other number to exit");
    cout<<endl;

    cin>>login;
    system("cls");
    system("color 57");

     cbe user;



    short int npin,pp,choice,trial=0;
     bool ispin1,isacc1;

     cout <<"\n\n\n\t\t\tEnter your account number :\n\n\n\t\t\t ";
   cin>>pp;
   isacc1=user.checkaccnumb(pp);
   bool c=false;
   c=isacc1;
      if(c)
{


     cout <<"\n\n\n\t\t\tEnter your pin :\n\n\n\t\t\t ";
   cin>>npin;
     ispin1= user.pincheck(npin);
     while(!(ispin1)&&(trial<2)){

        cout<<"\n\n\n\t\t\tEnter your pin again \n\n\t\t\t:";
        cin>>npin;
        ispin1= user.pincheck(npin);
        trial++;}
        if(!(ispin1)&& (trial=2))
            {
            cout<<"\t\t\t\tYou have entered wrong pin 3 times. GOOD BYE"<<endl;
            return 0;}
}    else {cout<<"\t\tInvalid Account Number!! TRY Again"<<endl;}



        system("cls");
bool b= user.pincheck(npin);
     if(b)
      user.submenu();



    return 0;
}


