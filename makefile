CC = g++
LIBS = -Wall -g -lgtest_main -lgtest -lpthread -pthread

testeUsuario:
	${CC} -o teste_usuario teste_usuario.cpp ${LIBS}
	./teste_usuario

testePartida:
	${CC} -o teste_partida teste_partida.cpp ${LIBS}
	./teste_partida

testeCartao:
	${CC} -o teste_cartao teste_cartao.cpp ${LIBS}
	./teste_cartao
