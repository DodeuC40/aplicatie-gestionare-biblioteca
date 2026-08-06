# Sistem de Gestionare a Bibliotecii

Aplicație modulară de consolă dezvoltată în **C++17**

Acest proiect personal a fost creat pentru fixarea noțiunilor de OOP și învățarea etapelor de dezvoltare a unei aplicații C++ (organizarea în fișiere .h / .cpp, compilare prin terminal, configurare CMake). În realizarea proiectului am folosit asistența AI pentru verificarea codului și pentru a mă ghida în configurarea mediului de lucru.

## Facilitățile principale
- Bază de date cu cărți și elevi + date de identificare pentru fiecare;
- Posibilitatea de adăugare și ștergere a elevilor / cărților din baza de date;
- Sistem de împrumut - retur, care ține evidența automată a istoricului de împrumuturi;
- Protecție împotriva erorilor de introducere a datelor prin folosirea unei functii speciale de citire (citesteNumar din fisierul main.cpp);
- Salvarea și încărcarea automată din fișiere text (`.txt`) a datelor.

## Structura proiectului 
aplicatie_biblioteca/
├── include/       # Fișiere de antet (.h)
├── src/           # Fișiere de implementare (.cpp)
├── build/         # Fișiere de compilare și executabil (generat)
└── CMakeLists.txt # Script de configurare CMake 

## Cerințe anterioare
Compilator C++17 (g++, clang sau MSVC)
CMake 3.12+

## Comenzi de build
1. Generarea fișierelor de configurare
cmake -B build

2. Compilarea proiectului
cmake --build build

3. Rularea executabilului
Pe Windows:
.\build\Debug\biblioteca.exe

Pe Linux / macOS:
./build/biblioteca