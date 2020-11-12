#include<fstream>
#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
class menu
{
public:
    int itemcode;
    char name[50];
    int price;
public:
    void accept()
    {
        cout<<endl<<"Enter Item Code";
        cin>>itemcode;
        cout<<"Enter Item name";
        cin>>name;
        cout<<"Enter price";
        cin>>price;
    }
    void display()
    {
        cout<<endl<<itemcode<<"\t\t"<<name<<"\t"<<price;

    }

};
menu obj; // global object
void additem()
{
    obj.accept();
    fstream wr;
    wr.open("d:\\myproject\\menu.txt",ios::app);
    wr.write((char *)&obj,sizeof(obj));
    cout<<endl<<"Item Added Sucessfully";

}
void viewmenu()
{
    fstream rd;
    rd.open("d:\\myproject\\menu.txt",ios::in);

    rd.seekg(0,ios::end);

    int n=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=n;i++)
    {
    rd.read((char *)&obj,sizeof(obj));
    obj.display();
    }

}
void removeitem()
{
    fstream rd,wr;
    rd.open("d:\\myproject\\menu.txt",ios::in);
    wr.open("d:\\myproject\\temp.txt",ios::out);

    rd.seekg(0,ios::end);

    int n=rd.tellg()/sizeof(obj);

    rd.seekg(0,ios::beg);

    int sr;
    cout<<endl<<"Enter item code to remove item";
    cin>>sr;

    for(int i=1;i<=n;i++)
    {
        rd.read((char *)&obj,sizeof(obj));

        if(obj.itemcode==sr)
        {
            cout<<endl<<"Item removed";
        }
        else
        {
            wr.write((char *)&obj,sizeof(obj));
        }
    }
    rd.close();
    wr.close();
    remove("d:\\myproject\\menu.txt");
    rename("d:\\myproject\\temp.txt","d:\\myproject\\menu.txt");


}

class bill
{
public:
    int billid;
    int dd,mm,yy;
    int icode,pr,qty,total;
    char iname[50];
public:
    void accept(int bid,int d,int m,int y,int ic,int q)
    {
        billid=bid;
        dd=d;
        mm=m;
        yy=y;
        icode=ic;
        qty=q;

        fstream rd;
        rd.open("d:\\myproject\\menu.txt",ios::in);

        rd.seekg(0,ios::end);
        int n=rd.tellg()/sizeof(obj);
        rd.seekg(0,ios::beg);

        for(int i=1;i<=n;i++)
        {
            rd.read((char *)&obj,sizeof(obj));
            if(icode==obj.itemcode)
            {
                strcpy(iname,obj.name);
                pr=obj.price;
                total=pr*qty;
            }
        }




        cout<<endl<<"Bill id"<<billid;
        cout<<endl<<"DD-MM-yy"<<dd<<"-"<<mm<<"-"<<yy;
        cout<<endl<<"item code"<<icode;
        cout<<endl<<"item name"<<iname;
        cout<<endl<<"qty"<<qty;
        cout<<endl<<"total"<<total;




    }

};
bill bobj;

void preparebill()
{
    int bill_number;
    cout<<"Enter Bill Number";
    cin>>bill_number;
    cout<<"Enter Date in dd mm yyyy format";
    int day,mon,year;
    cin>>day>>mon>>year;

    int choice=0;
    while(1)
    {
        int itemcode;
        cout<<"Enter item code";
        cin>>itemcode;
        int qty;
        cout<<"Enter qty";
        cin>>qty;
        bobj.accept(bill_number,day,mon,year,itemcode,qty);
         fstream wr;
        wr.open("d:\\myproject\\bill.txt",ios::app);
        wr.write((char *)&bobj,sizeof(bobj));
        wr.close();
        cout<<endl<<endl<<"Enter 1 to add new item";
        cout<<endl<<"Enter 2 to prepare bill";
        cin>>choice;
        if(choice==2)
        {
            break;
        }

    }

    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;


    cout<<endl<<"Bill Number "<<bill_number<<"\t\t"<<"Dated: "<<day<<"-"<<mon<<"-"<<year;

    cout<<endl<<endl<<endl;

    cout<<endl<<"***********************************************************";
    cout<<endl<<"\t\tStar Orient Catering";
    cout<<endl<<"***********************************************************";

    fstream rd;
    rd.open("d:\\myproject\\bill.txt",ios::in);
    rd.seekg(0,ios::end);
    int n=rd.tellg()/sizeof(bobj);
    rd.seekg(0,ios::beg);
    int ftotal=0;
    for(int i=1;i<=n;i++)
    {
        rd.read((char *)&bobj,sizeof(bobj));
        if(bobj.billid==bill_number)
        {
            cout<<endl<<bobj.icode<<"\t"<<bobj.iname<<"\t"<<bobj.qty<<"\t"<<bobj.pr<<"\t"<<bobj.total;
            ftotal=ftotal+bobj.total;
        }

    }
    cout<<endl<<endl<<endl;
    cout<<"**************************************************************";
    cout<<endl<<"Total Amount is "<<ftotal;
    cout<<endl<<"********************************************************";













}








void updateitem()
{
    fstream rd,wr;
    rd.open("d:\\myproject\\menu.txt",ios::in);
    wr.open("d:\\myproject\\temp.txt",ios::out);

    rd.seekg(0,ios::end);

    int n=rd.tellg()/sizeof(obj);

    rd.seekg(0,ios::beg);

    int sr;
    cout<<endl<<"Enter item code to update item";
    cin>>sr;

    for(int i=1;i<=n;i++)
    {
        rd.read((char *)&obj,sizeof(obj));

        if(obj.itemcode==sr)
        {
            obj.accept();
            wr.write((char *)&obj,sizeof(obj));
        }
        else
        {
            wr.write((char *)&obj,sizeof(obj));
        }
    }
    rd.close();
    wr.close();
    remove("d:\\myproject\\menu.txt");
    rename("d:\\myproject\\temp.txt","d:\\myproject\\menu.txt");





}


main()
{
 preparebill();
}








