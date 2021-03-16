#ifndef BCLASS_H
#define BCLASS_H

#include "base.h"

class b_class_t: public base_t
{
public:
  b_class_t (base_t *parent) : base_t (parent) {}
  b_class_t (base_t *parent, std::string name) : base_t (parent, name) {}
  ~b_class_t () {}
};

#endif
