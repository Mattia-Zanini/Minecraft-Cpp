# Minecraft-Cpp

Un clone di Minecraft in C++.

## Descrizione

Questo progetto mira a ricreare le meccaniche fondamentali e l'esperienza di
gioco di Minecraft utilizzando C++ e librerie moderne. Per il momento il
progetto funziona solo macOS.

## Caratteristiche

- Generazione di chunk procedurali
- Gestione del giocatore e della telecamera
- Rendering basato su blocchi
- Sistema di input personalizzato
- Integrazione di librerie esterne (SDL3, spdlog)

## Come Compilare ed Eseguire

Questo progetto utilizza CMake per la gestione della build.

### Prerequisiti

- Un compilatore C++ (es. GCC, Clang, MSVC)
- CMake (versione 3.16)
- **spdlog**: Libreria per il logging.
- **SDL3**: Libreria per la gestione di finestre, input e audio.
- **glad**: Libreria per il caricamento dei puntatori a funzioni di OpenGL.

Per `spdlog`, `SDL3` e `glad`, è necessario scaricare le librerie e inserirle nella cartella `vendored` presente nella root del progetto.

> [!WARNING]
> Per `glad`, è **fondamentale** generare i file per la versione corretta di OpenGL. Il progetto è configurato per usare **OpenGL 4.1 (Core)**, che è la versione massima supportata da macOS.
> Quando si generano i file dal [sito ufficiale di glad](https://glad.dav1d.de/), assicurarsi di impostare:
> - `gl`: `Version 4.1`
> - `Profile`: `Core`

### Compilazione

Per compilare il progetto eseguire il seguente comando nella root del progetto:

```bash
cmake -S . -B build && cmake --build build
```

### Esecuzione

Dopo la compilazione, l'eseguibile si troverà nella directory `build/` (o
`build/Release/` su Windows, o `build/minecraftClone.app` su macOS).

Esempio (Linux/macOS):

```bash
./minecraftClone
```

## Dipendenze

- **SDL3**: Utilizzato per la gestione della finestra, input e rendering.
- **spdlog**: Utilizzato per il logging.

## Licenza

Questo progetto è rilasciato sotto la licenza MIT. Vedi il file `LICENSE` per
maggiori dettagli.
