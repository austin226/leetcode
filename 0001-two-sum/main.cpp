#include <iostream>
#include <string>
#include <string_view>

int main() {
  std::string s = "123";
  bool startsWith = s.starts_with("1");
  std::cout << "Result" << startsWith << std::endl;
}