
#include <Randomize.hh>
#include <G4Electron.hh>
#include "PrimaryGen.hh"
using namespace std;


PrimaryGen::PrimaryGen()
{
    gun = new G4ParticleGun(250);
    G4cout<<"Primary particles generator is created successfully\t\tOK!!!"<<G4endl;
}

PrimaryGen::~PrimaryGen() {
    delete gun;
}

void PrimaryGen::GeneratePrimaries(G4Event* anEvent)
{



    const G4int size=10;
    G4double E[size],f[size],sum[size];
    G4double dE = (Emax/size);

    for(int i=0;i<=size;i++) {
        E[i]=i*dE;
        f[i]=(1+Emax/m0c)*sqrt(pow(1+E[i]/m0c,2)-1)*pow(((Emax-E[i])/m0c),2);
        cout<<"E= "<<E[i]<<" ; "<<"dE = "<<dE<<" ; "<<" f(E)="<<f[i]<<endl;
//       E=dE+E;
//      sum[f+=f];
    }
    sum[0]=0;
    for(int j=1;j<=size;j++){
        sum[j]=f[j]*dE+sum[j-1];
        cout<<"Fsum= "<<sum[j]<<endl;

    }
    for(int n=0;n<=size;n++){

        sum[n]=sum[n]/sum[size];

        cout<<"plot= "<<sum[n]<<endl;
    }
G4double P=G4UniformRand();
  G4double summa=0,EBeta=0;
    G4int r=0;
    while(summa<=P){
        summa=sum[r];
        EBeta=EBeta+dE;
        r++;
        cout<<"P= "<<P<<"summa= "<<sum[r]<<" ; "<<"E = "<<EBeta<<endl;
    }


    G4double q1=2 * G4UniformRand() - 1;
    G4double q2=2 * G4UniformRand() - 1;
    G4double q3=2 * G4UniformRand() - 1;
    G4double l=sqrt(pow(q1,2)+pow(q2,2)+pow(q3,2));
    G4double i=G4UniformRand();
    G4double X=20.*cm,Y=20.*cm,Z=20.*cm,R=20.*cm;
    if(i<=0.7) {

        do {
            X = (10 * (2 * G4UniformRand() - 1));
            Y = (10 * (2 * G4UniformRand() - 1));
            Z = (10 * (2 * G4UniformRand() - 1));
        }    while (sqrt(X * X + Y * Y + Z * Z) > R);


        gun->SetParticleDefinition(G4Gamma::GammaDefinition());
        gun->SetParticlePosition(G4ThreeVector(X, Y, Z));
        gun->SetParticleEnergy(661. * keV);
        gun->SetParticleMomentumDirection(G4ThreeVector(0, 1/ sqrt(2.), 1/ sqrt(2.)));
        gun->GeneratePrimaryVertex(anEvent);

    }
    G4double X1=0,Y1=0,R1=20.*cm;
    G4double Z1=(10 * (2 * G4UniformRand() - 1));
        do {
            X1 = (10 * (2 * G4UniformRand() - 1));
            Y1 = (10 * (2 * G4UniformRand() - 1));
        } while (sqrt(X1* X1 + Y1 * Y1) > R1);

        gun->SetParticleDefinition(G4Electron::ElectronDefinition());
//    gun->SetParticlePosition(G4ThreeVector( 100.*cm,0,0));
        gun->SetParticlePosition(
                G4ThreeVector(100. * cm +X1, Y1,Z1));
        gun->SetParticleEnergy(EBeta * keV);
        gun->SetParticleMomentumDirection(G4ThreeVector(q1 / l, q2 / l, q3 / l));
        gun->GeneratePrimaryVertex(anEvent);
}