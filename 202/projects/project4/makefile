CXX = g++
CXXFLAGS = -Wall

proj4: Plant.o Tree.o Vegetable.o Fruit.o Flower.o Garden.o driver.cpp driver.h
	$(CXX) $(CXXFLAGS) Plant.o Tree.o Fruit.o Vegetable.o Flower.o Garden.o driver.h driver.cpp -o proj4

Vegetable.o: Plant.cpp Plant.h Vegetable.cpp Vegetable.h
	$(CXX) $(CXXFLAGS) -c Vegetable.cpp

Tree.o: Plant.cpp Plant.h Fruit.cpp Fruit.h Tree.cpp Tree.h
	$(CXX) $(CXXFLAGS) -c Tree.cpp

Fruit.o: Fruit.cpp Fruit.h
	$(CXX) $(CXXFLAGS) -c Fruit.cpp

Flower.o: Plant.cpp Plant.h Flower.cpp Flower.h
	$(CXX) $(CXXFLAGS) -c Flower.cpp

Plant.o: Plant.cpp Plant.h
	$(CXX) $(CXXFLAGS) -c Plant.cpp

Garden.o: Plant.cpp Plant.h Fruit.cpp Fruit.h Tree.cpp Tree.h Vegetable.cpp Vegetable.h Flower.cpp Flower.h Garden.cpp Garden.h
	$(CXX) $(CXXFLAGS) -c Garden.cpp

clean:
	rm *.o*

run:
	./proj4