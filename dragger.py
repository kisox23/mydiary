import time, os, sys, random
from termcolor import colored

class Player:                           #CLASSE PER CREARE L'OGGETTO GIOCATORE
    def __init__(self, name, life):
        self.name = name
        self.life = life

class Enemy:                            #CLASSE PER CREARE L'OGGETTO NEMICO
    def __init__(self, name, life):
        self.name = name
        self.life = life

def start():
    os.system("clear")
    username = str(input("Inserisci un username: "))
    if len(username) < 1:
        print(colored("Non valido","red"))
        time.sleep(1)

    enemy_list = ["Panzuto","Gattoso","Nonna","Drago"]          #LISTA PER I NOMI DEI NEMICI

    rand_name = random.randint(0,3)                             #GENERAZIONE NUMERO CASUALE PER ASSEGNARLO A UN ELEMENTO DELLA LISTA
    x = 0
    if rand_name == 0:
        z = enemy_list[0]
        x = 80
    elif rand_name == 1:
        z = enemy_list[1]
        x = 100                                                 #ASSEGNAZIONI
    elif rand_name == 2:
        z = enemy_list[2]
        x = 120
    elif rand_name == 3:
        z = enemy_list[3]
        x = 180
    enemy1 = Enemy(z,x)                                         #OGGETTO NEMICO
    player1 = Player(username, 100)                             #OGGETTO GIOCATORE
    os.system("clear")
    print(f"Stai combattendo contro {enemy1.name}, preparati!")
    time.sleep(1)
    print("3...")
    time.sleep(0.75)
    print("2...")
    time.sleep(0.75)
    print("1...")
    time.sleep(0.75)
    print("\nCombatti!")
    time.sleep(0.75)
    turn = 0
    casuality_list = ["\nBabbo natale vi porta la rogna! Perdete 15 PV.",
                      "\nPiove acqua santa! I vostri PV aumentano di 20.",
                      f"\n{enemy1.name} mangia una mela raccolta per terra, ma diventa down! Perde 10 PV e la sanita' mentale",
                      f"\n{player1.name} punzecchia un nano che gli rompe le ossa! Perde 10 PV.",
                      f"\nUn uomo vestito da Gesu' dona a {player1.name} 15 PV e un Vangelo!",
                      f"\n{enemy1.name} parla in una strana lingua, ma si rinvigorisce!"]
                        #LISTA EVENTUALITA'

    charge = 0          #CARICA ATTACCO SPECIALE
    lifecharge = 0      #CARICA DIFESA SPECIALE

    while True:

        os.system("clear")
        while (turn % 2) == 0 and player1.life > 0 and enemy1.life > 0:
            os.system("clear")
            print(f"""
1 --> Colata di vomito                          2 --> Craniata sul naso

3 --> Schiaffo di marmo                         4 --> Calcio nello stomaco

5 --> Attacco speciale                          6 --> Recupera PV
                        
                        PUNTI VITA {player1.name}: {player1.life}
                        PUNTI VITA {enemy1.name}: {enemy1.life}""")
            if charge >= 100:
                print(colored("\n                   Adesso puoi usare l'attacco speciale!", "cyan"))

            if lifecharge >= 100:
                print(colored("\n                   Adesso puoi recuperare i tuoi PV!", "cyan"))

            try:
                att = int(input("\n>> "))
                if att == 1:
                    print(colored("Il nemico viene sommerso dal vomito! Perde 10 PV.","yellow"))
                    enemy1.life += -10
                    turn += 1
                    time.sleep(3.5)
                elif att == 2:
                    print(colored(f"Il naso di {enemy1.name} perde sangue! 15 PV tolti.","magenta"))
                    enemy1.life += -15
                    turn += 1
                    time.sleep(3.5)
                elif att == 3:
                    print(colored(f"Il marmo della mano di {player1.name} fa perdere 30 PV al nemico!","red"))
                    enemy1.life += -30
                    turn += 1
                    time.sleep(3.5)
                elif att == 4:
                    print(colored("Un calcio dritto in pancia! Meno 20 PV","yellow"))
                    enemy1.life += -20
                    turn += 1
                    time.sleep(3.5)
                elif att == 5:
                    if charge >= 100:
                        print(colored(f"{player1.name} usa l'attacco speciale! 40 punti di danno al nemico!","green"))
                        turn += 1
                        enemy1.life += -40
                        time.sleep(3.5)
                        charge = 0
                    else:
                        print(colored("Non puoi usare l'attacco speciale ora!","red"))
                        time.sleep(3.5)
                        continue
                elif att == 6:
                    if lifecharge >= 100:
                        print(colored("Ripristini 20 PV","green"))
                        turn += 1
                        player1.life += 20
                        time.sleep(3.5)
                        lifecharge = 0
                    else:
                        print(colored("Non puoi ripristinare i tuoi PV ora!","red"))
                        time.sleep(3.5)
                        continue
                else:
                    continue

            except ValueError:
                os.system("clear")
                print(f"""PAUSA
PREMI INVIO PER TORNARE AL GIOCO, SCRIVI ESCI PER USCIRE""")
                pausa = input(">> ")
                if pausa == "":
                    continue
                elif pausa == "esci":
                    print("\nCiao!")
                    os.system("clear")
                    exit(2)
                elif pausa == "/2377":
                    os.system("clear")
                    print(f"""uelcom to de developper menu

1 --> sets pivi                        2 --> cienj neimz

3 --> tosets                           4 --> ecsith""")
                    try:
                        menu = str(input("\n>> "))
                        if menu == "sets pivi p":
                            player1.life = int(input("\nsaiz >> "))
                            time.sleep(0.75)
                        elif menu == "sets pivi e":
                            enemy1.life = int(input("\nsaiz >> "))
                            time.sleep(0.75)
                        elif menu == "cienj neim p":
                            player1.name = str(input("\nneim >> "))
                            time.sleep(0.75)
                        elif menu == "cienj neim e":
                            enemy1.name = str(input("\nneim >> "))
                            time.sleep(0.75)
                        elif menu == "ecsith" or menu == "ex":
                            time.sleep(0.75)
                            continue
                        else:
                            continue
                    except ValueError:
                        continue

        while (turn % 2) != 0 and player1.life > 0 and enemy1.life > 0:
            rand_att = random.randint(0,3)
            if rand_att == 0:
                print(colored(f"\n{enemy1.name} ti fa il solletico! Ma ti leva 10 PV.","yellow"))
                player1.life += -10
                turn += 1
                charge += 25
                lifecharge += 34
                time.sleep(3.5)
            elif rand_att == 1:
                print(colored(f"\n{player1.name} viene preso a calci! Meno 15 PV.","magenta"))
                player1.life += -15
                turn += 1
                charge += 25
                lifecharge += 34
                time.sleep(3.5)
            elif rand_att == 2:
                print(colored("\nBrutto colpo! Perdi 30 PV.","red"))
                player1.life += -30
                turn += 1
                charge += 25
                lifecharge += 34
                time.sleep(3.5)
            elif rand_att == 3:
                if rand_name == 0:
                    print(colored(f"\nVieni schiacciato dalla pancia di {enemy1.name}! 10 PV si incastrano nella ciccia.","yellow"))
                    player1.life += -10
                    turn += 1
                    charge += 25
                    lifecharge += 34
                    time.sleep(3.5)
                elif rand_name == 1:
                    print(colored(f"\nGli artigli di {enemy1.name} fanno un'opera d'arte sulla tua faccia! Perdi 10 PV\ne la possibilita' di avere ragazze.", "yellow"))
                    player1.life += -10
                    turn += 1
                    charge += 25
                    lifecharge += 34
                    time.sleep(3.5)
                elif rand_name == 2:
                    print(colored(f"\n{enemy1.name} ti colpisce con la sua ciabatta! Perdi €15 per il gelato.", "magenta"))
                    player1.life += -15
                    turn += 1
                    charge += 25
                    lifecharge += 34
                    time.sleep(3.5)
                elif rand_name == 3:
                    print(colored(f"\n{enemy1.name} ti brucia i vestiti! Perdi la dignita' e 20 PV","red"))
                    player1.life += -20
                    turn += 1
                    lifecharge += 34
                    charge += 25
                    time.sleep(3.5)
            else:
                continue

        while (turn % 3) == 0 and player1.life > 0 and enemy1.life > 0:
            casuality = random.randint(0,5)
            if casuality == 0:
                print(casuality_list[0])
                player1.life += -15
                enemy1.life += -15
                time.sleep(3.5)
                break
            elif casuality == 1:
                print(casuality_list[1])
                player1.life += 20
                enemy1.life += 20
                time.sleep(3.5)
                break
            elif casuality == 2:
                print(casuality_list[2])
                enemy1.life += -10
                time.sleep(3.5)
                break
            elif casuality == 3:
                print(casuality_list[3])
                player1.life += -10
                time.sleep(3.5)
                break
            elif casuality == 4:
                print(casuality_list[4])
                player1.life += 15
                time.sleep(3.5)
                break
            elif casuality == 5:
                print(casuality_list[5])
                enemy1.life += 15
                time.sleep(3.5)
                break

        while player1.life <= 0:
            os.system("clear")
            time.sleep(0.5)
            print(colored("Sei stato sconfitto!","green"))
            scelta = int(input("1 --> Si'                       2 --> No  \nVuoi ricominciare? \n\n>> "))
            if scelta == 1:
                start()
            elif scelta == 2:
                os.system("clear")
                exit(1)
            else:
                continue

        while enemy1.life <= 0:
            os.system("clear")
            time.sleep(0.5)
            print(colored("Hai battuto {enemy1.name}! Bravo!", "green"))
            scelta = int(input("1 --> Si'                       2 --> No  \nVuoi ricominciare? \n\n>> "))
            if scelta == 1:
                start()
            elif scelta == 2:
                os.system("clear")
                exit(1)
            else:
                continue

start()