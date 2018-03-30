<img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQsQNvEqjnkYAZa4ZjqcJTX2TNqcsu-T-RBw_PMH3ZAVr6QQczC3w"/>

Skład:  
  
| Imię i nazwisko | Rola |  
| -------- | -------- |  
| Artur Knopik  | Developer (c++)   |  

-----

![](https://thinkspacestudio.com/images/z/zombiemazecalendar15c556c9919.jpg)
# Instrukcja kompilacja/używania gotowego pliku .exe
- Aby program po skompilowaniu działał poprawnie należy skopiowa folder z głównego katalogu repozytorium ```"resource"``` do ``` "*\SFML_GAME_PROJECT" ``` (domyślny folder budowy projektu)  
* Nastpnie naley skopiowa ```"libgcc_s_dw2-1.dll"``` i ```"libstdc++-6.dll"``` z folderu ```"C:\MinGW\bin"```(domylny folder instalacji MinGW) lub z folderu ``"*\LIBS"``  do ```"*\SFML_GAME_PROJECT"``` 

  > Podczas bezpośredniego uruchomienia pliku ```.exe``` jest wymagany folder``` "resource"``` wraz z zawartością.

 ---
 
# Rozwój projektu
 - 30.03.2018 - Zainportowano podstawowy szablon aplikacji:  
 	+ Konfiguracja Cmake:
 		+ Widnows:
 		+ Linux (Do naprawy: na wirtualnej maszynie działa, normalnie zainstalowany Linux już nie)  
 	+ StateMenager:
 		+ MenuState
 		+ PlayState
 		+ PauseState  
	- Podjęcie decyzji o stworzeniu Klona Super Mario Bros





