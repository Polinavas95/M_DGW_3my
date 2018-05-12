
#include <G4PhysicalConstants.hh>
#include <G4Tubs.hh>
#include <G4Sphere.hh>
#include "DetGeometry.hh"

DetGeometry::DetGeometry() {
    world_sizeXYZ   = 50 * m;
    nist            = G4NistManager::Instance();
    material       = nist->FindOrBuildMaterial("G4_AIR");
    solidWorld      = new G4Box("solWorld", 0.5*world_sizeXYZ, 0.5*world_sizeXYZ, 0.5*world_sizeXYZ);
    logicWorld      = new G4LogicalVolume(solidWorld, material, "logWorld");
    physWorld       = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "phyWorld", 0, false, 0);
   }

DetGeometry::~DetGeometry() {}

G4VPhysicalVolume* DetGeometry::Construct(){
 G4Tubs *tubs = new G4Tubs("tubs",0,20*cm,20.*cm,0,2*pi);
    auto tubs_log = new G4LogicalVolume(tubs, nist->FindOrBuildMaterial("G4_AIR"), "tubs_LOG");
    //tubs_log->SetVisAttributes(G4Colour::Red());
    new G4PVPlacement(0, G4ThreeVector(100.*cm,0, 0), tubs_log, "tubs_PV", logicWorld, false, 0);

    G4Sphere * sphere=new G4Sphere("sphere",0,20.*cm,0,2*pi,0,pi);
    auto sphere_log=new G4LogicalVolume(sphere,nist->FindOrBuildMaterial("G4_AIR"),"sphere_log");
    //sphere_log->SetVisAttributes(G4Colour::Blue());
    new G4PVPlacement(0, G4ThreeVector(0,0, 0), sphere_log, "sphere_PV", logicWorld, false, 0);

    G4cout<<"Geometry of detector is build successfully\t\t\t\t\t\tOK!!!"<<G4endl;
    return physWorld;
}


