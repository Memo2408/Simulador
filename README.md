# Proyecto final de Sistemas Operativos: equipo 5

Simulador en consola de colocación de memoria con **Primer Ajuste** y **Buddy System**, y de planificación de procesos con **Round Robin**. Está escrito en C++.

Universidad Autónoma de Aguascalientes · Ingeniería en Sistemas Computacionales · 3.er semestre.

## Qué hace

- Al inicio pide estos datos y no arranca si falta alguno:
  - algoritmo (Primer Ajuste o Buddy System);
  - memoria de 1, 4 u 8 MB;
  - tamaño máximo de proceso;
  - cuanto máximo por proceso;
  - cuanto del sistema.
- Genera procesos al azar y siempre tiene uno listo para entrar.
- Los coloca en memoria con el algoritmo elegido y los atiende con Round Robin: un solo proceso por ciclo.
- Imprime cada ciclo en el formato del profesor: los procesos como `[id,tamaño,cuanto]` y los huecos como `[0,tamaño,0]`.
- El usuario controla la velocidad y decide cuándo termina la simulación.

## Equipo

| Quién | Parte | Archivos |
|---|---|---|
| Guillermo | Menú, integración y GitHub | `src/main.cpp`, `src/menu.h/.cpp`, `pruebas/diapositiva11.cpp`, `compilar.bat` y los archivos comunes |
| Germán | Primer Ajuste y generador de procesos | `src/primer_ajuste.h/.cpp`, `src/generador.cpp`, `pruebas/primer_ajuste.cpp` y `pruebas/generador.cpp` |
| Leonardo | Buddy System | `src/buddy.h/.cpp` y `pruebas/buddy.cpp` |
| Héctor | Ciclo, Round Robin y control | `src/simulador.h/.cpp`, `pruebas/ciclo.cpp` y `pruebas/generador_falso.cpp` |

## Compilar

Se necesita el g++ de WinLibs:

```
winget install BrechtSanders.WinLibs.POSIX.UCRT
```

Desde la carpeta del proyecto (el `.\` hace falta en PowerShell y también funciona en cmd):

```
.\compilar.bat
.\simulador.exe
```

`compilar.bat` compila todos los `.cpp` de `src/`. Con `-static`, el `.exe` corre en cualquier Windows sin instalar nada.

En Linux no hay `compilar.bat`; se compila con:

```
g++ -std=c++17 -O2 -Wall -o simulador src/*.cpp
```

Por eso, lo que solo existe en Windows (`<windows.h>`, `<conio.h>`, `Sleep`, `_kbhit`, `_getch`, `SetConsoleOutputCP`) va dentro de `#ifdef _WIN32`, como en `src/main.cpp`.

## Pruebas

Cada prueba es un `.cpp` con su propio `main()` dentro de `pruebas/`. Incluye los encabezados con la ruta `../src/`, por ejemplo `#include "../src/primer_ajuste.h"`. Se compila junto con los `.cpp` de `src/` que use, sin `main.cpp`, y se corre con `.\` y el nombre del `.exe`. `pruebas/ejemplo.cpp` muestra la forma.

| Prueba | Comando |
|---|---|
| Primer Ajuste | `g++ -std=c++17 -Wall -o pa.exe pruebas\primer_ajuste.cpp src\primer_ajuste.cpp` |
| Generador | `g++ -std=c++17 -Wall -o gen.exe pruebas\generador.cpp src\generador.cpp` |
| Buddy System | `g++ -std=c++17 -Wall -o buddy.exe pruebas\buddy.cpp src\buddy.cpp` |
| Ciclo, con el generador falso | `g++ -std=c++17 -Wall -o ciclo.exe pruebas\ciclo.cpp pruebas\generador_falso.cpp src\simulador.cpp` |
| Ciclo, con el generador real | `g++ -std=c++17 -Wall -o ciclo.exe pruebas\ciclo.cpp src\generador.cpp src\simulador.cpp` |
| Diapositiva 11 | `g++ -std=c++17 -Wall -o d11.exe pruebas\diapositiva11.cpp src\primer_ajuste.cpp src\generador.cpp src\simulador.cpp` |

`pruebas/generador_falso.cpp` solo se compila con las pruebas, nunca junto con `src/generador.cpp`.

## Cómo se juntan las partes

- **Archivos comunes:** `src/proceso.h`, `src/memoria.h` y `src/generador.h`. No se cambian; si alguien necesita algo distinto, se lo pide a Guillermo.
- **Encabezados de cada parte:** `src/primer_ajuste.h` (Germán), `src/buddy.h` (Leonardo) y `src/simulador.h` (Héctor) ya traen la parte pública, que no se cambia. Cada quien agrega sus datos en `private` y escribe su `.cpp`.
- **Cómo los junta `main.cpp`:**

  ```cpp
  Memoria* memoria;
  if (algoritmo == 1) memoria = new PrimerAjuste(memoriaKB);
  else                memoria = new Buddy(memoriaKB);
  Generador generador(maxTamano, maxCuanto);
  Simulador simulador(*memoria, generador, cuantoSistema);
  simulador.correr();     // corre ciclos hasta que el usuario aprieta S
  delete memoria;
  ```

- **Mientras no llega Buddy** (hasta el jueves), `main.cpp` crea solo `PrimerAjuste`: `compilar.bat` junta todos los `.cpp` de `src/`, y si `main.cpp` usa `Buddy` antes de que exista `buddy.cpp`, no enlaza.
- **Funciones auxiliares:** si alguien hace una fuera de su clase, le pone `static`, para que no choque con otra del mismo nombre en otro `.cpp`.

## Ramas

Cada quien trabaja en su rama y solo en sus archivos:

| Rama | Quién |
|---|---|
| `primer-ajuste` | Germán |
| `buddy` | Leonardo |
| `ciclo-rr` | Héctor |
| `menu` | Guillermo |

Cuando una parte funciona, su dueño abre un pull request a `main`. Guillermo lo revisa y lo integra con *Create a merge commit* (no con *Squash and merge*). `main` siempre compila, y las ramas no se borran al integrar.

Para traer a tu rama lo que ya se integró:

```
git pull --no-rebase --no-edit origin main
```

Si aun así se abre Vim, aprieta Esc, escribe `:wq` y luego Enter.
