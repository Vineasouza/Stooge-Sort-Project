from tkinter import*
import csv
import matplotlib.pyplot as pt
from PIL import Image, ImageTk
import random 

class Aplicacao:
    
    __janela = None
    __CompOuTroca = -1
    

    __dados = {"InsertionSort": [0,False] ,"SeletionSort": [0,False],"MergeSort": [0,False],
    "BubleSort":[0,False],"ShellSort": [0,False],"QuickSort": [0,False], "StoogeSort": [0,False]
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
        
        self.LabelVetor = Label(self.FramaInforma,text = "Vetor:", fg = "Black" )
        self.LabelVetor.place(x =10, y = 10)
        
        self.LabelComp = Label(self.FramaInforma,text = "Comparação:", fg = "Black")
        self.LabelComp.place(x=10, y= 30)

        self.LabelCompInfor = Label(self.FramaInforma, text =".....", fg = "Black")
        self.LabelCompInfor.place(x=90, y=30)

        self.Algortimos = Label(self.FramaInforma, text = "Algoritmos selecionado:", fg = "Black")
        self.Algortimos.place(x =10, y =55)
        
        self.InformaAlg = Label(self.FramaInforma,  fg = "Black", text ="...")
        self.InformaAlg.place(x=150,y=55)

        self.Frame3 = Frame(janela, height = 300, width = 600, background ="#1e8bc3");
        self.Frame3.place(x= 110, y = 115);

        self.Frame4 = Frame(janela, height = 150,width = 600, background = "#1e8bc3")
        self.Frame4.place(x =110, y = 430)

        self.LabelConclu = Label(self.Frame4,text= "Conclusões: ", fg ="Black")
        self.LabelConclu.place(x = 10, y = 10)
       
        self.LabelConcluAlgoritmosPlotados = Label(self.Frame4, text = ".....", fg = "Black")
        self.LabelConcluAlgoritmosPlotados.place(x=80, y=10)

        self.LabelPiorAlgoritmo = Label(self.Frame4, text = ".......", fg = "Black")
        self.LabelPiorAlgoritmo.place(x=80, y=33)

        #------------------------- Entrada do vetor --------------------------------
        self.Entrada = Entry(self.Frame2);
        self.Entrada.place(x=100, y =10);

        self.Ent = Label(self.Frame2, text = "Insira o vetor", background = "red", fg = "white");
        self.Ent.place(x=10,y=10);

        self.ok = Button(self.Frame2, text = "OK", background = "blue", fg = "white")
        self.ok.place(x = 240, y = 10)
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
        
        
        self.janela.mainloop()

    ##--------------------- Funções ----------------------------------

    def escreveVetor(self,x):
        tamanho  = []
        number = int (self.Entrada.get())
        tamanho.append(number)

        vetor = []
        i = 0
        while(i<number):
            vetor.append(random.randint(1,number))
            i = i + 1
        
        vetOpen = open("vetor.csv",mode ='w')
        vetWrite = csv.writer(vetOpen,delimiter = ',')

        
        vetWrite.writerow(vetor)
        


    def plota_grafico(self, event):
        labels = []

        for chave in self.__dados:
            if self.__dados[chave][1] == True:
                labels.append(chave)


        recebe = open("Exemplo.csv")
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
        self.criaLabel()
        self.mostraPiorAlgoritmo()
        self.reiniciaAlgoritmosSelecionado()
       
    def criaLabel(self):
        image = Image.open("barra.jpg")
        image2 = image.resize((600,300))
        photo = ImageTk.PhotoImage(image2)
        self.label = Label(self.Frame3, text = "adicionando", image = photo)
        self.label.image = photo
        self.label.place(x = 0, y = 0)


    ## ------------------------------ Funções informativas ------------------------

    def numComp(self, event):

        self.CompOuTroca = 0
        self.labelCompInforma()
    
    def numTroca(self, event):

        self.CompOuTroca = 1
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


        for chave in self.__dados:
            self.__dados[chave][1] = False

        self.LabelConcluAlgoritmosPlotados["text"] = self.__StringAlg
        self.InformaAlg["text"] = "...."
        
        self.__StringAlg = []
        

    
    def labelCompInforma(self):

        if self.CompOuTroca == 0:
            self.LabelCompInfor["text"] = "Nº de comparações"

        elif self.CompOuTroca == 1:
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

janela = Tk()   
janela.geometry("800x590+300+80")
janela.title("Argoritmos de Ordenação")
janela.resizable(width = False, height = False)
janela["bg"] = "#1f3a93"
Aplicacao(janela)




