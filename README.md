# slimax

## Budowanie

Interfejs aplikacji został zbudowany z wykorzystaniem frameworka Qt w wersji 6.0.2. Aby zbudować projekt należy odpowiednio skonfigurować swoje IDE, albo umieścić wpis

``set(CMAKE_PREFIX_PATH "ścieżka_do_Qt\\lib\\cmake\\")``

przykładowo

``set(CMAKE_PREFIX_PATH "C:\\Qt\\6.0.2\\mingw81_64\\lib\\cmake")``

## Obsługa
Aplikacja posiada interfejs graficzny. W głownym oknie wyświetlone są wartości symulacji aktualizowane "na żywo" podczas jej wykonywania. Sterować danymi symulacji można za pomocą menu `Symluacja`:


- `Nowa` - otwiera okno w którym można ustawić parametry symulacji 
- `Modyfikuj` - otwiera analogiczne okno jak powzej z załadowanymi danymi aktualnej symluacji. Pozwala na jej modyfikację.
- `Zapisz` - pozwala na zapisanie aktualnej symulacji do pliku
- `Otwórz` - pozwala na odczyt symulacji z pliku


