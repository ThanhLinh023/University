from random import randint
from turtle import width
import pygame

pygame.init()
screen = pygame.display.set_mode((500, 500))
pygame.display.set_caption('Test Graphic User Interface')
running = True
colorBg = (150, 200, 100)
clock = pygame.time.Clock()
t = (253, 129, 82)
m = pygame.Rect(0, 0, 50, 50)

black = (0, 0, 0)
font = pygame.font.Font('freesansbold.ttf', 25)
text = font.render("Testing", True, black)

while running:
    clock.tick(60)
    screen.fill(colorBg)
    pygame.draw.rect(screen, t, m)
    h = pygame.mouse.get_pos()
    for event in pygame.event.get():
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP:
                if m.y <= 0:
                    m.y = screen.get_height() - m.height
                else:
                    m.y -= m.height
            elif event.key == pygame.K_DOWN:
                if m.y >= screen.get_height() - m.height:
                    m.y = 0
                else:
                    m.y += m.height
            elif event.key == pygame.K_LEFT:
                if m.x <= 0:
                    m.x = screen.get_width() - m.width
                else:
                    m.x -= m.width
            elif event.key == pygame.K_RIGHT:
                if m.x >= screen.get_width() - m.width:
                    m.x = 0
                else:
                    m.x += m.width
            elif event.key == pygame.K_ESCAPE:
                pygame.quit()
        if event.type == pygame.MOUSEBUTTONDOWN:
            if h[0] >= m.x and h[0] <= (m.x + m.width) and h[1] >= m.y and h[1] <= (m.y + m.width):
                colorBg = (randint(0, 255), randint(0, 255), randint(0, 255))
            else:
                colorBg = (randint(0, 255), randint(0, 255), randint(0, 255))
    pygame.display.flip()
pygame.quit()