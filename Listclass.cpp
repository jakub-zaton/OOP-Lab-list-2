#include "Listclass.h"
#include<stdlib.h>
using namespace std;

//Constructors section
List::List()
{
    Size=1;
    tab=new(nothrow)double[Size];
    tab[0]=0;
}


List::List(int S)
{
    tab=new double[S];
    for(int i=0;i<S;i++)
        tab[i]=1.0;
    Size=S;
}


List::List(int S,double *val_tab2)
{
    tab=new(nothrow)double[S];
    for(int i=0;i<S;i++)
        tab[i]=val_tab2[i];
    Size=S;
}


List::List(int S,int type)
{



    union_=new(nothrow)unia*[S];

    union_[0]=new(nothrow) unia [S];
    union_[1]=new(nothrow) unia [S];
    union_[2]=new(nothrow) unia [S];



}


List::List(const List &prev_element)
{
    Size=prev_element.Size;
    for(int i=0;i<Size;i++)
        val_tab[i]=prev_element.val_tab[i];
}





//Destructor

List::~List()
{
    delete [] tab;
}


//Setters section
void List::setSize(int S)
{
    Size=S;
}


void List::setVal_tab(double *val_tab2)
{
    for(int i=0;i<Size;i++)
          tab[i]=val_tab2[i];
}


//Getter
int List::getSize() const {return Size;};


//Methods section

void List::Add_single_element(int pos)
{
    double new_value;

    cout<<"What value do you want to add on position "<<pos+1<<"?"<<endl;
    cin>>new_value;
    tab[pos]=new_value;
}


void List::Add_multi_elements()
{
    int new_size;
    double *tmp_tab;

    cout<<"How many elements would you like to add?"<<endl;
    cin>>new_size;

    tmp_tab=new(nothrow)double[Size+new_size];

    for(int i=0;i<Size+new_size;i++)
    {
        if(i<Size)
            *(tmp_tab+i)=*(tab+i);
        else
        {
            cout<<"Enter element #"<<i+1<<": ";
            cin>>tmp_tab[i];
        }
     }

     delete [] tab;

     tab=tmp_tab;
     Size+=new_size;
}



void List::AddDiferent_type(int S,int type)
{
    int counter_int=0,counter_double=0,counter_char=0;
    while((counter_int+counter_char+counter_double)<S)
    {
        cout<<"what type do u want to add?"<<endl;
        cout<<"1 - int, 2- double, 3 - char"<<endl;
        cin>>type;
        switch (type)
        {
            case 1: {cout<<"enter int:  ";cin>> union_[0][counter_int].int_;counter_int++;break;}
            case 2: {cout<<"enter double:  ";cin>>union_[1][counter_double].double_;counter_double++;break;}
            case 3: {cout<<"enter char:  ";cin>> union_[2][counter_char].char_;counter_char++;break;}
        }
    }

    cout<<endl<<endl;

    for(int i=0;i<counter_int;i++)
        cout<<"union int  #"<<i+1<<" "<<union_[0][i].int_<<endl;


    for(int i=0;i<counter_double;i++)
        cout<<"union double  #"<<i+1<<" "<<union_[1][i].double_<<endl;


    for(int i=0;i<counter_char;i++)
        cout<<"union char  #"<<i+1<<" "<< union_[2][i].char_<<endl;

    Size=S;
}




void List::Delete()
{
    int new_size,row;
    double *tmp_tab;

    cout<<"Deleting series of elements: from which element would you like to start deletion?"<<endl;
    cin>>row;
    cout<<"How many elements would you like to delete?"<<endl;
    cin>>new_size;

    if (Size<new_size)
    {
        cout<<"Error, you can't delete more than you have!"<<endl;
        exit(0);
    }

    else
    {
        tmp_tab=new(nothrow)double[Size-new_size];

        for(int i=0;i<Size-new_size;i++)
        {
            if(i<row-1)
                *(tmp_tab+i)=*(tab+i);
            else
                *(tmp_tab+i)=*(tab+i+new_size);
        }

        delete [] tab;
        tab=tmp_tab;
        Size-=new_size;
    }
}



void List::Is_empty()
{
    if(Size==1&&tab[0]==0)
        cout<<"List is empty"<<endl;
    else
        cout<<"FULL"<<endl;
}


int List::Access()
{
    int pos;
    cout<<"Which element do you want have access to?"<<endl;
    cin>>pos;

    return pos-1;
}


void List::Num_of_elements()
{
    cout<<"There are "<<Size<<" elements on the list"<<endl;
}


void List::Print()
{
    cout<<"SizePrint="<<Size<<endl;
    for(int i=0;i<Size;i++)
       cout<<"Element #"<<i+1<<" = "<<tab[i]<<endl;
}
