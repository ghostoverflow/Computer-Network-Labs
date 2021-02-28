#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //socket
#include <arpa/inet.h>  //inet_addr
#include <pthread.h>

void *my_thread(void *message)
{
    int client_sock = (int)message;
    char server_message[2000], client_message[2000];

    //Cleaning the Buffers
    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));

    //Receive Name/CNIC from the client
    if (recv(client_sock, client_message, sizeof(client_message), 0) < 0)
    {
        printf("Receive Failed. Error!!!!!\n");
    }

    char name_cnic[255];
    strcpy(name_cnic, client_message);

    char *newline;
    newline = strchr(name_cnic, '\n');
    if (newline != NULL)
        *newline = '\0';

    FILE *fp;
    char buff[255];
    fp = fopen("./Voters_List.txt", "r");
    int voter_found = 0;

    while (fgets(buff, sizeof(buff), fp) != NULL)
    {
        //remove newline and carriage return characters
        char *newline, *carriage_return;
        newline = strchr(buff, '\n');
        if (newline != NULL)
            *newline = '\0';

        carriage_return = strchr(buff, '\r');
        if (carriage_return != NULL)
            *carriage_return = '\0';

        if (strcmp(name_cnic, buff) == 0)
        {
            voter_found = 1;
            break;
        }
    }

    fclose(fp);

    if (voter_found == 1)
    {
        //Cleaning the Buffers
        memset(server_message, '\0', sizeof(server_message));
        memset(client_message, '\0', sizeof(client_message));

        strcpy(server_message, "Welcome Voter.");

        if (send(client_sock, server_message, strlen(server_message), 0) < 0)
        {
            printf("Send Failed. Error!!!!!\n");
        }

        fp = fopen("./Votes.txt", "a");
        fclose(fp);

        fp = fopen("./Votes.txt", "r");

        int vote_casted = 0;
        if (fp != NULL)
        {
            while (fgets(buff, 200, fp) != NULL)
            {
                //parse string
                char *temp_comma;
                temp_comma = strchr(buff, ',');
                if (temp_comma != NULL)
                    *temp_comma = '\0';

                if (strcmp(name_cnic, buff) == 0)
                {
                    vote_casted = 1;
                    break;
                }
            }
        }

        fclose(fp);

        if (vote_casted == 0)
        {
            //display candidates list
            fp = fopen("./Candidates_List.txt", "r");

            char candidates[1000];

            strcpy(candidates, "Canidates: \n");

            while (fgets(buff, sizeof(buff), fp) != NULL)
            {
                strcat(candidates, buff);
            }

            fclose(fp);

            //send candidates data back to client

            //Cleaning the Buffers
            memset(server_message, '\0', sizeof(server_message));
            memset(client_message, '\0', sizeof(client_message));

            strcpy(server_message, candidates);

            if (send(client_sock, server_message, strlen(server_message), 0) < 0)
            {
                printf("Send Failed. Error!!!!!\n");
            }

            //Cleaning the Buffers
            memset(server_message, '\0', sizeof(server_message));
            memset(client_message, '\0', sizeof(client_message));

            //Receive candidate's symbol from client
            if (recv(client_sock, client_message, sizeof(client_message), 0) < 0)
            {
                printf("Receive Failed. Error!!!!!\n");
            }

            //write this vote in Votes.txt
            char symbol[100];
            strcpy(symbol, client_message);

            char vote[200];
            strcpy(vote, name_cnic);
            strcat(vote, ",");
            strcat(vote, symbol);
            strcat(vote, "\n");

            fp = fopen("./Votes.txt", "a");
            fputs(vote, fp);
            fclose(fp);

            //send a vote casted message back to client

            //Cleaning the Buffers
            memset(server_message, '\0', sizeof(server_message));
            memset(client_message, '\0', sizeof(client_message));

            strcpy(server_message, "You have succesfully casted your vote.\n");

            if (send(client_sock, server_message, strlen(server_message), 0) < 0)
            {
                printf("Send Failed. Error!!!!!\n");
            }
        }
        else
        {
            //Cleaning the Buffers
            memset(server_message, '\0', sizeof(server_message));
            memset(client_message, '\0', sizeof(client_message));

            strcpy(server_message, "Error! You have already casted a vote.\n");

            if (send(client_sock, server_message, strlen(server_message), 0) < 0)
            {
                printf("Send Failed. Error!!!!!\n");
            }
        }
    }
    else
    {
        //Cleaning the Buffers
        memset(server_message, '\0', sizeof(server_message));
        memset(client_message, '\0', sizeof(client_message));

        strcpy(server_message, "Error! Name not in voters list.\n");

        if (send(client_sock, server_message, strlen(server_message), 0) < 0)
        {
            printf("Send Failed. Error!!!!!\n");
        }
    }

    close(client_sock);
    pthread_exit(NULL);
}

int main(void)
{
    int socket_desc, client_sock, client_size;
    struct sockaddr_in server_addr, client_addr;
    char server_message[2000], client_message[2000];
    pthread_t thread1;

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

    //Binding IP and Port to socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2000);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Bind Failed. Error!!!!!\n");
        return -1;
    }

    printf("Bind Done\n");

    //Put the socket into Listening State
    if (listen(socket_desc, 1) < 0)
    {
        printf("Listening Failed. Error!!!!!\n");
        return -1;
    }

    printf("Listening for Incoming Connections.....\n");

    while (1)
    {
        //Accept the incoming Connections
        client_size = sizeof(client_addr);
        client_sock = accept(socket_desc, (struct sockaddr *)&client_addr, &client_size);

        if (client_sock < 0)
        {
            printf("Accept Failed. Error!!!!!!\n");
            return -1;
        }

        //printf("Client Connected with IP: %s and Port No: %i\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        strcpy(client_message, "Connection Established!");

        // Send the connection message back to client
        if (send(client_sock, client_message, strlen(client_message), 0) < 0)
        {
            printf("Send Failed. Error!!!!!\n");
            return -1;
        }

        //Cleaning the Buffers
        memset(server_message, '\0', sizeof(server_message));
        memset(client_message, '\0', sizeof(client_message));

        //create new thread for each client
        pthread_create(&thread1, NULL, my_thread, (void *)client_sock);
    }

    //waitng for threads to close
    //Note: the program will not reach here most of the times
    pthread_join(thread1, NULL); //Suspends main thread until termination of threads

    //Cleaning the Buffers
    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));

    //Closing the Socket
    close(socket_desc);
    return 0;
}
