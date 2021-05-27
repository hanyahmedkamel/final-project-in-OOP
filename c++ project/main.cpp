//
//  main.cpp
//  c++ project
//
//  Created by HanyAhmed on 5/19/20.
//  Copyright © 2020 HanyAhmed. All rights reserved.
//

#include <iostream>
using namespace std;
#include <string>
class worker;
class pro_worker;
class student;
class person{// abstract base class
    protected: //access specifier
    string name;
    int ID,birthday;
   virtual void setname()=0; //pure virtual function
   virtual void  setID()=0;//pure virtual function
   virtual void  setdate()=0;//pure virtual function
   virtual string getname()=0;//pure virtual function
   virtual int getid()=0;//pure virtual function
   virtual int getdate()=0;//pure virtual function
public://access specifier
    person(){             //constructor
        name="unknown";
        ID=0;
        birthday=0;
    }
    virtual void all()=0;//pure virtual function
};
class student:virtual public person{//Inheritance
public:
    student(){//constructor
        school_name="unknown";
        num_of_student++;
    }
    protected://access specifier
    static int num_of_student;
    string school_name;
        void setname(){//function override & abstraction
            cout<<"enter your name";
            cin>>name;
                   }
    void setschool(){//function override & abstraction
               cout<<"enter your school name";
               cin>>school_name;
                      }
        void setID(){//function override & abstraction
            cout<<"enter your ID";
            cin>>ID;
                   }
        void setdate(){//function override & abstraction
            cout<<"enter you birth date";
            cin>>birthday;
                   }
        string getname(){//function override & abstraction
            return name;
                   }
        int getid(){//function override & abstraction
            return ID;
                      }
  string getschoolname(){// abstraction
        return school_name;
    }
        int getdate(){//function override & abstraction
            return birthday;
                   }
public://access specifier
        void all(){//function override & abstraction
            setname();
            setID();
            setdate();
            setschool();
            cout<<"***********************"<<endl;
            cout<<"hello "<<getname()<<endl;
            cout<<"your ID = "<<getid()<<endl;
            cout<<"your birthday is "<<getdate()<<endl;
            cout<<"your your school is "<<getschoolname()<<endl;
            cout<<"***********************"<<endl;
            }
    friend void pop(student x,worker y,pro_worker z);//Friend Function
    friend void pop(student x,pro_worker z);//Friend Function
    friend void pop(student x,worker y);//Friend Function
    friend void pop(worker y,pro_worker z);//Friend Function
    friend void pop(worker y);//Friend Function
    friend void pop(student x);//Friend Function
    friend void pop(pro_worker z);//Friend Function
};
//encapsulation
class worker:virtual public student{ //Inheritance
protected://access specifier
    int years_of_experiance;
    static int num_of_worker;
    string University_name,division_name;
    void set_unver_name(){
        cout<<"enter unversity name";
        cin>>University_name;
    }
    void set_division_name(){
        cout<<"enter divison name";
        cin>>division_name;
    }
    string get_unver_name(){
       return University_name;
    }
    string get_division_name(){
          return division_name;
       }
    void set_time(){
           cout<<"enter your year of work in the field";
           cin>>years_of_experiance;
       }
    int get_time(){
           return years_of_experiance;
       }
public://access specifier
    worker(){//constructor
        University_name="unknown";
        division_name="unknown";
        num_of_worker++;
        years_of_experiance=0;
    }
    void operator*(worker a)//Operators Overloading & abstraction
    {
        if(years_of_experiance>a.years_of_experiance){//Operators Overloading
            cout<<"heighest years of employees work in the field = "<<years_of_experiance<<endl;
        }else
            cout<<"heighest years of employees work in the field = "<<a.years_of_experiance<<endl;
        }
    void all(){//function override
        setname();
        setID();
        setdate();
        setschool();
        set_unver_name();
        set_division_name();
        set_time();
        cout<<"***********************"<<endl;
        cout<<"hello "<<getname()<<endl;
        cout<<"your ID = "<<getid()<<endl;
        cout<<"your birthday is "<<getdate()<<endl;
        cout<<"your school is "<<getschoolname()<<endl;
        cout<<"your university is "<<get_unver_name()<<endl;
        cout<<"your division is "<<get_division_name()<<endl;
        cout<<"years of working = "<<get_time()<<endl;
        cout<<"***********************"<<endl;
        }
    friend void pop(student x,worker y,pro_worker z);//Friend Function
    friend void pop(student x,pro_worker z);//Friend Function
    friend void pop(student x,worker y);//Friend Function
    friend void pop(worker y,pro_worker z);//Friend Function
    friend void pop(worker y);//Friend Function
    friend void pop(student x);//Friend Function
    friend void pop(pro_worker z);//Friend Function
};
class pro_worker:public worker{
    private:
    int num_of_skills;
    static int num_of_pro_worker;
    void set_num_skills(){
        cout<<"enter your the number of skills you gain in the work field";
        cin>>num_of_skills;
    }
    int get_num_skills(){
        return num_of_skills;
    }
    public:
    pro_worker(){
        years_of_experiance=0;
        num_of_pro_worker++;
        num_of_skills=0;
    }
    void operator*(pro_worker a)//Operators Overloading
    {
        if(years_of_experiance>a.years_of_experiance){
            cout<<"heighest years of employees work in the field = "<<years_of_experiance<<endl;
        }else
            cout<<"heighest years of employees work in the field = "<<a.years_of_experiance<<endl;
        }
    void all(){//function override
    setname();
    setID();
    setdate();
    setschool();
    set_unver_name();
    set_division_name();
    set_time();
    set_num_skills();
    cout<<"***********************"<<endl;
    cout<<"hello "<<getname()<<endl;
    cout<<"your ID = "<<getid()<<endl;
    cout<<"your birthday is "<<getdate()<<endl;
    cout<<"your school is "<<getschoolname()<<endl;
    cout<<"your university is "<<get_unver_name()<<endl;
    cout<<"your division is "<<get_division_name()<<endl;
    cout<<"years of working = "<<get_time()<<endl;
    cout<<"all your skill = "<<get_num_skills()<<endl;
    cout<<"***********************"<<endl;
    }
    friend void pop(student x,worker y,pro_worker z);//Friend Function
    friend void pop(student x,pro_worker z);
    friend void pop(student x,worker y);
    friend void pop(worker y,pro_worker z);
    friend void pop(worker y);
    friend void pop(student x);
    friend void pop(pro_worker z);
};
int student::num_of_student=0;//static variable
int worker::num_of_worker=0;//static variable
int pro_worker::num_of_pro_worker=0;//static variable

 void pop(student x,worker y,pro_worker z){//Friend Function implementation & function overloading
    cout<<"number of all population = "<<x.num_of_student+z.num_of_pro_worker+y.num_of_worker;//function overloading
}
void pop(student x,pro_worker z){//function overloading
    cout<<"number of all population = "<<x.num_of_student+z.num_of_pro_worker;
}
void pop(student x,worker y){//Friend Function implementation &function overloading
cout<<"number of all population = "<<x.num_of_student+y.num_of_worker;
}
void pop(worker y,pro_worker z){//Friend Function implementation &function overloading
cout<<"number of all population = "<<z.num_of_pro_worker+y.num_of_worker;
}
void pop(worker y){//Friend Function implementation & function overloading
    cout<<"number of all population = "<<y.num_of_worker;
}
void pop(student x){//Friend Function implementation & function overloading
    cout<<"number of all population = "<<x.num_of_student;
}
void pop(pro_worker z){//Friend Function implementation & function overloading
    cout<<"number of all population = "<<z.num_of_pro_worker;
}
int main()
    {
        pro_worker a,b,c;
        student x,y,z;
        pop(a);
    }
