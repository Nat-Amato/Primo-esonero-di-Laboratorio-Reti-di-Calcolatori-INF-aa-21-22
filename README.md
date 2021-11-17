## Primo esonero di Laboratorio - Reti di Calcolatori (INF) aa 20-21

#### Applicazione TCP client/server, dove il server è una calcolatrice remota che risponde alle richieste del client



#### Autori

- Amato Natale
- de Gioia Francesco





#### Guida all'uso



##### Lato server

Avviare il file Server.exe

Una volta aperto, il server chiederà l'inserimento di una porta o in alternativa, premendo il tasto INVIO il server imposterà una porta di default (60000)

<img src="C:\Users\amato\Desktop\Server_v9jL31OFRa.png" alt="Server_v9jL31OFRa" style="zoom: 50%;" />

Scelta la porta, il server chiederà l'inserimento dell'IP della macchina o in alternativa, premendo il tasto INVIO il server imposterà l'IP su localhost (127.0.0.1)

<img src="C:\Users\amato\Desktop\Server_z9GtnkjmmW.png" alt="Server_z9GtnkjmmW" style="zoom: 50%;" />

Terminata la configurazione, il server rimarrà in attesa di un client.

<img src="C:\Users\amato\Desktop\Server_9IjJhf9TCs.png" alt="Server_9IjJhf9TCs" style="zoom: 50%;" />

Ricevuta la connessione, il server visualizzerà sullo standard output l'indirizzo e il numero di porta del client, scrivendo "*Connection established with `xxx.xxx.xxx.xxx:yyyyy`"*.
