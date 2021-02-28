/*
        TCP_Server. This Program will will create the Server side for TCP_Socket Programming.
        It will receive the data from the client and then send the same data back to client.
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h>  //inet_addr
#include <pthread.h>    //thread

#define MAX_CLIENTS 3

int client_count = 0;

void *my_thread(void *arg)
{
    // printf("%s", "A Client Connected\n");
    client_count++;

    char server_message[2000], client_message[2000]; // Sending values from the server and receive from the server we need this
    int keep_running = 1;

    //Cleaning the Buffers

    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message)); // Set all bits of the padding field//

    int *client_sock_ptr = (int *)arg;
    int client_sock = *client_sock_ptr;

    if (client_sock < 0)
    {
        printf("Accept Failed. Error!!!!!!\n");
        return;
    }

    //printf("Client Connected with IP: %s and Port No: %i\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    //inet_ntoa() function converts the Internet host address in, given in network byte order, to a string in IPv4 dotted-decimal notation

    //Receive the message from the client
    while (keep_running)
    {
        if (recv(client_sock, client_message, sizeof(client_message), 0) < 0)
        {
            printf("Receive Failed. Error!!!!!\n");
            return;
        }

        printf("Client[%d] Message: %s\n", client_count, client_message);

        //Send the message back to client

        if (strcmp(client_message, "DISCONNECT") == 0)
        {
            strcpy(server_message, "Disconnecting......");
            keep_running = 0;
        }
        else
            strcpy(server_message, client_message);

        if (send(client_sock, server_message, strlen(client_message), 0) < 0)
        {
            printf("Send Failed. Error!!!!!\n");
            return;
        }

        memset(server_message, '\0', sizeof(server_message));
        memset(client_message, '\0', sizeof(client_message));
    }

    //Closing the Socket

    close(client_sock);
    client_count--;
    // printf("%s", "A Client Disconnected\n");

    //exiting thread
    pthread_exit(NULL);
}

int main(void)
{
    int socket_desc, client_sock, client_size;
    struct sockaddr_in server_addr, client_addr; //SERVER ADDR will have all the server address
    pthread_t threads[MAX_CLIENTS];
    //Creating Socket

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_desc < 0)
    {
        printf("Could Not Create Socket. Error!!!!!\n");
        return -1;
    }

    printf("Socket Created\n");

    //Binding IP and Port to socket

    server_addr.sin_family = AF_INET;                     /* Address family = Internet */
    server_addr.sin_port = htons(2000);                   // Set port number, using htons function to use proper byte order */
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); /* Set IP address to localhost */

    // BINDING FUNCTION

    if (bind(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) // Bind the address struct to the socket.  /
                                                                                     //bind() passes file descriptor, the address structure,and the length of the address structure
    {
        printf("Bind Failed. Error!!!!!\n");
        return -1;
    }

    printf("Bind Done\n");

    //Put the socket into Listening State
    while (1)
    {
        if (listen(socket_desc, 1) < 0) //This listen() call tells the socket to listen to the incoming connections.
                                        // The listen() function places all incoming connection into a "backlog queue" until accept() call accepts the connection.
        {
            printf("Listening Failed. Error!!!!!\n");
            return -1;
        }

        printf("Listening for Incoming Connections.....\n");

        //Accept the incoming Connections

        client_size = sizeof(client_addr);

        client_sock = accept(socket_desc, (struct sockaddr *)&client_addr, &client_size); // heree particular client k liye new socket create kr rhaa ha

        if (client_count < MAX_CLIENTS)
            pthread_create(&threads[client_count], NULL, my_thread, (void *)&client_sock);
    }
    //closing socket
    close(socket_desc);

    //waitng for threads to close
    //Note: the program will not reach here most of the times
    for (int i = 0; i < MAX_CLIENTS; i++)
        pthread_join(threads[i], NULL); //Suspends main thread until termination of threads

    return 0;
}
