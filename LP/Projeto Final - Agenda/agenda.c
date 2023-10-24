#include <stdio.h>
#include <string.h>

#define TAM 100
#define TAM_TEL 12

typedef struct {
  char nome[TAM];
} Nome;

typedef struct {
  char tel[TAM_TEL];
  char auxTel[TAM_TEL];
} Telefone;

typedef struct {
  Nome Nome;
  Telefone Tel;
} Contatos;

Contatos agenda[TAM];

#define CONTATO_CADASTRADO "Contato cadastrado com sucesso!\n"
#define INDICE_INCORRETO "Índice digitado não existe [1,100]!\n"
#define TELEFONE_10_11                                                         \
  "Telefone não tem 10 ou 11 dígitos! Favor digite novamente.\n"
#define AGENDA_VAZIA "Agenda vazia!\n"
#define CONTATO_INEXISTENTE "Contato digitado não existe!\n"
#define CONTATO_REMOVIDO "Contato removido com sucesso!\n"
#define INDICE_VAZIO "Índice digitado está vazio!\n"
#define VALORES_0_5 "Escolha valores entre 0 e 5!\n"
#define SAIR_AGENDA "Tchau!"

void Limpar_Strings() {
  int i;

  for (i = 1; i <= TAM; i++) {
    strcpy(agenda[i].Nome.nome, " ");
    strcpy(agenda[i].Tel.tel, " ");
  }
  return;
}

void Imprimir_Contato(int i) {
  printf("Contato[%d]- Nome:%s Tel:%s\n", i, agenda[i].Nome.nome,
         agenda[i].Tel.tel);
  return;
}

int Conferir_Telefone(int i) {
  int x, k = 0;

  x = strlen(agenda[i].Tel.auxTel);
  if (x == 10 || x == 11) {
    k++;
  } else if (x < 10 || x > 11) {
  }
  return k;
}

void Sair_Agenda() {
  printf(SAIR_AGENDA);
  return;
}

void Receber_Indice(int *i) {
  scanf("%d", i);
  return;
}

int Conferir_Indice(int i) {
  int k = 0;

  if (i >= 1 || i >= TAM) {
    k++;
  } else {
  }
  return k;
}

void Listar_Contatos_FE() {
  int i;

  for (i = 1; i <= TAM; i++) {
    if (strlen(agenda[i].Tel.tel) > 1) {
      Imprimir_Contato(i);
    } else {
      continue;
    }
  }
  return;
}

void Cadastrar_Contato() {
  int i, j, k, auxK = 0;

  Receber_Indice(&i);
  k = Conferir_Indice(i);

  if (k <= 0) {
    printf(INDICE_INCORRETO);

  } else {
    scanf("%s", agenda[i].Nome.nome);
    scanf("%s", agenda[i].Tel.auxTel);

    k = Conferir_Telefone(i);

    if (k > 0) {
      strcpy(agenda[i].Tel.tel, agenda[i].Tel.auxTel);
      printf(CONTATO_CADASTRADO);

    } else if (k <= 0) {
      printf(TELEFONE_10_11);

      for (j = 0; auxK <= 0; j++) {
        scanf("%s", agenda[i].Tel.auxTel);
        auxK = Conferir_Telefone(i);

        if (auxK > 0) {
          strcpy(agenda[i].Tel.tel, agenda[i].Tel.auxTel);
          printf(CONTATO_CADASTRADO);

        } else if (auxK <= 0) {
          printf(TELEFONE_10_11);
          continue;
        }
      }
    }
  }
  return;
}

void Listar_Contatos() {
  int i, k = 0;

  for (i = 1; i <= TAM; i++) {
    if (strlen(agenda[i].Tel.tel) > 1) {
      Imprimir_Contato(i);

    } else {
      k++;
      continue;
    }
  }

  if (k == TAM) {
    printf(AGENDA_VAZIA);
  }
  return;
}

void Mostrar_Contato() {
  int i, j;
  int k = 0, c = 0;

  for (j = 1; j <= TAM; j++) {
    if (strlen(agenda[j].Nome.nome) <= 1) {
      k++;

    } else {
      if (strlen(agenda[j].Nome.nome) > 1) {
        c++;
      }
    }
  }

  if (k == TAM && c == 0) {
    printf(AGENDA_VAZIA);

  } else {
    Receber_Indice(&i);

    if (i < 1 || i > TAM) {
      printf(INDICE_INCORRETO);

    } else {
      if (strlen(agenda[i].Nome.nome) <= 1) {
        printf(INDICE_VAZIO);

      } else {
        if (strlen(agenda[i].Nome.nome) > 1) {
          Imprimir_Contato(i);
        }
      }
    }
  }
  return;
}

void Apagar_Contato_Indice() {
  int i, k;

  Receber_Indice(&i);
  k = Conferir_Indice(i);

  if (k <= 0) {
    printf(INDICE_INCORRETO);

  } else {
    if (strlen(agenda[i].Nome.nome) <= 1) {
      printf(INDICE_VAZIO);

    } else {
      strcpy(agenda[i].Nome.nome, " ");
      strcpy(agenda[i].Tel.tel, " ");
      printf(CONTATO_REMOVIDO);
      Listar_Contatos_FE();
    }
  }
  return;
}

void Apagar_Contato_Nome() {
  char string[TAM];
  int i, k = 0;

  scanf("%s", string);

  for (i = 1; i <= TAM; i++) {
    if (strcmp(string, agenda[i].Nome.nome) == 0) {
      strcpy(agenda[i].Nome.nome, " ");
      strcpy(agenda[i].Tel.tel, " ");
      printf(CONTATO_REMOVIDO);
      Listar_Contatos_FE();

    } else {
      k++;
    }
  }

  if (k == TAM) {
    printf(CONTATO_INEXISTENTE);
  }
  return;
}

void Menu() {
  int n;

  while (n != 0) {
    Receber_Indice(&n);

    if (n < 0 || n > 5) {
      printf(VALORES_0_5);

    } else {
      switch (n) {
      case 0:
        Sair_Agenda();
        break;

      case 1:
        Cadastrar_Contato();
        break;

      case 2:
        Listar_Contatos();
        break;

      case 3:
        Mostrar_Contato();
        break;

      case 4:
        Apagar_Contato_Indice();
        break;

      case 5:
        Apagar_Contato_Nome();
        break;
      }
    }
  }
  return;
}

int main() {

  Limpar_Strings();
  Menu();

  return 0;
}