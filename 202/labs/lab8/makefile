CXX = g++
CXXFLAGS = -Wall

lab8: Candle.o Scented.o Birthday.o lab8.cpp
	$(CXX) $(CXXFLAGS) Candle.o Scented.o Birthday.o lab8.cpp -o lab8

Birthday.o: Birthday.cpp Birthday.h
	$(CXX) $(CXXFLAGS) -c Birthday.cpp

Scented.o: Scented.cpp Scented.h
	$(CXX) $(CXXFLAGS) -c Scented.cpp

Candle.o: Candle.cpp Candle.h
	$(CXX) $(CXXFLAGS) -c Candle.cpp

clean:
	rm *.o
	rm *~

run:
	./lab8