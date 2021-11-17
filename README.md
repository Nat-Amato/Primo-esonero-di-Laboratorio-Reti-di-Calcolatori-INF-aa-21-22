## Primo esonero di Laboratorio - Reti di Calcolatori (INF) aa 20-21

#### Applicazione TCP client/server, dove il server è una calcolatrice remota che risponde alle richieste del client



#### Autori

- Amato Natale
- de Gioia Francesco





#### Guida alla configurazione



##### Lato server

Avviare il file Server.exe

Una volta avviato, il server chiederà l'inserimento di una porta o in alternativa, premendo il tasto INVIO il server imposterà una porta di default `(60000)`

Scelta la porta, il server chiederà l'inserimento dell'IP della macchina o in alternativa, premendo il tasto INVIO il server imposterà l'IP su localhost `(127.0.0.1)`

Terminata la configurazione, il server rimarrà in attesa di un client.

Ricevuta la connessione, il server visualizzerà sullo standard output l'indirizzo e il numero di porta del client, scrivendo "*Connection established with `xxx.xxx.xxx.xxx:yyyyy`"*.

<img src="https://user-images.githubusercontent.com/48321178/142286905-05a6b693-fe38-4415-b8f9-a1fae555f8c8.gif" width="60%" height="60%">

> Nota bene:
>
> Il server interagisce anche da remoto, pertanto se al client inserirete l'IP pubblico del server, la connessione avverrà con successo, occorre però come primo passaggio impostare il Port forwarding affinché un computer remoto possa collegarsi ad un computer o ad un servizio specifico all'interno di una LAN.
> ![image](https://user-images.githubusercontent.com/48321178/142287306-274c65e9-4c94-41c4-958b-45f1358366ad.png)

&nbsp;&nbsp;

##### Lato client

Avviare il file Client.exe

Una volta avviato, il client chiederà l'inserimento dell'IP del server o in alternativa, premendo il tasto <img src="https://user-images.githubusercontent.com/48321178/142282274-fb1c83bc-69d2-4c3d-9a5f-2862615c3b7a.png" img alt="Invio" title="INVIO" width="1.5%" height="1.5%"> il client tenterà il collegamento al localhost (127.0.0.1)

Scelto l'IP del server, il client chiederà l'inserimento della sua porta o in alternativa, premendo il tasto <img src="https://user-images.githubusercontent.com/48321178/142282274-fb1c83bc-69d2-4c3d-9a5f-2862615c3b7a.png" img alt="Invio" title="INVIO" width="1.5%" height="1.5%"> il client tenterà il collegamento alla porta impostata di default (60000)

Impostati IP e Porta, il client  richiederà la connessione al server.



...TO DO...
