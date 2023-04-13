#include <stdio.h>
#include <string.h>
#include <locale.h>

struct verificacao{ //tentativa do user em fazer login
    char user_ver[30];
    char pass_ver[40];
};
struct cadastro{ //login cadastrado do user
    char user[30];
    char pass[40];
};
struct boletim{ //estrutura do boletim
    char nome[30];
    char disciplina[20];
    float notas[3];
    float media;
};

int main(){
    setlocale(LC_ALL, " ");
    struct cadastro c;
    struct boletim b;
    struct verificacao v;
    
    int cad_ver = 0; //verificação inicia falsa

    int login_ver; //verificação do login
    int fim = 1; //variavel de parada do algoritmo
    int i; //contagem de for para as notas

    while(fim == 1){
        printf("Fazer login ou cadastro\n");
        printf("1 - Login // 2 - Cadastro\n");
        scanf("%d", &cad_ver);
        while(cad_ver == 2){
            printf("Digite o nome de usuario para cadastro\n");
            scanf("%s", c.user);
            printf("Digite a senha\n");
            scanf("%s", c.pass);
            printf("\nUsuario cadastrado\n");
            cad_ver = 1;
        }
        if(cad_ver == 1){ //usuario tem cadastro
            do{
                printf("Usuario:");
                scanf("%s", v.user_ver);
                printf("Senha:");
                scanf("%s", v.pass_ver);
                if((strcmp(v.user_ver, c.user) == 0) && (strcmp(v.pass_ver, c.pass) == 0)){
                    printf("\nLogin autorizado\n");
                    login_ver = 1;
                }else{
                    printf("\nUsuario ou Senha incorreto(s)\n");
                    login_ver = 0;
                }
            }while(login_ver != 1);
        }
            
        printf("Digite seu nome\n");
        scanf("%s", b.nome);
        printf("\nDigite a disciplina\n");
        scanf("%s", b.disciplina);
        printf("\nDigite as notas do aluno\n");
        for(i = 0; i <= 2; i++){
            scanf("%f", &b.notas[i]);
            if((b.notas[i] < 0) || (b.notas[i] > 10)){
                printf("Nota inválida\n");
            }
        }

        b.media = (b.notas[0] + b.notas[1] + b.notas[2]) / 3; //calculo da media das notas
        printf("\nA media do aluno: %.1f\n", b.media);
        if(b.media >= 7.0){
            printf("Aprovado\n");
        }else{
            if(b.media >= 4.0){
                printf("Exame\n");
            }else{
                printf("Reprovado\n");
            }
        }
        printf(" Deseja realizar novamente?\n1 - Sim   2 - Não "); //checagem de parada do algoritmo
        scanf("%d", &fim);
        if(fim != 1){
            printf(" -- SAINDO DO SISTEMA -- ");
        }
    }

    return 0;
}