## Primo esonero di Laboratorio - Reti di Calcolatori (INF) aa 21-22


#### Applicazione TCP client/server, dove il server è una calcolatrice remota che risponde alle richieste del client

&nbsp;&nbsp;

#### Autori

- Amato Natale
- de Gioia Francesco

&nbsp;&nbsp;

#### Guida alla configurazione

##### Lato server

Avviare il file Server.exe

Una volta avviato, il server chiederà l'inserimento di una porta o in alternativa, premendo il tasto <img src="https://user-images.githubusercontent.com/48321178/142282274-fb1c83bc-69d2-4c3d-9a5f-2862615c3b7a.png" img alt="Invio" title="INVIO" width="1.5%" height="1.5%"> il server imposterà una porta di default `(60000)`

Scelta la porta, il server chiederà l'inserimento dell'IP della macchina o in alternativa, premendo il tasto <img src="https://user-images.githubusercontent.com/48321178/142282274-fb1c83bc-69d2-4c3d-9a5f-2862615c3b7a.png" img alt="Invio" title="INVIO" width="1.5%" height="1.5%"> il server imposterà l'IP su localhost `(127.0.0.1)`

Terminata la configurazione, il server rimarrà in attesa di un client.

Ricevuta la connessione, il server visualizzerà sullo standard output l'indirizzo e il numero di porta del client, scrivendo "*Connection established with `xxx.xxx.xxx.xxx:yyyyy`"*.

<img src="https://user-images.githubusercontent.com/48321178/142928094-5152ca4e-eed9-4a6f-8273-8bac46f69324.gif" width="60%" height="60%">

> Nota bene:
>
> Il server interagisce anche da remoto, pertanto se al client inserirete l'IP pubblico del server, la connessione avverrà con successo, occorre però come primo passaggio impostare il Port forwarding affinché un computer remoto possa collegarsi ad un computer o ad un servizio specifico all'interno di una LAN.
> ![image](https://user-images.githubusercontent.com/48321178/142287306-274c65e9-4c94-41c4-958b-45f1358366ad.png)

&nbsp;&nbsp;

##### Lato client

Avviare il file Client.exe

Una volta avviato, il client chiederà l'inserimento dell'IP del server o in alternativa, premendo il tasto <img src="https://user-images.githubusercontent.com/48321178/142282274-fb1c83bc-69d2-4c3d-9a5f-2862615c3b7a.png" img alt="Invio" title="INVIO" width="1.5%" height="1.5%"> il client acquisirà il localhost (127.0.0.1)

Scelto l'IP del server, il client chiederà l'inserimento della sua porta o in alternativa, premendo il tasto <img src="https://user-images.githubusercontent.com/48321178/142282274-fb1c83bc-69d2-4c3d-9a5f-2862615c3b7a.png" img alt="Invio" title="INVIO" width="1.5%" height="1.5%"> il client acquisirà la porta impostata di default (60000)

Impostati IP e Porta, il client  richiederà la connessione al server.

&nbsp;&nbsp;

#### Funzionamento

Stabilita la connessione, il client legge l'operazione da compiere (usando i caratteri `+`, `x`, `-`, `/`, rispettivamente per *Addizione*, *Moltiplicazione*, *Sottrazione* e *Divisione*) e due numeri interi dallo standard input (es. `+ 23 45`) ed invia al server quanto letto da tastiera.

<img src="https://user-images.githubusercontent.com/48321178/142927294-9b1c6192-58d6-4352-bb3f-b29d5c4f03af.gif" width="60%" height="60%">

> Nota bene:
>
> - La lettura da riga di comando è effettuata in una singola lettura (ossia `+ 23 45[invio]`, non `+[invio]23[invio]45[invio]`).



Il server legge quanto inviato dal client, esegue l'operazione richiesta e invia il risultato al client (es. `68`).

Il client legge la risposta inviata dal server e la visualizza sullo standard output.

Successivamente, il client potrà leggere dallo standard input la successiva operazione da compiere o se invece di un'operazione si è scelto il simbolo di `=`, il client chiude la connessione con il server e termina qui il suo processo.

Il server rimarrà in ascolto e non terminerà mai il suo processo, sarà in grado di accettare una coda massima di 5 client (parametro `qlen`), ma di processarne uno per volta in quanto *non multithread*.
