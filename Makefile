SRC = $(wildcard *805.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
main: $(OBJ)
	g++ $< -o $@ -g
 
$(OBJ): $(SRC)
	g++ -c $< -o $@ -g
 
clean:
	rm -rf $(OBJ) main
