
#include "base.h"
#include "aclass.h"
#include "bclass.h"

int main ()
{
  std::string a_name, b_name;

  std::cin >> a_name;

  b_class_t root (nullptr, a_name);

  while (true)
    {
      std::cin >> a_name >> b_name;
      if(a_name == b_name)
        break;
      else
        root.add_to_tree (a_name, b_name);
    }

  std::cout << std::endl << root.get_name ().c_str ();
  root.print_tree ();
  return 0;
}
