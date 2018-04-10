<img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQsQNvEqjnkYAZa4ZjqcJTX2TNqcsu-T-RBw_PMH3ZAVr6QQczC3w"/>

Skład:  
  
| Imię i nazwisko | Rola |  
| -------- | -------- |  
| Artur Knopik  | Developer (c++)   |  

-----

![](https://thinkspacestudio.com/images/z/zombiemazecalendar15c556c9919.jpg)
# Instrukcja kompilacja/używania gotowego pliku .exe
- Aby program po skompilowaniu działał poprawnie należy skopiować folder z głównego katalogu repozytorium ```"resource"``` do ``` "*\SFML_GAME_PROJECT" ``` (domyślny folder budowy projektu)  
* Następnie należy skopiować ```"libgcc_s_dw2-1.dll"``` i ```"libstdc++-6.dll"``` z folderu ```"C:\MinGW\bin"```(domyślny folder instalacji MinGW) lub z folderu ``"*\LIBS"``  do ```"*\SFML_GAME_PROJECT"``` 

  > Podczas bezpośredniego uruchomienia pliku ```.exe``` jest wymagany folder``` "resource"``` wraz z zawartością.

 ---
 
# Rozwój projektu - Historia
 - 30.03.2018 - Zaimportowano podstawowy szablon aplikacji: 
 	+ Konfiguracja Cmake:
 		+ Widnows:
 		+ Linux (Do naprawy: na wirtualnej maszynie działa, normalnie zainstalowany Linux już nie)  
 	+ StateMenager:
 		+ MenuState
 		+ PlayState
 		+ PauseState  

 - 03.04.2018  
   + zaimplementowano prosty model "Entity" (Abstrakcyjna) oraz dodano nową klasę do tej rodziny
     + Player 
   + zaimplementowano prosty model "Controller" (Abstrakcyjna) oraz dodano nową klasę do tej rodziny   
     + PlayerController
   + Zaimplementowany szablon ładowania Poziomów PlayedLevel (Abstrakcyjna)
   +  Zaimplementowany szablon ładowania części poziomów RoomLevel (Abstrakcyjna)  
   + Dodano nową klasę do rodziny Entity
     + Brick
 - 10.04.2018   
   + Drobne zmiany w Entity odnoszące się do pozycji gracza   
   + dodano nowy obiekt do rodziny Controller
   		+   SimpleCreatureController
   + Dodano nową klasę do rodziny Entity
   	 + SimpleEnemy
   + Dodano nową klasę do rodziny Level
   		+ Test_Level
   + Dodano nową klasę do rodziny Room
   		+ Test_Room
   + Dodano CollisionChecker - wykrywanie kolizji oraz ustawianie odpowiednich flag dla obiektów typu Entity


