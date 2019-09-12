CC = g++
LIBS = -Wall -g -lgtest_main -lgtest -lpthread -pthread
Usuario = teste_usuario teste_usuario.cpp
Partida = teste_partida teste_partida.cpp
Cartao =  teste_cartao teste_cartao.cpp
Ingresso = teste_ingresso teste_ingresso.cpp


testeUsuario:
	${CC} -o  $(Usuario) ${LIBS}
	./teste_usuario

testePartida:
	${CC} -o $(Partida) ${LIBS}
	./teste_partida

testeCartao:
	${CC} -o $(Cartao) ${LIBS}
	./teste_cartao

testeIngresso:
	$(CC) -o $(Ingresso) $(LIBS)
	./teste_ingresso
