#include <iostream>

using namespace std;

class Student{
	private:
		char *name;
		int age;
		float score;
	
	public:
		Student(char *, int, float);
		void say();
};

Student::Student(char *name1, int age1, float score1){
	name = name1;
	age = age1;
	score = score1;
}

void Student::say(){
cout<<"name: "<<name<<"\n"<<"age: "<<age<<"\n"<<"score: "<<score<<endl;
}

int main(){
	Student stu("xiaoming",15,90.5f);
	stu.say();
}