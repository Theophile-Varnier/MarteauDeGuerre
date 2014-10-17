#include "sorcier.h"

Sorcier::Sorcier(CategorieUnite categorie, int niveau)
  : Personnage(categorie)
{
  niveau_ = niveau;
}
