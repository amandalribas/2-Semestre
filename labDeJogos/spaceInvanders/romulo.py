from PPlay.window import *
from PPlay.gameimage import GameImage
from PPlay.sprite import *
from PPlay.collision import *
from PPlay.gameobject import *
from random import choices
janela = Window(900, 600)
cenario = GameImage("black_screen.png")

teclado = Window.get_keyboard()

while True:

    menu = "MENU"
    janela.draw_text(f"{menu}", (janela.width - len(menu)*40)/2, 4,
                     size=60,  color=(150, 100, 150), font_name="Arial", bold=False, italic=False)
    op_jogar = "Jogar - Aperte 'W'."
    janela.draw_text(f"{op_jogar}", (janela.width - 300)/2, 30+100,
                     size=30,  color=(150, 100, 150), font_name="Arial", bold=False, italic=False)
    op_dificuldade = "Dificuldade - Aperte 'D'."
    janela.draw_text(f"{op_dificuldade}", (janela.width - 300)/2, 80+100,
                     size=30,  color=(150, 100, 150), font_name="Arial", bold=False, italic=False)
    op_ranking = "Ranking - Aperte 'A'."
    janela.draw_text(f"{op_ranking}", (janela.width - 300)/2, 130+100,
                     size=30,  color=(150, 100, 150), font_name="Arial", bold=False, italic=False)
    op_sair = "Sair - Aperte 'ESC'."
    janela.draw_text(f"{op_sair}", (janela.width - 300)/2, 180+100,
                     size=30,  color=(150, 100, 150), font_name="Arial", bold=False, italic=False)

    if teclado.key_pressed("W"):  # Loop do Jogo
        janela.clear()
        while True:
            janela.update()
            op_sair_s = "Sair - Aperte 'S'."

            janela.draw_text(f"{op_sair_s}", (janela.width - 300)/2, 180+100,
                     size=30,  color=(150, 100, 150), font_name="Arial", bold=False, italic=False)
            if teclado.key_pressed("S"):
                janela.clear()
                break
    if teclado.key_pressed("D"):
        janela.clear()
        while True:
            dif_facil = "facil"
            janela.draw_text(f"{dif_facil}", (janela.width - 300)/2, 30+100,
                            size=30,  color=(150, 100, 150), font_name="Arial", bold=False, italic=False)
            dif_medio = "medio"
            janela.draw_text(f"{dif_medio}", (janela.width - 300)/2, 80+100,
                            size=30,  color=(150, 100, 150), font_name="Arial", bold=False, italic=False)
            dif_dificil = "difícil"
            janela.draw_text(f"{dif_dificil}", (janela.width - 300)/2, 130+100,
                            size=30,  color=(150, 100, 150), font_name="Arial", bold=False, italic=False)
            janela.update()
            op_sair_s  = "Sair - Aperte 'S'."
            janela.draw_text(f"{op_sair_s}", (janela.width - 300)/2, 180+100,
                     size=30,  color=(150, 100, 150), font_name="Arial", bold=False, italic=False)
            if teclado.key_pressed("S"):
                janela.clear()
                break
    if teclado.key_pressed("R"):
        ...

    if teclado.key_pressed("ESC"):
        janela.close()
        break
    janela.update()