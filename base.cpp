#include "base.h"

base_t::base_t (base_t *parent)
{
  set_parent (parent);

  if (m_parent != nullptr)
    m_parent->m_children.push_back (this);
}

base_t::base_t (base_t *parent, std::string name)
{
  set_parent (parent);
  set_name (name);
}

base_t::~base_t ()
{
  for (unsigned int i = 0; i < m_children.size (); i++)
    delete m_children[i];
}

void base_t::set_name (std::string name) { m_name = name; }
std::string base_t::get_name () { return m_name; }
void base_t::set_parent (base_t *parent) { m_parent = parent; }
base_t *base_t::get_parent () { return m_parent; }

void base_t::print_tree ()
{
  if (m_children.size() == 0)
    return;

  std::cout << std::endl << m_name.c_str ();

  for (unsigned int i = 0; i < m_children.size(); i++)
    std::cout << "  " << m_children[i] -> get_name().c_str ();

  for (unsigned int i = 0; i < m_children.size(); i++)
    m_children[i] -> print_tree ();
}

base_t *base_t::search_by_name (std::string name)
{
  if (m_name == name)
    return this;

  for (base_t *iter : m_children)
    {
      iter = iter->search_by_name (name);
      if (iter != nullptr)
        return iter;
    }

  return nullptr;
}

void base_t::add_to_tree (std::string root_name, std::string obj_name)
{
  base_t *node = search_by_name (root_name);
  node->add_to_children (new base_t (node, obj_name));
}

void base_t::add_to_children (base_t *children)
{
  m_children.push_back (children);
}
