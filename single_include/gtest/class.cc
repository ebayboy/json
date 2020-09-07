

#include <cstring>
#include <cstdio>

#include <iostream>
#include <fstream>
#include <exception>

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

#if 1
      NLOHMANN_DEFINE_TYPE_INTRUSIVE(Person, name, address, age);
#else 

    friend void to_json(json &j, const Person &p)
    {
        j = json{
            {"name", p.name},
            {"address", p.address},
            {"age", p.age}
		};
    }

	  friend void from_json(const json &j, Person &p)
	  {
		  if (j.find("name") != j.end()) {
			j.at("name").get_to(p.name);
		  }

		  if (j.find("address") != j.end()) {
			  j.at("address").get_to(p.address);
		  }

		  if (j.find("age") != j.end()) {
			  j.at("age").get_to(p.age);
		  }
	  }

#endif
  };
}

int json_ifstream_test()
{
    std::ifstream fs("in.json");
    if (fs.bad()) {
      cout << __func__ << __LINE__ << endl;
      return 1;
    }

#if 1
    json j;
    cout << "before person:" << endl;
    fs >> j;
#else
	json j = json::parse(fs);
    cout << "before person:" << endl;
#endif
    //throw exception 之后的代码不会执行
    ns::Person p = j;

	//cout << "after person:" << p << endl;
	cout << "after person:" << endl;

	cout << "name:" << p.getName() << endl;
	cout << "age:" << p.getAge() << endl;
	cout << "address:" << p.getAddress() << endl;

	if (p.getName() != "fanpf" || p.getAge() != 38 || p.getAddress() != "tianyangcheng") {
		goto err;
	} 

    fs.close();
    return 0;

err:

  fs.close();
  return 1;
}

int json_ofstream_test()
{
  ns::Person p("fanpf", "tianyangcheng", 38);
  json j = p;

  std::ofstream fs("out.json");
  fs << j << std::endl;
  fs.close();

  std::ifstream o("out.json");

  json jo;
  o >> jo;

  o.close();

  auto result = json::diff(j, jo);
  if (result.dump() != "[]") {
    cout << "FAIL:" << __func__ << __LINE__ << endl;
  }

  return 0;
}

int json_class_test()
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

#if 0
int main()
{
	json_ifstream_test();
	return 0;
}
#endif
