#include <iostream>
#include <string>
#include <ctime>
using namespace std;
struct student{
	string sname;
	int score;
};
struct teacher{
	string tname;
	struct student sarr[5];
};
//给老师和学生赋值的函数
void allocatespace(struct teacher tarr[],int len){
	string nameseed="ABCDE";
	for(int i=0;i<len;i++)
	{
		tarr[i].tname="teacher_";
		tarr[i].tname+=nameseed[i];
		for(int j=0;j<5;j++){
			tarr[i].sarr[j].sname="student_";
			tarr[i].sarr[j].sname+=nameseed[j];
			int random=rand()% 61 + 40;
			
		}
		
	}
}
void printInfo(struct teacher tarr[],int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<"teacher's name: "<<tarr[i].tname<<endl;
		for(int j=0;j<5;j++){
			cout<<"\tstudent's name: "<<tarr[i].sarr[j].sname
			<<" student's score: "<<tarr[i].sarr[j].score<<endl;
		}
	}
}
int main(){
	srand((unsigned int)time(NULL));
	//创建3名老师的数组
	struct teacher tarr[3];
	//通过函数给3名老师的信息赋值，
	//并给老师待定学生信息赋值
	int len=sizeof(tarr)/sizeof(tarr[0]);
	allocatespace(tarr,len);
	printInfo(tarr,len);
}