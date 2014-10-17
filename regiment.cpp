#include "regiment.h"

Regiment::Regiment(CategorieUnite categorie, bool porteDrapeau, bool musicien, Figurine* champion)
  :Unite(categorie)
{
  porteDrapeau_ = porteDrapeau;
  musicien_ = musicien;
  champion_ = champion;
}
