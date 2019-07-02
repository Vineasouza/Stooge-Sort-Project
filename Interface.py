from tkinter import*
import csv
import matplotlib.pyplot as pt
from PIL import Image, ImageTk
import random 
import os
import subprocess
class Aplicacao:
    
    __janela = None
    
    __grafico = {"comparação": False, "trocas": False}
    

    __dados = {"InsertionSort": [0,False] , "SeletionSort": [0,False], "BubleSort": [0,False],
    "ShellSort": [0,False], "QuickSort": [0,False], "MergeSort": [0,False], "StoogeSort": [0,False]
    }

    __StringAlg = []

    def __init__(self, tk):
        self.janela = tk
        self.Frame1 = Frame(janela,height = 330, width = 200, background = "#1e8bc3");
        self.Frame1.place(x= 0, y = 10);

        self.Frame2 = Frame(janela, height = 100, width = 600, background = "#1e8bc3");
        self.Frame2.place(x = 110, y = 10);

        self.FramaInforma = Frame(self.Frame2, height = 90 , width = 600, background = "#1e8bc3")
        self.FramaInforma.place(x = 275,  y= 5)
        
        self.LabelVetor = Label(self.FramaInforma,text = "Tamanho do vetor :", fg = "White", bg = "#1e8bc3" )
        self.LabelVetor.place(x =10, y = 10)
        
        self.TamanhoVetor = Label(self.FramaInforma, text = "...", fg = "White", bg = "#1e8bc3")
        self.TamanhoVetor.place(x= 140, y = 10)

        self.LabelComp = Label(self.FramaInforma,text = "Comparação:", fg = "White", bg = "#1e8bc3")
        self.LabelComp.place(x=10, y= 30)

        self.LabelCompInfor = Label(self.FramaInforma, text =".....", fg = "White", bg =  "#1e8bc3")
        self.LabelCompInfor.place(x=90, y=30)

        self.Algortimos = Label(self.FramaInforma, text = "Algoritmos selecionado:", fg = "White", bg = "#1e8bc3")
        self.Algortimos.place(x =10, y =55)
        
        self.InformaAlg = Label(self.FramaInforma,  fg = "White", text ="...", bg = "#1e8bc3")
        self.InformaAlg.place(x=150,y=55)

        self.Frame3 = Frame(janela, height = 300, width = 600, background ="#1e8bc3");
        self.Frame3.place(x= 110, y = 115);

        self.Frame4 = Frame(janela, height = 150,width = 600, background = "#1e8bc3")
        self.Frame4.place(x =110, y = 430)

        self.LabelConclu = Label(self.Frame4,text= "Conclusões: ", fg ="White", bg = "#1e8bc3")
        self.LabelConclu.place(x = 10, y = 10)
       
        self.LabelConcluAlgoritmosPlotados = Label(self.Frame4, text = ".....", fg = "White", bg = "#1e8bc3")
        self.LabelConcluAlgoritmosPlotados.place(x=80, y=10)

        self.LabelPiorAlgoritmo = Label(self.Frame4, text = ".......", fg = "White", bg ="#1e8bc3")
        self.LabelPiorAlgoritmo.place(x=80, y=33)

        self.MelhorAlgoritmo = Label(self.Frame4, text = "....", fg = "White", bg = "#1e8bc3")
        self.MelhorAlgoritmo.place(x=80, y=55)

        #------------------------- Entrada do vetor --------------------------------
        self.Entrada = Entry(self.Frame2);
        self.Entrada.place(x=115, y =10);

        self.Ent = Label(self.Frame2, text = "Tamanho do vetor", background = "red", fg = "white");
        self.Ent.place(x=10,y=8);

        self.ok = Button(self.Frame2, text = "OK", background = "blue", fg = "white")
        self.ok.place(x = 245, y = 10)
        self.ok.bind("<Button-1>", self.escreveVetor)

        #-------------------------------------------------------------------------------

        self.botaoC1 = Button(self.Frame2, text="Nº de comparações", background ="blue", fg = "white");
        self.botaoC1.place(x = 10, y =40);
        self.botaoC1.bind("<Button-1>",self.numComp)

        self.botaoC2 = Button(self.Frame2, text="N° de trocas", background ="blue", fg = "white");
        self.botaoC2.place(x = 130, y =40);
        self.botaoC2.bind("<Button-1>",self.numTroca)

        self.botaoExibir = Button(self.Frame2, text = "Exibir gráfico", background ="blue", fg = "white");
        self.botaoExibir.place( x=80, y = 70);
        self.botaoExibir.bind("<Button-1>",self.plota_grafico)

        

        ##Botões
        self.botao1 = Button(self.Frame1, text="InsertionShort", background ="blue", fg = "white");
        self.botao1.bind("<Button-1>",self.InsertionShort)
        self.botao1.place( y = 30)
        self.botao1.pack( padx = 10,pady = 10)

        self.botao2 = Button(self.Frame1, text="SeletionShort", background = "blue", fg = "white");
        self.botao2.bind("<Button-1>",self.SeletionSort)
        self.botao2.place(y = 50)
        self.botao2.pack( pady = 10)

        self.botao3 = Button(self.Frame1, text="MergeShort", background ="blue", fg ="white");
        self.botao3.place(y = 70)
        self.botao3.pack( pady = 10)
        self.botao3.bind("<Button-1>", self.MergeSort)

        self.botao4 = Button(self.Frame1, text="BubleShort", background = "blue", fg="white");
        self.botao4.place(y = 90)
        self.botao4.pack( pady = 10)
        self.botao4.bind("<Button-1>",self.BubleSort)

        self.botao5 = Button(self.Frame1, text = "Shellsort", background = "blue", fg = "white")
        self.botao5.place(y=110)
        self.botao5.pack( pady = 10)
        self.botao5.bind("<Button-1>", self.ShellSort)

        self.botao6 = Button(self.Frame1, text = "Quiksort", background = "blue", fg = "white")
        self.botao6.place(y=130)
        self.botao6.pack( pady = 10)
        self.botao6.bind("<Button-1>",self.QuickSort)

        self.botao7 = Button(self.Frame1, text = "StoogeSort", background = "blue", fg = "white")
        self.botao7.place(y=150)
        self.botao7.pack( pady = 10)
        self.botao7.bind("<Button-1>",self.StoogeSort)

        self.botao8 = Button(self.Frame1, text = "Todos", background = "blue", fg = "white")
        self.botao8.place(y=170)
        self.botao8.pack( pady = 10)
        self.botao8.bind("<Button-1>", self.Todos)
        
        self.janela.mainloop()

    ##--------------------- Funções ----------------------------------

    def escreveVetor(self,x):
        tamanho  = []
        number = int (self.Entrada.get())
        self.TamanhoVetor["text"] = number
        

        tamanho.append(number)

        vetor = []
        i = 0
        while(i<number):
            vetor.append(random.randint(1,number))
            i = i + 1
        
        vetOpen = open("vetor.csv",mode ='w')
        vetWrite = csv.writer(vetOpen,delimiter = ',')

        
        vetWrite.writerow(vetor)

        #INVOCAR O EXERCUTAVEL DO C PARA RODAR OS DADOS
        os.system("testa.exe")
   


    #FUNÇÃO QUE PLOTA GRÁFICO EM RELAÇÃO A NÚMERO DE COMPARAÇÕES (0) OU RELAÇÃO A NÚMERO DE TROCAS (1)
    def plota_grafico(self, event):
        
        
        for t in self.__grafico:

            if self.__grafico[t] == True:

                if t == "comparação":

                    labels = []

                    for chave in self.__dados:
                        if self.__dados[chave][1] == True:
                            labels.append(chave)

                    recebe = open("dadosComparacao.csv")
                    dados = csv.reader(recebe,delimiter=';') #DELIMITER É COMO OS CAMPOS ESTÃO DIVIDIDOS (PODENDO SER , E ;)

                    dadosRecebidos = []
                    for i in dados:
                        for n in i:
                            dadosRecebidos.append(int(n)) ###PROBLEMA A SER SOLUCIONADO
            
                    #print(dadosRecebidos)
        
                    contador = 0
        
                    for k in self.__dados:
                        self.__dados[k][0] = dadosRecebidos[contador]
                        contador += 1
        
                    #print(labels)
                    dadosPlotados = []

                    for j in self.__dados:
                        if self.__dados[j][1] == True:
                            dadosPlotados.append(self.__dados[j][0])
            
                
       
                    #print(self.__dados)
                    #print(dadosPlotados)
                    pt.figure(figsize=(8,4))
                    pt.bar(labels,dadosPlotados, color = "green",width=0.6, align="center")
                    pt.xticks(labels)
                    pt.xlabel("Algoritmos de Ordenação")
                    pt.ylabel("Passos computacionais")
                    pt.grid(True)
                    pt.savefig("barra.jpg")
                    self.criaLabelComp()
                    self.mostraPiorAlgoritmo()
                    self.mostraMelhorAlgoritmo()
                    self.reiniciaAlgoritmosSelecionado()
                    
        
                elif t == "trocas":
                    
                    labels = []

                    for chave in self.__dados:
                        if self.__dados[chave][1] == True:
                            labels.append(chave)

                    recebe = open("dadosTrocas.csv")
                    dados = csv.reader(recebe,delimiter=';') #DELIMITER É COMO OS CAMPOS ESTÃO DIVIDIDOS (PODENDO SER , E ;)

                    dadosRecebidos = []
                    for i in dados:
                        for n in i:
                            dadosRecebidos.append(int(n)) ###PROBLEMA A SER SOLUCIONADO
            
                    #print(dadosRecebidos)
        
                    contador = 0
        
                    for k in self.__dados:
                        self.__dados[k][0] = dadosRecebidos[contador]
                        contador += 1
        
                    #print(labels)
                    dadosPlotados = []

                    for j in self.__dados:
                        if self.__dados[j][1] == True:
                            dadosPlotados.append(self.__dados[j][0])
            
                
       
                    #print(self.__dados)
                    #print(dadosPlotados)
                    pt.figure(figsize=(8,4))
                    pt.bar(labels,dadosPlotados, color = "green",width=0.6, align="center")
                    pt.xticks(labels)
                    pt.xlabel("Algoritmos de Ordenação")
                    pt.ylabel("Passos computacionais")
                    pt.grid(True)
                    pt.savefig("barra2.jpg")
                    self.criaLabelComp()
                    self.mostraPiorAlgoritmo()
                    self.mostraMelhorAlgoritmo()
                    self.reiniciaAlgoritmosSelecionado()

                else:
                    pass



    def criaLabelComp(self):
        
        for t in self.__grafico:
            
            if self.__grafico[t] == True:

                if t == "comparação":

                    image = Image.open("barra.jpg")
                    image2 = image.resize((600,300))
                    photo = ImageTk.PhotoImage(image2)
                    self.label = Label(self.Frame3, text = "adicionando", image = photo)
                    self.label.image = photo
                    self.label.place(x = 0, y = 0)

                elif t == "trocas":

                    image = Image.open("barra2.jpg")
                    image2 = image.resize((600,300))
                    photo = ImageTk.PhotoImage(image2)
                    self.label = Label(self.Frame3, text = "adicionando", image = photo)
                    self.label.image = photo
                    self.label.place(x = 0, y = 0)
                else:
                    pass


        

    ## ------------------------------ Funções informativas ------------------------

    def numComp(self, event):

        self.__grafico["comparação"] = True
        self.__grafico["trocas"] = False

        self.labelCompInforma()
    
    def numTroca(self, event):
        
        self.__grafico["comparação"] = False
        self.__grafico["trocas"] = True

        self.labelCompInforma()
    
    #----------------------- Funções que muda os valores no dicionario --------------------
    def MergeSort(self, event):
        self.__dados["MergeSort"][1] = True 
        self.alteraAlgoritmosSelecionado()

    def InsertionShort(self, event):
        self.__dados["InsertionSort"][1] = True
        self.alteraAlgoritmosSelecionado()

    def SeletionSort(self, event):
        self.__dados["SeletionSort"][1] = True
        self.alteraAlgoritmosSelecionado()

    def BubleSort(self, event):
        self.__dados["BubleSort"][1] = True
        self.alteraAlgoritmosSelecionado()


    def ShellSort(self, event):
        self.__dados["ShellSort"][1] = True
        self.alteraAlgoritmosSelecionado()

    def QuickSort(self, event):
        self.__dados["QuickSort"][1] = True
        self.alteraAlgoritmosSelecionado()

    def StoogeSort(self,event):
        self.__dados["StoogeSort"][1] = True
        self.alteraAlgoritmosSelecionado()

    def Todos(self,event):
        
        for i in self.__dados:
            self.__dados[i][1] = True

        self.InformaAlg["text"] = "Todos"

    #----------------------------------------------------------------------------------------------------
    
    def alteraAlgoritmosSelecionado(self):
        
        
        for chave in self.__dados:
            
            if self.__dados[chave][1] == True:
                
                #---- VERIFICANDO SE NÃO REPETE ---
                for k in self.__StringAlg:

                    if(k == chave):
                        self.__StringAlg.remove(k)
                #--------------------------------    
                self.__StringAlg.append(chave)


           

        self.InformaAlg["text"] = self.__StringAlg

       

    def reiniciaAlgoritmosSelecionado(self): 

        for t in self.__grafico:
            self.__grafico[t] = False

        for chave in self.__dados:
            self.__dados[chave][1] = False
        
        String = ""
        for i in self.__StringAlg:
            String += i +", "

        if self.InformaAlg["text"] == "Todos":
            self.LabelConcluAlgoritmosPlotados["text"] = "Todos"
        else:
            self.LabelConcluAlgoritmosPlotados["text"] = String

       
        self.InformaAlg["text"] = "...."
        self.LabelCompInfor["text"] = "..."
        self.__StringAlg = []
        

    
    def labelCompInforma(self):

       for t in self.__grafico:
           if self.__grafico[t] == True:
                
                if t == "comparação":
                   
                   self.LabelCompInfor["text"] = "Nº de comparações"
                
                elif t == "trocas":
                    
                    self.LabelCompInfor["text"] = "Nº de trocas"
                
                else:
                    pass

    def mostraPiorAlgoritmo(self):
        pior = [0,""]

        for k in self.__dados:
            if self.__dados[k][1] == True:
                if self.__dados[k][0] > pior[0]:
                    pior[1] = k
                    pior[0] = self.__dados[k][0]
                    
        self.LabelPiorAlgoritmo["text"] = pior[1] + " >> Pior Algoritmo"

    def mostraMelhorAlgoritmo(self):
        
        melhor = [0,""]

        for k in self.__dados:

            if melhor[0] == 0:
                melhor[0] = self.__dados[k][0]
                melhor[1] = k
                continue
            
            if self.__dados[k][0] < melhor[0]:
                melhor[0] = self.__dados[k][0]
                melhor[1] = k
        

        self.MelhorAlgoritmo["text"] = melhor[1] + ">> Melhor Algoritmo"


janela = Tk()   
janela.geometry("800x590+300+80")
janela.title("Argoritmos de Ordenação")
janela.resizable(width = False, height = False)
janela["bg"] = "#1f3a93"
Aplicacao(janela)




