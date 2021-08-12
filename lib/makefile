PROGNAME := 1D_EKLM_DMRG.out
SRCDIR   := src
OUTDIR   := build
INCDIR   := include
SMLDIR   := sml
MODDIR   := model/EKLM
DMRGDIR  := dmrg
TARGET   := $(OUTDIR)/$(PROGNAME)
SRCS     := $(wildcard $(SRCDIR)/*.cpp) $(wildcard ../../../$(SMLDIR)/*.cpp) $(wildcard ../../../$(MODDIR)/*.cpp) $(wildcard ../../../$(DMRGDIR)/*.cpp)
OBJS     := $(addprefix $(OUTDIR)/,$(patsubst %.cpp,%.o,$(SRCS)))

#CC = icpc
#CFLAGS = -Wall -std=c++17 -O3 -qopenmp -parallel -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I $(INCDIR)
#LFLAGS = -mkl

CC = g++
CFLAGS = -Wall -std=c++17 -O3 -mtune=native -march=native -Xpreprocessor -fopenmp -I ../../../$(INCDIR)
LFLAGS = -llapack -lomp

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

$(OUTDIR)/%.o: %.cpp
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OUTDIR)