#include<bits/stdc++.h>
using namespace std;
class SportRun:public Sport {
protected:
    int m, l;
public:
    SportRun(int m, int l):Sport(m, l) {}
    string getDescription(){
        string A,B;
    	int x=m;
    	while(x){
    		A+=x%10+'0';
    		x/=10;
		}
		int n=A.length();
		for(int i=0;i<n/2;i++)
		swap(A[i],A[n-i-1]);
		string s = to_string(minutes);
        return "You're running for "+s+ " minute(s)";
    }
    virtual int getSportIntensity()override{
        return (minutes / 10) * level;
    }
};
class SportBicycle : public Sport {
public:
    SportBicycle(int m, int l) : Sport(m, l) {}
    virtual int getSportIntensity()override {
        return (minutes / 5) * (minutes / 5) * level;
    }
    string getDescription(){
        string s = to_string(minutes);
        return "You're riding for "+s+" minute(s)";
    }
};
/*zch error
#include<bits/stdc++.h> 
using namespace std; 
class Sport{
	protected:
        int minutes, level;
    public:
        Sport(int minutes, int level):minutes(minutes),level(level){} 
        virtual string getDescription()=0; 
        virtual int getSportintensity()=0;    
};
class SportRun:public Sport{
    public:
        SportRun(int m, int l) : Sport(m, l) {} 
		string getDescription(); 
		int getSportintensity();
};
class SportBicycle:public Sport
{
    public:
        SportBicycle(int m, int l) : Sport(m,l) {}
        string getDescription(); 
		int getSportintensity();
};
string SportRun::getDescription()
{
	string str("You're running for "); 
	str.append(to_string(minutes)); 
	str.append(" minute(s)"); 
	return str;
}
int SportRun::getSportIntensity(){
    int intensity= minutes / 10; 
	intensity*= level; 
	return intensity;
}
string SportBicycle::getDescription()
{
	string str("You're riding for "); 
	str.append(to_string(minutes)); 
	str.append(" minute(s)"); 
	return str;
}
int SportBicycle::getSportintensity()
{
	intintensity=minutes/5;
    intensity= intensity* intensity;
	intensity*= level; 
	return intensity;
}*/


/*#include<bits/stdc++.h>
using namespace std;
class SportRun: public Sport{
public:
    SportRun(int m, int l): Sport(m, l){}
    string getDescription(){
    	string A,B;
    	int x=minutes;
    	while(x){
    		A+=x%10+'0';
    		x/=10;
		}
		int n=A.length();
		for(int i=0;i<n/2;i++)
		swap(A[i],A[n-i-1]);
		return "You're running for "+A+"minute(s)";
	}
	int getSportIntensity(){
		return minutes/10*level;
	}
};

class SportBicycle: public Sport{
public:
    SportBicycle(int m, int l): Sport(m, l){}
    string getDescription(){
    	string A;
    	int x=minutes;
    	while(x){
    		A+=x%10+'0';
    		x/=10;
		}
		int n=A.length();
		for(int i=0;i<n/2;i++)
		swap(A[i],A[n-i-1]);
		return "You're riding for "+A+"minute(s)";
	}
	int getSportIntensity(){
		return (minutes/5)*(minutes/5)*level;
	}
};*/
