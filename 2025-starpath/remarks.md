### Compiler Warnings

When built it may complain about argc and argv being unused.
I am old school and can't imagine main() not including them, so please
ignore those warnings.

### Requirements

Ideally you will run the program in a shell that supports vt340 "sixel"
support.  Many shells do.

On a Debian Linux system at least your best bet is to run it inside of an 
xterm run with the following
```
    xterm -ti vt340
```

The _try.sh_ script will attempt to do this for you.

Alternately you can direct the output to a file and use ImageMagick
but it will only show the first frame of the animation.
```
    ./prog > out.sixel
    display out.sixel
```

### Obfuscation

Rather than going for intentional obfuscation, this entry is size-coded.

This is inspired by the size-optimization of Applesoft BASIC (and other
8-bit systems) that were done on a now sadly discontinued series of
twitter-bots.

It turns out size-coding is often indistinguishable from obfuscation.

This was an attempt to take a program and make the source code as small
as possible.

Some examples of things you can do:
- Turn if/else constructs into ternary operator when possible
- Re-use variables when possible
- Move increments from loop headers out into the loop body
- Avoid whitespace
- Shrink constants when possible (Ironically tricks like 1e4 instead of 10000 don't work as well in C as they do in BASIC or javascript because modern C can be strict at times)
- Try to collapse loops and statements to avoid need for curly brackets
- Avoid == in various ways

Often these changes, especially ones that use multiply or divide,
can be bad for performance on some systems.
However the hope is an optimizing compiler can see past that and
re-optimize the code to something that will run quickly on modern machines.

In the end I skipped some optimizations that would have worked in the
old days but cause compiler warnings these days (mostly abusing orders
of operations, or having single-statement code blocks triggering
indent warnings if you put more on the same line).

I also skipped a few places where single-byte text constants could
be changed to the equivalent two-digit numeric variant for
aesthetics reasons.

### Background

This is a variant of _Starpath_, a 64-byte MS-DOS/VGA demoscene demo
by Hellmood released at Lovebyte 2025.  This demo does raymarching and
various clever things to get the animation, the gradient sky, and the stars
all in a 64-byte executable.

Obviously this ends up being a lot larger than 64-bytes of 8086 assembly.

This version about 1/3 of the code is the actual ray-marching, and the
latter 2/3 is code taking each frame and turning it into a sixel image.
