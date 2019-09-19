#include "../partida.cpp"
#include <gtest/gtest.h>

// compile: g++ -Wall -g -pthread -o teste_partida teste_partida.cpp -lgtest_main -lgtest -lpthread

int main(int argc, char **argv)
{

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(CadastroPartida, CasosTesteNumeroSalaPositivas)
{
    Partida partida(1, "22/11/98", "15:45", 999.99, 99);
    ASSERT_EQ(1, partida.getNumeroSala());

    Partida partida2(9, "22/01/00", "17:00", 0, 250);
    ASSERT_EQ(9, partida2.getNumeroSala());

    Partida partida3(10, "22/01/00", "17:00", 0, 250);
    ASSERT_EQ(10, partida3.getNumeroSala());
}

TEST(CadastroPartida, CasosTesteDatasPositivas)
{
    Partida partida1(1, "22/11/98", "15:45", 999.99, 99);
    ASSERT_EQ("22/11/98", partida1.getData());

    Partida partida2(1, "22/01/01", "15:45", 999.99, 99);
    ASSERT_EQ("22/01/01", partida2.getData());
}

TEST(CadastroPartida, CasosTesteHorasPositivas)
{
    Partida partida1(1, "22/01/01", "15:00", 999.99, 99);
    ASSERT_EQ("15:00", partida1.getHorario());

    Partida partida2(1, "22/11/98", "15:15", 999.99, 99);
    ASSERT_EQ("15:15", partida2.getHorario());

    Partida partida3(1, "22/11/98", "15:30", 999.99, 99);
    ASSERT_EQ("15:30", partida3.getHorario());

    Partida partida4(1, "22/11/98", "15:45", 999.99, 99);
    ASSERT_EQ("15:45", partida4.getHorario());
}

TEST(CadastroPartida, CasosoTestePrecoPositovos)
{
    Partida partida(1, "22/11/98", "15:45", 999.99, 99);
    ASSERT_EQ(999.99, partida.getPreco());

    Partida partida2(9, "22/01/00", "17:00", 0, 250);
    ASSERT_EQ(0, partida2.getPreco());

    Partida partida3(9, "22/01/00", "17:00", 494, 250);
    ASSERT_EQ(494, partida3.getPreco());
}

TEST(CadastroPartida, CasosoTesteDisponibilidadePositovos)
{
    Partida partida(1, "22/11/98", "15:45", 999.99, 1);
    ASSERT_EQ(1, partida.getDisponibilidade());

    Partida partida2(9, "22/01/00", "17:00", 0, 250);
    ASSERT_EQ(250, partida2.getDisponibilidade());

    Partida partida3(9, "22/01/00", "17:00", 494, 100);
    ASSERT_EQ(100, partida3.getDisponibilidade());
}

TEST(Exception, CasosThrowExecptionNumeroSala)
{
    EXPECT_THROW({
        try
        {
            Partida partida(-1, "22/11/98", "15:45", 999.99, 99);
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Número de sala inválido, certifique-se que seja um número entre 1 a 10", e.what());
            throw;
        }
    },
                 invalid_argument);
    EXPECT_THROW({
        try
        {
            Partida partida(0, "22/11/98", "15:45", 999.99, 99);
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Número de sala inválido, certifique-se que seja um número entre 1 a 10", e.what());
            throw;
        }
    },
                 invalid_argument);
    EXPECT_THROW({
        try
        {
            Partida partida(11, "22/11/98", "15:45", 999.99, 99);
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Número de sala inválido, certifique-se que seja um número entre 1 a 10", e.what());
            throw;
        }
    },
                 invalid_argument);
    EXPECT_THROW({
        try
        {
            Partida partida(-100000, "22/11/98", "07:45", 999.99, 99);
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Número de sala inválido, certifique-se que seja um número entre 1 a 10", e.what());
            throw;
        }
    },
                 invalid_argument);
}

TEST(Exception, CasosThrowExecptionData)
{
    EXPECT_THROW({
        try
        {
            Partida partida(1, "22/11/1998", "15:45", 999.99, 99);
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Formato inválido, certifique-se que a data se encontra no seguinte formato: DD/MM/AA", e.what());
            throw;
        }
    },
                 invalid_argument);

    EXPECT_THROW({
        try
        {
            Partida partida(1, "22/13/98", "15:45", 999.99, 99);
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Formato inválido, certifique-se que a data se encontra no seguinte formato: DD/MM/AA", e.what());
            throw;
        }
    },
                 invalid_argument);
    EXPECT_THROW({
        try
        {
            Partida partida(1, "32/08/98", "15:45", 999.99, 99);
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Formato inválido, certifique-se que a data se encontra no seguinte formato: DD/MM/AA", e.what());
            throw;
        }
    },
                 invalid_argument);
    EXPECT_THROW({
        try
        {
            Partida partida(1, "22/11", "15:45", 999.99, 99);
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Formato inválido, certifique-se que a data se encontra no seguinte formato: DD/MM/AA", e.what());
            throw;
        }
    },
                 invalid_argument);
}

TEST(Exception, CasosThrowExecptionHorario)
{
    EXPECT_THROW({
        try
        {
            Partida partida(1, "22/11/98", "17:41", 999.99, 99);
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Horario invalido, certifique-se de que o horário se encontre entre 7:00 e 22:45 e os minutos sejam 00,15,30,45", e.what());
            throw;
        }
    },
                 invalid_argument);
    EXPECT_THROW({
        try
        {
            Partida partida(1, "22/11/98", "23:45", 999.99, 99);
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Horario invalido, certifique-se de que o horário se encontre entre 7:00 e 22:45 e os minutos sejam 00,15,30,45", e.what());
            throw;
        }
    },
                 invalid_argument);
    EXPECT_THROW({
        try
        {
            Partida partida(1, "22/11/98", "06:45", 999.99, 99);
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Horario invalido, certifique-se de que o horário se encontre entre 7:00 e 22:45 e os minutos sejam 00,15,30,45", e.what());
            throw;
        }
    },
                 invalid_argument);
}

TEST(Exception, CasosThrowExecptionPreco)
{

    EXPECT_THROW({
        try
        {
            Partida partida(1, "22/11/98", "17:45", -1, 99);
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Preço inválido, certifique-se que esteja entre 0 e 1000.", e.what());
            throw;
        }
    },
                 invalid_argument);
    EXPECT_THROW({
        try
        {
            Partida partida(1, "22/11/98", "17:45", 1000.01, 99);
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Preço inválido, certifique-se que esteja entre 0 e 1000.", e.what());
            throw;
        }
    },
                 invalid_argument);
}

TEST(Exception, CasosThrowExecptionDisponibilidade)
{
    EXPECT_THROW({
        try
        {
            Partida partida(1, "22/11/98", "17:45", 900, 251);
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Disponibilidade inválida, certifique-se de que seja um numero entre 1 e 250.", e.what());
            throw;
        }
    },
                 invalid_argument);
    EXPECT_THROW({
        try
        {
            Partida partida(1, "22/11/98", "17:45", 900, 0);
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Disponibilidade inválida, certifique-se de que seja um numero entre 1 e 250.", e.what());
            throw;
        }
    },
                 invalid_argument);
    EXPECT_THROW({
        try
        {
            Partida partida(1, "22/11/98", "17:45", 900, -5);
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Disponibilidade inválida, certifique-se de que seja um numero entre 1 e 250.", e.what());
            throw;
        }
    },
                 invalid_argument);
}
