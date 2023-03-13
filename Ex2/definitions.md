Polimorfizm dynamiczny to możliwość decydowania o tym jaka funkcja zostanie wywołana pod daną nazwą w czasie
wykonania programu zamiast w momencie kompilacji. Wykorzystywany do pracy z niejednorodnymi obiektami, wymaga
użycia wskaźników / referencji oraz funkcji wirtualnych

Plimorfizm statyczny to przeciwieństwie do dynamicznego decyduje o tym jaka funkcja zostanie wywołana pod
daną nazwą w moemencie kompilacji. Wykorzystywany do pracy z jednorodnymi obiektami, np. za pomocą szablonów.
Jest bardziej wydajny ale ma mniejsze możliwości.

Klasa abstrakcyjna - jest to klasa, której obiektu nie można utworzyć gdyż zawiera definicję funkcji wirtualnej.
Klasa taka może być rozszerzona przez inną klasę i dopiero gdy zostanie zaimplementowana matoda / metody
wirtualne, będzie można utworzyć obiekt.

Funkcja wirtualna to definicja funkcji w klasie, nie posiadająca implementacji. Metoda taka może być zaimplementowana
dopiero w klasie dziedziczącej.
