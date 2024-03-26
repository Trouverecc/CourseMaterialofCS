#include <iostream>
using namespace std;
int main()
{
	int m,f,e;
	char score;
	while((cin>>m>>f>>e)&&(m!=-1||f!=-1||e!=-1))
	{
		int sum;
		sum=m+f;
		if(sum>=80)
		cout<<'A'<<endl;
		if(sum>=65&&sum<80)
		cout<<'B'<<endl;
		if(sum>=50&&sum<65)
		cout<<'C'<<endl;
		if(sum>=30&&sum<50)
		{
			if(e>=50)
			cout<<'C'<<endl;
			if(e<50)
			cout<<'D'<<endl;
		}
		if(sum<=30)
		cout<<'F'<<endl;
	}
	if(m==-1||f==-1)
	cout<<'F'<<endl;
	return 0;
}
/*#include <iostream>
using namespace std;

int main(){
    int mid,final,makeup,sum = 0;
    char score;

    while ((cin >> mid >> final >> makeup) && !(mid == -1 && final == -1 && makeup == -1)) {
        sum = mid + final;

        if (sum < 70 && sum >= 65)
            sum = 70;
        else if (sum < 65 && sum >= 50)
            sum = 50;

        sum /= 10;
        switch (sum) {
            case 10:
            case 9:
            case 8:
                score = 'A';
                break;
            case 7:
                score = 'B';
                break;
            case 5:
                score = 'C';
                break;
            case 4:
            case 3:
                if (makeup >= 50)
                    score = 'C';
                else
                    score = 'D';
                break;
            default:
                score = 'F';
                break;
        }

        if(mid == -1 || final == -1)
            score = 'F';
        
        cout << score << endl;
    }

    return 0;
}