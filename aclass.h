#ifndef ACLASS_H
#define ACLASS_H

#include "base.h"

class a_class_t: public base_t
{
public:
  a_class_t (base_t *parent) : base_t (parent) {}
  a_class_t (base_t *parent, std::string name) : base_t (parent, name) {}
  ~a_class_t () {}
};

#endif
