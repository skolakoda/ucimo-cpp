# Učimo C++

Vežbe i primeri za programski jezik C++. Napomena: Neki primeri su platformski specifični, samo za Win ili Linux.

Korisni tutorijali:

- [C++ Tutorial (SoloLearn)](https://www.sololearn.com/Course/CPlusPlus/)

Vidi još: [Učimo C](https://github.com/skolakoda/ucimo-c) i [Učimo OpenGL](https://github.com/skolakoda/ucimo-opengl).

## Kompajliranje

Kompajliranje C++ fajla na Linuxu:

```
g++ zdravo.cpp
```

To će napraviti izlazni fajl `a.out` koji pokrećemo na sledeći način:

```
./a.out
```

Komanda za imenovani izlazni fajl je:

```
g++ zdravo.cpp -o zdravo
```

Ukoliko program koristi neku biblioteku, npr. OpenGL, potrebno je instalirati biblioteku, te dodati opcije prevodioca:

```
gcc ime-fajla.cpp -o ime-fajla -lGL -lGLU -lglut
```

## Projekti

Unutar repozitorija se nalazi nekoliko projekata, za čije pokretanje je potrebno odgovarajuće razvojno okruženje (IDE): Code Blocks ili Visual Studio.

Vidi uputstvo za pravljenje C++ projekta u Code Blocks editoru:
http://wiki.codeblocks.org/index.php/Creating_a_new_project

## Linkovi

http://jeanpetric.github.io/2016/03/30/simple-game-development-using-c-and-sdl.html

https://github.com/caioteixeira/Asteroids
