SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -pg  -I$(INC) -c


all: $(BIN)/backtracking	$(BIN)/voraz

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
	
$(BIN)/bactraking: $(OBJ)/Apermutacion.o $(OBJ)/bactraking.o
	$(CXX) -o	$(BIN)/backtracking	$(OBJ)/bactraking.o	$(OBJ)/Apermutacion.o

$(OBJ)/bactraking.o: $(SRC)/backtracking.cpp $(INC)/Apermutacion.h
	$(CXX) $(CPPFLAGS) $(SRC)/backtracking.cpp -o $(OBJ)/bactraking.o	

$(OBJ)/Apermutacion.o: $(SRC)/Apermutacion.cpp $(INC)/Apermutacion.h
	$(CXX) $(CPPFLAGS) $(SRC)/Apermutacion.cpp -o $(OBJ)/Apermutacion.o

$(BIN)/voraz:	$(OBJ)/voraz.o
	$(CXX) -o $(BIN)/voraz	$(OBJ)/voraz.o 	

$(OBJ)/voraz.o:		$(SRC)/voraz.cpp 
	$(CXX) $(CPPFLAGS) $(SRC)/voraz.cpp -o $(OBJ)/voraz.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
