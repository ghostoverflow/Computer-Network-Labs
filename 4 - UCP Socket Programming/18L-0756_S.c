#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //// Needed for socket creating and binding
#include <arpa/inet.h>  //inet_addr

int verify(char *arr)
{
    //YY-AAAA-CI
    if (strlen(arr) > 10)
        return 0;

    if (arr[2] != '-' || arr[7] != '-' || arr[8] != 'C')
        return 0;

    if (arr[9] != 'I' && arr[9] != 'O')
    {
        return 0;
    }
    return 1;
}

int searchStudent(char *arr, char db[][8])
{
    int i, flag = -1;
    for (i = 0; i < 30 && flag == -1; ++i)
    {

        if (strcmp(arr, db[i]) == 0)
        {
            flag = i;
        }
    }
    return flag;
}

void reorder(char db[][8], int index)
{
    int i;
    int j = index;
    for (i = index - 1; i >= 0; i--, j--)
    {
        strcpy(db[j], db[i]);
    }
    memset(db[0], '\0', sizeof(db[0]));
}

int main(void)
{
    int socket_desc;
    struct sockaddr_in server_addr, client_addr;
    char server_message[2000], client_message[2000];
    int client_struct_length = sizeof(client_addr);
    int count = 0, end = 0;
    char database[30][8];
    int i;
    for (i = 0; i < 30; i++)
        memset(database[i], '\0', sizeof(database[0]));

    //Cleaning the Buffers

    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));

    //Creating UDP Socket

    socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (socket_desc < 0)
    {
        printf("Could Not Create Socket. Error!!!!!\n");
        return -1;
    }

    printf("Socket Created\n");

    //Binding IP and Port to socket

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2000);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // bind your socket to localhost only, if you want connect any particular ip you should mention it in INET_ADDR.

    if (bind(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Bind Failed. Error!!!!!\n");
        return -1;
    }

    printf("Bind Done\n");
    while (1)
    {
        printf("Listening for Messages...\n\n");

        //Receive the message from the client

        if (recvfrom(socket_desc, client_message, sizeof(client_message), 0, (struct sockaddr *)&client_addr, &client_struct_length) < 0)
        {
            printf("Receive Failed. Error!!!!!\n");
            return -1;
        }

        if (verify(client_message))
        {
            char mode = client_message[9];
            client_message[7] = '\0';
            if (mode == 'I')
            {
                if (searchStudent(client_message, database) == -1)
                {
                    if (count < 30)
                    {
                        char message[100];
                        strcpy(message, "Welcome Student ");
                        strcat(message, client_message);
                        strcpy(server_message, message);

                        strcpy(database[end % 30], client_message);
                        end++;
                        count++;
                        for (i = 0; i < 30; ++i)
                            if (database[i][0] != '\0')
                                printf("%s\n", database[i]);
                    }
                    else
                    {
                        strcpy(server_message, "Server Space is full!");
                    }
                }
                else
                {
                    strcpy(server_message, "You are already here.");
                }
            }
            else
            {
                int index = searchStudent(client_message, database);
                if (index != -1)
                {
                    char message[100];
                    strcpy(message, "Goodbye Student ");
                    strcat(message, client_message);
                    strcat(message, "! Have a nice day.");
                    strcpy(server_message, message);
                    reorder(database, index);
                    int i;
                    for (i = 0; i < 30; ++i)
                    {
                        if (database[i][0] != '\0')
                            printf("%s\n", database[i]);
                    }
                    count--;
                }
                else
                {
                    strcpy(server_message, "You didn't check in today. Contact System Administrator.");
                }
            }
        }
        else
        {
            strcpy(server_message, "Invalid Input!");
        }

        if (sendto(socket_desc, server_message, strlen(server_message), 0, (struct sockaddr *)&client_addr, client_struct_length) < 0)
        {
            printf("Send Failed. Error!!!!!\n");
            return -1;
        }

        memset(server_message, '\0', sizeof(server_message));
        memset(client_message, '\0', sizeof(client_message));
    }
    //Closing the Socket

    close(socket_desc);
    return 0;
}
