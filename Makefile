# Define o compilador
CXX = g++

# Define as flags de compilação
CXXFLAGS = -Wall -g

# Define os arquivos de origem e os arquivos objeto
SRCS = sistemaGestao.cpp astronauta.cpp voo.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

# Define o arquivo executável final
EXEC = sistemaGestao

# Regra padrão para compilar todos os arquivos
all: $(EXEC)

# Regra para criar o executável
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Regra para compilar arquivos .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos objeto e executável
clean:
	rm -f $(OBJS) $(EXEC)