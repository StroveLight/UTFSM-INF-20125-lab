CFLAGS = -g -Wall -Wextra

enumerar: enumerar.o numeros/primero.o numeros/segundo.o numeros/tercero.o
	gcc $(CFLAGS) -o $@ $^

enumerar.o: enumerar.c
	gcc $(CFLAGS) -c -o $@ $<

numeros/%.o: numeros/%.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm enumerar enumerar.o numeros/*.o