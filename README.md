<img width="692" height="972" alt="UML_Blackjack diagram1" src="https://github.com/user-attachments/assets/2486ee98-b54a-4720-898a-55cb97b27733" />
# Blackjack 🃏

Et konsolbaseret **Blackjack-spil udviklet i C++17** med fokus på objektorienteret design, testbarhed og en klar adskillelse mellem spillogik og brugergrænseflade.

Projektet er udviklet som en del af Specialisterne Academy og følger de klassiske Blackjack-regler med spiller, dealer, indsatser og blackjack-udbetaling.

## Teknisk fokus

- Objektorienteret design
- Adskillelse af spillogik og brugergrænseflade
- Unit testing med **Catch2**
- Deterministisk test af specifikke spilscenarier
- Build-system med **CMake**
- **97 % testdækning** målt med OpenCppCoverage

## Om spillet

Spillet følger de klassiske Blackjack-regler:

- Spiller og dealer starter med 2 kort.
- Spilleren kan vælge mellem **Hit** og **Stand**.
- Dealeren trækker automatisk kort, indtil hånden har en værdi på mindst 17.
- Es tæller som 11 eller 1 afhængigt af håndens værdi.
- Spilleren placerer en indsats før hver runde.
- Blackjack udbetaler **3:2**.

Brugergrænsefladen er konsolbaseret.

## Teknologier

- **C++17**
- **CMake**
- **Catch2**
- **OpenCppCoverage**

## Arkitektur

Projektet er bygget med fokus på at holde **spillogikken adskilt fra brugergrænsefladen**.

Klasserne håndterer derfor ikke selv input eller output fra konsollen. De modtager i stedet data gennem funktionsparametre og returnerer resultater til `main`.

Det gør spillogikken lettere at teste og gør det muligt at teste specifikke spilscenarier uden at simulere brugerinput.

### Centrale klasser

#### `Card`

Repræsenterer et enkelt spillekort med rang og kulør.

#### `Deck`

Administrerer kortbunken og kan:

- generere et almindeligt kortspil
- blande kortene
- dele kort ud
- oprettes med en forudbestemt kortrækkefølge til tests

Den forudbestemte kortrækkefølge gør det muligt at teste konkrete scenarier som blackjack, bust og push.

#### `Hand`

Holder spillerens kort og beregner håndens værdi.

Håndterer blandt andet:

- es som 1 eller 11
- blackjack
- bust

#### `Dealer`

Har sin egen `Hand` og følger dealerens faste regel:

> Dealeren trækker kort, så længe håndens værdi er under 17.

#### `Game`

Binder spillets dele sammen og håndterer blandt andet:

- første uddeling
- spillerens tur
- dealerens tur
- afgørelsen af vinderen
- spillets resultat

`Game` kommunikerer ikke direkte med konsollen.

##  UML-diagram

![U_Blackjack%20diagram1.jpg

Diagrammet viser relationerne mellem projektets centrale klasser.

`Game` anvender `Deck`, spillerens `Hand` og `Dealer`. `Dealer` indeholder selv en `Hand`, mens både `Deck` og `Hand` arbejder med `Card`-objekter.

## Kom godt i gang

### Krav

For at bygge projektet skal du bruge:

- En **C++17-kompatibel compiler**
  - MSVC
  - GCC
  - Clang
- **CMake 3.14+**

### Clone repository

```bash
git clone <repository-url>
cd <repository-folder># BLACKJACK
