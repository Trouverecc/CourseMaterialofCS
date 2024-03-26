#include <iostream>
#include <string>
using namespace std;
const int day_tab[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                            {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
const string month_name[13] = {" ", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};
const string day_name[13] = {"th", "st", "nd", "rd"};
int runnian(int y)
{
    return (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
}
int month_to_day(int leap, int month, int day)
{
    for (int i = month - 2; i >= 0; i--)
        day += day_tab[leap][i];
    return day;
}
int year_to_day(int year)
{
    return 365 + runnian(year);
}
void times(int data)
{
    if (data <= 9)
        cout << 0;
}
int main()
{
    int n,d;
    long long y0, m0, d0, h0, mi0, s0;
    long long year_new, month_new, day_new, hour_new, minute_new, second_new;
    long long s1, second_add, day_add;
    cin >> n;
    while (n--)
    {
        cin >> y0 >> m0 >> d0 >> h0 >> mi0 >> s0 >> s1;
        int month[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
	                     {0,31,29,31,30,31,30,31,31,30,31,30,31}};
		int year0=y0,month0=m0,day0=d0,s=h0,f=mi0,a=s1;
		int hh=0,mm=0,ss=0;//秒转成的时分秒
		long long b=0;//输入的秒数
		int dd=0,sum=0;
		
		if((y0%4==0&&y0%100!=0)||(y0%400==0)){
			for(int i=0;i<m0;i++){
				sum+=month[1][i];
			}
		}else
		{
			for(int i=0;i<m0;i++){
				sum+=month[0][i];
			}
		}
		sum+=d;//输入的日期是初始年份的第几天*/
		hh=b/3600;
        mm=b/60%60;
        ss=b%60;
        if(ss+a>=60){
        	a=ss+a-60;//新秒
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
			a+=ss;
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
		day_add = s1 / 86400;
        long long second_add = h0 * 3600 + mi0 * 60 + s0 + s1 % 86400;
        if (second_add >= 86400)
        {
            day_add += second_add / 86400;
            second_add %= 86400;
        }
        hour_new = second_add / 3600;
        second_add %= 3600;
        minute_new = second_add / 60;
        second_add %= 60;
        second_new = second_add;
        day_add += month_to_day(runnian(y0), m0, d0);
        long long y = y0;
        while (day_add > year_to_day(y))
        {
            day_add -= year_to_day(y);
            y++;
        }
        while (day_add <= 0)
        {
            y--;
            day_add += year_to_day(y);
        }
        long long m = 1;
        long long d1;
        while ((d1 = day_add - day_tab[runnian(y)][m - 1]) > 0)
        {
            day_add = d1;
            m++;
        }
        year_new = y;
        month_new = m;
        day_new = day_add;
        cout << month_name[month_new] << " " << day_new;
        if (day_new % 10 > 0 && day_new % 10 <= 3 && day_new / 10 != 1)
            cout << day_name[day_new % 10] << " ";
        else
            cout << day_name[0] << " ";
        times(hour_new);
        cout << hour_new << ":";
        times(minute_new);
        cout << minute_new << ":";
        times(second_new);
        cout << second_new << " " << year_new <<endl;
    }
}