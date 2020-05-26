#if !defined (LISTCLASS_H)
#define LISTCLASS_H
#include<iostream>


union unia
    {
        int int_;
        double double_;
        char char_;
    };


class List
{
private:
    int Size;
    double *tab,*val_tab,value;
    unia **union_;



public:
    List ();
    List(int);
    List(int,double*);
    List(int,int);
    List(const List&);

    ~List();


    void setSize(int);
    void setVal_tab(double*);


    int getSize() const;


    void Add_single_element(int); //I understand it as 'change value of existing element'
    void Add_multi_elements();
    void AddDiferent_type(int,int);      // because here I give the option to add any amount of elements
    void Delete();
    void Is_empty();
    int Access();
    void Num_of_elements();
    void Print();


};
#endif
