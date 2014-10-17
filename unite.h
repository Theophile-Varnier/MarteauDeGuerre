#ifndef _UNITE_H_
#define _UNITE_H_

#include "figurine.h"
#include "common.h"
#include <list>

using std::list;

class Unite{
  public:
    Unite(CategorieUnite);
  private:
    list<Figurine*> figurines_;
    CategorieUnite categorie_;

};

#endif
