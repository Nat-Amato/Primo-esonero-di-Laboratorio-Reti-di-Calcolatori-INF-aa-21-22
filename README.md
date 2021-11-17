## Primo esonero di Laboratorio - Reti di Calcolatori (INF) aa 20-21

#### Applicazione TCP client/server, dove il server è una calcolatrice remota che risponde alle richieste del client



#### Autori

- Amato Natale
- de Gioia Francesco





#### Guida all'uso



##### Lato server

Avviare il file Server.exe

Una volta aperto, il server chiederà l'inserimento di una porta o in alternativa, premendo il tasto INVIO il server imposterà una porta di default (60000)

<img src="https://user-images.githubusercontent.com/48321178/142228069-2d774920-23df-4d03-8985-6c79933ba0da.png" width="60%" height="60%">

Scelta la porta, il server chiederà l'inserimento dell'IP della macchina o in alternativa, premendo il tasto INVIO il server imposterà l'IP su localhost (127.0.0.1)

<img src="https://user-images.githubusercontent.com/48321178/142228124-92b6206c-330e-4442-b556-afb3da75061c.png" width="60%" height="60%">

Terminata la configurazione, il server rimarrà in attesa di un client.

<img src="https://user-images.githubusercontent.com/48321178/142228158-bd34afa8-5869-4280-a4d3-360f3895cc30.png" width="60%" height="60%">

Ricevuta la connessione, il server visualizzerà sullo standard output l'indirizzo e il numero di porta del client, scrivendo "*Connection established with `xxx.xxx.xxx.xxx:yyyyy`"*.



...TO DO...



##### Lato client

Avviare il file Client.exe

Una volta avviato, il client chiederà l'inserimento dell'IP del server o in alternativa, premendo il tasto INVIO il client tenterà il collegamento al localhost (127.0.0.1)

Scelto l'IP del server, il client chiederà l'inserimento della sua porta o in alternativa, premendo il tasto INVIO il client tenterà il collegamento alla porta impostata di default (60000)

Impostati IP e Porta, il client  richiederà la connessione al server.



...TO DO...
