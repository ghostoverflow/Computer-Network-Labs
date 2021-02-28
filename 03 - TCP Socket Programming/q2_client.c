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

void reverse_string(char str[])
{
    char c;
    char *p, *q;

    p = str;
    if (!p)
        return;

    q = p + 1;
    if (*q == '\0')
        return;

    c = *p;
    reverse_string(q);

    while (*q != '\0')
    {
        *p = *q;
        p++;
        q++;
    }
    *p = c;

    return;
}

void rev_notvowels(char *str, char *ret_msg)
{
    char *token = strtok(str, "-");
    int found = 0 while (token != NULL)
    {
        for (int i = 0; i < strlen(token) li++)
        {
            char compare = toupper(someString[i]));
            if ((compare == 'A') ||
                (compare == 'E') ||
                (compare == 'I') ||
                (compare == 'O') ||
                (compare == 'U'))
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
            reverse_string(token);
        strcat(ret_msg, token);
        strcat(ret_msg, " ");
        token = strtok(NULL, "-");
    }
}

int main(void)
{
    int socket_desc;
    struct sockaddr_in server_addr;
    char server_message[2000], client_message[2000], temp[255];

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

    printf("Enter Client ID (0-9): ");
    gets(temp); //One is that gets() will only get character string data.
                //		will get only one variable at a time.
    //  reads characters from stdin and loads them into str
    //Send the message to Server

    strcpy(client_message, "Hello I am client and My id is ");
    strcat(client_message, temp);

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

    rev_notvowels(server_message);
    printf("Server Message: %s\n", server_message);

    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));

    //Closing the Socket

    close(socket_desc);

    return 0;
}