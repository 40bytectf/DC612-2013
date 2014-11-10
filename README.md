DC612-2013
==========

Challenges from Def Con 612's 1-day event 9/3/13.

This code is intentionally exploitable and should not be run on any production system. It is provided as a means to explain and better understand binary application exploitation and reverse engineering. 

A make file will be provided shortly for all files that need to be compiled on your system.

Making on your system
=====================

cd DC12--2013/
make [directive]

all: builds all challenges in ./challenges/.
clean: removes all binaries only.
clean-all: removes from and including ./challenges/.

exploit-all: builds all exploit challenges in ./challenges/.
exploit-n: build n exploit challenge in ./challenges/.
clean-exploit: removes exploit binaries only.
clean-exploit-all: removes all exploit challenge directories.
clean-exploit-n: remove n exploit binary only.

crypto-all: builds all crypto challenges in ./challenges/.
crypto-n: build n crypt challenge in ./challenges/.
clean-crypto: removes crypto challenge binaries only.
clean-crypto-all: removes all crypto challenge directories.
clean-crypt0-n: remove n crypto challenge.
