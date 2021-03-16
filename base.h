#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
#include <vector>

class base_t
{
private:
  base_t *m_parent;
  std::string m_name;
  std::vector <base_t *> m_children;

public:
  base_t (base_t *);
  base_t (base_t *, std::string);
  ~base_t ();

  void set_name (std::string);
  std::string get_name ();

  void set_parent (base_t *);
  base_t *get_parent ();

  void print_tree ();

  base_t *search_by_name (std::string);

  void add_to_tree (std::string, std::string);
  void add_to_children (base_t *);
};

#endif
