#include "../usuario.cpp"
#include <gtest/gtest.h>

// compile: g++ -Wall -g -pthread -o teste_usuario teste_usuario.cpp -lgtest_main -lgtest -lpthread

int main(int argc, char **argv)
{

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(CadastroUsuario, CasosTesteCPF)
{
    Usuario usuario("025.335.231-27", "Teste12");
    ASSERT_EQ("025.335.231-27", usuario.getCpf());

    Usuario usuario1("025.335.231-27", "Teste12");
    ASSERT_EQ("025.335.231-27", usuario1.getCpf());
}

TEST(CadastroUsuario, CasosTesteSenha)
{
    Usuario usuario("025.335.231-27", "Teste12");
    ASSERT_EQ(true, usuario.comparaSenha("Teste12"));

    Usuario usuario1("025.335.231-27", "DADAssdavasda2525");
    ASSERT_EQ(true, usuario1.comparaSenha("DADAssdavasda2525"));
}

TEST(Exception, ExcecaoCPF)
{

    EXPECT_THROW(
        {
            try
            {
                Usuario usuario("026546546465", "Teste12"); // CPF inválido
            }
            catch (invalid_argument e)
            {
                EXPECT_STREQ("CPF inválido: verifique a existência de Letras ou símbolos fora de posição.", e.what());
                throw;
            }
        },
        invalid_argument);
    EXPECT_THROW(
        {
            try
            {
                Usuario usuario("0265afs6546465", "Teste12"); // CPF inválido
            }
            catch (invalid_argument e)
            {
                EXPECT_STREQ("CPF inválido: verifique a existência de Letras ou símbolos fora de posição.", e.what());
                throw;
            }
        },
        invalid_argument);
    EXPECT_THROW(
        {
            try
            {
                Usuario usuario("0265;-6465", "Teste12"); // CPF inválido
            }
            catch (invalid_argument e)
            {
                EXPECT_STREQ("CPF inválido: verifique a existência de Letras ou símbolos fora de posição.", e.what());
                throw;
            }
        },
        invalid_argument);
}

TEST(Exception, ExcecaoSenha)
{

    EXPECT_THROW(
        {
            try
            {
                Usuario usuario("025.335.231-27", "TESTE12"); // CPF inválido
            }
            catch (invalid_argument e)
            {
                EXPECT_STREQ("Senha nao bate os requisitos: Certifique-se que contem uma letra maiuscula, uma minuscula e um numero.", e.what());
                throw;
            }
        },
        invalid_argument);
    EXPECT_THROW(
        {
            try
            {
                Usuario usuario("025.335.231-27", "teste12"); // CPF inválido
            }
            catch (invalid_argument e)
            {
                EXPECT_STREQ("Senha nao bate os requisitos: Certifique-se que contem uma letra maiuscula, uma minuscula e um numero.", e.what());
                throw;
            }
        },
        invalid_argument);
    EXPECT_THROW(
        {
            try
            {
                Usuario usuario("025.335.231-27", "Teste"); // CPF inválido
            }
            catch (invalid_argument e)
            {
                EXPECT_STREQ("Senha nao bate os requisitos: Certifique-se que contem uma letra maiuscula, uma minuscula e um numero.", e.what());
                throw;
            }
        },
        invalid_argument);
}
