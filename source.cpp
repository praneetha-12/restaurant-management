#include <iostream>
#include<stdlib.h>
using namespace std;
#include<exception>

//user-defined exception class to throw an exception when the customer places no order after choosing the option
class exception0
{
    public:
    char *what()
    {
        return "No order is placed";
    }
};


class sale{
    int pizzaS,burgerS,ffS,cokeS,icS,choice;
    int existingPizza,existingIc,existingCoke,existingBurger,existingFfs;
    int pizzaq,burgerq,ffq,cokeq,icq;
    float pizzaP,burgerP,ffP,cokeP,icP;
    public:
    sale()
    {
        pizzaS=0;
        burgerS=0;
        ffS=0;
        cokeS=0;
        icS=0;
        pizzaP=0;
        burgerP=0;
        ffP=0;
        cokeP=0;
        icP=0;
        
    }
    void controlpanel();
    void displaybill()
    {
        int total;
        cout<<"\n\t\t\t\t\t Bill\n";
        cout<<"\t\t\t Pizza:         "<<pizzaP<<endl;
        cout<<"\t\t\t Burger:        "<<burgerP<<endl;
        cout<<"\t\t\t French Fries:  "<<ffP<<endl;
        cout<<"\t\t\t Coke:          "<<cokeP<<endl;
        cout<<"\t\t\t Ice cream:     "<<icP<<endl;
        total=pizzaP+burgerP+ffP+cokeP+icP;
        cout<<"\t\t\t Total:         "<<total<<endl;
        cout<<"Please pay "<<total;
    }
};

//a control panel function to implement a food ordering control panel for the customers to order food 
void sale::controlpanel()
{
    existingPizza=500;
    existingIc=500;
    existingBurger=500;
    existingFfs=500;
    existingCoke=500;
    char ch='y';
    cout<<"\n\t\t\t\t\tMenu: \n Place Your Order: \n";
    cout<<"\n1.Pizza: \n2.Burger: \n3.French Fries: \n4.Coke: \n5.Ice cream: \n";
    
    while(ch=='y')
    {
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
         cout<<"There are "<<existingPizza<<" Pizzas"<<endl;
        cout<<"Enter pizza quantity(500 rupees per pizza): ";
        cin>>pizzaq;
        try{
            if(pizzaq==0)
            {
                throw exception0();
            }
            else if(existingPizza>=pizzaq)
            {  
                existingPizza=existingPizza-pizzaq;
                pizzaS+=pizzaq;
                pizzaP+=pizzaq*500;
            
                cout<<"Your pizza order is placed.\n";
            }
        else{
            cout<<"We're sorry for the inconvenience.\n We are currently short of pizzas.\n Please order anything else from our menu \n";
        }
        }
        catch(exception0 e)
        {
            cout<<e.what()<<endl;
        }
        break;
        case 2:
         cout<<"There are "<<existingBurger<<" Burgers"<<endl;
        cout<<"Enter burger quantity(130 rupees per burger): ";
        cin>>burgerq;
        try{
            if(burgerq==0)
            {
                throw exception0();
            }
        
        else if(existingBurger>=burgerq)
        {
            existingBurger=existingBurger-burgerq;
            burgerS+=burgerq;
            burgerP+=burgerq*130;
            
            cout<<"Your burger order is placed.\n";
        }
        else{
            cout<<"We're sorry for the inconvenience.\n We are currently short of burgers.\n Please order anything else from our menu \n";
        }
        }
        catch(exception0 e)
        {
            cout<<e.what()<<endl;
        }
        break;
        case 3:
         cout<<"There are "<<existingFfs<<" French Fries"<<endl;
        cout<<"Enter french fries quantity(100 rupees per french fries): ";
        cin>>ffq;
        try
        {
            if(ffq==0)
            {
                throw exception0();
            }
        
        else if(existingFfs>=ffq)
        {
            existingFfs=existingFfs-ffq;
            ffS+=ffq;
            ffP+=ffq*100;
            
            cout<<"Your french fries order is placed.\n";
        }
        else{
            cout<<"We're sorry for the inconvenience.\n We are currently short of french fries.\n Please order anything else from our menu \n";
        }
        }
        catch(exception0 e)
        {
            cout<<e.what()<<endl;
        }
        break;
        case 4:
         cout<<"There are "<<existingCoke<<" Coke"<<endl;
        cout<<"Enter coke quantity(50 rupees per coke): ";
        cin>>cokeq;
        try
        {
            if(cokeq==0)
            {
                 throw exception0();
            }
        
        else if(existingCoke>=cokeq)
        {
            existingCoke=existingCoke-cokeq;
            cokeS+=cokeq;
            cokeP+=cokeq*50;
            
            cout<<"Your coke order is placed.\n";
        }
        else{
            cout<<"We're sorry for the inconvenience.\n We are currently short on coke.\n Please order anything else from our menu \n";
        }
        }
        catch(exception0 e)
        {
            cout<<e.what()<<endl;
        }
        break;
        case 5:
        cout<<"There are "<<existingIc<<" Ice creams"<<endl;
        cout<<"Enter ice cream quantity(120 rupees per ice cream): ";
        cin>>icq;
        try
        {
            if(icq==0)
            {
                 throw exception0();
            }
        
        else if(existingIc>=icq)
        {
            existingIc=existingIc-icq;
            icS+=icq;
            icP+=icq*500;
            cout<<"Your ice cream order is placed.\n";
        }
        else{
            cout<<"We're sorry for the inconvenience.\n We are currently short on ice creams.\n Please order anything else from our menu \n";
        }
        }
        catch(exception0 e)
        {
            cout<<e.what()<<endl;
        }
        break;
        default:
        cout<<"Invalid Choice Entered. Please order again.";
    }
    cout<<"Would you like to continue placing order(y/n)? ";
    cin>>ch;
    }
}


int main()
{
    sale s;
    s.controlpanel();
    s.displaybill();
    return 0;
}
