#include <iostream>
#include <string>
using namespace std;
//创建学生数据类型：学生包括（姓名，年龄，分数）
//自定义数据类型
//语法 struct 类型名称
struct student
{
	//成员列表
	//姓名
	string name;
	//年龄
	int age;
	//分数
	int score;
}s3;//顺便创建结构体变量
//通过学生类型创建具体学生
int main()
{
    //type1
	struct student s1;
	//给s1属性赋值，通过.访问结构体变量中的属性
	s1.name="Peter";
	s1.age=18;
	s1.score=100;
	cout<<s1.name<<" "<<s1.age<<" "<<s1.score<<endl;
	//type2
	struct student s2={"John",19,99};
	cout<<s2.name<<" "<<s2.age<<" "<<s2.score<<endl;
	//type3
	s3.name="Linda";
	s3.age=17;
	s3.score=100;
	cout<<s3.name<<" "<<s3.age<<" "<<s3.score<<endl;
}
//在定义结构体时顺便创建结构体变量