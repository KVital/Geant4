#include "PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4RandomDirection.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction()
{
  // ������� �������� ������
  // �������� ��������� �� ����� �������
  particleGun = new G4ParticleGun(1);

  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  /*G4ParticleDefinition* gamma = particleTable->FindParticle("gamma");
  // ������������� ��� � ������� ������, ���������� ��������� ���������
  particleGun->SetParticleDefinition(gamma);
  particleGun->SetParticleEnergy(100*MeV);
  //particleGun->SetParticlePosition(G4ThreeVector(0, 0, 0));*/

if (G4UniformRand()<0.5)
{

  G4ParticleDefinition* neutron = particleTable->FindParticle("neutron");
  particleGun->SetParticleDefinition(neutron);
  particleGun->SetParticleEnergy(3.0*G4UniformRand()*GeV);
  }
else
{G4ParticleDefinition* gamma = particleTable->FindParticle("gamma");
  // ������������� ��� � ������� ������, ���������� ��������� ���������
  particleGun->SetParticleDefinition(gamma);
  particleGun->SetParticleEnergy(100*G4UniformRand()*MeV);
  //particleGun->SetParticlePosition(G4ThreeVector(0, 0, 0));
}



}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete particleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
{
  particleGun->SetParticleMomentumDirection(G4RandomDirection());
  G4double r = 117.0*mm;
  G4double h = 50.0*cm;
  G4double dl = 0.1547;
  
  G4double fs = 2*3.14159*G4UniformRand();
  G4double rs = r*(1+dl/2+dl/2*cos(6*fs));
  G4double zs = h*G4UniformRand() - h/2;

  G4double xs = rs*cos(fs);
  G4double ys = rs*sin(fs);

  particleGun->SetParticlePosition(G4ThreeVector(xs, ys, zs));
  particleGun->GeneratePrimaryVertex(event);
}

