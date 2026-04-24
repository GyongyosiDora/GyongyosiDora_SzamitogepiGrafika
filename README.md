# Haunted Room
A program egy interaktív 3D jelenetet valósít meg ahol a felhasználó egy sötét szobát járhat be belső nézetben.
A szobában különböző objektumok találhatók, illetve egy fáklya ami dinamikusan világítja be a szobát.

## Funkciók
- Kamera kezelés
- 3D modellek betöltése fájlból
- Textúrázott objektumok
- Dinamikus fénykezelés
- Használati útmutató
- Köd
- Ütközésvizsgálat
- Interaktív objektum

## Nézet és kamerakezelés
A program belső nézetes megközelítést használ.
- W, A, S, D - mozgás a térben
- Egér - nézési irány változtatása
- A mozgás során ütközésvizsgálat történik, így a felhasználó nem tud áthaladni a falakon vagy nagyobb objektumokon

## Objektumok és modellek
A jelenetben található objektumok külső fájlokból kerülnek betöltésre `.obj` formátumban.
Tervezett modellek:
- asztal
- láda
- fáklya

A modellek textúrázottak, PNG vagy JPEG formátumú képek felhasználásával.

## Fáklya és fénykezelés
A fő fényforrás egy fáklya, amit a felhasználó karaktere a kezében tart.

A fáklya:
- `.obj` formátumú modellként kerül betöltésre
- egy külső, ingyenes modellgyűjteményből származik
- a kamera pozíciójához kötött, így együtt mozog a felhasználóval
- a kamera előtt enyhe eltolással jelenik meg, mintha kézben lenne

A fáklya két részből áll:
- egy szilárd rész (maga a fáklya), ami 3D geometriával és textúrával jelenik meg
- egy lángot reprezentáló rész, ami egyszerűsített módon, színezett vagy átlátszó textúrázott síkokkal, egyszerű animációval lesz megvalósítva

A láng nem fizikai szimuláció, hanem vizuális effektként jelenik meg, amely a dinamikus fényforrással együtt biztosítja a fáklya hatását.

A fáklya dinamikus fényt bocsát ki:
- a fény intenzitása időben enyhén változik, ezzel villogó hatást kiváltva
- a felhasználó a `+` és `-` billentyűkkel tudja módosítani a fény erősségét

## Interakció
A jelenet tartalmaz egy interaktív elemet, a ládát. 

Az `E` billentyű megnyomásával nyitás/zárás animáció történik. A mozgás nem azonnali, hanem időfüggő animációval valósul meg, ami során a láda fedele fokozatosan nyílik ki vagy csukódik be.

## Használati útmutató
Az `F1` billentyű megnyomására egy képernyőre rajzolt súgó (overlay) jelenik meg, ami tartalmazza az irányításhoz szükséges információkat.

## Technológia
- C programozási nyelv
- OpenGL
- GLFW
- GLAD
- stb_image

## Fordítás
A program a következő paranccsal fordítható: `make`
