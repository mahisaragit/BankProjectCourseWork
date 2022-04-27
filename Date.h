//Date.h
#ifndef DATE_H
#define DATE_H

#include<vector>
#include<string>
using namespace std;


class Date
{
	friend ostream& operator<<(ostream& output, const  Date& date);

private:
	int day;
	int month;	
	int year;

public:
	vector<int>daysPerMonth = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //vector containing numbers of days per every month
	Date();
	Date(int , int , int);

	void setDate(int , int , int );
	void setDay(int);
	void setMonth(int);
	void setYear(int);

	int getDay()const;
	int getMonth()const;
	int getYear()const;
	void printDate()const;
	
};
#endif
