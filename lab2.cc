// ������������ ����� ��� ������� ������� �� ����������� ����
// ��� ����� ����� � ����������� include/
#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"

// ������������ ����� ��� ������� �� ���������� Geant4
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "Randomize.hh"
#include "LHEP.hh"
// ���� � �������� ��� ������ � ��������� ��������
#include <ctime>

int main(int argc, char** argv)
{
  // ����� ���������� ��������� �����
  CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
  // � ������������� ���������� ������� ��������� �������
  // ��������� ����� ���������� ����� ���� �������� ������������� �� ����� ��������� ��������� 
  CLHEP::HepRandom::setTheSeed(time(NULL));

  // �������� ������ ��� ���������� ��������������
  G4RunManager* runManager = new G4RunManager;
  // ����������� ������������ �������
  // ����������� ������ ���������
  G4VModularPhysicsList* physList = new LHEP;
  // ��������� � ���� ������ ���������� ���������
  //physList->RegisterPhysics(new OpticalConstructor);
  runManager->SetUserInitialization(physList);
  // ����������� ������������ �������: �������� ������, ���������, ��������� � ���������
  runManager->SetUserInitialization(new PhysicsList);
  runManager->SetUserInitialization(new DetectorConstruction);
  runManager->SetUserAction(new PrimaryGeneratorAction);

  // ����������� �������������� �������: �����/���������� ����������
  runManager->SetUserAction(new RunAction);

  // �������� � ��������� ������ ��� ���������� �������������
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();
  
  // ��������� ���� �������������:
  // ���������������� ��������������� ������, ��������� � ���������
  // ������ �������, ����������� ���������, ...
  runManager->Initialize();
  
  // ������ ����������������� �����
  G4UImanager* UI = G4UImanager::GetUIpointer();
	// � argv[1] ���������� ������ �������� ��������� ������ (��� ����������������� �����)
  UI->ExecuteMacroFile(argv[1]);
  
  // ������������ ������
  delete visManager;
  delete runManager;
  // � �����
  return 0;
}
