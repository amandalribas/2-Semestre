from PPlay.window import *
from PPlay.keyboard import *
from PPlay.sprite import *
from PPlay.gameimage import *
import config
from datetime import datetime  

def gameover():
    arquivo = open("jogadores.txt", "a")

    janela = Window(1200, 744)
    teclado = Window.get_keyboard()
    nome = input("Digite seu nome: ")
    arquivo.write(f'{nome} ')
    arquivo.write(str(config.pontos))
    arquivo.write(f' {str(datetime.now().day)}/{str(datetime.now().month)}/{str(datetime.now().year)}\n')
    arquivo.close()
    while True:
        janela.draw_text("GAME-OVER", 415, janela.height/2, size=70, color=(255,0,0), font_name="Arial", bold=False, italic=False)
        if (teclado.key_pressed("esc")):
            janela.close()
        janela.update()

def ordenaArquivo():
    arquivo = open("jogadores.txt", "r")
    lista = []
    for linha in arquivo:
        atual = linha.split(' ')
        lista.append(atual)
    arquivo.close()

    lista_ordenada = []
    lista_ordenada = sorted(lista, key=lambda x: int(x[1]), reverse=True)
    
    for linha in lista_ordenada:
        print(f"{linha[0]} {linha[1]} {linha[2]}")
        
    arquivo = open("jogadores.txt", "w")
    for linha in lista_ordenada:
        arquivo.write(f'{linha[0]} {linha[1]} {linha[2]}')
    arquivo.close()
    return lista_ordenada