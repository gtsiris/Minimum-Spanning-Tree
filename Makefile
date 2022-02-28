objects=Exercise_9.o MSTImplementation.o
Exercise_9 : $(objects)
	gcc $(objects) -o Exercise_9
Exercise_9.o :Exercise_9.c MSTInterface.h MSTTypes.h
	gcc -c Exercise_9.c
MSTImplementation.o :MSTImplementation.c MSTInterface.h MSTTypes.h
	gcc -c MSTImplementation.c
clean:
	rm Exercise_9 $(objects)
