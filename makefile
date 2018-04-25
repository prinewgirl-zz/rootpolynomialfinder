roots: randomFloat.o polyderivative.o evalpoly.o deflation.o laguerre.o main.o
	gcc $^  -lm -o roots

randomFloat.o:
	gcc -c  randomFloat.c

polyderivative.o:
	gcc -c  polyderivative.c

evalpoly.o:
	gcc -c  evalpoly.c

deflation.o:
	gcc -c  deflation.c

laguerre.o:
	gcc -c  laguerre.c

main.o:
	gcc -c  main.c

clean:
	rm *.o
