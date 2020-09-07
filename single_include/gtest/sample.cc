
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

#define  dd()  do  { cerr << __func__ << ":" << __LINE__  << endl; } while (0)

static int test_j_string()
{
	// store a string in a JSON value
	json j_string = "this is a string";

	// retrieve the string value (alternative when an variable already exists)
	std::string cpp_string2;
	j_string.get_to(cpp_string2);
	cout << "j_string.get_to(cpp_string):" << cpp_string2 << endl;

	// retrieve the serialized value (explicit JSON serialization)
	std::string serialized_string = j_string.dump();
	cout << "serialized_string:" << serialized_string << endl;

	// output of original string
	std::cout << cpp_string2 << " == " << j_string.get<std::string>() << '\n';

	// output of serialized value
	std::cout << j_string << " == " << serialized_string << std::endl;

  return 0;
}

//.dump() always returns the serialized value, and 
//.get<std::string>() returns the originally stored string value.
//xx.get_to(std::string) , xx must store std::string , can't json serial string
//.parse()  get a json object
static int test_parse()
{
	//store a json serial object in JSON value
	json j_obj = json::parse("{ \"happy\": true, \"pi\": 3.141 }");
	cout << "j_serial string:" << j_obj << endl;

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

