CC=gcc
CFLAGS=-g -O0
ECFLAGS=$(CFLAGS) -fno-stack-protector
CCFLAGS=$(CFLAGS) -Wall
CWD=$(PWD)
OUTPATH=$(CWD)/challenges

all: dir exploit-all crypto-all
dir:
	mkdir -p $(OUTPATH)

exploit-all: exploit-1 exploit-2 exploit-3 exploit-4
exploit-1:
	mkdir -p $(OUTPATH)/exploit1 && \
	$(CC) -o $(OUTPATH)/exploit1/exploit1 $(ECFLAGS) $(CWD)/c/exploit1/stack-0.c
exploit-2:
	mkdir -p $(OUTPATH)/exploit2 && \
	$(CC) -o $(OUTPATH)/exploit2/exploit2 $(ECFLAGS) $(CWD)/c/exploit2/variables.c
exploit-3:
	mkdir -p $(OUTPATH)/exploit3 && \
	$(CC) -o $(OUTPATH)/exploit3/exploit3 $(ECFLAGS) $(CWD)/c/exploit3/eip.c
exploit-4:
	mkdir -p $(OUTPATH)/exploit4 && \
	$(CC) -o $(OUTPATH)/exploit4/exploit4 $(ECFLAGS) $(CWD)/c/exploit4/exec-waht.c

crypto-all: crypto-1 crypto-2 crypto-3
crypto-1:
	mkdir -p $(OUTPATH)/crypto1 && \
	$(CC) -o $(OUTPATH)/crypto1/crypto1 $(CCFLAGS) $(CWD)/c/crypto1/rot.c
crypto-2:
	mkdir -p $(OUTPATH)/crypto2 && \
	$(CC) -o $(OUTPATH)/crypto2/crypto2 $(CCFLAGS) $(CWD)/c/crypto2/crypto2.c
crypto-3:
	mkdir -p $(OUTPATH)/crypto3 && \
	$(CC) -o $(OUTPATH)/crypto3/crypto3 $(CCFLAGS) $(CWD)/c/crypto3/crypto3.c

clean: clean-exploit clean-crypto
clean-all: clean-exploit-all clean-crypto-all clean-dirs

clean-dirs:
	rm -rf $(OUTPATH)

clean-exploit: clean-exploit-1 clean-exploit-2 clean-exploit-3 clean-exploit-4
clean-exploit-all: clean-exploit clean-exploit-dirs
clean-exploit-dirs:
	rm -rf $(OUTPATH)/exploit{1,2,3,4}
clean-exploit-1:
	rm -f $(OUTPATH)/exploit1/exploit1
clean-exploit-2:
	rm -f $(OUTPATH)/exploit2/exploit2
clean-exploit-3:
	rm -f $(OUTPATH)/exploit3/exploit3
clean-exploit-4:
	rm -f $(OUTPATH)/exploit4/exploit4

clean-crypto: clean-crypto-1 clean-crypto-2 clean-crypto-3
clean-crypto-all: clean-crypto clean-crypto-dirs
clean-crypto-dirs:
	rm -rf $(OUTPATH)/crypto{1,2,3}
clean-crypto-1:
	rm -f $(OUTPATH)/crypto1/crypto1
clean-crypto-2:
	rm -f $(OUTPATH)/crypto2/crypto2
clean-crypto-3:
	rm -f $(OUTPATH)/crypto3/crypto3
