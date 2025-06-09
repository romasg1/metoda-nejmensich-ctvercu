# Aproximace dat metodou nejmenších čtverců

Tento projekt slouží k odvození a testování aproximace naměřených dat lineární, konstantní i kvadratickou funkcí pomocí metody nejmenších čtverců. K vyřešení vzniklých soustav rovnic používá vlastní implementaci dříve probíraných numerických metod.

## Popis úlohy

1. **Odvození**  
   - Ruční odvození lineární aproximace (metodou nejmenších čtverců) s detailním vysvětlením každého kroku.  
   - Stejné odvození pro konstantní a kvadratickou funkci.  
   - Porovnání vašeho postupu s výukovým materiálem.  
   - Odvození vyfoťte a odevzdejte.

2. **Implementace v C**  
   - Funkce pro výpočet koeficientů soustavy normálních rovnic.  
   - Použití vlastní implementace metody řešení soustav (Gauss, LU, …).  
   - Načítání testovacích dat z hlavičkového souboru `pole.h` (očekávaná přímka ≈ `f(x) = 5.5x - 3.3`).  
   - Načítání větších datasetů z textových souborů `F.txt` (lineární) a `E.txt` (konstantní).

## Struktura projektu

AproximaceLsq/
├── src/
│ ├── main.c # Hlavní program – volba režimu a volání funkcí
│ ├── lsq.c # Výpočet koeficientů normálních rovnic
│ ├── solver.c # Implementace metody řešení soustav
│ ├── data_loader.c # Načítání z pole.h, F.txt, E.txt
│ ├── lsq.h # Hlavičkový soubor pro lsq.c
│ ├── solver.h # Hlavičkový soubor pro solver.c
│ ├── data_loader.h # Hlavičkový soubor pro data_loader.c
│ └── pole.h # Předpřipravená data pro rychlý test
├── F.txt # Data pro lineární aproximaci
├── E.txt # Data pro konstantní aproximaci
├── AproximaceLsq.cbp # Projekt pro Code::Blocks
└── README.md # Tento soubor

markdown
Zkopírovat
Upravit

## Požadavky

- Kompilátor C (GCC, Clang nebo MSVC)  
- IDE Code::Blocks (projektový soubor `AproximaceLsq.cbp`)  

## Instalace a spuštění

1. **Otevření v Code::Blocks**  
   - Spusť Code::Blocks.  
   - Zvol **File → Open…** a načti `AproximaceLsq.cbp`.  

2. **Kompilace & spuštění**  
   - V hlavním toolbaru klikni na ikonu Build & Run (klávesa F9).  
   - Program se zeptá, jaký režim chcete spustit (lineární, konstantní, kvadratická).  
   - Zadáním příslušné volby se provede výpočet a výpis tabulky výsledných aproximací.

## Ukázka výstupu

Lineární aproximace:
a0 = -3.3000, a1 = 5.5000
x: [data] f(x): [výsledná přímka]
Tabulka časů pro různá data…

Konstantní aproximace:
a0 = 2.3456
…

Kvadratická aproximace:
a0 = …, a1 = …, a2 = …
…

yaml
Zkopírovat
Upravit

## Poznámky

- V souboru `pole.h` jsou malé testovací datové sady pro rychlé ověření funkčnosti.  
- Větší datové sady (`F.txt`, `E.txt`) obsahují šum a očekávané výsledky jsou na začátku souboru.  
- Všechny funkce jsou zdokumentované v komentářích nad jejich hlavičkami
