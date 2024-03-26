//用const防误操作
#include <iostream>
#include <string>
using namespace std;
struct student{
	string name;
	int age;
	int score;
};
//将函数中形参改为指针，可减小内存空间，
//而且不会复制新的副本出来
void printstudent(const student *s)
{
	cout<<"name: "<<s->name
	<<" age: "<<s->age
	<<" score: "<<s->score;
}
int main(){
	struct student s={"Peter",15,100};
	printstudent(&s);
}