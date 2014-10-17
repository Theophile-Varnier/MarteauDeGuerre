#ifndef _SORCIER_H_
#define _SORCIER_H_

#include "personnage.h"

class Sorcier: public Personnage
{
  public:
    Sorcier(CategorieUnite, int);
  private:
    int niveau_;
};
#endif
