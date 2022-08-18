#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
class shopping
{
private:
    int pcode;
    float price,dis;
    string pname;
public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void list();
    void receipt();
    void rem();
};
void shopping::menu()
{
    m:
    int chioce;
    string email,password;
    cout<<"\t\t\t\t ____________________________ \n";
    cout<<"\t\t\t\t                              \n";
    cout<<"\t\t\t\t    ~:SUPER MARKET MENU:~     \n";
    cout<<"\t\t\t\t                              \n";
    cout<<"\t\t\t\t ____________________________ \n";
    cout<<"\t\t\t\t _                          _ \n";
    cout<<"\t\t\t\t|                            |\n";
    cout<<"\t\t\t\t| 1. Administrator           |\n";
    cout<<"\t\t\t\t|                            |\n";
    cout<<"\t\t\t\t| 2. Buyer                   |\n";
    cout<<"\t\t\t\t|                            |\n";
    cout<<"\t\t\t\t| 3. Exit                    |\n";
    cout<<"\t\t\t\t|                            |\n";
    cout<<"\t\t\t\t -                          - \n";
    cout<<"\n\n\t\t\tPlease Select Your Choice:-  ";
    cin>>chioce;
    switch(chioce)
    {
    case 1:
        cout<<"\n\n\t\t\t\"YOUR WELOCME\"\n";
        cout<<"\n\t\t Please Login First\n";
        cout<<"\n\t\t\t Enter Your Email:_ ";
        cin>>email;
        cout<<"\n\t\t\t Enter Password:_   ";
        cin>>password;
        if(email=="harsh" && password=="123")
            administrator();
        else{
            cout<<"\nInvalid email or password";
            break;
        }
    case 2:
        {
            buyer();
        }
    case 3:
        {
            exit(0);
        }
    default:
        {
            cout<<"\nPlesae Select from the Given option";
        }
        goto m;
    }
}
void shopping::administrator()
{
    m:
    int choice;
    cout<<"\n\t\t\t |--------------------------------------|\n";
    cout<<"\n\t\t\t |         :ADMINISTRATOR MENU:         |\n";
    cout<<"\n\t\t\t |--------------------------------------|\n";
    cout<<"\n\t\t\t                                        \n";
    cout<<"\n\t\t\t 1.   Add the product:     \n";
    cout<<"\n\t\t\t 2.   Modify the product:  \n";
    cout<<"\n\t\t\t 3.   Delete the product:  \n";
    cout<<"\n\t\t\t 4.   Back to main Menu:   \n";
    cout<<"\n\t     Please enter your Choice:";
    cin>>choice;
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout<<"\nInvalid choice:";
    }
    goto m;
}
void shopping::buyer()
{
    m:
    int choice;
    cout<<"\n\t\t\t |-----------------|\n";
    cout<<"\n\t\t\t | 1. Buy Product  |\n";
    cout<<"\n\t\t\t | 2. Go Back:     |\n";
    cout<<"\n\t\t\t |-----------------|\n";
    cout<<"\n\t\tEnter Your Choice:";
    cin>>choice;
    switch(choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
    default:
        cout<<"\n Invalid Choice:";
    }
    goto m;
}
void shopping::add()
{
    m:
    fstream data;
    int c,token=0;
    float p,d;
    string n;
    cout<<"\n Add new Product:";
    cout<<"\n Enter Product Code:";
    cin>>pcode;
    cout<<"\n Enter Name Of the Product:";
    cin>>pname;
    cout<<"\n Enter Price of the Product:";
    cin>>price;
    cout<<"\n Enter Discount of the Product:";
    cin>>dis;
    data.open("database.txt",ios::in);
    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<pcode<<"  "<<pname<<" "<<price<<" "<<dis;
        data.close();
    }
    else{
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c==pcode)
                token++;
            data>>c>>n>>p>>d;
        }
        data.close();
        if(token==1)
            goto m;
        else{
            data.open("database.txt",ios::app|ios::out);
            data<<pcode<<pname<<price<<dis;
            data.close();
        }
    }
    cout<<"\n Record Inserted:";
}
void shopping::edit()
{
    fstream data,data1;
    int pkey,token=0,c;
    float p,d;
    string n;
    cout<<"\n\t\t Modify The Record :";
    cout<<"\n\t\t Enter Product Code:";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
        cout<<"\n File Does not Exit:";
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n Product New Code:";
                cin>>c;
                cout<<"\n Name Of the Product:";
                cin>>n;
                cout<<"\n Price of the Product:";
                cin>>p;
                cout<<"\n Discount on the product:";
                cin>>d;
                data<<c<<"  "<<n<<" "<<p<<" "<<d;
                cout<<"\n Record Edited:";
                token++;
            }
            else{
                data<<pcode<<pname<<price<<dis;
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)
            cout<<"\nRecord Not Found Sorry!";
    }
}
void shopping::rem()
{
    fstream data,data1;
    int pkey,token=0;
    cout<<"\n Delete Product:";
    cout<<"\nEnter Product Code:";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
        cout<<"\nFile Does not Exist:";
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey){
                cout<<"\n\tProduct Successfully deleted:";
                token++;}
            else{
                data1<<pcode<<pname<<price<<dis;
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)
            cout<<"\n\t Record Not Found:";
    }
}
void shopping::list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\tProduct Name\tProduct Number\tPrice:";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"  "<<pname<<" "<<price;
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}
void shopping::receipt()
{
    fstream data;
    int c=0;
    int arrc[100];
    int arrq[100];
    char choice;
    float amount=0,dis=0,total=0;
    cout<<"\n\t\t\t RECIEPT  ";
    data.open("database.txt",ios::in);
    if(!data)
        cout<<"\nEmpty Database:";
    else{
        data.close();
        list();
        cout<<"\n\tPlease Place The Order:";
        do{
            m:
            cout<<"\n Enter Product Code:";
            cin>>arrc[c];
            cout<<"\n Enter Product Quality:";
            cin>>arrq[c];
            for(int i=0;i<c;i++){
                if(arrc[c]==arrc[i]){
                    cout<<"\n\t Duplicate Product Code: Please Try Again!:";
                    goto m;
                }
                c++;
                cout<<"\n\t\t Do You Want Another Product? If yes Please Press Y else NO:";
                cin>>choice;
            }
        }
        while(choice=='Y');
        cout<<"\t\t\t RECIEPT     ";
        cout<<"\n Product Number Product Name Product Quantity Price Amount With Discount:";
        for(int i=0;i<c;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(pcode==arrc[i]){
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"    "<<pname<<" "<<price<<" "<<dis<<"   "<<amount;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
    }
}

int main()
{
    shopping s;
    s.menu();
    getch();
}
