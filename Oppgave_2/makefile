INCLDIR = ./include
CC = gcc
CFLAGS = -O2
CFLAGS += -I$(INCLDIR)
NAME = oppg2

OBJDIR = obj

#List all .h files here.
_DEPS = ReadAndConvert.h
DEPS = $(patsubst %,$(INCLDIR)/%,$(_DEPS))

#List all .c Files here with .o
_OBJS = $(NAME).o ReadAndConvert.o
OBJS = $(patsubst %, $(OBJDIR)/%,$(_OBJS))

$(OBJDIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#Change oppg1 to whatever name desired.
$(NAME):$(OBJS)
	gcc -o $@ $^ $(CFLAGS) 

#Here change execute to oppgname.
exe:
	./$(NAME)

.PHONY: clean
clean: 
	rm -f $(OBJDIR)/*.o *~ core $(INCLDIR)/*~ ./$(NAME)
