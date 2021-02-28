/*
        UDP_Server. This Program will will create the Server side for UDP_Socket Programming.
        It will receive the data from the client and then send the same data back to client.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h> //// Needed for socket creating and binding
#include <arpa/inet.h>	//inet_addr

typedef struct data
{
	char rollno[255];
	struct data *next;
} data;

char returnMsg[255];

data *head = NULL;

data *find_rollno(char *s)
{
	data *temp = head;
	while (temp != NULL)
	{
		if (strcmp(s, temp->rollno) == 0)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

void print_data()
{
	data *temp = head;
	while (temp != NULL)
	{
		printf("%s\n", temp->rollno);
		temp = temp->next;
	}
}

void insert_data(char roll[])
{

	// creating data here
	data *newdata;
	newdata = (data *)malloc(sizeof(data));

	strcpy(newdata->rollno, roll);

	//linking it to list

	newdata->next = head;
	head = newdata;
}

int remove_data(char roll[])
{
	data *temp = head;
	data *prev = temp;
	int found = 0;
	while (temp != NULL)
	{
		if (strcmp(roll, temp->rollno) == 0)
		{
			found = 1;
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	if (found != 0)
	{
		prev->next = temp->next;
		free(temp);
		return 1;
	}
	return 0;
}

void checkin(char roll[])
{
	char substr[10];
	strncpy(substr, roll, 7);
	substr[7] = '\0';

	if (find_rollno(substr) == NULL) //no already exsistance
	{
		insert_data(substr);
		//printf("Welcome Student %s\n", substr);
		strcpy(returnMsg, "Welcome Student ");
		strcat(returnMsg, substr);
	}
	else
	{ //already here
		//printf("%s", "You are already here.\n");
		strcpy(returnMsg, "You are already here.");
	}
}

void checkout(char roll[])
{
	char substr[10];
	strncpy(substr, roll, 7);
	substr[7] = '\0';

	if (remove_data(substr) == 0) //not found
	{
		//printf("%s", "You didn’t check in today. Contact System Administrator.\n");
		strcpy(returnMsg, "You didn’t check in today. Contact System Administrator.\n");
	}
	else
	{
		//("Good Bye Student %s! Have a nice day.\n", roll);
		strcpy(returnMsg, "Good Bye Student");
		strcat(returnMsg, substr);
		strcat(returnMsg, "! Have a nice day.");
	}
}

int main(void)
{
	int socket_desc;
	struct sockaddr_in server_addr, client_addr;
	char server_message[2000], client_message[2000];
	int client_struct_length = sizeof(client_addr);

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

		printf("Received Message from IP: %s and Port No: %i\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

		//printf("Client Message: %s\n", client_message);

		// my working

		if (client_message[9] == 'I')
		{
			checkin(client_message);
		}
		else if (client_message[9] == 'O')
		{
			checkout(client_message);
		}
		print_data();

		//Send the message back to client

		strcpy(server_message, returnMsg);

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
