#include <iostream>
#include <algorithm>
#include <array>

void printArray(const char* s, const std::array<int, 5> &data)
{
  std::cout << s << '\n';
  for (auto i: data)
  {
    std::cout << i << ' ';
  }

  std::cout << '\n';
}

void findReplace(std::array<int, 5> &data)
{
  std::cout << "Enter value to FIND and REPLACE\n";

  int find{}, replace{};
  std::cin >> find >> replace;

  auto found{ std::find(data.begin(), data.end(), find)};

  if (found == data.end())
  {
    std::cout << "Value not found!\n";
  }
  else
  {
    *found = replace;
  }
}

bool containsBel(std::string_view str)
{
  return (str.find("bel") != std::string_view::npos);
}

bool containsZen(std::string_view str)
{
  return (str.find("zen") != std::string_view::npos);
}

void searchFor(std::array<std::string_view, 4> sarr)
{

  //auto found { std::find_if(sarr.begin(), sarr.end(), containsBel)};

  /*
  if (found != sarr.end())
  {
    std::cout << "Found : " << *found << '\n';
  }
  else
  {
    std::cout << "Did not found substring!\n";
  }
  */
  
  auto count { std::count_if(sarr.begin(), sarr.end(), containsZen)};

  std::cout << "Number of strings with \"zen\": " << count << '\n';

  
}


int main()
{
  /*
  * algorithms library:
  * 1. Inspectors -> view but not modify: searching and counting
  * 2. Mutators -> modify data: sorting and shuffling
  * 3. Facilitators -> generate result based on values of data members: multiply values or
  *   determine what order pairs of elements should be sorted in
  */

  //constexpr std::array<std::string_view, 4> sarr { "Hunde", "Katzen", "Kratzen", "Gabeln"};

  //searchFor(sarr);

  //std::array<int, 5> arr { 23, 32, 11, 44, 90 };

  //printArray("Before: ", arr);

  //findReplace(arr);

  //printArray("After: ", arr);

  int i {2};

  int &j = i;

  j = 3;

  std::cout << j;

  return 0;
}
