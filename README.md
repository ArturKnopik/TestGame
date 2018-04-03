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
	- Podjęcie decyzji o stworzeniu Klona Super Mario Bros

 - 03.04.2018  
  + zaimplementowano prosty model "Entity" (Abstrakcyjna) 
     +  Player (grywalna)
  + zaimplementowano prosty model "Controller" <Abstrakcyjna>   
     + PlayerController (podstawowa kontrolo gracza, brak grawitacji oraz przyśpieszenia)
  + Zaimplementowany szablon ładowania Poziomów PlayedLevel (Abstrakcyjna)
  +  Zaimplementowany szablon ładowania części poziomów RoomLevel (Abstrakcyjna)  
   + Dodano nowy obiekt do rodziny Entity
     + Brick



