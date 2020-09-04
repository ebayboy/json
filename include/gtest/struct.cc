
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

namespace ns {
  // a simple struct to model a person
  struct person {
    std::string name;
    std::string address;
    int age;
  };

  NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(person, name, address, age);
};

int json_struct_test()
{
  //结构体可以用{}初始化， 类不行
  ns::person p{"Ned Flanders", "744 Evergreen Terrace", 60};

  //struct to person
  json j = p;

  string s = "{\"address\":\"744 Evergreen Terrace\",\"age\":60,\"name\":\"Ned Flanders\"}";
  if (j.dump() != s) {
    return 1;
  }

  ns::person p1 = j;
  if (p1.name != "Ned Flanders") {
    return 1;
  }

  if (p1.address != "744 Evergreen Terrace") {
    return 1;
  }
  
  if (p1.age != 60) {
    return 1;
  }

  return 0;
}

