CC = gcc # le compilateur à utiliser
CFLAGS = -Wall # les options du compilateur
LDFLAGS = -lsx # les options pour l’éditeur de liens
SRC = jeu.c callbacks.c data.c # les fichiers sources
PROG = jeu # nom de l’exécutable
OBJS = $(SRC:.c=.o) # les .o qui en découlent
.SUFFIXES: .c .o # lien entre les suffixes

all: $(PROG)

# étapes de compilation et d’édition de liens
# $@ la cible $^ toutes les dépendances
$(PROG): $(OBJS)
		$(CC) -o $@ $^ $(LDFLAGS)

callbacks.o: callbacks.h data.h
data.o: data.h
jeu.o: data.h callbacks.h
# le lien entre .o et .c
# $< dernière dépendance
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# pour faire propre
.PHONY: clean
clean:
		rm -f *.o *~ core $(PROG)