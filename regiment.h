#ifndef _REGIMENT_H_
#define _REGIMENT_H_

#include "unite.h"

class Regiment: public Unite
{
  public:
    Regiment(CategorieUnite, bool, bool, Figurine*);
  private:
    bool porteDrapeau_;
    bool musicien_;
    Figurine* champion_;


};
#endif
