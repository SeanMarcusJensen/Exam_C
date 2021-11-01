INCLDIR = ./include
CC = gcc
CFLAGS = -O2
CFLAGS += -I$(INCLDIR)

OBJDIR = obj
#List all .h files here.
_DEPS = test.h
DEPS = $(patsubst %,$(INCLDIR)/%,$(_DEPS))

#List all .c Files here with .o
_OBJS = main.o
OBJS = $(patsubst %, $(OBJDIR)/%,$(_OBJS))

$(OBJDIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#Change oppg1 to whatever name desired.
oppg1:$(OBJS)
	gcc -o $@ $^ $(CFLAGS) 

#Here change execute to oppgname.
exe:
	./oppg1

.PHONY: clean
clean: 
	rm -f $(OBJDIR)/*.o *~ core $(INCLDIR)/*~ 
