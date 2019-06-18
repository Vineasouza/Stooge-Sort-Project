from tkinter import*
import csv
import matplotlib.pyplot as pl
from PIL import Image, ImageTk

class Aplicacao:
    
    __janela = None
    __Comp = None

    def __init__(self, tk):
        janela = tk
        self.Frame1 = Frame(janela,height = 330, width = 200, background = "#1e8bc3");
        self.Frame1.place(x= 0, y = 10);

        self.Frame2 = Frame(janela, height = 100, width = 485, background = "red");
        self.Frame2.place(x = 110, y = 10);

        self.FramaInforma = Frame(self.Frame2, height = 90 , width = 200, background = "yellow")
        self.FramaInforma.place(x = 275,  y= 5)
        
        self.LabelVetor = Label(self.FramaInforma,text = "Vetor:", fg = "Black" )
        self.LabelVetor.place(x =10, y = 10)
        
        self.LabelComp = Label(self.FramaInforma,text = "Comparação:", fg = "Black")
        self.LabelComp.place(x=10, y= 30)

        self.LabelCompInfor = Label(self.FramaInforma, text =".....", fg = "Black")
        self.LabelCompInfor.place(x=90, y=30)


        self.Frame3 = Frame(janela, height = 215, width = 485, background ="green");
        self.Frame3.place(x= 110, y = 115);

        self.Frame4 = Frame(janela, height = 215,width = 485, background = "yellow")
        self.Frame4.place(x =110, y = 335)

        self.LabelConclu = Label(self.Frame4,text= "Conclusões: ", fg ="Black")
        self.LabelConclu.place(x = 10, y = 10)

        self.Entrada = Entry(self.Frame2);
        self.Entrada.place(x=100, y =10);

        self.Ent = Label(self.Frame2, text = "Insira o vetor", background = "red", fg = "white");
        self.Ent.place(x=10,y=10);

        self.botaoC1 = Button(self.Frame2, text="Nº de comparações", background ="blue", fg = "white");
        self.botaoC1.place(x = 10, y =40);
        self.botaoC1.bind("<Button-1>",self.labelComp)

        self.botaoC2 = Button(self.Frame2, text="N° de trocas", background ="blue", fg = "white");
        self.botaoC2.place(x = 130, y =40);

        self.botaoExibir = Button(self.Frame2, text = "Exibir gráfico", background ="blue", fg = "white");
        self.botaoExibir.place( x=80, y = 70);

        

        ##Botões
        self.botao1 = Button(self.Frame1, text="InsertionShort", background ="blue", fg = "white");
        self.botao1.bind("<Button-1>",self.plota_grafico)
        self.botao1.place( y = 30)
        self.botao1.pack( padx = 10,pady = 10)

        self.botao2 = Button(self.Frame1, text="SeletionShort", background = "blue", fg = "white");
        self.botao2.bind("<Button-1>",self.criaLabel)
        self.botao2.place(y = 50)
        self.botao2.pack( pady = 10)

        self.botao3 = Button(self.Frame1, text="MergeShort", background ="blue", fg ="white");
        self.botao3.place(y = 70)
        self.botao3.pack( pady = 10)

        self.botao4 = Button(self.Frame1, text="BubleShort", background = "blue", fg="white");
        self.botao4.place(y = 90)
        self.botao4.pack( pady = 10)

        self.botao5 = Button(self.Frame1, text = "Shellsort", background = "blue", fg = "white")
        self.botao5.place(y=110)
        self.botao5.pack( pady = 10)

        self.botao6 = Button(self.Frame1, text = "Quiksort", background = "blue", fg = "white")
        self.botao6.place(y=130)
        self.botao6.pack( pady = 10)

        self.botao7 = Button(self.Frame1, text = "StoogeSort", background = "blue", fg = "white")
        self.botao7.place(y=150)
        self.botao7.pack( pady = 10)



        
        tk.mainloop()


    def plota_grafico(self, event):
        pass
       
    def criaLabel(self, event):
        image = Image.open("problema.jpg")
        photo = ImageTk.PhotoImage(image)
        self.label = Label(janela, text = "adicionando", image = photo)
        self.label.image = photo
        self.label.place(x = 0, y = 250)

    def labelComp(self, event):
            self.LabelCompInfor["text"] = "Nº de comparações"


janela = Tk()   
janela.geometry("700x560+30+30")
janela.title("Argoritmos de Ordenação")
Aplicacao(janela)





