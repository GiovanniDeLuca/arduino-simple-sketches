TMR 4 - Backend Readme

This project is the CORE Temera product and is a midleware to track item movements for products that use RFID tags.

Project structure  --> generato con archetipo???
.
├── docs
├── prada                   # customization folder
│   ├── core                # Package for TMR Core Customization  --> qui si customizza il core del framework(qui è personalizzata per Prada)
│   ├── core.webresource    # Package for Exposed customized API
│   ├── prada-tmr-api       # Exposed custom API
│   ├── persistence         # Database configuration (DataSource)
│   └── pom.xml             # Project dependencies
├── .gitignore
└── README.md

Prerequisites
- Java 8 (JDK 8)
- maven
- postgres 10
- wildfly
- Intelij CE

Install on windows
- Install java JDK 8 for your OS (https://www.oracle.com/technetwork/java/javase/downloads/jdk8-downloads-2133151.html)
- Install maven -> https://maven.apache.org/download.cgi
- Install postgres 10 -> https://www.postgresql.org/download/
- Install PGAdmin III for easier database management
- Install wildfly 10 e configurarlo localmente su IntelliJ
- Add Java and maven to your system path
- Add environment variables for java and maven eg. Creazione di variabili di ambiente locali(dovrebbe essere create al termine dell'installazione)
 	JAVA_HOME=C:\Program Files\Java\jdk1.8.0_152 settata in automatico al momento dell'installazione
	M2_HOME=C:\Program Files\Apache\maven        basta una di queste variabili?
	MAVEN_HOME=C:\Program Files\Apache\maven     basta una di queste variabili?

Install on macOS
- Install java JDK 8 for your OS (https://www.oracle.com/technetwork/java/javase/downloads/jdk8-downloads-2133151.html)
- Install maven: use brew https://brewformulas.org/Maven or install official package  https://maven.apache.org/download.cgi
- Install postgres 10:  you can use https://postgresapp.com/ or install official package https://www.postgresql.org/download/
- Install dbeaver for easier database management: https://dbeaver.io/download/ 
- Add Java and maven to your system path: Open your .bash_profile or .zshrc and add these lines: export JAVA_HOME=$(/usr/libexec/java_home) export PATH=$PATH:$JAVA_HOME/bin
- Add postures tools to path: Open your .bash_profile or .zshrc and add these lines:: export POSTGRES_BIN=/Applications/Postgres.app/Contents/Versions/latest/bin export PATH=$PATH:$POSTGRES_BIN

Necessary steps to work on TMR
TMR uses some dependencies deployed on a Temera local maven package manager so we need to instruct our local mvn How to resolve those dependencies.

1. Create a maven config directory on your user home 
	`mkdir ~/.m2` then copy the settings.xml inside.  
￼

2. Open InteliJ and import intelij settings below (File > Import Settings….): 
￼

3. Export the wildfly archive to a local directory eg. ~/wildfly

4. Create postgres databases eg. tmr_prada or if you want to configure a remote database, see the Remote Database Tunneling section
Creao il database locale e  poi creo su Widlfy le connessioni per agganciarsi al database

5. Configure local databases on wildfly: 

open ~/wildfly/standalone/configuration/standalone.xml and add a datasource for each database you want to configure as seen below and a driver for each database driver you want to run.
Ade following code in <datasources> node:

/wildfly/standalone/configuration/standalone.xml è il file di configurazione di JBOSS

tmr_prada è il nome del database installato su postgresql; per ogni database dei vari brand è necessario fare un dump(ricreazione database)

<datasource jta="true" jndi-name="java:jboss/datasources/prada-TMR-DS" pool-name="prada-TMRCore-DS" enabled="true" use-java-context="true">
    <connection-url>jdbc:postgresql://localhost:5432/tmr_prada</connection-url>
    <driver-class>org.postgresql.Driver</driver-class>
    <driver>postgresql</driver>
    <pool>
        <min-pool-size>5</min-pool-size>
        <max-pool-size>10</max-pool-size>
    </pool>
    <security>
        <user-name>tmr</user-name>
        <password>tmr</password>
    </security>
    <validation>
        <validate-on-match>false</validate-on-match>
        <background-validation>false</background-validation>
    </validation>
    <statement>
        <share-prepared-statements>false</share-prepared-statements>
    </statement>
</datasource>

Add following code in <drivers> node:

<driver name="postgresql" module="org.postgresql">
    <xa-datasource-class>org.postgresql.xa.PGXADataSource</xa-datasource-class>
</driver>

And you need to add the driver in wildfly/modules/org/postgresql  mettere qui dentro il driver
￼

To debug the .war, start the standalone like this:
# ./bin/standalone.sh --debug

Remote Database Tunneling
You can configure a remote database by tunneling it via ssh and access it as you were on the same network.
In order to create the tunneling you will need to have configured previously the ssh key on the server you want tu access.
	ssh root@jenkins.temera.it -L 15432:localhost:5432
Now you will access in ssh to the machine and create the tunel. Don’t close the terminal unless you want to kill the tunneling.
Now you can accesso the database on the configured port eg: localhost:15432 as user “tmr” and pass “tmr”.

TMR Code Generator (Scaffolding)
Follow the guide below.

Guida per scaricare il programma TMR4
https://temera.atlassian.net/wiki/spaces/TB/pages/36569111/How+to+use+Tmr+Scaffold+module
	mvn tmr:scaffold -Dentity.name=MyCustomEntity -Dentity.superclass=TmrEntity -Dmodule.name=core -Dbase.package.name=it.temera.tmr.gucci

Add user on db, open connection and run following queries:
CREATE USER username WITH PASSWORD ‘your_password';
GRANT ALL PRIVILEGES ON DATABASE tmr TO tmr;

Start Widlfy Server
In order to deploy .war files to local wildfly you need to run it. Use the following command:
	~/wildfly/bin/standalone.sh
Now your server is up and running, you need to deploy a .war in order to run a package.
In order to deploy a .war package, copy it in ~/wildfly//standalone/deployments directory or use maven to deploy the war.

Build Project and deploy on local wildfly
We can use maven to build the project and automatically deploy it on the running wildfly with the following terminal command:
    mvn package wildfly:deploy -Pdevel,pg -DskipTests=true


How-Tos
How to access the Jenkins tmr postgres database?
# Entra nella machina jenkins
ssh root@jenkins.temera.it
# per entrare nella bash di Postgres
docker exec -it postgres-9-4 bash
# entra come utente Postgres
su - postgres
# accedi a un db specifico: psql [nome_db] [nome_utente]
psql gucci_devel_2 postgres
# lista comandi psql \
\?
# lista comandi sql
\h
# lista tutte le tabelle nel db (devi aver selezionato un database)
\dt
# mostra info tabella: \d table_name
\d products
# chiudi la connessione psql
\q

How can I dump a jenkins pg databse and restore it on a local machine?
1. entrate in ssh sulla macchina: `ssh root@jenkins.temera.it`
2. eseguite il seguente comando cambiando il nome db: `docker exec postgres-9-4 pg_dump -U postgres -F t prada_devel > /tmp/prada_devel.sql`
3. Per facilitare il download è consigliabile zippare il file: `tar -czvf /tmp/prada_devel.tar.gz /tmp/prada_devel.sql`
4. Scarica il file con scp da un terminale della tua macchina: `scp root@jenkins.temera.it:/tmp/prada_devel.tar.gz prada_devel.tar.gz`
5. Rimuovi i file creati sul server: `rm -rf /tmp/prada_devel.sql && rm -rf /tmp/prada_devel.tar.gz`
6. Scompatta l’archivio sulla tua macchina: `tar -xzvf prada_devel.tar.gz`
7. Usa il file prada_devel.sql su un qualsiasi client pg per importare schema e dati

#psql
CREATE DATABASE Prada;
CREATE USER tmr WITH ENCRYPTED PASSWORD ‘tmr’;
GRANT ALL PRIVILEGES ON DATABASE prada TO tmr;

# pg_restore --dbname=prada --verbose /Users/vassi/Downloads/tmp/prada_devel.sql

TMR Development Terms

Dto -> Data Transfer Object (Rappresentazione esterna di un modello/entità)
Mapper -> Trasformatore che si occupa di convertire i dati da Dto a Entity e da Entity a Dto
Validator -> Validazione dei dati in entrata (GET/POST) per oggetti complessi

Model -> Entità mappata su una tabella del db
Dao -> Data Access Object: quello che fa le query sulle entità/modello (costruisci query con QueryBuilder)
QueryParam -> Parametri che vengono passati al Dao per customizzare le query (come where sulle query)
Filter -> Filtri di sicurezza per farti vedere solo dati su cui hai autorizzazione
EntityService -> Gestisce i lifecycle delle entità (creazione, modifica)

ENTITY_NAME_DtoMapper

I DtoMapper è un argomento all’apparenza complesso, ma in pratica Nel Mapper spieghiamo come 
il Dto deve risolvere le dipendenze Complesse. Per quanto riguarda le primitive (String, int, boolean) 
Non è necessario mappare niente. Per quanto riguarda gli oggetti complessi bisogna mappare in una funzione toDto
Lentità che dobbiamo mappare, inoltre dobbiamo mappare anche le dipendenze di questa entità.

Cose da sapere per i test
NB. Quando si aggiunge un package(directory in intelij di primo livello), aggiungere il modulo alla batteria di test es.
    File: PradaCoreDeploymentHelper@createFullModule() … aggiungere una riga con una classe del nuovo package
    es.    pradacore.addPackages(true, Filters.exclude(".*Test.*"), CustomProduct.class.getPackage());

NB. Quando aggiungiamo una nuova entità custom aggiungere la deleteAll per i test es. deleteAll(CustomItem.class); in AbstractPradaCoreTest@clearDb()

InteliJ Keystrokes
cmd+option+L -> reformat code
cmd+option+f -> estrae il field a livello di classe
cmd+option+m -> estrae metodo da selezione
cmd+option+v -> creare variabile per chiamata selezionata
cmd+fn+f9 -> build
cmd+d -> duplicate line




