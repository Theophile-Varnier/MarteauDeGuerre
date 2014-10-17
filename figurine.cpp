#include "figurine.h"

Figurine::Figurine(int M, int CC, int CT, int F, int E, int PV, int I, int A, int Cd){
  M_ = M;
  CC_ = CC;
  CT_ = CT;
  F_ = F;
  E_ = E;
  PV_ = PV;
  I_ = I;
  A_ = A;
  Cd_ = Cd;
}

int Figurine::Mouvement() const{
  return M_;
}

int Figurine::CapaciteCombat() const{
  return CC_;
}

int Figurine::CapaciteTir() const{
  return CT_;
}

int Figurine::Force() const{
  return F_;
}

int Figurine::Endurence() const{
  return E_;
}

int Figurine::PointsDeVie() const{
  return PV_;
}

int Figurine::Initiative() const{
  return I_;
}

int Figurine::Attaques() const{
  return A_;
}

int Figurine::Commandement() const{
  return Cd_;
}

std::ostream& operator<<(std::ostream& Stream, const Figurine& Obj){

  Stream << "M | CC | CT | F | E | PV | I | A | Cd\n"
    << Obj.M_ << "   " << Obj.CC_ << "    " << Obj.CT_ << "    " << Obj.F_ << "   " << Obj.E_ << "   " << Obj.PV_ << "    "
    << Obj.I_ << "   " << Obj.A_ << "   " << Obj.Cd_;
  return Stream;
}
