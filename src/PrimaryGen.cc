
#include <Randomize.hh>
#include <G4Electron.hh>
#include "PrimaryGen.hh"



PrimaryGen::PrimaryGen()
{
    gun = new G4ParticleGun(10);
    G4cout<<"Primary particles generator is created successfully\t\tOK!!!"<<G4endl;
}

PrimaryGen::~PrimaryGen() {
    delete gun;
}

void PrimaryGen::GeneratePrimaries(G4Event* anEvent)
{
    G4double q1=2 * G4UniformRand() - 1;
    G4double q2=2 * G4UniformRand() - 1;
    G4double q3=2 * G4UniformRand() - 1;
    G4double l=sqrt(pow(q1,2)+pow(q2,2)+pow(q3,2));
    G4double i=G4UniformRand();
    G4double X=20,Y=20,Z=20,R=20*cm;
    if(i<=0.7) {

        while (sqrt(X * X + Y * Y + Z * Z) > R) {
            X = (10 * (2 * G4UniformRand() - 1));
            Y = (10 * (2 * G4UniformRand() - 1));
            Z = (10 * (2 * G4UniformRand() - 1));
        }

        gun->SetParticleDefinition(G4Gamma::GammaDefinition());
        gun->SetParticlePosition(G4ThreeVector(X, Y, Z));
        gun->SetParticleEnergy(661. * keV);
        gun->SetParticleMomentumDirection(G4ThreeVector(0, 1/ sqrt(2.), 1/ sqrt(2.)));
        gun->GeneratePrimaryVertex(anEvent);

    }


    gun->SetParticleDefinition(G4Electron::ElectronDefinition());
//    gun->SetParticlePosition(G4ThreeVector( 100.*cm,0,0));
    gun->SetParticlePosition(G4ThreeVector(100+(10 * (2 * G4UniformRand() - 1)), (10 * (2 * G4UniformRand() - 1)),
                                           (10 * (2 * G4UniformRand() - 1))));
    gun->SetParticleEnergy(545. * keV);
    gun->SetParticleMomentumDirection(G4ThreeVector(q1/l,q2/l,q3/l));
    gun->GeneratePrimaryVertex(anEvent);

}