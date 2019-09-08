#Makefile Générique
#Projet 3 / PI2
#Etienne PENAULT / Lies AMAROUCHE

OBJS	= main.o myifisin.o redir_1.o redir_droite.o redir_tt.o streplace.o decouper.o myif.o redierr.o redir_2.o redir_gauche.o sleep.o
OUT	= Exe
CC	 = gcc
FLAGS	 = -O3 -c -Wall

all: $(OBJS)
	$(CC) $(OBJS) -o $(OUT)
main.o: main.c
	$(CC) $(FLAGS) main.c 
decouper.o: decouper.c
	$(CC) $(FLAGS) decouper.c 
myif.o: myif.c
	$(CC) $(FLAGS) myif.c 
myifisin.o: myifisin.c
	$(CC) $(FLAGS) myifisin.c
redir_1.o: redir_1.c
	$(CC) $(FLAGS) redir_1.c
redir_2.o: redir_2.c
	$(CC) $(FLAGS) redir_2.c
redir_droite.o: redir_droite.c
	$(CC) $(FLAGS) redir_droite.c
redir_gauche.o: redir_gauche.c
	$(CC) $(FLAGS) redir_gauche.c
redir_tt.o: redir_tt.c
	$(CC) $(FLAGS) redir_tt.c
streplace.o: streplace.c
	$(CC) $(FLAGS) streplace.c
sleep.o: sleep.c
	$(CC) $(FLAGS) sleep.c
redierr.o: redierr.c
	$(CC) $(FLAGS) redierr.c
clean:
	rm -f $(OBJS) $(OUT)
