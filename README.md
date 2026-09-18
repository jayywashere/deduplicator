# deduplicator

> a small CLI for finding duplicate files because who knows if i have 873 duplicate images of the same cat (WHO knows?)

## About

`deduplicator` is a small file deduplication CLI written in `C++`!

i made this mainly to practice working with:

- `std::filesystem`
- file I/O
- binary file comparison
- `std::vector`
- `std::unordered_map`
- C++ project structure
- CMake
- separating scanning, grouping, comparison, and reporting logic
- making a program that actually does something useful instead of just printing `hello world` for the 1000th time yes?
- actually made me spend 30 minutes learning batch files......... so... they might look REALLY different!!..

the program scans a directory recursively, groups files that have the same size, compares those candidates byte-for-byte, and reports the files that are actually duplicates. . .

DO TAKE NOTE THAT, uhmm, if you enter a valid directory and the program is, uhh, taking "too" long to respond... just wait! they're just doing their job... haha....

## Features

- recursive directory scanning
- groups files by size before comparing them
- byte-for-byte duplicate comparison
- duplicate group reporting
- interactive directory input
- accepts paths containing spaces
- `q`, `quit`, or `exit` to leave the program
- CMake build system
- small reusable components instead of one enormous `main.cpp`
- does **not** automatically delete anything because i would like my files to remain alive, pretty please

## How It Works

`deduplicator` uses a few stages:

```text
directory
    ↓
 Scanner
    ↓
files grouped by size
    ↓
 Grouper
    ↓
same-size candidates compared (groups of <2 are removed before proceeding)
    ↓
 Comparator
    ↓
duplicate groups (groups of <2 are removed before proceeding)
    ↓
 Reporter
```

the size grouping is useful because two files with different sizes cannot possibly contain the exact same contents.. but they could, coincidentally..

once files have been grouped by size, only files within the same group need to be compared byte-for-byte!!

so, like, instead of comparing every file against every other file:

```text
file A ── file B
       ├─ file C
       ├─ file D
       └─ ...
```

the program first narrows the candidates:

```text
size: 532 bytes
├── file A
├── file B
└── file C

size: 1024 bytes
├── file D
└── file E
```

and then compares files within each group.! how lovely..

## Example

a normal session looks something like this:

```text
Welcome to the deduplicator!

Enter a directory path, or type 'q' to exit:
> ../../

=================================================================
                      DUPLICATE FILE REPORT
=================================================================

[Group #1] - Size: 36 bytes
-----------------------------------------------------------------
  ../../Demos\minigrep\.git\COMMIT_EDITMSG
  ../../Demos\text-analyzer\.git\COMMIT_EDITMSG

[Group #2] - Size: 416 bytes
-----------------------------------------------------------------
  ../../APlus\.git\logs\HEAD
  ../../APlus\.git\logs\refs\heads\master

...

=================================================================

Enter a directory path, or type 'q' to exit:
> .
No duplicate files found! Your drive is clean.

Enter a directory path, or type 'q' to exit:
> q
Goodbye!
```

btw: q/quit/exit works! oh wow, what a FUN fact... totally,... obviously..,?... ok..

## Why I Made This

um.. i wanted a C++ project that was a little more practical than the usual:

```text
read input
do something
print result
```

_(how many times have i repeated that thing.. i really AM making excuses, huh.. wait, NO... I'M NOT.)_

and i also wanted to actually work with C++'s filesystem and file I/O instead of just knowing that `std::filesystem` exists and then proceeding to never touch it !

it also gave me an excuse to learn more about structuring a C++ project with headers, source files, CMake, and separate components without turning the project into 47 abstract interfaces for no reason. . . i really wanted to use the `module`, `export`, and `import` thingies to replace the crusty `#include` module system... aha!!

## Requirements

- C++23
- CMake 3.25 or newer or whatever.. just, um, manually compile it?!? if you don't have!?!
- a C++23-compatible compiler
- pretty obvious, because i am seen using `<print>` (maybe?)

## Running

clone the repository:

```powershell
git clone https://github.com/jayywashere/deduplicator
cd deduplicator
```

configure and build:

```powershell
cmake -S . -B build
cmake --build build --parallel
```

run it:

```powershell
./build/deduplicator
```

on Windows:

```powershell
.\build\deduplicator.exe
```

### Development Script

the repository also includes small Windows batch scripts for development:

```powershell
.\dev
# .bat is omitted
```

which configures, builds, and runs the program.

you can also use:

```powershell
.\dev --silent
# .bat is omitted
```

for quieter output. (who wants this??)

## License

See [LICENSE](LICENSE).
