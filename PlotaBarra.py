import csv
import matplotlib.pyplot as pt

labels = ["ShellSort", "InsertionSort", "BubleSort","SelectionSort","StoogeSort","Merge sort","quickSort"]
recebe = open("Exemplo.csv")
dados = csv.reader(recebe,delimiter=';') #DELIMITER É COMO OS CAMPOS ESTÃO DIVIDIDOS (PODENDO SER , E ;)

comp = []
for i in dados:
        for n in i:
            comp.append(int(n))

pt.figure(figsize=(8,4))
pt.bar(labels,comp, color = "green",width=0.6, align="center")
pt.xticks(labels)
pt.xlabel("Algoritmos de Ordenação")
pt.ylabel("Passos computacionais")
pt.grid(True)
pt.savefig("barra.jpg")
pt.show()