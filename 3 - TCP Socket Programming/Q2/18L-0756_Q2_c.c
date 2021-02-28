/*
        TCP_Client. This Program will implement the Client Side for TCP_Socket Programming.
        It will get some data from user and will send to the server and as a reply from the
        server, it will get its data back.
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h>  //inet_addr

typedef enum
{
        false,
        true
} bool;

bool findVowel(char *word)
{
        int size = strlen(word);
        bool flag = false;
        int i;
        for (i = 0; i < size && !flag; i++)
        {
                if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' ||
                    word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U')
                        flag = true;
        }
        return flag;
}

void reverseStr(char *str)
{
        char newStr[2000];
        memset(newStr, '\0', sizeof(newStr));
        char *token = strtok(str, " ");
        while (token != NULL)
        {
                if (!findVowel(token))
                {
                        int size = strlen(token);
                        int n = size;
                        char temp;
                        int i;
                        for (i = 0; i < size / 2; i++, n--)
                        {
                                temp = token[i];
                                token[i] = token[n - 1];
                                token[n - 1] = temp;
                        }
                }
                strcat(newStr, token);
                token = strtok(NULL, " ");
                if (token != NULL)
                {
                        int tempSize = strlen(newStr);
                        newStr[tempSize] = ' ';
                        newStr[tempSize + 1] = '\0';
                }
                else
                        strcpy(str, newStr);
        }
}

int main(void)
{
        int socket_desc;
        struct sockaddr_in server_addr;
        char server_message[2000], client_message[2000];

        //Cleaning the Buffers

        memset(server_message, '\0', sizeof(server_message));
        memset(client_message, '\0', sizeof(client_message));

        //Creating Socket

        socket_desc = socket(AF_INET, SOCK_STREAM, 0);

        if (socket_desc < 0)
        {
                printf("Could Not Create Socket. Error!!!!!\n");
                return -1;
        }

        printf("Socket Created\n");

        //Specifying the IP and Port of the server to connect

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(2000);
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

        //Now connecting to the server accept() using connect() from client side

        if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        {
                printf("Connection Failed. Error!!!!!");
                return -1;
        }

        printf("Connected\n");

        //Get Input from the User
        printf("Enter Message: ");
        gets(client_message); //One is that gets() will only get character string data.
                              //		will get only one variable at a time.
                              //  reads characters from stdin and loads them into str
        //Send the message to Server

        if (send(socket_desc, client_message, strlen(client_message), 0) < 0)
        {
                printf("Send Failed. Error!!!!\n");
                return -1;
        }

        //Receive the message back from the server

        if (recv(socket_desc, server_message, sizeof(server_message), 0) < 0)
        {
                printf("Receive Failed. Error!!!!!\n");
                return -1;
        }
        reverseStr(server_message);
        printf("Server Message: %s\n", server_message);

        memset(server_message, '\0', sizeof(server_message));
        memset(client_message, '\0', sizeof(client_message));

        //Closing the Socket

        close(socket_desc);

        return 0;
}
