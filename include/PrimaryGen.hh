

#ifndef CPROJECT_PRIMARYGEN_HH
#define CPROJECT_PRIMARYGEN_HH


#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"

#include "G4Event.hh"

#include "G4SystemOfUnits.hh"

#include "G4Gamma.hh"

class G4ParticleGun;
class G4Event;

class PrimaryGen : public G4VUserPrimaryGeneratorAction
{
private:
    G4double sum;
    G4int size;
    G4double dE;
    G4double Emax=545.*keV;
    G4double m0c=0.511*MeV;
    G4double E;
    G4double f;
    G4ParticleGun * gun;
    G4int i;
public:
    PrimaryGen();
    virtual ~PrimaryGen();
    virtual void GeneratePrimaries(G4Event*);
};

#endif //CPROJECT_PRIMARYGEN_HH
