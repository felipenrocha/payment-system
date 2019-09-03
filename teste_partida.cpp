#include "partida.cpp"
#include <gtest/gtest.h>

TEST(CadastoPartida, CasosPositivos)
{
    Partida partida(2, "22/11/98", "15:45", 999.99, 99);

    ASSERT_EQ(2, partida.getNumeroSala());
    ASSERT_EQ("22/11/98", partida.getData());
    ASSERT_EQ("15:45", partida.getHorario());
    ASSERT_EQ(999.99, partida.getPreco());
    ASSERT_EQ(99, partida.getDisponibilidade());

    Partida partida2(9, "22/01/00", "17:00", 0, 250);

    ASSERT_EQ(9, partida2.getNumeroSala());
    ASSERT_EQ("22/01/00", partida2.getData());
    ASSERT_EQ("17:00", partida2.getHorario());
    ASSERT_EQ(0, partida2.getPreco());
    ASSERT_EQ(250, partida2.getDisponibilidade());
}

TEST(Exception, CasosThrowExecption)
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
            Partida partida(1, "22/11/1998", "15:45", 999.99, 99);
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Formato inválido, certifique-se que a data se encontra no seguinte formato: DD/MM/AA", e.what());
            throw;
        }
    },
                 invalid_argument);
}

int main(int argc, char **argv)
{

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}