#include <cstdlib>
#include <iostream>

using namespace std;

class Date //this is an abstract data type!!
{
	private:
		int month, day, year;
	public:
		Date(int,int,int);
		Date(int=20070104);
		void setDate(int, int, int);
		void showDate(void);
		int dayofwk(void); //makes it able to call the function
              
};

int Date::dayofwk()
{
    int mm, dd, yyyy, A, B;
    A=23*mm/9+dd+4;
    if(mm<3)
        B=yyyy--;
    else
        B=yyyy-2;
    return (A+B+yyyy/4-yyyy/100+yyyy/400);
}

Date::Date(int mm, int dd, int yyyy)
{
    cout<<"Object created"<<endl;
    month=mm;
    day=dd;
    year=yyyy;
}

Date::Date(int yyyymmdd)
{
    year = yyyymmdd/10000;
    month = (yyyymmdd-(year*10000))/100;
    day = yyyymmdd-year*10000-month*100;
}

void Date::setDate(int mm, int dd, int yyyy)
{
     month=mm;
     day=dd;
     year=yyyy;
}
void Date::showDate(void)
{
     cout << "The date is " << month << "/" << day << "/" << year << endl;
} 
                     
      

int main(int argc, char *argv[])
{
    int mm, dd, yyyy;
    Date a, b, c;
    a.setDate(int, int, int);
    
    cout<<"Month: ";
    cin>>mm;
    cout<<"Day: ";
    cin>>dd;
    cout<<"Year: ";
    cin>>yyyy;
    
    string n[]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    cout<<a.showDate()<< n[a.dayofwk()]; 
    system("PAUSE");
    return EXIT_SUCCESS;
}
