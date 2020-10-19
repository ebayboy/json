
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

#define  dd()  do  { cerr << __func__ << ":" << __LINE__  << endl; } while (0)

/*
 * j_string.get_to(cpp_string):this is a string
 * serialized_string:"this is a string"
 * this is a string == this is a string
 * "this is a string" == "this is a string"
 *
 * j_serial string:{"happy":true,"pi":3.141}
 * serial_string:{"happy":true,"pi":3.141}
 */
static int test_j_string()
{
	// store a string in a JSON value
	json j_string = "this is a string";
	cout << "j_string:" << j_string << endl;

	// retrieve the string value (alternative when an variable already exists)
	std::string cpp_string2;
	j_string.get_to(cpp_string2);
	cout << "j_string.get_to(cpp_string2):" << cpp_string2 << endl;

	// retrieve the serialized value (explicit JSON serialization)
	std::string serialized_string = j_string.dump();
	cout << "serialized_string:" << serialized_string << endl;

	// output of original string
	std::cout << "cpp_string2 == j_string.get<std:string>():  " << cpp_string2 << " == " << j_string.get<std::string>() << '\n';

	// output of serialized value
	std::cout <<  "j_string == serialized_string : " << j_string << " == " << serialized_string << std::endl;

  return 0;
}

//.dump() always returns the serialized value, and 
//.get<std::string>() returns the originally stored string value.
//xx.get_to(std::string) , xx must store std::string , can't json serial string
//.parse()  get a json object
/*
 * ori_str:{   "happy"  :  true  ,  "pi":   3.141    }
 * json object:{"happy":true,"pi":3.141}
 * serial_string:{"happy":true,"pi":3.141}
 */
static int test_parse()
{
	//store a json serial object in JSON value
	string ori_str = "{   \"happy\"  :  true  ,  \"pi\":   3.141   }";
	cout << "ori_str:" << ori_str << endl;

	json j_obj = json::parse(ori_str);
	cout << "json object:" << j_obj << endl;

	std::string serial_string = j_obj.dump();
	cout << "serial_string:" << serial_string << endl;

  return 0;
}

extern int sample_test()
{
	if (test_j_string() != 0) {
    dd();
    return 1;
  }

	if (test_parse() != 0) {
    dd();
    return 1;
  }

	return 0;
}


int main()
{
	sample_test();

	return 0;
}

