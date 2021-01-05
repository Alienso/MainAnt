# :ant: Project 08-MainAnt :ant:

MainAnt je aplikacija koja korisniku omoguca da pomocu elemenata scene, koje nazivamo cvorovi, kreira drvoliku strukturku koja se prevodi u odgovarajuci c++ kod.Program cine:
1. Cvorovi scene pomocu kojih gradimo kod 
2. Definisanje klasa
3. Definisanje funkcija
4. Generisanje koda na osnovu formirane scene(pomocu parsera)

# O projektu
Mainant je zamisljen kao GUI koji korisniku omogucava da na vizuelan nacin gradi svoj kod. Elementi koda su cvorovi, a povezivanjem cvorova na odredjeni  nacin gradimo kod. Kao i u svakom programskom jeziku i nas GUI je osetljiv na redosled operacija, tacnije na redosled povezivanja cvorova, dakle korisnik mora da pazi na koji nacin gradi samu scenu. Nakon sto napravimo scenu sa kojom smo zadovoljni, mozemo odabrati opciju compile, koja ce generisati c++ kod koji odgovara datoj sceni, ili opciju run, koja ce izgraditi i pokrenuti odgovarajuci c++ kod. Pored run i compile opcije, imamo opciju Open Code koja otvara generisan .cpp fajl i opciju Format Code koja gradi novi .cpp fajl koji je isti kao prethodni samo je formatiran. 
Maiant omogucava gradjenje jednostavnih kodova, klasa i funkcija. 

# Pokretanje projekta
Projekat je ceo implementiran u razvojnom okruzenju Qt, tako da je nepohodno instalirati ovo okruzenje i pokrenuti projekat u QtCreatoru klkiom na dugme run. Takodje je neophodno posedovati c++ kompajler, i to bas g++. Verzija QtCreatror-a mora biti najmanje 5.12. 

Ako zelite da vidite generisan kod za napravljenu scenu klikom na opciju Compile u Build padajucem meniju generise se kod, a opcijom Open Code u istom meniju se otvara kod koji je generisan. Za lepsi izgled koda ugradjena je opcija Format Code u istom meniju, prilikom koje se generise formatiran kod koji mozete da nadjete na istoj lokaciji gde vam se nalazi direktorijum glavnog programa.

# Video snimak aplikacije

[Video](https://drive.google.com/file/d/1i_hih03tABAcz8mNLgUuM7UTYp16eRqC/view?usp=sharing)

# Nedeljni izvestaji

[Nedeljni izvestaji](https://gitlab.com/matf-bg-ac-rs/course-rs/projects-2020-2021/08-mainant/-/wikis/Home-Page)

# Dokumentacija

[Dokumentacija](https://gitlab.com/matf-bg-ac-rs/course-rs/projects-2020-2021/08-mainant/-/blob/master/documentation/UMLDiagram.html)

# Neophodno za pokretanje
- QtCreator version 5.12 or up
- g++


## Developers

- [Vladimir Arsenijevic, 39/2017](https://gitlab.com/Alienso)
- [Mila Mladjenovic, 100/2017](https://gitlab.com/milamladjenovic)
- [Mirko Ilic, 468/2018](https://gitlab.com/Mirko07998)
- [Andjela Ilic, 105/2017](https://gitlab.com/ilicandjela)

