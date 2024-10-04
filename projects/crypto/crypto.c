#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * *return codes:
 * * 0: successfully finished task
 * *-1: error reading input
 * *-2: memory allocation failure
 * *-3: encryption failure
 */


//Initial message
void InitialMessage() {
  printf("_________ .__       .__                                           __               __            __________              ____.__        \n");
  printf("\\_   ___ \\|__|_____ |  |__   ___________  _____________  ____    |__| ____   _____/  |_          \\______   \\___.__.     |    |__| ____  \n");
  printf("/    \\  \\/|  \\____ \\|  |  \\_/ __ \\_  __ \\ \\____ \\_  __ \\/  _ \\   |  |/ __ \\_/ ___\\   __\\          |    |  _<   |  |     |    |  |/    \\ \n");
  printf("\\     \\___|  |  |_> >   Y  \\  ___/|  | \\/ |  |_> >  | \\(  <_> )  |  \\  ___/\\  \\___|  |            |    |   \\\\___  | /\\__|    |  |   |  \\\n");
  printf(" \\______  /__|   __/|___|  /\\___  >__|    |   __/|__|   \\____/\\__|  |\\___  >\\___  >__|    ______  |______  // ____| \\________|__|___|  /\n");
  printf("        \\/   |__|        \\/     \\/        |__|               \\______|    \\/     \\/       /_____/         \\/ \\/                       \\/ \n");
  printf("\n\n");
}

/* Frees allocated memory for variables.
 * Needs to be added each time a new memory is allocated by malloc.*/
void free_Malloc_variables(char * a, char *b) {
  free(a);
  free(b);
}

//*인풋값 유효여부 확인(아직 안쓰임). 문제있으면 -1 돌려줌.
int validateInput(int min, int max) {
  char input[sizeof(int)];
  int value;

  printf("Please type your selection (%d - %d)\n", min, max);
  if(fgets(input, sizeof(input), stdin) != NULL) {
    input[strcspn(input, "\n")] = 0;

    char *endptr;
    value = strtol(input, &endptr, 10);

    if(*endptr != '\0' || endptr == input || value < min || value > max) {
      printf("Error!!! Invalid input.\nPlease enter a number between %d and %d!\nExiting ...\n", min, max);
      return -1;
    }
    return value;
  }else {
    printf("Error reading input.\nExiting ...\n");
    return -1;
  }
}


//*인풋버퍼 초기화
void clrInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * Encryption function. 암호화 기능 함수.
 * @param method Parameter for this function will determine the encryption method.
 */
int encrypting(int method, char* toEncrypt, char* result) {
  switch (method) {
    case 1:
    /*TODO:start implementing encryption function here.
    Must return an exit code. 
    use bitwise operator.
    maybe use salt n pepper if needed.*/
  }
}

/**
 * Decryption function. 복호화 기능 함수.
 * @param method Parameter for this function will determine the decryption method.
 */
int decrypting(int method, char* toEncrypt, char* result) {
  switch (method) {
    case 1:
    //여따해
  }
}

//*main. 메인
int main(void) {
  int decrypt_or_encrypt = 0;
  int decrypt_method = 0;
  int encrypt_method = 0;
  char * object_string = (char *)malloc(sizeof(char) * 512);
  char * result_data = (char *)malloc(sizeof(char) * 512);
  if (object_string == NULL || result_data == NULL) {
    printf("Memory allocation failed!\nExiting...\n");
    
    free_Malloc_variables(object_string, result_data);
    return -2;
  }
  //print out initial message
  InitialMessage();


  printf("This is a basic decrypt/encrypt program.\n");
  printf("What has been encrypted using this program is only decrypt-able with this one. (Ideally...)\n");
  printf("This program only works with English Alphabets on current version!");
  printf("Please enter what you want to encrypt: \n");
  if (fgets(object_string, sizeof(object_string), stdin)!= NULL) {
    object_string[strcspn(object_string, "\n")] = '\0';
  } else {
    printf("Error reading input.\nExiting...\n");
    free_Malloc_variables(object_string, result_data);
    return -1;
  }

  printf("Please Select what You want to do: \n");
  printf("[1]Encrypt\n[2]Decrypt\n");
  
  decrypt_or_encrypt = validateInput(1, 2);
  if(decrypt_or_encrypt != -1) {
    clrInputBuffer();

    switch (decrypt_or_encrypt) {
      case 1: //암호화
        printf("Select encrypting method(#1 will be based on my own algorithm.): \n");
        //암호화 방법 몇가지(base64 url 등등) 사용해보기.
        printf("[1]CIPHER\n[2]asdf\n[3]asdf\n[4]asdf\n[5]asdf\n");
        encrypt_method = validateInput(1, 5); //함수 입력값은 선택지에 따라 바뀜
        if(encrypt_method != -1) {
          encrypting(encrypt_method, object_string, result_data);
          //계속해
        }
      break;

      case 2: //복호화
        printf("Select decrypting method(use #1 if you used this program to encrypt.): \n");
        //복호화 방법 몇가지 사용해보기.
        printf("[1]DCIPHER\n[2]asdf\n[3]asdf\n[4]asdf\n[5]asdf\n");
        decrypt_method = validateInput(1, 5); //함수 입력값은 선택지에 따라 바뀜
        if(decrypt_method != -1) {
          decrypting(decrypt_method, object_string, result_data);
          //계속해
        }
      break;
    }
  } else {
    printf("Invalid input. Exiting...\n");
    free_Malloc_variables(object_string, result_data);
    return -1;
  }

  printf("Here is the Result!\n");
  printf("[%f]\n");
  free_Malloc_variables(object_string, result_data);
  return 0;
}