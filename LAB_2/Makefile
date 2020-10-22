executable: main.cpp
	gcc -lstdc++ main.cpp calculator.cpp -o Lab2
	echo 'Created executable'

sharedlib: calculator.cpp
	gcc -fpic -c calculator.cpp
	gcc -shared -o libcalc.so calculator.o
	rm calculator.o
	echo 'Created library'

clean:
	rm Lab2 libcalc.so
