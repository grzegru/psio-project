## Opis projektu 
Celem projektu było zrobienie adaptacji gry FlappyBird. Jest to gra która w 2013 roku była jedną z najbardziej popularnych gier na urządzenia mobline, została nazwana najpopularniejszą darmową grą na świecie. Jest to gra o prostej rozgrywce, o charakterze gry zręcznościowej. Głównym zadaniem gracza jest przelatywanie między rurami i staranie się, żeby uniknąć kolizji pokonując jak najwięcej przeszkód(rur)
#### W projekcie docelowo utworzyłem 8 klas które składają się na plik .cpp oraz plik .h. W każdnym pliku .h mamy nagłówki metod, natomiast w pliku .cpp mamy całe ciało metody. 
##### Klasa Background odpowiada za: 
- wczytywanie tła oraz jego rysowanie,
##### Klasa Bird odpowiada za: 
- wczytywanie 4 tekstur ptaka oraz zapisywanie ich do wektora,
- animacje ruchu skrzydel ptaka poprzez wyswietlanie kazdej z 4 tekstur po kolei,
- wyłapywanie klikniecia na ekran, powoduje to odtworzenie dźwięku lotu ptaka, oraz restart zegara
- w metodzie Update po restarcie zegara odbywa się lot w góre ptaka oraz jego rotacja, po upłynięciu pewnego czasu ptak zaczyna spadać oraz rotować(do pewnego momentu) w przeciwnym kierunku.
- funkcja GetSprite która ma za zadanie zwracac sprite ptaka który jest potrzebny do kolizji,
- funkcja setposition która odpowiada za położenie początkowe ptaka na początku nowej gry,
- spadek ptaka po kolizji z obiektem az do upadku na podłoże
- rysowanie obiektu
##### Klasa Collisions odpowiada za:
- odgłos koliji,
- funkcje CheckCollisions które są przesilone i w zależności od podania ilości obiektów mają odpowiadać za kolizje ptaka z podłożem lub tez rurami, w momencie kolizji zwracają wartość true,
##### Klasa GameManu odpowiada za:
-rysowanie wszystkich potrzebnych obiektow na poczatku gry oraz w ekranie przygotowania do gry,
##### Klasa gameover odpowiada za:
- rysowanie obiektów końcowych gry, w zależności od ilości punktów różnego medalu, oraz wyświetlanie ilość punktow
- otworzenie pliku z zapisanym rekordem, sprawdzenie czy najnowszny wynik jest wyższy niż rekord, jeśli tak to nadpisanie pliku i wyświetlenie rekordu
##### Klasa Ground odpowiada za:
- rysowanie, ruch podłoża oraz zwracanie sprita ground potrzebnego do kolizji,
##### Klasa Pipe odpowiada za:
- ustawienie poczatkowe rur,
- ruch rur i ich ponowne pojawienie sie po tym gdy rura "ucieknie" za ekran,
- losowosc polozenia rur w osi OY z zachowaniem stałej odległości między nimi
- zwracanie pozycji rur
- zwracanie wartości true po tym gdy pozycja ptaka jest wieksza niz pozycja rury(co docelowo prowadzi do zwiekszania ilosci punktow)
- ustawianie pozycji startowych rur
##### Klasa Points odpowiada za:
- zamianie ilosci punktow na zmienna typu "string" aby wyświetlić ilość punktów za pomocą font'a
- wyswietlanie ilosci punktow na ekranie,
- odglos zdobycia punkta,
Plik main.cpp w którym tworzone są obiekty, okno programu oraz wywoływane są funkcję.
## Sterowanie oraz zasady gry
W grze całe sterowanie opiera się na lewym przycisku myszy. Po kliknięciu play wyświetla się okno z lecącym ptakiem oraz komunikatem do przygotowania, po kolejnym kliknięciu zaczynają pojawiać się rury, a na ptaka zaczyna działać grawitacja. Rozgrywka kończy się wraz z kolizją z podłożem lub z rurami. Zostaję wyświetlony wynik końcowy, rekord oraz przyciski do ponownego zagrania lub też wyjścia z gry.
## Niezbędne biblioteki 
SFML-2.5.1
## Zewnętrzne zasoby 
Część grafik została wykonana przeze mnie, inne zostały zapożyczone, były one na licencji pozwalającej na ogólny dostęp, jedynie mile widziane jest wspomnienie:
- ptak - OpenGameArt.org ; autor: bevouliin.com 
- tło, rury oraz podłoże-  kenney.nl ;
