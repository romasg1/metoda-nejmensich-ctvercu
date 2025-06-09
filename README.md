# Aproximace dat metodou nejmenších čtverců

Tento projekt slouží k odvození a testování aproximace naměřených dat lineární, konstantní i kvadratickou funkcí pomocí metody nejmenších čtverců. K vyřešení vzniklých soustav rovnic používá vlastní implementaci dříve probíraných numerických metod.

## Popis úlohy

1. **Odvození**  
   - Ruční odvození lineární aproximace (metodou nejmenších čtverců) s detailním vysvětlením každého kroku.  
   - Stejné odvození pro konstantní funkci.  

2. **Implementace v C**  
   - Funkce pro výpočet koeficientů soustavy normálních rovnic.  
   - Použití vlastní implementace metody řešení soustav (Gauss, G-J, …).  
   - Načítání testovacích dat z hlavičkového souboru `pole.h`.  

## Požadavky

- Kompilátor C (GCC, Clang nebo MSVC)  
- IDE Code::Blocks (projektový soubor `AproximaceLsq.cbp`)  

## Instalace a spuštění

1. **Otevření v Code::Blocks**  
   - Spusť Code::Blocks.  
   - Zvol **File → Open…** a načti `AproximaceLsq.cbp`.
   - NEBO PŘETÁHNI soubor .cbp na codeBlocks 

2. **Kompilace & spuštění**  
   - V hlavním toolbaru klikni na ikonu Build & Run (klávesa F9).  
   - Program se zeptá, jaký režim chcete spustit (lineární, konstantní, kvadratická).  
   - Zadáním příslušné volby se provede výpočet a výpis tabulky výsledných aproximací.


## Poznámky

- V souboru `pole.h` jsou malé testovací datové sady pro rychlé ověření funkčnosti.  
- Větší datové sady (`F.txt`, `E.txt`) obsahují šum a očekávané výsledky jsou na začátku souboru.  
- Všechny funkce jsou zdokumentované v komentářích nad jejich hlavičkami
