

#include <cstring>
#include <cstdio>

#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

namespace ns {

  class Person {

    private:
      std::string name;
      std::string address;
      int age;

    public:
      Person():name(""), address(""), age(0) {}
      Person(string name, string address, int age) : name(name), address(address), age(age) {} 

      string getName() { return name; }
      string getAddress() { return address; }
      int getAge() { return age; }

      friend std::ostream& operator<<(std::ostream& o, const Person& s)
      {
        o << "name:" << s.name << endl;
        o << "address:" << s.address << endl;
        o << "age:" << s.age << endl;
        return o;
      }

      NLOHMANN_DEFINE_TYPE_INTRUSIVE(Person, name, address, age)
  };
}

extern int json_class_test()
{
  //class 初始化 (), struct 初始化 {}
  ns::Person p("Ned Flanders", "744 Evergreen Terrace", 60);

  json j = p;
  ns::Person p1 = j;

  if (p1.getName() != "Ned Flanders") {
    return 1;
  }
  if (p1.getAddress() != "744 Evergreen Terrace") {
    return 1;
  }
  if (p1.getAge() != 60) {
    return 1;
  }

  return 0;
}
