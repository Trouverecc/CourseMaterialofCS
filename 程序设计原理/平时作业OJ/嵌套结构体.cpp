#include <iostream>
#include <string>
using namespace std;
struct student{
	string name;
	int age;
	int score;
};
struct teacher{
	int id;
	string name;
	int age;
	struct student stu;
};
int main(){
	teacher t;
	t.id=001;
	t.name="Cherry";
	t.age=18;
	t.stu.name="Linda";
	t.stu.age=17;
	t.stu.score=100;
	cout<<"t name "<<t.name
	<<" t age "<<t.age
	<<" t id "<<t.id<<endl;
	cout<<"s name "<<t.stu.name
	<<" s age "<<t.stu.age
	<<" s score "<<t.stu.score<<endl;
}