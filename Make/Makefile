generate_output: generate_output.o
	g++ generate_output.cpp -o generate_output.exe
generate_output.o: generate_output.cpp
	g++ -c generate_output.cpp generate_output.h -o generate_output.o
clean:
	rm *.o
	rm *.exe
	rm Codingame.cpp