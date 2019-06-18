import csv
import matplotlib.pyplot as pt

labels = "Burble", "QuickSort", "Seleção","Inserção","Shellsort","Merge sort","Stooge Sort"

recebe = open("Exemplo.csv")
dados = csv.reader(recebe,delimiter=';') #DELIMITER É COMO OS CAMPOS ESTÃO DIVIDIDOS (PODENDO SER , E ;)

comp = []
for i in dados:
        for n in i:
            comp.append(int(n))


fig1, ax1 = pt.subplots()
ax1.pie(comp, labels=labels, autopct='%1.1f%%', shadow = True, startangle = 90)
ax1.axis('equal')
pt.savefig("pizza.jpg")
pt.show()