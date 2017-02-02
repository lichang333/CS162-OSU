#include <iostream>

struct Employee{

  short id;
  int age;
  double wage;  
};

void print_information(Employee employee){
//    std::cout<<"Name:     "<<employee.name<<"\n";
    std::cout<<"ID:     "<<employee.id<<"\n";
    std::cout<<"Age:    "<<employee.age<<"\n";
    std::cout<<"Wage:   "<<employee.wage<<"\n";
}

int main(){
    Employee joe={14,32,24.15};
    Employee frank={15,28,18.27};
    
    print_information(joe);
    std::cout<<"\n";
    print_information(frank);
    std::cout<<"\n";

    return 0;
}