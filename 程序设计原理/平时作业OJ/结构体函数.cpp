#include <iostream>
using namespace std;
struct student{
	string name;
	int age;
	int score;
};
//1、值传递
void printstudent1(struct student s){
	cout<<"name "<<s.name
	<<" age "<<s.age
	<<" score "<<s.score<<endl;
}
//2、地址传递
void printstudent2(struct student *p){
	cout<<"name "<<p->name
	<<" age "<<p->age
	<<" score "<<p->score<<endl;
}
int main(){
	struct student s;
	s.name="Peter";
	s.age=18;
	s.score=100;
	printstudent1(s);
	printstudent2(&s);
}
//若不想修改主函数中的数据，用值传递，反之用地址传递
