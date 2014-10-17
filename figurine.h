#ifndef _FIGURINE_H_
#define _FIGURINE_H_

#include <ostream>
#include <string>

class Figurine
{

  friend std::ostream& operator<<(std::ostream&, const Figurine&);

  public:
    Figurine(int M, int CC, int CT, int F, int E, int PV, int I, int A, int Cd);
    int Mouvement() const;
    int CapaciteCombat() const;
    int CapaciteTir() const;
    int Force() const;
    int Endurence() const;
    int PointsDeVie() const;
    int Initiative() const;
    int Attaques() const;
    int Commandement() const;

  private:
    int M_;
    int CC_;
    int CT_;
    int F_;
    int E_;
    int PV_;
    int I_;
    int A_;
    int Cd_;
};

#endif
