#include "connectServer.h"

/**
 * connectServer soll den Client mit dem Gameserver verbinden.
 * Dazu wird ein Socket implementiert.
 * Der Hostname wird in eine IP Adresse umgewandelt.
 * Zusätzlich wird die Methode performconnetion mit dem Socket aufgerufen.
 */
int connectServer(int portnumber, char *hostname){
    int sock;                                                                   //!Filedeskriptor für den Socket.
    struct hostent *he;                                                         //!struct hostent *he. Enthält Informationen über host (HOSTNAME)

    //SOCKET ANLEGEN
    /* PF_INET: Internet Protokoll Version 4
     * SOCK_STREAM: Typ des Sockets.(Gegensatz: SOCK_DGRAM). Stream Zuverlässiger.
     * 0: Default Transportprotokoll des Sockettyps. Von SOCK_STREAM ist dies TCP.
     */
    printf("Connecting to %s:%i... \n", hostname, portnumber);
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock == -1){
        perror("Could not generate socket\n");
        exit(EXIT_FAILURE);
    }

    //HOSTNAME in IP Adresse umwandeln
    if( (he = gethostbyname(hostname)) == NULL){                                //Hostname von Client übergeben
        perror("Could not resolve Hostname\n");
        exit(EXIT_FAILURE);
    }

    /* Die Struktur enthält Informationen über Adresse, Port und Internetprotokollfamilie des Gameservers
     * sin_family: Wird die Protokollfamilie zugewiesen (PF_INET für Internet-Protokoll Version 4)
     * sin_port: Speichert den IP-Port (=Endpunkt, der zur Kommunikation mit Netzwerk belegt wird)
     * sin_addr: Speichert die IP-Adresse des Gameservers
     */
    struct sockaddr_in server;
    server.sin_family = PF_INET;
    server.sin_port = htons(portnumber);                                        //Portnummer von Client übergeben
    memcpy(&server.sin_addr.s_addr, he->h_addr_list[0], he -> h_length);

    //CONNECT
    if(connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0){
        perror("Could not connect to server\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Successfully connected to server\n");
    }

    return sock;
}
