#include <stdio.h>
#include <string.h>
#include <locale.h>

struct verificacao{ //tentativa do user em fazer login
    char verificacaoUser[30];
    char verificacaoPass[40];
};
struct cadastro{ //login cadastrado do user
    char user[30];
    char pass[40];
};
struct boletim{ //estrutura do boletim
    char nome[30];
    int disciplina;
    float notas[3];
    float media;
};

int main(){
    setlocale(LC_ALL, " ");
    struct cadastro c;
    struct boletim b;
    struct verificacao v;
    
    int verificacaoCadastro = 0; //verificação inicia falsa

    int fim = 1; //variavel de parada do algoritmo
    int i; //contagem de for para as notas
    int fazerCadastro = 0;
    int tentativas;

    while(fim == 1){
        int cadastramento = 1;
        printf("Fazer login ou cadastro\n");
        printf("1 - Login    2 - Cadastro\n");
        scanf("%d", &verificacaoCadastro);
        while(cadastramento == 1){
            if(verificacaoCadastro == 2){
                printf("\nDigite o nome de usuario para cadastro: ");
                scanf("%s", c.user);
                printf("Digite a senha: ");
                scanf("%s", c.pass);
                printf("\n---- Usuario cadastrado ----\n");
                verificacaoCadastro = 1;
            }
            else{ //verificação do cadastro
                int login_ver = 0; //verificação do login
                if(login_ver != 1){
                    for(tentativas = 1; tentativas <= 3; tentativas++){
                        printf("\nUsuario: ");
                        scanf("%s", v.verificacaoUser);
                        printf("Senha: ");
                        scanf("%s", v.verificacaoPass);
                        if((strcmp(v.verificacaoUser, c.user) == 0) && (strcmp(v.verificacaoPass, c.pass) == 0)){ //usuario fez login
                            printf("\n---- Login autorizado ----\n");
                            login_ver = 1;
                            cadastramento = 0;
                            tentativas = 4;
                        }else{ //usuario errou ou não tem cadastro
                            printf("\nUsuario ou Senha incorreto(s), tente novamente\n");
                            login_ver = 0;
                        }
                    }
                    if(login_ver == 0){
                        printf("\nDeseja fazer cadastro?\n");
                        printf("1 - Sim    2 - Não\n");
                        scanf("%d", &fazerCadastro);
                        if(fazerCadastro == 1){ //redirecionando para realização do cadastro
                            verificacaoCadastro = 2;
                            login_ver = 1;
                        }else{
                            printf("\n---- SAINDO DO SISTEMA ----");
                            return 0; //fim do algoritmo
                        }
                    }    
                }
            }
        }
        printf("\nDigite seu nome\n");
        scanf("%s[^\n]", b.nome);
        printf("\nDigite a disciplina\n");
        printf("0 - Logica Matematica\n1 - Logica de Programacao\n2 - ICC\n3 - Ingles\n4 - Calculo\n");
        scanf("%d", &b.disciplina);
        printf("\nDigite as notas das 3 APs\n");
        for(i = 0; i <= 2; i++){
            scanf("%f", &b.notas[i]);
            if((b.notas[i] < 0) || (b.notas[i] > 10)){
                printf("Nota inválida\n");
                break;
            }
        }

        b.media = (b.notas[0] + b.notas[1] + b.notas[2]) / 3; //calculo da media das notas
        switch(b.disciplina){
            case 0:
                printf("\nDisciplina: Logica Matematica\n");
            break;
            case 1:
                printf("\nDisciplina: Logica de Programacao\n");
            break;
            case 2:
                printf("\nDisciplina: ICC\n");
            break;
            case 3:
                printf("\nDisciplina: Ingles\n");
            break;
            case 4:
                printf("\nDisciplina: Calculo\n");
            break;
        }
        printf("\nA media do aluno %s: %.1f\n", b.nome, b.media);
        if(b.media >= 7.0){
            printf("Aprovado\n");
        }else{
            if(b.media >= 4.0){
                printf("Exame\n");
            }else{
                printf("Reprovado\n");
            }
        }
        printf("\nDeseja realizar novamente?\n1 - Sim   2 - Nao\n"); //checagem de parada do algoritmo
        scanf("%d", &fim);
        if(fim != 1){
            printf("\n---- SAINDO DO SISTEMA ----");
        }
    }

    return 0;
}