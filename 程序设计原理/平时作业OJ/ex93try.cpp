#include <iostream>
using namespace std;
class Date {
	static int m_s_month[12];
	int m_year;
	int m_month;
	int m_day;
public:
	Date(int y = 0, int m = 0, int d = 0) {
		m_year = y;
		m_month = m;
		m_day = d;
	}
	friend ostream& operator<<(ostream& os, Date& a);
	friend istream& operator>>(istream& os, Date& a);
	static int getMonthDay(int y, size_t n);//返回y年n月的天数
	bool LeapYear(int year)const;
	int countLeapYear(int year)const;
	Date operator+(size_t n)const;
};
int Date::m_s_month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int Date::getMonthDay(int y, size_t n) {
	return m_s_month[n - 1] + (n == 2 && (y % 400 == 0 || (y % 4 == 0 && y % 100)));
}
bool Date::LeapYear(int y)const {
	return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}
ostream& operator<<(ostream& os, Date& a) {
	os << a.m_year << " " << a.m_month << " " << a.m_day << " ";
	return os;
}
istream& operator>>(istream& os, Date& t) {
	
	while (1) {
		os >> t.m_year;
		
	}
	
	while (1) {
		os >> t.m_month;
		
		
	}
	
	while (1) {
		os >> t.m_day;
		
	
		break;
	}
	return os;
}
int Date::countLeapYear(int year)const {
	if (m_year == year) {
		return LeapYear(year);
	}
	int begin = m_year;
	int end = year - 1;
	if (m_year > year) {
		begin = year;
		end = m_year - 1;
	}
	while (!(LeapYear(begin))) {
		++begin;
	}
	while (!(LeapYear(end))) {
		--end;
	}
	int tmp = begin;
	int count = 0;
	if (begin <= end) {
		while (tmp <= end && tmp % 100) {
			++tmp;;
		}
		for (; tmp <= end; !LeapYear(tmp) ? ++count : count, tmp += 100);
		return (end - begin) / 4 + 1 - count;
	}
	return 0;
}
Date Date::operator+(size_t n)const {
	Date tmp = *this;
	size_t count = 0;
	for (int i = 1; i < (int)tmp.m_month; ++i) {
		count += getMonthDay(tmp.m_year, i);
	}
	count += tmp.m_day;
	if (n >= (365 + LeapYear(tmp.m_year) - count)) {
		n -= (365 + LeapYear(tmp.m_year) - count);
		tmp.m_month = 12;
		tmp.m_day = 31;
		while ((int)n >= (365 + LeapYear(tmp.m_year + 1))) {
			n -= (365 + LeapYear(++tmp.m_year));
		}
	}
	for (; n > 0; --n) {
		if (tmp.m_day == getMonthDay(tmp.m_year, tmp.m_month)) {
			tmp.m_day = 1;
			tmp.m_month == 12 ? tmp.m_month = 1, ++tmp.m_year : ++tmp.m_month;
		}
		else {
			++tmp.m_day;
		}
	}
	return tmp;
}
int main(){
	int n,sum=0;
	int month[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}};
	cin>>n;
	while(n--){
		int y,m,d,s,f,aa;
		int hh=0,mm=0,ss=0;//秒转成的时分秒
		long long bb;//输入的秒数
		int dd=0;
		cin>>y>>m>>d>>s>>f>>aa>>bb;
		if((y%4==0&&y%100!=0)||(y%400==0)){
			for(int i=0;i<m;i++){
				sum+=month[1][i];
			}
		}else
		{
			for(int i=0;i<m;i++){
				sum+=month[0][i];
			}
		}
		sum+=d;//输入的日期是初始年份的第几天
		hh+=bb/3600;
        mm+=bb/60%60;
        ss+=bb%60;
        if(ss+aa>=60){
        	aa=ss+aa-60;//新秒
        	f=f+mm+1;//新分
        	if(f>=60){
        		f=f-60;
        		s=s+hh+1;
        		if(s>=24){
        			dd=s/24;
        			s=s%24;
				}
			}
			else{
				s=s+hh;
				if(s>=24){
        			dd=s/24;
        			s=s%24;
				}
			}
		}
		else{
			aa+=ss;
			f+=mm;
			if(f>=60){
        		f=f-60;
        		s=s+hh+1;
        		if(s>=24){
        			dd=s/24;
        			s=s%24;
				}	
			}
			else{
				s=s+hh;
				if(s>=24){
        			dd=s/24;
        			s=s%24;
				}
			}
		}
		Date a, b;	
		cin>>a;
		b=a+dd;
		cout<<b<<endl;
	}
}