#include <iostream>
#include "textAdven.hpp"
#include <vector>
#include <list>
#include <string>

//// I believe this is finished /////: in main just need to have appropriate adds and removes for each vertex
//this is in github now, look into git pull-ing 
Inventory::Inventory() {
  Items emergencyHelp;
  Items Clues;
  Items healthItems;
  Items Weapons;
  Items Coinage;
  emergencyHelp.Type = "EMERGENCY HELP";
  emergencyHelp.Name = "N/A";
  emergencyHelp.Quantity = 3;
  emergencyHelp.Key = "N/A";
  emergencyHelp.nextItem = NULL;
  //
  Clues.Type = "CLUES";
  Clues.Name = "N/A";
  Clues.Quantity = -1;
  Clues.Key = "N/A";
  Clues.nextItem = NULL;
  //
  healthItems.Type = "HEALTH ITEMS";
  healthItems.Name = "N/A";
  healthItems.Quantity = -1;
  healthItems.Key = "N/A";
  healthItems.nextItem = NULL;
  //
  Weapons.Type = "WEAPONS";
  Weapons.Name = "N/A";
  Weapons.Quantity = -1;
  Weapons.Key = "N/A";
  Weapons.nextItem = NULL;
  //
  Coinage.Type = "COINAGE";
  Coinage.Name = "N/A";
  Coinage.Quantity = -1;
  Coinage.Key = "N/A";
  Coinage.nextItem = NULL;
  inventory.push_back(emergencyHelp);
  inventory.push_back(Clues);
  inventory.push_back(healthItems);
  inventory.push_back(Weapons);
  inventory.push_back(Coinage);
}

Inventory::~Inventory() {
  inventory.clear();
}
    
void Inventory::addToInventory(Items x) {
  for (int i = 0; i < 5; i++){
    if (x.Type == inventory[i].Type) {
      Items* finder = &inventory[i];
      while (finder->nextItem != NULL) {
	if (finder->Name == x.Name) {
	  finder->Quantity = finder->Quantity + x.Quantity;
	  return;
	}
	else {
	  finder = finder->nextItem;
	}
      }
      if (finder->Name == x.Name) {
	finder->Quantity = finder->Quantity + x.Quantity;
	  return;
      }
      else {
	finder->nextItem = &x;  /////is this correct?
	return;
      }
    }
  }
}

void Inventory::removeFromInventory(Items x) {
  for (int i = 0; i < 5; i++) {
    if (x.Type == inventory[i].Type) {
      Items* parentFinder = &inventory[i];
      Items* finder = (inventory[i].nextItem);
      while(finder->nextItem != NULL) {
	if (finder->Name == x.Name) {
	    finder->Quantity = finder->Quantity - 1;
	    if (finder->Quantity > 0) {
	      return;
	    }
	    else if(finder->Quantity > -10) {
	      parentFinder->nextItem = finder->nextItem;
	      delete finder;
	      finder = NULL;
	      return;
	    }
	}
	else {
	  parentFinder = finder;
	  finder = finder->nextItem;
	}
      }
      if (finder->Name == x.Name) {
	finder->Quantity = finder->Quantity - 1;
	if (finder->Quantity > 0) {
	      return;
	}
        else {
	      parentFinder->nextItem = NULL;
	      delete finder;
	      finder = NULL;
	      return;
        }
      }
      else {
	std::cout << "Could not find item" << std::endl;
	return;
      }
    }
  }
}

void Inventory::displayInventory() {
  std::cout << "EMERGENCY HELPS Left: " << inventory[0].Quantity << std::endl;
  for (int i = 1; i < 5; i++) {
    std::cout << inventory[i].Type << " in inventory: " << std::endl;
    Items* marker = inventory[i].nextItem;
    while (marker != NULL) {
      std::cout << "---" << marker->Name << ": " << marker->Quantity << " left" << std::endl;
      marker = marker->nextItem;
    }
  }
}

void Inventory::emptyInventory() {
  inventory.clear();
}

