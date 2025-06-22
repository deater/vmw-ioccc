### Compiler Warnings

When built it may complain about argc and argv being unused.
I am old school and can't imagine main() not including them, so please
ignore those warnings.

### Requirements

This requires a terminal emulator that supports 24-bit ANSI colors.
These days most Linux terminal emulators do, including stock xterm
(at least on Debian).

There is sound too!  On a Debian system at least if you have
    /usr/bin/aplay
it will attempt to pipe the sound into it at the default 8kHz/8-bit unsigned.
If aplay is not detected it will write the sound to the file "r.raw"
which you can then try to play on your sound program of choice, or if
you have a SUN machine, cat it to /dev/audio.

### Obfuscation

It was so hard to get this to fit in the size requirements that I stopped
obfuscating once I made it fit.

Attempts to make things look cooler or shrink things more only seemed
to make things bigger somehow.

### Background

Hopefully it's obvious what this is.  I wish I had more space, I could
have made it sneakier and also had a few more frames of animation.

It's about half animation, half music right now.  I should have optimized
the music better.

Believe it or not this is actually a rough port of an Atari 2600 version
of this program.
