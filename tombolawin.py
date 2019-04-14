import os, random, time, sys

def main():
    os.system("cls")
    print("1 - Classico (9x10)              2 - Alternativo (6x15)")
    x = int(input("Scegli il tipo di visualizzazione della griglia: "))
    if x == 1:
        x = 10
    elif x == 2:
        x = 15
    else:
        main()

    stack = 1
    tabellone = [0]*90

    while stack < 91:
        ex = 0
        os.system("cls")
        i = 1
        while i < 91:
            print(tabellone[i-1], end=" ")
            if (i % x) == 0:
                print("\n")
            i += 1
        try:
            scelta = int(input("\n\nEstrai numero (1), vedi usciti (2), esci (3) >> "))
            if scelta == 1:
                while ex == 0:
                    num = random.randint(1, 90)
                    if num in tabellone:
                        continue
                    else:
                        ex = 1
                tabellone[num-1] = num
                stack += 1
                continue
            elif scelta == 2:
                os.system("cls")
                z = 1
                while z < 91:
                    if tabellone[z - 1] != 0:
                        print(tabellone[z - 1], end=" - ")
                    z += 1
                input("\nPremi invio per continuare.")
                break
                continue
            elif scelta == 3:
                os.system("cls")
                sys.exit(0)

        except ValueError:
            continue
    while True:
        os.system("cls")
        i = 1
        while i < 91:
            print(tabellone[i - 1], end=" ")
            if (i % x) == 0:
                print("\n")
            i += 1
        try:
            exit = int(input("Partita finita! 1 --> Ricomincia      Altro --> Esci\n\n>> "))
            if exit == 1:
                main()
            else:
                os.system("cls")
                sys.exit(0)
        except ValueError:
            continue

main()
